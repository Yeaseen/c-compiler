/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include "SymbolTable.h"

#define YYSTYPE SymbolInfo*

using namespace std;
string dec_print = "outdec proc\n\
;input ax\n\
PUSH AX\n\
PUSH BX\n\
PUSH CX\n\
PUSH DX\n\
cmp ax,0\n\
jge @END_IF1\n\
PUSH AX\n\
MOV DL,'-'\n\
MOV AH,2\n\
INT 21H\n\
POP AX\n\
NEG AX\n\
\n\
@END_IF1:\n\
XOR CX,CX\n\
MOV BX,10D\n\
\n\
@REPEAT1:\n\
XOR DX,DX\n\
DIV BX\n\
PUSH DX\n\
INC CX\n\
cmp ax,0\n\
JNE @REPEAT1\n\
\n\
MOV AH,2\n\
\n\
@PRINT_LOOP:\n\
\n\
POP DX\n\
mov dh,0\n\
add DL,30H\n\
INT 21H\n\
LOOP @PRINT_LOOP\n\
\n\
POP DX\n\
POP CX\n\
POP BX\n\
POP AX\n\
RET\n\
OUTDEC ENDP\n\
";


int labelCount=0;
int tempCount=0;

string IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}

string newLabel()
{
  string temp="l";
  
  labelCount++;
  temp=temp+IntToString(labelCount);
  return temp;

}


string newTemp()
{
  string temp="t";
  tempCount++;
  temp=temp+IntToString(tempCount);
  return temp;

}


string bb="";
string total_code;
string initial_code =".MODEL SMALL\n.STACK 100H\n\n.DATA\n";
string declare_code;
string function_code;
string main_code = ".CODE\n\nMAIN PROC\n\nMOV AX, @DATA\nMOV DS, AX\n\n";

int global_scope_id=1;
int yyparse(void);
int yylex(void);
extern FILE *yyin;

extern int lin_count;
extern int error_count;
int type;
SymbolTable* table;
SymbolInfo* dam;
FILE *logout;
FILE *errorout;
FILE *asmout;
int pos=0;
int flow[10];
string item[10];
int pos1=0;
int flow1[10];
int flow2[10];
int println=0;
void yyerror(char *s)
{
	//write your code
}



#line 188 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    FOR = 260,
    INT = 261,
    CHAR = 262,
    WHILE = 263,
    FLOAT = 264,
    VOID = 265,
    RETURN = 266,
    PRINTLN = 267,
    ID = 268,
    ADDOP = 269,
    MULOP = 270,
    INCOP = 271,
    DECOP = 272,
    RELOP = 273,
    NOT = 274,
    LPAREN = 275,
    RPAREN = 276,
    LCURL = 277,
    RCURL = 278,
    LTHIRD = 279,
    RTHIRD = 280,
    COMMA = 281,
    SEMICOLON = 282,
    ASSIGNOP = 283,
    CONST_CHAR = 284,
    CONST_INT = 285,
    CONST_FLOAT = 286,
    LOGICOP = 287,
    MAIN = 288,
    noelse = 289
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define INT 261
#define CHAR 262
#define WHILE 263
#define FLOAT 264
#define VOID 265
#define RETURN 266
#define PRINTLN 267
#define ID 268
#define ADDOP 269
#define MULOP 270
#define INCOP 271
#define DECOP 272
#define RELOP 273
#define NOT 274
#define LPAREN 275
#define RPAREN 276
#define LCURL 277
#define RCURL 278
#define LTHIRD 279
#define RTHIRD 280
#define COMMA 281
#define SEMICOLON 282
#define ASSIGNOP 283
#define CONST_CHAR 284
#define CONST_INT 285
#define CONST_FLOAT 286
#define LOGICOP 287
#define MAIN 288
#define noelse 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 307 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  117

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    37,     2,     2,
       2,     2,    36,    34,     2,    35,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   134,   134,   146,   151,   156,   161,   167,   175,   209,
     265,   271,   272,   274,   291,   309,   314,   317,   320,   326,
     332,   339,   352,   367,   376,   395,   396,   399,   400,   401,
     402,   428,   445,   466,   485,   498,   513,   514,   517,   523,
     545,   546,   596,   597,   771,   772,  1007,  1008,  1079,  1080,
    1162,  1206,  1250,  1253,  1269,  1307,  1308,  1309,  1310,  1356,
    1408,  1409,  1411,  1417
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "INT", "CHAR",
  "WHILE", "FLOAT", "VOID", "RETURN", "PRINTLN", "ID", "ADDOP", "MULOP",
  "INCOP", "DECOP", "RELOP", "NOT", "LPAREN", "RPAREN", "LCURL", "RCURL",
  "LTHIRD", "RTHIRD", "COMMA", "SEMICOLON", "ASSIGNOP", "CONST_CHAR",
  "CONST_INT", "CONST_FLOAT", "LOGICOP", "MAIN", "'+'", "'-'", "'*'",
  "'%'", "noelse", "$accept", "start", "program", "unit",
  "func_declaration", "func_definition", "lparen2", "parameter_list2",
  "parameter_list", "compound_statement", "var_declaration",
  "type_specifier", "declaration_list", "statements", "statement",
  "expression_statement", "variable", "expression", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    43,    45,    42,    37,   289
};
# endif

#define YYPACT_NINF -61

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-61)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,   -61,   -61,   -61,     2,     9,   -61,   -61,   -61,   -61,
       8,   -61,   -61,     3,    26,   -61,    10,     9,    23,   -61,
      13,    24,    21,    44,    35,   -61,   -11,     9,   -61,    30,
      67,   -61,   -61,    48,    37,    43,    43,    43,   144,    46,
       6,   144,   144,   144,   -61,   -61,   -61,   -61,   -61,   -61,
      51,    96,   -61,   -61,    -3,    47,   -61,    39,    19,    68,
     -61,   -61,   -61,   -61,   144,   140,   144,    55,    71,   144,
     144,    38,   -61,   -61,    64,    69,   -61,   -61,   -61,   -61,
     144,   -61,   144,   144,   144,   144,    70,   140,    74,   -61,
      75,   -61,    79,    62,    78,   -61,   -61,   -61,    68,    97,
     -61,   125,   144,   125,    65,   -61,   144,   -61,   108,    92,
     -61,   -61,   -61,   125,   125,   -61,   -61
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    18,    19,    20,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    23,     0,    10,     0,    12,     0,    17,
       0,     0,    11,     0,    21,    24,     0,     0,    14,     0,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,    16,    36,    56,    57,    29,    27,
       0,     0,    25,    28,    53,     0,    40,    42,    44,    46,
      48,    52,    13,    22,     0,     0,     0,     0,     0,    61,
       0,    53,    50,    51,     0,    23,    15,    26,    58,    59,
       0,    37,     0,     0,     0,     0,     0,     0,     0,    35,
       0,    63,     0,    60,     0,    55,    41,    43,    47,    45,
      49,     0,     0,     0,     0,    54,     0,    39,    31,     0,
      33,    34,    62,     0,     0,    32,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -61,   -61,   -61,   109,   -61,   -61,    14,   -61,   -61,    91,
      17,     7,   -61,   -61,   -45,   -55,   -41,   -35,   -60,    40,
      36,    41,   -37,   -61,   -61,   -61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    17,    21,    22,    48,
      49,    50,    14,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    92,    93
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      71,    71,    11,    67,    72,    73,    77,    10,    74,    91,
      87,    30,    10,    78,    79,     1,    31,     9,     2,     3,
      96,    13,     9,    15,    23,    80,    69,    16,    71,    86,
      70,    88,   102,    83,    33,    94,    24,    84,    25,    71,
      20,    71,    71,    71,    71,    26,   112,    27,   100,    64,
      65,    66,    18,    19,    78,    79,   108,    28,   110,    29,
      34,    62,    63,    15,    75,    71,    68,   109,   115,   116,
      35,    82,    36,     1,    81,    37,     2,     3,    38,    39,
      40,    41,    89,    85,    90,    95,    42,    43,   106,    30,
      44,   101,   111,    16,    45,   103,   104,    46,    47,    35,
     105,    36,     1,   107,    37,     2,     3,    38,    39,    40,
      41,    83,   113,   114,    12,    42,    43,    32,    30,    76,
      99,     0,    97,    45,    98,     0,    46,    47,    35,     0,
      36,     1,     0,    37,     2,     3,    38,    39,    40,    41,
       0,     0,     0,     0,    42,    43,     0,    30,     0,     0,
       0,     0,    45,    40,    41,    46,    47,    40,    41,    42,
      43,     0,     0,    42,    43,     0,     0,    45,     0,     0,
      46,    47,     0,     0,    46,    47
};

