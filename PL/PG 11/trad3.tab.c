/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "trad3.y"
                          // SECCION 1 Declaraciones de C-Yacc
#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para cadenas
#include <stdlib.h>           // declaraciones para exit ()

#define FF fflush(stdout);    // para forzar la impresion inmediata
char temp [2048] ;
char *genera_cadena (char *nombre);


#line 82 "trad3.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


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
    NUMERO = 258,
    IDENTIF = 259,
    INTEGER = 260,
    STRING = 261,
    PUTS = 262,
    LEQ = 263,
    GEQ = 264,
    EQ = 265,
    NEQ = 266,
    AND = 267,
    OR = 268,
    IF = 269,
    ELSE = 270,
    PRINT = 271,
    MAIN = 272,
    WHILE = 273,
    FOR = 274,
    SIGNO_UNARIO = 275
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "trad3.y"
                      // El tipo de la pila tiene caracter dual
      int valor ;             // - valor numerico de un NUMERO
      char *cadena ;          // - para pasar los nombres de IDENTIFES

#line 157 "trad3.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   276

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

#define YYUNDEFTOK  2
#define YYMAXUTOK   275


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,    25,    23,    31,    24,     2,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
      21,    20,    22,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    29,     2,    30,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    51,    51,    55,    57,    59,    65,    68,    70,    72,
      75,    76,    78,    81,    86,    88,    91,    93,    97,   101,
     103,   105,   107,   109,   111,   114,   118,   122,   124,   128,
     130,   131,   135,   137,   139,   141,   143,   147,   149,   151,
     154,   156,   158,   160,   162,   166,   170,   172,   175,   177,
     180,   181,   183,   185,   187,   191,   192,   193,   197,   199,
     201,   203,   205,   207,   209,   211,   215,   216,   218,   220,
     223,   227,   229,   231
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMERO", "IDENTIF", "INTEGER", "STRING",
  "PUTS", "LEQ", "GEQ", "EQ", "NEQ", "AND", "OR", "IF", "ELSE", "PRINT",
  "MAIN", "WHILE", "FOR", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "SIGNO_UNARIO", "';'", "'['", "']'", "','", "'('", "')'", "'{'", "'}'",
  "$accept", "axioma", "decl", "resdecl", "def", "fun", "inipar",
  "resinipar", "mainfun", "cuerpo", "decliter", "iter", "els", "sent",
  "setq", "ressetq", "impr", "callfun", "par", "respar", "expresion",
  "expresioncond", "cond", "termino", "vec", "operando", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      61,    60,    62,    43,    45,    42,    47,   275,    59,    91,
      93,    44,    40,    41,   123,   125
};
# endif

