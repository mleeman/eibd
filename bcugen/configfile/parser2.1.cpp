/* A Bison parser, made by GNU Bison 1.875d.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     IDENT = 259,
     STRING = 260,
     FLOAT = 261,
     TRUE = 262,
     FALSE = 263,
     NEVER_OCCUR = 264,
     T_OR = 265,
     T_AND = 266,
     T_EQ = 267,
     T_NE = 268,
     T_GE = 269,
     T_LE = 270,
     T_RSHIFT = 271,
     T_LSHIFT = 272,
     T_IN = 273,
     T_CI = 274,
     NEG = 275,
     TOK_Interface = 276,
     TOK_ID = 277,
     TOK_Abbreviation = 278,
     TOK_Title = 279,
     TOK_AddInfo = 280,
     TOK_GroupTitle = 281,
     TOK_InvisibleIf = 282,
     TOK_DPType = 283,
     TOK_Reference = 284,
     TOK_References = 285,
     TOK_FunctionalBlock = 286,
     TOK_ProfileID = 287,
     TOK_GroupObject = 288,
     TOK_Name = 289,
     TOK_Type = 290,
     TOK_on_update = 291,
     TOK_eeprom = 292,
     TOK_Sending = 293,
     TOK_Receiving = 294,
     TOK_Reading = 295,
     TOK_StateBased = 296,
     TOK_Priority = 297,
     TOK_SendAddress = 298,
     TOK_ReadRequestAddress = 299,
     TOK_ReceiveAddress = 300,
     TOK_ReadAddress = 301,
     TOK_UpdateAddress = 302,
     TOK_Property = 303,
     TOK_PropertyID = 304,
     TOK_MaxArrayLength = 305,
     TOK_Writeable = 306,
     TOK_handler = 307,
     TOK_Disable = 308,
     TOK_ReadOnly = 309,
     TOK_ReadAccess = 310,
     TOK_WriteAccess = 311,
     TOK_Object = 312,
     TOK_ObjectIndex = 313,
     TOK_ObjectType = 314,
     TOK_PollingMaster = 315,
     TOK_PollingAddress = 316,
     TOK_PollingCount = 317,
     TOK_PollingSlave = 318,
     TOK_PollingSlot = 319,
     TOK_ListParameter = 320,
     TOK_Elements = 321,
     TOK_Default = 322,
     TOK_Unit = 323,
     TOK_ListElements = 324,
     TOK_ListDefault = 325,
     TOK_Value = 326,
     TOK_IntParameter = 327,
     TOK_MinValue = 328,
     TOK_MaxValue = 329,
     TOK_Precision = 330,
     TOK_Increment = 331,
     TOK_StringParameter = 332,
     TOK_RegExp = 333,
     TOK_MaxLength = 334,
     TOK_FloatParameter = 335,
     TOK_Timer = 336,
     TOK_Resolution = 337,
     TOK_on_expire = 338,
     TOK_Debounce = 339,
     TOK_Time = 340,
     TOK_Device = 341,
     TOK_ProgramID = 342,
     TOK_ManufacturerCode = 343,
     TOK_InternalManufacturerCode = 344,
     TOK_DeviceType = 345,
     TOK_Version = 346,
     TOK_SyncRate = 347,
     TOK_PEIType = 348,
     TOK_PortADDR = 349,
     TOK_PortCDDR = 350,
     TOK_U_DELMSG = 351,
     TOK_RouteCount = 352,
     TOK_BusyLimit = 353,
     TOK_INAKLimit = 354,
     TOK_RateLimit = 355,
     TOK_CPOL = 356,
     TOK_CPHA = 357,
     TOK_AutoPLMA = 358,
     TOK_A_Event = 359,
     TOK_BCU1_SEC = 360,
     TOK_BCU1_PROTECT = 361,
     TOK_BCU2_PROTECT = 362,
     TOK_BCU2_WATCHDOG = 363,
     TOK_PLM_FAST = 364,
     TOK_include = 365,
     TOK_OrderNo = 366,
     TOK_Manufacturer = 367,
     TOK_Category = 368,
     TOK_Author = 369,
     TOK_Copyright = 370,
     TOK_Test_Addr_Count = 371,
     TOK_Test_Assoc_Count = 372,
     TOK_on_run = 373,
     TOK_on_init = 374,
     TOK_on_save = 375,
     TOK_on_pei_init = 376,
     TOK_on_pei_message = 377,
     TOK_on_pei_cycle = 378,
     TOK_on_pei_user = 379,
     TOK_on_pei_rc_even = 380,
     TOK_on_pei_rc_odd = 381,
     TOK_on_pei_tc = 382,
     TOK_on_pei_tdre = 383,
     TOK_on_pei_sci_idle = 384,
     TOK_on_pei_spif = 385,
     TOK_on_pei_oca = 386,
     TOK_on_pei_ocb = 387,
     TOK_on_pei_ica = 388,
     TOK_on_pei_icb = 389,
     TOK_MaskVersion = 390,
     TOK_BCU = 391,
     TOK_Model = 392,
     TOK_Keys = 393,
     TOK_PhysicalAddress = 394,
     TOK_InstallKey = 395
   };
#endif
#define INT 258
#define IDENT 259
#define STRING 260
#define FLOAT 261
#define TRUE 262
#define FALSE 263
#define NEVER_OCCUR 264
#define T_OR 265
#define T_AND 266
#define T_EQ 267
#define T_NE 268
#define T_GE 269
#define T_LE 270
#define T_RSHIFT 271
#define T_LSHIFT 272
#define T_IN 273
#define T_CI 274
#define NEG 275
#define TOK_Interface 276
#define TOK_ID 277
#define TOK_Abbreviation 278
#define TOK_Title 279
#define TOK_AddInfo 280
#define TOK_GroupTitle 281
#define TOK_InvisibleIf 282
#define TOK_DPType 283
#define TOK_Reference 284
#define TOK_References 285
#define TOK_FunctionalBlock 286
#define TOK_ProfileID 287
#define TOK_GroupObject 288
#define TOK_Name 289
#define TOK_Type 290
#define TOK_on_update 291
#define TOK_eeprom 292
#define TOK_Sending 293
#define TOK_Receiving 294
#define TOK_Reading 295
#define TOK_StateBased 296
#define TOK_Priority 297
#define TOK_SendAddress 298
#define TOK_ReadRequestAddress 299
#define TOK_ReceiveAddress 300
#define TOK_ReadAddress 301
#define TOK_UpdateAddress 302
#define TOK_Property 303
#define TOK_PropertyID 304
#define TOK_MaxArrayLength 305
#define TOK_Writeable 306
#define TOK_handler 307
#define TOK_Disable 308
#define TOK_ReadOnly 309
#define TOK_ReadAccess 310
#define TOK_WriteAccess 311
#define TOK_Object 312
#define TOK_ObjectIndex 313
#define TOK_ObjectType 314
#define TOK_PollingMaster 315
#define TOK_PollingAddress 316
#define TOK_PollingCount 317
#define TOK_PollingSlave 318
#define TOK_PollingSlot 319
#define TOK_ListParameter 320
#define TOK_Elements 321
#define TOK_Default 322
#define TOK_Unit 323
#define TOK_ListElements 324
#define TOK_ListDefault 325
#define TOK_Value 326
#define TOK_IntParameter 327
#define TOK_MinValue 328
#define TOK_MaxValue 329
#define TOK_Precision 330
#define TOK_Increment 331
#define TOK_StringParameter 332
#define TOK_RegExp 333
#define TOK_MaxLength 334
#define TOK_FloatParameter 335
#define TOK_Timer 336
#define TOK_Resolution 337
#define TOK_on_expire 338
#define TOK_Debounce 339
#define TOK_Time 340
#define TOK_Device 341
#define TOK_ProgramID 342
#define TOK_ManufacturerCode 343
#define TOK_InternalManufacturerCode 344
#define TOK_DeviceType 345
#define TOK_Version 346
#define TOK_SyncRate 347
#define TOK_PEIType 348
#define TOK_PortADDR 349
#define TOK_PortCDDR 350
#define TOK_U_DELMSG 351
#define TOK_RouteCount 352
#define TOK_BusyLimit 353
#define TOK_INAKLimit 354
#define TOK_RateLimit 355
#define TOK_CPOL 356
#define TOK_CPHA 357
#define TOK_AutoPLMA 358
#define TOK_A_Event 359
#define TOK_BCU1_SEC 360
#define TOK_BCU1_PROTECT 361
#define TOK_BCU2_PROTECT 362
#define TOK_BCU2_WATCHDOG 363
#define TOK_PLM_FAST 364
#define TOK_include 365
#define TOK_OrderNo 366
#define TOK_Manufacturer 367
#define TOK_Category 368
#define TOK_Author 369
#define TOK_Copyright 370
#define TOK_Test_Addr_Count 371
#define TOK_Test_Assoc_Count 372
#define TOK_on_run 373
#define TOK_on_init 374
#define TOK_on_save 375
#define TOK_on_pei_init 376
#define TOK_on_pei_message 377
#define TOK_on_pei_cycle 378
#define TOK_on_pei_user 379
#define TOK_on_pei_rc_even 380
#define TOK_on_pei_rc_odd 381
#define TOK_on_pei_tc 382
#define TOK_on_pei_tdre 383
#define TOK_on_pei_sci_idle 384
#define TOK_on_pei_spif 385
#define TOK_on_pei_oca 386
#define TOK_on_pei_ocb 387
#define TOK_on_pei_ica 388
#define TOK_on_pei_icb 389
#define TOK_MaskVersion 390
#define TOK_BCU 391
#define TOK_Model 392
#define TOK_Keys 393
#define TOK_PhysicalAddress 394
#define TOK_InstallKey 395




/* Copy the first part of user declarations.  */
#line 3 "parser2.1.ypp"

