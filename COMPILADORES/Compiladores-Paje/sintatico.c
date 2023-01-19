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
#line 11 "sintatico.y"

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    #include "estruturas.h"
    #include "lexico.c"
    #include "pilha.c"
    #include "tabela.c"

    #define DEBUG(x) x
    //int yylex();
    //int msg (char *);
    int yyerror (char *);
    void empilha(int, char);
    int desempilha();
    void mostra_pilha(char *);
    void insere_simbolo (struct elem_tab_simbolos);
    int busca_simbolo(char *);
    void mostra_tabela();
    extern char atomo [];
    int contaVar = 0;
    int rotulo = 0;
    int tipo;
    int mecanismo = 10;
    char escopo = 'G';
    extern FILE *yyin;
    extern FILE *yyout;
    extern char atomo[80];
    int npar = 0;
    int avar = 0;
    int gvar;
    int qtdtabela = 0;
    

#line 106 "sintatico.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SINTATICO_H_INCLUDED
# define YY_YY_SINTATICO_H_INCLUDED
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
    T_PROGRAMA = 258,
    T_INICIO = 259,
    T_FIM = 260,
    T_IDENTIF = 261,
    T_LEIA = 262,
    T_ESCREVA = 263,
    T_ENQTO = 264,
    T_FACA = 265,
    T_FIMENQTO = 266,
    T_SE = 267,
    T_ENTAO = 268,
    T_SENAO = 269,
    T_FIMSE = 270,
    T_ATRIB = 271,
    T_VEZES = 272,
    T_DIV = 273,
    T_MAIS = 274,
    T_MENOS = 275,
    T_MAIOR = 276,
    T_MENOR = 277,
    T_IGUAL = 278,
    T_E = 279,
    T_OU = 280,
    T_NAO = 281,
    T_V = 282,
    T_F = 283,
    T_NUMERO = 284,
    T_ABRE = 285,
    T_FECHA = 286,
    T_INTEIRO = 287,
    T_LOGICO = 288,
    T_REPITA = 289,
    T_ATE = 290,
    T_FIMREPITA = 291,
    T_FUNC = 292,
    T_FIMFUNC = 293,
    T_REF = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SINTATICO_H_INCLUDED  */



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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  117

