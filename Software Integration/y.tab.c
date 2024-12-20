/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20230521

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <vector>
#include <string.h>
#include <queue>
#include <set>
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <stack>
#include <algorithm>
#include <fstream>

#define add_tac($$, $1, $2, $3) {strcpy($$.type, $1.type);\
    sprintf($$.lexeme, get_temp().c_str());\
    string lt=string($1.type);\
    string rt=string($3.type);\
    if((lt == "CHAR" && rt == "INT") || (rt == "CHAR" && lt == "INT")){\
        strcpy($$.type, "INT");\
    }\
    else if((lt == "FLOAT" && rt == "INT") || (rt == "FLOAT" && lt == "INT")){\
        strcpy($$.type, "FLOAT");\
    }\
    else if((lt == "FLOAT" && rt == "FLOAT") || (lt == "INT" && rt == "INT") || (lt == "CHAR" && rt == "CHAR")){\
        strcpy($$.type, $1.type);\
    }\
    else{\
        sem_errors.push_back("Cannot convert between CHAR and FLOAT in line : " + to_string(countLine+1));\
        sem_errors.push_back(lt + " and " + rt);\
    }}

using namespace std;

void yyerror(const char *s);
int yylex();
int yywrap();
int yytext();
vector<string> sem_errors;
extern int yylex();
extern int yyparse();
extern int countLine;
void yyerror(const char *s);

stack<int> scope_history;
vector<string> tac;

int scope_counter = 0;
int label_counter = 0;
int hasReturnStmt = 0;
int variable_count = 0;

stack<int> loop_break, loop_continue;
stack<pair<string, vector<string>>> function_call;

/* for array declaration with initialization*/
string curr_array;
int arr_index=0;

/*temp variables free*/
queue<string> free_temp;
set<string> const_temps;

/*functions*/
bool check_type(string l, string r);
bool check_declaration(string variable);
bool check_scope(string variable);
bool check_multiple_declaration(string variable);
string get_temp();

struct var_info {
    string data_type;
    int scope;
    int size;   /* for arrays*/
    int isArray;
    int line_number; 
};
struct func_info{
    string return_type;
    int num_params;
    vector<string> param_types;
    unordered_map<string, struct var_info> symbol_table;
};

map<string, struct func_info> function_table;
string current_function;
vector<string> current_func_param_types;



