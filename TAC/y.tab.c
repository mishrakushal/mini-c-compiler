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
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symbol_table.c"

    #define HUNDO 1000
    #define MAX_CODE_LENGTH 1000
    #define MAX_NUM_OF_SYMBOLS 1000

    int g_addr = 100 * 1;
    int i=1 * 1;
    int lnum1 = 0 * 1;
    int stack[HUNDO];
    int idx_1 = 0 * 1;
    int end[HUNDO],arr[10];
    int ct = 0  * 1;
    int c = 0 * 1;
    int b = 0 * 1;
    int fl = 0 * 1;
    int top = 0 * 1;
    int label[20];
    int num_label = 0 * 1;
    int ltop=0 * 1;
    char stmt1[HUNDO][10];
    char temp_count[2]="0";
    int plist[HUNDO],flist[HUNDO], k = -1 * 1,errc=0 * 1,j=0 * 1;
    char temp[2]="t";
    char null[2]=" ";
    void yyerror(char *s);
    int print_line();
    extern int yylineno;
    void start_scope() {
        stack[idx_1] = i * 1;
        i += 1 * 1;
        idx_1 += 1 * 1;
        // return;
    }

    void end_scope() {
        idx_1 -= 1 * 1;
        end[stack[idx_1]] = 1 * 1;
        stack[idx_1] = 0 * 1;
        // return;
    }

    void if1() {
        num_label += 1 * 1;
        strcpy(temp,"t");
        strcat(temp,temp_count);
        printf("\n%s = not %s\n",temp,stmt1[top * 1]);
        printf("if %s goto L%d\n",temp,num_label);
        temp_count[0] += 1 * 1;
        label[++ltop] = num_label * 1;
        return;
    }

    void if2() {
        num_label += 1 * 1;
        printf("\ngoto L%d\n",num_label);
        printf("L%d: \n",label[ltop--]);
        label[++ltop] = num_label * 1;
        return;
    }

    void if3() {
        printf("\nL%d:\n",label[ltop--]);
        return;
    }

    void while1() {
        num_label += 1 * 1;
        label[++ltop] = num_label * 1;
        printf("\nL%d:\n",num_label);
        return;
    }

    void while2() {
        num_label += 1 * 1;
        strcpy(temp,"t");
        strcat(temp,temp_count);
        printf("\n%s = not %s\n",temp,stmt1[top--]);
        printf("if %s goto L%d\n",temp,num_label);
        temp_count[0] += 1 * 1;
        label[++ltop] = num_label * 1;
        return;
    }

    void while3() {
        int y = label[ltop--];
        printf("\ngoto L%d\n",label[ltop--]);
        printf("L%d:\n",y);
        return;
    }

    void dowhile1() {
        num_label += 1 * 1;
        label[++ltop]=num_label;
        printf("\nL%d:\n",num_label);
        return;
    }

    void dowhile2() {
        printf("\nif %s goto L%d\n",stmt1[top--],label[ltop--]);
        return;
    }

    void for1() {
        num_label += 1 * 1;
        label[++ltop] = num_label * 1;
        printf("\nL%d:\n",num_label);
        return;
    }

    void for2() {
        num_label += 1 * 1;
        strcpy(temp,"t");
        strcat(temp,temp_count);
        printf("\n%s = not %s\n",temp,stmt1[top--]);
        printf("if %s goto L%d\n",temp,num_label);
        temp_count[0] += 1 * 1;
        label[++ltop] = num_label * 1;
        num_label += 1 * 1;
        printf("goto L%d\n",num_label);
        label[++ltop * 1] = num_label * 1;
        num_label += 1 * 1;
        printf("L%d:\n",num_label);
        label[++ltop * 1] = num_label * 1;
        return;
    }

    void for3() {
        printf("\ngoto L%d\n",label[ltop-3]);
        printf("L%d:\n",label[ltop-1]);
        return;
    }

    void for4() {
        printf("\ngoto L%d\n",label[ltop * 1]);
        printf("L%d:\n",label[ltop-2]);
        ltop -= 4 * 1;
        return;
    }

    void push(char *a) {
        strcpy(stmt1[++top * 1],a);
        return;
    }

    void array1() {
        strcpy(temp,"t");
        strcat(temp,temp_count);
        printf("\n%s = %s\n",temp,stmt1[top * 1]);
        strcpy(stmt1[top * 1],temp);
        temp_count[0]++;
        strcpy(temp,"t");
        strcat(temp,temp_count);
        printf("%s = %s [ %s ] \n",temp,stmt1[top-1],stmt1[top * 1]);
        top -= 1 * 1;
        strcpy(stmt1[top],temp);
        temp_count[0] += 1 * 1;
        return;
    }

    void code_generator() {
        strcpy(temp,"t");
        strcat(temp,temp_count);
        printf("\n%s = %s %s %s\n",temp,stmt1[top-2],stmt1[top-1],stmt1[top * 1]);
        top -= 2 * 1;
        strcpy(stmt1[top],temp);
        temp_count[0] += 1 * 1;
        return;
    }

    void code_gen_umin() {
        strcpy(temp,"t");
        strcat(temp,temp_count);
        printf("\n%s = -%s\n",temp,stmt1[top]);
        top -= 1;
        strcpy(stmt1[top],temp);
        temp_count[0] += 1 * 1;
    }

    void codegen_assign() {
        printf("\n%s = %s\n",stmt1[top - 2],stmt1[top * 1]);
        top = top - 2 * 1;
        return;
    }

