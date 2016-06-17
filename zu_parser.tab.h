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
extern YYSTYPE yylval;