#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 95 "parser.y"
typedef union YYSTYPE {
    struct node { 
        char lexeme[100];
        int line_number;
        char type[100];
        char if_body[5];
        char elif_body[5];
		char else_body[5];
        char loop_body[5];
        char parentNext[5];
        char case_body[5];
        char id[5];
        char temp[5];
        int nParams;
    } node; 
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 140 "y.tab.c"

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

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INT 257
#define CHAR 258
#define FLOAT 259
#define STRING 260
#define VOID 261
#define RETURN 262
#define CLASS 263
#define PUBLIC 264
#define PRIVATE 265
#define PROTECTED 266
#define INPUT 267
#define OUTPUT 268
#define IF 269
#define ELSE 270
#define WHILE 271
#define FOR 272
#define BREAK 273
#define CONTINUE 274
#define INT_NUM 275
#define FLOAT_NUM 276
#define ID 277
#define ADD 278
#define SUB 279
#define MUL 280
#define DIV 281
#define ASSIGN 282
#define EQ 283
#define NE 284
#define LT 285
#define GT 286
#define LE 287
#define GE 288
#define AND 289
#define OR 290
#define SCOL 291
#define COMMA 292
#define LP 293
#define RP 294
#define LF 295
#define RF 296
#define LB 297
#define RB 298
#define STR 299
#define CHARACTER 300
#define BITAND 301
#define BITOR 302
#define NEG 303
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,   32,    2,   33,    3,   29,   29,
    4,    4,    4,    4,    4,    4,   34,    5,    5,    5,
    6,    7,    7,    8,    9,    9,   10,   10,   10,   11,
   11,   11,   12,   12,   12,   12,   12,   12,   12,   12,
   12,   12,   12,   12,   13,   13,   13,   13,   35,   13,
   36,   31,   31,   16,   16,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   15,   15,   15,   15,
   15,   15,   30,   30,   17,   18,   18,   18,   19,   19,
   19,   20,   20,   20,   14,   14,   37,   38,   39,   40,
   21,   41,   42,   43,   44,   22,   22,   45,   23,   23,
   46,   47,   48,   24,   49,   50,   51,   52,   25,   53,
   26,   27,   27,   27,   28,
};
static const YYINT yylen[] = {                            2,
    1,    2,    2,    0,    0,    5,    0,    6,    1,    1,
    1,    1,    1,    1,    2,    2,    0,    4,    1,    0,
    2,    2,    0,    5,    2,    0,    4,    2,    0,    1,
    1,    1,    2,    2,    2,    2,    1,    1,    1,    2,
    2,    5,    8,    5,    2,    4,    4,    5,    0,   10,
    0,    4,    1,    2,    1,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    1,
    1,    1,    1,    4,    2,    1,    1,    3,    1,    1,
    1,    1,    1,    1,    3,    6,    0,    0,    0,    0,
   13,    0,    0,    0,    0,   13,    0,    0,    5,    0,
    0,    0,    0,   10,    0,    0,    0,    0,   15,    0,
    5,    3,    1,    0,    1,
};
static const YYINT yydefred[] = {                         4,
    0,    0,    0,    0,   13,   14,    9,    0,    2,    0,
   10,    3,    0,   15,   16,    0,    5,    7,   26,    0,
    0,    0,    0,    0,    0,    0,   87,  101,    0,    0,
    0,   82,   83,    0,   79,   80,    0,   84,   81,    0,
    0,    0,    0,    0,    0,    0,   70,   71,    0,   77,
   37,   38,   39,   73,   72,    0,   30,   31,   32,   24,
   25,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   40,   41,    0,    0,    0,    0,    0,    6,   22,   33,
   34,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   35,    0,    0,   36,   76,   75,    0,
    0,    0,   28,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   78,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   21,    8,    0,    0,   47,    0,    0,    0,
    0,    0,    0,    0,  105,    0,    0,    0,    0,    0,
    0,    0,   27,   74,   42,    0,   44,   88,  102,    0,
    0,    0,  111,    0,    0,   18,    0,    0,    0,    0,
    0,    0,  112,   49,    0,   89,  103,  106,    0,   43,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   90,
  104,  107,    0,   50,    0,    0,    0,    0,    0,  108,
   52,   92,    0,   91,    0,    0,   98,    0,    0,    0,
  109,    0,    0,   93,   99,    0,   94,    0,    0,   95,
    0,   96,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  305,  306,  257,  258,  259,  260,  261,  263,  307,  308,
  309,  313,  334,  280,  280,  277,  295,  277,  295,  337,
  338,  314,  260,  262,  267,  268,  269,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  293,  300,  303,  309,
  312,  317,  318,  319,  320,  321,  322,  323,  324,  325,
  326,  329,  330,  331,  335,  293,  264,  265,  266,  296,
  315,  316,  277,  277,  320,  293,  293,  342,  351,  293,
  291,  291,  282,  297,  358,  320,  277,  296,  312,  291,
  291,  278,  279,  280,  281,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  301,  302,  291,  277,  323,  309,
  310,  311,  307,  309,  282,  297,  277,  320,  293,  293,
  277,  319,  320,  320,  293,  294,  282,  297,  320,  320,
  320,  320,  320,  320,  320,  320,  320,  320,  320,  320,
  320,  320,  277,  294,  339,  277,  299,  320,  294,  297,
  294,  320,  320,  297,  291,  298,  320,  332,  333,  320,
  275,  292,  291,  298,  291,  320,  291,  294,  294,  320,
  354,  282,  294,  292,  298,  310,  298,  343,  352,  298,
  320,  320,  332,  282,  294,  295,  295,  291,  340,  291,
  344,  353,  355,  295,  312,  312,  319,  325,  336,  296,
  296,  294,  341,  296,  345,  356,  292,  270,  327,  295,
  336,  269,  270,  328,  357,  346,  295,  312,  293,  350,
  296,  320,  312,  294,  296,  347,  295,  348,  312,  296,
  349,  327,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          1,
    2,    9,   10,   40,  101,  102,   41,   12,   22,   61,
   62,   42,   43,   44,   45,   46,   47,   48,   49,   50,
   51,  199,  204,   52,   53,   54,  148,  149,   13,   55,
  189,   20,   21,  135,  179,  193,   68,  168,  181,  195,
  206,  216,  218,  221,  210,   69,  169,  182,  161,  183,
  196,  205,   75,
};
static const YYINT yysindex[] = {                         0,
    0, -109, -274, -265,    0,    0,    0, -243,    0, -253,
    0,    0, -230,    0,    0, -242,    0,    0,    0,  -85,
 -220, -261, -193, -132, -183, -182,    0,    0, -180, -191,
 -174,    0,    0, -260,    0,    0, -132,    0,    0, -156,
 -168,  -85, -169, -162,   -9, -155,    0,    0, -181,    0,
    0,    0,    0,    0,    0,  -46,    0,    0,    0,    0,
    0,    3, -147, -158,  291, -117, -132, -131, -130, -113,
    0,    0, -132, -132, -126,   16, -246,    0,    0,    0,
    0, -132, -132, -132, -132, -132, -132, -132, -132, -132,
 -132, -132, -132,    0, -132, -132,    0,    0,    0, -108,
 -118,    0,    0,  -96,  -94, -132, -240,   41, -132, -132,
 -241,  -84,  291,   66, -132,    0, -132,  -66, -263, -263,
 -223, -223,  327,  327, -122, -122, -122, -122,  316,  316,
  291,  291,    0,    0,  -76,  -74,    0,   91,  -68, -132,
  -55,  116,  141, -132,    0,  -45,  291,  -56,  -52,  291,
  -57,  -46,    0,    0,    0,  166,    0,    0,    0,  191,
 -132, -132,    0, -132,  -17,    0,  -36,  -47,  -29,  -45,
  216,  291,    0,    0,  -18,    0,    0,    0,  -12,    0,
  -85,  -85, -113, -268,  -11,  -10,   -7,    0,   -8,    0,
    0,    0,   -3,    0,   20,   -4, -268,   15,   28,    0,
    0,    0,   12,    0,  -85,   18,    0,   13, -132,  -85,
    0,  241,   17,    0,    0,   19,    0,  -85,   27,    0,
   20,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,  308,   35,   38,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   36,
    0,    0,    0,   25,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -34,    0,    0,    0,    0,    0,    0,
    0,   36,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   39,    0,    0,    0,    0,
    0,    0,    0,  -59,   43,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   45,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -160,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -211,    0,   44,    0,    0,    0,  390,  407,
  352,  373,  467,  479,  -88,  423,  439,  455,   68,   93,
 -217, -167,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  266, -139,    0,   46,   48,
    0,   39,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   44,   50,    0,    0,    0,    0,    0,
    0, -176,    0,    0,    0,    0,    0,    0,    0,    0,
   36,   36,    0,    0,    0,    0,    0, -252,    0,    0,
    0,    0,    0,    0, -248,    0,    0,    0, -170,    0,
    0,    0,    0,    0,   36,    0,    0,    0,    0,   36,
    0,    0,    0,    0,    0,    0,    0,   36,    0,    0,
 -248,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,  275,    0,   14,  196,    0,  -40,    0,    0,    0,
    0,    0,    0,  -69,  -24,    0,    0,  312,    0, -151,
    0,  142,    0,    0,    0,    0,  201,    0,    0,    0,
  176,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
#define YYTABLESIZE 777
static const YYINT yytable[] = {                         65,
  112,   79,   57,   58,   59,   14,   32,   33,   97,   97,
   97,   97,   76,   97,   15,   11,   84,   85,   97,   97,
   97,   73,   97,   97,   97,   97,   97,   97,   97,   97,
   97,   38,  188,   16,   60,  117,   74,   95,   96,   51,
   73,   17,  108,   53,   97,  188,   18,   97,  113,  114,
  118,   97,   19,  139,   97,  144,  140,  119,  120,  121,
  122,  123,  124,  125,  126,  127,  128,  129,  130,  100,
  131,  132,   56,   68,   68,  104,   68,   95,   96,   85,
   68,  138,   85,   63,  142,  143,  100,  100,  100,  100,
  147,  100,  150,   32,   33,   98,  100,  100,  100,   71,
  100,  100,  100,  100,  100,  100,  100,  100,  100,   66,
   67,   37,   70,  187,   86,  156,   72,   86,   38,  160,
   77,   80,  100,   69,   69,  100,   69,   78,   81,  100,
   69,   17,  100,   19,  105,   97,  171,  172,  106,  147,
  185,  186,   32,   33,   64,   35,   36,    3,    4,    5,
    6,    7,  115,    8,  115,   82,   83,   84,   85,  107,
   37,  109,  110,  111,  208,  100,  115,   38,  133,  213,
   39,    3,    4,    5,   23,  134,   24,  219,   95,   96,
  136,   25,   26,   27,  212,   28,   29,   30,   31,   32,
   33,   34,   35,   36,   62,   62,   62,   62,   62,   62,
   62,   62,   62,   62,  137,   62,  145,   37,  151,   62,
    3,    4,    5,    6,   38,  152,  153,   39,   76,   76,
   76,   76,  155,   76,   76,   76,   76,   76,   76,   76,
   76,   76,   76,  110,   76,  157,  162,  163,   76,  164,
  165,   76,   76,   76,   76,   76,   76,  176,   76,   76,
   76,   76,   76,   76,   76,   76,   76,  175,  110,    3,
    4,    5,    6,    7,  174,  177,   76,   76,   82,   83,
   84,   85,  180,   86,   87,   88,   89,   90,   91,   92,
   93,   94,  184,  202,  190,  191,  192,  194,  197,  198,
  200,   95,   96,   82,   83,   84,   85,  203,   86,   87,
   88,   89,   90,   91,   92,   93,  207,    1,  211,  116,
  209,   11,  215,  217,   12,   55,   95,   96,   82,   83,
   84,   85,  220,   86,   87,   88,   89,   90,   91,   92,
   93,   23,   20,   54,  141,   45,  103,  114,   46,  113,
   48,   95,   96,   82,   83,   84,   85,  166,   86,   87,
   88,   89,   90,   91,   92,   93,   66,   66,   66,   66,
   99,   66,  222,  146,  173,   66,   95,   96,   82,   83,
   84,   85,  201,   86,   87,   88,   89,   90,   91,   92,
   93,   67,   67,   67,   67,    0,   67,    0,  154,    0,
   67,   95,   96,   82,   83,   84,   85,    0,   86,   87,
   88,   89,   90,   91,   92,   93,    0,    0,    0,  158,
    0,    0,    0,    0,    0,    0,   95,   96,   82,   83,
   84,   85,    0,   86,   87,   88,   89,   90,   91,   92,
   93,    0,    0,    0,  159,    0,    0,    0,    0,    0,
    0,   95,   96,   82,   83,   84,   85,    0,   86,   87,
   88,   89,   90,   91,   92,   93,    0,    0,    0,    0,
    0,    0,    0,  167,    0,    0,   95,   96,   82,   83,
   84,   85,    0,   86,   87,   88,   89,   90,   91,   92,
   93,    0,    0,    0,    0,    0,    0,    0,  170,    0,
    0,   95,   96,   82,   83,   84,   85,    0,   86,   87,
   88,   89,   90,   91,   92,   93,  178,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   95,   96,   82,   83,
   84,   85,    0,   86,   87,   88,   89,   90,   91,   92,
   93,    0,    0,    0,  214,    0,    0,    0,    0,    0,
    0,   95,   96,   74,   74,   74,   74,    0,   74,   74,
   74,   74,   74,   74,   74,   74,   74,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   74,   74,   82,   83,
   84,   85,    0,   86,   87,   88,   89,   90,   91,   92,
   93,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   95,   96,   82,   83,   84,   85,    0,   86,   87,
   88,   89,   90,   91,   82,   83,   84,   85,    0,    0,
    0,   88,   89,   90,   91,    0,   95,   96,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   95,   96,   58,
   58,   58,   58,    0,   58,   58,   58,   58,   58,   58,
   58,   58,   58,   58,    0,   58,    0,    0,    0,   58,
   59,   59,   59,   59,    0,   59,   59,   59,   59,   59,
   59,   59,   59,   59,   59,    0,   59,   56,   56,    0,
   59,    0,   56,   56,   56,   56,   56,   56,   56,   56,
   56,   56,    0,   56,   57,   57,    0,   56,    0,   57,
   57,   57,   57,   57,   57,   57,   57,   57,   57,    0,
   57,    0,    0,    0,   57,   63,   63,   63,   63,   63,
   63,   63,   63,   63,   63,    0,   63,    0,    0,    0,
   63,   64,   64,   64,   64,   64,   64,   64,   64,   64,
   64,    0,   64,    0,    0,    0,   64,   65,   65,   65,
   65,   65,   65,   65,   65,   65,   65,    0,   65,   60,
   60,    0,   65,    0,    0,   60,   60,   60,   60,    0,
   60,   61,   61,    0,   60,    0,    0,   61,   61,   61,
   61,    0,   61,    0,    0,    0,   61,
};
static const YYINT yycheck[] = {                         24,
   70,   42,  264,  265,  266,  280,  275,  276,  257,  258,
  259,  260,   37,  262,  280,    2,  280,  281,  267,  268,
  269,  282,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  300,  184,  277,  296,  282,  297,  301,  302,  292,
  282,  295,   67,  296,  293,  197,  277,  296,   73,   74,
  297,  300,  295,  294,  303,  297,  297,   82,   83,   84,
   85,   86,   87,   88,   89,   90,   91,   92,   93,   56,
   95,   96,  293,  291,  292,   62,  294,  301,  302,  291,
  298,  106,  294,  277,  109,  110,  257,  258,  259,  260,
  115,  262,  117,  275,  276,  277,  267,  268,  269,  291,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  293,
  293,  293,  293,  183,  291,  140,  291,  294,  300,  144,
  277,  291,  293,  291,  292,  296,  294,  296,  291,  300,
  298,  292,  303,  294,  282,  291,  161,  162,  297,  164,
  181,  182,  275,  276,  277,  278,  279,  257,  258,  259,
  260,  261,  292,  263,  294,  278,  279,  280,  281,  277,
  293,  293,  293,  277,  205,  152,  293,  300,  277,  210,
  303,  257,  258,  259,  260,  294,  262,  218,  301,  302,
  277,  267,  268,  269,  209,  271,  272,  273,  274,  275,
  276,  277,  278,  279,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  292,  299,  294,  291,  293,  275,  298,
  257,  258,  259,  260,  300,  292,  291,  303,  278,  279,
  280,  281,  291,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  292,  293,  294,  291,  282,  294,  298,  292,
  298,  301,  302,  278,  279,  280,  281,  295,  283,  284,
  285,  286,  287,  288,  289,  290,  291,  294,  293,  257,
  258,  259,  260,  261,  282,  295,  301,  302,  278,  279,
  280,  281,  291,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  295,  269,  296,  296,  294,  296,  292,  270,
  295,  301,  302,  278,  279,  280,  281,  270,  283,  284,
  285,  286,  287,  288,  289,  290,  295,    0,  296,  294,
  293,  277,  296,  295,  277,  291,  301,  302,  278,  279,
  280,  281,  296,  283,  284,  285,  286,  287,  288,  289,
  290,  296,  294,  291,  294,  291,   62,  294,  291,  294,
  291,  301,  302,  278,  279,  280,  281,  152,  283,  284,
  285,  286,  287,  288,  289,  290,  289,  290,  291,  292,
   49,  294,  221,  298,  164,  298,  301,  302,  278,  279,
  280,  281,  197,  283,  284,  285,  286,  287,  288,  289,
  290,  289,  290,  291,  292,   -1,  294,   -1,  298,   -1,
  298,  301,  302,  278,  279,  280,  281,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,  294,
   -1,   -1,   -1,   -1,   -1,   -1,  301,  302,  278,  279,
  280,  281,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,   -1,   -1,   -1,  294,   -1,   -1,   -1,   -1,   -1,
   -1,  301,  302,  278,  279,  280,  281,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  298,   -1,   -1,  301,  302,  278,  279,
  280,  281,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  298,   -1,
   -1,  301,  302,  278,  279,  280,  281,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  301,  302,  278,  279,
  280,  281,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,   -1,   -1,   -1,  294,   -1,   -1,   -1,   -1,   -1,
   -1,  301,  302,  278,  279,  280,  281,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  301,  302,  278,  279,
  280,  281,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  301,  302,  278,  279,  280,  281,   -1,  283,  284,
  285,  286,  287,  288,  278,  279,  280,  281,   -1,   -1,
   -1,  285,  286,  287,  288,   -1,  301,  302,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  301,  302,  278,
  279,  280,  281,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  292,   -1,  294,   -1,   -1,   -1,  298,
  278,  279,  280,  281,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  292,   -1,  294,  278,  279,   -1,
  298,   -1,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  292,   -1,  294,  278,  279,   -1,  298,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  292,   -1,
  294,   -1,   -1,   -1,  298,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  292,   -1,  294,   -1,   -1,   -1,
  298,  283,  284,  285,  286,  287,  288,  289,  290,  291,
  292,   -1,  294,   -1,   -1,   -1,  298,  283,  284,  285,
  286,  287,  288,  289,  290,  291,  292,   -1,  294,  283,
  284,   -1,  298,   -1,   -1,  289,  290,  291,  292,   -1,
  294,  283,  284,   -1,  298,   -1,   -1,  289,  290,  291,
  292,   -1,  294,   -1,   -1,   -1,  298,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 303
#define YYUNDFTOKEN 359
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","INT","CHAR","FLOAT","STRING",
"VOID","RETURN","CLASS","PUBLIC","PRIVATE","PROTECTED","INPUT","OUTPUT","IF",
"ELSE","WHILE","FOR","BREAK","CONTINUE","INT_NUM","FLOAT_NUM","ID","ADD","SUB",
"MUL","DIV","ASSIGN","EQ","NE","LT","GT","LE","GE","AND","OR","SCOL","COMMA",
"LP","RP","LF","RF","LB","RB","STR","CHARACTER","BITAND","BITOR","NEG",
"$accept","PROGRAM","LIST","FUNCTION","FUNCTION_PREFIX","DATA_TYPE","PARAMLIST",
"PARAM","STMTLIST","CLASSDEF","CLASSBODY","CLASSMEMBER","ACCESS_MODIFIER",
"STMT","DECLARATION","ASSIGNMENT","EXPR","RETURN_STMT","UNARY_EXPR",
"PRIMARY_EXPR","UNARY_OP","CONST","IF_STMT","ELIF_STMT","ELSE_STMT",
"WHILE_STMT","FOR_STMT","FUNCTION_CALL","ARGUMENTLIST","ARG","FUNCTION_TYPE",
"POSTFIX_EXPR","ARR_VALUES","$$1","$$2","$$3","$$4","$$5","$$6","$$7","$$8",
"$$9","$$10","$$11","$$12","$$13","$$14","$$15","$$16","$$17","$$18","$$19",
"$$20","$$21","$$22","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : PROGRAM",
"PROGRAM : LIST",
"LIST : LIST FUNCTION",
"LIST : LIST CLASSDEF",
"LIST :",
"$$1 :",
"FUNCTION : FUNCTION_PREFIX LF $$1 STMTLIST RF",
"$$2 :",
"FUNCTION_PREFIX : FUNCTION_TYPE ID $$2 LP PARAMLIST RP",
"FUNCTION_TYPE : VOID",
"FUNCTION_TYPE : DATA_TYPE",
"DATA_TYPE : INT",
"DATA_TYPE : CHAR",
"DATA_TYPE : FLOAT",
"DATA_TYPE : STRING",
"DATA_TYPE : INT MUL",
"DATA_TYPE : CHAR MUL",
"$$3 :",
"PARAMLIST : PARAM $$3 COMMA PARAMLIST",
"PARAMLIST : PARAM",
"PARAMLIST :",
"PARAM : DATA_TYPE ID",
"STMTLIST : STMT STMTLIST",
"STMTLIST :",
"CLASSDEF : CLASS ID LF CLASSBODY RF",
"CLASSBODY : CLASSBODY CLASSMEMBER",
"CLASSBODY :",
"CLASSMEMBER : ACCESS_MODIFIER DATA_TYPE ID SCOL",
"CLASSMEMBER : ACCESS_MODIFIER FUNCTION",
"CLASSMEMBER :",
"ACCESS_MODIFIER : PUBLIC",
"ACCESS_MODIFIER : PRIVATE",
"ACCESS_MODIFIER : PROTECTED",
"STMT : DECLARATION SCOL",
"STMT : ASSIGNMENT SCOL",
"STMT : EXPR SCOL",
"STMT : RETURN_STMT SCOL",
"STMT : IF_STMT",
"STMT : WHILE_STMT",
"STMT : FOR_STMT",
"STMT : BREAK SCOL",
"STMT : CONTINUE SCOL",
"STMT : INPUT LP ID RP SCOL",
"STMT : INPUT LP ID LB EXPR RB RP SCOL",
"STMT : OUTPUT LP EXPR RP SCOL",
"DECLARATION : DATA_TYPE ID",
"DECLARATION : DATA_TYPE ID ASSIGN EXPR",
"DECLARATION : STRING ID ASSIGN STR",
"DECLARATION : DATA_TYPE ID LB INT_NUM RB",
"$$4 :",
"DECLARATION : DATA_TYPE ID LB INT_NUM RB ASSIGN $$4 LF ARR_VALUES RF",
"$$5 :",
"ARR_VALUES : CONST $$5 COMMA ARR_VALUES",
"ARR_VALUES : CONST",
"RETURN_STMT : RETURN EXPR",
"RETURN_STMT : RETURN",
"EXPR : EXPR ADD EXPR",
"EXPR : EXPR SUB EXPR",
"EXPR : EXPR MUL EXPR",
"EXPR : EXPR DIV EXPR",
"EXPR : EXPR EQ EXPR",
"EXPR : EXPR NE EXPR",
"EXPR : EXPR LT EXPR",
"EXPR : EXPR GT EXPR",
"EXPR : EXPR LE EXPR",
"EXPR : EXPR GE EXPR",
"EXPR : EXPR AND EXPR",
"EXPR : EXPR OR EXPR",
"EXPR : EXPR BITAND EXPR",
"EXPR : EXPR BITOR EXPR",
"EXPR : UNARY_EXPR",
"EXPR : PRIMARY_EXPR",
"EXPR : POSTFIX_EXPR",
"POSTFIX_EXPR : FUNCTION_CALL",
"POSTFIX_EXPR : ID LB EXPR RB",
"UNARY_EXPR : UNARY_OP PRIMARY_EXPR",
"PRIMARY_EXPR : ID",
"PRIMARY_EXPR : CONST",
"PRIMARY_EXPR : LP EXPR RP",
"UNARY_OP : ADD",
"UNARY_OP : SUB",
"UNARY_OP : NEG",
"CONST : INT_NUM",
"CONST : FLOAT_NUM",
"CONST : CHARACTER",
"ASSIGNMENT : ID ASSIGN EXPR",
"ASSIGNMENT : ID LB EXPR RB ASSIGN EXPR",
"$$6 :",
"$$7 :",
"$$8 :",
"$$9 :",
"IF_STMT : IF $$6 LP EXPR RP $$7 LF $$8 STMTLIST RF $$9 ELIF_STMT ELSE_STMT",
"$$10 :",
"$$11 :",
"$$12 :",
"$$13 :",
"ELIF_STMT : ELSE IF $$10 LP EXPR RP $$11 LF $$12 STMTLIST RF $$13 ELIF_STMT",
"ELIF_STMT :",
"$$14 :",
"ELSE_STMT : ELSE LF $$14 STMTLIST RF",
"ELSE_STMT :",
"$$15 :",
"$$16 :",
"$$17 :",
"WHILE_STMT : WHILE $$15 LP EXPR RP $$16 LF $$17 STMTLIST RF",
"$$18 :",
"$$19 :",
"$$20 :",
"$$21 :",
"FOR_STMT : FOR LP ASSIGNMENT SCOL $$18 EXPR SCOL $$19 ASSIGNMENT RP $$20 LF $$21 STMTLIST RF",
"$$22 :",
"FUNCTION_CALL : ID $$22 LP ARGUMENTLIST RP",
"ARGUMENTLIST : ARG COMMA ARGUMENTLIST",
"ARGUMENTLIST : ARG",
"ARGUMENTLIST :",
"ARG : EXPR",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

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

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 691 "parser.y"

void yyerror(const char* msg) {
    sem_errors.push_back("syntax error in line " + to_string(countLine));
    for(auto item: sem_errors)
        cout << item << endl;
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

bool check_type(string l, string r){
    if(r == "FLOAT" && l == "CHAR"){
        sem_errors.push_back("Cannot convert type FLOAT to CHAR in line " + to_string(countLine+1));
        return false;
    }
    if(l == "FLOAT" && r == "CHAR"){
        sem_errors.push_back("Cannot convert typr CHAR to FLOAT in line " + to_string(countLine+1));
        return false;
    }
    return true;
}

bool check_declaration(string variable){
    if(function_table[current_function].symbol_table.find(variable) == function_table[current_function].symbol_table.end()){
        sem_errors.push_back("Variable " + variable + " already declared in line " + to_string(countLine + 1));
        return false;
    }
    return true;
}

bool check_scope(string variable){
    int scope = function_table[current_function].symbol_table[variable].scope;
    stack<int> temp = scope_history;
    while(!temp.empty()){
        if(temp.top() == scope)
            return true;
        temp.pop();
    }
    sem_errors.push_back("Variable " + variable + " not declared in line " + to_string(countLine + 1));
    return false;
}

bool check_multiple_declaration(string variable){
    if(function_table[current_function].symbol_table.find(variable) != function_table[current_function].symbol_table.end()){
        sem_errors.push_back("Variable " + variable + " already declared in line " + to_string(countLine + 1));
        return true;
    }
    return false;
}

string get_temp(){
    if(free_temp.empty()){
        return "@t" + to_string(variable_count++);
    }
    string t=free_temp.front();
    free_temp.pop(); 
    return t; 
}

int main(int argc, char* argv[]) {
    yyparse();
    for(auto item: sem_errors){
        cout << item << endl;
    }
    if(sem_errors.size() > 0)
        exit(0);
    for(auto x: tac)
        cout << x << endl;
}
#line 989 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
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
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

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

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
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
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 5:
#line 143 "parser.y"
	{
                        hasReturnStmt = 0;
                        scope_history.push(++scope_counter);
                    }
#line 1665 "y.tab.c"
break;
case 6:
#line 147 "parser.y"
	{
                        if(function_table[string(yystack.l_mark[-4].node.lexeme)].return_type != "VOID" && hasReturnStmt == 0){
                            sem_errors.push_back("Function type " + function_table[string(yystack.l_mark[-4].node.lexeme)].return_type + "\n");
                            sem_errors.push_back("Function " + string(yystack.l_mark[-4].node.lexeme) + " does not have a return statement in line " + to_string(countLine + 1));
                        }
                        if(function_table[string(yystack.l_mark[-4].node.lexeme)].return_type == "VOID" && hasReturnStmt == 1){
                            sem_errors.push_back("Function type " + function_table[string(yystack.l_mark[-4].node.lexeme)].return_type + "\n");
                            sem_errors.push_back("Function " + string(yystack.l_mark[-4].node.lexeme) + " has a return statement in line " + to_string(countLine + 1));
                        }
                        scope_history.pop();
                        scope_counter--;
                        tac.push_back("end:\n");
                        hasReturnStmt = 0;
                    }
#line 1683 "y.tab.c"
break;
case 7:
#line 161 "parser.y"
	{
                        if(function_table.find(string(yystack.l_mark[0].node.lexeme)) != function_table.end()){
                            sem_errors.push_back("Function " + string(yystack.l_mark[0].node.lexeme) + " already declared in line " + to_string(countLine + 1));
                        }
                        tac.push_back(string(yystack.l_mark[0].node.lexeme) + ":" + " " + string(yystack.l_mark[-1].node.type));
                        current_function = string(yystack.l_mark[0].node.lexeme);

                }
#line 1695 "y.tab.c"
break;
case 8:
#line 168 "parser.y"
	{
                    function_table[current_function].return_type = string(yystack.l_mark[-5].node.type);
                    function_table[current_function].num_params = yystack.l_mark[-1].node.nParams;
                    strcpy(yyval.node.lexeme, yystack.l_mark[-4].node.lexeme);
                }
#line 1704 "y.tab.c"
break;
case 9:
#line 174 "parser.y"
	{
                    sprintf(yyval.node.type, "VOID");
                    strcpy(yyval.node.type, "VOID");
                }
#line 1712 "y.tab.c"
break;
case 10:
#line 178 "parser.y"
	{
                    strcpy(yyval.node.type, yystack.l_mark[0].node.type);
                }
#line 1719 "y.tab.c"
break;
case 11:
#line 181 "parser.y"
	{
                    strcpy(yyval.node.type, "INT");
                }
#line 1726 "y.tab.c"
break;
case 12:
#line 184 "parser.y"
	{
                    strcpy(yyval.node.type, "CHAR");
                }
#line 1733 "y.tab.c"
break;
case 13:
#line 187 "parser.y"
	{
                    strcpy(yyval.node.type, "FLOAT");
                }
#line 1740 "y.tab.c"
break;
case 14:
#line 190 "parser.y"
	{
                    strcpy(yyval.node.type, "STRING");
                }
#line 1747 "y.tab.c"
break;
case 15:
#line 193 "parser.y"
	{
                    strcpy(yyval.node.type, "INT*");
                }
#line 1754 "y.tab.c"
break;
case 16:
#line 196 "parser.y"
	{
                    strcpy(yyval.node.type, "CHAR*");
                }
#line 1761 "y.tab.c"
break;
case 17:
#line 199 "parser.y"
	{
                    function_table[current_function].param_types.push_back(string(yystack.l_mark[0].node.type));
                    function_table[current_function].symbol_table[string(yystack.l_mark[0].node.lexeme)] = {string(yystack.l_mark[0].node.type), scope_counter +1, 0, 0, countLine + 1};
                    tac.push_back("- arg " + string(yystack.l_mark[0].node.type) + " " + string(yystack.l_mark[0].node.lexeme));
                }
#line 1770 "y.tab.c"
break;
case 18:
#line 203 "parser.y"
	{
                    yyval.node.nParams = yystack.l_mark[0].node.nParams + 1;
                }
#line 1777 "y.tab.c"
break;
case 19:
#line 206 "parser.y"
	{
                    function_table[current_function].param_types.push_back(string(yystack.l_mark[0].node.type));
                    function_table[current_function].symbol_table[string(yystack.l_mark[0].node.lexeme)] = {string(yystack.l_mark[0].node.type), scope_counter +1, 0, 0, countLine + 1};
                    tac.push_back("- arg " + string(yystack.l_mark[0].node.type) + " " + string(yystack.l_mark[0].node.lexeme));
                    yyval.node.nParams = 1;
                }
#line 1787 "y.tab.c"
break;
case 21:
#line 213 "parser.y"
	{
                    yyval.node.nParams = 1;
                    strcpy(yyval.node.type, yystack.l_mark[-1].node.type);
                    strcpy(yyval.node.lexeme, yystack.l_mark[0].node.lexeme);
                }
#line 1796 "y.tab.c"
break;
case 40:
#line 237 "parser.y"
	{
                    if(loop_break.empty()){
                        sem_errors.push_back("Break statement outside loop in line " + to_string(countLine + 1));
                    }
                    else{
                        tac.push_back("GOTO #L" + to_string(loop_break.top()));
                    }
                }
#line 1808 "y.tab.c"
break;
case 41:
#line 245 "parser.y"
	{
                    if(loop_continue.empty()){
                        sem_errors.push_back("Continue statement outside loop in line " + to_string(countLine + 1));
                    }
                    else{
                        tac.push_back("GOTO #L" + to_string(loop_continue.top()));
                    }
                }
#line 1820 "y.tab.c"
break;
case 42:
#line 253 "parser.y"
	{
                    check_declaration(string(yystack.l_mark[-2].node.lexeme));
                    tac.push_back("input " + string(yystack.l_mark[-2].node.lexeme) + " " + function_table[current_function].symbol_table[string(yystack.l_mark[-2].node.lexeme)].data_type);
                }
#line 1828 "y.tab.c"
break;
case 43:
#line 257 "parser.y"
	{
                    check_declaration(string(yystack.l_mark[-5].node.lexeme));
                    string temp = get_temp();
                    tac.push_back("input " + temp + " " + function_table[current_function].symbol_table[string(yystack.l_mark[-5].node.lexeme)].data_type);
                    tac.push_back(string(yystack.l_mark[-5].node.lexeme) + "[" + string(yystack.l_mark[-3].node.lexeme) + "] = " + temp + " " + function_table[current_function].symbol_table[string(yystack.l_mark[-5].node.lexeme)].data_type);
                    free_temp.push(temp);
                }
#line 1839 "y.tab.c"
break;
case 44:
#line 264 "parser.y"
	{
                    tac.push_back("output " + string(yystack.l_mark[-2].node.lexeme) + " " + string(yystack.l_mark[-2].node.type));
                }
#line 1846 "y.tab.c"
break;
case 45:
#line 267 "parser.y"
	{
                    tac.push_back("- " + string(yystack.l_mark[-1].node.type) + " " + string(yystack.l_mark[0].node.lexeme));
                    function_table[current_function].symbol_table[string(yystack.l_mark[0].node.lexeme)] = {string(yystack.l_mark[-1].node.type), scope_counter, 0, 0, countLine + 1};
                }
#line 1854 "y.tab.c"
break;
case 46:
#line 271 "parser.y"
	{
                    if(string(yystack.l_mark[0].node.type) == "VOID"){
                        sem_errors.push_back("Cannot assign void to variable in line " + to_string(countLine + 1));
                    }
                    check_type(string(yystack.l_mark[-3].node.type), string(yystack.l_mark[0].node.type));
                    tac.push_back("- " + string(yystack.l_mark[-3].node.type) + " " + string(yystack.l_mark[-2].node.lexeme));
                    tac.push_back(string(yystack.l_mark[-2].node.lexeme) + " = " + string(yystack.l_mark[0].node.lexeme) + " " + string(yystack.l_mark[-3].node.type));
                    function_table[current_function].symbol_table[string(yystack.l_mark[-2].node.lexeme)] = {string(yystack.l_mark[-3].node.type), scope_counter, 0, 0, countLine + 1};

                    if(const_temps.find(string(yystack.l_mark[0].node.lexeme)) == const_temps.end() && yystack.l_mark[0].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[0].node.lexeme));
                }
#line 1869 "y.tab.c"
break;
case 47:
#line 282 "parser.y"
	{
                    check_multiple_declaration(string(yystack.l_mark[-2].node.lexeme));
                    tac.push_back("- STR " + string(yystack.l_mark[-2].node.lexeme));
                    tac.push_back(string(yystack.l_mark[-2].node.lexeme) + " = " + string(yystack.l_mark[0].node.lexeme) + " STR");
                    function_table[current_function].symbol_table[string(yystack.l_mark[-2].node.lexeme)] = {"STR", scope_counter, 0, 0, countLine + 1};
                }
#line 1879 "y.tab.c"
break;
case 48:
#line 288 "parser.y"
	{
                    check_multiple_declaration(string(yystack.l_mark[-3].node.lexeme));
                    tac.push_back("- " + string(yystack.l_mark[-4].node.type) + " " + string(yystack.l_mark[-3].node.lexeme) + "[" + string(yystack.l_mark[-1].node.lexeme) + "]");
                    function_table[current_function].symbol_table[string(yystack.l_mark[-3].node.lexeme)] = {string(yystack.l_mark[-4].node.type), scope_counter, stoi(string(yystack.l_mark[-1].node.lexeme)), 1, countLine + 1};
                }
#line 1888 "y.tab.c"
break;
case 49:
#line 293 "parser.y"
	{
                    check_multiple_declaration(string(yystack.l_mark[-4].node.lexeme));
                    tac.push_back("- " + string(yystack.l_mark[-5].node.type) + " " + string(yystack.l_mark[-4].node.lexeme) + "[" + string(yystack.l_mark[-2].node.lexeme) + "]");
                    function_table[current_function].symbol_table[string(yystack.l_mark[-4].node.lexeme)] = {string(yystack.l_mark[-5].node.type), scope_counter, stoi(string(yystack.l_mark[-2].node.lexeme)), 1, countLine + 1};
                    curr_array = string(yystack.l_mark[-4].node.lexeme);
                }
#line 1898 "y.tab.c"
break;
case 51:
#line 299 "parser.y"
	{
                    check_type(function_table[current_function].symbol_table[curr_array].data_type, string(yystack.l_mark[0].node.type));
                    tac.push_back(curr_array + "[" + to_string(arr_index++) + "] = " + string(yystack.l_mark[0].node.lexeme) + " " + function_table[current_function].symbol_table[curr_array].data_type);
                    if(arr_index > function_table[current_function].symbol_table[curr_array].size){
                        sem_errors.push_back("Array " + curr_array + " out of bounds in line " + to_string(countLine + 1));
                    }
                }
#line 1909 "y.tab.c"
break;
case 53:
#line 306 "parser.y"
	{
                    check_type(function_table[current_function].symbol_table[curr_array].data_type, string(yystack.l_mark[0].node.type));
                    tac.push_back(curr_array + "[" + to_string(arr_index++) + "] = " + string(yystack.l_mark[0].node.lexeme) + " " + function_table[current_function].symbol_table[curr_array].data_type);
                    if(arr_index > function_table[current_function].symbol_table[curr_array].size){
                        sem_errors.push_back("Array " + curr_array + " out of bounds in line " + to_string(countLine + 1));
                    }
                }
#line 1920 "y.tab.c"
break;
case 54:
#line 313 "parser.y"
	{
                    check_type(function_table[current_function].return_type, string(yystack.l_mark[0].node.type));
                    tac.push_back("return " + string(yystack.l_mark[0].node.lexeme) + " " + function_table[current_function].return_type);
                    hasReturnStmt = 1;
                }
#line 1929 "y.tab.c"
break;
case 55:
#line 318 "parser.y"
	{
                    if(function_table[current_function].return_type != "VOID"){
                        sem_errors.push_back("Function " + current_function + " expects a return statement in line " + to_string(countLine + 1));
                    }
                    tac.push_back("return " + function_table[current_function].return_type);
                    hasReturnStmt = 0;
                }
#line 1940 "y.tab.c"
break;
case 56:
#line 325 "parser.y"
	{
                    add_tac(yyval.node, yystack.l_mark[-2].node, yystack.l_mark[-1].node, yystack.l_mark[0].node);
                    tac.push_back(string(yyval.node.lexeme) + " = " + string(yystack.l_mark[-2].node.lexeme) + " " + string(yystack.l_mark[-1].node.lexeme) + " " + string(yystack.l_mark[0].node.lexeme) + " " + string(yyval.node.type));
                    
                    if(const_temps.find(string(yystack.l_mark[-2].node.lexeme)) == const_temps.end() && yystack.l_mark[-2].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-2].node.lexeme));
                    if(const_temps.find(string(yystack.l_mark[0].node.lexeme)) == const_temps.end() && yystack.l_mark[0].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[0].node.lexeme));
                }
