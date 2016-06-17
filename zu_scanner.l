%option c++ yyclass="zu_scanner" outfile="zu_scanner.cpp"
%option debug stack noyywrap yylineno 8bit
%{
/* $Id: zu_scanner.l,v 1.13 2016/05/20 01:24:41 ist179055 Exp $ */
// make relevant includes before including the parser's tab file
#include <string>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include "zu_scanner.h"
#include "zu_parser.tab.h"

// don't change this
#define yyerror LexerError

%}

%x X_STRING X_COMMENT X_STRING_ASCII

ALPHA			  [a-zA-Z]
ALPHANUM		[0-9]|{ALPHA}

%%

                       //{ set_debug(1); }

">="                   return tGE;
"<="                   return tLE;
"=="                   return tEQ;
"!="                   return tNE;

"/*"                   yy_push_state(X_COMMENT);
<X_COMMENT>"/*"        yy_push_state(X_COMMENT);
<X_COMMENT>"*/"        yy_pop_state();
<X_COMMENT>.|\n        ; //ignore

":"                    return *yytext;
"!"                    return *yytext;
"!!"                   return tPRINT;
"!!!"                  return tRETURN;
"<>"                   return tCONTINUE;
"><"                   return tBREAK;

\"                     yy_push_state(X_STRING); yylval.s = new std::string("");
<X_STRING>\"           yy_pop_state(); return tSTRING;
<X_STRING>\\\"         *yylval.s += yytext + 1;
<X_STRING>\\           yy_push_state(X_STRING_ASCII);
<X_STRING>.            *yylval.s += yytext;
<X_STRING>\n           yyerror("newline in string");

<X_STRING_ASCII>n			                          {yy_pop_state(); *yylval.s += std::string(1,10); }
<X_STRING_ASCII>r			                          {yy_pop_state(); *yylval.s += std::string(1,13); }
<X_STRING_ASCII>t			                          {yy_pop_state(); *yylval.s += std::string(1,9); }
<X_STRING_ASCII>[\"\\]			                    {yy_pop_state(); *yylval.s += std::string(1,(int)*yytext); }
<X_STRING_ASCII>[0-9a-fA-F][0-9a-fA-F]?	                       {yy_pop_state(); *yylval.s += std::string(1,strtol(yytext, nullptr, 16)); }
<X_STRING_ASCII>.|\n			                       yyerror("Invalid special character");

[a-zA-Z]+                               yylval.s = new std::string(yytext); return tIDENTIFIER;

[1-9][0-9]*[eE][1-9][0-9]*                    yylval.d = strtod(yytext, nullptr); return tDOUBLE;
[1-9][0-9]*[eE]"+"[1-9][0-9]*                 yylval.d = strtod(yytext, nullptr); return tDOUBLE;
[1-9][0-9]*[eE]"-"[1-9][0-9]*                 yylval.d = strtod(yytext, nullptr); return tDOUBLE;

[1-9][0-9]*"."[0-9]+[eE][1-9][0-9]*           yylval.d = strtod(yytext, nullptr); return tDOUBLE;
[1-9][0-9]*"."[0-9]+[eE]"+"[1-9][0-9]*        yylval.d = strtod(yytext, nullptr); return tDOUBLE;
[1-9][0-9]*"."[0-9]+[eE]"-"[1-9][0-9]*        yylval.d = strtod(yytext, nullptr); return tDOUBLE;

[1-9][0-9]*"."[0-9]+                          yylval.d = strtod(yytext, nullptr); return tDOUBLE;

0                                       yylval.i = strtol(yytext, nullptr, 10); return tINTEGER;
[1-9][0-9]*                             yylval.i = strtol(yytext, nullptr, 10); return tINTEGER;
"0x"[0-9a-fA-F]+                        yylval.i = strtol(yytext, nullptr, 16); return tINTEGER;

[-()<>=+*/%;{}.,@?&|~#$\[\]?]  return *yytext;

"//".*$                ; //ignore

[ \t\n]+               ; /* ignore whitespace */

.                      yyerror("Unknown character");

%%
// Very, very dirty hack: flex is a mess generating C++ scanners.
int zu_scanner::yywrap() { return 1; }