#line 260 "y.tab.c"

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
    INT = 258,
    FLOAT = 259,
    VOID = 260,
    ID = 261,
    NUM = 262,
    REAL = 263,
    WHILE = 264,
    IF = 265,
    RETURN = 266,
    PREPROC = 267,
    LE = 268,
    STRING = 269,
    PRINT = 270,
    FUNCTION = 271,
    DO = 272,
    ARRAY = 273,
    ELSE = 274,
    STRUCT = 275,
    STRUCT_VAR = 276,
    FOR = 277,
    GE = 278,
    EQ = 279,
    NE = 280,
    INC = 281,
    DEC = 282,
    AND = 283,
    OR = 284,
    NEQ = 285,
    UMINUS = 286
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define VOID 260
#define ID 261
#define NUM 262
#define REAL 263
#define WHILE 264
#define IF 265
#define RETURN 266
#define PREPROC 267
#define LE 268
#define STRING 269
#define PRINT 270
#define FUNCTION 271
#define DO 272
#define ARRAY 273
#define ELSE 274
#define STRUCT 275
#define STRUCT_VAR 276
#define FOR 277
#define GE 278
#define EQ 279
#define NE 280
#define INC 281
#define DEC 282
#define AND 283
#define OR 284
#define NEQ 285
#define UMINUS 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 201 "parser.y"

        int ival;
        char *str;
    

