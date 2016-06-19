/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "pascal.y" /* yacc.c:339  */

#define YYPARSER
#include "global.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreePtr

static TreePtr theTree;
extern FILE * yyin;
int yylex();
int yyerror(char*);

#line 81 "pascal.tab.c" /* yacc.c:339  */

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
   by #include "pascal.tab.h".  */
#ifndef YY_YY_PASCAL_TAB_H_INCLUDED
# define YY_YY_PASCAL_TAB_H_INCLUDED
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
    NOT = 258,
    MUL = 259,
    DIV = 260,
    IDIV = 261,
    MOD = 262,
    AND = 263,
    PLUS = 264,
    MINUS = 265,
    OR = 266,
    DOT = 267,
    COLON = 268,
    COMMA = 269,
    SEMI = 270,
    ASSIGN = 271,
    EQUAL = 272,
    UNEQUAL = 273,
    GE = 274,
    GT = 275,
    LE = 276,
    LT = 277,
    LP = 278,
    RP = 279,
    LB = 280,
    RB = 281,
    TRUE = 282,
    FALSE = 283,
    MAXINT = 284,
    SYST_BOOLEAN = 285,
    SYST_CHAR = 286,
    SYST_INTEGER = 287,
    SYST_REAL = 288,
    SYST_STRING = 289,
    SYSP_WRITELN = 290,
    SYSP_WRITE = 291,
    SYSP_READLN = 292,
    SYSP_READ = 293,
    PROGRAM = 294,
    TYPE = 295,
    VAR = 296,
    CONST = 297,
    ARRAY = 298,
    RECORD = 299,
    FUNCTION = 300,
    PROCEDURE = 301,
    OF = 302,
    PBEGIN = 303,
    END = 304,
    IF = 305,
    THEN = 306,
    ELSE = 307,
    REPEAT = 308,
    UNTIL = 309,
    WHILE = 310,
    DO = 311,
    FOR = 312,
    TO = 313,
    DOWNTO = 314,
    CASE = 315,
    GOTO = 316,
    ID = 317,
    INTEGER = 318,
    REAL = 319,
    CHAR = 320,
    STRING = 321,
    IFX = 322
  };
#endif
/* Tokens.  */
#define NOT 258
#define MUL 259
#define DIV 260
#define IDIV 261
#define MOD 262
#define AND 263
#define PLUS 264
#define MINUS 265
#define OR 266
#define DOT 267
#define COLON 268
#define COMMA 269
#define SEMI 270
#define ASSIGN 271
#define EQUAL 272
#define UNEQUAL 273
#define GE 274
#define GT 275
#define LE 276
#define LT 277
#define LP 278
#define RP 279
#define LB 280
#define RB 281
#define TRUE 282
#define FALSE 283
#define MAXINT 284
#define SYST_BOOLEAN 285
#define SYST_CHAR 286
#define SYST_INTEGER 287
#define SYST_REAL 288
#define SYST_STRING 289
#define SYSP_WRITELN 290
#define SYSP_WRITE 291
#define SYSP_READLN 292
#define SYSP_READ 293
#define PROGRAM 294
#define TYPE 295
#define VAR 296
#define CONST 297
#define ARRAY 298
#define RECORD 299
#define FUNCTION 300
#define PROCEDURE 301
#define OF 302
#define PBEGIN 303
#define END 304
#define IF 305
#define THEN 306
#define ELSE 307
#define REPEAT 308
#define UNTIL 309
#define WHILE 310
#define DO 311
#define FOR 312
#define TO 313
#define DOWNTO 314
#define CASE 315
#define GOTO 316
#define ID 317
#define INTEGER 318
#define REAL 319
#define CHAR 320
#define STRING 321
#define IFX 322

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PASCAL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 266 "pascal.tab.c" /* yacc.c:358  */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   369

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  251

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    27,    27,    33,    39,    45,    53,    54,    56,    66,
      73,    76,    79,    83,    87,    90,    93,    97,    98,   100,
     108,   110,   116,   117,   118,   120,   121,   122,   123,   124,
     125,   126,   128,   134,   136,   146,   148,   154,   168,   173,
     174,   176,   185,   187,   193,   201,   209,   210,   211,   213,
     219,   226,   232,   238,   239,   241,   249,   251,   256,   262,
     264,   266,   268,   277,   279,   283,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   295,   299,   304,   311,   315,
     320,   325,   330,   336,   337,   339,   343,   347,   353,   358,
     363,   371,   372,   374,   379,   387,   389,   393,   398,   402,
     410,   412,   417,   422,   427,   432,   437,   442,   444,   449,
     454,   459,   461,   466,   471,   476,   481,   486,   488,   492,
     495,   496,   500,   504,   508
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NOT", "MUL", "DIV", "IDIV", "MOD",
  "AND", "PLUS", "MINUS", "OR", "DOT", "COLON", "COMMA", "SEMI", "ASSIGN",
  "EQUAL", "UNEQUAL", "GE", "GT", "LE", "LT", "LP", "RP", "LB", "RB",
  "TRUE", "FALSE", "MAXINT", "SYST_BOOLEAN", "SYST_CHAR", "SYST_INTEGER",
  "SYST_REAL", "SYST_STRING", "SYSP_WRITELN", "SYSP_WRITE", "SYSP_READLN",
  "SYSP_READ", "PROGRAM", "TYPE", "VAR", "CONST", "ARRAY", "RECORD",
  "FUNCTION", "PROCEDURE", "OF", "PBEGIN", "END", "IF", "THEN", "ELSE",
  "REPEAT", "UNTIL", "WHILE", "DO", "FOR", "TO", "DOWNTO", "CASE", "GOTO",
  "ID", "INTEGER", "REAL", "CHAR", "STRING", "IFX", "$accept", "program",
  "routing", "routing_head", "const_part", "const_expr_list",
  "const_value", "type_part", "type_decl_list", "type_definition",
  "type_decl", "type_decl_simple", "type_decl_array", "type_decl_record",
  "field_decl_list", "field_decl", "name_list", "var_part",
  "var_decl_list", "var_decl", "routing_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "parameters",
  "para_decl_list", "para_type_list", "var_para_list", "val_para_list",
  "routing_body", "stmt_list", "stmt", "non_label_stmt", "assign_stmt",
  "proc_stmt", "args", "compound_stmt", "if_stmt", "repeat_stmt",
  "while_stmt", "for_stmt", "direction", "case_stmt", "case_expr_list",
  "case_expr", "goto_stmt", "expression_list", "expression", "expr",
  "term", "factor", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322
};
# endif