#line 1951 "y.tab.c"
break;
case 57:
#line 332 "parser.y"
	{
                    add_tac(yyval.node, yystack.l_mark[-2].node, yystack.l_mark[-1].node, yystack.l_mark[0].node);
                    tac.push_back(string(yyval.node.lexeme) + " = " + string(yystack.l_mark[-2].node.lexeme) + " " + string(yystack.l_mark[-1].node.lexeme) + " " + string(yystack.l_mark[0].node.lexeme) + " " + string(yyval.node.type));
                    
                    if(const_temps.find(string(yystack.l_mark[-2].node.lexeme)) == const_temps.end() && yystack.l_mark[-2].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-2].node.lexeme));
                    if(const_temps.find(string(yystack.l_mark[0].node.lexeme)) == const_temps.end() && yystack.l_mark[0].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[0].node.lexeme));
                }
#line 1962 "y.tab.c"
break;
case 58:
#line 339 "parser.y"
	{
                    add_tac(yyval.node, yystack.l_mark[-2].node, yystack.l_mark[-1].node, yystack.l_mark[0].node);
                    tac.push_back(string(yyval.node.lexeme) + " = " + string(yystack.l_mark[-2].node.lexeme) + " " + string(yystack.l_mark[-1].node.lexeme) + " " + string(yystack.l_mark[0].node.lexeme) + " " + string(yyval.node.type));
                    
                    if(const_temps.find(string(yystack.l_mark[-2].node.lexeme)) == const_temps.end() && yystack.l_mark[-2].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-2].node.lexeme));
                    if(const_temps.find(string(yystack.l_mark[0].node.lexeme)) == const_temps.end() && yystack.l_mark[0].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[0].node.lexeme));
                }