#line 377 "y.tab.c"

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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  204

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


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
      39,    40,    37,    35,    41,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      31,    33,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   207,   207,   208,   209,   210,   213,   229,   247,   248,
     251,   254,   255,   256,   259,   262,   263,   266,   267,   268,
     269,   270,   271,   272,   279,   280,   290,   291,   292,   295,
     295,   295,   298,   298,   298,   298,   301,   301,   301,   304,
     305,   308,   308,   308,   311,   312,   313,   314,   315,   316,
     319,   319,   319,   319,   334,   338,   339,   343,   346,   347,
     350,   350,   350,   350,   376,   388,   423,   424,   428,   432,
     435,   435,   438,   438,   439,   439,   440,   441,   441,   441,
     442,   442,   442,   443,   443,   443,   444,   444,   444,   445,
     445,   445,   446,   446,   446,   447,   447,   447,   448,   448,
     448,   449,   449,   449,   450,   452,   452,   453,   453,   454,
     456,   457,   457,   458,   459
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "VOID", "ID", "NUM",
  "REAL", "WHILE", "IF", "RETURN", "PREPROC", "LE", "STRING", "PRINT",
  "FUNCTION", "DO", "ARRAY", "ELSE", "STRUCT", "STRUCT_VAR", "FOR", "GE",
  "EQ", "NE", "INC", "DEC", "AND", "OR", "NEQ", "'<'", "'>'", "'='",
  "UMINUS", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "','", "'{'", "'}'",
  "';'", "'['", "']'", "$accept", "start", "Function", "parameter_list",
  "parameter", "Type", "CompoundStmt", "StmtList", "stmt", "dowhile",
  "$@1", "$@2", "for", "$@3", "$@4", "$@5", "if", "$@6", "$@7", "else",
  "while", "$@8", "$@9", "assignment", "assignment1", "$@10", "$@11",
  "$@12", "consttype", "Declaration", "$@13", "$@14", "$@15", "array",
  "$@16", "E", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23",
  "$@24", "$@25", "$@26", "$@27", "$@28", "$@29", "$@30", "$@31", "$@32",
  "$@33", "$@34", "$@35", "$@36", "T", "$@37", "$@38", "F", "$@39", YY_NULLPTR
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
     285,    60,    62,    61,   286,    43,    45,    42,    47,    40,
      41,    44,   123,   125,    59,    91,    93
};
# endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-102)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     167,   -66,   -66,   -66,   -66,    82,   -66,   -66,   167,    20,
      31,   167,    48,     4,    23,   167,    70,    70,    58,   -66,
       3,   -66,   -66,    -3,   -66,    70,   -66,    25,   -66,    71,
     -66,    55,   187,     7,   129,    95,   -66,    98,    17,   -66,
     150,   115,   118,    28,   -66,   155,    22,   117,   124,   -66,
     -66,    77,   -66,    17,   -66,   -66,    44,    66,   -66,   121,
     125,   -66,   -66,   118,   135,   -66,   112,   129,   129,   132,
     129,    17,   133,   164,   157,   158,   151,   161,   154,   165,
     166,   168,    26,   -21,   -66,   -66,   -66,   -66,   -66,   -66,
     142,   -66,   -66,   -66,   -66,   -66,   -66,   -66,    44,    17,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,    26,    26,    26,    26,    53,   -66,   160,     0,
     163,   -66,   169,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   153,    -8,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    66,    66,   -66,   -66,   170,   172,    17,
     156,   -66,   159,   190,   118,    17,   -66,   -66,    44,    44,
      44,    44,    44,    44,    44,    44,    44,   162,    17,    76,
     -66,   -66,   173,   196,    44,   -66,    78,   -66,   171,   175,
     174,   -66,   118,   -66,    17,    17,   118,   -66,    94,    44,
     -66,   193,   -66,   176,   118,   -66,   177,    17,   -66,   -66,
      44,   179,   118,   -66
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    69,    11,    12,    13,    50,    58,    59,     0,     0,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     3,
       0,     1,     2,    60,    64,     0,     4,    56,    54,     0,
      51,     0,     0,     0,     0,     0,    55,     0,     0,    68,
       0,     0,     0,     0,     9,     0,    48,     0,    49,    61,
      66,   113,   111,     0,   114,   104,    52,    76,   109,    60,
       0,    16,     6,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    74,    53,   105,   107,    67,
       0,     7,     8,    44,    45,    46,    65,    47,    62,     0,
      78,    81,    84,    87,    90,    93,    96,    99,   102,   113,
     112,   110,     0,     0,     0,     0,    50,    41,     0,     0,
       0,    29,     0,    14,    26,    28,    15,    21,    22,    18,
      20,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    75,   106,   108,     0,     0,     0,
       0,    24,     0,     0,     0,     0,    63,    71,    79,    82,
      85,    88,    91,    94,    97,   100,   103,     0,     0,     0,
      25,    23,     0,     0,    32,    19,     0,    36,     0,     0,
       0,    42,     0,    27,     0,     0,     0,    37,     0,    33,
      43,    40,    30,     0,     0,    38,     0,     0,    39,    31,
      34,     0,     0,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,    59,   -66,   -66,   145,   -29,   -61,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -27,    35,   -66,   -66,   -66,     5,   -31,
     -66,   -66,   -66,   -66,   -66,   -53,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,    42,   -66,   -66,   -65,
     -66
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    43,    44,    12,    62,    90,   126,   127,
     154,   196,   128,   180,   193,   201,   129,   182,   191,   195,
     130,   148,   186,    47,    13,    18,    38,    86,    54,    15,
      35,    71,   132,    55,    72,    56,   112,   113,    73,   134,
      74,   135,    75,   136,    76,   137,    77,   138,    78,   139,
      79,   140,    80,   141,    81,   142,    57,   114,   115,    58,
      82
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      83,    41,    91,    40,    45,    14,   150,     6,     7,    31,
       2,     3,     4,    14,    84,    85,    14,   110,    98,   111,
      14,    14,    14,    51,     6,     7,    20,    84,    85,   125,
      14,    21,   109,     6,     7,    45,    33,    14,   157,    48,
      94,    95,    34,    97,   151,    32,   133,    42,    24,   145,
     146,    28,    29,    52,    23,    66,    53,    67,   -50,   131,
      36,    40,    52,    68,    25,    53,    16,    19,    63,    64,
      22,    93,    48,    48,    26,    48,    27,     6,     7,    84,
      85,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     -77,    30,   147,   173,    16,    14,   169,   -56,    17,    39,
     -80,   -83,   174,    87,    88,   -89,   -92,   -86,   -95,   -98,
    -101,    84,    85,    84,    85,   176,   177,    37,   181,     6,
       7,   187,   -70,    16,   152,   190,   -56,    17,    49,    84,
      85,   188,   189,   198,   192,    46,     6,     7,     2,     3,
       4,   203,    50,     1,   200,     2,     3,     4,   116,     6,
       7,   117,   118,   119,   143,   144,    59,   120,    60,   121,
      61,    65,     9,    69,   122,    70,    34,    -5,     1,    89,
       2,     3,     4,     5,     6,     7,    96,   100,    99,     8,
     101,   103,   102,   105,    61,   123,   124,     9,     1,   104,
       2,     3,     4,     5,     6,     7,   106,   156,   107,   149,
     170,   108,   153,   171,   172,   179,   175,     9,   155,    92,
     167,   168,   194,   178,   184,   183,     0,     0,   185,   202,
     197,   199
};