static const yytype_int8 yycheck[] =
{
      41,    42,     0,    38,    41,    42,    51,     0,    43,    69,
      65,    22,     5,    16,    17,     6,    27,     0,     9,    10,
      80,    13,     5,    20,    17,    28,    20,    24,    69,    64,
      24,    66,    87,    14,    27,    70,    13,    18,    25,    80,
      30,    82,    83,    84,    85,    21,   106,    26,    85,    35,
      36,    37,    26,    27,    16,    17,   101,    13,   103,    24,
      30,    13,    25,    20,    13,   106,    20,   102,   113,   114,
       3,    32,     5,     6,    27,     8,     9,    10,    11,    12,
      13,    14,    27,    15,    13,    21,    19,    20,    26,    22,
      23,    21,    27,    24,    27,    21,    21,    30,    31,     3,
      21,     5,     6,    25,     8,     9,    10,    11,    12,    13,
      14,    14,     4,    21,     5,    19,    20,    26,    22,    23,
      84,    -1,    82,    27,    83,    -1,    30,    31,     3,    -1,
       5,     6,    -1,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    19,    20,    -1,    22,    -1,    -1,
      -1,    -1,    27,    13,    14,    30,    31,    13,    14,    19,
      20,    -1,    -1,    19,    20,    -1,    -1,    27,    -1,    -1,
      30,    31,    -1,    -1,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     9,    10,    40,    41,    42,    43,    44,    49,
      50,     0,    42,    13,    51,    20,    24,    45,    26,    27,
      30,    46,    47,    50,    13,    25,    21,    26,    13,    24,
      22,    27,    48,    50,    30,     3,     5,     8,    11,    12,
      13,    14,    19,    20,    23,    27,    30,    31,    48,    49,
      50,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    13,    25,    45,    45,    45,    56,    20,    20,
      24,    55,    61,    61,    56,    13,    23,    53,    16,    17,
      28,    27,    32,    14,    18,    15,    56,    54,    56,    27,
      13,    57,    63,    64,    56,    21,    57,    58,    60,    59,
      61,    21,    54,    21,    21,    21,    26,    25,    53,    56,
      53,    27,    57,     4,    21,    53,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    42,    43,    44,
      45,    46,    46,    47,    47,    48,    48,    49,    50,    50,
      50,    51,    51,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      61,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      63,    63,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     6,
       1,     1,     0,     4,     2,     3,     2,     3,     1,     1,
       1,     3,     6,     1,     4,     1,     2,     1,     1,     1,
       7,     5,     7,     5,     5,     3,     1,     2,     1,     4,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       2,     2,     1,     1,     4,     3,     1,     1,     2,     2,
       1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 135 "parser.y" /* yacc.c:1646  */
    {
	
              
              {fprintf(logout,"Line no %d->start: program\n\n",lin_count);} 
              //main code er shate $$->code ta add korte hope
              //main_code = main_code+$1->code;
              main_code = main_code + "\n\nMAIN ENDP\n\n";
             
	}
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 147 "parser.y" /* yacc.c:1646  */
    {
           fprintf(logout,"Line no %d->program: unit program\n\n",lin_count);

	}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 151 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->program: unit \n\n",lin_count); (yyval)=(yyvsp[0]);}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 157 "parser.y" /* yacc.c:1646  */
    {
            fprintf(logout,"Line no %d->unit: var_declaration\n\n",lin_count);
	}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 162 "parser.y" /* yacc.c:1646  */
    {
           fprintf(logout,"Line no %d->unit: func_declaration\n\n",lin_count);

     	}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 168 "parser.y" /* yacc.c:1646  */
    {
           fprintf(logout,"Line no %d->unit: func_definition\n\n",lin_count);
           (yyval)=(yyvsp[0]);
     	}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 176 "parser.y" /* yacc.c:1646  */
    {
                           fprintf(logout,"Line no %d->func_declaration : type_specifier ID LPAREN parameter_list2 RPAREN SEMICOLON\n\n",lin_count);
                        table->ExitScope();
                        cout<<" exitscope from func";
                       SymbolInfo* temp=table->Look((yyvsp[-4])->name);
                        
                       if(!temp){
                         table->InsertS((yyvsp[-4])->name,(yyvsp[-4])->type,-1111,-1111,1,0,-1111,-1111,(yyvsp[-5])->value.c);
                         temp=table->Look((yyvsp[-4])->name);
                        
                        
                        	
                        temp->type="Function";
                        temp->fsize=pos;
                        temp->para=1;
                        temp->isF=0;
                        if (temp->value.c==0) { temp->fsign=0; temp->value.c=-3;}
                        else if(temp->value.c==1) {temp->fsign=1; temp->value.c=-3;}
                        else if(temp->value.c==4) {temp->fsign=2; temp->value.c=-3;}
                         
                        for(int i=0;i<pos;i++) {  temp->f[i]=flow[i]; }; 
                        
                        
                        pos=0;
                        table->AllScopePrint();
                        
                          
			}
                        else if(temp) { fprintf(errorout,"Array already declared\n\n"); error_count++;}

}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 210 "parser.y" /* yacc.c:1646  */
    {
                         fprintf(logout,"Line no %d->func_definition:type_specifier ID LPAREN parameter_list2 RPAREN compound_statement\n\n",lin_count);
                        table->ExitScope();
                        cout<<" exitscope from defi";
                        
                        SymbolInfo* temp=table->Look((yyvsp[-4])->name);
                        
                       if(!temp){
                        table->InsertS((yyvsp[-4])->name,(yyvsp[-4])->type,-1111,-1111,1,0,-1111,-1111,type);
                        temp=table->Look((yyvsp[-4])->name);	
                        temp->type="Function";
                        temp->fsize=pos;
                        temp->para=1;
                        temp->isF=1;
                        if (temp->value.c==0) { temp->fsign=0; temp->value.c=-3;}
                        else if(temp->value.c==1) {temp->fsign=1; temp->value.c=-3;}
                        else if(temp->value.c==4) {temp->fsign=2; temp->value.c=-3;}
                         
                        for(int i=0;i<pos;i++) { temp->f[i]=flow[i]; temp->variable[i]=item[i];
                           


}
                        temp->freturn=(yyvsp[0])->freturn;
                        string tempq=newTemp();
                        declare_code+=tempq+" dw ?\n";
                        bb=tempq;
                        
                        
                        if(temp->name=="main") { (yyval)=(yyvsp[0]); main_code=main_code+(yyvsp[0])->code;  }
                        else {
                              (yyvsp[0])->code+="\n\nmov ax,"+(yyvsp[0])->freturn+"\n";
                              (yyvsp[0])->code+="mov "+bb+",ax";
                             function_code+="\n"+temp->name+" proc near\n\n";
                             function_code+="push ax\npush bx\npush cx\npush dx\n";
                             function_code+=(yyvsp[0])->code+"\n";
                             function_code+="pop dx\npop cx\npop bx\npop ax\nret\n\n";
                             function_code+=temp->name+" endp\n\n";

                             }
                        //bb=temp->freturn;//=string(newTemp());
                        pos=0;
                        table->AllScopePrint();
                       
                          
			}
                        else if(temp->isF==0 && (temp->fsign==0||temp->fsign==1 || temp->fsign==2)) {temp->isF=1;}
                        else if(temp->isF==1){ fprintf(errorout,"%s is already defined \n\n",temp->name.c_str()); error_count++; } 
                        else { fprintf(errorout,"Error at Line no%d: %s is a ID ",lin_count,temp->name.c_str()); error_count++; }                    

                        (yyval)=(yyvsp[0]);
                        
}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 265 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0])->name=="(") {table->EntryScope(); global_scope_id++;}}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 271 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->parameter_list2 : parameter_list\n\n",lin_count);}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 272 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->parameter_list2 : \n\n",lin_count);}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 274 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->parameter_list : parameter_list COMMA type_specifier ID\n %s \n\n",lin_count,(yyvsp[0])->name.c_str());

                 if(table->Look((yyvsp[0])->name)!=NULL) {fprintf(errorout,"Line np %d->Multiple declaration of %s\n\n",lin_count,(yyvsp[0])->name.c_str());  error_count++;}
                 else {

                      (yyvsp[0])->symbol=(yyvsp[0])->name+IntToString(global_scope_id);
                      declare_code+=(yyvsp[0])->symbol+" dw "+"?\n";
                      table->InsertS((yyvsp[0])->name,(yyvsp[0])->type,(yyvsp[0])->symbol,-1111,-1111,1,0,-1111,-1111,type);

                       //table->InsertS($4->name,$4->type,-1111,-1111,1,0,-1111,-1111,type);
                       flow[pos]=(yyvsp[-1])->value.c;
                       item[pos]=(yyvsp[0])->symbol;
                        pos++;
                      table->AllScopePrint();}
                 

}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 291 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->parameter_list : type_specifier ID\n %s \n\n",lin_count,(yyvsp[0])->name.c_str());
                 if(table->Look((yyvsp[0])->name)!=NULL) {fprintf(errorout,"Line np %d->Multiple declaration of %s \n\n ",lin_count,(yyvsp[0])->name.c_str());  error_count++;}
                 else {
                      (yyvsp[0])->symbol=(yyvsp[0])->name+IntToString(global_scope_id);
                      declare_code+=(yyvsp[0])->symbol+" dw "+"?\n";
                      table->InsertS((yyvsp[0])->name,(yyvsp[0])->type,(yyvsp[0])->symbol,-1111,-1111,1,0,-1111,-1111,type);

                        //table->InsertS($2->name,$2->type,-1111,-1111,1,0,-1111,-1111,type);
                        flow[pos]=(yyvsp[-1])->value.c;
                        item[pos]=(yyvsp[0])->symbol;
                        pos++;
                      table->AllScopePrint();}
                 


}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 309 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->compound_statement : LCURL statements RCURL\n\n",lin_count); (yyval)=(yyvsp[-1]);



}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 314 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->compound_statement : LCURL RCURL\n\n",lin_count);}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 317 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->var_declaration : type_specifier declaration_list SEMICOLON\n\n",lin_count);  }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 320 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->type_specifier	: INT\n\n",lin_count); type=0;  
                         SymbolInfo* temp=new SymbolInfo;
                         temp->value.c=0;
                         (yyval)=temp;
                         
                          }
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 326 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->type_specifier	: FLOAT\n\n",lin_count); type=1;
                         SymbolInfo* temp=new SymbolInfo;
                         temp->value.c=1;
                         (yyval)=temp;
                         
                         }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 332 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->type_specifier	: VOID\n\n",lin_count);  type=4;
                         SymbolInfo* temp=new SymbolInfo;
                         temp->value.c=4;
                         (yyval)=temp;
                         }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 339 "parser.y" /* yacc.c:1646  */
    {
                 fprintf(logout,"Line no %d->declaration_list : declaration_list COMMA ID\n %s\n\n",lin_count,(yyvsp[0])->name.c_str());
                 if(table->Look((yyvsp[0])->name)!=NULL) {fprintf(errorout,"Line no %d->Multiple declaration of %s",lin_count,(yyvsp[0])->name); error_count++;}
                 else {
                       (yyvsp[0])->symbol=(yyvsp[0])->name+IntToString(global_scope_id);
                      declare_code+=(yyvsp[0])->symbol+" dw "+"?\n";


                        table->InsertS((yyvsp[0])->name,(yyvsp[0])->type,(yyvsp[0])->symbol,-1111,-1111,1,0,-1111,-1111,type);
                        table->AllScopePrint();
                              }

                   }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 352 "parser.y" /* yacc.c:1646  */
    {
                 fprintf(logout,"Line no %d->declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n %s\n\n",lin_count,(yyvsp[-3])->name.c_str());
                  if(table->Look((yyvsp[-3])->name)!=NULL) {fprintf(errorout,"Line no %d->Multiple declaration of %s",lin_count,(yyvsp[-3])->name.c_str()); error_count++;}
                  else {if(type==0) {
                         (yyvsp[-3])->symbol=(yyvsp[-3])->name+IntToString(global_scope_id);
                         declare_code+=(yyvsp[-3])->symbol+" dw ";
                         for(int i=0;i<(yyvsp[-1])->value.ival-1;i++) { declare_code+="? "; }
                         declare_code+="?\n";


                      table->InsertS((yyvsp[-3])->name,(yyvsp[-3])->type,(yyvsp[-3])->symbol,-1111,-1111,(yyvsp[-1])->value.ival,0,-1111,-1111,2); 
                      table->AllScopePrint();}
                        else if(type==1){table->InsertS((yyvsp[-3])->name,(yyvsp[-3])->type,(yyvsp[-3])->symbol,-1111,-1111,(yyvsp[-1])->value.ival,0,-1111,-1111,3); table->AllScopePrint();}                     
}
                    }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 367 "parser.y" /* yacc.c:1646  */
    {   
                 fprintf(logout,"Line no %d->declaration_list : ID\n %s \n\n",lin_count,(yyvsp[0])->name.c_str()); 
                 if(table->Look((yyvsp[0])->name)!=NULL) {fprintf(errorout,"Line np %d->Multiple declaration of %s",lin_count,(yyvsp[0])->name.c_str());  error_count++;}
                 else {
                      (yyvsp[0])->symbol=(yyvsp[0])->name+IntToString(global_scope_id);
                      declare_code+=(yyvsp[0])->symbol+" dw "+"?\n";
                      table->InsertS((yyvsp[0])->name,(yyvsp[0])->type,(yyvsp[0])->symbol,-1111,-1111,1,0,-1111,-1111,type);
                      table->AllScopePrint();}
                  }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 376 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->declaration_list : ID LTHIRD CONST_INT RTHIRD\n %s\n\n",lin_count,(yyvsp[-3])->name.c_str());
                  if(table->Look((yyvsp[-3])->name)!=NULL) {fprintf(errorout,"Line no %d->Multiple declaration of %s",lin_count,(yyvsp[-3])->name.c_str()); error_count++;}
                  else { if(type==0) {

                         (yyvsp[-3])->symbol=(yyvsp[-3])->name+IntToString(global_scope_id);
                         declare_code+=(yyvsp[-3])->symbol+" dw ";
                         for(int i=0;i<(yyvsp[-1])->value.ival-1;i++) { declare_code+="? "; }
                         declare_code+="?\n";

                         table->InsertS((yyvsp[-3])->name,(yyvsp[-3])->type,(yyvsp[-3])->symbol,-1111,-1111,(yyvsp[-1])->value.ival,0,-1111,-1111,2); 
                         table->AllScopePrint();
                                                   }
                         else if(type==1){table->InsertS((yyvsp[-3])->name,(yyvsp[-3])->type,(yyvsp[-3])->symbol,-1111,-1111,(yyvsp[-1])->value.ival,0,-1111,-1111,3); table->AllScopePrint();}                          
}
                  
                   
                   }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 395 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d-> statements : statement\n\n",lin_count); (yyval)=(yyvsp[0]);  }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 396 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d-> statements : statements statement\n\n",lin_count); (yyval)=new SymbolInfo; (yyval)->code=(yyvsp[-1])->code + (yyvsp[0])->code; (yyval)->freturn=(yyvsp[0])->freturn;  }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 399 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->statement : var_declaration\n\n",lin_count);(yyval)=(yyvsp[0]);}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 400 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->statement : expression_statement\n\n",lin_count);(yyval)=(yyvsp[0]);}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 401 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d-> statement : compound_statement\n\n",lin_count); (yyval)=(yyvsp[0]);}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 402 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n",lin_count); 

                 string label_start=newLabel();
                 string label_end=newLabel();
                 SymbolInfo* p=new SymbolInfo;
                 p->code=(yyvsp[-4])->code+"\n";
                 p->code+=label_start+":\n";
                 p->code+=(yyvsp[-3])->code+"\n";
                 p->code+="mov ax,"+(yyvsp[-3])->address+"\n";
                 p->code+="cmp ax,0\n";
                 p->code+="je "+label_end+"\n";
                 p->code+=(yyvsp[0])->code+"\n";
                 p->code+=(yyvsp[-2])->code+"\n";
                 p->code+="jmp "+label_start+"\n";
                 p->code+=label_end+":\n\n";


                 (yyval)=p;






                  table->ExitScope(); 
                  cout<<"exitscopefor "; }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 428 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->statement: IF LPAREN expression RPAREN statement\n\n",lin_count); 
                    string label_f=newLabel();
                    SymbolInfo* p=new SymbolInfo;
                    p->code=(yyvsp[-2])->code+"\n";
                    p->code+="mov ax,"+(yyvsp[-2])->address+"\n";
                    p->code+="cmp ax,0\n";
                    p->code+="je "+label_f+"\n";
                    p->code+=(yyvsp[0])->code+"\n";
                    p->code+=label_f+":\n\n";
                   
                    (yyval)=p; 
                   
                    table->ExitScope(); 
                    //global_scope_id--; 
                    cout<<"exitscope if ";             
                  
}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 445 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->statement: IF LPAREN expression RPAREN statement ELSE statement\n\n",lin_count); 

              string label_f=newLabel();
              string label_t=newLabel();
              SymbolInfo* p=new SymbolInfo;
              p->code=(yyvsp[-4])->code+"\n";
              p->code+="mov ax,"+(yyvsp[-4])->address+"\n";
              p->code+="cmp ax,0\n";
              p->code+="je "+label_f+"\n";
              p->code+=(yyvsp[-2])->code+"\n";
              p->code+="jmp "+label_t+"\n";
              p->code+=label_f+":\n";
              p->code+=(yyvsp[0])->code+"\n";
              p->code+=label_t+":\n";

             (yyval)=p;


              table->ExitScope(); 

              cout<<"exitscope";}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 466 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->statement: WHILE LPAREN expression RPAREN statement\n\n",lin_count); 


              string label_start=newLabel();
              string label_end=newLabel();
              SymbolInfo* p=new SymbolInfo;
              
              p->code=label_start+"\n";
              p->code+=(yyvsp[-2])->code+"\n";
              p->code+="mov ax,"+(yyvsp[-2])->address+"\n";
              p->code+="cmp ax,0\n";
              p->code+="je "+label_end+"\n";
              p->code+=(yyvsp[0])->code+"\n";
              p->code+="jmp "+label_start+"\n";
              p->code+=label_end+":\n";
                   
                   table->ExitScope(); 
                   cout<<"exitscopewhile";}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 485 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->statement: PRINTLN LPAREN ID RPAREN SEMICOLON\n\n",lin_count);  