#line 1973 "y.tab.c"
break;
case 59:
#line 346 "parser.y"
	{
                    add_tac(yyval.node, yystack.l_mark[-2].node, yystack.l_mark[-1].node, yystack.l_mark[0].node);
                    tac.push_back(string(yyval.node.lexeme) + " = " + string(yystack.l_mark[-2].node.lexeme) + " " + string(yystack.l_mark[-1].node.lexeme) + " " + string(yystack.l_mark[0].node.lexeme) + " " + string(yyval.node.type));
                    
                    if(const_temps.find(string(yystack.l_mark[-2].node.lexeme)) == const_temps.end() && yystack.l_mark[-2].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-2].node.lexeme));
                    if(const_temps.find(string(yystack.l_mark[0].node.lexeme)) == const_temps.end() && yystack.l_mark[0].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[0].node.lexeme));
                }
#line 1984 "y.tab.c"
break;
case 60:
#line 353 "parser.y"
	{
                    add_tac(yyval.node, yystack.l_mark[-2].node, yystack.l_mark[-1].node, yystack.l_mark[0].node);
                    tac.push_back(string(yyval.node.lexeme) + " = " + string(yystack.l_mark[-2].node.lexeme) + " " + string(yystack.l_mark[-1].node.lexeme) + " " + string(yystack.l_mark[0].node.lexeme) + " " + string(yyval.node.type));
                    
                    if(const_temps.find(string(yystack.l_mark[-2].node.lexeme)) == const_temps.end() && yystack.l_mark[-2].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-2].node.lexeme));
                    if(const_temps.find(string(yystack.l_mark[0].node.lexeme)) == const_temps.end() && yystack.l_mark[0].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[0].node.lexeme));
                }