static const yytype_int16 yycheck[] =
{
      53,    32,    63,    32,    33,     0,     6,     7,     8,     6,
       3,     4,     5,     8,    35,    36,    11,    82,    71,    40,
      15,    16,    17,     6,     7,     8,     6,    35,    36,    90,
      25,     0,     6,     7,     8,    64,    39,    32,    46,    34,
      67,    68,    45,    70,    44,    42,    99,    40,    44,   114,
     115,    16,    17,    36,     6,    33,    39,    35,    33,    90,
      25,    90,    36,    41,    41,    39,    41,     8,    40,    41,
      11,    66,    67,    68,    15,    70,     6,     7,     8,    35,
      36,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      13,    33,    39,   154,    41,    90,   149,    44,    45,    44,
      23,    24,   155,    37,    38,    28,    29,    30,    31,    32,
      33,    35,    36,    35,    36,   168,    40,    46,    40,     7,
       8,   182,    45,    41,   119,   186,    44,    45,    33,    35,
      36,   184,   185,   194,    40,     6,     7,     8,     3,     4,
       5,   202,    44,     1,   197,     3,     4,     5,     6,     7,
       8,     9,    10,    11,   112,   113,     6,    15,    43,    17,
      42,     6,    20,    46,    22,    41,    45,     0,     1,    44,
       3,     4,     5,     6,     7,     8,    44,    13,    45,    12,
      23,    30,    24,    29,    42,    43,    44,    20,     1,    28,
       3,     4,     5,     6,     7,     8,    31,    44,    32,    39,
      44,    33,    39,    44,    14,     9,    44,    20,    39,    64,
      40,    39,    19,    40,    39,    44,    -1,    -1,    44,    40,
      44,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    12,    20,
      48,    49,    52,    71,    75,    76,    41,    45,    72,    48,
       6,     0,    48,     6,    44,    41,    48,     6,    71,    71,
      33,     6,    42,    39,    45,    77,    71,    46,    73,    44,
      52,    76,    40,    50,    51,    52,     6,    70,    75,    33,
      44,     6,    36,    39,    75,    80,    82,   103,   106,     6,
      43,    42,    53,    40,    41,     6,    33,    35,    41,    46,
      41,    78,    81,    85,    87,    89,    91,    93,    95,    97,
      99,   101,   107,    82,    35,    36,    74,    37,    38,    44,
      54,    53,    51,    75,    70,    70,    44,    70,    82,    45,
      13,    23,    24,    30,    28,    29,    31,    32,    33,     6,
     106,    40,    83,    84,   104,   105,     6,     9,    10,    11,
      15,    17,    22,    43,    44,    53,    55,    56,    59,    63,
      67,    76,    79,    82,    86,    88,    90,    92,    94,    96,
      98,   100,   102,   103,   103,   106,   106,    39,    68,    39,
       6,    44,    75,    39,    57,    39,    44,    46,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    40,    39,    82,
      44,    44,    14,    53,    82,    44,    82,    40,    40,     9,
      60,    40,    64,    44,    39,    44,    69,    53,    82,    82,
      53,    65,    40,    61,    19,    66,    58,    44,    53,    44,
      82,    62,    40,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    48,    48,    49,    49,    50,    50,
      51,    52,    52,    52,    53,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    57,
      58,    56,    60,    61,    62,    59,    64,    65,    63,    66,
      66,    68,    69,    67,    70,    70,    70,    70,    70,    70,
      72,    73,    74,    71,    71,    71,    71,    71,    75,    75,
      77,    78,    79,    76,    76,    76,    76,    76,    76,    76,
      81,    80,    83,    82,    84,    82,    82,    85,    86,    82,
      87,    88,    82,    89,    90,    82,    91,    92,    82,    93,
      94,    82,    95,    96,    82,    97,    98,    82,    99,   100,
      82,   101,   102,    82,    82,   104,   103,   105,   103,   103,
     106,   107,   106,   106,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     5,     6,     3,     1,
       2,     1,     1,     1,     3,     2,     0,     1,     1,     4,
       1,     1,     1,     3,     2,     3,     1,     5,     1,     0,
       0,     9,     0,     0,     0,    12,     0,     0,     8,     2,
       0,     0,     0,     7,     3,     3,     3,     3,     1,     1,
       0,     0,     0,     6,     3,     3,     1,     1,     1,     1,
       0,     0,     0,     8,     2,     6,     5,     6,     4,     1,
       0,     5,     0,     4,     0,     4,     1,     0,     0,     5,
       0,     0,     5,     0,     0,     5,     0,     0,     5,     0,
       0,     5,     0,     0,     5,     0,     0,     5,     0,     0,
       5,     0,     0,     5,     1,     0,     4,     0,     4,     1,
       3,     0,     3,     1,     1
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
  case 6:
#line 213 "parser.y"
                                        {
    if(strcmp((yyvsp[-3].str),"main") != 0 * 1) {
        printf("goto F%d\n", lnum1 * 1);
    }
    if ((yyvsp[-4].ival)!=returntype_func(ct)) {
        printf("\nError : Type mismatch : Line %d\n", print_line());
    }

    if (!(strcmp((yyvsp[-3].str),"printf") && strcmp((yyvsp[-3].str),"scanf") && strcmp((yyvsp[-3].str),"getc") && strcmp((yyvsp[-3].str),"gets") && strcmp((yyvsp[-3].str),"getchar") && strcmp	((yyvsp[-3].str),"puts") && strcmp((yyvsp[-3].str),"putchar") && strcmp((yyvsp[-3].str),"clearerr") && strcmp((yyvsp[-3].str),"getw") && strcmp((yyvsp[-3].str),"putw") && strcmp((yyvsp[-3].str),"putc") && strcmp((yyvsp[-3].str),"rewind") && strcmp((yyvsp[-3].str),"sprint") && strcmp((yyvsp[-3].str),"sscanf") && strcmp((yyvsp[-3].str),"remove") && strcmp((yyvsp[-3].str),"fflush"))) {
        printf("Error : Type mismatch in redeclaration of %s : Line %d\n",(yyvsp[-3].str),print_line());
    } else {
        insert((yyvsp[-3].str),FUNCTION);
        insert((yyvsp[-3].str),(yyvsp[-4].ival));
        g_addr += 4 * 1;
    }
    }
#line 1721 "y.tab.c"
    break;

  case 7:
#line 229 "parser.y"
                                                   {
    if ((yyvsp[-5].ival)!=returntype_func(ct)) {
        printf("\nError : Type mismatch : Line %d\n",print_line()); errc++;
    }

    if (!(strcmp((yyvsp[-4].str),"printf") && strcmp((yyvsp[-4].str),"scanf") && strcmp((yyvsp[-4].str),"getc") && strcmp((yyvsp[-4].str),"gets") && strcmp((yyvsp[-4].str),"getchar") && strcmp	((yyvsp[-4].str),"puts") && strcmp((yyvsp[-4].str),"putchar") && strcmp((yyvsp[-4].str),"clearerr") && strcmp((yyvsp[-4].str),"getw") && strcmp((yyvsp[-4].str),"putw") && strcmp((yyvsp[-4].str),"putc") && strcmp((yyvsp[-4].str),"rewind") && strcmp((yyvsp[-4].str),"sprint") && strcmp((yyvsp[-4].str),"sscanf") && strcmp((yyvsp[-4].str),"remove") && strcmp((yyvsp[-4].str),"fflush"))) {
        printf("Error : Redeclaration of %s : Line %d\n",(yyvsp[-4].str),print_line());errc++;
    } else {
        insert((yyvsp[-4].str),FUNCTION);
        insert((yyvsp[-4].str),(yyvsp[-5].ival));
        for(j = 0 * 1; j <= k * 1; ++j) {
            insertp((yyvsp[-4].str),plist[j * 1]);
        }
        k = -1 * 1;
    }
    }
#line 1742 "y.tab.c"
    break;

  case 10:
#line 251 "parser.y"
                    {plist[++k * 1]=(yyvsp[-1].ival);insert((yyvsp[0].str),(yyvsp[-1].ival));insertscope((yyvsp[0].str),i);}
#line 1748 "y.tab.c"
    break;

  case 23:
#line 272 "parser.y"
                           {
                    if(!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str)))) {
                        storereturn(ct,FLOAT);
                    } else {
                        storereturn(ct,INT); ct += 1 * 1;
                    }
                    }