if((yyvsp[-2])->value.c==0) fprintf(logout,"Value of %s is %d\n\n",(yyvsp[-2])->name.c_str(),(yyvsp[-2])->value.ival);
else if((yyvsp[-2])->value.c=1) fprintf(logout,"Value of %s is %f\n\n",(yyvsp[-2])->name.c_str(),(yyvsp[-2])->value.fval);
       declare_code+=(yyvsp[-2])->name+ " dw " +"?\n";
      (yyval)=(yyvsp[-2]);
      (yyval)->code+="mov ax,"+(yyvsp[-2])->name+"\n";
      (yyval)->code+="call dec_print\n"; println=1;
      (yyval)->code+="mov ah,2\nmov dl,0dh\nint 21h\nmove ah,2\nmov dl,0ah\nint 21h\n";



}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 498 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->statement: RETURN expression SEMICOLON\n\n",lin_count);

              //$$=new SymbolInfo("return","RETURN");
              //$$->code="\n\n;exit to dos\nMOV AH, 4ch\nINT 21H\n";
              //$$->freturn=$2->address;
              (yyvsp[-1])->code+="push dx,"+(yyvsp[-1])->address+"\n"+"ret \n";
              (yyval)=(yyvsp[-1]);
              
              



}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 513 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->expression_statement : SEMICOLON\n\n",lin_count);(yyval)=(yyvsp[0]);}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 514 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->expression_statement : expression SEMICOLON\n\n",lin_count);(yyval)=(yyvsp[-1]);}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 517 "parser.y" /* yacc.c:1646  */
    {  fprintf(logout,"Line no %d-> variable: ID\n %s\n\n",lin_count,(yyvsp[0])->name.c_str());
                     SymbolInfo* d=table->LookAll((yyvsp[0])->name);
                     if(d==NULL) {fprintf(errorout,"Line no %d: Undeclared Variable %s \n\n",lin_count,(yyvsp[0])->name.c_str()); (yyval)=dam; error_count++; }
                     else if(d->value.c==2 || d->value.c==3) {fprintf(errorout,"Line no %d: %s is Araay Type\n\n",lin_count,(yyvsp[0])->name.c_str());                  (yyval)=dam; error_count++; } 
                     else {(yyval)=d;}    
}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 523 "parser.y" /* yacc.c:1646  */
    {
                   fprintf(logout,"Line no %d-> variable: ID LTHIRD expression RTHIRD\n %s\n\n",lin_count,(yyvsp[-3])->name.c_str());
                SymbolInfo* d=table->LookAll((yyvsp[-3])->name);
                 if(d==NULL) {fprintf(errorout,"Line no %d: Undeclared variable %s \n\n",lin_count,(yyvsp[-3])->name.c_str()); (yyval)=dam; error_count++;}
                 
                 else { 
                         
                        if(d->value.c!=2 && d->value.c!=3) {fprintf(errorout,"Line no %d: %s is not a Array type\n\n",lin_count,d->name.c_str()); (yyval)=dam; error_count++; }
                        else if (d->value.arraysize<(yyvsp[-1])->value.ival){fprintf(errorout,"Line no %d: ArrayOutOfBound Error\n\n",lin_count); (yyval)=dam; error_count++;}
                        else if ((yyvsp[-1])->value.c==1) {fprintf(errorout,"Line no %d: Array Index is not  <INT> type\n\n",lin_count); (yyval)=dam; error_count++;} 
                        else if ((yyvsp[-1])->value.ival<0) {fprintf(errorout,"Line no %d: Array Index is Negative\n\n",lin_count); (yyval)=dam; error_count++;}
                        else if ((yyvsp[-1])->value.arrayl==1) {fprintf(errorout,"Line no %d: Ivalid Index found \n\n"); (yyval)=dam; error_count++;} 
                        else  {  d->value.arraypos=(yyvsp[-1])->value.ival; (yyval)=d; 

                        (yyval)->code=(yyvsp[-1])->code+"mov bx, " +(yyvsp[-1])->address +"\nadd bx, bx\n"; }
                     }
                   


}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 545 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->expression-> logic_expression\n\n",lin_count); (yyval)=(yyvsp[0]); (yyval)->address=IntToString((yyvsp[0])->value.ival);}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 546 "parser.y" /* yacc.c:1646  */
    {
fprintf(logout,"Line no %d->expression-> variable ASSIGNOP logic_expression\n\n",lin_count);
           
          //SymbolInfo* p= new SymbolInfo;
          if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==0) {(yyvsp[-2])->value.ival=(yyvsp[0])->value.ival;}
          else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==1) { fprintf(errorout,"Error at %d: Type Casting from 'float' to 'int'\n\n",lin_count); error_count++;  (yyvsp[-2])->value.ival=(yyvsp[0])->value.fval;}
          else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==2) { (yyvsp[-2])->value.ival=(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
          else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==3) { fprintf(errorout,"Error at %d: Type Casting from 'float' to 'int'\n\n",lin_count);
error_count++;  (yyvsp[-2])->value.ival=(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}

          else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==0) {fprintf(errorout,"Error at %d: Type Casting from 'int' to 'float'\n\n",lin_count); error_count++;  (yyvsp[-2])->value.fval=(yyvsp[0])->value.ival;}
          else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==1) {(yyvsp[-2])->value.fval=(yyvsp[0])->value.fval;}
          else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==2) {fprintf(errorout,"Error at %d: Type Casting from 'int' to 'float'\n\n",lin_count); error_count++;  (yyvsp[-2])->value.fval=(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
          else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==3) {(yyvsp[-2])->value.fval=(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}

          else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==0) {(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]=(yyvsp[0])->value.ival;}
          else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==1) {fprintf(errorout,"Error at %d: Type Casting from 'float' to 'int'\n\n",lin_count); error_count++;  (yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]=(yyvsp[0])->value.fval;}
          else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==2) {(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]=(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
          else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==3) {fprintf(errorout,"Error at %d: Type Casting from 'float' to 'int'\n\n",lin_count);
error_count++;   (yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]=(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos]; }

          else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==0) {fprintf(errorout,"Error at %d: Type Casting from 'int' to 'float'\n\n",lin_count); error_count++;  (yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]=(yyvsp[0])->value.ival; } 
          else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==1) { (yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]=(yyvsp[0])->value.fval; }
          else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==2) {fprintf(errorout,"Error at %d: Type Casting from 'int' to 'float'\n\n",lin_count); error_count++;  (yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]=(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos]; }
          else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==3) {(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]=(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}  
          

         string temp=newTemp();
         declare_code+=temp+ " dw " +"?\n";
         (yyval)=(yyvsp[-2]);
         (yyval)->code+=(yyvsp[0])->code;
         (yyval)->code+="mov ax,"+(yyvsp[0])->address+"\n";
         if((yyvsp[-2])->value.c==0) {(yyval)->code+="mov "+(yyvsp[-2])->symbol+",ax\n";}
         else if((yyvsp[-2])->value.c==2) {(yyval)->code+="mov "+(yyvsp[-2])->symbol+"[bx],ax\n";}
                   
        (yyval)->code+="mov "+temp+",1\n\n";
        (yyval)->address=temp;  


      table->AllScopePrint();

}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 596 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->logic_expression : rel_expression\n\n",lin_count); (yyval)=(yyvsp[0]);}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 597 "parser.y" /* yacc.c:1646  */
    {
fprintf(logout,"Line no %d->logic_expression : rel_expression LOGICOP rel_expression\n\n",lin_count);
                 if((yyvsp[-2])->value.arrayl==1) {(yyval)=(yyvsp[-2]);}
                 else if((yyvsp[0])->value.arrayl==1) {(yyval)=(yyvsp[0]);}
                 else{
                  SymbolInfo* p= new SymbolInfo;
                  p->code=(yyvsp[-2])->code+(yyvsp[0])->code;
                  string op=(yyvsp[-1])->name;
                  int temp;
               if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==0) {
                       int x=(yyvsp[-2])->value.ival;
                       int y=(yyvsp[0])->value.ival;
                         
                if(op=="&&") temp = x&&y;
		else if(op=="||") temp = x||y;
                                }
               else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==1) {
                         int x=(yyvsp[-2])->value.ival;
                         float y=(yyvsp[0])->value.fval;
                        
                 if(op=="&&") temp = x&&y;
		else if(op=="||") temp = x||y;
                                }
                 
                else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==2) {
                         int x=(yyvsp[-2])->value.ival;
                         int y=(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];
                        
                 if(op=="&&") temp = x&&y;
		else if(op=="||") temp = x||y;
                                }
                else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==3) {
                         int x=(yyvsp[-2])->value.ival;
                         float y=(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];
                        
                 if(op=="&&") temp = x&&y;
		else if(op=="||") temp = x||y;
                                }
                  
                     
                else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==0) {
                         float x=(yyvsp[-2])->value.fval;
                         int y=(yyvsp[0])->value.ival;
                        
                 if(op=="&&") temp = x&&y;
		else if(op=="||") temp = x||y;
                                }
                else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==1) {
                         float x=(yyvsp[-2])->value.fval;
                         float y=(yyvsp[0])->value.fval;
                        
                 if(op=="&&") temp = x&&y;
		else if(op=="||") temp = x||y;
                                }
                
                else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==2) {
                         float x=(yyvsp[-2])->value.fval;
                         int y=(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];
                        
                 if(op=="&&") temp = x&&y;
		else if(op=="||") temp = x||y;
                                }

                else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==3) {
                         float x=(yyvsp[-2])->value.fval;
                         float y=(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];
                        
                 if(op=="&&") temp = x&&y;
		else if(op=="||") temp = x||y;
                                }
 
                else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==0) {
                         int x=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos];
                         int y=(yyvsp[0])->value.ival;
                        
                 if(op=="&&") temp = x&&y;
		else if(op=="||") temp = x||y;
                                }
                
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==1) {
                         int x=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos];
                         float y=(yyvsp[0])->value.fval;
                        
                 if(op=="&&") temp = x&&y;
		else if(op=="||") temp = x||y;
                                }
                else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==2) {
                         int x=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos];
                         int y=(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];
                        
                 if(op=="&&") temp = x&&y;
		else if(op=="||") temp = x||y;
                                }

  
                else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==3) {
                         int x=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos];
                         float y=(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];
                        
                 if(op=="&&") temp = x&&y;
		else if(op=="||") temp = x||y;
                                }

                else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==0) {
                         float x=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos];
                         int y=(yyvsp[0])->value.ival;
                        
                 if(op=="&&") temp = x&&y;
		else if(op=="||") temp = x||y;
                                }

                else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==1) {
                         float x=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos];
                         float y=(yyvsp[0])->value.fval;
                        
                 if(op=="&&") temp = x&&y;
		else if(op=="||") temp = x||y;
                                }

               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==2) {
                         float x=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos];
                         int y=(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];
                        
                 if(op=="&&") temp = x&&y;
		else if(op=="||") temp = x||y;
                                }
               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==3) {
                         float x=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos];
                         float y=(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];
                        
                 if(op=="&&") temp = x&&y;
		else if(op=="||") temp = x||y;
                                }
 
         p->value.c=0;
         p->value.ival=temp;
         string temp1=newTemp();
         declare_code+=temp1+ " dw " +"?\n";
         string label_t=newLabel();
         string label_f=newLabel();

         p->code+="mov ax,"+(yyvsp[-2])->address+"\n";
         p->code+="cmp ax,0\n";
         if(op=="&&"){p->code+="je "+label_f+"\n";
                      p->code+="mov ax,"+(yyvsp[0])->address+"\n";
                      p->code+="cmp ax,0\n";
                      p->code+="je " + label_f + "\n";
                      p->code+="mov " + temp1 + ",1\n";
                      p->code+="jmp " + label_t+"\n";
                      p->code+=label_f + ":\n";
                      p->code+="mov " + temp1 + ", 0\n";
                      p->code+= label_t + ":\n\n";
                     }
         else if(op=="||"){p->code+="jne "+label_t+"\n";
                      p->code+="mov ax,"+(yyvsp[0])->address+"\n";
                      p->code+="cmp ax,0\n";
                      p->code+="jne " + label_t + "\n";
                      p->code+="mov " + temp1 + ",0\n";
                      p->code+="jmp " + label_f+"\n";
                      p->code+=label_t + ":\n";
                      p->code+="mov " + temp1 + ", 1\n";
                      p->code+= label_f + ":\n\n";
}
         p->address=temp1;
         (yyval)=p;
        
 
}

  

}
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 771 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->rel_expression	: simple_expression\n\n",lin_count); (yyval)=(yyvsp[0]);}
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 772 "parser.y" /* yacc.c:1646  */
    {
                 fprintf(logout,"Line no %d->rel_expression: simple_expression RELOP simple_expression\n\n",lin_count);
                 
                 if((yyvsp[-2])->value.arrayl==1) {(yyval)=(yyvsp[-2]);}
                 else if((yyvsp[0])->value.arrayl==1) {(yyval)=(yyvsp[0]);}
                 else{
                  SymbolInfo* p= new SymbolInfo;
                  p->code=(yyvsp[-2])->code+(yyvsp[0])->code;
                  string op=(yyvsp[-1])->name;
                  int temp;
               if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==0) {
                       int x=(yyvsp[-2])->value.ival;
                       int y=(yyvsp[0])->value.ival;
                         
                if (op==">") temp = x>y;
		else if(op=="<") temp = x<y;
		else if(op==">=") temp = x>=y;
		else if(op=="<=") temp = x<=y;
		else if(op=="==") temp = x==y;
		else if(op=="!=")  temp = x!=y;
		                                }
               else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==1) {
                         int x=(yyvsp[-2])->value.ival;
                         float y=(yyvsp[0])->value.fval;
                        
                if (op==">") temp = x>y;
		else if(op=="<") temp = x<y;
		else if(op==">=") temp = x>=y;
		else if(op=="<=") temp = x<=y;
		else if(op=="==") temp = x==y;
		else if(op=="!=")  temp = x!=y;
	
                                }
                 
                else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==2) {
                         int x=(yyvsp[-2])->value.ival;
                         int y=(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];
                        
                if (op==">") temp = x>y;
		else if(op=="<") temp = x<y;
		else if(op==">=") temp = x>=y;
		else if(op=="<=") temp = x<=y;
		else if(op=="==") temp = x==y;
		else if(op=="!=")  temp = x!=y;
	                        }
                else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==3) {
                         int x=(yyvsp[-2])->value.ival;
                         float y=(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];
                        
                if (op==">") temp = x>y;
		else if(op=="<") temp = x<y;
		else if(op==">=") temp = x>=y;
		else if(op=="<=") temp = x<=y;
		else if(op=="==") temp = x==y;
		else if(op=="!=")  temp = x!=y;
	                        }
                  
                     
                else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==0) {
                         float x=(yyvsp[-2])->value.fval;
                         int y=(yyvsp[0])->value.ival;
                        
                if (op==">") temp = x>y;
		else if(op=="<") temp = x<y;
		else if(op==">=") temp = x>=y;
		else if(op=="<=") temp = x<=y;
		else if(op=="==") temp = x==y;
		else if(op=="!=")  temp = x!=y;
	                        }
                else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==1) {
                         float x=(yyvsp[-2])->value.fval;
                         float y=(yyvsp[0])->value.fval;
                        
                if (op==">") temp = x>y;
		else if(op=="<") temp = x<y;
		else if(op==">=") temp = x>=y;
		else if(op=="<=") temp = x<=y;
		else if(op=="==") temp = x==y;
		else if(op=="!=")  temp = x!=y;
	                        }
                
                else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==2) {
                         float x=(yyvsp[-2])->value.fval;
                         int y=(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];
                        
                if (op==">") temp = x>y;
		else if(op=="<") temp = x<y;
		else if(op==">=") temp = x>=y;
		else if(op=="<=") temp = x<=y;
		else if(op=="==") temp = x==y;
		else if(op=="!=")  temp = x!=y;
	                        }

                else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==3) {
                         float x=(yyvsp[-2])->value.fval;
                         float y=(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];
                        
                if (op==">") temp = x>y;
		else if(op=="<") temp = x<y;
		else if(op==">=") temp = x>=y;
		else if(op=="<=") temp = x<=y;
		else if(op=="==") temp = x==y;
		else if(op=="!=")  temp = x!=y;
	                        }
 
                else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==0) {
                         int x=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos];
                         int y=(yyvsp[0])->value.ival;
                        
                if (op==">") temp = x>y;
		else if(op=="<") temp = x<y;
		else if(op==">=") temp = x>=y;
		else if(op=="<=") temp = x<=y;
		else if(op=="==") temp = x==y;
		else if(op=="!=")  temp = x!=y;
	                        }
                
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==1) {
                         int x=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos];
                         float y=(yyvsp[0])->value.fval;
                        
                if (op==">") temp = x>y;
		else if(op=="<") temp = x<y;
		else if(op==">=") temp = x>=y;
		else if(op=="<=") temp = x<=y;
		else if(op=="==") temp = x==y;
		else if(op=="!=")  temp = x!=y;
	                        }
                else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==2) {
                         int x=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos];
                         int y=(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];
                        
                if (op==">") temp = x>y;
		else if(op=="<") temp = x<y;
		else if(op==">=") temp = x>=y;
		else if(op=="<=") temp = x<=y;
		else if(op=="==") temp = x==y;
		else if(op=="!=")  temp = x!=y;
	                        }

  
                else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==3) {
                         int x=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos];
                         float y=(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];
                        
                if (op==">") temp = x>y;
		else if(op=="<") temp = x<y;
		else if(op==">=") temp = x>=y;
		else if(op=="<=") temp = x<=y;
		else if(op=="==") temp = x==y;
		else if(op=="!=")  temp = x!=y;
	                        }

                else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==0) {
                         float x=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos];
                         int y=(yyvsp[0])->value.ival;
                        
                if (op==">") temp = x>y;
		else if(op=="<") temp = x<y;
		else if(op==">=") temp = x>=y;
		else if(op=="<=") temp = x<=y;
		else if(op=="==") temp = x==y;
		else if(op=="!=")  temp = x!=y;
	                        }

                else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==1) {
                         float x=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos];
                         float y=(yyvsp[0])->value.fval;
                        
                if (op==">") temp = x>y;
		else if(op=="<") temp = x<y;
		else if(op==">=") temp = x>=y;
		else if(op=="<=") temp = x<=y;
		else if(op=="==") temp = x==y;
		else if(op=="!=")  temp = x!=y;
	                        }

               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==2) {
                         float x=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos];
                         int y=(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];
                        
                if (op==">") temp = x>y;
		else if(op=="<") temp = x<y;
		else if(op==">=") temp = x>=y;
		else if(op=="<=") temp = x<=y;
		else if(op=="==") temp = x==y;
		else if(op=="!=")  temp = x!=y;
	                        }
               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==3) {
                         float x=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos];
                         float y=(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];
                        
                if (op==">") temp = x>y;
		else if(op=="<") temp = x<y;
		else if(op==">=") temp = x>=y;
		else if(op=="<=") temp = x<=y;
		else if(op=="==") temp = x==y;
		else if(op=="!=")  temp = x!=y;
	                        }
 
         p->value.c=0;
         p->value.ival=temp;
         string temp1=newTemp();
         declare_code+=temp1+ " dw " +"?\n";
         string label_t=newLabel(); 
         string label_f=newLabel(); 
         p->code+="mov ax,"+(yyvsp[-2])->address+"\n";
         p->code+="cmp ax,"+(yyvsp[0])->address+"\n";
         if(op=="<") {p->code+="jl "+label_t+"\n";}
         else if(op==">") {p->code+="jg "+label_t+"\n";}
         else if(op==">=") {p->code+="jge "+label_t+"\n";}
         else if(op=="<=") {p->code+="jle "+label_t+"\n";}
         else if(op=="==") {p->code+="je "+label_t+"\n";}
         else if(op=="!=") {p->code+="jne "+label_t+"\n";}
         p->code+="mov "+temp1+",0\n";
         p->code+="jmp "+label_f+"\n";
         p->code+=label_t+":\n";
         p->code+="mov "+temp1+",1\n";
         p->code+=label_f+":\n\n";
         p->address=temp1;

         (yyval)=p;
         
 
}


                  }