#line 1995 "y.tab.c"
break;
case 61:
#line 360 "parser.y"
	{
                    add_tac(yyval.node, yystack.l_mark[-2].node, yystack.l_mark[-1].node, yystack.l_mark[0].node);
                    tac.push_back(string(yyval.node.lexeme) + " = " + string(yystack.l_mark[-2].node.lexeme) + " " + string(yystack.l_mark[-1].node.lexeme) + " " + string(yystack.l_mark[0].node.lexeme) + " " + string(yyval.node.type));
                    
                    if(const_temps.find(string(yystack.l_mark[-2].node.lexeme)) == const_temps.end() && yystack.l_mark[-2].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-2].node.lexeme));
                    if(const_temps.find(string(yystack.l_mark[0].node.lexeme)) == const_temps.end() && yystack.l_mark[0].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[0].node.lexeme));
                }
#line 2006 "y.tab.c"
break;
case 62:
#line 367 "parser.y"
	{
                    add_tac(yyval.node, yystack.l_mark[-2].node, yystack.l_mark[-1].node, yystack.l_mark[0].node);
                    tac.push_back(string(yyval.node.lexeme) + " = " + string(yystack.l_mark[-2].node.lexeme) + " " + string(yystack.l_mark[-1].node.lexeme) + " " + string(yystack.l_mark[0].node.lexeme) + " " + string(yyval.node.type));
                    
                    if(const_temps.find(string(yystack.l_mark[-2].node.lexeme)) == const_temps.end() && yystack.l_mark[-2].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-2].node.lexeme));
                    if(const_temps.find(string(yystack.l_mark[0].node.lexeme)) == const_temps.end() && yystack.l_mark[0].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[0].node.lexeme));
                }