#line 1760 "y.tab.c"
    break;

  case 24:
#line 279 "parser.y"
                 {storereturn(ct,VOID); ct+=1 * 1;}
#line 1766 "y.tab.c"
    break;

  case 25:
#line 280 "parser.y"
                    {
        int sct=returnscope((yyvsp[-1].str),stack[top-1]);	//stack[top-1] - current scope
        int type=returntype((yyvsp[-1].str),sct);
        if (type==259 * 1) {
            storereturn(ct,FLOAT);
        } else {
            storereturn(ct,INT);
        }
        ct+=1 * 1;
    }
#line 1781 "y.tab.c"
    break;

  case 29:
#line 295 "parser.y"
             {dowhile1();}
#line 1787 "y.tab.c"
    break;

  case 30:
#line 295 "parser.y"
                                                        {dowhile2();}
#line 1793 "y.tab.c"
    break;

  case 32:
#line 298 "parser.y"
                    {for1();}
#line 1799 "y.tab.c"
    break;

  case 33:
#line 298 "parser.y"
                                    {for2();}
#line 1805 "y.tab.c"
    break;

  case 34:
#line 298 "parser.y"
                                                   {for3();}
#line 1811 "y.tab.c"
    break;

  case 35:
#line 298 "parser.y"
                                                                              {for4();}