#define YYPACT_NINF -153

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-153)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -24,   -43,   -29,    41,    33,     9,    20,    48,    73,    38,
    -153,  -153,  -153,  -153,    40,    51,    67,   119,    98,   185,
     120,    40,  -153,    80,    43,   137,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,   135,   119,   139,   139,   139,   139,  -153,
    -153,     2,  -153,     2,    97,     2,   116,   245,   147,  -153,
    -153,   172,   181,  -153,  -153,   188,  -153,  -153,  -153,   189,
      89,  -153,  -153,   122,    80,  -153,   155,   162,    43,  -153,
     190,  -153,   210,  -153,  -153,   212,     2,  -153,  -153,  -153,
    -153,   214,     2,     2,     2,     1,  -153,    18,    62,    90,
    -153,   243,    29,   215,   194,  -153,   166,     2,     2,  -153,
     301,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
     205,    80,  -153,   220,   221,  -153,  -153,  -153,    89,   175,
    -153,   216,   216,  -153,  -153,    67,    67,  -153,    30,   323,
    -153,  -153,  -153,   294,   182,     2,  -153,     2,     2,     2,
       2,     2,     2,   272,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   272,     2,   144,   237,   323,   108,  -153,
     136,   -35,  -153,   143,   231,  -153,   239,  -153,   -34,   242,
    -153,   241,   244,     2,  -153,  -153,  -153,   266,    62,    62,
      62,    62,    62,    62,   206,    90,    90,    90,  -153,  -153,
    -153,  -153,  -153,   323,  -153,    86,   247,   252,   112,  -153,
       2,   250,   246,  -153,  -153,   136,   119,  -153,    80,   259,
      -4,  -153,   269,   276,   136,  -153,  -153,   323,  -153,   272,
    -153,  -153,     2,   272,   272,  -153,  -153,   323,     2,   248,
     275,  -153,   259,   -34,  -153,   136,   136,  -153,  -153,   173,
    -153,  -153,   323,   136,  -153,  -153,  -153,  -153,   272,  -153,
    -153
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     0,     0,     0,     0,    18,     0,     0,     6,
       1,     3,    63,     4,     0,    40,     7,     0,     0,     0,
       0,    17,    20,     0,    48,     0,    14,    15,    16,    10,
      11,    12,    13,     0,     0,    84,    84,    84,    84,    63,
      61,     0,    63,     0,     0,     0,     0,    84,     0,    62,
      65,     0,     0,    68,    69,     0,    71,    72,    73,     0,
       0,    19,    38,     0,    39,    42,     0,     0,     5,    46,
       0,    47,     0,     2,     9,     0,     0,    82,    81,    80,
      79,     0,     0,     0,     0,    84,   119,     0,   107,   111,
     117,     0,     0,     0,     0,    98,     0,     0,     0,    78,
       0,    66,    67,    70,    74,    25,    26,    27,    28,    29,
       0,     0,    30,     0,     0,    22,    23,    24,     0,     0,
      41,    54,    54,    44,    45,     7,     7,     8,     0,   100,
      85,   121,   122,     0,     0,     0,   118,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,     0,    64,
       0,     0,    35,     0,     0,    21,     0,    37,     0,     0,
      52,     0,     0,     0,    83,   120,   124,     0,   105,   106,
     101,   102,   103,   104,    86,   108,   109,   110,   112,   113,
     116,   114,   115,    88,    89,     0,     0,     0,     0,    95,
       0,     0,     0,    33,    34,     0,     0,    43,     0,    60,
       0,    56,     0,     0,     0,    49,    51,    99,   123,     0,
      91,    92,     0,     0,     0,    93,    94,    77,     0,     0,
       0,    31,    59,     0,    53,     0,     0,    50,    87,     0,
      97,    96,    76,     0,    36,    55,    57,    58,     0,    32,
      90
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,   -12,  -153,  -153,  -153,   -17,  -153,  -153,   273,
     183,  -152,  -153,  -153,  -153,   138,  -109,  -153,  -153,   238,
    -153,   249,  -153,   251,  -153,   199,  -153,    91,  -153,  -153,
    -153,    19,  -137,   223,  -153,  -153,   -15,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,   128,  -153,  -153,   -42,   227,
     -65,   -73
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     9,    86,    15,    21,    22,
     114,   115,   116,   117,   161,   162,    63,    24,    64,    65,
      68,    69,    70,    71,    72,   169,   210,   211,   212,   213,
      13,    19,    49,    50,    51,    52,    77,    53,    54,    55,
      56,    57,   222,    58,   198,   199,    59,   128,    87,    88,
      89,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    92,   163,    94,    25,    82,   184,   208,   202,   131,
     132,   233,    83,   134,   203,     1,   194,    75,     2,     7,
     234,    78,    79,    80,    76,    84,   135,    62,    62,    26,
      27,    28,    99,     8,   129,   137,   138,   139,   140,   141,
     142,    10,   133,   113,   173,    11,   137,   138,   139,   140,
     141,   142,   163,   230,   174,   157,   158,    12,    81,   209,
      14,    91,   237,    16,    85,    29,    30,    31,    32,   143,
     136,   144,   145,   146,   188,   189,   190,   191,   192,   185,
     186,   187,   238,   246,   247,   153,   240,   241,    66,    67,
      17,   249,    23,   177,   147,   148,   149,   150,   151,   232,
      18,   113,    20,   137,   138,   139,   140,   141,   142,     2,
     193,   250,   195,   171,   172,    34,    26,    27,    28,   105,
     106,   107,   108,   109,   209,   137,   138,   139,   140,   141,
     142,   217,   110,   111,   201,   118,   119,    60,   197,    26,
      27,    28,    62,   113,   220,   221,    26,    27,    28,    73,
      74,   112,    29,    30,    31,    32,   205,   119,   227,    93,
     100,   225,    76,    26,    27,    28,   105,   106,   107,   108,
     109,    26,    27,    28,   196,    29,    30,    31,    32,    95,
     239,   197,    29,    30,    31,    32,   242,   101,   113,   231,
     137,   138,   139,   140,   141,   142,   102,   113,   112,    29,
      30,    31,    32,   103,   104,   125,   196,    29,    30,    31,
      32,   137,   138,   139,   140,   141,   142,   121,   113,   113,
      35,    36,    37,    38,   122,   126,   113,   127,   156,   248,
     160,   154,   164,    39,    40,    41,   165,   167,    42,   168,
      43,   155,    44,   206,   176,    45,    46,    47,    48,    35,
      36,    37,    38,   200,   207,   214,   215,    96,   219,   216,
     223,    97,    39,   130,    41,   224,   228,    42,    76,    43,
      98,    44,   229,   119,    45,    46,    47,    48,    35,    36,
      37,    38,   235,   137,   138,   139,   140,   141,   142,   236,
     244,    39,   218,    41,    61,   243,    42,   152,    43,   204,
      44,   166,   120,    45,    46,    47,    48,    35,    36,    37,
      38,   137,   138,   139,   140,   141,   142,   123,   175,   124,
      39,   170,    41,   159,   245,    42,   226,    43,     0,    44,
       0,     0,    45,    46,    47,    48,    35,    36,    37,    38,
     137,   138,   139,   140,   141,   142,     0,     0,     0,    39,
       0,    41,     0,     0,    42,     0,    43,     0,    44,     0,
       0,    45,    46,    47,   178,   179,   180,   181,   182,   183
};