#line 2017 "y.tab.c"
break;
case 63:
#line 374 "parser.y"
	{
                    add_tac(yyval.node, yystack.l_mark[-2].node, yystack.l_mark[-1].node, yystack.l_mark[0].node);
                    tac.push_back(string(yyval.node.lexeme) + " = " + string(yystack.l_mark[-2].node.lexeme) + " " + string(yystack.l_mark[-1].node.lexeme) + " " + string(yystack.l_mark[0].node.lexeme) + " " + string(yyval.node.type));
                    
                    if(const_temps.find(string(yystack.l_mark[-2].node.lexeme)) == const_temps.end() && yystack.l_mark[-2].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-2].node.lexeme));
                    if(const_temps.find(string(yystack.l_mark[0].node.lexeme)) == const_temps.end() && yystack.l_mark[0].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[0].node.lexeme));
                }
#line 2028 "y.tab.c"
break;
case 64:
#line 381 "parser.y"
	{
                    add_tac(yyval.node, yystack.l_mark[-2].node, yystack.l_mark[-1].node, yystack.l_mark[0].node);
                    tac.push_back(string(yyval.node.lexeme) + " = " + string(yystack.l_mark[-2].node.lexeme) + " " + string(yystack.l_mark[-1].node.lexeme) + " " + string(yystack.l_mark[0].node.lexeme) + " " + string(yyval.node.type));
                    
                    if(const_temps.find(string(yystack.l_mark[-2].node.lexeme)) == const_temps.end() && yystack.l_mark[-2].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-2].node.lexeme));
                    if(const_temps.find(string(yystack.l_mark[0].node.lexeme)) == const_temps.end() && yystack.l_mark[0].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[0].node.lexeme));
                }
#line 2039 "y.tab.c"
break;
case 65:
#line 388 "parser.y"
	{
                    add_tac(yyval.node, yystack.l_mark[-2].node, yystack.l_mark[-1].node, yystack.l_mark[0].node);
                    tac.push_back(string(yyval.node.lexeme) + " = " + string(yystack.l_mark[-2].node.lexeme) + " " + string(yystack.l_mark[-1].node.lexeme) + " " + string(yystack.l_mark[0].node.lexeme) + " " + string(yyval.node.type));
                    
                    if(const_temps.find(string(yystack.l_mark[-2].node.lexeme)) == const_temps.end() && yystack.l_mark[-2].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-2].node.lexeme));
                    if(const_temps.find(string(yystack.l_mark[0].node.lexeme)) == const_temps.end() && yystack.l_mark[0].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[0].node.lexeme));
                }
#line 2050 "y.tab.c"
break;
case 66:
#line 395 "parser.y"
	{
                    add_tac(yyval.node, yystack.l_mark[-2].node, yystack.l_mark[-1].node, yystack.l_mark[0].node);
                    string l0 = "#L" + to_string(++label_counter);
                    string l1 = "#L" + to_string(++label_counter);
                    string l2 = "#L" + to_string(++label_counter);
                    string l3 = "#L" + to_string(++label_counter);
                    string dtype = string(yyval.node.type);

                    tac.push_back("if " + string(yystack.l_mark[-2].node.lexeme) + " GOTO " + l3 + " else GOTO " + l1);
                    tac.push_back(l3 + ":");
                    tac.push_back("if " + string(yystack.l_mark[0].node.lexeme) + " GOTO " + l0 + " else GOTO " + l1);
                    tac.push_back(l0 + ":");
                    tac.push_back(string(yyval.node.lexeme) + " = 1 " + dtype);
                    tac.push_back("GOTO " + l2);
                    tac.push_back(l1 + ":");
                    tac.push_back(string(yyval.node.lexeme) + " = 0 " + dtype);
                    tac.push_back(l2 + ":");

                    if(const_temps.find(string(yystack.l_mark[-2].node.lexeme)) == const_temps.end() && yystack.l_mark[-2].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-2].node.lexeme));
                    if(const_temps.find(string(yystack.l_mark[0].node.lexeme)) == const_temps.end() && yystack.l_mark[0].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[0].node.lexeme));

                    label_counter++;
                }
#line 2077 "y.tab.c"
break;
case 67:
#line 418 "parser.y"
	{
                    add_tac(yyval.node, yystack.l_mark[-2].node, yystack.l_mark[-1].node, yystack.l_mark[0].node)
                    string l0 = "#L" + to_string(++label_counter);
                    string l1 = "#L" + to_string(++label_counter);
                    string l2 = "#L" + to_string(++label_counter);
                    string l3 = "#L" + to_string(++label_counter);
                    string dtype = string(yyval.node.type);

                    tac.push_back("if " + string(yystack.l_mark[-2].node.lexeme) + " GOTO " + l0 + " else GOTO " + l3);
                    tac.push_back(l3 + ":");
                    tac.push_back("if " + string(yystack.l_mark[0].node.lexeme) + " GOTO " + l0 + " else GOTO " + l1);
                    tac.push_back(l0 + ":");
                    tac.push_back(string(yyval.node.lexeme) + " = 1 " + dtype);
                    tac.push_back("GOTO " + l2);
                    tac.push_back(l1 + ":");
                    tac.push_back(string(yyval.node.lexeme) + " = 0 " + dtype);
                    tac.push_back(l2 + ":");

                    if(const_temps.find(string(yystack.l_mark[-2].node.lexeme)) == const_temps.end() && yystack.l_mark[-2].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-2].node.lexeme));
                    if(const_temps.find(string(yystack.l_mark[0].node.lexeme)) == const_temps.end() && yystack.l_mark[0].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[0].node.lexeme));

                    label_counter++;
                }