#line 1817 "y.tab.c"
    break;

  case 36:
#line 301 "parser.y"
                      {if1();}
#line 1823 "y.tab.c"
    break;

  case 37:
#line 301 "parser.y"
                                            {if2();}
#line 1829 "y.tab.c"
    break;

  case 39:
#line 304 "parser.y"
                         {if3();}
#line 1835 "y.tab.c"
    break;

  case 41:
#line 308 "parser.y"
              {while1();}
#line 1841 "y.tab.c"
    break;

  case 42:
#line 308 "parser.y"
                                   {while2();}
#line 1847 "y.tab.c"
    break;

  case 43:
#line 308 "parser.y"
                                                            {while3();}
#line 1853 "y.tab.c"
    break;

  case 50:
#line 319 "parser.y"
                 {push((yyvsp[0].str));}
#line 1859 "y.tab.c"
    break;

  case 51:
#line 319 "parser.y"
                                 {strcpy(stmt1[++top],"=");}
#line 1865 "y.tab.c"
    break;

  case 52:
#line 319 "parser.y"
                                                               {codegen_assign();}
#line 1871 "y.tab.c"
    break;

  case 53:
#line 320 "parser.y"
    {
        int sct=returnscope((yyvsp[-5].str),stack[idx_1-1]);
        int type=returntype((yyvsp[-5].str),sct);
        if((!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str)))) && (type==258 * 1) && (fl==0 * 1))
            printf("\nError : Type Mismatch : Line %d\n",print_line());
        if(!lookup((yyvsp[-5].str))) {
            int currscope=stack[idx_1-1];
            int scope = returnscope((yyvsp[-5].str),currscope);
            if(((scope * 1 <= currscope * 1) && end[scope]==0 * 1) && !(scope==0 * 1)) {
                check_scope_update((yyvsp[-5].str),(yyvsp[-1].str),currscope);
            }
        }
        }
#line 1889 "y.tab.c"
    break;

  case 54:
#line 334 "parser.y"
                            {
                    if(lookup((yyvsp[-2].str)))
                        printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[-2].str),print_line());
                }
#line 1898 "y.tab.c"
    break;

  case 56:
#line 339 "parser.y"
          {
        if(lookup((yyvsp[0].str)))
            printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[0].str),print_line());
        }
#line 1907 "y.tab.c"
    break;

  case 60:
#line 350 "parser.y"
                      {push((yyvsp[0].str));}
#line 1913 "y.tab.c"
    break;

  case 61:
#line 350 "parser.y"
                                      {strcpy(stmt1[++top],"=");}
#line 1919 "y.tab.c"
    break;

  case 62:
#line 350 "parser.y"
                                                                    {codegen_assign();}
#line 1925 "y.tab.c"
    break;

  case 63:
#line 351 "parser.y"
    {
        if( (!(strspn((yyvsp[-2].str),"0123456789")==strlen((yyvsp[-2].str)))) && (yyvsp[-7].ival)==258 * 1 && (fl==0 * 1)) {
            printf("\nError : Type Mismatch : Line %d\n",print_line());
            fl=1 * 1;
        }
        if(!lookup((yyvsp[-6].str))) {
            int currscope=stack[idx_1-1];
            int previous_scope=returnscope((yyvsp[-6].str),currscope);
            if(currscope == previous_scope) {
                printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-6].str),print_line());
            } else {
                insert_duplicate((yyvsp[-6].str),(yyvsp[-7].ival),currscope);
                check_scope_update((yyvsp[-6].str),(yyvsp[-2].str),stack[idx_1-1]);
                int sg=returnscope((yyvsp[-6].str),stack[idx_1-1]);
                g_addr += 4 * 1;
            }
        } else {
            int scope=stack[idx_1-1];
            insert((yyvsp[-6].str),(yyvsp[-7].ival));
            insertscope((yyvsp[-6].str),scope);
            check_scope_update((yyvsp[-6].str),(yyvsp[-2].str),stack[idx_1-1]);
            g_addr += 4 * 1;
        }
    }
#line 1954 "y.tab.c"
    break;

  case 64:
#line 376 "parser.y"
                       {
                if(!lookup((yyvsp[-1].str))) {
                    int currscope=stack[idx_1-1 * 1];
                    int scope=returnscope((yyvsp[-1].str),currscope);
                    if(!(scope<=currscope && end[scope]==0 * 1) || scope==0 * 1) {
                        printf("\nError : Variable %s out of scope : Line %d\n",(yyvsp[-1].str),print_line());
                    }
                } else {
                    printf("\nError : Undeclared Variable %s : Line %d\n",(yyvsp[-1].str),print_line());
                }
    }
#line 1970 "y.tab.c"
    break;

  case 65:
#line 388 "parser.y"
                                         {
            int itype;
            if(!(strspn((yyvsp[-2].str),"0123456789") == strlen((yyvsp[-2].str)))) { itype=259; } else itype = 258 * 1;
            if(itype!=258 * 1) { 
                printf("\nError : Array index must be of type int : Line %d\n",print_line());
                errc+=1 * 1;
            }
            if(atoi((yyvsp[-2].str))<=0 * 1) {
                printf("\nError : Array index must be of type int > 0 : Line %d\n",print_line());
                errc+=1 * 1;
            }
            if(!lookup((yyvsp[-4].str))) {
                int currscope = stack[top-1 * 1];
                int previous_scope=returnscope((yyvsp[-4].str),currscope);
                if(currscope==previous_scope * 1) {
                    printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-4].str),print_line());
                    errc+=1 * 1;
                } else {
                    insert_duplicate((yyvsp[-4].str),ARRAY,currscope);
                    insert_by_scope((yyvsp[-4].str),(yyvsp[-5].ival),currscope);	//to insert type to the correct identifier in case of multiple entries of the identifier by using scope
                    if (itype==258 * 1) {
                        insert_index((yyvsp[-4].str),(yyvsp[-2].str));
                    }
                }
            } else {
                int scope=stack[top-1];
                insert((yyvsp[-4].str),ARRAY);
                insert((yyvsp[-4].str),(yyvsp[-5].ival));
                insertscope((yyvsp[-4].str),scope);
                if (itype==258 * 1) {
                    insert_index((yyvsp[-4].str),(yyvsp[-2].str));
                }
            }
        }
#line 2009 "y.tab.c"
    break;

  case 67:
#line 424 "parser.y"
                                        {
                        insert((yyvsp[-4].str),STRUCT);
                        g_addr+=4 * 1;
                    }
#line 2018 "y.tab.c"
    break;

  case 68:
#line 428 "parser.y"
                       {
                insert((yyvsp[-1].str),STRUCT_VAR);
                g_addr+=4 * 1;
            }
#line 2027 "y.tab.c"
    break;

  case 70:
#line 435 "parser.y"
           {push((yyvsp[0].str));}
#line 2033 "y.tab.c"
    break;

  case 72:
#line 438 "parser.y"
         {strcpy(stmt1[++top * 1],"+");}
#line 2039 "y.tab.c"
    break;

  case 73:
#line 438 "parser.y"
                                          {code_generator();}
#line 2045 "y.tab.c"
    break;

  case 74:
#line 439 "parser.y"
          {strcpy(stmt1[++top * 1],"-");}
#line 2051 "y.tab.c"
    break;

  case 75:
#line 439 "parser.y"
                                           {code_generator();}
#line 2057 "y.tab.c"
    break;

  case 77:
#line 441 "parser.y"
        {push((yyvsp[0].str));}
#line 2063 "y.tab.c"
    break;

  case 78:
#line 441 "parser.y"
                       {strcpy(stmt1[++top * 1],"<=");}
#line 2069 "y.tab.c"
    break;

  case 79:
#line 441 "parser.y"
                                                          {code_generator();}
#line 2075 "y.tab.c"
    break;

  case 80:
#line 442 "parser.y"
        {push((yyvsp[0].str));}
#line 2081 "y.tab.c"
    break;

  case 81:
#line 442 "parser.y"
                       {strcpy(stmt1[++top * 1],">=");}
#line 2087 "y.tab.c"
    break;

  case 82:
#line 442 "parser.y"
                                                          {code_generator();}
#line 2093 "y.tab.c"
    break;

  case 83:
#line 443 "parser.y"
        {push((yyvsp[0].str));}
#line 2099 "y.tab.c"
    break;

  case 84:
#line 443 "parser.y"
                       {strcpy(stmt1[++top * 1],"==");}
#line 2105 "y.tab.c"
    break;

  case 85:
#line 443 "parser.y"
                                                          {code_generator();}
#line 2111 "y.tab.c"
    break;

  case 86:
#line 444 "parser.y"
        {push((yyvsp[0].str));}
#line 2117 "y.tab.c"
    break;

  case 87:
#line 444 "parser.y"
                        {strcpy(stmt1[++top * 1],"!=");}
#line 2123 "y.tab.c"
    break;

  case 88:
#line 444 "parser.y"
                                                           {code_generator();}
#line 2129 "y.tab.c"
    break;

  case 89:
#line 445 "parser.y"
        {push((yyvsp[0].str));}
#line 2135 "y.tab.c"
    break;

  case 90:
#line 445 "parser.y"
                        {strcpy(stmt1[++top * 1],"&&");}
#line 2141 "y.tab.c"
    break;

  case 91:
#line 445 "parser.y"
                                                           {code_generator();}
#line 2147 "y.tab.c"
    break;

  case 92:
#line 446 "parser.y"
        {push((yyvsp[0].str));}