static const yytype_int16 yycheck[] =
{
      17,    43,   111,    45,    16,     3,   143,    41,   160,    82,
      83,    15,    10,    12,    49,    39,   153,    34,    42,    62,
      24,    36,    37,    38,    23,    23,    25,    62,    62,    27,
      28,    29,    47,    62,    76,    17,    18,    19,    20,    21,
      22,     0,    84,    60,    14,    12,    17,    18,    19,    20,
      21,    22,   161,   205,    24,    97,    98,    48,    39,   168,
      40,    42,   214,    15,    62,    63,    64,    65,    66,    51,
      85,     9,    10,    11,   147,   148,   149,   150,   151,   144,
     145,   146,   219,   235,   236,    56,   223,   224,    45,    46,
      17,   243,    41,   135,     4,     5,     6,     7,     8,   208,
      62,   118,    62,    17,    18,    19,    20,    21,    22,    42,
     152,   248,   154,   125,   126,    17,    27,    28,    29,    30,
      31,    32,    33,    34,   233,    17,    18,    19,    20,    21,
      22,   173,    43,    44,    26,    13,    14,    17,   155,    27,
      28,    29,    62,   160,    58,    59,    27,    28,    29,    12,
      15,    62,    63,    64,    65,    66,    13,    14,   200,    62,
      13,    49,    23,    27,    28,    29,    30,    31,    32,    33,
      34,    27,    28,    29,    62,    63,    64,    65,    66,    63,
     222,   198,    63,    64,    65,    66,   228,    15,   205,   206,
      17,    18,    19,    20,    21,    22,    15,   214,    62,    63,
      64,    65,    66,    15,    15,    15,    62,    63,    64,    65,
      66,    17,    18,    19,    20,    21,    22,    62,   235,   236,
      35,    36,    37,    38,    62,    15,   243,    15,    62,    56,
      25,    16,    12,    48,    49,    50,    15,    62,    53,    23,
      55,    47,    57,    12,    62,    60,    61,    62,    63,    35,
      36,    37,    38,    16,    15,    13,    15,    12,    52,    15,
      13,    16,    48,    49,    50,    13,    16,    53,    23,    55,
      25,    57,    26,    14,    60,    61,    62,    63,    35,    36,
      37,    38,    13,    17,    18,    19,    20,    21,    22,    13,
      15,    48,    26,    50,    21,    47,    53,    54,    55,   161,
      57,   118,    64,    60,    61,    62,    63,    35,    36,    37,
      38,    17,    18,    19,    20,    21,    22,    68,    24,    68,
      48,   122,    50,   100,   233,    53,   198,    55,    -1,    57,
      -1,    -1,    60,    61,    62,    63,    35,    36,    37,    38,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    53,    -1,    55,    -1,    57,    -1,
      -1,    60,    61,    62,   137,   138,   139,   140,   141,   142
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    42,    69,    70,    71,    72,    62,    62,    73,
       0,    12,    48,    98,    40,    75,    15,    17,    62,    99,
      62,    76,    77,    41,    85,    70,    27,    28,    29,    63,
      64,    65,    66,    74,    17,    35,    36,    37,    38,    48,
      49,    50,    53,    55,    57,    60,    61,    62,    63,   100,
     101,   102,   103,   105,   106,   107,   108,   109,   111,   114,
      17,    77,    62,    84,    86,    87,    45,    46,    88,    89,
      90,    91,    92,    12,    15,    74,    23,   104,   104,   104,
     104,    99,     3,    10,    23,    62,    74,   116,   117,   118,
     119,    99,   116,    62,   116,    63,    12,    16,    25,   104,
      13,    15,    15,    15,    15,    30,    31,    32,    33,    34,
      43,    44,    62,    74,    78,    79,    80,    81,    13,    14,
      87,    62,    62,    89,    91,    15,    15,    15,   115,   116,
      49,   119,   119,   116,    12,    25,   104,    17,    18,    19,
      20,    21,    22,    51,     9,    10,    11,     4,     5,     6,
       7,     8,    54,    56,    16,    47,    62,   116,   116,   101,
      25,    82,    83,    84,    12,    15,    78,    62,    23,    93,
      93,    70,    70,    14,    24,    24,    62,   116,   117,   117,
     117,   117,   117,   117,   100,   118,   118,   118,   119,   119,
     119,   119,   119,   116,   100,   116,    62,    74,   112,   113,
      16,    26,    79,    49,    83,    13,    12,    15,    41,    84,
      94,    95,    96,    97,    13,    15,    15,   116,    26,    52,
      58,    59,   110,    13,    13,    49,   113,   116,    16,    26,
      79,    74,    84,    15,    24,    13,    13,    79,   100,   116,
     100,   100,   116,    47,    15,    95,    79,    79,    56,    79,
     100
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    69,    70,    71,    72,    72,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    75,    75,    76,
      76,    77,    78,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    80,    81,    82,    82,    83,    84,    84,    85,
      85,    86,    86,    87,    88,    88,    88,    88,    88,    89,
      90,    91,    92,    93,    93,    94,    94,    95,    95,    96,
      97,    98,    99,    99,   100,   100,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   102,   102,   102,   103,   103,
     103,   103,   103,   104,   104,   105,   106,   106,   107,   108,
     109,   110,   110,   111,   112,   112,   113,   113,   114,   115,
     115,   116,   116,   116,   116,   116,   116,   116,   117,   117,
     117,   117,   118,   118,   118,   118,   118,   118,   119,   119,
     119,   119,   119,   119,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     2,     4,     2,     0,     5,     4,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     2,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     6,     3,     2,     1,     4,     3,     1,     2,
       0,     2,     1,     4,     2,     2,     1,     1,     0,     4,
       5,     4,     3,     3,     0,     3,     1,     3,     3,     2,
       1,     3,     2,     0,     3,     1,     2,     2,     1,     1,
       2,     1,     1,     1,     2,     3,     6,     5,     2,     2,
       2,     2,     2,     3,     0,     3,     4,     6,     4,     4,
       8,     1,     1,     5,     2,     1,     3,     3,     2,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     1,     2,     1,
       3,     2,     2,     4,     3
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
#line 28 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newModuleNode(ProgramK);
					(yyval) -> child[0] = (yyvsp[-1]);
					(yyval) -> lineno = lineno;
					(yyval) -> attr.name = (char*)(yyvsp[-3]);
					theTree = (yyval);}