#line 2500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1007 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->simple_expression : term\n\n",lin_count); (yyval)=(yyvsp[0]);}
#line 2506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1008 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->simple_expression : simple_expression\n\n",lin_count);

                 if((yyvsp[-2])->value.arrayl==1) {(yyval)=(yyvsp[-2]);}
                 else if((yyvsp[0])->value.arrayl==1) {(yyval)=(yyvsp[0]);}
                 else{
                     SymbolInfo* p = new SymbolInfo;
                     p->code=(yyvsp[-2])->code+(yyvsp[0])->code;
                   if((yyvsp[-1])->name=="+"){
                       if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==0) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.ival+(yyvsp[0])->value.ival;}
               else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==1) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.ival+(yyvsp[0])->value.fval;}
               else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==2) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.ival+(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
               else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.ival+(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}
               
               else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==0) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.fval+(yyvsp[0])->value.ival;}
               else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==1) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.fval+(yyvsp[0])->value.fval;}
               else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==2) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.fval+(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
               else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.fval+(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}
 
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==0) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]+(yyvsp[0])->value.ival;}
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==1) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]+(yyvsp[0])->value.fval;}
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==2) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]+(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]+(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}

               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==0) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]+(yyvsp[0])->value.ival;}
               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==1) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]+(yyvsp[0])->value.fval;}
               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==2) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]+(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]+(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}

                 }
                  else if((yyvsp[-1])->name=="-"){
                    if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==0) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.ival-(yyvsp[0])->value.ival;}
               else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==1) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.ival-(yyvsp[0])->value.fval;}
               else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==2) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.ival-(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
               else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.ival-(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}
 
               else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==0) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.fval-(yyvsp[0])->value.ival;}
               else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==1) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.fval-(yyvsp[0])->value.fval;}
               else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==2) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.fval-(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
               else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.fval-(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}
            
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==0) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]-(yyvsp[0])->value.ival;}
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==1) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]-(yyvsp[0])->value.fval;}
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==2) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]-(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]-(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}
                  
               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==0) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]-(yyvsp[0])->value.ival;}
               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==1) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]-(yyvsp[0])->value.fval;}
               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==2) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]-(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]-(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}


                 }

          string temp=newTemp();
          declare_code+=temp+ " dw " +"?\n";
             p->code+="mov ax,"+(yyvsp[-2])->address+"\n";
              if((yyvsp[-1])->name=="+"){p->code+="add ax,"+(yyvsp[0])->address+"\n";}
              else if((yyvsp[-1])->name=="-"){p->code+="sub ax,"+(yyvsp[0])->address+"\n";}
             p->code+="mov "+temp+",ax\n\n";
             p->address=temp;
             (yyval)=p;
             
   }  
               
     table->AllScopePrint();



}
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1079 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->term :	unary_expression\n\n",lin_count); (yyval)=(yyvsp[0]);}
#line 2586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1080 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->term :	term MULOP unary_expression\n\n",lin_count);

        if((yyvsp[-2])->value.arrayl==1) {(yyval)=(yyvsp[-2]);}
        else if((yyvsp[0])->value.arrayl==1) {(yyval)=(yyvsp[0]);}
        else{
             SymbolInfo* p=new SymbolInfo;
             p->code=(yyvsp[-2])->code+(yyvsp[0])->code;
             if((yyvsp[-1])->name=="*"){
               if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==0) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.ival*(yyvsp[0])->value.ival;}
               else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==1) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.ival*(yyvsp[0])->value.fval;}
               else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==2) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.ival*(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
               else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.ival*(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}
     
               else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==0) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.fval*(yyvsp[0])->value.ival;}
               else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==1) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.fval*(yyvsp[0])->value.fval;}
               else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==2) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.fval*(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
               else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.fval*(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}
               
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==0) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]*(yyvsp[0])->value.ival;}
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==1) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]*(yyvsp[0])->value.fval;}
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==2) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]*(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]*(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}
               
               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==0) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]*(yyvsp[0])->value.ival;}
               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==1) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]*(yyvsp[0])->value.fval;}
               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==2) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]*(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]*(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}
                 }
             else if((yyvsp[-1])->name=="/"){
               if (((yyvsp[0])->value.c==0 && (yyvsp[0])->value.ival==0) || ((yyvsp[0])->value.c==1 && (yyvsp[0])->value.fval==0) || ((yyvsp[0])->value.c==2 && (yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos]) || ((yyvsp[0])->value.c==3 && (yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos])) {fprintf(errorout,"Line no %d: divedend by zero error\n\n",lin_count); error_count++; p=dam;  }
               else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==0) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.ival/(yyvsp[0])->value.ival;}                
               else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==0) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.ival/(yyvsp[0])->value.fval;}
               else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==2) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.ival/(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
               else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.ival/(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}
               
               else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==0) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.fval/(yyvsp[0])->value.ival;}
               else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==1) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.fval/(yyvsp[0])->value.fval;}
               else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==2) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.fval/(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
               else if((yyvsp[-2])->value.c==1 && (yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.fval/(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}
               
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==0) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]/(yyvsp[0])->value.ival;}
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==1) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]/(yyvsp[0])->value.fval;}
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==2) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]/(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
               else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos]/(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}
             
               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==0) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]/(yyvsp[0])->value.ival;}
               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==1) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]/(yyvsp[0])->value.fval;}
               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==2) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]/(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
               else if((yyvsp[-2])->value.c==3 && (yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=(yyvsp[-2])->value.farray[(yyvsp[-2])->value.arraypos]/(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}
                         

               }
             else if((yyvsp[-1])->name=="%"){
                
                if((yyvsp[-2])->value.c==1 || (yyvsp[-2])->value.c==3 || (yyvsp[0])->value.c==1 || (yyvsp[0])->value.c==3){fprintf(errorout,"Line no %d: Ivalid operands to binary %\n\n ",lin_count); error_count++; p=dam;}
                else if((yyvsp[-2])->value.c==0 && (yyvsp[0])->value.c==0) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.ival % (yyvsp[0])->value.ival;}
                else if((yyvsp[-1])->value.c==0 && (yyvsp[0])->value.c==2) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.ival % (yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
                else if((yyvsp[-2])->value.c==2 && (yyvsp[0])->value.c==0) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos] % (yyvsp[0])->value.ival;}
                else if((yyvsp[-1])->value.c==2 && (yyvsp[0])->value.c==2) {p->value.c=0; p->value.ival=(yyvsp[-2])->value.iarray[(yyvsp[-2])->value.arraypos] % (yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}

               }
          string temp=newTemp();
          declare_code+=temp+ " dw " +"?\n";
               
          p->code+="mov dx,0\n";
          p->code+="mov ax,"+(yyvsp[-2])->address+"\n";
          if((yyvsp[-1])->name=="*") {p->code+="mul "+(yyvsp[0])->address +"\n";}
          else if((yyvsp[-1])->name=="/" || (yyvsp[-1])->name=="%"){p->code+="div "+(yyvsp[0])->address +"\n";}

          if((yyvsp[-1])->name=="*" || (yyvsp[-1])->name=="/"){p->code+="mov "+temp+",ax\n\n";}
          else if((yyvsp[-1])->name=="%") {p->code+="mov "+temp+",dx\n\n";}
          
          
          p->address=temp;

          (yyval)=p;
           
} 
   table->AllScopePrint();
}
#line 2671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1162 "parser.y" /* yacc.c:1646  */
    { fprintf(logout,"Line no %d-> unary_expression : ADDOP unary_expression\n\n",lin_count);
                   if((yyvsp[0])->value.arrayl==1) {(yyval)=(yyvsp[0]);}
                   else{
                    SymbolInfo* p= new SymbolInfo;
                    if((yyvsp[-1])->name=="+") {

                        
                        if((yyvsp[0])->value.c==0) {p->value.c=(yyvsp[0])->value.c; p->value.ival=(yyvsp[0])->value.ival;  }
                        else if((yyvsp[0])->value.c==1) {p->value.c=(yyvsp[0])->value.c; p->value.fval=(yyvsp[0])->value.fval;}
                        else if((yyvsp[0])->value.c==2) {p->value.c=0; p->value.ival=(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
                        else if((yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}
                          }
                   else if((yyvsp[-1])->name=="-"){
                        if((yyvsp[0])->value.c==0) {

                        p->value.c=(yyvsp[0])->value.c; 
                        p->value.ival=-(yyvsp[0])->value.ival;
}
                        else if((yyvsp[0])->value.c==1) {p->value.c=(yyvsp[0])->value.c; p->value.fval=-(yyvsp[0])->value.fval;}
                        else if((yyvsp[0])->value.c==2) {p->value.c=0; p->value.ival=-(yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos];}
                        else if((yyvsp[0])->value.c==3) {p->value.c=1; p->value.fval=-(yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos];}
                           


                          }
                        
                     p->code=(yyvsp[0])->code;
                     if((yyvsp[-1])->name=="-"){
                     string temp=newTemp();
                    declare_code+=temp+ " dw " +"?\n";
                    p->code+="mov ax, " + (yyvsp[0])->address + "\n";
		    p->code+="neg ax\n";
		    p->code+="mov "+temp+", ax\n\n";


}


                     (yyval)=p;
                    
 }
                  table->AllScopePrint();
                  
}
#line 2720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1206 "parser.y" /* yacc.c:1646  */
    { fprintf(logout,"Line no %d-> unary_expression : NOT unary_expression\n\n",lin_count);
                   
                   if((yyvsp[0])->value.arrayl==1){(yyval)=(yyvsp[0]);} 
                   else{
                   SymbolInfo* p=new SymbolInfo;
                   p->value.c=0;
                  
                   if((yyvsp[0])->value.c==0) {p->value.ival=!((yyvsp[0])->value.ival);
                    


                    }
                   else if((yyvsp[0])->value.c==1) {p->value.ival=!((yyvsp[0])->value.fval);}
                   else if((yyvsp[0])->value.c==2) {p->value.ival=!((yyvsp[0])->value.iarray[(yyvsp[0])->value.arraypos]);
                   




                   }
                   else if((yyvsp[0])->value.c==3) {p->value.ival=!((yyvsp[0])->value.farray[(yyvsp[0])->value.arraypos]);}
                                        
                    p->code=(yyvsp[0])->code;
                    string temp=newTemp();
                    string label1=newLabel(); 
                    string label2=newLabel(); 
                    declare_code+=temp+ " dw " +"?\n";
                    
                    p->code+="mov ax, " + (yyvsp[0])->address + "\n";
		    p->code+="cmp ax,0\n";
                    p->code+="je "+label1+"\n";
                    p->code+="mov "+temp+",0\n";
                    p->code+="jmp "+label2+"\n";
                    p->code+=label1+":\n";
                    p->code+="mov "+temp+",1\n";
                    p->code+=label2+":\n";
                    
		    p->address=temp;

                   (yyval)=p;
                   
                         }
                  table->AllScopePrint();
}
#line 2769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1250 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->unary_expression: factor\n\n",lin_count); (yyval)=(yyvsp[0]);}
#line 2775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1253 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->factor: variable\n\n",lin_count);
                (yyval)=(yyvsp[0]);
                if((yyvsp[0])->value.arrayl==1) {}                      
                else if((yyvsp[0])->value.c==0) { (yyval)->address=(yyvsp[0])->symbol;}
                else if((yyvsp[0])->value.c==2) {
                string temp=newTemp();
                declare_code+=temp+ " dw " +"?\n";
                (yyval)->code+= "mov ax, " +(yyvsp[0])->symbol+"[bx]\n";
                (yyval)->code+="mov "+temp+",ax\n\n";
                
                (yyval)->address=temp; 
               }           



                    }
#line 2796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1269 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->factor: ID LPAREN argument_list RPAREN\n\n",lin_count);
             SymbolInfo* p=new SymbolInfo;
           SymbolInfo* temp=table->LookAll((yyvsp[-3])->name);
         
          if(temp==NULL) {fprintf(errorout,"Error at Line %d: function is not defined\n\n",lin_count); p=dam; error_count++;}
          else if(temp->isF==0) {fprintf(errorout,"Error at Line %d: function is only declared , no defined\n\n",lin_count); p=dam; error_count++; }
          else if(temp->isF==-1) {fprintf(errorout,"Error at Line %d: Not a Function\n\n",lin_count); p=dam; error_count++; }
          else if(temp->fsize!=pos1 ) {fprintf(errorout,"Error at Line %d: parameter numbers are no equal\n\n",lin_count); p=dam; error_count++;} 
          else if(temp->fsize==0 && pos1==0 && temp->fsign==0) {p->value.c=0; p->value.ival=temp->funi;}
          else if(temp->fsize==0 && pos1==0 && temp->fsign==1) {p->value.c=1; p->value.fval=temp->funf;}
          else if(temp->fsize==0 && pos1==0 && temp->fsign==2) {}
          
          else  if(temp->fsize==pos1){ int i=0,k=0;
for(i=0;i<temp->fsize;i++){if(temp->f[i]!=flow1[i]) {fprintf(errorout,"Error at Line %d: perameter is not matched\n\n",lin_count);} p=dam; k=1; error_count++; break; }
          if(k==0){
                   if(temp->fsign==0) {p->value.c=0; p->value.ival=temp->funi;}
                   else if(temp->fsign==1) {p->value.c=1; p->value.fval=temp->funf;}
                   else if(temp->fsign==2) {p->value.arrayl=1;}
  }

}        
         for(int i=0;i<pos1;i++){

            p->code+="mov "+temp->variable[i]+","+IntToString(flow2[i])+"\n";

                        } 
         p->code+="\ncall  " +temp->name+"\n\n";   
         (yyval)=p;
         pos1=0;
               


}
#line 2834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1307 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->factor: LPAREN expression RPAREN\n\n",lin_count); (yyval)=(yyvsp[-1]);}
#line 2840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1308 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->factor: CONST_INT\n %s\n\n",lin_count,(yyvsp[0])->name.c_str()); (yyval)=(yyvsp[0]); (yyval)->address=IntToString((yyvsp[0])->value.ival); }
#line 2846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1309 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->factor: CONST_FLOAT\n %s\n\n",lin_count,(yyvsp[0])->name.c_str()); (yyval)=(yyvsp[0]);}
#line 2852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1310 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->factor: variable INCOP\n\n",lin_count);
(yyval)=new SymbolInfo((yyvsp[-1])->name,(yyvsp[-1])->type,(yyvsp[-1])->value.ival,(yyvsp[-1])->value.fval,(yyvsp[-1])->value.arraysize,(yyvsp[-1])->value.arraypos,-1111,-1111,(yyvsp[-1])->value.c);
 
                          if((yyvsp[-1])->value.arrayl==1){(yyval)->value.arrayl=1;}
                          else {  
                          int c=(yyvsp[-1])->value.arraypos;  
                          if((yyvsp[-1])->value.c==0) {
                          
                          string temp=newTemp();
                            declare_code+=temp+ " dw " +"?\n";
                            string code="";
                            code = code+"mov ax," + (yyvsp[-1])->symbol+"\n";
                            code+="mov "+temp+",ax\n";
                            code+="inc ax\n";
                            code+="mov "+(yyvsp[-1])->symbol+",ax\n\n";
                            (yyval)->code=(yyvsp[-1])->code+code;
                            (yyval)->address=temp;
                            (yyvsp[-1])->value.ival=(yyvsp[-1])->value.ival+1;

}
                          else if((yyvsp[-1])->value.c==1) {(yyvsp[-1])->value.fval=(yyvsp[-1])->value.fval+1;}
                          else if((yyvsp[-1])->value.c==2) {
                          
                           string temp=newTemp();
                           declare_code+=temp+ " dw " +"?\n";
                           string code="";
                         
                           code+= "mov ax, " +(yyvsp[-1])->symbol+"[bx]\n";
                           code+="mov "+temp+",ax\n";
                           code+="inc ax\n";
                           code+="mov "+(yyvsp[-1])->symbol+"[bx],ax\n\n";

                           (yyval)->code=(yyvsp[-1])->code+code;
                           (yyval)->address=temp;
                            (yyval)->value.iarray[c]=(yyvsp[-1])->value.iarray[c];
                           (yyvsp[-1])->value.iarray[c]=(yyvsp[-1])->value.iarray[c]+1;
                            
}
                          else if((yyvsp[-1])->value.c==3) {(yyval)->value.farray[c]=(yyvsp[-1])->value.farray[c]; (yyvsp[-1])->value.farray[c]=(yyvsp[-1])->value.farray[c]+1;}
                          }
                         
                          
                          table->AllScopePrint(); 
  

}
#line 2903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1356 "parser.y" /* yacc.c:1646  */
    { fprintf(logout,"Line no %d->factor: variable DECOP\n\n",lin_count);
                (yyval)=new SymbolInfo((yyvsp[-1])->name,(yyvsp[-1])->type,(yyvsp[-1])->value.ival,(yyvsp[-1])->value.fval,(yyvsp[-1])->value.arraysize,(yyvsp[-1])->value.arraypos,-1111,-1111,(yyvsp[-1])->value.c); 
                   
                  if((yyvsp[-1])->value.arrayl==1){(yyval)->value.arrayl=1;}
                  else {  
                          int c=(yyvsp[-1])->value.arraypos;  
                          
                          if((yyvsp[-1])->value.c==0) {  
                            
                            string temp=newTemp();
                            declare_code+=temp+ " dw " +"?\n";
                            string code="";
                            code = code+"mov ax," + (yyvsp[-1])->symbol+"\n";
                            code+="mov "+temp+",ax\n";
                            code+="dec ax\n";
                            code+="mov "+(yyvsp[-1])->symbol+",ax\n\n";
                            (yyval)->code=(yyvsp[-1])->code+code;
                            (yyval)->address=temp;
                            
                            (yyvsp[-1])->value.ival=(yyvsp[-1])->value.ival-1;
                            
                            
                              }
                          else if((yyvsp[-1])->value.c==1) { (yyvsp[-1])->value.fval=(yyvsp[-1])->value.fval-1; }
                          else if((yyvsp[-1])->value.c==2) { 
                          
                           string temp=newTemp();
                           declare_code+=temp+ " dw " +"?\n";
                           string code="";
                         
                           code+= "mov ax, " +(yyvsp[-1])->symbol+"[bx]\n";
                           code+="mov "+temp+",ax\n";
                           code+="dec ax\n";
                           code+="mov "+(yyvsp[-1])->symbol+"[bx],ax\n\n";

                           (yyval)->code=(yyvsp[-1])->code+code;
                           (yyval)->address=temp;
                           (yyval)->value.iarray[c]=(yyvsp[-1])->value.iarray[c];
                           (yyvsp[-1])->value.iarray[c]=(yyvsp[-1])->value.iarray[c]-1;
                           

}
                          else if((yyvsp[-1])->value.c==3) {(yyval)->value.farray[c]=(yyvsp[-1])->value.farray[c]; (yyvsp[-1])->value.farray[c]=(yyvsp[-1])->value.farray[c]-1;  } 
                       }
                     
                     
                     table->AllScopePrint(); 
           }