#define YYPACT_NINF (-146)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,    13,    34,    19,     9,  -146,     7,    15,  -146,    19,
    -146,    92,    97,   100,    89,   123,   107,  -146,    99,   120,
      17,     6,   147,   126,   130,   141,   143,   184,  -146,  -146,
     157,   158,   156,     6,     6,    99,   186,  -146,   156,    57,
     189,   162,   165,   177,   183,   185,   171,   156,  -146,   195,
     187,  -146,  -146,  -146,   212,   190,    64,    67,    67,   118,
     218,    64,   225,    64,   232,  -146,  -146,   156,    67,   157,
    -146,  -146,   209,    67,    67,    64,   210,   124,  -146,  -146,
    -146,  -146,    67,   188,   206,   142,    67,    67,   236,   213,
     211,   168,   214,   215,   216,   238,   217,  -146,   204,  -146,
    -146,  -146,   175,   219,    67,    67,    67,    67,    64,    64,
      64,    64,    64,    64,    64,    64,  -146,   175,  -146,  -146,
      67,  -146,   179,   196,    54,  -146,   220,   221,    22,   222,
     223,    64,  -146,  -146,  -146,    47,    47,  -146,  -146,  -146,
    -146,   133,   133,   104,   174,  -146,  -146,   142,   226,   229,
      64,  -146,  -146,    37,    65,   227,   228,  -146,    71,   156,
      67,   231,  -146,  -146,  -146,    98,    49,   230,    22,   234,
      22,   233,   210,   246,  -146,   245,   156,  -146,  -146,  -146,
     156,   243,   237,   235,  -146,  -146,    67,   239,    37,   210,
     156,   240,   241,  -146,   156,  -146
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     0,    12,     9,     1,     0,     0,     2,    12,
      10,     0,     0,     0,     0,    15,     0,    11,     9,     0,
       9,     6,     0,     0,     0,     0,     0,     0,     8,     3,
      17,     0,    24,     6,     6,     9,     0,    14,    24,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    30,     0,
       0,     4,     5,     7,     0,     0,     0,     0,    47,    39,
       0,     0,     0,     0,     0,    18,    19,    24,     0,    17,
      13,    72,    71,     0,     0,     0,    55,     0,    56,    50,
      69,    66,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,    56,     0,    56,     0,     0,    23,     0,    16,
      67,    68,    55,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,    70,    45,
       0,    46,    39,     0,    39,    32,     0,     0,     0,     0,
       0,     0,    36,    73,    57,    51,    52,    53,    54,    59,
      58,    64,    65,    62,    63,    61,    60,    49,     0,     0,
       0,    38,    31,     0,    71,    41,     0,    44,    40,    24,
       0,    56,    48,    33,    35,    39,     0,     0,     0,     0,
       0,     0,    25,     0,    37,    28,    24,    43,    29,    42,
      24,     0,     0,     0,    21,    20,     0,     0,     0,    26,
      24,     0,     0,    27,    24,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,   -12,    -2,   242,  -146,  -146,   197,  -146,   -37,
    -146,  -146,  -146,  -145,  -146,  -110,   -67,  -104,  -146,   106,
     -55,   -52,   -56,    50,   -32,  -146
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    14,     8,     9,    23,    37,    10,    46,
      96,   182,   176,    47,    48,    89,   156,    49,    84,   121,
      76,    91,    78,    79,    80,    81
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,    55,    83,    85,    77,    92,    50,    94,   167,    29,
      66,     1,   148,    98,   151,    50,    25,     4,    28,   103,
     102,    51,    52,     6,   157,    71,   154,   117,   155,    11,
      97,   122,   123,    53,     5,    50,     7,    27,    12,    15,
      13,   166,    40,   191,    41,    73,    74,    16,    13,   135,
     136,   137,   138,    43,    75,   174,   139,   140,   141,   142,
     143,   144,   145,   146,   157,   147,   157,    71,    72,    56,
      71,    72,   106,   107,   150,   161,   158,    56,    57,   108,
     109,   110,   111,   112,   113,    88,    57,    73,    74,    58,
      73,    74,   114,   115,    57,    18,    75,    58,   165,    82,
      19,   177,   170,   179,    20,   172,   108,   109,   110,   111,
     112,   113,   108,   109,   110,   111,   158,    21,   158,   114,
     115,    50,   171,   100,   101,   114,   115,    50,    22,    88,
      13,   189,   108,   109,   110,   111,   112,   113,    86,   184,
      24,   108,   109,   185,    50,   114,   115,    87,    50,    88,
      26,    30,   116,   192,   114,   115,    50,   195,    50,    31,
      39,    40,    50,    41,    32,   104,   105,   106,   107,    33,
      42,    34,    43,   120,    44,    45,   108,   109,   110,   111,
     112,   113,   108,   109,   110,   111,   112,    35,    36,   114,
     115,    54,    38,    59,    60,   114,   115,    61,   104,   105,
     106,   107,   104,   105,   106,   107,    65,    68,   133,    62,
      88,   104,   105,   106,   107,    63,    69,    64,   118,   104,
     105,   106,   107,    67,    90,    70,   149,   104,   105,   106,
     107,    93,   132,   104,   105,   106,   107,    95,    57,   119,
     124,   125,   130,   160,   126,   131,   128,   127,   152,   129,
     181,    17,   134,   162,   163,   153,   159,   164,   168,   173,
     183,   169,   178,   186,     0,   175,    99,     0,   180,   188,
     187,     0,     0,   190,     0,   193,   194
};