#line 1560 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 34 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newModuleNode(ProgramK);
					(yyval) -> child[0] = (yyvsp[-1]);
					(yyval) -> lineno = lineno;
					(yyval) -> attr.name =NULL;}
#line 1569 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 40 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newModuleNode(RoutingK);
					(yyval) -> child[0] = (yyvsp[-1]);
					(yyval) -> child[1] = (yyvsp[0]);
					(yyval) -> lineno = lineno;}
#line 1578 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 46 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newModuleNode(Routing_headK);
					(yyval) -> child[0] = (yyvsp[-3]);
					(yyval) -> child[1] = (yyvsp[-2]);
					(yyval) -> child[2] = (yyvsp[-1]);
					(yyval) -> child[3] = (yyvsp[0]);
					(yyval) -> lineno = lineno;}
#line 1589 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 53 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1595 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 54 "pascal.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1601 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 57 "pascal.y" /* yacc.c:1646  */
    {	TreePtr p = (yyvsp[-4]);
					if(p){
						while(p -> sibling) p = p -> sibling;
						p -> sibling = newDeclNode(ConstK);
						p -> sibling -> child[0] = (yyvsp[-1]);
						p -> sibling -> attr.name = (char*)(yyvsp[-3]);
						p -> sibling -> lineno = lineno;
					}
					(yyval) = (yyvsp[-4]);}