#line 2956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1408 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->argument_list: arguments\n\n",lin_count);}
#line 2962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1409 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->argument_list: ",lin_count); }
#line 2968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1411 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->arguments: arguments COMMA logic_expression\n\n",lin_count);               
                              if((yyvsp[0])->value.c==0 || (yyvsp[0])->value.c==1) {flow1[pos1]=(yyvsp[0])->value.c; flow2[pos1]=(yyvsp[0])->value.ival;
  pos1++;}
                              else {flow1[pos]=-2; pos++;}

}
#line 2979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1417 "parser.y" /* yacc.c:1646  */
    {fprintf(logout,"Line no %d->arguments: logic_expression\n\n",lin_count); 


              
               if((yyvsp[0])->value.c==0 || (yyvsp[0])->value.c==1) {flow1[pos1]=(yyvsp[0])->value.c; flow2[pos1]=(yyvsp[0])->value.ival; 
                    
                     pos1++;}
               else {flow1[pos]=-2; pos++;}
}
#line 2993 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2997 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1437 "parser.y" /* yacc.c:1906  */

int main(int argc,char *argv[])
{
        table=new SymbolTable(7);
        dam=new SymbolInfo;
        dam->value.arrayl=1;
        dam->value.c=-2;
        declare_code = "\n";
        
	FILE *fp;	
	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}


        logout=fopen("log.txt","w");
        errorout=fopen("error.txt","w");
        asmout=fopen("code.asm","w");	
	

	yyin=fp;
	yyparse();

        fprintf(logout,"Total Line: %d\n\n",lin_count);
        fprintf(logout,"Total Error: %d\n\n",error_count);
        declare_code = declare_code + "\n\n";
 	
 	total_code = initial_code + declare_code + main_code;
 	if(println==1){total_code = total_code + "\n" +dec_print+ "\nEND MAIN\n"+function_code;}
        else {total_code = total_code + "\n" +"\nEND MAIN\n"+function_code;}
        
        fprintf(asmout,"%s",total_code.c_str());
        
	fclose(yyin);
        fclose(logout);
        fclose(errorout);

	
	return 0;
}