#line 2104 "y.tab.c"
break;
case 68:
#line 441 "parser.y"
	{
                    add_tac(yyval.node, yystack.l_mark[-2].node, yystack.l_mark[-1].node, yystack.l_mark[0].node);
                    tac.push_back(string(yyval.node.lexeme) + " = " + string(yystack.l_mark[-2].node.lexeme) + " " + string(yystack.l_mark[-1].node.lexeme) + " " + string(yystack.l_mark[0].node.lexeme) + " " + string(yyval.node.type));
                    
                    if(const_temps.find(string(yystack.l_mark[-2].node.lexeme)) == const_temps.end() && yystack.l_mark[-2].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-2].node.lexeme));
                    if(const_temps.find(string(yystack.l_mark[0].node.lexeme)) == const_temps.end() && yystack.l_mark[0].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[0].node.lexeme));
                }
#line 2115 "y.tab.c"
break;
case 69:
#line 448 "parser.y"
	{
                    add_tac(yyval.node, yystack.l_mark[-2].node, yystack.l_mark[-1].node, yystack.l_mark[0].node);
                    tac.push_back(string(yyval.node.lexeme) + " = " + string(yystack.l_mark[-2].node.lexeme) + " " + string(yystack.l_mark[-1].node.lexeme) + " " + string(yystack.l_mark[0].node.lexeme) + " " + string(yyval.node.type));
                    
                    if(const_temps.find(string(yystack.l_mark[-2].node.lexeme)) == const_temps.end() && yystack.l_mark[-2].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-2].node.lexeme));
                    if(const_temps.find(string(yystack.l_mark[0].node.lexeme)) == const_temps.end() && yystack.l_mark[0].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[0].node.lexeme));
                }
#line 2126 "y.tab.c"
break;
case 70:
#line 455 "parser.y"
	{
                    strcpy(yyval.node.lexeme, yystack.l_mark[0].node.lexeme);
                    strcpy(yyval.node.type, yystack.l_mark[0].node.type);
                    sprintf(yyval.node.lexeme, "%s", yystack.l_mark[0].node.lexeme);
                }
#line 2135 "y.tab.c"
break;
case 71:
#line 460 "parser.y"
	{
                    strcpy(yyval.node.lexeme, yystack.l_mark[0].node.lexeme);
                    strcpy(yyval.node.type, yystack.l_mark[0].node.type);
                    sprintf(yyval.node.lexeme, "%s", yystack.l_mark[0].node.lexeme);
                }
#line 2144 "y.tab.c"
break;
case 72:
#line 465 "parser.y"
	{
                    strcpy(yyval.node.lexeme, yystack.l_mark[0].node.lexeme);
                    strcpy(yyval.node.type, yystack.l_mark[0].node.type);
                    sprintf(yyval.node.lexeme, "%s", yystack.l_mark[0].node.lexeme);
                }
#line 2153 "y.tab.c"
break;
case 73:
#line 470 "parser.y"
	{
                    strcpy(yyval.node.type, yystack.l_mark[0].node.type);
                    sprintf(yyval.node.lexeme, "%s", yystack.l_mark[0].node.lexeme);
                }
#line 2161 "y.tab.c"
break;
case 74:
#line 474 "parser.y"
	{
                    if(check_declaration(string(yystack.l_mark[-3].node.lexeme)) && function_table[current_function].symbol_table[string(yystack.l_mark[-3].node.lexeme)].isArray == 0){
                        sem_errors.push_back("Variable " + string(yystack.l_mark[-3].node.lexeme) + " is not an array in line " + to_string(countLine + 1));
                    }
                    check_scope(string(yystack.l_mark[-3].node.lexeme));
                    strcpy(yyval.node.type, function_table[current_function].symbol_table[string(yystack.l_mark[-3].node.lexeme)].data_type.c_str());
                    sprintf(yyval.node.lexeme, get_temp().c_str());
                    tac.push_back(string(yyval.node.lexeme) + " = " + string(yystack.l_mark[-3].node.lexeme) + "[" + string(yystack.l_mark[-1].node.lexeme) + "] " + yyval.node.type);

                    if(const_temps.find(string(yystack.l_mark[-1].node.lexeme)) == const_temps.end() && yystack.l_mark[-1].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-1].node.lexeme));
                }
#line 2176 "y.tab.c"
break;
case 75:
#line 485 "parser.y"
	{
                    strcpy(yyval.node.type, yystack.l_mark[0].node.type);
                    sprintf(yyval.node.lexeme, get_temp().c_str());
                    if(string(yystack.l_mark[-1].node.lexeme) == "~" || string(yystack.l_mark[-1].node.lexeme) == "-"){
                        tac.push_back(string(yyval.node.lexeme) + " = " + string(yystack.l_mark[-1].node.lexeme) + " " + string(yystack.l_mark[0].node.lexeme) + " " + string(yyval.node.type));
                    }
                    else if(string(yystack.l_mark[-1].node.lexeme) == "+"){
                        tac.push_back(string(yyval.node.lexeme) + " = " + string(yystack.l_mark[0].node.lexeme) + " " + string(yyval.node.type));
                    }
                    else{
                        tac.push_back(string(yyval.node.lexeme) + " = ~ " + string(yystack.l_mark[0].node.lexeme) + " " + string(yyval.node.type));
                    }

                    if(const_temps.find(string(yystack.l_mark[0].node.lexeme)) == const_temps.end() && yystack.l_mark[0].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[0].node.lexeme));
                }
#line 2195 "y.tab.c"
break;
case 76:
#line 500 "parser.y"
	{
                    check_declaration(string(yystack.l_mark[0].node.lexeme));
                    strcpy(yyval.node.type, function_table[current_function].symbol_table[string(yystack.l_mark[0].node.lexeme)].data_type.c_str());
                    strcpy(yyval.node.lexeme, yystack.l_mark[0].node.lexeme);
                }
#line 2204 "y.tab.c"
break;
case 77:
#line 505 "parser.y"
	{
                    strcpy(yyval.node.type, yystack.l_mark[0].node.type);
                    
                    string t = get_temp();
                    sprintf(yyval.node.lexeme, t.c_str());
                    tac.push_back(string(yyval.node.lexeme) + " = " + string(yystack.l_mark[0].node.lexeme) + " " + string(yystack.l_mark[0].node.type));
                    const_temps.insert(t);
                }
#line 2216 "y.tab.c"
break;
case 78:
#line 513 "parser.y"
	{
                    strcpy(yyval.node.type, yystack.l_mark[-1].node.type);
                    strcpy(yyval.node.lexeme, yystack.l_mark[-1].node.lexeme);
                }
#line 2224 "y.tab.c"
break;
case 82:
#line 520 "parser.y"
	{
                    strcpy(yyval.node.type, "INT");
                    strcpy(yyval.node.lexeme, yystack.l_mark[0].node.lexeme);
                }
#line 2232 "y.tab.c"
break;
case 83:
#line 524 "parser.y"
	{
                    strcpy(yyval.node.type, "FLOAT");
                    strcpy(yyval.node.lexeme, yystack.l_mark[0].node.lexeme);
                }
#line 2240 "y.tab.c"
break;
case 84:
#line 528 "parser.y"
	{
                    strcpy(yyval.node.type, "CHAR");
                    strcpy(yyval.node.lexeme, yystack.l_mark[0].node.lexeme);
                }
#line 2248 "y.tab.c"
break;
case 85:
#line 532 "parser.y"
	{
                    if(string(yystack.l_mark[0].node.type) == "VOID"){
                        sem_errors.push_back("Cannot assign void to variable in line " + to_string(countLine + 1));
                    }
                    check_type(function_table[current_function].symbol_table[string(yystack.l_mark[-2].node.lexeme)].data_type, string(yystack.l_mark[0].node.type));
                    check_scope(string(yystack.l_mark[-2].node.lexeme));
                    check_declaration(string(yystack.l_mark[-2].node.lexeme));
                    tac.push_back(string(yystack.l_mark[-2].node.lexeme) + " = " + string(yystack.l_mark[0].node.lexeme) + " " + function_table[current_function].symbol_table[string(yystack.l_mark[-2].node.lexeme)].data_type);

                    /*checking if we can free any temp variables*/
                    if(const_temps.find(string(yystack.l_mark[0].node.lexeme)) == const_temps.end() && yystack.l_mark[0].node.lexeme[0] == '@')
                        free_temp.push(string(yystack.l_mark[0].node.lexeme));

                }
#line 2266 "y.tab.c"
break;
case 86:
#line 546 "parser.y"
	{
                    if(string(yystack.l_mark[0].node.type) == "VOID"){
                        sem_errors.push_back("Cannot assign void to variable in line " + to_string(countLine + 1));
                    }
                    check_type(function_table[current_function].symbol_table[string(yystack.l_mark[-5].node.lexeme)].data_type, string(yystack.l_mark[0].node.type));
                    if(check_declaration(string(yystack.l_mark[-5].node.lexeme)) && function_table[current_function].symbol_table[string(yystack.l_mark[-5].node.lexeme)].isArray == 0){
                        sem_errors.push_back("Variable " + string(yystack.l_mark[-5].node.lexeme) + " is not an array in line " + to_string(countLine + 1));
                    }
                    check_scope(string(yystack.l_mark[-5].node.lexeme));
                    tac.push_back(string(yystack.l_mark[-5].node.lexeme) + "[" + string(yystack.l_mark[-3].node.lexeme) + "] = " + string(yystack.l_mark[0].node.lexeme) + " " + function_table[current_function].symbol_table[string(yystack.l_mark[-5].node.lexeme)].data_type);
                        
                }