#line 1615 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 67 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newDeclNode(ConstK);
                    (yyval) -> child[0] = (yyvsp[-1]);
                    (yyval) -> attr.name = (char*)(yyvsp[-2]);
                    (yyval) -> lineno = lineno;
				}
#line 1625 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 73 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(IntK);
						(yyval) -> attr.intval = atoi((char*)(yyvsp[0]));
						(yyval) -> lineno = lineno;}
#line 1633 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 76 "pascal.y" /* yacc.c:1646  */
    {		(yyval) = newExprNode(RealK);
						(yyval) -> attr.realval = atof((char*)(yyvsp[0]));
						(yyval) -> lineno = lineno;}
#line 1641 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 79 "pascal.y" /* yacc.c:1646  */
    {		(yyval) = newExprNode(CharK);
						if(((char*)(yyvsp[0]))[0] == '#') (yyval) -> attr.charval = atoi((char*)(yyvsp[0]) + 1);
						else (yyval) -> attr.charval = ((char*)(yyvsp[0]))[1];
						(yyval) -> lineno = lineno;}
#line 1650 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 83 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(StringK);
						((char*)(yyvsp[0]))[strlen((char*)(yyvsp[0])) - 1] = 0;
						(yyval) -> attr.strval = (char*)(yyvsp[0])+1;
						(yyval) -> lineno = lineno;}
#line 1659 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 87 "pascal.y" /* yacc.c:1646  */
    {		(yyval) = newExprNode(BoolK);
						(yyval) -> attr.intval = 1;
						(yyval) -> lineno = lineno;}
#line 1667 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 90 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(BoolK);
						(yyval) -> attr.intval = 0;
						(yyval) -> lineno = lineno;}
#line 1675 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 93 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(IntK);
						(yyval) -> attr.intval = 32767;
						(yyval) -> lineno = lineno;}
#line 1683 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 97 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1689 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 98 "pascal.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1695 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 100 "pascal.y" /* yacc.c:1646  */
    {
												TreePtr p = (yyvsp[-1]);
                   								if (p){
                   									while(p -> sibling) p = p -> sibling;
                   									p -> sibling = (yyvsp[0]);
                   									(yyval) = (yyvsp[-1]);
                   								}
                   								else (yyval) = (yyvsp[0]);}
#line 1708 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 108 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1714 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 111 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newDeclNode(TypeK);
						(yyval) -> child[0] = (yyvsp[-1]);
						(yyval) -> attr.name = (char*)(yyvsp[-3]);
						(yyval) -> lineno = lineno;}
#line 1723 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 116 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1729 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 117 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1735 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 118 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1741 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 120 "pascal.y" /* yacc.c:1646  */
    {(yyval) = newDeclNode(SimpleK);(yyval) -> type = BooleanT;(yyval) -> lineno = lineno;}
#line 1747 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 121 "pascal.y" /* yacc.c:1646  */
    {(yyval) = newDeclNode(SimpleK);(yyval) -> type = CharacterT;(yyval) -> lineno = lineno;}
#line 1753 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 122 "pascal.y" /* yacc.c:1646  */
    {(yyval) = newDeclNode(SimpleK);(yyval) -> type = IntegerT;(yyval) -> lineno = lineno;}
#line 1759 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 123 "pascal.y" /* yacc.c:1646  */
    {(yyval) = newDeclNode(SimpleK);(yyval) -> type = RealT;(yyval) -> lineno = lineno;}
#line 1765 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 124 "pascal.y" /* yacc.c:1646  */
    {(yyval) = newDeclNode(SimpleK);(yyval) -> type = StringT;(yyval) -> lineno = lineno;}
#line 1771 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 125 "pascal.y" /* yacc.c:1646  */
    {(yyval) = newDeclNode(SimpleK);(yyval) -> type = IDT;(yyval) -> attr.name = (char*)(yyvsp[0]);(yyval) -> lineno = lineno;}
#line 1777 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 126 "pascal.y" /* yacc.c:1646  */
    {(yyval) = newDeclNode(SimpleK);(yyval) -> child[0] = (yyvsp[-3]);(yyval) -> child[1] = (yyvsp[0]);(yyval) -> attr.intval = 0;(yyval) -> lineno = lineno;}
#line 1783 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 129 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newDeclNode(ArrayK);
                     	(yyval)->child[0] = (yyvsp[-3]);
                     	(yyval)->child[1] = (yyvsp[0]);
                     	(yyval) -> lineno = lineno;}