#define YYUNDEFTOK  2
#define YYMAXUTOK   294


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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    97,    97,    99,    96,   107,   109,   110,   110,   118,
     118,   121,   137,   120,   152,   152,   154,   168,   168,   170,
     170,   176,   177,   179,   179,   181,   195,   209,   209,   211,
     211,   211,   211,   211,   213,   213,   215,   223,   238,   246,
     250,   245,   265,   268,   278,   267,   291,   290,   314,   334,
     354,   374,   394,   414,   434,   454,   474,   494,   496,   496,
     498,   498,   500,   516,   536,   533,   546,   552,   558,   564,
     573
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_PROGRAMA", "T_INICIO", "T_FIM",
  "T_IDENTIF", "T_LEIA", "T_ESCREVA", "T_ENQTO", "T_FACA", "T_FIMENQTO",
  "T_SE", "T_ENTAO", "T_SENAO", "T_FIMSE", "T_ATRIB", "T_VEZES", "T_DIV",
  "T_MAIS", "T_MENOS", "T_MAIOR", "T_MENOR", "T_IGUAL", "T_E", "T_OU",
  "T_NAO", "T_V", "T_F", "T_NUMERO", "T_ABRE", "T_FECHA", "T_INTEIRO",
  "T_LOGICO", "T_REPITA", "T_ATE", "T_FIMREPITA", "T_FUNC", "T_FIMFUNC",
  "T_REF", "$accept", "programa", "$@1", "$@2", "cabecalho", "rotinas",
  "$@3", "lista_funcoes", "funcao", "$@4", "$@5", "lista_parametros",
  "parametro", "mecanismo", "variaveis", "declaracao_variaveis", "tipo",
  "lista_variaveis", "lista_comandos", "comando", "entrada_saida",
  "identificador", "leitura", "escrita", "repeticao", "$@6", "$@7",
  "repetir", "selecao", "$@8", "$@9", "atribuicao", "$@10", "expressao",
  "argumentos", "lista_argumentos", "argumento", "termo", "$@11", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF (-40)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-8)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,     1,    17,   -40,   -40,   -40,    -7,   -40,   -40,   -40,
     -40,    26,   -14,   -40,    -5,    31,    -3,   -40,   -40,     6,
      -7,   -40,    -3,   -40,    32,    30,   -40,    30,     6,    34,
       6,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,    35,
     -40,   -40,    30,   -40,   -40,   -40,    30,     7,   132,   -40,
      30,   123,    18,   -40,   -40,    36,   -40,   -40,   108,   -40,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    99,
     -40,    30,    30,    12,   -40,    30,   -40,   -40,    13,    13,
       2,     2,   141,    59,    59,   -40,     6,    79,   132,   -40,
     132,    33,    30,   -40,     6,    47,   -40,   -15,   -40,   -40,
      52,   -40,   -40,   -40,   -40,    -7,   -40,     6,    -7,    60,
      50,    64,   -40,   -40,     6,    46,   -40
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     5,     1,    19,    24,    23,     3,
      20,     0,     6,    26,    22,     0,     0,    25,    21,    27,
       0,     8,    10,    36,     0,     0,    39,     0,    27,     0,
      27,    29,    46,    34,    35,    30,    33,    31,    32,     0,
       9,    37,     0,    67,    68,    66,     0,    63,    38,    57,
       0,     0,     0,     4,    28,     0,    11,    69,     0,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      43,     0,     0,     0,    70,    58,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    40,    27,     0,    47,    14,
      62,     0,    59,    61,    27,     0,    42,    17,    65,    60,
       0,    44,    12,    18,    15,     0,    41,    27,    19,     0,
       0,     0,    16,    45,    27,     0,    13
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,   -40,   -40,   -40,   -40,   -40,    49,   -40,   -40,
     -40,   -40,   -40,   -40,   -39,    58,   -18,   -40,   -24,   -40,
     -40,   -19,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -17,   -40,   -40,    -6,    43,   -40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     6,    12,     3,    15,    16,    21,    22,    73,
     108,    97,   104,   105,     9,    10,    11,    14,    29,    30,
      31,    47,    33,    34,    35,    50,    94,    36,    37,    86,
     107,    38,    55,    90,    91,    92,    93,    49,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      32,    17,    39,     1,    52,    41,    54,     4,    48,    32,
      51,    32,    23,    24,    25,    26,   102,     5,    27,    60,
      61,    62,    63,    -7,   103,     7,     8,     7,     8,    58,
      60,    61,    13,    69,    20,    19,    23,    59,    23,    53,
      28,    56,    89,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    72,    71,    87,    88,    42,    43,    44,    45,
      46,   101,    95,   106,    98,   113,   112,    32,   114,   111,
     100,    40,    18,     0,     0,    32,    60,    61,    62,    63,
      64,    65,    66,   110,   116,    57,    99,   109,    32,     0,
     115,     0,     0,     0,     0,    32,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,    96,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,     0,    70,     0,     0,    74,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    60,    61,
      62,    63,    64,    65
};

