%{
// $Id: zu_parser.y,v 1.24 2016/05/18 01:36:36 ist179055 Exp $
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
//-- don't change *any* of these --- END!
%}

%union {
  int                   i;	/* integer value */
  std::string          *s;	/* symbol name or string literal */
  double                d;      /* double value */
  bool                  b;
  basic_type           *basic;
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  zu::lvalue_node  *lvalue;
  zu::block_node *block_value;
  zu::declaration_node *declaration;
};

%token <i> tINTEGER
%token <d> tDOUBLE
%token <s> tIDENTIFIER tSTRING
%token <b> tIMPORT tEXPORT
%token tPRINT tRETURN tCONTINUE tBREAK

%right tRIGHT
%left tLEFT
%nonassoc tUNARY


%right '='
%left '|'
%left '&'
%nonassoc '~'
%left tEQ tNE
%left '<' '>' tGE tLE
%left '+' '-'
%left '*' '/' '%'
%nonassoc '?'
%nonassoc '(' ')' '[' ']'
%right ':'

%type <s> string
%type <node> stmt function_definition decl
%type <sequence> list decls exprs varsblock varsfor
%type <expression> expr
%type <lvalue> lval
%type <declaration> var vardecl varblock
%type <block_value> block
%type <basic> type

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

function_definition	: decls { compiler->ast($1); }
                        ;

list :       stmt	       { $$ = new cdk::sequence_node(LINE, $1); }
	   | list stmt         { $$ = new cdk::sequence_node(LINE, $2, $1); }
	   | list ',' stmt     { $$ = new cdk::sequence_node(LINE, $3, $1); }
	   ;

stmt   : expr ';'                                                           { $$ = new zu::evaluation_node(LINE, $1); }
       | expr '!'                                                           { $$ = new zu::print_node(LINE, $1); }
       | expr tPRINT                                                        { $$ = new zu::print_node(LINE, $1); }
       //| expr                                                               { $$ = $1; }
       | tRETURN                                                            { $$ = new zu::return_node(LINE); }
       | tCONTINUE                                                          { $$ = new zu::continue_node(LINE); }
       | tBREAK                                                             { $$ = new zu::break_node(LINE);    }
       | '[' expr ']' '#' stmt                                              { $$ = new zu::if_node(LINE, $2, $5); }
       | '[' expr ']' '?' stmt                                              { $$ = new zu::if_node(LINE, $2, $5); }
       | '[' expr ']' '?' stmt ':' stmt                                     { $$ = new zu::if_else_node(LINE, $2, $5, $7); }
       | '[' ';' ';' ']' stmt                                               { $$ = new zu::for_node(LINE, nullptr, nullptr, nullptr, $5); }
       | '[' ';' ';' exprs ']' stmt                                         { $$ = new zu::for_node(LINE, nullptr, nullptr, $4, $6); }
       | '[' ';' exprs ';' exprs ']' stmt                                   { $$ = new zu::for_node(LINE, nullptr, $3, $5, $7); }
       | '[' ';' exprs ';' ']' stmt                                         { $$ = new zu::for_node(LINE, nullptr, $3, nullptr, $6); }
       | '[' varsfor ';' ';' ']' stmt                                          { $$ = new zu::for_node(LINE, $2, nullptr, nullptr, $6); }
       | '[' varsfor ';' ';' exprs ']' stmt                                    { $$ = new zu::for_node(LINE, $2, nullptr, $5, $7); }
       | '[' varsfor ';' exprs ';' ']' stmt                                    { $$ = new zu::for_node(LINE, $2, $4, nullptr, $7); }
       | '[' varsfor ';' exprs ';' exprs ']' stmt                              { $$ = new zu::for_node(LINE, $2, $4, $6, $8); }
       | '[' exprs ';' exprs ';' exprs ']' stmt                             { $$ = new zu::for_node(LINE, $2, $4, $6, $8); }
       | block                                                              { $$ = $1; }
       ;
     
type : '#'                    { $$ = new basic_type(4, basic_type::TYPE_INT); }
     | '%'                    { $$ = new basic_type(8, basic_type::TYPE_DOUBLE); }
     | '$'                    { $$ = new basic_type(4, basic_type::TYPE_STRING); }
     | '!'                    { $$ = new basic_type(0, basic_type::TYPE_VOID); }
     | '<' type '>'           { $$ = new basic_type(4, basic_type::TYPE_POINTER); }
     ;
     
block : '{' '}'                           { $$ = new zu::block_node(LINE, nullptr, nullptr); }
      | '{' list '}'                      { $$ = new zu::block_node(LINE, nullptr, $2); }
      | '{' varsblock '}'                      { $$ = new zu::block_node(LINE, $2, nullptr); }
      | '{' varsblock  list '}'                { $$ = new zu::block_node(LINE, $2, $3); }
      ;

