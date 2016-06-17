/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20150711

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "zu_parser.y"
/* $Id: zu_parser.y,v 1.24 2016/05/18 01:36:36 ist179055 Exp $*/
/*-- don't change *any* of these: if you do, you'll break the compiler.*/
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
/*-- don't change *any* of these --- END!*/
#line 14 "zu_parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
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
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 61 "zu_parser.y"
/*-- The rules below will be included in yyparse, the main parsing function.*/
#line 55 "zu_parser.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define tINTEGER 257
#define tDOUBLE 258
#define tIDENTIFIER 259
#define tSTRING 260
#define tIMPORT 261
#define tEXPORT 262
#define tPRINT 263
#define tRETURN 264
#define tCONTINUE 265
#define tBREAK 266
#define tRIGHT 267
#define tLEFT 268
#define tUNARY 269
#define tEQ 270
#define tNE 271
#define tGE 272
#define tLE 273
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    4,    4,    4,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,   15,   15,   15,   15,   15,   14,   14,
   14,   14,    1,    1,    6,    6,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,   12,    7,    7,    8,    8,   13,   13,
   13,   13,   13,   13,   11,   11,   11,    5,    5,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,   10,   10,   10,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    3,    2,    2,    2,    1,    1,    1,
    5,    5,    7,    5,    6,    7,    6,    6,    7,    7,
    8,    8,    1,    1,    1,    1,    1,    3,    2,    3,
    3,    4,    1,    2,    1,    3,    1,    1,    1,    2,
    2,    2,    1,    2,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    4,    3,
    3,    1,    3,    2,    1,    2,    1,    3,    2,    3,
    3,    4,    5,    5,    2,    4,    5,    1,    2,    2,
    5,    5,    6,    6,    7,    7,    8,    8,    6,    6,
    7,    7,    8,    8,    9,    9,    4,    5,    6,    7,
    5,    6,    7,    8,    1,    4,    6,
};
static const YYINT yydefred[] = {                         0,
    0,   25,   27,   24,   26,    0,   78,    0,    0,    0,
    0,   79,   80,    0,   28,    0,    0,    0,    0,   37,
   39,    0,    0,    0,    0,    0,    0,    0,   43,   38,
    0,    0,    0,    0,    0,   67,    0,    0,    0,    0,
   34,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   44,    0,    0,    0,    0,   98,    0,    0,    0,
    0,    0,    0,   58,    0,    0,   60,   61,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   84,    0,    0,    8,    9,   10,
    0,   29,    2,    0,    0,    0,   65,    0,   23,    0,
  102,   68,    0,    0,    0,    0,   83,    0,   59,    0,
    0,  106,    0,    0,   92,  100,    0,    0,    0,    0,
    0,   30,    3,   31,    0,   66,    7,    5,    6,   64,
    0,    0,    0,    0,    0,    0,   91,    0,    0,   88,
    0,    0,    0,    0,    0,    0,    4,   32,  104,    0,
    0,   87,    0,  107,   96,    0,    0,    0,    0,    0,
    0,    0,    0,   95,   14,    0,    0,    0,    0,    0,
    0,    0,    0,   11,   15,   17,    0,    0,   18,    0,
    0,    0,    0,   16,    0,   19,   20,    0,   13,   22,
   21,
};
static const YYINT yydgoto[] = {                          6,
   30,  103,    7,  104,    8,   75,  105,   35,  106,   32,
    9,  107,   36,  109,   37,
};
static const YYINT yysindex[] = {                       491,
  491,    0,    0,    0,    0,    0,    0,  491,  -59, -227,
   27,    0,    0,   55,    0, 1124,   51,  550,   -9,    0,
    0,   57, -207, 1124, 1124, 1124, 1124, 1124,    0,    0,
  875,  -28,  610,  -57,  -15,    0, -161, 1124,  645,  995,
    0,  910,  875,  875,  597,  759, 1124, 1124, 1124, 1124,
 1124, 1124, 1124, 1124, 1124, 1124, 1124, 1124, 1124, 1124,
 1124,    0,  -56,   13, 1124,  943,    0,  -44,  491,  163,
  875,  -43,   52,    0,   73,  875,    0,    0,  886,  910,
  -35,  -35,  290,  290,  290,  290,  -26,  -26,   29,   29,
   29,  780,  875, 1124,    0,  -37,  791,    0,    0,    0,
 1063,    0,    0,  953, 1037,  691,    0,   75,    0, 1124,
    0,    0, 1124,   76,   95, 1124,    0,  -33,    0, 1124,
 1124,    0,  791, 1124,    0,    0, 1133,  -29,   77,  817,
  237,    0,    0,    0,  969,    0,    0,    0,    0,    0,
  791,  875, 1124, 1124,  791, 1124,    0,  875,  847,    0,
  791, 1180,  139, 1124, 1198,  -22,    0,    0,    0,  875,
  875,    0,  791,    0,    0,  237,  -38, 1218,  140, 1224,
  149,  237,  237,    0,    0,  237,  237,  -24, 1124,  237,
  -21, 1240,  102,    0,    0,    0,  237,   15,    0,  237,
  237,   26,  237,    0,  237,    0,    0,  237,    0,    0,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,  162,    0,    0,
    0,    0,    0,  106,    0,    0,    0,    0,    0,    0,
    0,    1,   40,    0,    0,    0,    0,    0,    0,    0,
  126,   68,    0,   14,    0,    0,    0,    0,    0,    0,
    0,  243,  617,  633,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  153,    0,    0,    0,    0,  255,    0,  264,
  142,  283,    0,    0,    0,   82,    0,    0,  525,  567,
  500,  504,  359,  426,  430,  472,  206,  309,  107,  135,
  174,    0,  671,    0,    0,  351,  122,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  331,  355,    0,    0,  420,    0,    0,
    0,    0,  187,    0,    0,    0,    0,    0,    0,  170,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  227,  368,    0,    0,  289,    0,    0,   88,    0,    0,
  389,    0,    0,    0,    0,  748,    0,    0,    0,  369,
  390,    0,  415,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 1070,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
  179, 1228,  195,   99,    0,  194,    0,  -30, 1463,    0,
    0,  100,  -47, 1244,  138,
};
#define YYTABLESIZE 1645
static const YYINT yytable[] = {                         13,
  105,   59,   64,   65,   94,  120,   57,   55,   73,   56,
   59,   58,  173,   97,  120,   57,  110,  116,  108,  120,
   58,  112,  120,  124,   51,   68,   52,  146,   69,  154,
   39,   14,   61,  105,   62,  105,  105,  105,  105,   33,
  172,  105,  105,  105,  105,  105,   97,  105,   97,   97,
   97,   38,   23,   96,  176,   60,   69,  108,  120,  105,
  105,  105,  105,  105,   60,   66,   66,   62,  187,  120,
  129,  190,   33,   97,   33,   33,   33,   33,   66,   66,
   33,   33,   33,   33,   33,   66,   33,   19,   15,   66,
   33,  105,  118,  105,   18,   69,   40,   70,   33,   33,
   62,   33,   62,   62,   62,   62,   47,  195,   62,   62,
   62,   62,   62,  119,   62,   16,  120,   17,  198,   60,
   69,   99,   35,  105,  105,   35,   62,   62,   36,   62,
   33,   36,   33,  140,   48,  155,  143,   10,   11,   47,
   35,   47,   47,   47,   47,   10,   36,   47,   47,   47,
   47,   47,   81,   47,   99,  144,   99,   99,   62,  193,
   62,    1,   33,   33,   75,   47,   47,   48,   47,   48,
   48,   48,   48,   49,   35,   48,   48,   48,   48,   48,
   36,   48,  120,  120,   76,   81,   86,   81,   81,   81,
   62,   62,  120,   48,   48,  115,   48,  168,  179,   47,
   77,   41,   12,  135,  136,   45,   49,  182,   49,   49,
   49,   49,   81,   35,   49,   49,   49,   49,   49,   86,
   49,   86,   86,  113,    0,  114,  103,   48,   35,   47,
   47,    0,   49,   49,    0,   49,   53,   54,   45,    0,
   45,   45,   40,   45,    0,    0,   45,    0,   45,   45,
   45,    0,    0,    0,  101,    0,    0,   48,   48,  103,
    0,  103,  103,  105,   45,   45,   49,   45,    0,    0,
  105,  105,  105,  105,    0,   40,   27,   40,   40,   25,
   40,   26,   82,   40,    0,    0,   40,  101,   85,  101,
  101,  101,    0,    0,  128,    0,   49,   49,   45,    0,
   29,   40,   33,    0,   69,    0,    0,   69,   46,   33,
   33,   33,   33,    0,  101,   82,    0,   82,   82,   82,
  153,   85,   69,   85,   85,    0,   59,  101,   45,   45,
   62,   57,   55,    0,   56,   40,   58,   62,   62,   62,
   62,   46,   82,   46,   46,  167,   46,  169,  171,   46,
   90,   46,   46,   46,    0,    0,    0,    0,   50,   66,
    0,  178,   24,  181,    0,   40,   40,   46,   46,   47,
   46,   71,  188,    0,   71,  192,   47,   47,   47,   47,
   60,    0,    0,   90,    0,   90,   90,   90,   94,   71,
    0,   50,    0,   50,   50,   70,   50,   48,   70,   50,
    0,   46,   50,    0,   48,   48,   48,   48,   72,   73,
   90,   72,   73,   70,   93,    0,    0,   50,   50,   89,
   50,   94,    0,   94,   94,   51,   72,   73,    0,   54,
   74,   46,   46,   74,    0,    0,   49,    0,    0,    0,
    0,    0,    0,   49,   49,   49,   49,   93,   74,   93,
   93,   50,   89,    0,   89,   89,   89,    0,   51,    0,
   51,   51,   54,   51,   54,   54,   51,   54,   45,   51,
   54,   55,    0,   54,    0,   45,   45,   45,   45,   89,
    0,   50,   50,    0,   51,   51,    0,   51,   54,   54,
    0,   54,    0,   20,   21,   22,   23,    0,    0,   57,
   98,   99,  100,   56,   55,   40,   55,   55,    0,   55,
    0,    0,   55,    0,    0,   55,    0,    0,   51,    0,
    0,    0,   54,    3,   53,    4,    5,    2,    0,    0,
   55,   55,   57,   55,   57,   57,   56,   57,   56,   56,
   57,   56,    0,   57,   56,    0,    0,   56,   51,   51,
    1,    0,   54,   54,    0,    0,    0,   53,   57,   53,
   53,    0,   56,    0,   55,   53,   52,    0,   53,    0,
    0,   46,    0,    0,    0,    0,    0,    0,   46,   46,
   46,   46,    3,   53,    4,    5,    2,    0,    0,    0,
   34,    0,   57,    0,   55,   55,   56,    0,    0,   52,
    0,   52,   52,    0,   52,    0,    0,   52,    0,    1,
   52,    0,    0,    0,    0,    0,   42,   53,    0,    0,
    0,   50,   57,   57,    0,   52,   56,   56,   50,   50,
   50,   50,   41,   59,   48,    0,    0,   77,   57,   55,
    0,   56,    3,   58,    4,    5,    2,   53,   53,   42,
   63,   42,   42,    0,    0,    0,   51,   42,   52,   52,
   42,    0,    0,    0,    0,   41,    0,   41,   41,    1,
   63,    0,    0,   41,    0,   42,   41,    3,    0,    4,
    5,    2,    0,    0,    0,   72,    0,   60,   51,   52,
   52,   41,   54,    0,    0,   51,   51,   51,   51,   54,
   54,   54,   54,   63,    1,   63,   63,    0,    0,   42,
    0,   63,    0,    0,   63,    0,    0,    0,    0,    0,
   47,    0,    0,  139,    0,   41,    0,   59,   48,   63,
    0,    0,   57,   55,   55,   56,    0,   58,    0,   42,
    0,   55,   55,   55,   55,    0,    0,    0,    0,  138,
   51,    0,   52,    0,    0,   41,    0,    0,    0,    0,
    0,    0,   57,   63,    0,    0,   56,    0,    0,   57,
   57,    0,    0,   56,   56,    0,    0,    0,    0,    0,
   61,   60,    0,    0,   61,   61,    0,   53,    0,   61,
   61,    0,   61,   63,   61,   59,   48,    0,    0,    0,
   57,   55,    0,   56,    0,   58,   61,   61,    0,   61,
    0,    0,    0,    0,   47,    0,   59,   48,   51,    0,
   52,   57,   55,    0,   56,    0,   58,   59,   48,   52,
    0,    0,   57,   55,    0,   56,    0,   58,   61,   51,
    0,   52,    0,    0,    0,    0,    0,    0,    0,   60,
   51,   78,   52,   59,   48,    0,    0,    0,   57,   55,
    0,   56,    0,   58,    0,    0,   49,   50,   53,   54,
   60,   61,  122,    0,    0,    0,   51,    0,   52,   42,
    0,   60,   47,   59,   48,    0,    0,    0,   57,   55,
    0,   56,    0,   58,    0,   41,    0,    0,    0,    0,
    0,    0,    0,   47,    0,    0,   51,   60,   52,  156,
    0,   59,   48,   66,   47,    0,   57,   55,    0,   56,
    0,   58,   59,   48,    0,    0,    0,   57,   55,    0,
   56,    0,   58,   63,   51,    0,   52,   60,    0,  164,
   47,    0,    0,    0,    0,   51,   59,   52,    0,    0,
    0,   57,   55,  137,   56,    0,   58,    0,    0,    0,
   49,   50,   53,   54,    0,   60,    0,    0,    0,   51,
   47,   52,    0,    0,    0,    3,   60,    4,    5,    2,
    0,    0,   27,    0,    0,   25,    0,   26,    0,    0,
    0,    0,   27,    0,    0,   25,  131,   26,   47,    0,
   60,    0,    1,    0,    0,    0,   29,    0,   27,    0,
   61,   25,  131,   26,    0,    0,   29,   61,   61,   61,
   61,    0,    0,    0,    0,    0,    0,    0,   49,   50,
   53,   54,   29,  101,   27,   74,    0,   25,    0,   26,
    0,    0,    0,  101,    0,    0,    0,    0,    0,   49,
   50,   53,   54,    0,    0,    0,    0,    0,   29,  101,
   49,   50,   53,   54,    0,   66,    0,  102,   24,    3,
    0,    4,    5,    2,    0,   66,   27,  132,   24,   25,
    0,   26,    0,    0,    0,   28,   49,   50,   53,   54,
    0,   66,    0,  158,   24,    3,    1,    4,    5,    2,
   29,    0,   27,    0,    0,   25,    0,   26,    0,   12,
    0,    0,   12,   12,   12,    0,   49,   50,   53,   54,
   24,  127,    1,    0,    0,    0,   29,  101,    0,    0,
    0,    0,    0,   12,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   49,   50,   53,   54,    0,    0,
    0,    0,    0,   28,    0,   49,   50,   53,   54,   66,
   12,  134,   24,   27,    0,    0,   25,    0,   26,    0,
    0,    0,   27,    0,    0,   25,    0,   26,    0,   49,
   50,   53,   54,    0,    0,    0,    0,   29,   24,    0,
    0,  152,   12,    0,   12,   12,   29,    0,    0,   20,
   21,   22,   23,    0,    0,    0,   98,   99,  100,   20,
   21,   22,   23,    0,   28,    0,   98,   99,  100,   27,
    0,    0,   25,   28,   26,   20,   21,   22,   23,    0,
    0,    0,   98,   99,  100,    0,    0,   27,    0,    0,
   25,    0,   26,   29,    0,    0,    0,    0,    0,   24,
    0,   20,   21,   22,   23,    0,  170,   27,   24,    0,
   25,   29,   26,   27,    0,    0,   25,    0,   26,    0,
   28,    0,  166,    0,    0,    0,    0,   67,    0,   27,
    0,   29,   25,    0,   26,    0,    0,   29,   28,    0,
    0,    0,    0,   20,   21,   22,   23,    0,    0,    0,
   98,   99,  100,   29,    0,   24,   95,    0,   28,    0,
  177,  111,    0,    0,   28,  117,  180,    0,    0,   20,
   21,   22,   23,   24,    0,    0,   12,   12,   12,   12,
   28,  133,  191,   12,   12,   12,    0,    0,    0,  125,
  126,    0,    0,   24,    0,    0,    0,    0,    0,   24,
    0,    0,    0,    0,    0,    0,    0,    0,  157,    0,
    0,  147,  133,    0,    0,   24,  150,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   20,   21,   22,   23,  159,    0,    0,    0,  162,   20,
   21,   22,   23,  175,  165,    0,    0,    0,    0,  183,
  184,    0,    0,  185,  186,    0,  174,  189,    0,    0,
    0,    0,    0,    0,  194,    0,    0,  196,  197,    0,
  199,    0,  200,    0,    0,  201,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   20,   21,   22,   23,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   20,   21,   22,   23,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   20,   21,   22,   23,   31,    0,
   20,   21,   22,   23,    0,    0,   42,   43,   44,   45,
   46,    0,    0,    0,    0,    0,   20,   21,   22,   23,
   71,    0,   76,    0,    0,    0,    0,    0,    0,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,
   90,   91,   92,   93,    0,    0,    0,   97,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  123,    0,    0,    0,
    0,    0,    0,  130,    0,    0,    0,    0,    0,    0,
    0,    0,  141,    0,    0,  142,    0,    0,  145,    0,
    0,    0,  148,  149,    0,    0,  151,    0,    0,   76,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  160,  161,    0,  163,    0,
    0,    0,    0,    0,   76,    0,   76,   76,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   76,    0,   76,    0,    0,    0,    0,    0,    0,    0,
    0,   76,    0,    0,   76,
};
static const YYINT yycheck[] = {                         59,
    0,   37,   33,   61,   61,   44,   42,   43,   39,   45,
   37,   47,   35,    0,   44,   42,   61,   61,   66,   44,
   47,   69,   44,   61,   60,   41,   62,   61,   44,   59,
   40,  259,   61,   33,   63,   35,   36,   37,   38,    0,
   63,   41,   42,   43,   44,   45,   33,   47,   35,   36,
   37,   61,  260,   41,   93,   91,   44,  105,   44,   59,
   60,   61,   62,   63,   91,  123,  123,    0,   93,   44,
  101,   93,   33,   60,   35,   36,   37,   38,  123,  123,
   41,   42,   43,   44,   45,  123,   47,   33,   62,  123,
   40,   91,   41,   93,   40,   44,   40,  259,   59,   60,
   33,   62,   35,   36,   37,   38,    0,   93,   41,   42,
   43,   44,   45,   41,   47,   61,   44,   63,   93,   91,
   44,    0,   41,  123,  124,   44,   59,   60,   41,   62,
   91,   44,   93,   59,    0,   59,   61,    0,    1,   33,
   59,   35,   36,   37,   38,    8,   59,   41,   42,   43,
   44,   45,    0,   47,   33,   61,   35,   36,   91,   58,
   93,    0,  123,  124,   59,   59,   60,   33,   62,   35,
   36,   37,   38,    0,   93,   41,   42,   43,   44,   45,
   93,   47,   44,   44,   59,   33,    0,   35,   36,   37,
  123,  124,   44,   59,   60,   33,   62,   59,   59,   93,
   59,   23,    8,  105,  105,    0,   33,   59,   35,   36,
   37,   38,   60,   44,   41,   42,   43,   44,   45,   33,
   47,   35,   36,   61,   -1,   63,    0,   93,   59,  123,
  124,   -1,   59,   60,   -1,   62,  272,  273,   33,   -1,
   35,   36,    0,   38,   -1,   -1,   41,   -1,   43,   44,
   45,   -1,   -1,   -1,    0,   -1,   -1,  123,  124,   33,
   -1,   35,   36,  263,   59,   60,   93,   62,   -1,   -1,
  270,  271,  272,  273,   -1,   33,   40,   35,   36,   43,
   38,   45,    0,   41,   -1,   -1,   44,   33,    0,   35,
   36,   37,   -1,   -1,  101,   -1,  123,  124,   93,   -1,
   64,   59,  263,   -1,   41,   -1,   -1,   44,    0,  270,
  271,  272,  273,   -1,   60,   33,   -1,   35,   36,   37,
  127,   33,   59,   35,   36,   -1,   37,   91,  123,  124,
  263,   42,   43,   -1,   45,   93,   47,  270,  271,  272,
  273,   33,   60,   35,   36,  152,   38,  154,  155,   41,
    0,   43,   44,   45,   -1,   -1,   -1,   -1,    0,  123,
   -1,  168,  126,  170,   -1,  123,  124,   59,   60,  263,
   62,   41,  179,   -1,   44,  182,  270,  271,  272,  273,
   91,   -1,   -1,   33,   -1,   35,   36,   37,    0,   59,
   -1,   33,   -1,   35,   36,   41,   38,  263,   44,   41,
   -1,   93,   44,   -1,  270,  271,  272,  273,   41,   41,
   60,   44,   44,   59,    0,   -1,   -1,   59,   60,    0,
   62,   33,   -1,   35,   36,    0,   59,   59,   -1,    0,
   41,  123,  124,   44,   -1,   -1,  263,   -1,   -1,   -1,
   -1,   -1,   -1,  270,  271,  272,  273,   33,   59,   35,
   36,   93,   33,   -1,   35,   36,   37,   -1,   33,   -1,
   35,   36,   33,   38,   35,   36,   41,   38,  263,   44,
   41,    0,   -1,   44,   -1,  270,  271,  272,  273,   60,
   -1,  123,  124,   -1,   59,   60,   -1,   62,   59,   60,
   -1,   62,   -1,  257,  258,  259,  260,   -1,   -1,    0,
  264,  265,  266,    0,   33,  263,   35,   36,   -1,   38,
   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   93,   -1,
   -1,   -1,   93,   33,    0,   35,   36,   37,   -1,   -1,
   59,   60,   33,   62,   35,   36,   33,   38,   35,   36,
   41,   38,   -1,   44,   41,   -1,   -1,   44,  123,  124,
   60,   -1,  123,  124,   -1,   -1,   -1,   33,   59,   35,
   36,   -1,   59,   -1,   93,   41,    0,   -1,   44,   -1,
   -1,  263,   -1,   -1,   -1,   -1,   -1,   -1,  270,  271,
  272,  273,   33,   59,   35,   36,   37,   -1,   -1,   -1,
   41,   -1,   93,   -1,  123,  124,   93,   -1,   -1,   33,
   -1,   35,   36,   -1,   38,   -1,   -1,   41,   -1,   60,
   44,   -1,   -1,   -1,   -1,   -1,    0,   93,   -1,   -1,
   -1,  263,  123,  124,   -1,   59,  123,  124,  270,  271,
  272,  273,    0,   37,   38,   -1,   -1,   41,   42,   43,
   -1,   45,   33,   47,   35,   36,   37,  123,  124,   33,
   41,   35,   36,   -1,   -1,   -1,   60,   41,   62,   93,
   44,   -1,   -1,   -1,   -1,   33,   -1,   35,   36,   60,
    0,   -1,   -1,   41,   -1,   59,   44,   33,   -1,   35,
   36,   37,   -1,   -1,   -1,   41,   -1,   91,  263,  123,
  124,   59,  263,   -1,   -1,  270,  271,  272,  273,  270,
  271,  272,  273,   33,   60,   35,   36,   -1,   -1,   93,
   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,
  124,   -1,   -1,   33,   -1,   93,   -1,   37,   38,   59,
   -1,   -1,   42,   43,  263,   45,   -1,   47,   -1,  123,
   -1,  270,  271,  272,  273,   -1,   -1,   -1,   -1,   59,
   60,   -1,   62,   -1,   -1,  123,   -1,   -1,   -1,   -1,
   -1,   -1,  263,   93,   -1,   -1,  263,   -1,   -1,  270,
  271,   -1,   -1,  270,  271,   -1,   -1,   -1,   -1,   -1,
   33,   91,   -1,   -1,   37,   38,   -1,  263,   -1,   42,
   43,   -1,   45,  123,   47,   37,   38,   -1,   -1,   -1,
   42,   43,   -1,   45,   -1,   47,   59,   60,   -1,   62,
   -1,   -1,   -1,   -1,  124,   -1,   37,   38,   60,   -1,
   62,   42,   43,   -1,   45,   -1,   47,   37,   38,  263,
   -1,   -1,   42,   43,   -1,   45,   -1,   47,   91,   60,
   -1,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   91,
   60,   93,   62,   37,   38,   -1,   -1,   -1,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,  270,  271,  272,  273,
   91,  124,   93,   -1,   -1,   -1,   60,   -1,   62,  263,
   -1,   91,  124,   37,   38,   -1,   -1,   -1,   42,   43,
   -1,   45,   -1,   47,   -1,  263,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  124,   -1,   -1,   60,   91,   62,   93,
   -1,   37,   38,  123,  124,   -1,   42,   43,   -1,   45,
   -1,   47,   37,   38,   -1,   -1,   -1,   42,   43,   -1,
   45,   -1,   47,  263,   60,   -1,   62,   91,   -1,   93,
  124,   -1,   -1,   -1,   -1,   60,   37,   62,   -1,   -1,
   -1,   42,   43,  263,   45,   -1,   47,   -1,   -1,   -1,
  270,  271,  272,  273,   -1,   91,   -1,   -1,   -1,   60,
  124,   62,   -1,   -1,   -1,   33,   91,   35,   36,   37,
   -1,   -1,   40,   -1,   -1,   43,   -1,   45,   -1,   -1,
   -1,   -1,   40,   -1,   -1,   43,   44,   45,  124,   -1,
   91,   -1,   60,   -1,   -1,   -1,   64,   -1,   40,   -1,
  263,   43,   44,   45,   -1,   -1,   64,  270,  271,  272,
  273,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  270,  271,
  272,  273,   64,   91,   40,   41,   -1,   43,   -1,   45,
   -1,   -1,   -1,   91,   -1,   -1,   -1,   -1,   -1,  270,
  271,  272,  273,   -1,   -1,   -1,   -1,   -1,   64,   91,
  270,  271,  272,  273,   -1,  123,   -1,  125,  126,   33,
   -1,   35,   36,   37,   -1,  123,   40,  125,  126,   43,
   -1,   45,   -1,   -1,   -1,   91,  270,  271,  272,  273,
   -1,  123,   -1,  125,  126,   33,   60,   35,   36,   37,
   64,   -1,   40,   -1,   -1,   43,   -1,   45,   -1,   40,
   -1,   -1,   43,   44,   45,   -1,  270,  271,  272,  273,
  126,   59,   60,   -1,   -1,   -1,   64,   91,   -1,   -1,
   -1,   -1,   -1,   64,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  270,  271,  272,  273,   -1,   -1,
   -1,   -1,   -1,   91,   -1,  270,  271,  272,  273,  123,
   91,  125,  126,   40,   -1,   -1,   43,   -1,   45,   -1,
   -1,   -1,   40,   -1,   -1,   43,   -1,   45,   -1,  270,
  271,  272,  273,   -1,   -1,   -1,   -1,   64,  126,   -1,
   -1,   59,  123,   -1,  125,  126,   64,   -1,   -1,  257,
  258,  259,  260,   -1,   -1,   -1,  264,  265,  266,  257,
  258,  259,  260,   -1,   91,   -1,  264,  265,  266,   40,
   -1,   -1,   43,   91,   45,  257,  258,  259,  260,   -1,
   -1,   -1,  264,  265,  266,   -1,   -1,   40,   -1,   -1,
   43,   -1,   45,   64,   -1,   -1,   -1,   -1,   -1,  126,
   -1,  257,  258,  259,  260,   -1,   59,   40,  126,   -1,
   43,   64,   45,   40,   -1,   -1,   43,   -1,   45,   -1,
   91,   -1,   93,   -1,   -1,   -1,   -1,   34,   -1,   40,
   -1,   64,   43,   -1,   45,   -1,   -1,   64,   91,   -1,
   -1,   -1,   -1,  257,  258,  259,  260,   -1,   -1,   -1,
  264,  265,  266,   64,   -1,  126,   63,   -1,   91,   -1,
   93,   68,   -1,   -1,   91,   72,   93,   -1,   -1,  257,
  258,  259,  260,  126,   -1,   -1,  257,  258,  259,  260,
   91,  104,   93,  264,  265,  266,   -1,   -1,   -1,   96,
   97,   -1,   -1,  126,   -1,   -1,   -1,   -1,   -1,  126,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  131,   -1,
   -1,  118,  135,   -1,   -1,  126,  123,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  257,  258,  259,  260,  141,   -1,   -1,   -1,  145,  257,
  258,  259,  260,  166,  151,   -1,   -1,   -1,   -1,  172,
  173,   -1,   -1,  176,  177,   -1,  163,  180,   -1,   -1,
   -1,   -1,   -1,   -1,  187,   -1,   -1,  190,  191,   -1,
  193,   -1,  195,   -1,   -1,  198,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,   16,   -1,
  257,  258,  259,  260,   -1,   -1,   24,   25,   26,   27,
   28,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
   38,   -1,   40,   -1,   -1,   -1,   -1,   -1,   -1,   47,
   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,
   58,   59,   60,   61,   -1,   -1,   -1,   65,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   94,   -1,   -1,   -1,
   -1,   -1,   -1,  101,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  110,   -1,   -1,  113,   -1,   -1,  116,   -1,
   -1,   -1,  120,  121,   -1,   -1,  124,   -1,   -1,  127,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  143,  144,   -1,  146,   -1,
   -1,   -1,   -1,   -1,  152,   -1,  154,  155,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  168,   -1,  170,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  179,   -1,   -1,  182,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 273
#define YYUNDFTOKEN 291
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'","'$'","'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,
0,0,0,0,0,0,0,0,0,"':'","';'","'<'","'='","'>'","'?'","'@'",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tINTEGER",
"tDOUBLE","tIDENTIFIER","tSTRING","tIMPORT","tEXPORT","tPRINT","tRETURN",
"tCONTINUE","tBREAK","tRIGHT","tLEFT","tUNARY","tEQ","tNE","tGE","tLE",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : function_definition",
"function_definition : decls",
"list : stmt",
"list : list stmt",
"list : list ',' stmt",
"stmt : expr ';'",
"stmt : expr '!'",
"stmt : expr tPRINT",
"stmt : tRETURN",
"stmt : tCONTINUE",
"stmt : tBREAK",
"stmt : '[' expr ']' '#' stmt",
"stmt : '[' expr ']' '?' stmt",
"stmt : '[' expr ']' '?' stmt ':' stmt",
"stmt : '[' ';' ';' ']' stmt",
"stmt : '[' ';' ';' exprs ']' stmt",
"stmt : '[' ';' exprs ';' exprs ']' stmt",
"stmt : '[' ';' exprs ';' ']' stmt",
"stmt : '[' varsfor ';' ';' ']' stmt",
"stmt : '[' varsfor ';' ';' exprs ']' stmt",
"stmt : '[' varsfor ';' exprs ';' ']' stmt",
"stmt : '[' varsfor ';' exprs ';' exprs ']' stmt",
"stmt : '[' exprs ';' exprs ';' exprs ']' stmt",
"stmt : block",
"type : '#'",
"type : '%'",
"type : '$'",
"type : '!'",
"type : '<' type '>'",
"block : '{' '}'",
"block : '{' list '}'",
"block : '{' varsblock '}'",
"block : '{' varsblock list '}'",
"string : tSTRING",
"string : tSTRING string",
"exprs : expr",
"exprs : exprs ',' expr",
"expr : tINTEGER",
"expr : string",
"expr : tDOUBLE",
"expr : '~' expr",
"expr : '-' expr",
"expr : '+' expr",
"expr : '@'",
"expr : lval '?'",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : expr tGE expr",
"expr : expr tLE expr",
"expr : expr tNE expr",
"expr : expr tEQ expr",
"expr : tIDENTIFIER '(' ')'",
"expr : tIDENTIFIER '(' exprs ')'",
"expr : '(' expr ')'",
"expr : '[' expr ']'",
"expr : lval",
"expr : lval '=' expr",
"vardecl : varblock ';'",
"varsblock : vardecl",
"varsblock : varsblock vardecl",
"varsfor : varblock",
"varsfor : varsfor ',' varblock",
"varblock : type tIDENTIFIER",
"varblock : type tIDENTIFIER '!'",
"varblock : type tIDENTIFIER '?'",
"varblock : type tIDENTIFIER '=' expr",
"varblock : type tIDENTIFIER '?' '=' expr",
"varblock : type tIDENTIFIER '!' '=' expr",
"var : type tIDENTIFIER",
"var : type tIDENTIFIER '=' expr",
"var : type tIDENTIFIER '!' '=' expr",
"decls : decl",
"decls : decls decl",
"decl : var ';'",
"decl : type tIDENTIFIER '?' '(' ')'",
"decl : type tIDENTIFIER '!' '(' ')'",
"decl : type tIDENTIFIER '!' '(' ')' block",
"decl : type tIDENTIFIER '?' '(' ')' block",
"decl : type tIDENTIFIER '!' '(' ')' '=' expr",
"decl : type tIDENTIFIER '?' '(' ')' '=' expr",
"decl : type tIDENTIFIER '!' '(' ')' '=' expr block",
"decl : type tIDENTIFIER '?' '(' ')' '=' expr block",
"decl : type tIDENTIFIER '!' '(' varsfor ')'",
"decl : type tIDENTIFIER '?' '(' varsfor ')'",
"decl : type tIDENTIFIER '!' '(' varsfor ')' block",
"decl : type tIDENTIFIER '?' '(' varsfor ')' block",
"decl : type tIDENTIFIER '!' '(' varsfor ')' '=' expr",
"decl : type tIDENTIFIER '?' '(' varsfor ')' '=' expr",
"decl : type tIDENTIFIER '!' '(' varsfor ')' '=' expr block",
"decl : type tIDENTIFIER '?' '(' varsfor ')' '=' expr block",
"decl : type tIDENTIFIER '(' ')'",
"decl : type tIDENTIFIER '(' ')' block",
"decl : type tIDENTIFIER '(' ')' '=' expr",
"decl : type tIDENTIFIER '(' ')' '=' expr block",
"decl : type tIDENTIFIER '(' varsfor ')'",
"decl : type tIDENTIFIER '(' varsfor ')' block",
"decl : type tIDENTIFIER '(' varsfor ')' '=' expr",
"decl : type tIDENTIFIER '(' varsfor ')' '=' expr block",
"lval : tIDENTIFIER",
"lval : expr '[' expr ']'",
"lval : '(' expr ')' '[' expr ']'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 65 "zu_parser.y"
	{ compiler->ast(yystack.l_mark[0].sequence); }
break;
case 2:
#line 68 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 3:
#line 69 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 4:
#line 70 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-2].sequence); }
break;
case 5:
#line 73 "zu_parser.y"
	{ yyval.node = new zu::evaluation_node(LINE, yystack.l_mark[-1].expression); }
break;
case 6:
#line 74 "zu_parser.y"
	{ yyval.node = new zu::print_node(LINE, yystack.l_mark[-1].expression); }
break;
case 7:
#line 75 "zu_parser.y"
	{ yyval.node = new zu::print_node(LINE, yystack.l_mark[-1].expression); }
break;
case 8:
#line 77 "zu_parser.y"
	{ yyval.node = new zu::return_node(LINE); }
break;
case 9:
#line 78 "zu_parser.y"
	{ yyval.node = new zu::continue_node(LINE); }
break;
case 10:
#line 79 "zu_parser.y"
	{ yyval.node = new zu::break_node(LINE);    }
break;
case 11:
#line 80 "zu_parser.y"
	{ yyval.node = new zu::if_node(LINE, yystack.l_mark[-3].expression, yystack.l_mark[0].node); }
break;
case 12:
#line 81 "zu_parser.y"
	{ yyval.node = new zu::if_node(LINE, yystack.l_mark[-3].expression, yystack.l_mark[0].node); }
break;
case 13:
#line 82 "zu_parser.y"
	{ yyval.node = new zu::if_else_node(LINE, yystack.l_mark[-5].expression, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 14:
#line 83 "zu_parser.y"
	{ yyval.node = new zu::for_node(LINE, nullptr, nullptr, nullptr, yystack.l_mark[0].node); }
break;
case 15:
#line 84 "zu_parser.y"
	{ yyval.node = new zu::for_node(LINE, nullptr, nullptr, yystack.l_mark[-2].sequence, yystack.l_mark[0].node); }
break;
case 16:
#line 85 "zu_parser.y"
	{ yyval.node = new zu::for_node(LINE, nullptr, yystack.l_mark[-4].sequence, yystack.l_mark[-2].sequence, yystack.l_mark[0].node); }
break;
case 17:
#line 86 "zu_parser.y"
	{ yyval.node = new zu::for_node(LINE, nullptr, yystack.l_mark[-3].sequence, nullptr, yystack.l_mark[0].node); }
break;
case 18:
#line 87 "zu_parser.y"
	{ yyval.node = new zu::for_node(LINE, yystack.l_mark[-4].sequence, nullptr, nullptr, yystack.l_mark[0].node); }
break;
case 19:
#line 88 "zu_parser.y"
	{ yyval.node = new zu::for_node(LINE, yystack.l_mark[-5].sequence, nullptr, yystack.l_mark[-2].sequence, yystack.l_mark[0].node); }
break;
case 20:
#line 89 "zu_parser.y"
	{ yyval.node = new zu::for_node(LINE, yystack.l_mark[-5].sequence, yystack.l_mark[-3].sequence, nullptr, yystack.l_mark[0].node); }
break;
case 21:
#line 90 "zu_parser.y"
	{ yyval.node = new zu::for_node(LINE, yystack.l_mark[-6].sequence, yystack.l_mark[-4].sequence, yystack.l_mark[-2].sequence, yystack.l_mark[0].node); }
break;
case 22:
#line 91 "zu_parser.y"
	{ yyval.node = new zu::for_node(LINE, yystack.l_mark[-6].sequence, yystack.l_mark[-4].sequence, yystack.l_mark[-2].sequence, yystack.l_mark[0].node); }
break;
case 23:
#line 92 "zu_parser.y"
	{ yyval.node = yystack.l_mark[0].block_value; }
break;
case 24:
#line 95 "zu_parser.y"
	{ yyval.basic = new basic_type(4, basic_type::TYPE_INT); }
break;
case 25:
#line 96 "zu_parser.y"
	{ yyval.basic = new basic_type(8, basic_type::TYPE_DOUBLE); }
break;
case 26:
#line 97 "zu_parser.y"
	{ yyval.basic = new basic_type(4, basic_type::TYPE_STRING); }
break;
case 27:
#line 98 "zu_parser.y"
	{ yyval.basic = new basic_type(0, basic_type::TYPE_VOID); }
break;
case 28:
#line 99 "zu_parser.y"
	{ yyval.basic = new basic_type(4, basic_type::TYPE_POINTER); }
break;
case 29:
#line 102 "zu_parser.y"
	{ yyval.block_value = new zu::block_node(LINE, nullptr, nullptr); }
break;
case 30:
#line 103 "zu_parser.y"
	{ yyval.block_value = new zu::block_node(LINE, nullptr, yystack.l_mark[-1].sequence); }
break;
case 31:
#line 104 "zu_parser.y"
	{ yyval.block_value = new zu::block_node(LINE, yystack.l_mark[-1].sequence, nullptr); }
break;
case 32:
#line 105 "zu_parser.y"
	{ yyval.block_value = new zu::block_node(LINE, yystack.l_mark[-2].sequence, yystack.l_mark[-1].sequence); }
break;
case 33:
#line 108 "zu_parser.y"
	{ yyval.s = new std::string(*yystack.l_mark[0].s); }
break;
case 34:
#line 109 "zu_parser.y"
	{ yyval.s = new std::string(*yystack.l_mark[-1].s + *yystack.l_mark[0].s); }
break;
case 35:
#line 112 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression); }
break;
case 36:
#line 113 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression, yystack.l_mark[-2].sequence); }
break;
case 37:
#line 116 "zu_parser.y"
	{ yyval.expression = new cdk::integer_node(LINE, yystack.l_mark[0].i); }
break;
case 38:
#line 117 "zu_parser.y"
	{ yyval.expression = new cdk::string_node(LINE, yystack.l_mark[0].s); }
break;
case 39:
#line 118 "zu_parser.y"
	{ yyval.expression = new cdk::double_node(LINE, yystack.l_mark[0].d); }
break;
case 40:
#line 119 "zu_parser.y"
	{ yyval.expression = new cdk::neg_node(LINE, yystack.l_mark[0].expression); }
break;
case 41:
#line 120 "zu_parser.y"
	{ yyval.expression = new zu::simetric_node(LINE, yystack.l_mark[0].expression); }
break;
case 42:
#line 121 "zu_parser.y"
	{ yyval.expression = new zu::identity_node(LINE, yystack.l_mark[0].expression); }
break;
case 43:
#line 122 "zu_parser.y"
	{ yyval.expression = new zu::read_node(LINE);        }
break;
case 44:
#line 123 "zu_parser.y"
	{ yyval.expression = new zu::position_indicator_node(LINE, yystack.l_mark[-1].lvalue); }
break;
case 45:
#line 124 "zu_parser.y"
	{ yyval.expression = new cdk::add_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 46:
#line 125 "zu_parser.y"
	{ yyval.expression = new cdk::sub_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 47:
#line 126 "zu_parser.y"
	{ yyval.expression = new cdk::mul_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 48:
#line 127 "zu_parser.y"
	{ yyval.expression = new cdk::div_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 49:
#line 128 "zu_parser.y"
	{ yyval.expression = new cdk::mod_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 50:
#line 129 "zu_parser.y"
	{ yyval.expression = new cdk::lt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 51:
#line 130 "zu_parser.y"
	{ yyval.expression = new cdk::gt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 52:
#line 131 "zu_parser.y"
	{ yyval.expression = new zu::and_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 53:
#line 132 "zu_parser.y"
	{ yyval.expression = new zu::or_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression);  }
break;
case 54:
#line 133 "zu_parser.y"
	{ yyval.expression = new cdk::ge_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 55:
#line 134 "zu_parser.y"
	{ yyval.expression = new cdk::le_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 56:
#line 135 "zu_parser.y"
	{ yyval.expression = new cdk::ne_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 57:
#line 136 "zu_parser.y"
	{ yyval.expression = new cdk::eq_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 58:
#line 137 "zu_parser.y"
	{ yyval.expression = new zu::function_call_node(LINE, nullptr, yystack.l_mark[-2].s); }
break;
case 59:
#line 138 "zu_parser.y"
	{ yyval.expression = new zu::function_call_node(LINE, yystack.l_mark[-1].sequence, yystack.l_mark[-3].s); }
break;
case 60:
#line 139 "zu_parser.y"
	{ yyval.expression = yystack.l_mark[-1].expression; }
break;
case 61:
#line 140 "zu_parser.y"
	{ yyval.expression = new zu::memory_reservation_node(LINE, yystack.l_mark[-1].expression); }
break;
case 62:
#line 141 "zu_parser.y"
	{ yyval.expression = new zu::rvalue_node(LINE, yystack.l_mark[0].lvalue); }
break;
case 63:
#line 142 "zu_parser.y"
	{ yyval.expression = new zu::assignment_node(LINE, yystack.l_mark[-2].lvalue, yystack.l_mark[0].expression); }
break;
case 64:
#line 145 "zu_parser.y"
	{ yyval.declaration = yystack.l_mark[-1].declaration; }
break;
case 65:
#line 148 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].declaration); }
break;
case 66:
#line 149 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].declaration, yystack.l_mark[-1].sequence); }
break;
case 67:
#line 153 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].declaration); }
break;
case 68:
#line 154 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].declaration, yystack.l_mark[-2].sequence); }
break;
case 69:
#line 157 "zu_parser.y"
	{ yyval.declaration = new zu::declaration_node(LINE, yystack.l_mark[-1].basic, yystack.l_mark[0].s, false, nullptr, false); }
break;
case 70:
#line 158 "zu_parser.y"
	{ yyval.declaration = new zu::declaration_node(LINE, yystack.l_mark[-2].basic, yystack.l_mark[-1].s, false, nullptr, true); }
break;
case 71:
#line 159 "zu_parser.y"
	{ yyval.declaration = new zu::declaration_node(LINE, yystack.l_mark[-2].basic, yystack.l_mark[-1].s, true, nullptr, false); }
break;
case 72:
#line 160 "zu_parser.y"
	{ yyval.declaration = new zu::declaration_node(LINE, yystack.l_mark[-3].basic, yystack.l_mark[-2].s, false, yystack.l_mark[0].expression, false); }
break;
case 73:
#line 161 "zu_parser.y"
	{ yyval.declaration = new zu::declaration_node(LINE, yystack.l_mark[-4].basic, yystack.l_mark[-3].s, true, yystack.l_mark[0].expression, false); }
break;
case 74:
#line 162 "zu_parser.y"
	{ yyval.declaration = new zu::declaration_node(LINE, yystack.l_mark[-4].basic, yystack.l_mark[-3].s, false, yystack.l_mark[0].expression, true); }
break;
case 75:
#line 165 "zu_parser.y"
	{ yyval.declaration = new zu::declaration_node(LINE, yystack.l_mark[-1].basic, yystack.l_mark[0].s, false, nullptr, true); }
break;
case 76:
#line 166 "zu_parser.y"
	{ yyval.declaration = new zu::declaration_node(LINE, yystack.l_mark[-3].basic, yystack.l_mark[-2].s, false, yystack.l_mark[0].expression, true); }
break;
case 77:
#line 167 "zu_parser.y"
	{ yyval.declaration = new zu::declaration_node(LINE, yystack.l_mark[-4].basic, yystack.l_mark[-3].s, false, yystack.l_mark[0].expression, true); }
break;
case 78:
#line 170 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 79:
#line 171 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 80:
#line 174 "zu_parser.y"
	{ yyval.node = yystack.l_mark[-1].declaration; }
break;
case 81:
#line 175 "zu_parser.y"
	{ yyval.node = new zu::function_declaration_node(LINE, nullptr, yystack.l_mark[-4].basic, yystack.l_mark[-3].s, false, nullptr); }
break;
case 82:
#line 176 "zu_parser.y"
	{ yyval.node = new zu::function_declaration_node(LINE, nullptr, yystack.l_mark[-4].basic, yystack.l_mark[-3].s, true, nullptr); }
break;
case 83:
#line 177 "zu_parser.y"
	{ yyval.node = new zu::function_definition_node(LINE, nullptr, yystack.l_mark[-5].basic, yystack.l_mark[-4].s, yystack.l_mark[0].block_value, true, nullptr); }
break;
case 84:
#line 178 "zu_parser.y"
	{ yyval.node = new zu::function_definition_node(LINE, nullptr, yystack.l_mark[-5].basic, yystack.l_mark[-4].s, yystack.l_mark[0].block_value, false, nullptr); }
break;
case 85:
#line 179 "zu_parser.y"
	{ yyval.node = new zu::function_declaration_node(LINE, nullptr, yystack.l_mark[-6].basic, yystack.l_mark[-5].s, true, yystack.l_mark[0].expression); }
break;
case 86:
#line 180 "zu_parser.y"
	{ yyval.node = new zu::function_declaration_node(LINE, nullptr, yystack.l_mark[-6].basic, yystack.l_mark[-5].s, false, yystack.l_mark[0].expression); }
break;
case 87:
#line 181 "zu_parser.y"
	{ yyval.node = new zu::function_definition_node(LINE, nullptr, yystack.l_mark[-7].basic, yystack.l_mark[-6].s, yystack.l_mark[0].block_value, true, yystack.l_mark[-1].expression); }
break;
case 88:
#line 182 "zu_parser.y"
	{ yyval.node = new zu::function_definition_node(LINE, nullptr, yystack.l_mark[-7].basic, yystack.l_mark[-6].s, yystack.l_mark[0].block_value, false, yystack.l_mark[-1].expression); }
break;
case 89:
#line 183 "zu_parser.y"
	{ yyval.node = new zu::function_declaration_node(LINE, yystack.l_mark[-1].sequence, yystack.l_mark[-5].basic, yystack.l_mark[-4].s, true, nullptr); }
break;
case 90:
#line 184 "zu_parser.y"
	{ yyval.node = new zu::function_declaration_node(LINE, yystack.l_mark[-1].sequence, yystack.l_mark[-5].basic, yystack.l_mark[-4].s, false, nullptr); }
break;
case 91:
#line 185 "zu_parser.y"
	{ yyval.node = new zu::function_definition_node(LINE, yystack.l_mark[-2].sequence, yystack.l_mark[-6].basic, yystack.l_mark[-5].s, yystack.l_mark[0].block_value, true, nullptr); }
break;
case 92:
#line 186 "zu_parser.y"
	{ yyval.node = new zu::function_definition_node(LINE, yystack.l_mark[-2].sequence, yystack.l_mark[-6].basic, yystack.l_mark[-5].s, yystack.l_mark[0].block_value, false, nullptr); }
break;
case 93:
#line 187 "zu_parser.y"
	{ yyval.node = new zu::function_declaration_node(LINE, yystack.l_mark[-3].sequence, yystack.l_mark[-7].basic, yystack.l_mark[-6].s, true, yystack.l_mark[0].expression); }
break;
case 94:
#line 188 "zu_parser.y"
	{ yyval.node = new zu::function_declaration_node(LINE, nullptr, yystack.l_mark[-7].basic, yystack.l_mark[-6].s, false, nullptr); }
break;
case 95:
#line 189 "zu_parser.y"
	{ yyval.node = new zu::function_definition_node(LINE, yystack.l_mark[-4].sequence, yystack.l_mark[-8].basic, yystack.l_mark[-7].s, yystack.l_mark[0].block_value, true, yystack.l_mark[-1].expression); }
break;
case 96:
#line 190 "zu_parser.y"
	{ yyval.node = new zu::function_definition_node(LINE, yystack.l_mark[-4].sequence, yystack.l_mark[-8].basic, yystack.l_mark[-7].s, yystack.l_mark[0].block_value, false, yystack.l_mark[-1].expression); }
break;
case 97:
#line 192 "zu_parser.y"
	{ yyval.node = new zu::function_declaration_node(LINE, nullptr, yystack.l_mark[-3].basic, yystack.l_mark[-2].s, true, nullptr); }
break;
case 98:
#line 193 "zu_parser.y"
	{ yyval.node = new zu::function_definition_node(LINE, nullptr, yystack.l_mark[-4].basic, yystack.l_mark[-3].s, yystack.l_mark[0].block_value, true, nullptr); }
break;
case 99:
#line 194 "zu_parser.y"
	{ yyval.node = new zu::function_declaration_node(LINE, nullptr, yystack.l_mark[-5].basic, yystack.l_mark[-4].s, true, yystack.l_mark[0].expression); }
break;
case 100:
#line 195 "zu_parser.y"
	{ yyval.node = new zu::function_definition_node(LINE, nullptr, yystack.l_mark[-6].basic, yystack.l_mark[-5].s, yystack.l_mark[0].block_value, true, yystack.l_mark[-1].expression); }
break;
case 101:
#line 196 "zu_parser.y"
	{ yyval.node = new zu::function_declaration_node(LINE, yystack.l_mark[-1].sequence, yystack.l_mark[-4].basic, yystack.l_mark[-3].s, true, nullptr); }
break;
case 102:
#line 197 "zu_parser.y"
	{ yyval.node = new zu::function_definition_node(LINE, yystack.l_mark[-2].sequence, yystack.l_mark[-5].basic, yystack.l_mark[-4].s, yystack.l_mark[0].block_value, true, nullptr); }
break;
case 103:
#line 198 "zu_parser.y"
	{ yyval.node = new zu::function_declaration_node(LINE, yystack.l_mark[-3].sequence, yystack.l_mark[-6].basic, yystack.l_mark[-5].s, true, yystack.l_mark[0].expression); }
break;
case 104:
#line 199 "zu_parser.y"
	{ yyval.node = new zu::function_definition_node(LINE, yystack.l_mark[-4].sequence, yystack.l_mark[-7].basic, yystack.l_mark[-6].s, yystack.l_mark[0].block_value, true, yystack.l_mark[-1].expression); }
break;
case 105:
#line 202 "zu_parser.y"
	{ yyval.lvalue = new zu::identifier_node(LINE, yystack.l_mark[0].s); }
break;
case 106:
#line 203 "zu_parser.y"
	{ yyval.lvalue = new zu::index_node(LINE, yystack.l_mark[-3].expression, yystack.l_mark[-1].expression); }
break;
case 107:
#line 204 "zu_parser.y"
	{ yyval.lvalue = new zu::index_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-1].expression); }
break;
#line 1342 "zu_parser.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