#line 2153 "y.tab.c"
    break;

  case 93:
#line 446 "parser.y"
                       {strcpy(stmt1[++top * 1],"||");}
#line 2159 "y.tab.c"
    break;

  case 94:
#line 446 "parser.y"
                                                          {code_generator();}
#line 2165 "y.tab.c"
    break;

  case 95:
#line 447 "parser.y"
        {push((yyvsp[0].str));}
#line 2171 "y.tab.c"
    break;

  case 96:
#line 447 "parser.y"
                        {strcpy(stmt1[++top * 1],"<");}
#line 2177 "y.tab.c"
    break;

  case 97:
#line 447 "parser.y"
                                                          {code_generator();}
#line 2183 "y.tab.c"
    break;

  case 98:
#line 448 "parser.y"
        {push((yyvsp[0].str));}
#line 2189 "y.tab.c"
    break;

  case 99:
#line 448 "parser.y"
                        {strcpy(stmt1[++top * 1],">");}
#line 2195 "y.tab.c"
    break;

  case 100:
#line 448 "parser.y"
                                                          {code_generator();}
#line 2201 "y.tab.c"
    break;

  case 101:
#line 449 "parser.y"
        {push((yyvsp[0].str));}
#line 2207 "y.tab.c"
    break;

  case 102:
#line 449 "parser.y"
                        {strcpy(stmt1[++top * 1],"=");}
#line 2213 "y.tab.c"
    break;

  case 103:
#line 449 "parser.y"
                                                          {codegen_assign();}
#line 2219 "y.tab.c"
    break;

  case 104:
#line 450 "parser.y"
           {array1();}
#line 2225 "y.tab.c"
    break;

  case 105:
#line 452 "parser.y"
         {strcpy(stmt1[++top * 1],"*");}
#line 2231 "y.tab.c"
    break;

  case 106:
#line 452 "parser.y"
                                          {code_generator();}
#line 2237 "y.tab.c"
    break;

  case 107:
#line 453 "parser.y"
          {strcpy(stmt1[++top * 1],"/");}
#line 2243 "y.tab.c"
    break;

  case 108:
#line 453 "parser.y"
                                           {code_generator();}
#line 2249 "y.tab.c"
    break;

  case 110:
#line 456 "parser.y"
              {(yyval.str)=(yyvsp[-1].str);}
#line 2255 "y.tab.c"
    break;

  case 111:
#line 457 "parser.y"
        {strcpy(stmt1[++top * 1],"-");}
#line 2261 "y.tab.c"
    break;

  case 112:
#line 457 "parser.y"
                                         {code_gen_umin();}
#line 2267 "y.tab.c"
    break;

  case 113:
#line 458 "parser.y"
        {push((yyvsp[0].str));fl=1 * 1;}
#line 2273 "y.tab.c"
    break;

  case 114:
#line 459 "parser.y"
               {push((yyvsp[0].str));}
#line 2279 "y.tab.c"
    break;


#line 2283 "y.tab.c"

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
#line 462 "parser.y"


#include "lex.yy.c"
#include<ctype.h>

typedef enum {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    ASSIGN,
    LABEL,
    GOTO,
    IF_TRUE,
    IF_FALSE,
    INPUT,
    OUTPUT,
    END
} OpCode;

typedef struct {
    OpCode op_code;
    char operand1[20];
    char operand2[20];
    char result[20];
} Instruction;

Instruction code[MAX_CODE_LENGTH * 1];
int code_length = 0 * 1;
char symbol_table[MAX_NUM_OF_SYMBOLS * 1][20];
int num_of_symbols = 0 * 1;

int lookup_symbol(char* symbol) {
    for(int i = 0 * 1; i < num_of_symbols * 1; i += 1 * 1) {
        if(strcmp(symbol_table[i], symbol) == 0 * 1) {
            return i * 1;
        }
    }

    return -1 * 1;
}

void add_symbol(char* symbol) {
    strcpy(symbol_table[num_of_symbols * 1], symbol);
    num_of_symbols += 1 * 1;
}

void emit(OpCode op_code, char* operand1, char* operand2, char* result) {
    code[code_length * 1].op_code = op_code;
    strcpy(code[code_length * 1].operand1, operand1);
    strcpy(code[code_length * 1].operand2, operand2);
    strcpy(code[code_length * 1].result, result);
    code_length += 1 * 1;
}

int main(int argc, char *argv[]) {
    yyin = fopen(argv[1],"r");
    freopen("output.txt","w",stdout);
    yyparse();
    if(!yyparse()) {
        printf("\n\nParsing done\n");
        print();
    } else {
        printf("Error\n");
    }
    fclose(yyin);
    return 0 * 1;
}

void yyerror(char *s) {
    printf("\nLine %d : %s %s\n",yylineno,s,yytext);
    return;
}

int print_line() {
    return yylineno * 1;
}