static const yytype_int16 yycheck[] =
{
      32,    38,    57,    58,    56,    61,    38,    63,   153,    21,
      47,     5,   122,    68,   124,    47,    18,     4,    20,    75,
      75,    33,    34,     4,   128,     3,     4,    82,     6,    20,
      67,    86,    87,    35,     0,    67,    17,    20,    29,    32,
      31,     4,     5,   188,     7,    23,    24,    32,    31,   104,
     105,   106,   107,    16,    32,   165,   108,   109,   110,   111,
     112,   113,   114,   115,   168,   120,   170,     3,     4,    20,
       3,     4,    25,    26,    20,   131,   128,    20,    29,     8,
       9,    10,    11,    12,    13,    31,    29,    23,    24,    32,
      23,    24,    21,    22,    29,     3,    32,    32,   150,    32,
       3,   168,    31,   170,     4,   160,     8,     9,    10,    11,
      12,    13,     8,     9,    10,    11,   168,    28,   170,    21,
      22,   153,   159,    73,    74,    21,    22,   159,     5,    31,
      31,   186,     8,     9,    10,    11,    12,    13,    20,   176,
      33,     8,     9,   180,   176,    21,    22,    29,   180,    31,
      30,     4,    28,   190,    21,    22,   188,   194,   190,    33,
       4,     5,   194,     7,    34,    23,    24,    25,    26,    28,
      14,    28,    16,    31,    18,    19,     8,     9,    10,    11,
      12,    13,     8,     9,    10,    11,    12,     3,    31,    21,
      22,     5,    34,     4,    32,    21,    22,    32,    23,    24,
      25,    26,    23,    24,    25,    26,    35,    20,    33,    32,
      31,    23,    24,    25,    26,    32,     4,    32,    30,    23,
      24,    25,    26,    28,     6,    35,    30,    23,    24,    25,
      26,     6,    28,    23,    24,    25,    26,     5,    29,    33,
       4,    28,     4,    20,    33,    28,    31,    33,    28,    33,
       4,     9,    33,   147,    28,    34,    34,    28,    31,    28,
      15,    33,    28,    20,    -1,    35,    69,    -1,    35,    34,
      33,    -1,    -1,    34,    -1,    35,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    37,    38,     4,     0,     4,    17,    40,    41,
      44,    20,    29,    31,    39,    32,    32,    40,     3,     3,
       4,    28,     5,    42,    33,    39,    30,    20,    39,    38,
       4,    33,    34,    28,    28,     3,    31,    43,    34,     4,
       5,     7,    14,    16,    18,    19,    45,    49,    50,    53,
      60,    38,    38,    39,     5,    45,    20,    29,    32,     4,
      32,    32,    32,    32,    32,    35,    45,    28,    20,     4,
      35,     3,     4,    23,    24,    32,    56,    57,    58,    59,
      60,    61,    32,    56,    54,    56,    20,    29,    31,    51,
       6,    57,    58,     6,    58,     5,    46,    45,    56,    43,
      59,    59,    56,    58,    23,    24,    25,    26,     8,     9,
      10,    11,    12,    13,    21,    22,    28,    56,    30,    33,
      31,    55,    56,    56,     4,    28,    33,    33,    31,    33,
       4,    28,    28,    33,    33,    56,    56,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    56,    51,    30,
      20,    51,    28,    34,     4,     6,    52,    53,    57,    34,
      20,    58,    55,    28,    28,    57,     4,    49,    31,    33,
      31,    45,    56,    28,    51,    35,    48,    52,    28,    52,
      35,     4,    47,    15,    45,    45,    20,    33,    34,    56,
      34,    49,    45,    35,    35,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    38,    38,    39,    39,    39,
      40,    40,    40,    41,    42,    42,    43,    43,    44,    45,
      45,    45,    45,    45,    45,    46,    47,    48,    48,    49,
      49,    49,    50,    50,    50,    50,    50,    51,    51,    51,
      52,    52,    52,    52,    52,    53,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    57,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    59,    59,
      60,    61,    61,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     5,     7,     7,     0,     5,     3,     0,
       1,     2,     0,     7,     3,     0,     4,     0,     6,     2,
       8,     8,    12,     3,     0,     4,     3,     5,     1,     7,
       1,     5,     4,     6,     4,     6,     4,     5,     3,     0,
       1,     1,     3,     3,     1,     4,     2,     0,     3,     0,
       1,     3,     3,     3,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     2,     2,     1,
       4,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 51 "trad3.y"
                              { sprintf(temp, "%s%s", (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                printf("%s", genera_cadena(temp)); }
#line 1467 "trad3.tab.c"
    break;

  case 3:
#line 55 "trad3.y"
                                                                  { sprintf(temp, "(setq %s 0)\n%s%s", (yyvsp[-3].cadena), (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                                    (yyval.cadena) = genera_cadena(temp); }
#line 1474 "trad3.tab.c"
    break;

  case 4:
#line 57 "trad3.y"
                                                                      { sprintf(temp, "(setq %s %d)\n%s%s", (yyvsp[-5].cadena), (yyvsp[-3].valor), (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                                    (yyval.cadena) = genera_cadena(temp); }
#line 1481 "trad3.tab.c"
    break;

  case 5:
#line 59 "trad3.y"
                                                                    { sprintf(temp, "(setq %s (make-array %d))\n%s", (yyvsp[-5].cadena), (yyvsp[-3].valor), (yyvsp[0].cadena));
                                                                    (yyval.cadena) = genera_cadena(temp); }
#line 1488 "trad3.tab.c"
    break;

  case 6:
#line 65 "trad3.y"
                                                                      { ; }
#line 1494 "trad3.tab.c"
    break;

  case 7:
#line 68 "trad3.y"
                                                      { sprintf(temp, "(setq %s %d)\n%s", (yyvsp[-3].cadena), (yyvsp[-1].valor), (yyvsp[0].cadena));
                                                      (yyval.cadena) = genera_cadena(temp); }
#line 1501 "trad3.tab.c"
    break;

  case 8:
#line 70 "trad3.y"
                                                    { sprintf(temp, "(setq %s 0)\n%s", (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                                      (yyval.cadena) = genera_cadena(temp); }
#line 1508 "trad3.tab.c"
    break;

  case 9:
#line 72 "trad3.y"
                                                        { (yyval.cadena) = genera_cadena(""); }
#line 1514 "trad3.tab.c"
    break;

  case 10:
#line 75 "trad3.y"
                                  { (yyval.cadena) = genera_cadena((yyvsp[0].cadena)); }
#line 1520 "trad3.tab.c"
    break;

  case 11:
#line 76 "trad3.y"
                                    { sprintf(temp, "%s%s", (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                    (yyval.cadena) = genera_cadena(temp); }
#line 1527 "trad3.tab.c"
    break;

  case 12:
#line 78 "trad3.y"
                                      { (yyval.cadena) = genera_cadena(""); }
#line 1533 "trad3.tab.c"
    break;

  case 13:
#line 81 "trad3.y"
                                                              { sprintf(temp, "(defun %s (%s)\n%s)\n", (yyvsp[-6].cadena), (yyvsp[-4].cadena), (yyvsp[-1].cadena));
                                                              (yyval.cadena) = genera_cadena(temp); }
#line 1540 "trad3.tab.c"
    break;

  case 14:
#line 86 "trad3.y"
                                                      { sprintf(temp, "%s%s", (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena(temp); }
#line 1547 "trad3.tab.c"
    break;

  case 15:
#line 88 "trad3.y"
                                                { (yyval.cadena) = genera_cadena(""); }
#line 1553 "trad3.tab.c"
    break;

  case 16:
#line 91 "trad3.y"
                                                      { sprintf(temp, " %s%s", (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                                    (yyval.cadena) = genera_cadena(temp); }
#line 1560 "trad3.tab.c"
    break;

  case 17:
#line 93 "trad3.y"
                                                  { (yyval.cadena) = genera_cadena(""); }
#line 1566 "trad3.tab.c"
    break;

  case 18:
#line 97 "trad3.y"
                                                      { sprintf(temp, "(defun %s ()\n%s)\n", (yyvsp[-5].cadena), (yyvsp[-1].cadena));
                                                      (yyval.cadena) = genera_cadena(temp); }
#line 1573 "trad3.tab.c"
    break;

  case 19:
#line 101 "trad3.y"
                                                                                  { sprintf(temp, "%s%s", (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                                                                    (yyval.cadena) = genera_cadena(temp); }
#line 1580 "trad3.tab.c"
    break;

  case 20:
#line 103 "trad3.y"
                                                                                  { sprintf(temp, "\t(loop %s %s do\n%s\t)\n%s", (yyvsp[-7].cadena), (yyvsp[-5].cadena), (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                                                    (yyval.cadena) = genera_cadena(temp); }
#line 1587 "trad3.tab.c"
    break;

  case 21:
#line 105 "trad3.y"
                                                                                  { sprintf(temp, "\t(if %s\n\t%s%s%s", (yyvsp[-5].cadena), (yyvsp[-2].cadena), (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                                                                    (yyval.cadena) = genera_cadena(temp); }
#line 1594 "trad3.tab.c"
    break;

  case 22:
#line 107 "trad3.y"
                                                                                      { sprintf(temp, "%s\t(loop while %s do\n%s%s\t)\n%s", (yyvsp[-9].cadena), (yyvsp[-7].cadena), (yyvsp[-2].cadena), (yyvsp[-5].cadena), (yyvsp[0].cadena));
                                                                                    (yyval.cadena) = genera_cadena(temp); }
#line 1601 "trad3.tab.c"
    break;

  case 23:
#line 109 "trad3.y"
                                                                                  { sprintf(temp, "\t%s\n%s", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                                                    (yyval.cadena) = genera_cadena(temp); }
#line 1608 "trad3.tab.c"
    break;

  case 24:
#line 111 "trad3.y"
                                                                                      { (yyval.cadena) = genera_cadena(""); }
#line 1614 "trad3.tab.c"
    break;

  case 25:
#line 114 "trad3.y"
                                                      { sprintf(temp, "\t(setq %s %s)\n", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                      (yyval.cadena) = genera_cadena(temp); }
#line 1621 "trad3.tab.c"
    break;

  case 26:
#line 118 "trad3.y"
                                              { sprintf(temp, "\t(setq %s %s)\n", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                              (yyval.cadena) = genera_cadena(temp); }
#line 1628 "trad3.tab.c"
    break;

  case 27:
#line 122 "trad3.y"
                                              { sprintf(temp, "\t%s\t)\n", (yyvsp[-1].cadena));
                                              (yyval.cadena) = genera_cadena(temp); }
#line 1635 "trad3.tab.c"
    break;

  case 28:
#line 124 "trad3.y"
                                            { sprintf(temp, "\t)\n");
                                              (yyval.cadena) = genera_cadena(temp); }
#line 1642 "trad3.tab.c"
    break;

  case 29:
#line 128 "trad3.y"
                                                              { if(strcmp(temp, " ") != 0) sprintf(temp, "\t%s\n", genera_cadena(temp));
                                                          (yyval.cadena) = genera_cadena(temp); }
#line 1649 "trad3.tab.c"
    break;

  case 30:
#line 130 "trad3.y"
                                                        { (yyval.cadena) = genera_cadena(temp); }
#line 1655 "trad3.tab.c"
    break;

  case 31:
#line 131 "trad3.y"
                                                        { sprintf(temp, "\t(print \"%s\")\n", (yyvsp[-2].cadena));
                                                          (yyval.cadena) = genera_cadena(temp); }
#line 1662 "trad3.tab.c"
    break;

  case 32:
#line 135 "trad3.y"
                                                                { sprintf(temp, "\t(setq %s 0)\n%s", (yyvsp[-2].cadena), (yyvsp[-1].cadena));
                                                                  (yyval.cadena) = genera_cadena(temp); }
#line 1669 "trad3.tab.c"
    break;

  case 33:
#line 137 "trad3.y"
                                                                      { sprintf(temp, "\t(setq %s %s)\n%s", (yyvsp[-4].cadena), (yyvsp[-2].cadena), (yyvsp[-1].cadena));
                                                                  (yyval.cadena) = genera_cadena(temp); }
#line 1676 "trad3.tab.c"
    break;

  case 34:
#line 139 "trad3.y"
                                                                    { sprintf(temp, "\t(setq %s %s)\n", (yyvsp[-3].cadena), (yyvsp[-1].cadena));
                                                                  (yyval.cadena) = genera_cadena(temp); }
#line 1683 "trad3.tab.c"
    break;

  case 35:
#line 141 "trad3.y"
                                                                  { sprintf(temp, "\t(setq %s (make-array %s))\n", (yyvsp[-4].cadena), (yyvsp[-2].cadena));
                                                                  (yyval.cadena) = genera_cadena(temp); }
#line 1690 "trad3.tab.c"
    break;

  case 36:
#line 143 "trad3.y"
                                                                  { sprintf(temp, "\t(setf %s %s)\n", (yyvsp[-3].cadena), (yyvsp[-1].cadena));
                                                                  (yyval.cadena) = genera_cadena(temp); }
#line 1697 "trad3.tab.c"
    break;

  case 37:
#line 147 "trad3.y"
                                                              { sprintf(temp, "\t(setq %s %s)\n%s", (yyvsp[-3].cadena), (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                                              (yyval.cadena) = genera_cadena(temp); }
#line 1704 "trad3.tab.c"
    break;

  case 38:
#line 149 "trad3.y"
                                                            { sprintf(temp, "\t(setq %s 0)\n%s", (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                                              (yyval.cadena) = genera_cadena(temp); }
#line 1711 "trad3.tab.c"
    break;

  case 39:
#line 151 "trad3.y"
                                                                { (yyval.cadena) = genera_cadena(""); }
#line 1717 "trad3.tab.c"
    break;

  case 40:
#line 154 "trad3.y"
                                                { sprintf(temp, "(print %s)", (yyvsp[0].cadena));
                                              (yyval.cadena) = genera_cadena(temp); }
#line 1724 "trad3.tab.c"
    break;

  case 41:
#line 156 "trad3.y"
                                              { sprintf(temp, " ");
                                              (yyval.cadena) = genera_cadena(temp); }
#line 1731 "trad3.tab.c"
    break;

  case 42:
#line 158 "trad3.y"
                                              { sprintf(temp, "(print %s) %s", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                              (yyval.cadena) = genera_cadena(temp); }
#line 1738 "trad3.tab.c"
    break;

  case 43:
#line 160 "trad3.y"
                                            { sprintf(temp, "%s", (yyvsp[0].cadena));
                                              (yyval.cadena) = genera_cadena(temp); }
#line 1745 "trad3.tab.c"
    break;

  case 44:
#line 162 "trad3.y"
                                            { sprintf(temp, "(print %s)", (yyvsp[0].cadena));
                                              (yyval.cadena) = genera_cadena(temp); }
#line 1752 "trad3.tab.c"
    break;

  case 45:
#line 166 "trad3.y"
                                              { sprintf(temp, "(%s%s)", (yyvsp[-3].cadena), (yyvsp[-1].cadena));
                                          (yyval.cadena) = genera_cadena(temp); }
#line 1759 "trad3.tab.c"
    break;

  case 46:
#line 170 "trad3.y"
                                      { sprintf(temp, " %s%s", (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                        (yyval.cadena) = genera_cadena(temp); }
#line 1766 "trad3.tab.c"
    break;

  case 47:
#line 172 "trad3.y"
                                          { (yyval.cadena) = genera_cadena(""); }
#line 1772 "trad3.tab.c"
    break;

  case 48:
#line 175 "trad3.y"
                                              { sprintf(temp, " %s%s", (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                            (yyval.cadena) = genera_cadena(temp); }
#line 1779 "trad3.tab.c"
    break;

  case 49:
#line 177 "trad3.y"
                                              { (yyval.cadena) = genera_cadena(""); }
#line 1785 "trad3.tab.c"
    break;

  case 50:
#line 180 "trad3.y"
                                                                        { (yyval.cadena) = (yyvsp[0].cadena); }
#line 1791 "trad3.tab.c"
    break;

  case 51:
#line 181 "trad3.y"
                                              { sprintf(temp, "(+ %s %s)", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                (yyval.cadena) = genera_cadena(temp); }
#line 1798 "trad3.tab.c"
    break;

  case 52:
#line 183 "trad3.y"
                                              { sprintf(temp, "(- %s %s)", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                (yyval.cadena) = genera_cadena(temp); }
#line 1805 "trad3.tab.c"
    break;

  case 53:
#line 185 "trad3.y"
                                              { sprintf(temp, "(* %s %s)", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                (yyval.cadena) = genera_cadena(temp); }
#line 1812 "trad3.tab.c"
    break;

  case 54:
#line 187 "trad3.y"
                                                        { sprintf(temp, "(/ %s %s)", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                (yyval.cadena) = genera_cadena(temp); }
#line 1819 "trad3.tab.c"
    break;

  case 55:
#line 191 "trad3.y"
                                    { (yyval.cadena) = genera_cadena(temp); }
#line 1825 "trad3.tab.c"
    break;

  case 56:
#line 192 "trad3.y"
                                    { (yyval.cadena) = genera_cadena(temp); }
#line 1831 "trad3.tab.c"
    break;

  case 57:
#line 193 "trad3.y"
                                      { sprintf(temp, "(%s)", (yyvsp[-1].cadena));
                                      (yyval.cadena) = genera_cadena(temp); }
#line 1838 "trad3.tab.c"
    break;

  case 58:
#line 197 "trad3.y"
                                                     { sprintf(temp, "(>= %s %s)", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                        (yyval.cadena) = genera_cadena(temp); }
#line 1845 "trad3.tab.c"
    break;

  case 59:
#line 199 "trad3.y"
                                                      { sprintf(temp, "(<= %s %s)", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                        (yyval.cadena) = genera_cadena(temp); }
#line 1852 "trad3.tab.c"
    break;

  case 60:
#line 201 "trad3.y"
                                                        { sprintf(temp, "(> %s %s)", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                        (yyval.cadena) = genera_cadena(temp); }
#line 1859 "trad3.tab.c"
    break;

  case 61:
#line 203 "trad3.y"
                                                      { sprintf(temp, "(< %s %s)", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                        (yyval.cadena) = genera_cadena(temp); }
#line 1866 "trad3.tab.c"
    break;

  case 62:
#line 205 "trad3.y"
                                                        { sprintf(temp, "(and %s %s)", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                        (yyval.cadena) = genera_cadena(temp); }
#line 1873 "trad3.tab.c"
    break;

  case 63:
#line 207 "trad3.y"
                                                        { sprintf(temp, "(or %s %s)", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                        (yyval.cadena) = genera_cadena(temp); }
#line 1880 "trad3.tab.c"
    break;

  case 64:
#line 209 "trad3.y"
                                                        { sprintf(temp, "(= %s %s)", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                        (yyval.cadena) = genera_cadena(temp); }
#line 1887 "trad3.tab.c"
    break;

  case 65:
#line 211 "trad3.y"
                                                      { sprintf(temp, "(/= %s %s)", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                        (yyval.cadena) = genera_cadena(temp); }
#line 1894 "trad3.tab.c"
    break;

  case 66:
#line 215 "trad3.y"
                                                                      { (yyval.cadena) = (yyvsp[0].cadena); }
#line 1900 "trad3.tab.c"
    break;

  case 67:
#line 216 "trad3.y"
                                                      { sprintf(temp, "(+ %s)", (yyvsp[0].cadena));
                                                      (yyval.cadena) = genera_cadena(temp); }
#line 1907 "trad3.tab.c"
    break;

  case 68:
#line 218 "trad3.y"
                                                        { sprintf(temp, "(- %s)", (yyvsp[0].cadena));
                                                      (yyval.cadena) = genera_cadena(temp); }
#line 1914 "trad3.tab.c"
    break;

  case 69:
#line 220 "trad3.y"
                                                          { (yyval.cadena) = genera_cadena((yyvsp[0].cadena)); }
#line 1920 "trad3.tab.c"
    break;

  case 70:
#line 223 "trad3.y"
                                                      { sprintf(temp, "(aref %s %s)", (yyvsp[-3].cadena), (yyvsp[-1].cadena));
                                                  (yyval.cadena) = genera_cadena(temp); }
#line 1927 "trad3.tab.c"
    break;

  case 71:
#line 227 "trad3.y"
                                                { sprintf(temp,"%s", (yyvsp[0].cadena));
                                          (yyval.cadena) = genera_cadena(temp); }
#line 1934 "trad3.tab.c"
    break;

  case 72:
#line 229 "trad3.y"
                                        { sprintf(temp,"%d", (yyvsp[0].valor));
                                          (yyval.cadena) = genera_cadena(temp); }
#line 1941 "trad3.tab.c"
    break;

  case 73:
#line 231 "trad3.y"
                                              { sprintf(temp, "(%s)", (yyvsp[-1].cadena));
                                          (yyval.cadena) = genera_cadena(temp); }
#line 1948 "trad3.tab.c"
    break;


#line 1952 "trad3.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 235 "trad3.y"

                            // SECCION 4    Codigo en C
int n_linea = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_linea) ;
    printf ("\n") ;	// bye
}

char *mi_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
         fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
         fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
         exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}


/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_pal_reservadas { // para las palabras reservadas de C
    char *nombre ;
    int token ;
} t_reservada ;

t_reservada pal_reservadas [] = { // define las palabras reservadas y los
    "main",        MAIN,           // y los token asociados
    "int",         INTEGER,
    "while",       WHILE,
    "puts",        PUTS,
    "if",          IF,
    "else",        ELSE,
    "printf",      PRINT,
    ">=",          GEQ,
    "<=",          LEQ,
    "&&",          AND,
    "||",          OR,
    "==",          EQ,
    "!=",          NEQ,
    "for",         FOR,
    NULL,          0               // para marcar el fin de la tabla
} ;

t_reservada *busca_pal_reservada (char *nombre_simbolo)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_reservada *sim ;

    i = 0 ;
    sim = pal_reservadas ;
    while (sim [i].nombre != NULL) {
           if (strcmp (sim [i].nombre, nombre_simbolo) == 0) {
                                         // strcmp(a, b) devuelve == 0 si a==b
                 return &(sim [i]) ;
             }
           i++ ;
    }

    return NULL ;
}


/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/

char *genera_cadena (char *nombre)     // copia el argumento a un
{                                      // string en memoria dinamica
      char *p ;
      int l ;

      l = strlen (nombre)+1 ;
      p = (char *) mi_malloc (l) ;
      strcpy (p, nombre) ;

      return p ;
}


int yylex ()
{
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=>|%&+-/*" ;
    char cadena [256] ;
    t_reservada *simbolo ;

    do {
    	c = getchar () ;

		if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
			do {		//	OJO que puede funcionar mal si una linea contiene #
			 c = getchar () ;
			} while (c != '\n') ;
		}

		if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
			cc = getchar () ;
			if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
				ungetc (cc, stdin) ;
		 } else {
		     c = getchar () ;	// ...
		     if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
		          do {		// Se trata de codigo inline (Codigo embebido en C)
		              c = getchar () ;
		              putchar (c) ;
		          } while (c != '\n') ;
		     } else {		// ==> comentario, ignorar la linea
		          while (c != '\n') {
		              c = getchar () ;
		          }
		     }
		 }
		}

		if (c == '\n')
		 n_linea++ ;

    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
         i = 0 ;
         do {
             c = getchar () ;
             cadena [i++] = c ;
         } while (c != '\"' && i < 255) ;
         if (i == 256) {
              printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_linea) ;
         }		 	// habria que leer hasta el siguiente " , pero, y si falta?
         cadena [--i] = '\0' ;
         yylval.cadena = genera_cadena (cadena) ;
         return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
         ungetc (c, stdin) ;
         scanf ("%d", &yylval.valor) ;
//         printf ("\nDEV: NUMERO %d\n", yylval.valor) ;        // PARA DEPURAR
         return NUMERO ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
         i = 0 ;
         while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
                 (c >= '0' && c <= '9') || c == '_') && i < 255) {
             cadena [i++] = tolower (c) ;
             c = getchar () ;
         }
         cadena [i] = '\0' ;
         ungetc (c, stdin) ;

         yylval.cadena = genera_cadena (cadena) ;
         simbolo = busca_pal_reservada (yylval.cadena) ;
         if (simbolo == NULL) {    // no es palabra reservada -> identificador
//               printf ("\nDEV: IDENTIF %s\n", yylval.cadena) ;    // PARA DEPURAR
               return (IDENTIF) ;
         } else {
//               printf ("\nDEV: OTRO %s\n", yylval.cadena) ;       // PARA DEPURAR
               return (simbolo->token) ;
         }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
         cc = getchar () ;
         sprintf (cadena, "%c%c", (char) c, (char) cc) ;
         simbolo = busca_pal_reservada (cadena) ;
         if (simbolo == NULL) {
              ungetc (cc, stdin) ;
              yylval.cadena = NULL ;
              return (c) ;
         } else {
              yylval.cadena = genera_cadena (cadena) ; // aunque no se use
              return (simbolo->token) ;
         }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
         return (0) ;
    }

    return c ;
}


int main ()
{
    yyparse () ;
}