#line 1792 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 134 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1798 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 137 "pascal.y" /* yacc.c:1646  */
    {	TreePtr p = (yyvsp[-1]);
                        if(p){ 
                        	while(p -> sibling)
                            p = p -> sibling;
                            p -> sibling = (yyvsp[0]);
                            (yyval) = (yyvsp[-1]); 
                        }
                        else (yyval) = (yyvsp[0]);
                   	}
#line 1812 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 146 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1818 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 149 "pascal.y" /* yacc.c:1646  */
    { 	(yyval) = newDeclNode(FieldK);
                	(yyval) -> child[0] = (yyvsp[-3]);
                	(yyval) -> child[1] = (yyvsp[-1]);
                	(yyval) -> lineno = lineno;}
#line 1827 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 155 "pascal.y" /* yacc.c:1646  */
    { 	TreePtr p = (yyvsp[-2]);
                   	if(p){
                   		while (p -> sibling) p = p -> sibling;
                     	p -> sibling = newExprNode(IdK);
                     	p -> sibling -> attr.name = (char*)(yyvsp[0]);
                     	p -> sibling -> lineno = lineno;
                     	(yyval) = (yyvsp[-2]); 
              		}
                   	else{
                    	(yyval) = newExprNode(IdK);
		     			(yyval) -> attr.name=(char*)(yyvsp[0]);
		     			(yyval) -> lineno = lineno;
                   	}}
#line 1845 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 168 "pascal.y" /* yacc.c:1646  */
    { (yyval) = newExprNode(IdK);
                  (yyval) -> attr.name = (char*)(yyvsp[0]);
                  (yyval) -> lineno = lineno;
                }
#line 1854 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 173 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1860 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 174 "pascal.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1866 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 177 "pascal.y" /* yacc.c:1646  */
    {	TreePtr p = (yyvsp[-1]);
                        if(p){
                        	while (p -> sibling)
                            p = p -> sibling;
                            p -> sibling = (yyvsp[0]);
                            (yyval) = (yyvsp[-1]); 
                        }
                        else (yyval) = (yyvsp[0]);}
#line 1879 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 185 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1885 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 188 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newDeclNode(VarK);
					(yyval) -> child[0] = (yyvsp[-3]);
					(yyval) -> child[1] = (yyvsp[-1]);
					(yyval) -> lineno = lineno;}
#line 1894 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 194 "pascal.y" /* yacc.c:1646  */
    {	TreePtr p = (yyvsp[-1]);
                        if(p){ 
                        	while(p -> sibling) p = p -> sibling;
                            p -> sibling = (yyvsp[0]);
                            (yyval) = (yyvsp[-1]); 
                        }
                        else (yyval) = (yyvsp[0]);}
#line 1906 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 202 "pascal.y" /* yacc.c:1646  */
    {	TreePtr p = (yyvsp[-1]);
                        if(p){ 
                        	while(p -> sibling) p = p -> sibling;
                            p -> sibling = (yyvsp[0]);
                            (yyval) = (yyvsp[-1]); 
                        }
                        else (yyval) = (yyvsp[0]);}
#line 1918 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 209 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1924 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 210 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1930 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 211 "pascal.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1936 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 214 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newModuleNode(FunctionK);
						(yyval) -> child[0] = (yyvsp[-3]);
						(yyval) -> child[1] = (yyvsp[-1]);
						(yyval) -> lineno = lineno;}
#line 1945 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 220 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newModuleNode(Function_headK);
						(yyval) -> attr.name = (char*)(yyvsp[-3]);
						(yyval) -> lineno = lineno;
						(yyval) -> child[0] = (yyvsp[-2]);
						(yyval) -> child[1] = (yyvsp[0]);}
#line 1955 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 227 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newModuleNode(ProcedureK);
						(yyval) -> child[0] = (yyvsp[-3]);
						(yyval) -> child[1] = (yyvsp[-1]);
						(yyval) -> lineno = lineno;}
#line 1964 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 233 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newModuleNode(Procedure_headK);
						(yyval) -> attr.name = (char*)(yyvsp[-1]);
						(yyval) -> lineno = lineno;
						(yyval) -> child[0] = (yyvsp[0]);}
#line 1973 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 238 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1979 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 239 "pascal.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1985 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 242 "pascal.y" /* yacc.c:1646  */
    {	TreePtr p = (yyvsp[-2]);
                        if(p){
                        	while(p -> sibling) p = p -> sibling;
                            p -> sibling = (yyvsp[-1]);
                            (yyval) = (yyvsp[-2]); 
                        }
                        else (yyval) = (yyvsp[-1]);}
#line 1997 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 249 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2003 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 252 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newDeclNode(ParaK);
						(yyval) -> child[0] = (yyvsp[-2]);
                    	(yyval) -> child[2] = (yyvsp[0]);
                   		(yyval) -> lineno = lineno;}
#line 2012 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 257 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newDeclNode(ParaK);
						(yyval) -> child[1] = (yyvsp[-2]);
                    	(yyval) -> child[2] = (yyvsp[0]);
                   		(yyval) -> lineno = lineno;}
#line 2021 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 262 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2027 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 264 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2033 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 266 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 2039 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 269 "pascal.y" /* yacc.c:1646  */
    {
					TreePtr p = (yyvsp[-1]);
                    if(p){
                        while(p -> sibling) p = p -> sibling;
                        p -> sibling = (yyvsp[0]);
                        (yyval) = (yyvsp[-1]); 
                    }
                    else (yyval) = (yyvsp[0]);}