static const yytype_int8 yycheck[] =
{
      19,     6,    20,     3,    28,    24,    30,     6,    25,    28,
      27,    30,     6,     7,     8,     9,    31,     0,    12,    17,
      18,    19,    20,    37,    39,    32,    33,    32,    33,    46,
      17,    18,     6,    50,    37,     4,     6,    30,     6,     5,
      34,     6,    30,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    16,    35,    71,    72,    26,    27,    28,    29,
      30,    14,    86,    11,    31,    15,     6,    86,     4,   108,
      94,    22,    14,    -1,    -1,    94,    17,    18,    19,    20,
      21,    22,    23,   107,    38,    42,    92,   105,   107,    -1,
     114,    -1,    -1,    -1,    -1,   114,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    36,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,    31,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    17,    18,
      19,    20,    21,    22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    41,    44,     6,     0,    42,    32,    33,    54,
      55,    56,    43,     6,    57,    45,    46,     6,    55,     4,
      37,    47,    48,     6,     7,     8,     9,    12,    34,    58,
      59,    60,    61,    62,    63,    64,    67,    68,    71,    56,
      47,    61,    26,    27,    28,    29,    30,    61,    73,    77,
      65,    73,    58,     5,    58,    72,     6,    77,    73,    30,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    73,
      13,    35,    16,    49,    31,    78,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    10,    69,    73,    73,    30,
      73,    74,    75,    76,    66,    58,    36,    51,    31,    76,
      58,    14,    31,    39,    52,    53,    11,    70,    50,    56,
      58,    54,     6,    15,     4,    58,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    42,    43,    41,    44,    45,    46,    45,    47,
      47,    49,    50,    48,    51,    51,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    60,    60,    61,    62,    63,    65,
      66,    64,    67,    69,    70,    68,    72,    71,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    74,    74,
      75,    75,    76,    77,    78,    77,    77,    77,    77,    77,
      77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     8,     2,     0,     0,     2,     2,
       1,     0,     0,    12,     0,     2,     3,     0,     1,     0,
       1,     3,     2,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     0,
       0,     7,     5,     0,     0,     9,     0,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     0,     1,
       2,     1,     1,     1,     0,     5,     1,     1,     1,     2,
       3
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
#line 97 "sintatico.y"
            {fprintf(yyout,"\tINPP\n"); }
#line 1465 "sintatico.c"
    break;

  case 3:
#line 99 "sintatico.y"
            {
               gvar = avar; //quantidade de variáveis declaradas globalmente
            }
#line 1473 "sintatico.c"
    break;

  case 4:
#line 103 "sintatico.y"
            {
                 fprintf(yyout,"\tDMEM\t%d\n", gvar); //imprime a quantidade de variaveis globais que foram desalocadas
                 fprintf(yyout,"\tFIMP\n"); }
#line 1481 "sintatico.c"
    break;

  case 7:
#line 110 "sintatico.y"
          {
               fprintf(yyout,"\tDSVS\tL0\n");  // imprime o desvio sempre
          }
#line 1489 "sintatico.c"
    break;

  case 8:
#line 113 "sintatico.y"
          {
               fprintf(yyout,"L0\tNADA\n"); //imprime o caminho que vai o desvio sempre
          }
#line 1497 "sintatico.c"
    break;

  case 11:
#line 121 "sintatico.y"
     {
          avar = 0;
          rotulo++;
          strcpy(elem_tab.id, atomo);
          elem_tab.endereco = contaVar;
          elem_tab.tipo = tipo;
          elem_tab.escopo = escopo;
          elem_tab.mec = -1;
          elem_tab.rotulo = rotulo;
          fprintf(yyout,"L%d\tENSP\n", rotulo);                   //insere uma função na tabela de simbolos
          elem_tab.cat = 'F';
          contaVar++;
          insere_simbolo(elem_tab);
          escopo = 'L';
     }
#line 1517 "sintatico.c"
    break;

  case 12:
#line 137 "sintatico.y"
      {
          arruma_deslocamento(contaVar, npar);                 //deslocamento do ultimo parametro no valor de -3
      }
#line 1525 "sintatico.c"
    break;

  case 13:
#line 141 "sintatico.y"
        {
             int removeVariavelLocal = remove_local();
             fprintf(yyout,"\tDMEM\t%d\n", removeVariavelLocal - npar); //remove as variaveis declaradas, retirando as variaveis do parametro
             contaVar = contaVar - removeVariavelLocal;
             DEBUG (mostra_tabela(); )                             
             escopo = 'G';
             fprintf(yyout,"\tRTSP\t%d\n", npar); 
             npar = 0;

        }
#line 1540 "sintatico.c"
    break;

  case 16:
#line 155 "sintatico.y"
     {
          npar++;
          strcpy(elem_tab.id, atomo);
          elem_tab.endereco = contaVar;
          elem_tab.tipo = tipo;
          elem_tab.escopo = escopo;                    //insere na tabela de simbolo as variaveis declaradas no parametro da funcao 
          elem_tab.mec = mecanismo;
          elem_tab.rotulo = -1;
          elem_tab.cat = 'P';
          insere_simbolo(elem_tab);
          contaVar++;
          DEBUG (mostra_tabela(); )  
     }
#line 1558 "sintatico.c"
    break;

  case 17:
#line 168 "sintatico.y"
           {mecanismo = VAL;}
#line 1564 "sintatico.c"
    break;

  case 18:
#line 168 "sintatico.y"
                                      {mecanismo = REF;}
#line 1570 "sintatico.c"
    break;

  case 20:
#line 171 "sintatico.y"
            {
               DEBUG (mostra_tabela(); )
               fprintf(yyout,"\tAMEM\t%d\n",avar);     //mostra a quantidade variaveis alocada globalmente
            }
#line 1579 "sintatico.c"
    break;

  case 23:
#line 179 "sintatico.y"
               { tipo = LOG; }
#line 1585 "sintatico.c"
    break;

  case 24:
#line 179 "sintatico.y"
                                          {tipo = INT; }
#line 1591 "sintatico.c"
    break;

  case 25:
#line 182 "sintatico.y"
                    {    
                         strcpy (elem_tab.id, atomo) ;
                         elem_tab.endereco = avar;  
                         elem_tab.tipo = tipo;
                         elem_tab.escopo = escopo;
                         elem_tab.mec = -1;
                         elem_tab.rotulo = -1;
                         elem_tab.cat = 'V';
                         insere_simbolo (elem_tab);                   //insere as variaveis na tabela simbolo
                         contaVar++;    
                         avar++;
                    }
#line 1608 "sintatico.c"
    break;

  case 26:
#line 196 "sintatico.y"
                   {    
                         strcpy (elem_tab.id, atomo) ;
                         elem_tab.endereco = avar;  
                         elem_tab.tipo = tipo;
                         elem_tab.escopo = escopo;
                         elem_tab.mec = -1;
                         elem_tab.rotulo = -1;
                         elem_tab.cat = 'V';
                         insere_simbolo (elem_tab);
                         contaVar++;     
                         avar++;
                    }
#line 1625 "sintatico.c"
    break;

  case 36:
#line 216 "sintatico.y"
          {
               int i = busca_simbolo (atomo);
               if(i == -1)
                    msg("Identificador desconhecido");
               empilha(i,'i');
          }
#line 1636 "sintatico.c"
    break;

  case 37:
#line 224 "sintatico.y"
         {
              fprintf(yyout,"\tLEIA\n"); 
              int pos = busca_simbolo(atomo);
              if(pos == -1)
                  msg("Variavel nao declarada\n");
               if(TabSimb[pos].escopo == 'G')
                    fprintf(yyout,"\tARZG\t%d\n",TabSimb[pos].endereco); 
               else
                    if(TabSimb[pos].escopo == 'L' || TabSimb[pos].mec == VAL)
                         fprintf(yyout,"\tARZL\t%d\n",TabSimb[pos].endereco); 
                    else
                         fprintf(yyout,"\tARZI\t%d\n",TabSimb[pos].endereco); 
         }
#line 1654 "sintatico.c"
    break;

  case 38:
#line 239 "sintatico.y"
            {
                 fprintf(yyout,"\tESCR\n"); 
                 desempilha();
            }
#line 1663 "sintatico.c"
    break;

  case 39:
#line 246 "sintatico.y"
            {rotulo++;
            fprintf(yyout,"L%d\tNADA\n", rotulo); 
            empilha(rotulo, 'r'); }
#line 1671 "sintatico.c"
    break;

  case 40:
#line 250 "sintatico.y"
            {
                 DEBUG (mostra_pilha("repeticao"); )
                 int t1 = desempilha();
                 if(t1 != LOG)
                    msg("Incompatibilidade de tipos");
                 rotulo++;
                 fprintf(yyout,"\tDSVF\tL%d\n", rotulo); 
                 empilha(rotulo, 'r') ;}
#line 1684 "sintatico.c"
    break;

  case 41:
#line 259 "sintatico.y"
            {    int r1 = desempilha();
                 int r2 = desempilha();
                 fprintf(yyout,"\tDSVS\tL%d\n", r2); 
                 fprintf(yyout,"L%d\tNADA\n", r1); 
            }
#line 1694 "sintatico.c"
    break;

  case 43:
#line 268 "sintatico.y"
            {
               DEBUG (mostra_pilha("selecao"); )
               int t1 = desempilha();
               if(t1 != LOG)
                  msg("Incompatibilidade de tipos");  
               rotulo++;
               fprintf(yyout,"\tDSVF\tL%d\n", rotulo);
               empilha(rotulo, 'r');
           }
#line 1708 "sintatico.c"
    break;

  case 44:
#line 278 "sintatico.y"
            {
                 int r = desempilha();
                 rotulo++;
                 fprintf(yyout,"\tDSVS\tL%d\n", rotulo); 
                 fprintf(yyout,"L%d\tNADA\n", r); 
                 empilha(rotulo, 'r');
            }
#line 1720 "sintatico.c"
    break;

  case 45:
#line 286 "sintatico.y"
            {    int r = desempilha();
                 fprintf(yyout,"L%d\tNADA\n", r); 
            }
#line 1728 "sintatico.c"
    break;

  case 46:
#line 291 "sintatico.y"
          {    
               int pos = desempilha();
               empilha(pos,'i');
               empilha(TabSimb[pos].tipo, 't');
          }
#line 1738 "sintatico.c"
    break;

  case 47:
#line 298 "sintatico.y"
            {  
                 DEBUG (mostra_pilha("atribuicao"); )
                 int texp = desempilha();
                 int tvar = desempilha(); 
                 int end = desempilha();
                 if(texp != tvar)
                    msg("Incompatibilidade de tipos");
                 if(TabSimb[end].escopo == 'G')
                    fprintf(yyout,"\tARZG\t%d\n",TabSimb[end].endereco); 
               else                                                                  //Armazena a variavel com base no tipo dela
                    if(TabSimb[end].escopo == 'L' || TabSimb[end].mec == VAL)
                         fprintf(yyout,"\tARZL\t%d\n",TabSimb[end].endereco); 
                    else
                         fprintf(yyout,"\tARZI\t%d\n",TabSimb[end].endereco); 
            }
#line 1758 "sintatico.c"
    break;

  case 48:
#line 315 "sintatico.y"
                 {
                      char tipo2 = desempilha_tipo();            //retorna o tipo do topo da pilha 
                      int t2 = desempilha();                     //retorno o valor do topo da pilha que é o endereço
                                                                           
                      if(tipo2 == 'i')                           //se o tipo do topo da pilha for um identificador, busco o tipo do valor na tabela de simbolos
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();            
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tMULT\n");
                      empilha(INT, 't');
                 }
#line 1781 "sintatico.c"
    break;

  case 49:
#line 335 "sintatico.y"
                 {
                      char tipo2 = desempilha_tipo();
                      int t2 = desempilha();

                      if(tipo2 == 'i')       
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tDIV\n"); 
                      empilha(INT, 't');
                 }
#line 1804 "sintatico.c"
    break;

  case 50:
#line 355 "sintatico.y"
                 {
                     char tipo2 = desempilha_tipo();
                      int t2 = desempilha();

                      if(tipo2 == 'i')       
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tSOMA\n"); 
                      empilha(INT, 't');
                 }
#line 1827 "sintatico.c"
    break;

  case 51:
#line 375 "sintatico.y"
                 {
                     char tipo2 = desempilha_tipo();
                      int t2 = desempilha();

                      if(tipo2 == 'i')       
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tSUBT\n"); 
                      empilha(INT, 't');
                 }
#line 1850 "sintatico.c"
    break;

  case 52:
#line 395 "sintatico.y"
                 {
                      char tipo2 = desempilha_tipo();
                      int t2 = desempilha();

                      if(tipo2 == 'i')       
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tCMMA\n"); 
                      empilha(LOG, 't');
                 }
#line 1873 "sintatico.c"
    break;

  case 53:
#line 415 "sintatico.y"
                 {
                      char tipo2 = desempilha_tipo();
                      int t2 = desempilha();

                      if(tipo2 == 'i')       
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tCMME\n"); 
                      empilha(LOG, 't');
                 }
#line 1896 "sintatico.c"
    break;

  case 54:
#line 435 "sintatico.y"
                 {
                      char tipo2 = desempilha_tipo();
                      int t2 = desempilha();

                      if(tipo2 == 'i')       
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tCMIG\n"); 
                      empilha(LOG, 't');
                 }
#line 1919 "sintatico.c"
    break;

  case 55:
#line 455 "sintatico.y"
                 {
                      char tipo2 = desempilha_tipo();
                      int t2 = desempilha();

                      if(tipo2 == 'i')       
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tCONJ\n"); 
                      empilha(LOG, 't');
                 }
#line 1942 "sintatico.c"
    break;

  case 56:
#line 475 "sintatico.y"
                 {
                      char tipo2 = desempilha_tipo();
                      int t2 = desempilha();

                      if(tipo2 == 'i')       
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tDISJ\n"); 
                      empilha(LOG, 't');
                 }
#line 1965 "sintatico.c"
    break;

  case 62:
#line 501 "sintatico.y"
          {
               npar++;
               int posArg = desempilha();
               int posFunc = desempilha();         
               int posPar = TabSimb[posFunc].npar - npar;
               int retorno = buscaTipoParametro(posFunc,posPar);           //Compara o tipo do argumento declarado na função com o tipo da chamada da funcao
               if(retorno == -1)
                    msg("Parametro nao encontrado");
               if(TabSimb[posArg].tipo != retorno)
                    msg("ERRO");    
               empilha(posFunc, 'i');

          }
#line 1983 "sintatico.c"
    break;

  case 63:
#line 517 "sintatico.y"
     {
          int t1 = desempilha();
          if(TabSimb[t1].escopo == 'G' ){
               if(TabSimb[t1].mec == REF)
                    fprintf(yyout,"\tCREG\t%d\n", TabSimb[t1].endereco); 
               else
                    fprintf(yyout,"\tCRVG\t%d\n", TabSimb[t1].endereco);        //Carrega a variavel com base no seu tipo
          }
          else if(TabSimb[t1].escopo == 'L'){
               if(TabSimb[t1].mec == REF)
                    fprintf(yyout,"\tCREL\t%d\n", TabSimb[t1].endereco); 
               else
                    fprintf(yyout,"\tCRVL\t%d\n", TabSimb[t1].endereco); 
          }
          empilha(t1, 'i');
     }
#line 2004 "sintatico.c"
    break;

  case 64:
#line 536 "sintatico.y"
     {
          fprintf(yyout,"\tAMEM\t1\n");
     }
#line 2012 "sintatico.c"
    break;

  case 65:
#line 539 "sintatico.y"
     {
          int t1 = desempilha();
          empilha(TabSimb[t1].tipo, 't');
          fprintf(yyout,"\tSVCP\t\n");                                     //Desvio usado para chamar a função
          fprintf(yyout,"\tDSVS\tL%d\n",TabSimb[t1].rotulo);
     }
#line 2023 "sintatico.c"
    break;

  case 66:
#line 547 "sintatico.y"
            {
                 fprintf(yyout,"\tCRCT\t%s\n", atomo); 
                 empilha(INT, 't');
                 }
#line 2032 "sintatico.c"
    break;

  case 67:
#line 553 "sintatico.y"
            {
                 fprintf(yyout,"\tCRCT\t1\n"); 
                 empilha(LOG, 't');
            }
#line 2041 "sintatico.c"
    break;

  case 68:
#line 559 "sintatico.y"
            {
                 fprintf(yyout,"\tCRCT\t0\n"); 
                 empilha(LOG, 't');
            }
#line 2050 "sintatico.c"
    break;

  case 69:
#line 565 "sintatico.y"
            {
                 int t1 = desempilha();
                 if(t1 != LOG)
                    msg("Incompatibilidade de tipos");
                 fprintf(yyout,"\tNEGA\n"); 
                 empilha(LOG, 't');
            }
#line 2062 "sintatico.c"
    break;


#line 2066 "sintatico.c"

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
#line 577 "sintatico.y"


/*+--------------------------------------------+
  |     Corpo principal do programa COMPILADOR |
  +--------------------------------------------+*/

  int yyerror (char *s){
      msg("ERRO SINTATICO");
  }


  int main (int argc, char *argv[]){
       char *p, nameIn[100], nameOut[100];
       argc--;
       argv++;

       if(argc < 1){
            puts("\nCompilador SIMPLES");
            puts("\tUSO: ./simples <nomefonte>[.simples]\n\n");
            exit(10);
       }
       if(p =strstr (argv[0], ".simples"))
            *p = 0;
        strcpy (nameIn, argv[0]);
        strcat (nameIn, ".simples");
        strcpy (nameOut, argv[0]);
        strcat (nameOut, ".mvs");

        yyin = fopen(nameIn, "r");
        if(!yyin){
             puts("Programa fonte nao encontrado!");
             exit(20);
        }
        yyout = fopen(nameOut, "w");

        if(!yyparse()){
             printf("\nPrograma OK!\n\n");  
        }
        desaloca();
  }