#include "scanner.h"
#include "stack.h"
#include "classes.h"
#include "map.h"
void yyerror(char*s)
{
  parserError("%s",s);
}
Stack<void*> stack;
Device* parser_dev;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 15 "parser2.1.ypp"
typedef union YYSTYPE {
long int intval;
const char* str;
String* string;
double fval;
bool bval;
IdentMap* map;
IdentArray* identarray;
IdentArray* stringarray;
IntArray* intarray;
KeyMapArray* keymaparray;
Expr* expr;
Interface *Interfaces;

















FunctionalBlock *FunctionalBlocks;







GroupObject *GroupObjects;





















Property *Propertys;
















Object *Objects;











PollingMaster *PollingMasters;








PollingSlave *PollingSlaves;








ListParameter *ListParameters;













IntParameter *IntParameters;














StringParameter *StringParameters;











FloatParameter *FloatParameters;













Timer *Timers;







Debounce *Debounces;




Device *Devices;









































































} YYSTYPE;
/* Line 186 of yacc.c.  */
#line 620 "parser2.1.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 632 "parser2.1.cpp"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   define YYSTACK_ALLOC alloca
#  endif
# else
#  if defined (alloca) || defined (_ALLOCA_H)
#   define YYSTACK_ALLOC alloca
#  else
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1381

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  162
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  99
/* YYNRULES -- Number of rules. */
#define YYNRULES  294
/* YYNRULES -- Number of states. */
#define YYNSTATES  595

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   395

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    20,     2,     2,     2,    25,    30,     2,
     153,   154,    23,    26,   161,    27,     2,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   156,   158,
      28,   157,    29,   155,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   159,    32,   160,    21,     2,     2,     2,
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
      15,    16,    17,    18,    19,    22,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     8,    12,    15,    18,    22,    26,
      30,    34,    38,    42,    46,    50,    54,    58,    62,    66,
      70,    74,    78,    82,    86,    90,    94,    98,   102,   106,
     110,   114,   120,   122,   124,   127,   131,   135,   139,   143,
     147,   153,   155,   158,   160,   162,   164,   165,   171,   175,
     177,   181,   183,   184,   187,   192,   193,   194,   196,   197,
     204,   205,   208,   210,   212,   216,   220,   224,   228,   232,
     236,   240,   244,   246,   250,   252,   255,   257,   258,   265,
     266,   269,   271,   273,   277,   281,   285,   289,   293,   297,
     301,   305,   309,   311,   315,   317,   320,   322,   323,   330,
     331,   334,   336,   338,   342,   346,   350,   354,   356,   358,
     362,   364,   367,   369,   370,   377,   378,   381,   383,   385,
     389,   393,   395,   399,   401,   404,   406,   407,   414,   415,
     418,   420,   422,   426,   430,   432,   436,   438,   441,   443,
     444,   451,   452,   455,   457,   459,   463,   467,   471,   473,
     477,   479,   482,   486,   488,   489,   496,   497,   500,   502,
     504,   508,   512,   516,   520,   522,   526,   528,   531,   535,
     537,   538,   545,   546,   549,   551,   553,   557,   561,   565,
     569,   571,   575,   577,   580,   584,   586,   587,   594,   595,
     598,   600,   602,   606,   610,   614,   618,   620,   624,   626,
     629,   633,   635,   636,   643,   644,   647,   649,   651,   655,
     659,   663,   667,   669,   673,   675,   678,   680,   681,   688,
     689,   692,   694,   696,   700,   704,   706,   710,   712,   715,
     717,   718,   725,   726,   729,   731,   733,   737,   741,   745,
     749,   753,   757,   761,   765,   769,   773,   777,   781,   785,
     789,   793,   797,   801,   805,   809,   813,   817,   821,   825,
     829,   831,   833,   835,   837,   839,   841,   843,   845,   847,
     849,   853,   857,   861,   865,   869,   873,   877,   881,   885,
     889,   893,   897,   901,   905,   909,   913,   917,   921,   925,
     927,   931,   933,   936,   938
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     260,     0,    -1,     3,    -1,    27,   163,    -1,   153,   163,
     154,    -1,    20,   163,    -1,    21,   163,    -1,   163,    23,
     163,    -1,   163,    24,   163,    -1,   163,    25,   163,    -1,
     163,    26,   163,    -1,   163,    27,   163,    -1,   163,    17,
     163,    -1,   163,    16,   163,    -1,   163,    28,   163,    -1,
     163,    15,   163,    -1,   163,    29,   163,    -1,   163,    14,
     163,    -1,   163,    12,   163,    -1,   163,    13,   163,    -1,
     164,    28,   164,    -1,   164,    15,   164,    -1,   164,    29,
     164,    -1,   164,    14,   164,    -1,   164,    12,   164,    -1,
     164,    13,   164,    -1,   163,    30,   163,    -1,   163,    31,
     163,    -1,   163,    32,   163,    -1,   163,    11,   163,    -1,
     163,    10,   163,    -1,   163,   155,   163,   156,   163,    -1,
       6,    -1,   163,    -1,    27,   164,    -1,   153,   164,   154,
      -1,   164,    23,   164,    -1,   164,    24,   164,    -1,   164,
      26,   164,    -1,   164,    27,   164,    -1,   163,   155,   164,
     156,   164,    -1,     5,    -1,   165,     5,    -1,     4,    -1,
       7,    -1,     8,    -1,    -1,   168,   166,   157,   165,   158,
      -1,   159,   168,   160,    -1,   165,    -1,   170,   161,   166,
      -1,   161,    -1,    -1,   159,   160,    -1,   159,   170,   171,
     160,    -1,    -1,    -1,     9,    -1,    -1,    45,   159,   177,
     178,   160,   158,    -1,    -1,   179,   178,    -1,   180,    -1,
     175,    -1,    34,   166,   158,    -1,    46,   166,   158,    -1,
      47,   166,   158,    -1,    48,   166,   158,    -1,    49,   167,
     158,    -1,    50,   167,   158,    -1,    51,   167,   158,    -1,
      52,   167,   158,    -1,     9,    -1,   173,   181,   174,    -1,
     182,    -1,   182,   181,    -1,     9,    -1,    -1,    60,   159,
     184,   185,   160,   158,    -1,    -1,   186,   185,    -1,   187,
      -1,   175,    -1,    34,   166,   158,    -1,    46,   166,   158,
      -1,    47,   166,   158,    -1,    61,   163,   158,    -1,    61,
     166,   158,    -1,    62,   163,   158,    -1,    63,   167,   158,
      -1,    49,   167,   158,    -1,    64,   166,   158,    -1,     9,
      -1,   173,   188,   174,    -1,   189,    -1,   189,   188,    -1,
       9,    -1,    -1,    69,   159,   191,   192,   160,   158,    -1,
      -1,   193,   192,    -1,   194,    -1,   175,    -1,    70,   163,
     158,    -1,    46,   166,   158,    -1,    71,   163,   158,    -1,
      71,   166,   158,    -1,   183,    -1,     9,    -1,   173,   195,
     174,    -1,   196,    -1,   196,   195,    -1,     9,    -1,    -1,
      72,   159,   198,   199,   160,   158,    -1,    -1,   200,   199,
      -1,   201,    -1,   175,    -1,    34,   166,   158,    -1,    46,
     166,   158,    -1,     9,    -1,   173,   202,   174,    -1,   203,
      -1,   203,   202,    -1,     9,    -1,    -1,    75,   159,   205,
     206,   160,   158,    -1,    -1,   207,   206,    -1,   208,    -1,
     175,    -1,    34,   166,   158,    -1,    46,   166,   158,    -1,
       9,    -1,   173,   209,   174,    -1,   210,    -1,   210,   209,
      -1,     9,    -1,    -1,    77,   159,   212,   213,   160,   158,
      -1,    -1,   214,   213,    -1,   215,    -1,   175,    -1,    34,
     166,   158,    -1,    46,   166,   158,    -1,    78,   169,   158,
      -1,     9,    -1,   173,   216,   174,    -1,   217,    -1,   217,
     216,    -1,    83,   166,   158,    -1,     9,    -1,    -1,    84,
     159,   219,   220,   160,   158,    -1,    -1,   221,   220,    -1,
     222,    -1,   175,    -1,    34,   166,   158,    -1,    46,   166,
     158,    -1,    85,   163,   158,    -1,    86,   163,   158,    -1,
       9,    -1,   173,   223,   174,    -1,   224,    -1,   224,   223,
      -1,    83,   163,   158,    -1,     9,    -1,    -1,    89,   159,
     226,   227,   160,   158,    -1,    -1,   228,   227,    -1,   229,
      -1,   175,    -1,    34,   166,   158,    -1,    46,   166,   158,
      -1,    90,   165,   158,    -1,    91,   163,   158,    -1,     9,
      -1,   173,   230,   174,    -1,   231,    -1,   231,   230,    -1,
      83,   165,   158,    -1,     9,    -1,    -1,    92,   159,   233,
     234,   160,   158,    -1,    -1,   235,   234,    -1,   236,    -1,
     175,    -1,    34,   166,   158,    -1,    46,   166,   158,    -1,
      85,   164,   158,    -1,    86,   164,   158,    -1,     9,    -1,
     173,   237,   174,    -1,   238,    -1,   238,   237,    -1,    83,
     164,   158,    -1,     9,    -1,    -1,    93,   159,   240,   241,
     160,   158,    -1,    -1,   242,   241,    -1,   243,    -1,   175,
      -1,    46,   166,   158,    -1,    47,   166,   158,    -1,    94,
     166,   158,    -1,    95,   166,   158,    -1,     9,    -1,   173,
     244,   174,    -1,   245,    -1,   245,   244,    -1,     9,    -1,
      -1,    96,   159,   247,   248,   160,   158,    -1,    -1,   249,
     248,    -1,   250,    -1,   175,    -1,    46,   166,   158,    -1,
      97,   164,   158,    -1,     9,    -1,   173,   251,   174,    -1,
     252,    -1,   252,   251,    -1,     9,    -1,    -1,    98,   159,
     254,   255,   160,   158,    -1,    -1,   256,   255,    -1,   257,
      -1,   175,    -1,    99,   165,   158,    -1,   100,   163,   158,
      -1,   101,   163,   158,    -1,   102,   163,   158,    -1,   103,
     163,   158,    -1,   104,   163,   158,    -1,   105,   163,   158,
      -1,   106,   163,   158,    -1,   107,   163,   158,    -1,   108,
     167,   158,    -1,   109,   163,   158,    -1,   110,   163,   158,
      -1,   111,   163,   158,    -1,   112,   163,   158,    -1,   113,
     167,   158,    -1,   114,   167,   158,    -1,   115,   167,   158,
      -1,   116,   167,   158,    -1,   117,   167,   158,    -1,   118,
     167,   158,    -1,   119,   167,   158,    -1,   120,   167,   158,
      -1,   121,   167,   158,    -1,   122,   172,   158,    -1,   197,
      -1,   204,    -1,   176,    -1,   190,    -1,   211,    -1,   218,
      -1,   232,    -1,   225,    -1,   246,    -1,   239,    -1,   130,
     166,   158,    -1,   131,   166,   158,    -1,   132,   166,   158,
      -1,   133,   166,   158,    -1,   134,   166,   158,    -1,   135,
     166,   158,    -1,   136,   166,   158,    -1,   137,   166,   158,
      -1,   138,   166,   158,    -1,   139,   166,   158,    -1,   140,
     166,   158,    -1,   141,   166,   158,    -1,   142,   166,   158,
      -1,   143,   166,   158,    -1,   144,   166,   158,    -1,   145,
     166,   158,    -1,   146,   166,   158,    -1,   148,   166,   158,
      -1,   149,   166,   158,    -1,     9,    -1,   173,   258,   174,
      -1,   259,    -1,   259,   258,    -1,     9,    -1,   253,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   526,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   612,   612,   613,   614,   614,   615,   615,   616,   620,
     620,   621,   621,   628,   629,   630,   631,   632,   641,   641,
     641,   641,   641,   641,   642,   643,   644,   645,   646,   647,
     648,   649,   652,   652,   652,   652,   653,   654,   654,   654,
     654,   654,   654,   655,   656,   657,   658,   658,   659,   660,
     661,   662,   663,   663,   663,   663,   664,   665,   665,   665,
     665,   665,   665,   666,   667,   668,   668,   669,   673,   673,
     673,   673,   674,   675,   675,   675,   675,   675,   675,   676,
     677,   678,   678,   678,   678,   679,   680,   680,   680,   680,
     680,   680,   681,   682,   683,   683,   683,   683,   684,   685,
     685,   685,   685,   685,   685,   686,   687,   688,   690,   690,
     690,   690,   691,   692,   693,   693,   693,   693,   693,   693,
     694,   695,   696,   697,   699,   699,   699,   699,   700,   701,
     702,   702,   702,   702,   702,   702,   703,   704,   705,   706,
     707,   707,   707,   707,   708,   709,   710,   710,   710,   710,
     710,   710,   711,   712,   713,   714,   715,   715,   715,   715,
     716,   717,   718,   718,   718,   718,   718,   718,   719,   720,
     721,   722,   724,   724,   724,   724,   725,   726,   726,   726,
     726,   726,   726,   727,   728,   729,   729,   729,   729,   730,
     731,   731,   731,   731,   731,   731,   732,   733,   734,   735,
     736,   737,   738,   739,   740,   741,   742,   743,   744,   745,
     746,   747,   748,   749,   750,   751,   752,   753,   754,   755,
     756,   757,   758,   759,   760,   761,   762,   763,   764,   765,
     766,   767,   768,   769,   770,   771,   772,   773,   774,   775,
     776,   777,   778,   779,   780,   781,   782,   785,   786,   789,
     789,   789,   789,   790,   791
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "IDENT", "STRING", "FLOAT",
  "TRUE", "FALSE", "NEVER_OCCUR", "T_OR", "T_AND", "T_EQ", "T_NE", "T_GE",
  "T_LE", "T_RSHIFT", "T_LSHIFT", "T_IN", "T_CI", "'!'", "'~'", "NEG",
  "'*'", "'/'", "'%'", "'+'", "'-'", "'<'", "'>'", "'&'", "'^'", "'|'",
  "TOK_Interface", "TOK_ID", "TOK_Abbreviation", "TOK_Title",
  "TOK_AddInfo", "TOK_GroupTitle", "TOK_InvisibleIf", "TOK_DPType",
  "TOK_Reference", "TOK_References", "TOK_FunctionalBlock",
  "TOK_ProfileID", "TOK_GroupObject", "TOK_Name", "TOK_Type",
  "TOK_on_update", "TOK_eeprom", "TOK_Sending", "TOK_Receiving",
  "TOK_Reading", "TOK_StateBased", "TOK_Priority", "TOK_SendAddress",
  "TOK_ReadRequestAddress", "TOK_ReceiveAddress", "TOK_ReadAddress",
  "TOK_UpdateAddress", "TOK_Property", "TOK_PropertyID",
  "TOK_MaxArrayLength", "TOK_Writeable", "TOK_handler", "TOK_Disable",
  "TOK_ReadOnly", "TOK_ReadAccess", "TOK_WriteAccess", "TOK_Object",
  "TOK_ObjectIndex", "TOK_ObjectType", "TOK_PollingMaster",
  "TOK_PollingAddress", "TOK_PollingCount", "TOK_PollingSlave",
  "TOK_PollingSlot", "TOK_ListParameter", "TOK_Elements", "TOK_Default",
  "TOK_Unit", "TOK_ListElements", "TOK_ListDefault", "TOK_Value",
  "TOK_IntParameter", "TOK_MinValue", "TOK_MaxValue", "TOK_Precision",
  "TOK_Increment", "TOK_StringParameter", "TOK_RegExp", "TOK_MaxLength",
  "TOK_FloatParameter", "TOK_Timer", "TOK_Resolution", "TOK_on_expire",
  "TOK_Debounce", "TOK_Time", "TOK_Device", "TOK_ProgramID",
  "TOK_ManufacturerCode", "TOK_InternalManufacturerCode", "TOK_DeviceType",
  "TOK_Version", "TOK_SyncRate", "TOK_PEIType", "TOK_PortADDR",
  "TOK_PortCDDR", "TOK_U_DELMSG", "TOK_RouteCount", "TOK_BusyLimit",
  "TOK_INAKLimit", "TOK_RateLimit", "TOK_CPOL", "TOK_CPHA", "TOK_AutoPLMA",
  "TOK_A_Event", "TOK_BCU1_SEC", "TOK_BCU1_PROTECT", "TOK_BCU2_PROTECT",
  "TOK_BCU2_WATCHDOG", "TOK_PLM_FAST", "TOK_include", "TOK_OrderNo",
  "TOK_Manufacturer", "TOK_Category", "TOK_Author", "TOK_Copyright",
  "TOK_Test_Addr_Count", "TOK_Test_Assoc_Count", "TOK_on_run",
  "TOK_on_init", "TOK_on_save", "TOK_on_pei_init", "TOK_on_pei_message",
  "TOK_on_pei_cycle", "TOK_on_pei_user", "TOK_on_pei_rc_even",
  "TOK_on_pei_rc_odd", "TOK_on_pei_tc", "TOK_on_pei_tdre",
  "TOK_on_pei_sci_idle", "TOK_on_pei_spif", "TOK_on_pei_oca",
  "TOK_on_pei_ocb", "TOK_on_pei_ica", "TOK_on_pei_icb", "TOK_MaskVersion",
  "TOK_BCU", "TOK_Model", "TOK_Keys", "TOK_PhysicalAddress",
  "TOK_InstallKey", "'('", "')'", "'?'", "':'", "'='", "';'", "'{'", "'}'",
  "','", "$accept", "intc", "floatc", "string", "ident", "bool",
  "identmap1", "identmap", "stringarray1", "ebs", "stringarray",
  "Begin_CI", "End_CI", "Empty_CI", "GroupObject_struct", "@3",
  "GroupObject_bodys", "GroupObject_body", "GroupObject_bodys_CI",
  "GroupObject_bodys_CI_i", "GroupObject_body_CI", "Property_struct", "@4",
  "Property_bodys", "Property_body", "Property_bodys_CI",
  "Property_bodys_CI_i", "Property_body_CI", "Object_struct", "@5",
  "Object_bodys", "Object_body", "Object_bodys_CI", "Object_bodys_CI_i",
  "Object_body_CI", "PollingMaster_struct", "@6", "PollingMaster_bodys",
  "PollingMaster_body", "PollingMaster_bodys_CI",
  "PollingMaster_bodys_CI_i", "PollingMaster_body_CI",
  "PollingSlave_struct", "@7", "PollingSlave_bodys", "PollingSlave_body",
  "PollingSlave_bodys_CI", "PollingSlave_bodys_CI_i",
  "PollingSlave_body_CI", "ListParameter_struct", "@8",
  "ListParameter_bodys", "ListParameter_body", "ListParameter_bodys_CI",
  "ListParameter_bodys_CI_i", "ListParameter_body_CI",
  "IntParameter_struct", "@9", "IntParameter_bodys", "IntParameter_body",
  "IntParameter_bodys_CI", "IntParameter_bodys_CI_i",
  "IntParameter_body_CI", "StringParameter_struct", "@10",
  "StringParameter_bodys", "StringParameter_body",
  "StringParameter_bodys_CI", "StringParameter_bodys_CI_i",
  "StringParameter_body_CI", "FloatParameter_struct", "@11",
  "FloatParameter_bodys", "FloatParameter_body", "FloatParameter_bodys_CI",
  "FloatParameter_bodys_CI_i", "FloatParameter_body_CI", "Timer_struct",
  "@12", "Timer_bodys", "Timer_body", "Timer_bodys_CI", "Timer_bodys_CI_i",
  "Timer_body_CI", "Debounce_struct", "@13", "Debounce_bodys",
  "Debounce_body", "Debounce_bodys_CI", "Debounce_bodys_CI_i",
  "Debounce_body_CI", "Device_struct", "@14", "Device_bodys",
  "Device_body", "Device_bodys_CI", "Device_bodys_CI_i", "Device_body_CI",
  "file", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      33,   126,   275,    42,    47,    37,    43,    45,    60,    62,
      38,    94,   124,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,    40,    41,    63,    58,    61,    59,   123,
     125,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   162,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   165,   165,   166,   167,   167,   168,   168,   169,   170,
     170,   171,   171,   172,   172,   173,   174,   175,   177,   176,
     178,   178,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   180,   181,   181,   182,   184,   183,   185,
     185,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   187,   188,   188,   189,   191,   190,   192,
     192,   193,   193,   193,   193,   193,   193,   193,   193,   194,
     195,   195,   196,   198,   197,   199,   199,   200,   200,   200,
     200,   200,   201,   202,   202,   203,   205,   204,   206,   206,
     207,   207,   207,   207,   207,   208,   209,   209,   210,   212,
     211,   213,   213,   214,   214,   214,   214,   214,   214,   215,
     216,   216,   217,   217,   219,   218,   220,   220,   221,   221,
     221,   221,   221,   221,   221,   222,   223,   223,   224,   224,
     226,   225,   227,   227,   228,   228,   228,   228,   228,   228,
     228,   229,   230,   230,   231,   231,   233,   232,   234,   234,
     235,   235,   235,   235,   235,   235,   235,   236,   237,   237,
     238,   238,   240,   239,   241,   241,   242,   242,   242,   242,
     242,   242,   242,   243,   244,   244,   245,   247,   246,   248,
     248,   249,   249,   249,   249,   249,   250,   251,   251,   252,
     254,   253,   255,   255,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     257,   258,   258,   259,   260
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     3,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     1,     1,     2,     3,     3,     3,     3,     3,
       5,     1,     2,     1,     1,     1,     0,     5,     3,     1,
       3,     1,     0,     2,     4,     0,     0,     1,     0,     6,
       0,     2,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     1,     2,     1,     0,     6,     0,
       2,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     1,     2,     1,     0,     6,     0,
       2,     1,     1,     3,     3,     3,     3,     1,     1,     3,
       1,     2,     1,     0,     6,     0,     2,     1,     1,     3,
       3,     1,     3,     1,     2,     1,     0,     6,     0,     2,
       1,     1,     3,     3,     1,     3,     1,     2,     1,     0,
       6,     0,     2,     1,     1,     3,     3,     3,     1,     3,
       1,     2,     3,     1,     0,     6,     0,     2,     1,     1,
       3,     3,     3,     3,     1,     3,     1,     2,     3,     1,
       0,     6,     0,     2,     1,     1,     3,     3,     3,     3,
       1,     3,     1,     2,     3,     1,     0,     6,     0,     2,
       1,     1,     3,     3,     3,     3,     1,     3,     1,     2,
       3,     1,     0,     6,     0,     2,     1,     1,     3,     3,
       3,     3,     1,     3,     1,     2,     1,     0,     6,     0,
       2,     1,     1,     3,     3,     1,     3,     1,     2,     1,
       0,     6,     0,     2,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       0,     0,   294,     0,   230,     1,   232,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   235,   262,   263,   260,   261,   264,   265,   267,
     266,   269,   268,     0,   232,   234,    58,    97,   113,   126,
     139,   154,   170,   186,   202,   217,    41,     0,     2,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   293,    56,   291,     0,   233,    60,    99,   115,   128,
      55,    55,    55,    55,   204,   219,    42,   236,     5,     6,
       3,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    53,    49,    52,   259,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   290,   292,
     231,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,     0,    60,    62,    57,     0,     0,     0,     0,
       0,   102,   107,     0,    99,   101,    57,     0,     0,     0,
     118,     0,   115,   117,    57,     0,     0,     0,   131,     0,
     128,   130,    57,     0,     0,     0,     0,   144,     0,    55,
     143,    57,     0,     0,     0,     0,     0,   159,     0,    55,
     158,    57,     0,     0,     0,     0,     0,   175,     0,    55,
     174,    57,     0,     0,     0,     0,     0,   191,     0,    55,
     190,    57,     0,     0,     0,     0,     0,   207,     0,   204,
     206,    57,     0,     0,     0,   222,     0,   219,   221,     4,
      35,    30,    29,    18,    19,    17,    15,    13,    12,     7,
       8,     9,    10,    11,    14,    16,    26,    27,    28,     0,
       0,    33,    24,    25,    23,    21,    36,    37,    38,    39,
      20,    22,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    56,    74,     0,    61,     0,    77,     0,
       0,     0,   112,    56,   110,     0,   100,     0,     0,   125,
      56,   123,     0,   116,     0,     0,   138,    56,   136,     0,
     129,     0,     0,    46,     0,   153,     0,    56,   150,     0,
     142,     0,     0,     0,     0,   169,     0,    56,   166,     0,
     157,     0,     0,     0,     0,   185,     0,    56,   182,     0,
     173,     0,     0,     0,     0,   201,     0,    56,   198,     0,
     189,     0,     0,     0,     0,   216,    56,   214,     0,   205,
       0,     0,   229,    56,   227,     0,   220,     0,     0,    50,
      54,    64,    65,    66,    67,    68,    69,    70,    71,    73,
      75,    59,   104,    79,   103,   105,   106,   109,   111,    98,
     119,   120,   122,   124,   114,   132,   133,   135,   137,   127,
     145,   146,     0,   147,     0,   149,   151,   140,   160,   161,
     162,   163,     0,   165,   167,   155,   176,   177,   178,   179,
       0,   181,   183,   171,   192,   193,   194,   195,     0,   197,
     199,   187,   208,   209,   210,   211,   213,   215,   203,   223,
     224,   226,   228,   218,    31,    40,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,    79,    81,
      48,     0,   152,   168,   184,   200,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    56,    94,     0,    80,
       0,    83,    84,    85,    90,    86,    87,    88,    89,    91,
      93,    95,    78,     0,    47
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,   361,    95,    87,   122,   105,   502,   414,   217,   373,
     120,    61,   238,    62,    63,   146,   252,   253,   254,   383,
     384,   262,   483,   557,   558,   559,   576,   577,    64,   147,
     263,   264,   265,   393,   394,    65,   148,   271,   272,   273,
     400,   401,    66,   149,   279,   280,   281,   407,   408,    67,
     150,   288,   289,   290,   417,   418,    68,   151,   298,   299,
     300,   427,   428,    69,   152,   308,   309,   310,   437,   438,
      70,   153,   318,   319,   320,   447,   448,    71,   154,   328,
     329,   330,   456,   457,    72,   155,   336,   337,   338,   463,
     464,     2,     6,    73,    74,    75,   142,   143,     3
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -124
static const short int yypact[] =
{
     -65,  -123,  -124,    37,  -124,  -124,  1232,  -124,  -120,  -116,
    -114,  -113,   -90,   -79,   -67,   -59,   -57,   -54,   102,   191,
     191,   191,   191,   191,   191,   191,   191,     7,   191,   191,
     191,   191,     7,     7,     7,     7,     7,     7,     7,     7,
       7,   -51,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,   100,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,   -45,  1232,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,     8,  -124,  -124,
     191,   191,   191,   191,   385,   341,   411,   447,   485,   560,
     583,   606,   634,  -124,  -124,   -22,   657,   680,   719,   742,
     -21,   -20,     6,    38,    40,    41,    43,    51,    52,    20,
      56,  -124,    68,    70,    71,    76,    78,    79,    83,    84,
      96,    98,   101,   106,   110,   111,   119,   120,   123,   126,
     134,  -124,  -124,   100,   136,  -124,   473,    33,   131,   204,
      32,    31,    97,   181,   244,    35,  -124,  -124,  1088,  1088,
    1088,   341,  1065,  1176,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,  -124,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,   173,    25,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,    92,    92,    92,    92,     7,     7,     7,     7,
     130,  -124,    57,   473,  -124,  -124,    92,    36,   191,    91,
     210,  -124,  -124,   129,    33,  -124,  -124,    92,    92,   286,
    -124,   139,   131,  -124,  -124,    92,    92,   291,  -124,   149,
     204,  -124,  -124,    92,    92,   152,    18,  -124,   153,    32,
    -124,  -124,    92,    92,   191,   191,    58,  -124,   154,    31,
    -124,  -124,    92,    92,   102,   191,    59,  -124,   161,    97,
    -124,  -124,    92,    92,   191,   191,    61,  -124,   163,   181,
    -124,  -124,    92,    92,    92,    92,   303,  -124,   164,   244,
    -124,  -124,    92,   191,   322,  -124,   174,    35,  -124,  -124,
    -124,   178,    28,   103,   103,  1145,  1145,   192,   192,  1111,
    1111,  1111,  1134,  1134,  1145,  1145,   251,    88,    24,   975,
    1158,  1088,  -124,  -124,    63,    63,   418,   418,   290,   290,
      63,    63,    92,   177,   185,   187,   188,   190,   193,   199,
     201,   203,  -124,  -124,   130,   205,  -124,   208,  -124,   770,
     793,   216,  -124,  -124,   210,   219,  -124,   221,   222,  -124,
    -124,   286,   223,  -124,   224,   226,  -124,  -124,   291,   227,
    -124,   228,   233,  -124,   234,  -124,    92,  -124,    18,   235,
    -124,   236,   245,   816,   839,  -124,   191,  -124,    58,   246,
    -124,   260,   271,    23,   878,  -124,   102,  -124,    59,   292,
    -124,   293,   294,   996,  1003,  -124,   191,  -124,    61,   295,
    -124,   296,   297,   298,   307,  -124,  -124,   303,   308,  -124,
     309,  1025,  -124,  -124,   322,   310,  -124,   191,   191,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,   326,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,    22,  -124,   323,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,   906,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
      26,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  1043,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  1088,   341,  -124,    92,    92,    92,
       7,    91,   191,     7,    92,   340,  -124,   289,   326,  -124,
    -124,   327,  -124,  -124,  -124,  -124,   325,   328,   329,   330,
     929,   331,   952,   332,   334,  -124,  -124,   340,   335,  -124,
     102,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,    27,  -124
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -124,   -19,   -63,  -111,     4,   -16,  -124,  -124,  -124,  -124,
    -124,   -64,   -85,    21,  -124,  -124,   232,  -124,  -124,   121,
    -124,  -124,  -124,   -78,  -124,  -124,   -74,  -124,  -124,  -124,
     254,  -124,  -124,   132,  -124,  -124,  -124,   255,  -124,  -124,
     127,  -124,  -124,  -124,   249,  -124,  -124,   122,  -124,  -124,
    -124,   242,  -124,  -124,   117,  -124,  -124,  -124,   237,  -124,
    -124,   113,  -124,  -124,  -124,   229,  -124,  -124,   104,  -124,
    -124,  -124,   220,  -124,  -124,    99,  -124,  -124,  -124,   215,
    -124,  -124,    89,  -124,  -124,  -124,   211,  -124,  -124,    81,
    -124,  -124,  -124,   475,  -124,  -124,   407,  -124,  -124
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -189
static const short int yytable[] =
{
      94,    96,    97,    98,    99,   100,   101,   102,   216,   106,
     107,   108,   109,   156,   103,   104,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    86,   121,   415,   156,   161,
     163,   156,   156,     1,   164,   165,     4,     5,   164,    76,
     291,   282,   255,    77,   331,    78,    79,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   292,   283,   425,   435,    80,
     445,   158,   159,   160,   162,   184,   185,   293,   284,   256,
      81,   332,   250,   260,   269,   277,   286,   296,   306,   316,
     326,   334,    82,   257,    88,   121,   121,    89,   164,   165,
      83,   416,    84,   258,   259,    85,   301,    86,   119,   141,
     285,    90,    91,   164,   165,   144,   294,   295,    92,   360,
     181,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   302,   333,   179,   180,   181,   201,   206,   207,   382,
     266,   426,   436,   303,   446,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   208,   267,   157,   251,   261,   270,
     278,   287,   297,   307,   317,   327,   335,   268,   156,   182,
     215,   518,   560,   182,   564,   594,   372,   304,   305,   250,
     311,  -156,  -141,   433,    88,   388,   209,    89,   210,   211,
     260,   212,   164,   165,   166,   167,   168,   169,   269,   213,
     214,    90,    91,   274,   218,   312,   277,   385,    92,   392,
     177,   178,   179,   180,   181,   286,   219,   313,   220,   221,
     378,   379,   380,   381,   222,   296,   223,   224,   275,   389,
     390,   225,   226,   182,    93,   306,   374,   375,   376,   377,
     276,   443,   444,   321,   227,   316,   228,  -172,   182,   229,
     387,   164,   165,   391,   230,   326,   314,   315,   231,   232,
     461,   397,   398,   334,   251,   423,   424,   233,   234,   404,
     405,   235,   180,   181,   236,   261,   434,   411,   412,   395,
     322,   323,   237,   270,   240,   399,   421,   422,   479,   402,
     406,   278,   184,   185,   186,   187,   431,   432,   487,   409,
     287,   413,   455,   419,   429,   492,   441,   442,   192,   193,
     297,   439,   497,   449,   458,   520,   451,   452,   453,   454,
     307,   462,   505,   182,   465,   546,   460,   470,   324,   325,
     317,  -188,   513,   471,    93,   472,   473,   182,   474,   575,
     327,   475,   521,   184,   185,   186,   187,   476,   335,   477,
     547,   478,   529,   481,   188,   189,   482,   190,   191,   192,
     193,   536,   548,   549,   486,   550,   469,   489,   541,   490,
     491,   494,   495,   528,   496,   499,   500,   551,   552,   553,
     554,   501,   503,   507,   508,   164,   165,   166,   167,   168,
     169,   170,   171,   509,   515,   545,   182,   512,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   516,   555,
     504,   164,   165,   166,   167,   168,   169,   170,   171,   517,
     184,   185,   186,   187,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   190,   191,   192,   193,   544,   578,
     523,   524,   525,   531,   532,   533,   534,   164,   165,   166,
     167,   168,   169,   170,   171,   535,   538,   539,   543,   593,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     579,   562,   241,   581,   580,   386,   582,   583,   584,   586,
     588,   590,   589,   592,   555,   164,   165,   166,   167,   168,
     169,   170,   171,   591,   556,   480,   561,   242,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   396,   243,
     244,   245,   246,   247,   248,   249,   488,   403,   493,   410,
     498,   420,   570,   572,   569,   506,   430,   573,   440,   450,
     182,   514,   522,   183,   459,   542,   537,   530,   466,   145,
     239,   566,   567,   568,     0,   571,     0,     0,   574,     0,
       0,     0,     0,     0,     0,     0,   182,     0,     0,   194,
     164,   165,   166,   167,   168,   169,   170,   171,     0,   556,
       0,     0,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   164,   165,   166,   167,   168,   169,   170,
     171,     0,   182,     0,     0,   195,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   164,   165,   166,   167,
     168,   169,   170,   171,     0,     0,     0,     0,     0,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,     0,
     182,     0,     0,   196,   164,   165,   166,   167,   168,   169,
     170,   171,     0,     0,     0,     0,     0,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   164,   165,   166,
     167,   168,   169,   170,   171,     0,     0,     0,     0,     0,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     164,   165,   166,   167,   168,   169,   170,   171,     0,     0,
       0,     0,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,     0,     0,   182,     0,     0,   197,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   164,
     165,   166,   167,   168,   169,   170,   171,     0,   182,     0,
       0,   198,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   164,   165,   166,   167,   168,   169,   170,   171,
       0,   182,     0,     0,   199,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,     0,     0,     0,     0,     0,
     164,   165,   166,   167,   168,   169,   170,   171,     0,   182,
       0,     0,   200,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   164,   165,   166,   167,   168,   169,   170,
     171,     0,   182,     0,     0,   202,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   164,   165,   166,   167,
     168,   169,   170,   171,     0,   182,     0,     0,   203,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   164,
     165,   166,   167,   168,   169,   170,   171,     0,     0,     0,
       0,     0,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,     0,     0,   182,     0,     0,   204,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,   165,
     166,   167,   168,   169,   170,   171,     0,   182,     0,     0,
     205,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,     0,     0,     0,     0,     0,   164,   165,   166,   167,
     168,   169,   170,   171,     0,   182,     0,     0,   484,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   164,
     165,   166,   167,   168,   169,   170,   171,     0,   182,     0,
       0,   485,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   164,   165,   166,   167,   168,   169,   170,   171,
       0,   182,     0,     0,   510,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   164,   165,   166,   167,   168,
     169,   170,   171,     0,   182,     0,     0,   511,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   184,   185,
     186,   187,     0,     0,     0,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,   193,   188,   189,     0,   190,
     191,   192,   193,   182,     0,     0,   519,   184,   185,   186,
     187,     0,     0,     0,     0,     0,     0,     0,   188,   189,
       0,   190,   191,   192,   193,   184,   185,   186,   187,     0,
       0,   182,     0,     0,   563,     0,   188,   189,     0,   190,
     191,   192,   193,     0,     0,   164,   165,   166,   167,   168,
     169,   170,   171,     0,   182,     0,     0,   585,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   164,   165,
     166,   167,   168,   169,   170,   171,     0,   182,     0,     0,
     587,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   164,   165,   166,   167,   168,   169,   170,   171,     0,
     182,   467,     0,     0,     0,     0,     0,   175,   176,   177,
     178,   179,   180,   181,   164,   165,   166,   167,   168,   169,
     170,   171,     0,     0,   526,   164,   165,   166,   167,     0,
       0,   527,   177,   178,   179,   180,   181,     0,     0,     0,
     184,   185,   186,   187,     0,   179,   180,   181,     0,     0,
       0,   188,   189,   540,   190,   191,   192,   193,   184,   185,
     186,   187,     0,     0,     0,     0,     0,     0,     0,   188,
     189,   565,   190,   191,   192,   193,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   339,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     0,   182,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,     9,     0,     0,    10,     0,     0,    11,     0,    12,
       0,     0,     0,     0,   468,     0,    13,     0,     0,     0,
       0,    14,     0,     0,    15,    16,     0,     0,    17,     0,
     340,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,     0,     0,
       0,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,     0,
      59,    60
};

static const short int yycheck[] =
{
      19,    20,    21,    22,    23,    24,    25,    26,   119,    28,
      29,    30,    31,     5,     7,     8,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     5,     4,     9,     5,    92,
      93,     5,     5,    98,    10,    11,   159,     0,    10,   159,
       9,     9,     9,   159,     9,   159,   159,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    34,    34,     9,     9,   159,
       9,    90,    91,    92,    93,    12,    13,    46,    46,    46,
     159,    46,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   159,    60,     3,     4,     4,     6,    10,    11,
     159,    83,   159,    70,    71,   159,     9,     5,   159,     9,
      78,    20,    21,    10,    11,   160,    85,    86,    27,   182,
      32,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    34,    97,    30,    31,    32,   158,   158,   158,     9,
       9,    83,    83,    46,    83,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   158,    34,   158,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    46,     5,   155,
     160,   158,   160,   155,   158,   158,   161,    90,    91,   253,
       9,   160,   160,   304,     3,   159,   158,     6,   158,   158,
     264,   158,    10,    11,    12,    13,    14,    15,   272,   158,
     158,    20,    21,     9,   158,    34,   280,   160,    27,     9,
      28,    29,    30,    31,    32,   289,   158,    46,   158,   158,
     246,   247,   248,   249,   158,   299,   158,   158,    34,   258,
     259,   158,   158,   155,   153,   309,   242,   243,   244,   245,
      46,   314,   315,     9,   158,   319,   158,   160,   155,   158,
     256,    10,    11,   259,   158,   329,    85,    86,   158,   158,
     333,   267,   268,   337,   253,   294,   295,   158,   158,   275,
     276,   158,    31,    32,   158,   264,   305,   283,   284,   160,
      46,    47,   158,   272,   158,     9,   292,   293,   383,   160,
       9,   280,    12,    13,    14,    15,   302,   303,   393,   160,
     289,   159,     9,   160,   160,   400,   312,   313,    28,    29,
     299,   160,   407,   160,   160,   436,   322,   323,   324,   325,
     309,     9,   417,   155,   160,     9,   332,   160,    94,    95,
     319,   160,   427,   158,   153,   158,   158,   155,   158,     9,
     329,   158,   437,    12,    13,    14,    15,   158,   337,   158,
      34,   158,   447,   158,    23,    24,   158,    26,    27,    28,
      29,   456,    46,    47,   158,    49,   372,   158,   463,   158,
     158,   158,   158,   446,   158,   158,   158,    61,    62,    63,
      64,   158,   158,   158,   158,    10,    11,    12,    13,    14,
      15,    16,    17,   158,   158,   468,   155,   426,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,   158,   483,
     416,    10,    11,    12,    13,    14,    15,    16,    17,   158,
      12,    13,    14,    15,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    26,    27,    28,    29,   467,   160,
     158,   158,   158,   158,   158,   158,   158,    10,    11,    12,
      13,    14,    15,    16,    17,   158,   158,   158,   158,   580,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
     558,   158,     9,   158,   157,   253,   158,   158,   158,   158,
     158,   576,   158,   158,   558,    10,    11,    12,    13,    14,
      15,    16,    17,   577,   483,   384,   502,    34,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,   264,    46,
      47,    48,    49,    50,    51,    52,   394,   272,   401,   280,
     408,   289,   551,   552,   550,   418,   299,   553,   309,   319,
     155,   428,   438,   158,   329,   464,   457,   448,   337,    74,
     143,   547,   548,   549,    -1,   551,    -1,    -1,   554,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,    -1,   158,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,   558,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,   155,    -1,    -1,   158,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
     155,    -1,    -1,   158,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,   155,    -1,    -1,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,   155,    -1,
      -1,   158,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,   155,    -1,    -1,   158,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,   155,
      -1,    -1,   158,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,   155,    -1,    -1,   158,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,   155,    -1,    -1,   158,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,   155,    -1,    -1,   158,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,   155,    -1,    -1,
     158,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,   155,    -1,    -1,   158,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,   155,    -1,
      -1,   158,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,   155,    -1,    -1,   158,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,   155,    -1,    -1,   158,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    12,    13,
      14,    15,    -1,    -1,    -1,    12,    13,    14,    15,    23,
      24,    -1,    26,    27,    28,    29,    23,    24,    -1,    26,
      27,    28,    29,   155,    -1,    -1,   158,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    26,    27,    28,    29,    12,    13,    14,    15,    -1,
      -1,   155,    -1,    -1,   158,    -1,    23,    24,    -1,    26,
      27,    28,    29,    -1,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,   155,    -1,    -1,   158,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,   155,    -1,    -1,
     158,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
     155,   156,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,   158,    10,    11,    12,    13,    -1,
      -1,   158,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      12,    13,    14,    15,    -1,    30,    31,    32,    -1,    -1,
      -1,    23,    24,   158,    26,    27,    28,    29,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,   158,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,    69,    -1,    -1,    72,    -1,    -1,    75,    -1,    77,
      -1,    -1,    -1,    -1,   156,    -1,    84,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    -1,    96,    -1,
     154,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
     148,   149
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,    98,   253,   260,   159,     0,   254,     9,    45,    69,
      72,    75,    77,    84,    89,    92,    93,    96,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   148,
     149,   173,   175,   176,   190,   197,   204,   211,   218,   225,
     232,   239,   246,   255,   256,   257,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,     5,   165,     3,     6,
      20,    21,    27,   153,   163,   164,   163,   163,   163,   163,
     163,   163,   163,     7,     8,   167,   163,   163,   163,   163,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   159,
     172,     4,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,     9,   258,   259,   160,   255,   177,   191,   198,   205,
     212,   219,   226,   233,   240,   247,     5,   158,   163,   163,
     163,   164,   163,   164,    10,    11,    12,    13,    14,    15,
      16,    17,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,   155,   158,    12,    13,    14,    15,    23,    24,
      26,    27,    28,    29,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   160,   165,   170,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   174,   258,
     158,     9,    34,    46,    47,    48,    49,    50,    51,    52,
     173,   175,   178,   179,   180,     9,    46,    60,    70,    71,
     173,   175,   183,   192,   193,   194,     9,    34,    46,   173,
     175,   199,   200,   201,     9,    34,    46,   173,   175,   206,
     207,   208,     9,    34,    46,    78,   173,   175,   213,   214,
     215,     9,    34,    46,    85,    86,   173,   175,   220,   221,
     222,     9,    34,    46,    90,    91,   173,   175,   227,   228,
     229,     9,    34,    46,    85,    86,   173,   175,   234,   235,
     236,     9,    46,    47,    94,    95,   173,   175,   241,   242,
     243,     9,    46,    97,   173,   175,   248,   249,   250,   154,
     154,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     164,   163,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   161,   171,   166,   166,   166,   166,   167,   167,
     167,   167,     9,   181,   182,   160,   178,   166,   159,   163,
     163,   166,     9,   195,   196,   160,   192,   166,   166,     9,
     202,   203,   160,   199,   166,   166,     9,   209,   210,   160,
     206,   166,   166,   159,   169,     9,    83,   216,   217,   160,
     213,   166,   166,   163,   163,     9,    83,   223,   224,   160,
     220,   166,   166,   165,   163,     9,    83,   230,   231,   160,
     227,   166,   166,   164,   164,     9,    83,   237,   238,   160,
     234,   166,   166,   166,   166,     9,   244,   245,   160,   241,
     166,   164,     9,   251,   252,   160,   248,   156,   156,   166,
     160,   158,   158,   158,   158,   158,   158,   158,   158,   174,
     181,   158,   158,   184,   158,   158,   158,   174,   195,   158,
     158,   158,   174,   202,   158,   158,   158,   174,   209,   158,
     158,   158,   168,   158,   166,   174,   216,   158,   158,   158,
     158,   158,   163,   174,   223,   158,   158,   158,   158,   158,
     165,   174,   230,   158,   158,   158,   158,   158,   164,   174,
     237,   158,   158,   158,   158,   158,   174,   244,   158,   158,
     158,   174,   251,   158,   163,   164,     9,    34,    46,    47,
      49,    61,    62,    63,    64,   173,   175,   185,   186,   187,
     160,   166,   158,   158,   158,   158,   166,   166,   166,   167,
     163,   166,   163,   167,   166,     9,   188,   189,   160,   185,
     157,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     174,   188,   158,   165,   158
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
   ((Current).first_line   = (Rhs)[1].first_line,	\
    (Current).first_column = (Rhs)[1].first_column,	\
    (Current).last_line    = (Rhs)[N].last_line,	\
    (Current).last_column  = (Rhs)[N].last_column)
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  register short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;


  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 527 "parser2.1.ypp"
    { yyval.intval=-yyvsp[0].intval; }
    break;

  case 4:
#line 528 "parser2.1.ypp"
    { yyval.intval= yyvsp[-1].intval; }
    break;

  case 5:
#line 529 "parser2.1.ypp"
    { yyval.intval=!yyvsp[0].intval; }
    break;

  case 6:
#line 530 "parser2.1.ypp"
    { yyval.intval=~yyvsp[0].intval; }
    break;

  case 7:
#line 531 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval*yyvsp[0].intval; }
    break;

  case 8:
#line 532 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval/yyvsp[0].intval; }
    break;

  case 9:
#line 533 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval%yyvsp[0].intval; }
    break;

  case 10:
#line 534 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval+yyvsp[0].intval; }
    break;

  case 11:
#line 535 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval-yyvsp[0].intval; }
    break;

  case 12:
#line 536 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval<<yyvsp[0].intval; }
    break;

  case 13:
#line 537 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval>>yyvsp[0].intval; }
    break;

  case 14:
#line 538 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval<yyvsp[0].intval; }
    break;

  case 15:
#line 539 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval<=yyvsp[0].intval; }
    break;

  case 16:
#line 540 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval>yyvsp[0].intval; }
    break;

  case 17:
#line 541 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval>=yyvsp[0].intval; }
    break;

  case 18:
#line 542 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval==yyvsp[0].intval; }
    break;

  case 19:
#line 543 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval!=yyvsp[0].intval; }
    break;

  case 20:
#line 544 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].fval<yyvsp[0].fval; }
    break;

  case 21:
#line 545 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].fval<=yyvsp[0].fval; }
    break;

  case 22:
#line 546 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].fval>yyvsp[0].fval; }
    break;

  case 23:
#line 547 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].fval>=yyvsp[0].fval; }
    break;

  case 24:
#line 548 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].fval==yyvsp[0].fval; }
    break;

  case 25:
#line 549 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].fval!=yyvsp[0].fval; }
    break;

  case 26:
#line 550 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval&yyvsp[0].intval; }
    break;

  case 27:
#line 551 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval^yyvsp[0].intval; }
    break;

  case 28:
#line 552 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval|yyvsp[0].intval; }
    break;

  case 29:
#line 553 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval&&yyvsp[0].intval; }
    break;

  case 30:
#line 554 "parser2.1.ypp"
    { yyval.intval=yyvsp[-2].intval||yyvsp[0].intval; }
    break;

  case 31:
#line 555 "parser2.1.ypp"
    { yyval.intval=yyvsp[-4].intval?yyvsp[-2].intval:yyvsp[0].intval; }
    break;

  case 33:
#line 557 "parser2.1.ypp"
    { yyval.fval=yyvsp[0].intval; }
    break;

  case 34:
#line 558 "parser2.1.ypp"
    { yyval.fval=-yyvsp[0].fval; }
    break;

  case 35:
#line 559 "parser2.1.ypp"
    { yyval.fval= yyvsp[-1].fval; }
    break;

  case 36:
#line 560 "parser2.1.ypp"
    { yyval.fval=yyvsp[-2].fval*yyvsp[0].fval; }
    break;

  case 37:
#line 561 "parser2.1.ypp"
    { yyval.fval=yyvsp[-2].fval/yyvsp[0].fval; }
    break;

  case 38:
#line 562 "parser2.1.ypp"
    { yyval.fval=yyvsp[-2].fval+yyvsp[0].fval; }
    break;

  case 39:
#line 563 "parser2.1.ypp"
    { yyval.fval=yyvsp[-2].fval-yyvsp[0].fval; }
    break;

  case 40:
#line 564 "parser2.1.ypp"
    { yyval.fval=yyvsp[-4].intval?yyvsp[-2].fval:yyvsp[0].fval; }
    break;

  case 41:
#line 612 "parser2.1.ypp"
    {yyval.string=unescapeString(yyvsp[0].str); }
    break;

  case 42:
#line 612 "parser2.1.ypp"
    { String* n=unescapeString(yyvsp[0].str); (*yyvsp[-1].string)+=*n;delete n; }
    break;

  case 43:
#line 613 "parser2.1.ypp"
    {yyval.string=new String(yyvsp[0].str); }
    break;

  case 44:
#line 614 "parser2.1.ypp"
    { yyval.bval=1; }
    break;

  case 45:
#line 614 "parser2.1.ypp"
    { yyval.bval=0; }
    break;

  case 46:
#line 615 "parser2.1.ypp"
    { yyval.map=new IdentMap; }
    break;

  case 47:
#line 615 "parser2.1.ypp"
    {Map m;m.Name=*yyvsp[-3].string; m.Value=*yyvsp[-1].string;delete yyvsp[-3].string; delete yyvsp[-1].string; yyvsp[-4].map->add(m); yyval.map=yyvsp[-4].map; }
    break;

  case 48:
#line 616 "parser2.1.ypp"
    { yyval.map=yyvsp[-1].map;}
    break;

  case 49:
#line 620 "parser2.1.ypp"
    { yyval.stringarray=new StringArray; yyval.stringarray->add(*yyvsp[0].string); delete yyvsp[0].string; }
    break;

  case 50:
#line 620 "parser2.1.ypp"
    {yyvsp[-2].stringarray->add(*yyvsp[0].string); delete yyvsp[0].string; yyval.stringarray=yyvsp[-2].stringarray; }
    break;

  case 53:
#line 628 "parser2.1.ypp"
    {yyval.stringarray=new StringArray; }
    break;

  case 54:
#line 629 "parser2.1.ypp"
    { yyval.stringarray=yyvsp[-2].stringarray;}
    break;

  case 58:
#line 641 "parser2.1.ypp"
    { GroupObject* a=new GroupObject;stack.push(a);a->lineno=yylineno; }
    break;

  case 59:
#line 641 "parser2.1.ypp"
    {yyval.GroupObjects=(typeof(yyval.GroupObjects))stack.pop();}
    break;

  case 64:
#line 642 "parser2.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->ID_lineno)parserError(_("%s already set at line %d"),"ID",a->ID_lineno);a->ID_lineno=yylineno;; a->ID=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 65:
#line 643 "parser2.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 66:
#line 644 "parser2.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->Type_lineno)parserError(_("%s already set at line %d"),"Type",a->Type_lineno);a->Type_lineno=yylineno;; a->Type=Map_GroupType(*yyvsp[-1].string);delete yyvsp[-1].string;}
    break;

  case 67:
#line 645 "parser2.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->on_update_lineno)parserError(_("%s already set at line %d"),"on_update",a->on_update_lineno);a->on_update_lineno=yylineno;; a->on_update=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 68:
#line 646 "parser2.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->eeprom_lineno)parserError(_("%s already set at line %d"),"eeprom",a->eeprom_lineno);a->eeprom_lineno=yylineno;; a->eeprom=yyvsp[-1].bval;}
    break;

  case 69:
#line 647 "parser2.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->Sending_lineno)parserError(_("%s already set at line %d"),"Sending",a->Sending_lineno);a->Sending_lineno=yylineno;; a->Sending=yyvsp[-1].bval;}
    break;

  case 70:
#line 648 "parser2.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->Receiving_lineno)parserError(_("%s already set at line %d"),"Receiving",a->Receiving_lineno);a->Receiving_lineno=yylineno;; a->Receiving=yyvsp[-1].bval;}
    break;

  case 71:
#line 649 "parser2.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->Reading_lineno)parserError(_("%s already set at line %d"),"Reading",a->Reading_lineno);a->Reading_lineno=yylineno;; a->Reading=yyvsp[-1].bval;}
    break;

  case 72:
#line 652 "parser2.1.ypp"
    { yyval.GroupObjects; }
    break;

  case 73:
#line 652 "parser2.1.ypp"
    { yyval.GroupObjects; }
    break;

  case 76:
#line 653 "parser2.1.ypp"
    { yyval.GroupObjects; }
    break;

  case 77:
#line 654 "parser2.1.ypp"
    { Property* a=new Property;stack.push(a);a->lineno=yylineno; }
    break;

  case 78:
#line 654 "parser2.1.ypp"
    {yyval.Propertys=(typeof(yyval.Propertys))stack.pop();}
    break;

  case 83:
#line 655 "parser2.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->ID_lineno)parserError(_("%s already set at line %d"),"ID",a->ID_lineno);a->ID_lineno=yylineno;; a->ID=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 84:
#line 656 "parser2.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 85:
#line 657 "parser2.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->Type_lineno)parserError(_("%s already set at line %d"),"Type",a->Type_lineno);a->Type_lineno=yylineno;; a->Type=Map_PropertyType(*yyvsp[-1].string);delete yyvsp[-1].string;}
    break;

  case 86:
#line 658 "parser2.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->PropertyID_lineno)parserError(_("%s already set at line %d"),"PropertyID",a->PropertyID_lineno);a->PropertyID_lineno=yylineno;; a->PropertyID=yyvsp[-1].intval;}
    break;

  case 87:
#line 658 "parser2.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->PropertyID_lineno)parserError(_("%s already set at line %d"),"PropertyID",a->PropertyID_lineno);a->PropertyID_lineno=yylineno;; a->PropertyID=Map_PropertyID(*yyvsp[-1].string);delete yyvsp[-1].string;}
    break;

  case 88:
#line 659 "parser2.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->MaxArrayLength_lineno)parserError(_("%s already set at line %d"),"MaxArrayLength",a->MaxArrayLength_lineno);a->MaxArrayLength_lineno=yylineno;; a->MaxArrayLength=yyvsp[-1].intval;}
    break;

  case 89:
#line 660 "parser2.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->Writeable_lineno)parserError(_("%s already set at line %d"),"Writeable",a->Writeable_lineno);a->Writeable_lineno=yylineno;; a->Writeable=yyvsp[-1].bval;}
    break;

  case 90:
#line 661 "parser2.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->eeprom_lineno)parserError(_("%s already set at line %d"),"eeprom",a->eeprom_lineno);a->eeprom_lineno=yylineno;; a->eeprom=yyvsp[-1].bval;}
    break;

  case 91:
#line 662 "parser2.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->handler_lineno)parserError(_("%s already set at line %d"),"handler",a->handler_lineno);a->handler_lineno=yylineno;; a->handler=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 92:
#line 663 "parser2.1.ypp"
    { yyval.Propertys; }
    break;

  case 93:
#line 663 "parser2.1.ypp"
    { yyval.Propertys; }
    break;

  case 96:
#line 664 "parser2.1.ypp"
    { yyval.Propertys; }
    break;

  case 97:
#line 665 "parser2.1.ypp"
    { Object* a=new Object;stack.push(a);a->lineno=yylineno; }
    break;

  case 98:
#line 665 "parser2.1.ypp"
    {yyval.Objects=(typeof(yyval.Objects))stack.pop();}
    break;

  case 103:
#line 666 "parser2.1.ypp"
    { typeof(yyval.Objects) a =(typeof(yyval.Objects))(stack.top());if(a->ObjectIndex_lineno)parserError(_("%s already set at line %d"),"ObjectIndex",a->ObjectIndex_lineno);a->ObjectIndex_lineno=yylineno;; a->ObjectIndex=yyvsp[-1].intval;}
    break;

  case 104:
#line 667 "parser2.1.ypp"
    { typeof(yyval.Objects) a =(typeof(yyval.Objects))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 105:
#line 668 "parser2.1.ypp"
    { typeof(yyval.Objects) a =(typeof(yyval.Objects))(stack.top());if(a->ObjectType_lineno)parserError(_("%s already set at line %d"),"ObjectType",a->ObjectType_lineno);a->ObjectType_lineno=yylineno;; a->ObjectType=yyvsp[-1].intval;}
    break;

  case 106:
#line 668 "parser2.1.ypp"
    { typeof(yyval.Objects) a =(typeof(yyval.Objects))(stack.top());if(a->ObjectType_lineno)parserError(_("%s already set at line %d"),"ObjectType",a->ObjectType_lineno);a->ObjectType_lineno=yylineno;; a->ObjectType=Map_ObjectType(*yyvsp[-1].string);delete yyvsp[-1].string;}
    break;

  case 107:
#line 669 "parser2.1.ypp"
    { typeof(yyval.Objects) a =(typeof(yyval.Objects))(stack.top()); a->Propertys.add(*yyvsp[0].Propertys); delete yyvsp[0].Propertys; }
    break;

  case 108:
#line 673 "parser2.1.ypp"
    { yyval.Objects; }
    break;

  case 109:
#line 673 "parser2.1.ypp"
    { yyval.Objects; }
    break;

  case 112:
#line 674 "parser2.1.ypp"
    { yyval.Objects; }
    break;

  case 113:
#line 675 "parser2.1.ypp"
    { PollingMaster* a=new PollingMaster;stack.push(a);a->lineno=yylineno; }
    break;

  case 114:
#line 675 "parser2.1.ypp"
    {yyval.PollingMasters=(typeof(yyval.PollingMasters))stack.pop();}
    break;

  case 119:
#line 676 "parser2.1.ypp"
    { typeof(yyval.PollingMasters) a =(typeof(yyval.PollingMasters))(stack.top());if(a->ID_lineno)parserError(_("%s already set at line %d"),"ID",a->ID_lineno);a->ID_lineno=yylineno;; a->ID=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 120:
#line 677 "parser2.1.ypp"
    { typeof(yyval.PollingMasters) a =(typeof(yyval.PollingMasters))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 121:
#line 678 "parser2.1.ypp"
    { yyval.PollingMasters; }
    break;

  case 122:
#line 678 "parser2.1.ypp"
    { yyval.PollingMasters; }
    break;

  case 125:
#line 679 "parser2.1.ypp"
    { yyval.PollingMasters; }
    break;

  case 126:
#line 680 "parser2.1.ypp"
    { PollingSlave* a=new PollingSlave;stack.push(a);a->lineno=yylineno; }
    break;

  case 127:
#line 680 "parser2.1.ypp"
    {yyval.PollingSlaves=(typeof(yyval.PollingSlaves))stack.pop();}
    break;

  case 132:
#line 681 "parser2.1.ypp"
    { typeof(yyval.PollingSlaves) a =(typeof(yyval.PollingSlaves))(stack.top());if(a->ID_lineno)parserError(_("%s already set at line %d"),"ID",a->ID_lineno);a->ID_lineno=yylineno;; a->ID=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 133:
#line 682 "parser2.1.ypp"
    { typeof(yyval.PollingSlaves) a =(typeof(yyval.PollingSlaves))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 134:
#line 683 "parser2.1.ypp"
    { yyval.PollingSlaves; }
    break;

  case 135:
#line 683 "parser2.1.ypp"
    { yyval.PollingSlaves; }
    break;

  case 138:
#line 684 "parser2.1.ypp"
    { yyval.PollingSlaves; }
    break;

  case 139:
#line 685 "parser2.1.ypp"
    { ListParameter* a=new ListParameter;stack.push(a);a->lineno=yylineno; }
    break;

  case 140:
#line 685 "parser2.1.ypp"
    {yyval.ListParameters=(typeof(yyval.ListParameters))stack.pop();}
    break;

  case 145:
#line 686 "parser2.1.ypp"
    { typeof(yyval.ListParameters) a =(typeof(yyval.ListParameters))(stack.top());if(a->ID_lineno)parserError(_("%s already set at line %d"),"ID",a->ID_lineno);a->ID_lineno=yylineno;; a->ID=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 146:
#line 687 "parser2.1.ypp"
    { typeof(yyval.ListParameters) a =(typeof(yyval.ListParameters))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 147:
#line 688 "parser2.1.ypp"
    { typeof(yyval.ListParameters) a =(typeof(yyval.ListParameters))(stack.top()); if(a->Elements_lineno)parserError(_("%s already set at line %d"),"Elements",a->Elements_lineno);a->Elements_lineno=yylineno;; a->Elements=*yyvsp[-1].map; delete yyvsp[-1].map; }
    break;

  case 148:
#line 690 "parser2.1.ypp"
    { yyval.ListParameters; }
    break;

  case 149:
#line 690 "parser2.1.ypp"
    { yyval.ListParameters; }
    break;

  case 152:
#line 691 "parser2.1.ypp"
    { typeof(yyval.ListParameters) a =(typeof(yyval.ListParameters))(stack.top());if(a->Value_lineno)parserError(_("%s already set at line %d"),"Value",a->Value_lineno);a->Value_lineno=yylineno;; a->Value=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 153:
#line 692 "parser2.1.ypp"
    { yyval.ListParameters; }
    break;

  case 154:
#line 693 "parser2.1.ypp"
    { IntParameter* a=new IntParameter;stack.push(a);a->lineno=yylineno; }
    break;

  case 155:
#line 693 "parser2.1.ypp"
    {yyval.IntParameters=(typeof(yyval.IntParameters))stack.pop();}
    break;

  case 160:
#line 694 "parser2.1.ypp"
    { typeof(yyval.IntParameters) a =(typeof(yyval.IntParameters))(stack.top());if(a->ID_lineno)parserError(_("%s already set at line %d"),"ID",a->ID_lineno);a->ID_lineno=yylineno;; a->ID=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 161:
#line 695 "parser2.1.ypp"
    { typeof(yyval.IntParameters) a =(typeof(yyval.IntParameters))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 162:
#line 696 "parser2.1.ypp"
    { typeof(yyval.IntParameters) a =(typeof(yyval.IntParameters))(stack.top());if(a->MinValue_lineno)parserError(_("%s already set at line %d"),"MinValue",a->MinValue_lineno);a->MinValue_lineno=yylineno;; a->MinValue=yyvsp[-1].intval;}
    break;

  case 163:
#line 697 "parser2.1.ypp"
    { typeof(yyval.IntParameters) a =(typeof(yyval.IntParameters))(stack.top());if(a->MaxValue_lineno)parserError(_("%s already set at line %d"),"MaxValue",a->MaxValue_lineno);a->MaxValue_lineno=yylineno;; a->MaxValue=yyvsp[-1].intval;}
    break;

  case 164:
#line 699 "parser2.1.ypp"
    { yyval.IntParameters; }
    break;

  case 165:
#line 699 "parser2.1.ypp"
    { yyval.IntParameters; }
    break;

  case 168:
#line 700 "parser2.1.ypp"
    { typeof(yyval.IntParameters) a =(typeof(yyval.IntParameters))(stack.top());if(a->Value_lineno)parserError(_("%s already set at line %d"),"Value",a->Value_lineno);a->Value_lineno=yylineno;; a->Value=yyvsp[-1].intval;}
    break;

  case 169:
#line 701 "parser2.1.ypp"
    { yyval.IntParameters; }
    break;

  case 170:
#line 702 "parser2.1.ypp"
    { StringParameter* a=new StringParameter;stack.push(a);a->lineno=yylineno; }
    break;

  case 171:
#line 702 "parser2.1.ypp"
    {yyval.StringParameters=(typeof(yyval.StringParameters))stack.pop();}
    break;

  case 176:
#line 703 "parser2.1.ypp"
    { typeof(yyval.StringParameters) a =(typeof(yyval.StringParameters))(stack.top());if(a->ID_lineno)parserError(_("%s already set at line %d"),"ID",a->ID_lineno);a->ID_lineno=yylineno;; a->ID=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 177:
#line 704 "parser2.1.ypp"
    { typeof(yyval.StringParameters) a =(typeof(yyval.StringParameters))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 178:
#line 705 "parser2.1.ypp"
    { typeof(yyval.StringParameters) a =(typeof(yyval.StringParameters))(stack.top());if(a->RegExp_lineno)parserError(_("%s already set at line %d"),"RegExp",a->RegExp_lineno);a->RegExp_lineno=yylineno;; a->RegExp=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 179:
#line 706 "parser2.1.ypp"
    { typeof(yyval.StringParameters) a =(typeof(yyval.StringParameters))(stack.top());if(a->MaxLength_lineno)parserError(_("%s already set at line %d"),"MaxLength",a->MaxLength_lineno);a->MaxLength_lineno=yylineno;; a->MaxLength=yyvsp[-1].intval;}
    break;

  case 180:
#line 707 "parser2.1.ypp"
    { yyval.StringParameters; }
    break;

  case 181:
#line 707 "parser2.1.ypp"
    { yyval.StringParameters; }
    break;

  case 184:
#line 708 "parser2.1.ypp"
    { typeof(yyval.StringParameters) a =(typeof(yyval.StringParameters))(stack.top());if(a->Value_lineno)parserError(_("%s already set at line %d"),"Value",a->Value_lineno);a->Value_lineno=yylineno;; a->Value=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 185:
#line 709 "parser2.1.ypp"
    { yyval.StringParameters; }
    break;

  case 186:
#line 710 "parser2.1.ypp"
    { FloatParameter* a=new FloatParameter;stack.push(a);a->lineno=yylineno; }
    break;

  case 187:
#line 710 "parser2.1.ypp"
    {yyval.FloatParameters=(typeof(yyval.FloatParameters))stack.pop();}
    break;

  case 192:
#line 711 "parser2.1.ypp"
    { typeof(yyval.FloatParameters) a =(typeof(yyval.FloatParameters))(stack.top());if(a->ID_lineno)parserError(_("%s already set at line %d"),"ID",a->ID_lineno);a->ID_lineno=yylineno;; a->ID=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 193:
#line 712 "parser2.1.ypp"
    { typeof(yyval.FloatParameters) a =(typeof(yyval.FloatParameters))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 194:
#line 713 "parser2.1.ypp"
    { typeof(yyval.FloatParameters) a =(typeof(yyval.FloatParameters))(stack.top());if(a->MinValue_lineno)parserError(_("%s already set at line %d"),"MinValue",a->MinValue_lineno);a->MinValue_lineno=yylineno;; a->MinValue=yyvsp[-1].fval;}
    break;

  case 195:
#line 714 "parser2.1.ypp"
    { typeof(yyval.FloatParameters) a =(typeof(yyval.FloatParameters))(stack.top());if(a->MaxValue_lineno)parserError(_("%s already set at line %d"),"MaxValue",a->MaxValue_lineno);a->MaxValue_lineno=yylineno;; a->MaxValue=yyvsp[-1].fval;}
    break;

  case 196:
#line 715 "parser2.1.ypp"
    { yyval.FloatParameters; }
    break;

  case 197:
#line 715 "parser2.1.ypp"
    { yyval.FloatParameters; }
    break;

  case 200:
#line 716 "parser2.1.ypp"
    { typeof(yyval.FloatParameters) a =(typeof(yyval.FloatParameters))(stack.top());if(a->Value_lineno)parserError(_("%s already set at line %d"),"Value",a->Value_lineno);a->Value_lineno=yylineno;; a->Value=yyvsp[-1].fval;}
    break;

  case 201:
#line 717 "parser2.1.ypp"
    { yyval.FloatParameters; }
    break;

  case 202:
#line 718 "parser2.1.ypp"
    { Timer* a=new Timer;stack.push(a);a->lineno=yylineno; }
    break;

  case 203:
#line 718 "parser2.1.ypp"
    {yyval.Timers=(typeof(yyval.Timers))stack.pop();}
    break;

  case 208:
#line 719 "parser2.1.ypp"
    { typeof(yyval.Timers) a =(typeof(yyval.Timers))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 209:
#line 720 "parser2.1.ypp"
    { typeof(yyval.Timers) a =(typeof(yyval.Timers))(stack.top());if(a->Type_lineno)parserError(_("%s already set at line %d"),"Type",a->Type_lineno);a->Type_lineno=yylineno;; a->Type=Map_TimerType(*yyvsp[-1].string);delete yyvsp[-1].string;}
    break;

  case 210:
#line 721 "parser2.1.ypp"
    { typeof(yyval.Timers) a =(typeof(yyval.Timers))(stack.top());if(a->Resolution_lineno)parserError(_("%s already set at line %d"),"Resolution",a->Resolution_lineno);a->Resolution_lineno=yylineno;; a->Resolution=Map_TimerResType(*yyvsp[-1].string);delete yyvsp[-1].string;}
    break;

  case 211:
#line 722 "parser2.1.ypp"
    { typeof(yyval.Timers) a =(typeof(yyval.Timers))(stack.top());if(a->on_expire_lineno)parserError(_("%s already set at line %d"),"on_expire",a->on_expire_lineno);a->on_expire_lineno=yylineno;; a->on_expire=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 212:
#line 724 "parser2.1.ypp"
    { yyval.Timers; }
    break;

  case 213:
#line 724 "parser2.1.ypp"
    { yyval.Timers; }
    break;

  case 216:
#line 725 "parser2.1.ypp"
    { yyval.Timers; }
    break;

  case 217:
#line 726 "parser2.1.ypp"
    { Debounce* a=new Debounce;stack.push(a);a->lineno=yylineno; }
    break;

  case 218:
#line 726 "parser2.1.ypp"
    {yyval.Debounces=(typeof(yyval.Debounces))stack.pop();}
    break;

  case 223:
#line 727 "parser2.1.ypp"
    { typeof(yyval.Debounces) a =(typeof(yyval.Debounces))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 224:
#line 728 "parser2.1.ypp"
    { typeof(yyval.Debounces) a =(typeof(yyval.Debounces))(stack.top());if(a->Time_lineno)parserError(_("%s already set at line %d"),"Time",a->Time_lineno);a->Time_lineno=yylineno;; a->Time=yyvsp[-1].fval;}
    break;

  case 225:
#line 729 "parser2.1.ypp"
    { yyval.Debounces; }
    break;

  case 226:
#line 729 "parser2.1.ypp"
    { yyval.Debounces; }
    break;

  case 229:
#line 730 "parser2.1.ypp"
    { yyval.Debounces; }
    break;

  case 230:
#line 731 "parser2.1.ypp"
    { Device* a=new Device;stack.push(a);a->lineno=yylineno; }
    break;

  case 231:
#line 731 "parser2.1.ypp"
    {yyval.Devices=(typeof(yyval.Devices))stack.pop();}
    break;

  case 236:
#line 732 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->ProgramID_lineno)parserError(_("%s already set at line %d"),"ProgramID",a->ProgramID_lineno);a->ProgramID_lineno=yylineno;; a->ProgramID=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 237:
#line 733 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->ManufacturerCode_lineno)parserError(_("%s already set at line %d"),"ManufacturerCode",a->ManufacturerCode_lineno);a->ManufacturerCode_lineno=yylineno;; a->ManufacturerCode=yyvsp[-1].intval;}
    break;

  case 238:
#line 734 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->InternalManufacturerCode_lineno)parserError(_("%s already set at line %d"),"InternalManufacturerCode",a->InternalManufacturerCode_lineno);a->InternalManufacturerCode_lineno=yylineno;; a->InternalManufacturerCode=yyvsp[-1].intval;}
    break;

  case 239:
#line 735 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->DeviceType_lineno)parserError(_("%s already set at line %d"),"DeviceType",a->DeviceType_lineno);a->DeviceType_lineno=yylineno;; a->DeviceType=yyvsp[-1].intval;}
    break;

  case 240:
#line 736 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->Version_lineno)parserError(_("%s already set at line %d"),"Version",a->Version_lineno);a->Version_lineno=yylineno;; a->Version=yyvsp[-1].intval;}
    break;

  case 241:
#line 737 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->SyncRate_lineno)parserError(_("%s already set at line %d"),"SyncRate",a->SyncRate_lineno);a->SyncRate_lineno=yylineno;; a->SyncRate=yyvsp[-1].intval;}
    break;

  case 242:
#line 738 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->PEIType_lineno)parserError(_("%s already set at line %d"),"PEIType",a->PEIType_lineno);a->PEIType_lineno=yylineno;; a->PEIType=yyvsp[-1].intval;}
    break;

  case 243:
#line 739 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->PortADDR_lineno)parserError(_("%s already set at line %d"),"PortADDR",a->PortADDR_lineno);a->PortADDR_lineno=yylineno;; a->PortADDR=yyvsp[-1].intval;}
    break;

  case 244:
#line 740 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->PortCDDR_lineno)parserError(_("%s already set at line %d"),"PortCDDR",a->PortCDDR_lineno);a->PortCDDR_lineno=yylineno;; a->PortCDDR=yyvsp[-1].intval;}
    break;

  case 245:
#line 741 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->U_DELMSG_lineno)parserError(_("%s already set at line %d"),"U_DELMSG",a->U_DELMSG_lineno);a->U_DELMSG_lineno=yylineno;; a->U_DELMSG=yyvsp[-1].bval;}
    break;

  case 246:
#line 742 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->RouteCount_lineno)parserError(_("%s already set at line %d"),"RouteCount",a->RouteCount_lineno);a->RouteCount_lineno=yylineno;; a->RouteCount=yyvsp[-1].intval;}
    break;

  case 247:
#line 743 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->BusyLimit_lineno)parserError(_("%s already set at line %d"),"BusyLimit",a->BusyLimit_lineno);a->BusyLimit_lineno=yylineno;; a->BusyLimit=yyvsp[-1].intval;}
    break;

  case 248:
#line 744 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->INAKLimit_lineno)parserError(_("%s already set at line %d"),"INAKLimit",a->INAKLimit_lineno);a->INAKLimit_lineno=yylineno;; a->INAKLimit=yyvsp[-1].intval;}
    break;

  case 249:
#line 745 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->RateLimit_lineno)parserError(_("%s already set at line %d"),"RateLimit",a->RateLimit_lineno);a->RateLimit_lineno=yylineno;; a->RateLimit=yyvsp[-1].intval;}
    break;

  case 250:
#line 746 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->CPOL_lineno)parserError(_("%s already set at line %d"),"CPOL",a->CPOL_lineno);a->CPOL_lineno=yylineno;; a->CPOL=yyvsp[-1].bval;}
    break;

  case 251:
#line 747 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->CPHA_lineno)parserError(_("%s already set at line %d"),"CPHA",a->CPHA_lineno);a->CPHA_lineno=yylineno;; a->CPHA=yyvsp[-1].bval;}
    break;

  case 252:
#line 748 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->AutoPLMA_lineno)parserError(_("%s already set at line %d"),"AutoPLMA",a->AutoPLMA_lineno);a->AutoPLMA_lineno=yylineno;; a->AutoPLMA=yyvsp[-1].bval;}
    break;

  case 253:
#line 749 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->A_Event_lineno)parserError(_("%s already set at line %d"),"A_Event",a->A_Event_lineno);a->A_Event_lineno=yylineno;; a->A_Event=yyvsp[-1].bval;}
    break;

  case 254:
#line 750 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->BCU1_SEC_lineno)parserError(_("%s already set at line %d"),"BCU1_SEC",a->BCU1_SEC_lineno);a->BCU1_SEC_lineno=yylineno;; a->BCU1_SEC=yyvsp[-1].bval;}
    break;

  case 255:
#line 751 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->BCU1_PROTECT_lineno)parserError(_("%s already set at line %d"),"BCU1_PROTECT",a->BCU1_PROTECT_lineno);a->BCU1_PROTECT_lineno=yylineno;; a->BCU1_PROTECT=yyvsp[-1].bval;}
    break;

  case 256:
#line 752 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->BCU2_PROTECT_lineno)parserError(_("%s already set at line %d"),"BCU2_PROTECT",a->BCU2_PROTECT_lineno);a->BCU2_PROTECT_lineno=yylineno;; a->BCU2_PROTECT=yyvsp[-1].bval;}
    break;

  case 257:
#line 753 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->BCU2_WATCHDOG_lineno)parserError(_("%s already set at line %d"),"BCU2_WATCHDOG",a->BCU2_WATCHDOG_lineno);a->BCU2_WATCHDOG_lineno=yylineno;; a->BCU2_WATCHDOG=yyvsp[-1].bval;}
    break;

  case 258:
#line 754 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->PLM_FAST_lineno)parserError(_("%s already set at line %d"),"PLM_FAST",a->PLM_FAST_lineno);a->PLM_FAST_lineno=yylineno;; a->PLM_FAST=yyvsp[-1].bval;}
    break;

  case 259:
#line 755 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); if(a->include_lineno)parserError(_("%s already set at line %d"),"include",a->include_lineno);a->include_lineno=yylineno;; a->include=*yyvsp[-1].stringarray; delete yyvsp[-1].stringarray; }
    break;

  case 260:
#line 756 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->PollingMasters.add(*yyvsp[0].PollingMasters); delete yyvsp[0].PollingMasters; }
    break;

  case 261:
#line 757 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->PollingSlaves.add(*yyvsp[0].PollingSlaves); delete yyvsp[0].PollingSlaves; }
    break;

  case 262:
#line 758 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->GroupObjects.add(*yyvsp[0].GroupObjects); delete yyvsp[0].GroupObjects; }
    break;

  case 263:
#line 759 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->Objects.add(*yyvsp[0].Objects); delete yyvsp[0].Objects; }
    break;

  case 264:
#line 760 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->ListParameters.add(*yyvsp[0].ListParameters); delete yyvsp[0].ListParameters; }
    break;

  case 265:
#line 761 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->IntParameters.add(*yyvsp[0].IntParameters); delete yyvsp[0].IntParameters; }
    break;

  case 266:
#line 762 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->FloatParameters.add(*yyvsp[0].FloatParameters); delete yyvsp[0].FloatParameters; }
    break;

  case 267:
#line 763 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->StringParameters.add(*yyvsp[0].StringParameters); delete yyvsp[0].StringParameters; }
    break;

  case 268:
#line 764 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->Debounces.add(*yyvsp[0].Debounces); delete yyvsp[0].Debounces; }
    break;

  case 269:
#line 765 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->Timers.add(*yyvsp[0].Timers); delete yyvsp[0].Timers; }
    break;

  case 270:
#line 766 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_run_lineno)parserError(_("%s already set at line %d"),"on_run",a->on_run_lineno);a->on_run_lineno=yylineno;; a->on_run=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 271:
#line 767 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_init_lineno)parserError(_("%s already set at line %d"),"on_init",a->on_init_lineno);a->on_init_lineno=yylineno;; a->on_init=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 272:
#line 768 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_save_lineno)parserError(_("%s already set at line %d"),"on_save",a->on_save_lineno);a->on_save_lineno=yylineno;; a->on_save=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 273:
#line 769 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_init_lineno)parserError(_("%s already set at line %d"),"on_pei_init",a->on_pei_init_lineno);a->on_pei_init_lineno=yylineno;; a->on_pei_init=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 274:
#line 770 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_message_lineno)parserError(_("%s already set at line %d"),"on_pei_message",a->on_pei_message_lineno);a->on_pei_message_lineno=yylineno;; a->on_pei_message=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 275:
#line 771 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_cycle_lineno)parserError(_("%s already set at line %d"),"on_pei_cycle",a->on_pei_cycle_lineno);a->on_pei_cycle_lineno=yylineno;; a->on_pei_cycle=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 276:
#line 772 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_user_lineno)parserError(_("%s already set at line %d"),"on_pei_user",a->on_pei_user_lineno);a->on_pei_user_lineno=yylineno;; a->on_pei_user=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 277:
#line 773 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_rc_even_lineno)parserError(_("%s already set at line %d"),"on_pei_rc_even",a->on_pei_rc_even_lineno);a->on_pei_rc_even_lineno=yylineno;; a->on_pei_rc_even=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 278:
#line 774 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_rc_odd_lineno)parserError(_("%s already set at line %d"),"on_pei_rc_odd",a->on_pei_rc_odd_lineno);a->on_pei_rc_odd_lineno=yylineno;; a->on_pei_rc_odd=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 279:
#line 775 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_tc_lineno)parserError(_("%s already set at line %d"),"on_pei_tc",a->on_pei_tc_lineno);a->on_pei_tc_lineno=yylineno;; a->on_pei_tc=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 280:
#line 776 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_tdre_lineno)parserError(_("%s already set at line %d"),"on_pei_tdre",a->on_pei_tdre_lineno);a->on_pei_tdre_lineno=yylineno;; a->on_pei_tdre=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 281:
#line 777 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_sci_idle_lineno)parserError(_("%s already set at line %d"),"on_pei_sci_idle",a->on_pei_sci_idle_lineno);a->on_pei_sci_idle_lineno=yylineno;; a->on_pei_sci_idle=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 282:
#line 778 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_spif_lineno)parserError(_("%s already set at line %d"),"on_pei_spif",a->on_pei_spif_lineno);a->on_pei_spif_lineno=yylineno;; a->on_pei_spif=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 283:
#line 779 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_oca_lineno)parserError(_("%s already set at line %d"),"on_pei_oca",a->on_pei_oca_lineno);a->on_pei_oca_lineno=yylineno;; a->on_pei_oca=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 284:
#line 780 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_ocb_lineno)parserError(_("%s already set at line %d"),"on_pei_ocb",a->on_pei_ocb_lineno);a->on_pei_ocb_lineno=yylineno;; a->on_pei_ocb=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 285:
#line 781 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_ica_lineno)parserError(_("%s already set at line %d"),"on_pei_ica",a->on_pei_ica_lineno);a->on_pei_ica_lineno=yylineno;; a->on_pei_ica=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 286:
#line 782 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_icb_lineno)parserError(_("%s already set at line %d"),"on_pei_icb",a->on_pei_icb_lineno);a->on_pei_icb_lineno=yylineno;; a->on_pei_icb=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 287:
#line 785 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->BCU_lineno)parserError(_("%s already set at line %d"),"BCU",a->BCU_lineno);a->BCU_lineno=yylineno;; a->BCU=Map_BCUType(*yyvsp[-1].string);delete yyvsp[-1].string;}
    break;

  case 288:
#line 786 "parser2.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->Model_lineno)parserError(_("%s already set at line %d"),"Model",a->Model_lineno);a->Model_lineno=yylineno;; a->Model=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 289:
#line 789 "parser2.1.ypp"
    { yyval.Devices; }
    break;

  case 290:
#line 789 "parser2.1.ypp"
    { yyval.Devices; }
    break;

  case 293:
#line 790 "parser2.1.ypp"
    { yyval.Devices; }
    break;

  case 294:
#line 791 "parser2.1.ypp"
    { parser_dev=yyvsp[0].Devices; }
    break;


    }

/* Line 1010 of yacc.c.  */
#line 3346 "parser2.1.cpp"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {
		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
		 yydestruct (yystos[*yyssp], yyvsp);
	       }
        }
      else
	{
	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
	  yydestruct (yytoken, &yylval);
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

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

  yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}