#line 2052 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 277 "pascal.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 2058 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 280 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newStmtNode(LabelK);
				(yyval) -> child[0] = (yyvsp[0]);
				(yyval) -> attr.label = atoi((char*)(yyvsp[-2]));}
#line 2066 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 283 "pascal.y" /* yacc.c:1646  */
    {(yyval) = newStmtNode(LabelK);(yyval) -> child[1] = (yyvsp[0]);}
#line 2072 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 285 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 2078 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 286 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 2084 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 287 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2090 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 288 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2096 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 289 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 2102 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 290 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2108 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 291 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2114 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 292 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2120 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 293 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 2126 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 296 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newStmtNode(AssignK);
					(yyval) -> child[0] = (yyvsp[0]);
					(yyval) -> attr.name = (char*)(yyvsp[-2]);}
#line 2134 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 300 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newStmtNode(AssignK);
					(yyval) -> child[1] = (yyvsp[-3]);
					(yyval) -> child[2] = (yyvsp[0]);
					(yyval) -> attr.name = (char*)(yyvsp[-5]);}
#line 2143 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 305 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newStmtNode(AssignK);
					(yyval) -> child[3] = newExprNode(IdK);
					(yyval) -> child[3] -> attr.name = (char*)(yyvsp[-2]);
					(yyval) -> child[4] = (yyvsp[0]);
					(yyval) -> attr.name = (char*)(yyvsp[-4]);}
#line 2153 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 312 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newStmtNode(ProcK);
					(yyval) -> attr.name = (char*)(yyvsp[-1]);
					(yyval) -> child[0] = (yyvsp[0]);}
#line 2161 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 316 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newStmtNode(ProcK);
					(yyval) -> attr.name = (char*)malloc(5);
					strcpy((yyval) -> attr.name,"read");
					(yyval) -> child[0] = (yyvsp[0]);}
#line 2170 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 321 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newStmtNode(ProcK);
					(yyval) -> attr.name = (char*)malloc(7);
					strcpy((yyval) -> attr.name,"readln");
					(yyval) -> child[0] = (yyvsp[0]);}
#line 2179 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 326 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newStmtNode(ProcK);
					(yyval) -> attr.name = (char*)malloc(6);
					strcpy((yyval) -> attr.name,"write");
					(yyval) -> child[0] = (yyvsp[0]);}
#line 2188 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 331 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newStmtNode(ProcK);
					(yyval) -> attr.name = (char*)malloc(8);
					strcpy((yyval) -> attr.name,"writeln");
					(yyval) -> child[0] = (yyvsp[0]);}
#line 2197 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 336 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 2203 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 337 "pascal.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 2209 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 340 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newStmtNode(CompK);
						(yyval) -> child[0] = (yyvsp[-1]);}
#line 2216 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 344 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newStmtNode(IfK);
				(yyval) -> child[0] = (yyvsp[-2]);
				(yyval) -> child[1] = (yyvsp[0]);}
#line 2224 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 348 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newStmtNode(IfK);
				(yyval) -> child[0] = (yyvsp[-4]);
				(yyval) -> child[1] = (yyvsp[-2]);
				(yyval) -> child[2] = (yyvsp[0]);}
#line 2233 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 354 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newStmtNode(RepeatK);
					(yyval) -> child[0] = (yyvsp[-2]);
					(yyval) -> child[1] = (yyvsp[0]);}
#line 2241 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 359 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newStmtNode(WhileK);
					(yyval) -> child[0] = (yyvsp[-2]);
					(yyval) -> child[1] = (yyvsp[0]);}
#line 2249 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 364 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newStmtNode(ForK);
					(yyval) -> attr.name = (char*)(yyvsp[-6]);
					(yyval) -> child[0] = (yyvsp[-4]);
					(yyval) -> child[1] = (yyvsp[-3]);
					(yyval) -> child[2] = (yyvsp[-2]);
					(yyval) -> child[3] = (yyvsp[0]);}
#line 2260 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 371 "pascal.y" /* yacc.c:1646  */
    {(yyval) = newExprNode(DirK);(yyval) -> attr.direction = 1;}
#line 2266 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 372 "pascal.y" /* yacc.c:1646  */
    {(yyval) = newExprNode(DirK);(yyval) -> attr.direction = 0;}
#line 2272 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 375 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newStmtNode(CaseK);
					(yyval) -> child[0] = (yyvsp[-3]);
					(yyval) -> child[1] = (yyvsp[-1]);}
#line 2280 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 380 "pascal.y" /* yacc.c:1646  */
    {	TreePtr p = (yyvsp[-1]);
                   		if(p){
                   			while(p -> sibling) p = p -> sibling;
                   		  	p -> sibling = (yyvsp[0]);
                   		  	(yyval) = (yyvsp[-1]);
                   		}
                    	else (yyval) = (yyvsp[0]);}
#line 2292 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 387 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2298 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 390 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(Case_exprK);
					(yyval) -> child[0] = (yyvsp[-2]);
					(yyval) -> child[1] = (yyvsp[0]);}
#line 2306 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 394 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(Case_exprK);
					(yyval) -> attr.name = (char*)(yyvsp[-2]);
					(yyval) -> child[1] = (yyvsp[0]);}