#line 2282 "y.tab.c"
break;
case 87:
#line 558 "parser.y"
	{
                    sprintf(yystack.l_mark[0].node.parentNext, "#L%d", label_counter++);
                }
#line 2289 "y.tab.c"
break;
case 88:
#line 561 "parser.y"
	{
                    tac.push_back("if " + string(yystack.l_mark[-1].node.lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                    sprintf(yystack.l_mark[-1].node.if_body, "#L%d", label_counter++);
                    sprintf(yystack.l_mark[-1].node.else_body, "#L%d", label_counter++); 
                    tac.push_back(string(yystack.l_mark[-1].node.if_body) + ":");
                }
#line 2299 "y.tab.c"
break;
case 89:
#line 567 "parser.y"
	{
                    scope_history.push(++scope_counter);
                }
#line 2306 "y.tab.c"
break;
case 90:
#line 570 "parser.y"
	{
                    tac.push_back("GOTO " + string(yystack.l_mark[-9].node.parentNext));
                    tac.push_back(string(yystack.l_mark[-6].node.else_body) + ":");
                    scope_history.pop(); 
                    scope_counter--;
                }
#line 2316 "y.tab.c"
break;
case 91:
#line 576 "parser.y"
	{
                    tac.push_back(string(yystack.l_mark[-12].node.parentNext) + ":");
                }
#line 2323 "y.tab.c"
break;
case 92:
#line 580 "parser.y"
	{
                    string str = tac[tac.size()-2].substr(5);
                    char* hold = const_cast<char*>(str.c_str());
                    sprintf(yystack.l_mark[0].node.parentNext, "#L%d", label_counter++);
                }
#line 2332 "y.tab.c"
break;
case 93:
#line 584 "parser.y"
	{
                    tac.push_back("if " + string(yystack.l_mark[-1].node.lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                    sprintf(yystack.l_mark[-1].node.if_body, "#L%d", label_counter++);
                    sprintf(yystack.l_mark[-1].node.else_body, "#L%d", label_counter++);
                    tac.push_back(string(yystack.l_mark[-1].node.if_body) + ":");

                    if(const_temps.find(string(yystack.l_mark[-1].node.lexeme)) == const_temps.end() && yystack.l_mark[-1].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-1].node.lexeme));
                }
#line 2344 "y.tab.c"
break;
case 94:
#line 591 "parser.y"
	{
                    scope_history.push(++scope_counter);
                
                }
#line 2352 "y.tab.c"
break;
case 95:
#line 594 "parser.y"
	{
                    tac.push_back("GOTO " + string(yystack.l_mark[-9].node.parentNext));
                    tac.push_back(string(yystack.l_mark[-6].node.else_body) + ":");
                    scope_history.pop();
                    scope_counter--;
                }
#line 2362 "y.tab.c"
break;
case 98:
#line 601 "parser.y"
	{
                    scope_history.push(++scope_counter);
                }
#line 2369 "y.tab.c"
break;
case 99:
#line 604 "parser.y"
	{
                    scope_history.pop(); 
                    scope_counter--;
                }
#line 2377 "y.tab.c"
break;
case 101:
#line 609 "parser.y"
	{
                    sprintf(yystack.l_mark[0].node.loop_body, "#L%d", label_counter);
                    loop_continue.push(label_counter++);
                    tac.push_back("\n" + string(yystack.l_mark[0].node.loop_body) + ":");
                }
#line 2386 "y.tab.c"
break;
case 102:
#line 613 "parser.y"
	{
                    sprintf(yystack.l_mark[-1].node.if_body, "#L%d", label_counter++);
                    loop_break.push(label_counter);
                    sprintf(yystack.l_mark[-1].node.else_body, "#L%d", label_counter++);

                    tac.push_back("\nif " + string(yystack.l_mark[-1].node.lexeme) + " GOTO " + string(yystack.l_mark[-1].node.if_body) + " else GOTO " + string(yystack.l_mark[-1].node.else_body));
                    tac.push_back("\n" + string(yystack.l_mark[-1].node.if_body) + ":");

                    if(const_temps.find(string(yystack.l_mark[-1].node.lexeme)) == const_temps.end() && yystack.l_mark[-1].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-1].node.lexeme));
                }
#line 2400 "y.tab.c"
break;
case 103:
#line 622 "parser.y"
	{
                    scope_history.push(++scope_counter);
                }
#line 2407 "y.tab.c"
break;
case 104:
#line 624 "parser.y"
	{
                    scope_history.pop();
                    scope_counter--;
                    tac.push_back("GOTO " + string(yystack.l_mark[-9].node.loop_body));
                    tac.push_back(string(yystack.l_mark[-6].node.else_body) + ":");
                    loop_break.pop();
                    loop_continue.pop();
                }
#line 2419 "y.tab.c"
break;
case 105:
#line 632 "parser.y"
	{
                    sprintf(yystack.l_mark[-3].node.loop_body, "#L%d", label_counter++);
                    tac.push_back("\n" + string(yystack.l_mark[-3].node.loop_body) + ":");
                }
#line 2427 "y.tab.c"
break;
case 106:
#line 635 "parser.y"
	{
                    sprintf(yystack.l_mark[-1].node.if_body, "#L%d", label_counter++);
                    loop_break.push(label_counter);
                    sprintf(yystack.l_mark[-1].node.else_body, "#L%d", label_counter++);
                    tac.push_back("\nif " + string(yystack.l_mark[-1].node.lexeme) + " GOTO " + string(yystack.l_mark[-1].node.if_body) + " else GOTO " + string(yystack.l_mark[-1].node.else_body));
                    
                    sprintf(yystack.l_mark[-1].node.loop_body, "#L%d", label_counter);
                    loop_continue.push(label_counter++);
                    tac.push_back("\n" + string(yystack.l_mark[-1].node.if_body) + ":");

                    if(const_temps.find(string(yystack.l_mark[-1].node.lexeme)) == const_temps.end() && yystack.l_mark[-1].node.lexeme[0] == '@') free_temp.push(string(yystack.l_mark[-1].node.lexeme));
                }
#line 2443 "y.tab.c"
break;
case 107:
#line 646 "parser.y"
	{
                    tac.push_back("GOTO " + string(yystack.l_mark[-9].node.loop_body));
                    tac.push_back("\n" + string(yystack.l_mark[-4].node.if_body) + ":");
                }
#line 2451 "y.tab.c"
break;
case 108:
#line 649 "parser.y"
	{
                    scope_history.push(++scope_counter);
                }
#line 2458 "y.tab.c"
break;
case 109:
#line 651 "parser.y"
	{
                    scope_history.pop();
                    scope_counter--;
                    tac.push_back("GOTO " + string(yystack.l_mark[-9].node.loop_body));
                    tac.push_back(string(yystack.l_mark[-9].node.else_body) + ":");
                    loop_break.pop();
                    loop_continue.pop();
                }
#line 2470 "y.tab.c"
break;
case 110:
#line 659 "parser.y"
	{
                    function_call.push({string(yystack.l_mark[0].node.lexeme), function_table[string(yystack.l_mark[0].node.lexeme)].param_types});
                }
#line 2477 "y.tab.c"
break;
case 111:
#line 661 "parser.y"
	{
                    strcpy(yyval.node.type, function_table[string(yystack.l_mark[-4].node.lexeme)].return_type.c_str());
                    function_call.pop();
                    sprintf(yyval.node.lexeme, "%s", get_temp().c_str());
                    tac.push_back(string(yyval.node.lexeme) + " = @call " + string(yystack.l_mark[-4].node.lexeme) + " " + function_table[string(yystack.l_mark[-4].node.lexeme)].return_type + " " + to_string(function_table[string(yystack.l_mark[-4].node.lexeme)].num_params));
                }
#line 2487 "y.tab.c"
break;
case 112:
#line 667 "parser.y"
	{
                    int size = function_call.top().second.size();
                    string type = function_call.top().second[size - 1];
                    function_call.top().second.pop_back();
                    if(!check_type(type, string(yystack.l_mark[-2].node.type))){
                        sem_errors.push_back("Function " + function_call.top().first + " expects type " + type + " in line " + to_string(countLine + 1));
                    }
                }
#line 2499 "y.tab.c"
break;
case 113:
#line 675 "parser.y"
	{
                    int size = function_call.top().second.size();
                    string type = function_call.top().second[size - 1];
                    function_call.top().second.pop_back();
                    if(!check_type(type, string(yystack.l_mark[0].node.type))){
                        sem_errors.push_back("Function " + function_call.top().first + " expects type " + type + " in line " + to_string(countLine + 1));
                    }
                }
#line 2511 "y.tab.c"
break;
case 115:
#line 684 "parser.y"
	{
                    tac.push_back("param " + string(yystack.l_mark[0].node.lexeme) + " " + string(yystack.l_mark[0].node.type));
                }
#line 2518 "y.tab.c"
break;
#line 2520 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