string : tSTRING                         { $$ = new std::string(*$1); } 
       | tSTRING string                  { $$ = new std::string(*$1 + *$2); }
       ;
      
exprs : expr	                          { $$ = new cdk::sequence_node(LINE, $1); }
      | exprs ',' expr                    { $$ = new cdk::sequence_node(LINE, $3, $1); }
      ;      
      
expr : tINTEGER                           { $$ = new cdk::integer_node(LINE, $1); }
     | string                             { $$ = new cdk::string_node(LINE, $1); }
     | tDOUBLE                            { $$ = new cdk::double_node(LINE, $1); }
     | '~' expr                           { $$ = new cdk::neg_node(LINE, $2); }
     | '-' expr %prec tUNARY              { $$ = new zu::simetric_node(LINE, $2); }
     | '+' expr %prec tUNARY              { $$ = new zu::identity_node(LINE, $2); }
     | '@'                                { $$ = new zu::read_node(LINE);        }
     | lval '?'                           { $$ = new zu::position_indicator_node(LINE, $1); }
     | expr '+' expr	                  { $$ = new cdk::add_node(LINE, $1, $3); }
     | expr '-' expr	                  { $$ = new cdk::sub_node(LINE, $1, $3); }
     | expr '*' expr	                  { $$ = new cdk::mul_node(LINE, $1, $3); }
     | expr '/' expr	                  { $$ = new cdk::div_node(LINE, $1, $3); }
     | expr '%' expr	                  { $$ = new cdk::mod_node(LINE, $1, $3); }
     | expr '<' expr	                  { $$ = new cdk::lt_node(LINE, $1, $3); }
     | expr '>' expr	                  { $$ = new cdk::gt_node(LINE, $1, $3); }
     | expr '&' expr                      { $$ = new zu::and_node(LINE, $1, $3); }
     | expr '|' expr                      { $$ = new zu::or_node(LINE, $1, $3);  }
     | expr tGE expr	                  { $$ = new cdk::ge_node(LINE, $1, $3); }
     | expr tLE expr                      { $$ = new cdk::le_node(LINE, $1, $3); }
     | expr tNE expr	                  { $$ = new cdk::ne_node(LINE, $1, $3); }
     | expr tEQ expr	                  { $$ = new cdk::eq_node(LINE, $1, $3); }
     | tIDENTIFIER '(' ')'                { $$ = new zu::function_call_node(LINE, nullptr, $1); }
     | tIDENTIFIER '(' exprs ')'          { $$ = new zu::function_call_node(LINE, $3, $1); }
     | '(' expr ')'                       { $$ = $2; }
     | '[' expr ']'                       { $$ = new zu::memory_reservation_node(LINE, $2); } //FIXME correct expr (change  to lvalue?)
     | lval                               { $$ = new zu::rvalue_node(LINE, $1); }  //FIXME
     | lval '=' expr                      { $$ = new zu::assignment_node(LINE, $1, $3); }
     ;

vardecl : varblock ';'                                      { $$ = $1; }
        ;
     
varsblock : vardecl                                    { $$ = new cdk::sequence_node(LINE, $1); }
          | varsblock vardecl                          { $$ = new cdk::sequence_node(LINE, $2, $1); }
          ;

     
varsfor : varblock                             { $$ = new cdk::sequence_node(LINE, $1); }
        | varsfor',' varblock                  { $$ = new cdk::sequence_node(LINE, $3, $1); }
        ;
     
varblock : type tIDENTIFIER                      { $$ = new zu::declaration_node(LINE, $1, $2, false, nullptr, false); }
         | type tIDENTIFIER '!'                  { $$ = new zu::declaration_node(LINE, $1, $2, false, nullptr, true); }
         | type tIDENTIFIER '?'                  { $$ = new zu::declaration_node(LINE, $1, $2, true, nullptr, false); }
         | type tIDENTIFIER '=' expr             { $$ = new zu::declaration_node(LINE, $1, $2, false, $4, false); }
         | type tIDENTIFIER '?' '=' expr         { $$ = new zu::declaration_node(LINE, $1, $2, true, $5, false); }
         | type tIDENTIFIER '!' '=' expr         { $$ = new zu::declaration_node(LINE, $1, $2, false, $5, true); }
         ;
    
var : type tIDENTIFIER                      { $$ = new zu::declaration_node(LINE, $1, $2, false, nullptr, true); }
    | type tIDENTIFIER '=' expr             { $$ = new zu::declaration_node(LINE, $1, $2, false, $4, true); }
    | type tIDENTIFIER '!' '=' expr         { $$ = new zu::declaration_node(LINE, $1, $2, false, $5, true); }
    ;
     