#line 2314 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 399 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(GotoK);
					(yyval) -> attr.label = atoi((char*)(yyvsp[0]));}
#line 2321 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 403 "pascal.y" /* yacc.c:1646  */
    {	TreePtr p = (yyvsp[-2]);
                   		if(p){
                   			while(p -> sibling) p = p -> sibling;
                   		  	p -> sibling = (yyvsp[0]);
                   		  	(yyval) = (yyvsp[-2]);
                   		}
                    	else (yyval) = (yyvsp[0]);}
#line 2333 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 410 "pascal.y" /* yacc.c:1646  */
    {(yyval) =(yyvsp[0]);}
#line 2339 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 413 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(OpK);
					(yyval) -> child[0] = (yyvsp[-2]);
					(yyval) -> child[1] = (yyvsp[0]);
					(yyval) -> attr.op = GE;}
#line 2348 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 418 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(OpK);
					(yyval) -> child[0] = (yyvsp[-2]);
					(yyval) -> child[1] = (yyvsp[0]);
					(yyval) -> attr.op = GT;}
#line 2357 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 423 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(OpK);
					(yyval) -> child[0] = (yyvsp[-2]);
					(yyval) -> child[1] = (yyvsp[0]);
					(yyval) -> attr.op = LE;}
#line 2366 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 428 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(OpK);
					(yyval) -> child[0] = (yyvsp[-2]);
					(yyval) -> child[1] = (yyvsp[0]);
					(yyval) -> attr.op = LT;}
#line 2375 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 433 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(OpK);
					(yyval) -> child[0] = (yyvsp[-2]);
					(yyval) -> child[1] = (yyvsp[0]);
					(yyval) -> attr.op = EQUAL;}
#line 2384 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 438 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(OpK);
					(yyval) -> child[0] = (yyvsp[-2]);
					(yyval) -> child[1] = (yyvsp[0]);
					(yyval) -> attr.op = UNEQUAL;}
#line 2393 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 442 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2399 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 445 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(OpK);
				(yyval) -> child[0] = (yyvsp[-2]);
				(yyval) -> child[1] = (yyvsp[0]);
				(yyval) -> attr.op = PLUS;}
#line 2408 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 450 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(OpK);
				(yyval) -> child[0] = (yyvsp[-2]);
				(yyval) -> child[1] = (yyvsp[0]);
				(yyval) -> attr.op = MINUS;}
#line 2417 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 455 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(OpK);
				(yyval) -> child[0] = (yyvsp[-2]);
				(yyval) -> child[1] = (yyvsp[0]);
				(yyval) -> attr.op = OR;}
#line 2426 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 459 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2432 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 462 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(OpK);
				(yyval) -> child[0] = (yyvsp[-2]);
				(yyval) -> child[1] = (yyvsp[0]);
				(yyval) -> attr.op = MUL;}
#line 2441 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 467 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(OpK);
				(yyval) -> child[0] = (yyvsp[-2]);
				(yyval) -> child[1] = (yyvsp[0]);
				(yyval) -> attr.op = DIV;}
#line 2450 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 472 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(OpK);
				(yyval) -> child[0] = (yyvsp[-2]);
				(yyval) -> child[1] = (yyvsp[0]);
				(yyval) -> attr.op = MOD;}
#line 2459 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 477 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(OpK);
				(yyval) -> child[0] = (yyvsp[-2]);
				(yyval) -> child[1] = (yyvsp[0]);
				(yyval) -> attr.op = AND;}
#line 2468 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 482 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(OpK);
				(yyval) -> child[0] = (yyvsp[-2]);
				(yyval) -> child[1] = (yyvsp[0]);
				(yyval) -> attr.op = IDIV;}
#line 2477 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 486 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2483 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 489 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(FactorK);
				(yyval) -> attr.name = (char*)(yyvsp[-1]);
				(yyval) -> child[0] = (yyvsp[0]);}
#line 2491 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 493 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(FactorK);
				(yyval) -> child[1] = (yyvsp[0]);}
#line 2498 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 495 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 2504 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 497 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(OpK);
				(yyval) -> child[0] = (yyvsp[0]);
				(yyval) -> attr.op = NOT;}
#line 2512 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 501 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(OpK);
				(yyval) -> child[0] = (yyvsp[0]);
				(yyval) -> attr.op = MINUS;}
#line 2520 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 505 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(FactorK);
				(yyval) -> attr.name = (char*)(yyvsp[-3]);
				(yyval) -> child[2] = (yyvsp[-1]);}
#line 2528 "pascal.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 509 "pascal.y" /* yacc.c:1646  */
    {	(yyval) = newExprNode(FactorK);
				(yyval) -> attr.name = (char*)(yyvsp[-2]);
				(yyval) -> child[3] = newExprNode(IdK);
				(yyval) -> child[3] -> attr.name = (char*)(yyvsp[0]);}
#line 2537 "pascal.tab.c" /* yacc.c:1646  */
    break;


#line 2541 "pascal.tab.c" /* yacc.c:1646  */
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
#line 514 "pascal.y" /* yacc.c:1906  */

int yyerror(char * msg){
	printf("Syntax error at line %d: %s\n",lineno,msg);
	return 0;
}

TreePtr parse(void){
	yyin = source;
	yyparse();
	return theTree;
}