decls : decl                     { $$ = new cdk::sequence_node(LINE, $1); }
      | decls decl               { $$ = new cdk::sequence_node(LINE, $2, $1); }
      ;
     
decl : var ';'                                                           { $$ = $1; }
     | type tIDENTIFIER '?' '(' ')'                                      { $$ = new zu::function_declaration_node(LINE, nullptr, $1, $2, false, nullptr); }
     | type tIDENTIFIER '!' '(' ')'                                      { $$ = new zu::function_declaration_node(LINE, nullptr, $1, $2, true, nullptr); }
     | type tIDENTIFIER '!' '(' ')' block                                { $$ = new zu::function_definition_node(LINE, nullptr, $1, $2, $6, true, nullptr); }
     | type tIDENTIFIER '?' '(' ')' block                                { $$ = new zu::function_definition_node(LINE, nullptr, $1, $2, $6, false, nullptr); }
     | type tIDENTIFIER '!' '(' ')' '=' expr                             { $$ = new zu::function_declaration_node(LINE, nullptr, $1, $2, true, $7); }
     | type tIDENTIFIER '?' '(' ')' '=' expr                             { $$ = new zu::function_declaration_node(LINE, nullptr, $1, $2, false, $7); }
     | type tIDENTIFIER '!' '(' ')' '=' expr block                       { $$ = new zu::function_definition_node(LINE, nullptr, $1, $2, $8, true, $7); }
     | type tIDENTIFIER '?' '(' ')' '=' expr block                       { $$ = new zu::function_definition_node(LINE, nullptr, $1, $2, $8, false, $7); }
     | type tIDENTIFIER '!' '(' varsfor ')'                                 { $$ = new zu::function_declaration_node(LINE, $5, $1, $2, true, nullptr); }
     | type tIDENTIFIER '?' '(' varsfor ')'                                 { $$ = new zu::function_declaration_node(LINE, $5, $1, $2, false, nullptr); }
     | type tIDENTIFIER '!' '(' varsfor ')' block                           { $$ = new zu::function_definition_node(LINE, $5, $1, $2, $7, true, nullptr); }
     | type tIDENTIFIER '?' '(' varsfor ')' block                           { $$ = new zu::function_definition_node(LINE, $5, $1, $2, $7, false, nullptr); }
     | type tIDENTIFIER '!' '(' varsfor ')' '=' expr                        { $$ = new zu::function_declaration_node(LINE, $5, $1, $2, true, $8); }
     | type tIDENTIFIER '?' '(' varsfor ')' '=' expr                        { $$ = new zu::function_declaration_node(LINE, nullptr, $1, $2, false, nullptr); }
     | type tIDENTIFIER '!' '(' varsfor ')' '=' expr block                  { $$ = new zu::function_definition_node(LINE, $5, $1, $2, $9, true, $8); }
     | type tIDENTIFIER '?' '(' varsfor ')' '=' expr block                  { $$ = new zu::function_definition_node(LINE, $5, $1, $2, $9, false, $8); }
     
     | type tIDENTIFIER '(' ')'                                      { $$ = new zu::function_declaration_node(LINE, nullptr, $1, $2, true, nullptr); }
     | type tIDENTIFIER '(' ')' block                                { $$ = new zu::function_definition_node(LINE, nullptr, $1, $2, $5, true, nullptr); }
     | type tIDENTIFIER '(' ')' '=' expr                             { $$ = new zu::function_declaration_node(LINE, nullptr, $1, $2, true, $6); }
     | type tIDENTIFIER '(' ')' '=' expr block                       { $$ = new zu::function_definition_node(LINE, nullptr, $1, $2, $7, true, $6); }
     | type tIDENTIFIER '(' varsfor ')'                                 { $$ = new zu::function_declaration_node(LINE, $4, $1, $2, true, nullptr); }
     | type tIDENTIFIER '(' varsfor ')' block                           { $$ = new zu::function_definition_node(LINE, $4, $1, $2, $6, true, nullptr); }
     | type tIDENTIFIER '(' varsfor ')' '=' expr                        { $$ = new zu::function_declaration_node(LINE, $4, $1, $2, true, $7); }
     | type tIDENTIFIER '(' varsfor ')' '=' expr block                  { $$ = new zu::function_definition_node(LINE, $4, $1, $2, $8, true, $7); }
     ;

lval : tIDENTIFIER %prec tRIGHT                 { $$ = new zu::identifier_node(LINE, $1); }
     | expr '[' expr ']'                        { $$ = new zu::index_node(LINE, $1, $3); }
     | '(' expr ')' '[' expr ']'                { $$ = new zu::index_node(LINE, $2, $5); }
     ;

%%
