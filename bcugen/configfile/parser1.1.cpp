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
#line 3 "parser1.1.ypp"

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
#line 15 "parser1.1.ypp"
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
#line 620 "parser1.1.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 632 "parser1.1.cpp"

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
#define YYLAST   2313

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  162
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  127
/* YYNRULES -- Number of rules. */
#define YYNRULES  439
/* YYNRULES -- Number of states. */
#define YYNSTATES  948

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
     147,   153,   155,   159,   161,   164,   168,   172,   176,   180,
     184,   186,   188,   192,   194,   197,   201,   205,   209,   213,
     215,   217,   221,   223,   227,   231,   235,   239,   243,   247,
     251,   255,   259,   263,   267,   271,   275,   279,   283,   287,
     291,   295,   297,   303,   307,   310,   314,   318,   320,   322,
     324,   326,   328,   331,   333,   335,   337,   338,   344,   348,
     352,   358,   360,   364,   366,   370,   372,   376,   378,   379,
     382,   387,   390,   395,   398,   403,   406,   411,   414,   417,
     422,   423,   430,   431,   434,   436,   438,   442,   446,   450,
     454,   458,   462,   466,   470,   472,   476,   478,   481,   483,
     484,   491,   492,   495,   497,   499,   503,   507,   511,   515,
     517,   519,   523,   525,   528,   530,   531,   538,   539,   542,
     544,   546,   550,   554,   558,   562,   566,   570,   574,   578,
     582,   586,   588,   592,   594,   597,   601,   605,   609,   613,
     617,   621,   623,   624,   631,   632,   635,   637,   639,   643,
     647,   651,   655,   659,   663,   667,   671,   675,   679,   681,
     685,   687,   690,   694,   698,   702,   706,   708,   709,   716,
     717,   720,   722,   724,   728,   732,   736,   738,   742,   746,
     748,   752,   754,   757,   759,   760,   767,   768,   771,   773,
     775,   779,   783,   787,   789,   793,   795,   798,   802,   806,
     808,   809,   816,   817,   820,   822,   824,   828,   832,   836,
     838,   842,   844,   847,   851,   855,   857,   858,   865,   866,
     869,   871,   873,   877,   881,   885,   889,   893,   897,   899,
     903,   905,   908,   912,   914,   915,   922,   923,   926,   928,
     930,   934,   938,   942,   946,   950,   954,   958,   962,   966,
     968,   972,   974,   977,   981,   983,   984,   991,   992,   995,
     997,   999,  1003,  1007,  1011,  1015,  1019,  1023,  1027,  1029,
    1033,  1035,  1038,  1042,  1044,  1045,  1052,  1053,  1056,  1058,
    1060,  1064,  1068,  1072,  1076,  1080,  1084,  1088,  1092,  1096,
    1098,  1102,  1104,  1107,  1111,  1113,  1114,  1121,  1122,  1125,
    1127,  1129,  1133,  1137,  1141,  1145,  1147,  1151,  1153,  1156,
    1158,  1159,  1166,  1167,  1170,  1172,  1174,  1178,  1182,  1184,
    1188,  1190,  1193,  1195,  1196,  1203,  1204,  1207,  1209,  1211,
    1215,  1219,  1223,  1227,  1231,  1235,  1239,  1243,  1247,  1251,
    1255,  1259,  1263,  1267,  1271,  1275,  1279,  1283,  1287,  1291,
    1295,  1299,  1303,  1307,  1311,  1315,  1319,  1323,  1327,  1331,
    1333,  1337,  1341,  1343,  1345,  1347,  1349,  1351,  1353,  1355,
    1357,  1359,  1361,  1365,  1369,  1373,  1377,  1381,  1385,  1389,
    1393,  1397,  1401,  1405,  1409,  1413,  1417,  1421,  1425,  1429,
    1433,  1437,  1439,  1443,  1445,  1448,  1452,  1456,  1460,  1462
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     288,     0,    -1,     3,    -1,    27,   163,    -1,   153,   163,
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
     156,   164,    -1,   163,    -1,   153,   165,   154,    -1,     4,
      -1,    27,   165,    -1,   165,    26,   165,    -1,   165,    27,
     165,    -1,   165,    24,   165,    -1,   165,    25,   165,    -1,
     165,    23,   165,    -1,   175,    -1,   164,    -1,   153,   166,
     154,    -1,     4,    -1,    27,   166,    -1,   166,    26,   166,
      -1,   166,    27,   166,    -1,   166,    24,   166,    -1,   166,
      23,   166,    -1,   165,    -1,   173,    -1,   153,   167,   154,
      -1,     4,    -1,   167,    12,   167,    -1,   167,    13,   167,
      -1,   167,    15,   167,    -1,   167,    14,   167,    -1,   167,
      28,   167,    -1,   167,    29,   167,    -1,   166,    12,   166,
      -1,   166,    13,   166,    -1,   166,    15,   166,    -1,   166,
      14,   166,    -1,   166,    28,   166,    -1,   166,    29,   166,
      -1,   165,    12,   165,    -1,   165,    13,   165,    -1,   165,
      15,   165,    -1,   165,    14,   165,    -1,   165,    28,   165,
      -1,   165,    29,   165,    -1,   165,    -1,   174,    18,   153,
     180,   154,    -1,   172,    11,   172,    -1,    20,   172,    -1,
     153,   172,   154,    -1,   172,    10,   172,    -1,   170,    -1,
     169,    -1,   171,    -1,   168,    -1,     5,    -1,   173,     5,
      -1,     4,    -1,     7,    -1,     8,    -1,    -1,   176,   174,
     157,   173,   158,    -1,   159,   176,   160,    -1,   163,   157,
     163,    -1,   178,   161,   163,   157,   163,    -1,   163,    -1,
     179,   161,   163,    -1,   174,    -1,   180,   161,   174,    -1,
     173,    -1,   181,   161,   174,    -1,   161,    -1,    -1,   159,
     160,    -1,   159,   179,   182,   160,    -1,   159,   160,    -1,
     159,   178,   182,   160,    -1,   159,   160,    -1,   159,   180,
     182,   160,    -1,   159,   160,    -1,   159,   181,   182,   160,
      -1,    19,   159,    -1,   160,   158,    -1,    19,   159,   160,
     158,    -1,    -1,    33,   159,   191,   192,   160,   158,    -1,
      -1,   193,   192,    -1,   194,    -1,   189,    -1,    35,   174,
     158,    -1,    36,   173,   158,    -1,    37,   173,   158,    -1,
      38,   173,   158,    -1,    39,   172,   158,    -1,    40,   164,
     158,    -1,    40,   174,   158,    -1,    41,   185,   158,    -1,
       9,    -1,   187,   195,   188,    -1,   196,    -1,   196,   195,
      -1,     9,    -1,    -1,    43,   159,   198,   199,   160,   158,
      -1,    -1,   200,   199,    -1,   201,    -1,   189,    -1,    36,
     173,   158,    -1,    37,   173,   158,    -1,    44,   163,   158,
      -1,    44,   174,   158,    -1,   190,    -1,     9,    -1,   187,
     202,   188,    -1,   203,    -1,   203,   202,    -1,     9,    -1,
      -1,    45,   159,   205,   206,   160,   158,    -1,    -1,   207,
     206,    -1,   208,    -1,   189,    -1,    46,   174,   158,    -1,
      47,   174,   158,    -1,    48,   174,   158,    -1,    49,   175,
     158,    -1,    50,   175,   158,    -1,    51,   175,   158,    -1,
      52,   175,   158,    -1,    36,   173,   158,    -1,    37,   173,
     158,    -1,    53,   175,   158,    -1,     9,    -1,   187,   209,
     188,    -1,   210,    -1,   210,   209,    -1,    54,   174,   158,
      -1,    55,   163,   158,    -1,    56,   163,   158,    -1,    57,
     183,   158,    -1,    58,   183,   158,    -1,    59,   183,   158,
      -1,     9,    -1,    -1,    60,   159,   212,   213,   160,   158,
      -1,    -1,   214,   213,    -1,   215,    -1,   189,    -1,    46,
     174,   158,    -1,    47,   174,   158,    -1,    61,   163,   158,
      -1,    61,   174,   158,    -1,    62,   163,   158,    -1,    63,
     175,   158,    -1,    49,   175,   158,    -1,    64,   174,   158,
      -1,    36,   173,   158,    -1,    37,   173,   158,    -1,     9,
      -1,   187,   216,   188,    -1,   217,    -1,   217,   216,    -1,
      65,   175,   158,    -1,    66,   175,   158,    -1,    67,   163,
     158,    -1,    68,   163,   158,    -1,     9,    -1,    -1,    69,
     159,   219,   220,   160,   158,    -1,    -1,   221,   220,    -1,
     222,    -1,   189,    -1,    46,   174,   158,    -1,    71,   163,
     158,    -1,    71,   174,   158,    -1,   211,    -1,    36,   173,
     158,    -1,    37,   173,   158,    -1,     9,    -1,   187,   223,
     188,    -1,   224,    -1,   224,   223,    -1,     9,    -1,    -1,
      72,   159,   226,   227,   160,   158,    -1,    -1,   228,   227,
      -1,   229,    -1,   189,    -1,    46,   174,   158,    -1,    36,
     173,   158,    -1,    37,   173,   158,    -1,     9,    -1,   187,
     230,   188,    -1,   231,    -1,   231,   230,    -1,    73,   163,
     158,    -1,    74,   163,   158,    -1,     9,    -1,    -1,    75,
     159,   233,   234,   160,   158,    -1,    -1,   235,   234,    -1,
     236,    -1,   189,    -1,    46,   174,   158,    -1,    36,   173,
     158,    -1,    37,   173,   158,    -1,     9,    -1,   187,   237,
     188,    -1,   238,    -1,   238,   237,    -1,    73,   163,   158,
      -1,    76,   163,   158,    -1,     9,    -1,    -1,    77,   159,
     240,   241,   160,   158,    -1,    -1,   242,   241,    -1,   243,
      -1,   189,    -1,    46,   174,   158,    -1,    78,   177,   158,
      -1,    36,   173,   158,    -1,    37,   173,   158,    -1,    79,
     174,   158,    -1,    80,   173,   158,    -1,     9,    -1,   187,
     244,   188,    -1,   245,    -1,   245,   244,    -1,    83,   174,
     158,    -1,     9,    -1,    -1,    84,   159,   247,   248,   160,
     158,    -1,    -1,   249,   248,    -1,   250,    -1,   189,    -1,
      46,   174,   158,    -1,    85,   163,   158,    -1,    86,   163,
     158,    -1,    36,   173,   158,    -1,    37,   173,   158,    -1,
      79,   163,   158,    -1,    80,   173,   158,    -1,    87,   163,
     158,    -1,    88,   163,   158,    -1,     9,    -1,   187,   251,
     188,    -1,   252,    -1,   252,   251,    -1,    83,   163,   158,
      -1,     9,    -1,    -1,    89,   159,   254,   255,   160,   158,
      -1,    -1,   256,   255,    -1,   257,    -1,   189,    -1,    46,
     174,   158,    -1,    90,   173,   158,    -1,    91,   163,   158,
      -1,    79,   173,   158,    -1,    36,   173,   158,    -1,    37,
     173,   158,    -1,    80,   173,   158,    -1,     9,    -1,   187,
     258,   188,    -1,   259,    -1,   259,   258,    -1,    83,   173,
     158,    -1,     9,    -1,    -1,    92,   159,   261,   262,   160,
     158,    -1,    -1,   263,   262,    -1,   264,    -1,   189,    -1,
      46,   174,   158,    -1,    85,   164,   158,    -1,    86,   164,
     158,    -1,    36,   173,   158,    -1,    37,   173,   158,    -1,
      80,   173,   158,    -1,    87,   164,   158,    -1,    88,   164,
     158,    -1,    79,   164,   158,    -1,     9,    -1,   187,   265,
     188,    -1,   266,    -1,   266,   265,    -1,    83,   164,   158,
      -1,     9,    -1,    -1,    93,   159,   268,   269,   160,   158,
      -1,    -1,   270,   269,    -1,   271,    -1,   189,    -1,    46,
     174,   158,    -1,    47,   174,   158,    -1,    94,   174,   158,
      -1,    95,   174,   158,    -1,     9,    -1,   187,   272,   188,
      -1,   273,    -1,   273,   272,    -1,     9,    -1,    -1,    96,
     159,   275,   276,   160,   158,    -1,    -1,   277,   276,    -1,
     278,    -1,   189,    -1,    46,   174,   158,    -1,    97,   164,
     158,    -1,     9,    -1,   187,   279,   188,    -1,   280,    -1,
     280,   279,    -1,     9,    -1,    -1,    98,   159,   282,   283,
     160,   158,    -1,    -1,   284,   283,    -1,   285,    -1,   189,
      -1,   100,   163,   158,    -1,   101,   163,   158,    -1,   102,
     163,   158,    -1,   103,   163,   158,    -1,   104,   163,   158,
      -1,   105,   163,   158,    -1,   106,   163,   158,    -1,   107,
     163,   158,    -1,   108,   175,   158,    -1,   109,   163,   158,
      -1,   110,   163,   158,    -1,   111,   163,   158,    -1,   112,
     163,   158,    -1,   113,   175,   158,    -1,   114,   175,   158,
      -1,   115,   175,   158,    -1,   116,   175,   158,    -1,   117,
     175,   158,    -1,   118,   175,   158,    -1,   119,   175,   158,
      -1,   120,   175,   158,    -1,   121,   175,   158,    -1,   122,
     186,   158,    -1,    36,   173,   158,    -1,    37,   173,   158,
      -1,   123,   173,   158,    -1,   124,   173,   158,    -1,   125,
     173,   158,    -1,   126,   173,   158,    -1,   127,   173,   158,
      -1,   197,    -1,   128,   163,   158,    -1,   129,   163,   158,
      -1,   225,    -1,   232,    -1,   204,    -1,   218,    -1,   239,
      -1,   246,    -1,   260,    -1,   253,    -1,   274,    -1,   267,
      -1,   130,   174,   158,    -1,   131,   174,   158,    -1,   132,
     174,   158,    -1,   133,   174,   158,    -1,   134,   174,   158,
      -1,   135,   174,   158,    -1,   136,   174,   158,    -1,   137,
     174,   158,    -1,   138,   174,   158,    -1,   139,   174,   158,
      -1,   140,   174,   158,    -1,   141,   174,   158,    -1,   142,
     174,   158,    -1,   143,   174,   158,    -1,   144,   174,   158,
      -1,   145,   174,   158,    -1,   146,   174,   158,    -1,   148,
     174,   158,    -1,   149,   174,   158,    -1,     9,    -1,   187,
     286,   188,    -1,   287,    -1,   287,   286,    -1,   150,   184,
     158,    -1,   151,   163,   158,    -1,   152,   163,   158,    -1,
       9,    -1,   281,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   526,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   611,   611,
     611,   612,   612,   613,   614,   614,   615,   615,   616,   617,
     617,   618,   618,   619,   619,   620,   620,   621,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   631,   632,
     633,   633,   633,   633,   633,   633,   634,   635,   636,   637,
     638,   639,   639,   640,   641,   641,   641,   641,   642,   643,
     643,   643,   643,   643,   643,   644,   645,   646,   646,   647,
     648,   648,   648,   648,   649,   650,   650,   650,   650,   650,
     650,   651,   652,   653,   654,   655,   656,   657,   658,   659,
     660,   663,   663,   663,   663,   664,   665,   666,   667,   668,
     669,   670,   671,   671,   671,   671,   671,   671,   672,   673,
     674,   674,   675,   676,   677,   678,   679,   680,   681,   681,
     681,   681,   682,   683,   684,   685,   686,   687,   687,   687,
     687,   687,   687,   688,   689,   689,   690,   691,   692,   696,
     696,   696,   696,   697,   698,   698,   698,   698,   698,   698,
     699,   700,   701,   702,   702,   702,   702,   703,   704,   705,
     706,   706,   706,   706,   706,   706,   707,   708,   709,   710,
     710,   710,   710,   711,   712,   713,   714,   714,   714,   714,
     714,   714,   715,   716,   717,   718,   719,   720,   722,   722,
     722,   722,   723,   724,   725,   725,   725,   725,   725,   725,
     726,   727,   728,   729,   730,   731,   732,   733,   734,   736,
     736,   736,   736,   737,   738,   739,   739,   739,   739,   739,
     739,   740,   741,   742,   743,   744,   745,   746,   747,   747,
     747,   747,   748,   749,   750,   750,   750,   750,   750,   750,
     751,   752,   753,   754,   755,   756,   757,   758,   759,   760,
     760,   760,   760,   761,   762,   763,   763,   763,   763,   763,
     763,   764,   765,   766,   767,   769,   769,   769,   769,   770,
     771,   771,   771,   771,   771,   771,   772,   773,   774,   774,
     774,   774,   775,   776,   776,   776,   776,   776,   776,   777,
     778,   779,   780,   781,   782,   783,   784,   785,   786,   787,
     788,   789,   790,   791,   792,   793,   794,   795,   796,   797,
     798,   799,   800,   801,   802,   803,   804,   805,   806,   807,
     808,   809,   810,   811,   812,   813,   814,   815,   816,   817,
     818,   819,   820,   821,   822,   823,   824,   825,   826,   827,
     828,   829,   830,   831,   832,   833,   834,   835,   836,   839,
     840,   843,   843,   843,   843,   844,   845,   846,   847,   848
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
  "','", "$accept", "intc", "floatc", "intp", "floatp", "stringp",
  "stringb", "floatb", "intb", "listb", "expr", "string", "ident", "bool",
  "identmap1", "identmap", "keymaparray1", "intarray1", "identarray1",
  "stringarray1", "ebs", "intarray", "keymaparray", "identarray",
  "stringarray", "Begin_CI", "End_CI", "Empty_CI", "Interface_struct",
  "@1", "Interface_bodys", "Interface_body", "Interface_bodys_CI",
  "Interface_bodys_CI_i", "Interface_body_CI", "FunctionalBlock_struct",
  "@2", "FunctionalBlock_bodys", "FunctionalBlock_body",
  "FunctionalBlock_bodys_CI", "FunctionalBlock_bodys_CI_i",
  "FunctionalBlock_body_CI", "GroupObject_struct", "@3",
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
     164,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     167,   167,   167,   168,   168,   168,   168,   168,   168,   169,
     169,   169,   169,   169,   169,   170,   170,   170,   170,   170,
     170,   170,   171,   172,   172,   172,   172,   172,   172,   172,
     172,   173,   173,   174,   175,   175,   176,   176,   177,   178,
     178,   179,   179,   180,   180,   181,   181,   182,   182,   183,
     183,   184,   184,   185,   185,   186,   186,   187,   188,   189,
     191,   190,   192,   192,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   194,   195,   195,   196,   198,
     197,   199,   199,   200,   200,   200,   200,   200,   200,   200,
     200,   201,   202,   202,   203,   205,   204,   206,   206,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   208,   209,   209,   210,   210,   210,   210,   210,
     210,   210,   212,   211,   213,   213,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   215,
     216,   216,   217,   217,   217,   217,   217,   219,   218,   220,
     220,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     222,   223,   223,   224,   226,   225,   227,   227,   228,   228,
     228,   228,   228,   228,   229,   230,   230,   231,   231,   231,
     233,   232,   234,   234,   235,   235,   235,   235,   235,   235,
     236,   237,   237,   238,   238,   238,   240,   239,   241,   241,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   243,
     244,   244,   245,   245,   247,   246,   248,   248,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     250,   251,   251,   252,   252,   254,   253,   255,   255,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   257,
     258,   258,   259,   259,   261,   260,   262,   262,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     264,   265,   265,   266,   266,   268,   267,   269,   269,   270,
     270,   270,   270,   270,   270,   270,   271,   272,   272,   273,
     275,   274,   276,   276,   277,   277,   277,   277,   277,   278,
     279,   279,   280,   282,   281,   283,   283,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   285,   286,   286,   287,   287,   287,   287,   288
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     3,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     1,     1,     2,     3,     3,     3,     3,     3,
       5,     1,     3,     1,     2,     3,     3,     3,     3,     3,
       1,     1,     3,     1,     2,     3,     3,     3,     3,     1,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     5,     3,     2,     3,     3,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     0,     5,     3,     3,
       5,     1,     3,     1,     3,     1,     3,     1,     0,     2,
       4,     2,     4,     2,     4,     2,     4,     2,     2,     4,
       0,     6,     0,     2,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     1,     2,     1,     0,
       6,     0,     2,     1,     1,     3,     3,     3,     3,     1,
       1,     3,     1,     2,     1,     0,     6,     0,     2,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     2,     3,     3,     3,     3,     3,
       3,     1,     0,     6,     0,     2,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       1,     2,     3,     3,     3,     3,     1,     0,     6,     0,
       2,     1,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     2,     1,     0,     6,     0,     2,     1,     1,
       3,     3,     3,     1,     3,     1,     2,     3,     3,     1,
       0,     6,     0,     2,     1,     1,     3,     3,     3,     1,
       3,     1,     2,     3,     3,     1,     0,     6,     0,     2,
       1,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       1,     2,     3,     1,     0,     6,     0,     2,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     2,     3,     1,     0,     6,     0,     2,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       1,     2,     3,     1,     0,     6,     0,     2,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     2,     3,     1,     0,     6,     0,     2,     1,
       1,     3,     3,     3,     3,     1,     3,     1,     2,     1,
       0,     6,     0,     2,     1,     1,     3,     3,     1,     3,
       1,     2,     1,     0,     6,     0,     2,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     2,     3,     3,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       0,     0,   439,     0,   363,     1,   365,   431,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   368,   399,   404,   405,   402,   403,   406,   407,
     409,   408,   411,   410,     0,   365,   367,   117,    91,     0,
       0,   139,   155,   207,   224,   240,   256,   274,   295,   314,
     335,   350,     2,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   438,     0,     0,     0,     0,   433,     0,   366,
       0,    92,   392,   393,   141,   157,   209,   226,   242,   258,
     276,   297,   316,   337,   352,     5,     6,     3,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     369,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   115,   105,   108,   391,   394,   395,   396,   397,
     398,   400,   401,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,     0,     0,     0,     0,     0,   432,   434,   364,
     119,   150,     0,     0,     0,     0,     0,   144,   149,     0,
     141,   143,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   160,     0,   157,   159,   219,     0,
       0,     0,     0,     0,     0,   212,   216,     0,   209,   211,
     233,     0,     0,     0,     0,   229,     0,   226,   228,   249,
       0,     0,     0,     0,   245,     0,   242,   244,   268,     0,
       0,     0,     0,     0,     0,     0,   261,     0,   258,   260,
     289,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   279,     0,   276,   278,   308,     0,     0,     0,     0,
       0,     0,     0,     0,   300,     0,   297,   299,   329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   319,
       0,   316,   318,   345,     0,     0,     0,     0,     0,   340,
       0,   337,   339,   358,     0,     0,     0,   355,     0,   352,
     354,     4,    35,    30,    29,    18,    19,    17,    15,    13,
      12,     7,     8,     9,    10,    11,    14,    16,    26,    27,
      28,     0,     0,    33,    24,    25,    23,    21,    36,    37,
      38,    39,    20,    22,   107,     0,   111,     0,   108,   435,
     436,   437,   118,   120,     0,     0,     0,     0,   154,     0,
     152,     0,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,     0,     0,     0,     0,     0,     0,
       0,   173,     0,   158,     0,     0,     0,   182,     0,     0,
     223,     0,   221,     0,   210,     0,     0,     0,   239,     0,
       0,     0,   235,     0,   227,     0,     0,     0,   255,     0,
       0,     0,   251,     0,   243,     0,     0,     0,    96,     0,
       0,     0,   273,     0,     0,   270,     0,   259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   294,     0,     0,
     291,     0,   277,     0,     0,     0,     0,     0,     0,     0,
     313,     0,     0,   310,     0,   298,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   334,     0,     0,   331,     0,
     317,     0,     0,     0,     0,   349,     0,   347,     0,   338,
       0,     0,   362,     0,   360,     0,   353,     0,     0,   106,
     116,     0,   107,     0,   122,   145,   146,   147,   148,   151,
     153,   140,   168,   169,   161,   162,   163,   164,   165,   166,
     167,   170,     0,     0,     0,     0,     0,     0,     0,   172,
     174,   156,   217,   218,   213,   184,   214,   215,   220,   222,
     208,   231,   232,   230,     0,     0,   234,   236,   225,   247,
     248,   246,     0,     0,   250,   252,   241,   264,   265,   262,
       0,   263,   266,   267,     0,   269,   271,   257,   283,   284,
     280,   285,   286,   281,   282,   287,   288,     0,   290,   292,
     275,   305,   306,   301,   304,   307,   302,   303,     0,   309,
     311,   296,   323,   324,   320,   328,   325,   321,   322,   326,
     327,     0,   330,   332,   315,   341,   342,   343,   344,   346,
     348,   336,   356,   357,   359,   361,   351,    31,    40,    99,
       0,   112,   134,     0,     0,     0,     0,     0,     0,     0,
       0,   125,     0,   122,   124,   175,   176,   177,   109,   101,
     108,   178,   179,   180,   198,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   187,     0,   184,   186,   237,
     238,   253,   254,    98,     0,   272,   293,   312,   333,     0,
       0,     0,     0,     0,    43,     0,     0,     0,    33,    51,
      81,     0,     0,    90,    88,    87,    89,     0,    60,     0,
      50,     0,     0,     0,     0,   138,     0,   136,     0,   123,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   206,     0,     0,     0,     0,     0,   200,     0,
     185,     0,   100,   126,   127,   128,   129,     5,    84,    43,
       0,     3,    34,    44,    54,     0,     0,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   113,   103,   108,   133,   135,   137,
     121,   102,   110,   196,   197,   188,   189,   194,   190,   191,
     192,   193,   195,     0,     0,     0,     0,   199,   201,   183,
       0,     0,     0,    42,    52,    61,    85,    43,     0,     0,
      75,    76,    78,    77,    49,    47,    48,    45,    46,    79,
      80,    59,    69,    70,    72,    71,    58,    57,    55,    56,
      73,    74,    62,     0,    63,    64,    66,    65,    67,    68,
      86,    83,     0,   107,     0,   202,   203,   204,   205,    97,
      44,     0,     0,     0,   104,   114,    82,     0
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,   768,   109,   911,   771,   772,   773,   774,   775,   776,
     777,   778,   779,   780,   650,   519,   448,   730,   866,   244,
     445,   616,   273,   784,   134,    71,   277,    72,   288,   594,
     722,   723,   724,   786,   787,    73,   174,   289,   290,   291,
     459,   460,    74,   175,   305,   306,   307,   480,   481,   316,
     625,   746,   747,   748,   807,   808,    75,   176,   317,   318,
     319,   491,   492,    76,   177,   326,   327,   328,   501,   502,
      77,   178,   335,   336,   337,   511,   512,    78,   179,   347,
     348,   349,   524,   525,    79,   180,   362,   363,   364,   539,
     540,    80,   181,   375,   376,   377,   552,   553,    81,   182,
     390,   391,   392,   567,   568,    82,   183,   400,   401,   402,
     576,   577,    83,   184,   408,   409,   410,   583,   584,     2,
       6,    84,    85,    86,   166,   167,     3
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -738
static const short int yypact[] =
{
     -59,  -110,  -738,    60,  -738,  -738,  2077,  -738,   -93,    73,
      73,   -76,   -67,   -60,   -49,   -23,   -21,   -16,    -1,    12,
      22,    69,   368,   368,   368,   368,   368,   368,   368,   368,
      40,   368,   368,   368,   368,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    71,    73,    73,    73,    73,    73,
     368,   368,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,    72,  -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,
    -738,  -738,  -738,  -738,    75,  2077,  -738,    94,  -738,    31,
      52,  -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,
    -738,  -738,  -738,  -738,   368,   368,   368,   368,   682,  2079,
     785,   841,   977,  1000,  1023,  1046,  1069,  -738,  -738,    90,
    1092,  1160,  1205,  1228,   100,   102,   110,   139,   150,   156,
     160,   178,   179,    30,   180,    79,    80,    81,    82,    83,
    1251,  1274,  -738,   183,   195,   202,   203,   204,   207,   208,
     209,   217,   225,   233,   238,   243,   245,   246,   248,   251,
     252,   269,  -738,   214,   368,   368,   271,    72,   275,  -738,
     283,  -738,  -738,  -738,  2226,  2091,   618,   540,   544,  2080,
    2044,   873,  2215,   515,   428,  1956,  1956,  1956,  2079,  1933,
    1502,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
    -738,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,  -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,
    -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,
    -738,  -738,  -738,   227,   285,  -738,  -738,  -738,  -738,  -738,
    -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,
    -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,
    -738,  -738,    74,   290,  1297,  1320,   292,  -738,  -738,  -738,
    -738,  -738,   296,    73,    73,    34,   447,  -738,  -738,   297,
    2226,  -738,  -738,    73,    73,   170,   170,   170,    40,    40,
      40,    40,    40,   671,  -738,   302,  2091,  -738,  -738,    73,
      73,   170,   304,    34,   455,  -738,  -738,   307,   618,  -738,
    -738,    73,    73,   170,   176,  -738,   308,   540,  -738,  -738,
      73,    73,   170,   326,  -738,   310,   544,  -738,  -738,    73,
      73,   170,   318,   170,    73,    44,  -738,   319,  2080,  -738,
    -738,    73,    73,   170,   368,    73,   368,   368,   368,   368,
      47,  -738,   322,  2044,  -738,  -738,    73,    73,   170,    73,
      73,    73,   368,    49,  -738,   327,   873,  -738,  -738,    73,
      73,   170,   368,    73,   368,   368,   368,   368,    99,  -738,
     332,  2215,  -738,  -738,   170,   170,   170,   170,   469,  -738,
     335,   515,  -738,  -738,   170,   368,   477,  -738,   338,   428,
    -738,  -738,  -738,   352,    66,   429,   429,    33,    33,  2019,
    2019,  1996,  1996,  1996,  1137,  1137,    33,    33,   441,   358,
     173,  1910,   888,  1956,  -738,  -738,    78,    78,  1988,  1988,
     810,   810,    78,    78,   170,   348,  -738,  1864,   350,  -738,
    -738,  -738,  -738,  -738,    84,    88,  1364,   354,  -738,   271,
     447,   364,  -738,    93,    95,   370,   371,   377,   390,   396,
     398,   399,   402,  -738,   170,   368,   368,   357,   357,   357,
     271,   671,   407,  -738,    97,   104,   409,  -738,  1387,   416,
    -738,   271,   455,   420,  -738,   106,   107,   424,  -738,   368,
     368,   271,   176,   425,  -738,   108,   109,   431,  -738,   368,
     368,   271,   326,   435,  -738,   116,   117,   436,  -738,   437,
     439,   120,  -738,   170,   271,    44,   443,  -738,   121,   123,
     444,  1410,   124,  1433,  1456,  1479,  1523,  -738,   368,   271,
      47,   450,  -738,   126,   128,   453,   129,   130,   132,  1546,
    -738,    73,   271,    49,   454,  -738,   134,   135,   456,   491,
     136,   518,   645,   908,   954,  -738,   368,   271,    99,   471,
    -738,   472,   478,   481,   482,  -738,   271,   469,   483,  -738,
     484,  1113,  -738,   271,   477,   487,  -738,   368,   368,  -738,
    -738,   368,   368,   475,  2237,  -738,  -738,  -738,  -738,  -738,
    -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,
    -738,  -738,   492,  1569,  1592,    76,   493,   498,   504,  -738,
    -738,  -738,  -738,  -738,  -738,  2218,  -738,  -738,  -738,  -738,
    -738,  -738,  -738,  -738,  1615,  1638,  -738,  -738,  -738,  -738,
    -738,  -738,  1682,  1705,  -738,  -738,  -738,  -738,  -738,  -738,
      15,  -738,  -738,  -738,   505,  -738,  -738,  -738,  -738,  -738,
    -738,  -738,  -738,  -738,  -738,  -738,  -738,  1728,  -738,  -738,
    -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,   137,  -738,
    -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,
    -738,  1184,  -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,
    -738,  -738,  -738,  -738,  -738,  -738,  -738,  1956,  2079,  1956,
    1887,  -738,  -738,   170,    73,    73,    73,   373,    34,   440,
     661,  -738,   517,  2237,  -738,  -738,  -738,  -738,  -738,  1956,
     514,  -738,  -738,  -738,  -738,    73,    73,   170,   170,    40,
      34,   368,    40,   170,   423,  -738,   519,  2218,  -738,  -738,
    -738,  -738,  -738,  -738,   524,  -738,  -738,  -738,  -738,   368,
     529,   140,   151,   152,   664,   373,   343,   373,  1956,  2079,
    1818,  2284,   944,  -738,  -738,  -738,  -738,   169,   227,   672,
    -738,  1341,   546,    17,   557,  -738,   271,   661,   558,  -738,
     368,   543,   165,   167,   559,   561,   562,  1751,   581,  1774,
     584,   585,  -738,    40,    40,   368,   368,   271,   423,   598,
    -738,    73,  1956,  -738,  -738,  -738,  -738,  1956,   215,  -738,
     343,  1956,  2079,   545,   580,  1933,  1502,   709,  1661,   619,
     158,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   162,   162,   162,   162,   162,   162,   373,   373,
    -738,   604,  -738,  -738,  -738,  -738,   597,  -738,  -738,  -738,
    -738,  1956,  -738,  -738,  -738,  -738,  -738,  -738,  -738,  -738,
    -738,  -738,  -738,   602,   603,  1797,  1841,  -738,  -738,  -738,
     168,   280,   513,  -738,  -738,  -738,  -738,  -738,   422,   422,
     545,   545,   545,   545,   230,   230,   230,  -738,  -738,   545,
     545,   545,   580,   580,   580,   580,   250,   250,  -738,  -738,
     580,   580,  -738,   162,  -738,  -738,  -738,  -738,  -738,  -738,
    -738,   752,   170,   170,   608,  -738,  -738,  -738,  -738,  -738,
     545,   280,   609,  -102,  -738,  -738,  -738,   170
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -738,     0,   -65,  -215,  1225,  -737,  -738,  -738,  -738,  -738,
    -589,   114,   -52,    32,  -738,  -738,  -738,  -738,  -168,  -738,
    -428,  -179,  -738,  -738,  -738,   237,  -228,   570,  -738,  -738,
      46,  -738,  -738,   -17,  -738,  -738,  -738,   485,  -738,  -738,
     312,  -738,  -738,  -738,   470,  -738,  -738,   306,  -738,  -738,
    -738,    41,  -738,  -738,   -19,  -738,  -738,  -738,   473,  -738,
    -738,   300,  -738,  -738,  -738,   480,  -738,  -738,   316,  -738,
    -738,  -738,   468,  -738,  -738,   309,  -738,  -738,  -738,   479,
    -738,  -738,   294,  -738,  -738,  -738,   463,  -738,  -738,   301,
    -738,  -738,  -738,   466,  -738,  -738,   279,  -738,  -738,  -738,
     452,  -738,  -738,   276,  -738,  -738,  -738,   445,  -738,  -738,
     268,  -738,  -738,  -738,   438,  -738,  -738,   264,  -738,  -738,
    -738,   774,  -738,  -738,   694,  -738,  -738
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -94
static const short int yytable[] =
{
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   142,
     593,   142,   108,   110,   111,   112,   113,   114,   115,   116,
     829,   120,   121,   122,   123,    88,   171,   102,   142,     1,
     103,   188,   190,   191,   192,   193,   194,   117,   118,     4,
     140,   141,   946,   522,   104,   105,   537,   171,   550,   947,
       5,   106,   119,   206,   207,   208,    87,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   191,   102,    88,   102,
     103,   162,   103,    91,   171,   171,   171,   171,   171,   171,
     211,   212,    92,   171,   104,   105,   104,   105,   171,    93,
     171,   106,   171,   106,   185,   186,   187,   189,   565,   171,
      94,   171,   171,   171,   171,   924,   925,   926,   927,   928,
     929,   171,   171,    89,    90,   171,   171,   523,   171,   171,
     538,   171,   551,   171,   171,   171,    95,   171,    96,   171,
     171,   171,   171,    97,   432,   171,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   171,   171,    98,   135,
     136,   137,   138,   139,   274,   275,   922,    88,   858,   859,
     171,    99,   171,   171,   142,   753,   818,   864,   830,   858,
     859,   100,   566,   191,   192,   498,   942,   107,   209,   172,
     242,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     173,   433,   433,   433,   433,   433,   433,   433,   433,   433,
     433,   209,   163,   164,   165,   858,   859,   107,   101,   107,
     133,   599,   171,   457,   446,   168,   728,   246,   247,   248,
     249,   250,   595,   465,   466,   467,   596,   243,   228,   499,
     500,   602,   619,   603,   170,   622,   838,   839,   233,   486,
     234,   489,   623,   628,   631,   632,   639,   640,   235,   930,
     931,   497,   447,   636,   647,   648,   848,   849,   653,   658,
     507,   659,   662,   644,   671,   456,   672,   674,   675,   517,
     676,   520,   682,   683,   686,   757,   655,   236,   814,   617,
     618,   530,   791,   835,   836,   837,   838,   839,   237,   815,
     816,   668,   896,   488,   238,   923,   545,   559,   239,   561,
     562,   563,   564,   873,   679,   874,   939,   860,   209,   558,
     468,   469,   470,   471,   472,   508,   240,   241,   245,   692,
     581,   253,   571,   572,   573,   574,   102,   819,   699,   103,
     117,   118,   580,   254,   531,   704,   533,   534,   535,   536,
     255,   256,   257,   104,   105,   258,   259,   260,   191,   192,
     766,   102,   549,   272,   103,   261,   102,   764,    88,   103,
     117,   118,   433,   262,   433,   433,   433,   433,   104,   105,
     208,   263,   589,   765,   105,   106,   264,   454,   455,   509,
     766,   265,   510,   266,   267,   433,   268,   463,   464,   269,
     270,   286,   303,   314,   324,   333,   345,   360,   373,   388,
     398,   406,   612,   484,   485,   102,   897,   271,   103,   117,
     118,   276,   802,   279,   893,   495,   496,   403,   934,   191,
     192,   280,   104,   105,   505,   506,   444,     8,   449,   898,
     452,   191,   192,   515,   516,   453,   458,   461,   521,   206,
     207,   208,   482,   487,   490,   528,   529,   493,   503,   532,
     513,   654,   207,   208,   404,   613,   614,   518,   575,   526,
     543,   544,   541,   546,   547,   548,   582,   554,   803,   804,
     805,   806,   569,   556,   557,   578,   820,   560,   585,   634,
     635,   691,   770,   211,   212,   213,   214,   209,   590,   642,
     643,   592,   598,   209,   215,   216,   615,   217,   218,   219,
     220,   107,   601,   708,   393,   405,   767,   286,   604,   605,
     211,   212,   213,   214,     8,   606,   846,   847,   667,   848,
     849,   215,   216,   303,   217,   218,   219,   220,   607,   320,
     770,   823,   827,   329,   608,   314,   609,   610,   868,     8,
     611,   394,   395,     8,   324,   621,   433,   624,   835,   836,
     837,   838,   839,   333,   627,   899,   321,   322,   630,   887,
     330,   331,   633,   638,   209,   345,   323,   707,   433,   641,
     332,   709,   710,   646,   649,   651,   209,   652,   754,   783,
     360,   657,   660,   846,   847,   891,   848,   849,   670,   396,
     397,   673,   681,   373,   684,   729,   900,   901,   902,   903,
     904,   905,   906,   907,   908,   909,   910,   308,   388,   694,
     695,   852,   853,   854,   855,   711,   696,     8,   398,   697,
     698,   701,   702,   770,   770,   706,   406,   856,   857,   685,
     725,   731,   769,   781,   309,   310,   732,   211,   212,   213,
     214,   760,   733,   755,   311,   678,   782,   894,   215,   216,
     785,   217,   218,   219,   220,   790,   687,   788,   312,   809,
     473,   811,   -93,   940,   941,   794,   795,   813,   798,   313,
     861,   801,   191,   192,   193,   194,   195,   196,   197,   198,
     769,   822,   826,   872,   863,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   867,   870,   875,   433,   876,
     877,   831,   832,   833,   834,   474,   475,   476,   477,   478,
     479,   865,   835,   836,   837,   838,   839,   840,   841,   879,
     797,   799,   881,   882,   287,   304,   315,   325,   334,   346,
     361,   374,   389,   399,   407,   826,   889,   932,   933,   812,
     935,   936,   858,   895,   943,   817,   821,   825,   945,   789,
     869,   796,   600,   895,   800,   462,   483,   769,   769,   769,
     769,   769,   769,   769,   769,   769,   769,   620,   810,   888,
     871,   494,   629,   769,   769,   191,   192,   193,   194,   195,
     196,   197,   198,   688,   514,   885,   886,   504,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   637,   656,
     825,   645,   211,   212,   213,   214,   542,   527,   761,   762,
     763,   720,   680,   188,   190,   883,   884,   209,   219,   220,
     210,   669,   555,   570,   693,   700,   579,   586,   705,   792,
     793,   191,   192,   193,   194,   195,   196,   197,   198,   169,
     287,   278,   744,   893,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     0,     0,   304,     0,     0,     0,
     865,   944,   365,     0,     0,     0,     0,     0,   315,     0,
       0,     0,     8,     0,     0,   944,     0,   325,   821,   825,
     211,   212,   213,   214,     0,     0,   334,     0,     0,   366,
     367,   215,   216,     0,   217,   218,   219,   220,   346,   368,
     211,   212,   213,   214,     0,   890,     0,     0,     0,     0,
       0,   215,   216,   361,   217,   218,   219,   220,     0,     0,
     209,     0,     0,   221,     0,     0,   374,     0,     0,     0,
       0,     0,   369,   370,     0,     0,   852,   853,   854,   855,
     720,   389,     0,   371,   372,     0,   211,   212,   213,   214,
       0,   399,   856,   857,     0,     0,     0,   215,   216,   407,
     217,   218,   219,   220,   744,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,     0,   209,     0,     0,   222,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     191,   192,   193,   194,   195,   196,   197,   198,     0,     0,
       0,     0,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   191,   192,   193,   194,   195,   196,   197,
     198,     0,     0,     0,   588,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   191,   192,   193,   194,
     195,   196,   197,   198,     0,     0,   689,     0,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   191,
     192,   193,   194,   195,   196,   197,   198,     0,     0,     0,
       0,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   191,   192,   193,   194,   195,   196,   197,   198,
       0,     0,   690,     0,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   211,   212,   213,   214,     0,
       0,     0,   209,     0,     0,   223,   215,   216,     0,   217,
     218,   219,   220,     0,     0,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   209,     0,     0,   224,     0,
       0,     0,     0,     0,   721,   204,   205,   206,   207,   208,
     191,   192,   193,   194,   195,   196,   197,   198,   209,     0,
       0,   225,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,     0,     0,   745,   211,   212,   213,   214,
       0,   209,     0,     0,   226,     0,     0,   215,   216,     0,
     217,   218,   219,   220,     0,   191,   192,   193,   194,   195,
     196,   197,   198,     0,   209,     0,     0,   227,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   191,   192,
     193,   194,   195,   196,   197,   198,     0,   209,     0,     0,
     229,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   191,   192,   193,   194,   195,   196,   197,   198,     0,
       0,   703,     0,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   191,   192,   193,   194,   195,   196,
     197,   198,   209,   721,     0,     0,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   191,   192,   193,
     194,   195,   196,   197,   198,   209,     0,   745,   230,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     191,   192,   193,   194,   195,   196,   197,   198,     0,     0,
       0,     0,   758,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   211,   212,   213,   214,     0,     0,     0,
     209,     0,     0,   231,   215,   216,     0,   217,   218,   219,
     220,     0,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,     0,   209,     0,     0,   232,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   191,   192,   193,
     194,   195,   196,   197,   198,     0,   209,     0,     0,   251,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     191,   192,   193,   194,   195,   196,   197,   198,     0,   209,
       0,     0,   252,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   191,   192,   193,   194,   195,   196,   197,
     198,     0,   209,     0,     0,   450,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   191,   192,   193,   194,
     195,   196,   197,   198,     0,   209,     0,     0,   451,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   191,
     192,   193,   194,   195,   196,   197,   198,     0,     0,   862,
       0,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,     0,     0,   211,   212,   213,   214,     0,   209,
       0,     0,   597,     0,     0,   215,   216,     0,   217,   218,
     219,   220,     0,   191,   192,   193,   194,   195,   196,   197,
     198,     0,   209,     0,     0,   626,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   191,   192,   193,   194,
     195,   196,   197,   198,     0,   209,     0,     0,   661,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   191,
     192,   193,   194,   195,   196,   197,   198,     0,   209,     0,
       0,   663,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   191,   192,   193,   194,   195,   196,   197,   198,
       0,   209,     0,     0,   664,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   191,   192,   193,   194,   195,
     196,   197,   198,     0,   209,     0,     0,   665,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   191,   192,
     193,   194,   195,   196,   197,   198,   412,     0,     0,     0,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,     0,     0,   842,   843,   844,   845,     0,   209,     0,
       0,   666,     0,     0,   846,   847,     0,   848,   849,   850,
     851,     0,   191,   192,   193,   194,   195,   196,   197,   198,
       0,   209,     0,     0,   677,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   191,   192,   193,   194,   195,
     196,   197,   198,     0,   209,     0,     0,   726,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   191,   192,
     193,   194,   195,   196,   197,   198,     0,   209,     0,     0,
     727,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   191,   192,   193,   194,   195,   196,   197,   198,     0,
     209,     0,     0,   749,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   191,   192,   193,   194,   195,   196,
     197,   198,     0,   209,     0,     0,   750,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   191,   192,   193,
     194,   195,   196,   197,   198,   894,     0,     0,     0,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     831,   832,   833,   834,     0,     0,     0,   209,     0,     0,
     751,   835,   836,   837,   838,   839,   840,   841,     0,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,     0,
     209,     0,     0,   752,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   191,   192,   193,   194,   195,   196,
     197,   198,     0,   209,     0,     0,   756,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   191,   192,   193,
     194,   195,   196,   197,   198,     0,   209,     0,     0,   878,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     191,   192,   193,   194,   195,   196,   197,   198,     0,   209,
       0,     0,   880,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   191,   192,   193,   194,   195,   196,   197,
     198,     0,   209,     0,     0,   937,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   191,   192,   193,   194,
     195,   196,   197,   198,     0,     0,     0,     0,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,     0,
       0,   824,   828,     0,     0,     0,   209,     0,     0,   938,
     211,   212,   213,   214,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   217,   218,   219,   220,     0,   209,
       0,   591,   202,   203,   204,   205,   206,   207,   208,   191,
     192,   193,   194,   195,   196,     0,     0,     0,     0,     0,
       0,     0,   209,     0,   759,   892,     0,   204,   205,   206,
     207,   208,     0,   350,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,   209,   587,   912,   913,   914,
     915,   916,   917,   918,   919,   920,   921,     0,     0,     0,
     351,   352,     0,     0,     0,     0,     7,   411,   209,   338,
     353,   211,   212,   213,   214,     0,     8,     0,     0,     8,
     292,     0,   215,   216,     0,   217,   218,   219,   220,     0,
       8,   209,     0,     9,    10,     0,   339,   340,     0,     0,
      11,     0,    12,   354,   355,     0,   341,   293,   294,   356,
     357,   358,   359,     0,     0,     0,     0,   295,   296,   297,
     298,   299,   300,   301,   302,     0,    13,     0,     0,    14,
       0,   209,    15,     0,    16,     0,     0,     0,   342,   343,
     344,    17,     0,     0,     0,     0,    18,     0,     0,    19,
      20,     0,     0,    21,   209,     0,     0,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   378,    69,    70,   734,     0,     0,
       0,     0,     0,     0,     8,   281,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     8,   712,     0,     0,     0,
       0,   379,   380,     0,   735,   736,     8,     0,     0,   282,
       0,   381,   283,   284,   737,   738,     0,   739,     0,     0,
     285,     0,   713,   714,   715,   716,   717,   718,   719,   740,
     741,   742,   743,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   382,   383,   842,   843,   844,   845,
     384,   385,   386,   387,     0,     0,     0,   846,   847,     0,
     848,   849,   850,   851
};

static const short int yycheck[] =
{
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     4,
     448,     4,    22,    23,    24,    25,    26,    27,    28,    29,
     767,    31,    32,    33,    34,     5,     5,     3,     4,    98,
       6,   106,   107,    10,    11,    12,    13,     7,     8,   159,
      50,    51,   154,     9,    20,    21,     9,     5,     9,   161,
       0,    27,    30,    30,    31,    32,   159,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    10,     3,     5,     3,
       6,     9,     6,   159,     5,     5,     5,     5,     5,     5,
      12,    13,   159,     5,    20,    21,    20,    21,     5,   159,
       5,    27,     5,    27,   104,   105,   106,   107,     9,     5,
     159,     5,     5,     5,     5,   852,   853,   854,   855,   856,
     857,     5,     5,     9,    10,     5,     5,    83,     5,     5,
      83,     5,    83,     5,     5,     5,   159,     5,   159,     5,
       5,     5,     5,   159,   209,     5,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,     5,     5,   159,    45,
      46,    47,    48,    49,   164,   165,     4,     5,    10,    11,
       5,   159,     5,     5,     4,   160,   765,   160,   767,    10,
      11,   159,    83,    10,    11,     9,   923,   153,   155,   158,
     160,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     158,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   155,   150,   151,   152,    10,    11,   153,   159,   153,
     159,   459,     5,   285,   160,   160,   160,   158,   158,   158,
     158,   158,   158,   295,   296,   297,   158,   133,   158,    73,
      74,   158,   480,   158,   160,   158,    26,    27,   158,   311,
     158,   313,   158,   491,   158,   158,   158,   158,   158,   858,
     859,   323,   272,   501,   158,   158,    26,    27,   158,   158,
     332,   158,   158,   511,   158,   285,   158,   158,   158,   341,
     158,   343,   158,   158,   158,   158,   524,   158,   158,   478,
     479,   353,   730,    23,    24,    25,    26,    27,   158,   158,
     158,   539,   154,   313,   158,   153,   368,   382,   158,   384,
     385,   386,   387,   158,   552,   158,   158,   158,   155,   381,
     298,   299,   300,   301,   302,     9,   158,   158,   158,   567,
     405,   158,   394,   395,   396,   397,     3,     4,   576,     6,
       7,     8,   404,   158,   354,   583,   356,   357,   358,   359,
     158,   158,   158,    20,    21,   158,   158,   158,    10,    11,
      27,     3,   372,   159,     6,   158,     3,     4,     5,     6,
       7,     8,   382,   158,   384,   385,   386,   387,    20,    21,
      32,   158,   444,    20,    21,    27,   158,   283,   284,    73,
      27,   158,    76,   158,   158,   405,   158,   293,   294,   158,
     158,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   474,   309,   310,     3,     4,   158,     6,     7,
       8,   160,     9,   158,   154,   321,   322,     9,   866,    10,
      11,   158,    20,    21,   330,   331,   161,    19,   158,    27,
     158,    10,    11,   339,   340,   159,     9,   160,   344,    30,
      31,    32,   160,   159,     9,   351,   352,   160,   160,   355,
     160,   523,    31,    32,    46,   475,   476,   159,     9,   160,
     366,   367,   160,   369,   370,   371,     9,   160,    65,    66,
      67,    68,   160,   379,   380,   160,   153,   383,   160,   499,
     500,   566,   717,    12,    13,    14,    15,   155,   160,   509,
     510,   161,   158,   155,    23,    24,   159,    26,    27,    28,
      29,   153,   158,   588,     9,    97,   153,   290,   158,   158,
      12,    13,    14,    15,    19,   158,    23,    24,   538,    26,
      27,    23,    24,   306,    26,    27,    28,    29,   158,     9,
     765,   766,   767,     9,   158,   318,   158,   158,   786,    19,
     158,    46,    47,    19,   327,   158,   566,   158,    23,    24,
      25,    26,    27,   336,   158,   153,    36,    37,   158,   807,
      36,    37,   158,   158,   155,   348,    46,   587,   588,   158,
      46,   591,   592,   158,   158,   158,   155,   158,   650,   159,
     363,   158,   158,    23,    24,   820,    26,    27,   158,    94,
      95,   158,   158,   376,   158,   615,   831,   832,   833,   834,
     835,   836,   837,   838,   839,   840,   841,     9,   391,   158,
     158,    12,    13,    14,    15,   160,   158,    19,   401,   158,
     158,   158,   158,   858,   859,   158,   409,    28,    29,   158,
     158,   158,   717,   718,    36,    37,   158,    12,    13,    14,
      15,   713,   158,   158,    46,   551,   718,   154,    23,    24,
       9,    26,    27,    28,    29,   161,   158,   160,    60,   160,
       9,   157,    18,   898,   899,   737,   738,   158,   740,    71,
      18,   743,    10,    11,    12,    13,    14,    15,    16,    17,
     765,   766,   767,   160,   158,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   158,   158,   158,   718,   158,
     158,    12,    13,    14,    15,    54,    55,    56,    57,    58,
      59,   783,    23,    24,    25,    26,    27,    28,    29,   158,
     740,   741,   158,   158,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   820,   158,   153,   161,   759,
     158,   158,    10,   154,   932,   765,   766,   767,   160,   723,
     787,   739,   460,   154,   742,   290,   306,   842,   843,   844,
     845,   846,   847,   848,   849,   850,   851,   481,   747,   808,
     790,   318,   492,   858,   859,    10,    11,    12,    13,    14,
      15,    16,    17,   158,   336,   805,   806,   327,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,   502,   525,
     820,   512,    12,    13,    14,    15,   363,   348,   714,   715,
     716,   594,   553,   898,   899,   803,   804,   155,    28,    29,
     158,   540,   376,   391,   568,   577,   401,   409,   584,   735,
     736,    10,    11,    12,    13,    14,    15,    16,    17,    85,
     290,   167,   625,   154,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,   306,    -1,    -1,    -1,
     932,   933,     9,    -1,    -1,    -1,    -1,    -1,   318,    -1,
      -1,    -1,    19,    -1,    -1,   947,    -1,   327,   898,   899,
      12,    13,    14,    15,    -1,    -1,   336,    -1,    -1,    36,
      37,    23,    24,    -1,    26,    27,    28,    29,   348,    46,
      12,    13,    14,    15,    -1,   811,    -1,    -1,    -1,    -1,
      -1,    23,    24,   363,    26,    27,    28,    29,    -1,    -1,
     155,    -1,    -1,   158,    -1,    -1,   376,    -1,    -1,    -1,
      -1,    -1,    79,    80,    -1,    -1,    12,    13,    14,    15,
     723,   391,    -1,    90,    91,    -1,    12,    13,    14,    15,
      -1,   401,    28,    29,    -1,    -1,    -1,    23,    24,   409,
      26,    27,    28,    29,   747,    -1,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,   155,    -1,    -1,   158,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,   156,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,   158,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,   158,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    12,    13,    14,    15,    -1,
      -1,    -1,   155,    -1,    -1,   158,    23,    24,    -1,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,   155,    -1,    -1,   158,    -1,
      -1,    -1,    -1,    -1,   594,    28,    29,    30,    31,    32,
      10,    11,    12,    13,    14,    15,    16,    17,   155,    -1,
      -1,   158,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,   625,    12,    13,    14,    15,
      -1,   155,    -1,    -1,   158,    -1,    -1,    23,    24,    -1,
      26,    27,    28,    29,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,   155,    -1,    -1,   158,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,   155,    -1,    -1,
     158,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,   158,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    10,    11,    12,    13,    14,    15,
      16,    17,   155,   723,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    10,    11,    12,
      13,    14,    15,    16,    17,   155,    -1,   747,   158,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,   158,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    12,    13,    14,    15,    -1,    -1,    -1,
     155,    -1,    -1,   158,    23,    24,    -1,    26,    27,    28,
      29,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,   155,    -1,    -1,   158,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,   155,    -1,    -1,   158,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,   155,
      -1,    -1,   158,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,   155,    -1,    -1,   158,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,   155,    -1,    -1,   158,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,   158,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    12,    13,    14,    15,    -1,   155,
      -1,    -1,   158,    -1,    -1,    23,    24,    -1,    26,    27,
      28,    29,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,   155,    -1,    -1,   158,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,   155,    -1,    -1,   158,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,   155,    -1,
      -1,   158,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,   155,    -1,    -1,   158,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,   155,    -1,    -1,   158,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    10,    11,
      12,    13,    14,    15,    16,    17,   154,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    12,    13,    14,    15,    -1,   155,    -1,
      -1,   158,    -1,    -1,    23,    24,    -1,    26,    27,    28,
      29,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,   155,    -1,    -1,   158,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,   155,    -1,    -1,   158,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,   155,    -1,    -1,
     158,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
     155,    -1,    -1,   158,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,   155,    -1,    -1,   158,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    10,    11,    12,
      13,    14,    15,    16,    17,   154,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      12,    13,    14,    15,    -1,    -1,    -1,   155,    -1,    -1,
     158,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
     155,    -1,    -1,   158,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,   155,    -1,    -1,   158,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,   155,    -1,    -1,   158,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,   155,
      -1,    -1,   158,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,   155,    -1,    -1,   158,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,   766,   767,    -1,    -1,    -1,   155,    -1,    -1,   158,
      12,    13,    14,    15,    -1,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    26,    27,    28,    29,    -1,   155,
      -1,   157,    26,    27,    28,    29,    30,    31,    32,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,    -1,   157,   820,    -1,    28,    29,    30,
      31,    32,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,   155,   156,   842,   843,   844,
     845,   846,   847,   848,   849,   850,   851,    -1,    -1,    -1,
      36,    37,    -1,    -1,    -1,    -1,     9,   154,   155,     9,
      46,    12,    13,    14,    15,    -1,    19,    -1,    -1,    19,
       9,    -1,    23,    24,    -1,    26,    27,    28,    29,    -1,
      19,   155,    -1,    36,    37,    -1,    36,    37,    -1,    -1,
      43,    -1,    45,    79,    80,    -1,    46,    36,    37,    85,
      86,    87,    88,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    69,    -1,    -1,    72,
      -1,   155,    75,    -1,    77,    -1,    -1,    -1,    78,    79,
      80,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    -1,    96,   155,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     9,   148,   149,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    19,     9,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,     9,    -1,    -1,    -1,
      -1,    36,    37,    -1,    36,    37,    19,    -1,    -1,    33,
      -1,    46,    36,    37,    46,    47,    -1,    49,    -1,    -1,
      44,    -1,    35,    36,    37,    38,    39,    40,    41,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    80,    12,    13,    14,    15,
      85,    86,    87,    88,    -1,    -1,    -1,    23,    24,    -1,
      26,    27,    28,    29
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,    98,   281,   288,   159,     0,   282,     9,    19,    36,
      37,    43,    45,    69,    72,    75,    77,    84,    89,    92,
      93,    96,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   148,
     149,   187,   189,   197,   204,   218,   225,   232,   239,   246,
     253,   260,   267,   274,   283,   284,   285,   159,     5,   173,
     173,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,     3,     6,    20,    21,    27,   153,   163,   164,
     163,   163,   163,   163,   163,   163,   163,     7,     8,   175,
     163,   163,   163,   163,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   159,   186,   173,   173,   173,   173,   173,
     163,   163,     4,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,     9,   150,   151,   152,   286,   287,   160,   283,
     160,     5,   158,   158,   198,   205,   219,   226,   233,   240,
     247,   254,   261,   268,   275,   163,   163,   163,   164,   163,
     164,    10,    11,    12,    13,    14,    15,    16,    17,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   155,
     158,    12,    13,    14,    15,    23,    24,    26,    27,    28,
      29,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   160,   173,   181,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   159,   184,   163,   163,   160,   188,   286,   158,
     158,     9,    33,    36,    37,    44,   187,   189,   190,   199,
     200,   201,     9,    36,    37,    46,    47,    48,    49,    50,
      51,    52,    53,   187,   189,   206,   207,   208,     9,    36,
      37,    46,    60,    71,   187,   189,   211,   220,   221,   222,
       9,    36,    37,    46,   187,   189,   227,   228,   229,     9,
      36,    37,    46,   187,   189,   234,   235,   236,     9,    36,
      37,    46,    78,    79,    80,   187,   189,   241,   242,   243,
       9,    36,    37,    46,    79,    80,    85,    86,    87,    88,
     187,   189,   248,   249,   250,     9,    36,    37,    46,    79,
      80,    90,    91,   187,   189,   255,   256,   257,     9,    36,
      37,    46,    79,    80,    85,    86,    87,    88,   187,   189,
     262,   263,   264,     9,    46,    47,    94,    95,   187,   189,
     269,   270,   271,     9,    46,    97,   187,   189,   276,   277,
     278,   154,   154,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   164,   163,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   161,   182,   160,   163,   178,   158,
     158,   158,   158,   159,   173,   173,   163,   174,     9,   202,
     203,   160,   199,   173,   173,   174,   174,   174,   175,   175,
     175,   175,   175,     9,    54,    55,    56,    57,    58,    59,
     209,   210,   160,   206,   173,   173,   174,   159,   163,   174,
       9,   223,   224,   160,   220,   173,   173,   174,     9,    73,
      74,   230,   231,   160,   227,   173,   173,   174,     9,    73,
      76,   237,   238,   160,   234,   173,   173,   174,   159,   177,
     174,   173,     9,    83,   244,   245,   160,   241,   173,   173,
     174,   163,   173,   163,   163,   163,   163,     9,    83,   251,
     252,   160,   248,   173,   173,   174,   173,   173,   173,   163,
       9,    83,   258,   259,   160,   255,   173,   173,   174,   164,
     173,   164,   164,   164,   164,     9,    83,   265,   266,   160,
     262,   174,   174,   174,   174,     9,   272,   273,   160,   269,
     174,   164,     9,   279,   280,   160,   276,   156,   156,   174,
     160,   157,   161,   182,   191,   158,   158,   158,   158,   188,
     202,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   174,   163,   163,   159,   183,   183,   183,   188,
     209,   158,   158,   158,   158,   212,   158,   158,   188,   223,
     158,   158,   158,   158,   163,   163,   188,   230,   158,   158,
     158,   158,   163,   163,   188,   237,   158,   158,   158,   158,
     176,   158,   158,   158,   174,   188,   244,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   163,   188,   251,
     158,   158,   158,   158,   158,   158,   158,   158,   173,   188,
     258,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   164,   188,   265,   158,   158,   158,   158,   158,   188,
     272,   158,   158,   158,   188,   279,   158,   163,   164,   163,
     163,   160,     9,    35,    36,    37,    38,    39,    40,    41,
     187,   189,   192,   193,   194,   158,   158,   158,   160,   163,
     179,   158,   158,   158,     9,    36,    37,    46,    47,    49,
      61,    62,    63,    64,   187,   189,   213,   214,   215,   158,
     158,   158,   158,   160,   174,   158,   158,   158,   158,   157,
     174,   173,   173,   173,     4,    20,    27,   153,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   164,   174,   159,   185,     9,   195,   196,   160,   192,
     161,   182,   173,   173,   174,   174,   175,   163,   174,   163,
     175,   174,     9,    65,    66,    67,    68,   216,   217,   160,
     213,   157,   163,   158,   158,   158,   158,   163,   172,     4,
     153,   163,   164,   165,   166,   163,   164,   165,   166,   167,
     172,    12,    13,    14,    15,    23,    24,    25,    26,    27,
      28,    29,    12,    13,    14,    15,    23,    24,    26,    27,
      28,    29,    12,    13,    14,    15,    28,    29,    10,    11,
     158,    18,   158,   158,   160,   174,   180,   158,   188,   195,
     158,   163,   160,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   175,   175,   163,   163,   188,   216,   158,
     173,   165,   166,   154,   154,   154,   154,     4,    27,   153,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,     4,   153,   167,   167,   167,   167,   167,   167,
     172,   172,   153,   161,   182,   158,   158,   158,   158,   158,
     165,   165,   167,   180,   174,   160,   154,   161
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
#line 527 "parser1.1.ypp"
    { yyval.intval=-yyvsp[0].intval; }
    break;

  case 4:
#line 528 "parser1.1.ypp"
    { yyval.intval= yyvsp[-1].intval; }
    break;

  case 5:
#line 529 "parser1.1.ypp"
    { yyval.intval=!yyvsp[0].intval; }
    break;

  case 6:
#line 530 "parser1.1.ypp"
    { yyval.intval=~yyvsp[0].intval; }
    break;

  case 7:
#line 531 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval*yyvsp[0].intval; }
    break;

  case 8:
#line 532 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval/yyvsp[0].intval; }
    break;

  case 9:
#line 533 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval%yyvsp[0].intval; }
    break;

  case 10:
#line 534 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval+yyvsp[0].intval; }
    break;

  case 11:
#line 535 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval-yyvsp[0].intval; }
    break;

  case 12:
#line 536 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval<<yyvsp[0].intval; }
    break;

  case 13:
#line 537 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval>>yyvsp[0].intval; }
    break;

  case 14:
#line 538 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval<yyvsp[0].intval; }
    break;

  case 15:
#line 539 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval<=yyvsp[0].intval; }
    break;

  case 16:
#line 540 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval>yyvsp[0].intval; }
    break;

  case 17:
#line 541 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval>=yyvsp[0].intval; }
    break;

  case 18:
#line 542 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval==yyvsp[0].intval; }
    break;

  case 19:
#line 543 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval!=yyvsp[0].intval; }
    break;

  case 20:
#line 544 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].fval<yyvsp[0].fval; }
    break;

  case 21:
#line 545 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].fval<=yyvsp[0].fval; }
    break;

  case 22:
#line 546 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].fval>yyvsp[0].fval; }
    break;

  case 23:
#line 547 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].fval>=yyvsp[0].fval; }
    break;

  case 24:
#line 548 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].fval==yyvsp[0].fval; }
    break;

  case 25:
#line 549 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].fval!=yyvsp[0].fval; }
    break;

  case 26:
#line 550 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval&yyvsp[0].intval; }
    break;

  case 27:
#line 551 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval^yyvsp[0].intval; }
    break;

  case 28:
#line 552 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval|yyvsp[0].intval; }
    break;

  case 29:
#line 553 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval&&yyvsp[0].intval; }
    break;

  case 30:
#line 554 "parser1.1.ypp"
    { yyval.intval=yyvsp[-2].intval||yyvsp[0].intval; }
    break;

  case 31:
#line 555 "parser1.1.ypp"
    { yyval.intval=yyvsp[-4].intval?yyvsp[-2].intval:yyvsp[0].intval; }
    break;

  case 33:
#line 557 "parser1.1.ypp"
    { yyval.fval=yyvsp[0].intval; }
    break;

  case 34:
#line 558 "parser1.1.ypp"
    { yyval.fval=-yyvsp[0].fval; }
    break;

  case 35:
#line 559 "parser1.1.ypp"
    { yyval.fval= yyvsp[-1].fval; }
    break;

  case 36:
#line 560 "parser1.1.ypp"
    { yyval.fval=yyvsp[-2].fval*yyvsp[0].fval; }
    break;

  case 37:
#line 561 "parser1.1.ypp"
    { yyval.fval=yyvsp[-2].fval/yyvsp[0].fval; }
    break;

  case 38:
#line 562 "parser1.1.ypp"
    { yyval.fval=yyvsp[-2].fval+yyvsp[0].fval; }
    break;

  case 39:
#line 563 "parser1.1.ypp"
    { yyval.fval=yyvsp[-2].fval-yyvsp[0].fval; }
    break;

  case 40:
#line 564 "parser1.1.ypp"
    { yyval.fval=yyvsp[-4].intval?yyvsp[-2].fval:yyvsp[0].fval; }
    break;

  case 41:
#line 565 "parser1.1.ypp"
    { yyval.expr=new Expr; yyval.expr->i=yyvsp[0].intval; yyval.expr->Type=Expr::E_INT; }
    break;

  case 42:
#line 566 "parser1.1.ypp"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 43:
#line 567 "parser1.1.ypp"
    { yyval.expr=new Expr; yyval.expr->s=yyvsp[0].str;yyval.expr->Type=Expr::E_PAR; }
    break;

  case 44:
#line 568 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[0].expr;yyval.expr->Type=Expr::E_NEG;}
    break;

  case 45:
#line 569 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_PLUS;}
    break;

  case 46:
#line 570 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_MINUS;}
    break;

  case 47:
#line 571 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_DIV;}
    break;

  case 48:
#line 572 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_MOD;}
    break;

  case 49:
#line 573 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_MUL;}
    break;

  case 50:
#line 574 "parser1.1.ypp"
    { yyval.expr=new Expr; yyval.expr->i=yyvsp[0].bval; yyval.expr->Type=Expr::E_INT; }
    break;

  case 51:
#line 575 "parser1.1.ypp"
    { yyval.expr=new Expr; yyval.expr->f=yyvsp[0].fval; yyval.expr->Type=Expr::E_FLOAT; }
    break;

  case 52:
#line 576 "parser1.1.ypp"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 53:
#line 577 "parser1.1.ypp"
    { yyval.expr=new Expr; yyval.expr->s=yyvsp[0].str;yyval.expr->Type=Expr::E_PAR; }
    break;

  case 54:
#line 578 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[0].expr;yyval.expr->Type=Expr::E_NEG;}
    break;

  case 55:
#line 579 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_PLUS;}
    break;

  case 56:
#line 580 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_MINUS;}
    break;

  case 57:
#line 581 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_DIV;}
    break;

  case 58:
#line 582 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_MUL;}
    break;

  case 60:
#line 584 "parser1.1.ypp"
    { yyval.expr=new Expr; yyval.expr->s=*yyvsp[0].string; yyval.expr->Type=Expr::E_STRING; delete yyvsp[0].string;}
    break;

  case 61:
#line 585 "parser1.1.ypp"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 62:
#line 586 "parser1.1.ypp"
    { yyval.expr=new Expr; yyval.expr->s=yyvsp[0].str;yyval.expr->Type=Expr::E_PAR; }
    break;

  case 63:
#line 587 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_EQ;}
    break;

  case 64:
#line 588 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_NE;}
    break;

  case 65:
#line 589 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_LE;}
    break;

  case 66:
#line 590 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_GE;}
    break;

  case 67:
#line 591 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_LT;}
    break;

  case 68:
#line 592 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_GT;}
    break;

  case 69:
#line 593 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_EQ;}
    break;

  case 70:
#line 594 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_NE;}
    break;

  case 71:
#line 595 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_LE;}
    break;

  case 72:
#line 596 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_GE;}
    break;

  case 73:
#line 597 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_LT;}
    break;

  case 74:
#line 598 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_GT;}
    break;

  case 75:
#line 599 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_EQ;}
    break;

  case 76:
#line 600 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_NE;}
    break;

  case 77:
#line 601 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_LE;}
    break;

  case 78:
#line 602 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_GE;}
    break;

  case 79:
#line 603 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_LT;}
    break;

  case 80:
#line 604 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_GT;}
    break;

  case 81:
#line 605 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[0].expr;yyval.expr->Type=Expr::E_NOTNULL;}
    break;

  case 82:
#line 606 "parser1.1.ypp"
    { yyval.expr=new Expr; yyval.expr->s=*yyvsp[-4].string;delete yyvsp[-4].string;yyval.expr->id=*yyvsp[-1].identarray;delete yyvsp[-1].identarray;yyval.expr->Type=Expr::E_IN; }
    break;

  case 83:
#line 607 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_AND;}
    break;

  case 84:
#line 608 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[0].expr;yyval.expr->Type=Expr::E_NOT;}
    break;

  case 85:
#line 609 "parser1.1.ypp"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 86:
#line 610 "parser1.1.ypp"
    { yyval.expr=new Expr;yyval.expr->op1=yyvsp[-2].expr;yyval.expr->op2=yyvsp[0].expr;yyval.expr->Type=Expr::E_OR;}
    break;

  case 91:
#line 612 "parser1.1.ypp"
    {yyval.string=unescapeString(yyvsp[0].str); }
    break;

  case 92:
#line 612 "parser1.1.ypp"
    { String* n=unescapeString(yyvsp[0].str); (*yyvsp[-1].string)+=*n;delete n; }
    break;

  case 93:
#line 613 "parser1.1.ypp"
    {yyval.string=new String(yyvsp[0].str); }
    break;

  case 94:
#line 614 "parser1.1.ypp"
    { yyval.bval=1; }
    break;

  case 95:
#line 614 "parser1.1.ypp"
    { yyval.bval=0; }
    break;

  case 96:
#line 615 "parser1.1.ypp"
    { yyval.map=new IdentMap; }
    break;

  case 97:
#line 615 "parser1.1.ypp"
    {Map m;m.Name=*yyvsp[-3].string; m.Value=*yyvsp[-1].string;delete yyvsp[-3].string; delete yyvsp[-1].string; yyvsp[-4].map->add(m); yyval.map=yyvsp[-4].map; }
    break;

  case 98:
#line 616 "parser1.1.ypp"
    { yyval.map=yyvsp[-1].map;}
    break;

  case 99:
#line 617 "parser1.1.ypp"
    { yyval.keymaparray=new KeyMapArray; yyval.keymaparray->add(KeyMap(yyvsp[-2].intval,yyvsp[0].intval)); }
    break;

  case 100:
#line 617 "parser1.1.ypp"
    {yyvsp[-4].keymaparray->add(KeyMap(yyvsp[-2].intval,yyvsp[0].intval)); yyval.keymaparray=yyvsp[-4].keymaparray; }
    break;

  case 101:
#line 618 "parser1.1.ypp"
    { yyval.intarray=new IntArray; yyval.intarray->add(yyvsp[0].intval); }
    break;

  case 102:
#line 618 "parser1.1.ypp"
    {yyvsp[-2].intarray->add(yyvsp[0].intval); yyval.intarray=yyvsp[-2].intarray; }
    break;

  case 103:
#line 619 "parser1.1.ypp"
    { yyval.identarray=new IdentArray; yyval.identarray->add(*yyvsp[0].string); delete yyvsp[0].string; }
    break;

  case 104:
#line 619 "parser1.1.ypp"
    {yyvsp[-2].identarray->add(*yyvsp[0].string); delete yyvsp[0].string; yyval.identarray=yyvsp[-2].identarray; }
    break;

  case 105:
#line 620 "parser1.1.ypp"
    { yyval.stringarray=new StringArray; yyval.stringarray->add(*yyvsp[0].string); delete yyvsp[0].string; }
    break;

  case 106:
#line 620 "parser1.1.ypp"
    {yyvsp[-2].stringarray->add(*yyvsp[0].string); delete yyvsp[0].string; yyval.stringarray=yyvsp[-2].stringarray; }
    break;

  case 109:
#line 622 "parser1.1.ypp"
    {yyval.intarray=new IntArray; }
    break;

  case 110:
#line 623 "parser1.1.ypp"
    { yyval.intarray=yyvsp[-2].intarray;}
    break;

  case 111:
#line 624 "parser1.1.ypp"
    {yyval.keymaparray=new KeyMapArray; }
    break;

  case 112:
#line 625 "parser1.1.ypp"
    { yyval.keymaparray=yyvsp[-2].keymaparray;}
    break;

  case 113:
#line 626 "parser1.1.ypp"
    {yyval.identarray=new IdentArray; }
    break;

  case 114:
#line 627 "parser1.1.ypp"
    { yyval.identarray=yyvsp[-2].identarray;}
    break;

  case 115:
#line 628 "parser1.1.ypp"
    {yyval.stringarray=new StringArray; }
    break;

  case 116:
#line 629 "parser1.1.ypp"
    { yyval.stringarray=yyvsp[-2].stringarray;}
    break;

  case 120:
#line 633 "parser1.1.ypp"
    { Interface* a=new Interface;stack.push(a);a->lineno=yylineno; }
    break;

  case 121:
#line 633 "parser1.1.ypp"
    {yyval.Interfaces=(typeof(yyval.Interfaces))stack.pop();}
    break;

  case 126:
#line 634 "parser1.1.ypp"
    { typeof(yyval.Interfaces) a =(typeof(yyval.Interfaces))(stack.top());if(a->Abbreviation_lineno)parserError(_("%s already set at line %d"),"Abbreviation",a->Abbreviation_lineno);a->Abbreviation_lineno=yylineno;; a->Abbreviation=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 127:
#line 635 "parser1.1.ypp"
    { typeof(yyval.Interfaces) a =(typeof(yyval.Interfaces))(stack.top());if(a->Title_lineno)parserError(_("%s already set at line %d"),"Title",a->Title_lineno);a->Title_lineno=yylineno;; a->Title=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 128:
#line 636 "parser1.1.ypp"
    { typeof(yyval.Interfaces) a =(typeof(yyval.Interfaces))(stack.top());if(a->AddInfo_lineno)parserError(_("%s already set at line %d"),"AddInfo",a->AddInfo_lineno);a->AddInfo_lineno=yylineno;; a->AddInfo=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 129:
#line 637 "parser1.1.ypp"
    { typeof(yyval.Interfaces) a =(typeof(yyval.Interfaces))(stack.top());if(a->GroupTitle_lineno)parserError(_("%s already set at line %d"),"GroupTitle",a->GroupTitle_lineno);a->GroupTitle_lineno=yylineno;; a->GroupTitle=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 130:
#line 638 "parser1.1.ypp"
    { typeof(yyval.Interfaces) a =(typeof(yyval.Interfaces))(stack.top()); if(a->InvisibleIf_lineno)parserError(_("%s already set at line %d"),"InvisibleIf",a->InvisibleIf_lineno);a->InvisibleIf_lineno=yylineno;; a->InvisibleIf=yyvsp[-1].expr; }
    break;

  case 131:
#line 639 "parser1.1.ypp"
    { typeof(yyval.Interfaces) a =(typeof(yyval.Interfaces))(stack.top());if(a->DPType_lineno)parserError(_("%s already set at line %d"),"DPType",a->DPType_lineno);a->DPType_lineno=yylineno;; a->DPType=yyvsp[-1].fval;}
    break;

  case 132:
#line 639 "parser1.1.ypp"
    { typeof(yyval.Interfaces) a =(typeof(yyval.Interfaces))(stack.top());if(a->DPType_lineno)parserError(_("%s already set at line %d"),"DPType",a->DPType_lineno);a->DPType_lineno=yylineno;; a->DPType=Map_DPType(*yyvsp[-1].string);delete yyvsp[-1].string;}
    break;

  case 133:
#line 640 "parser1.1.ypp"
    { typeof(yyval.Interfaces) a =(typeof(yyval.Interfaces))(stack.top()); if(a->Reference_lineno)parserError(_("%s already set at line %d"),"Reference",a->Reference_lineno);a->Reference_lineno=yylineno;; a->Reference=*yyvsp[-1].identarray; delete yyvsp[-1].identarray; }
    break;

  case 134:
#line 641 "parser1.1.ypp"
    { yyval.Interfaces; }
    break;

  case 135:
#line 641 "parser1.1.ypp"
    { yyval.Interfaces; }
    break;

  case 138:
#line 642 "parser1.1.ypp"
    { yyval.Interfaces; }
    break;

  case 139:
#line 643 "parser1.1.ypp"
    { FunctionalBlock* a=new FunctionalBlock;stack.push(a);a->lineno=yylineno; }
    break;

  case 140:
#line 643 "parser1.1.ypp"
    {yyval.FunctionalBlocks=(typeof(yyval.FunctionalBlocks))stack.pop();}
    break;

  case 145:
#line 644 "parser1.1.ypp"
    { typeof(yyval.FunctionalBlocks) a =(typeof(yyval.FunctionalBlocks))(stack.top());if(a->Title_lineno)parserError(_("%s already set at line %d"),"Title",a->Title_lineno);a->Title_lineno=yylineno;; a->Title=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 146:
#line 645 "parser1.1.ypp"
    { typeof(yyval.FunctionalBlocks) a =(typeof(yyval.FunctionalBlocks))(stack.top());if(a->AddInfo_lineno)parserError(_("%s already set at line %d"),"AddInfo",a->AddInfo_lineno);a->AddInfo_lineno=yylineno;; a->AddInfo=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 147:
#line 646 "parser1.1.ypp"
    { typeof(yyval.FunctionalBlocks) a =(typeof(yyval.FunctionalBlocks))(stack.top());if(a->ProfileID_lineno)parserError(_("%s already set at line %d"),"ProfileID",a->ProfileID_lineno);a->ProfileID_lineno=yylineno;; a->ProfileID=yyvsp[-1].intval;}
    break;

  case 148:
#line 646 "parser1.1.ypp"
    { typeof(yyval.FunctionalBlocks) a =(typeof(yyval.FunctionalBlocks))(stack.top());if(a->ProfileID_lineno)parserError(_("%s already set at line %d"),"ProfileID",a->ProfileID_lineno);a->ProfileID_lineno=yylineno;; a->ProfileID=Map_ProfileID(*yyvsp[-1].string);delete yyvsp[-1].string;}
    break;

  case 149:
#line 647 "parser1.1.ypp"
    { typeof(yyval.FunctionalBlocks) a =(typeof(yyval.FunctionalBlocks))(stack.top()); a->Interfaces.add(*yyvsp[0].Interfaces); delete yyvsp[0].Interfaces; }
    break;

  case 150:
#line 648 "parser1.1.ypp"
    { yyval.FunctionalBlocks; }
    break;

  case 151:
#line 648 "parser1.1.ypp"
    { yyval.FunctionalBlocks; }
    break;

  case 154:
#line 649 "parser1.1.ypp"
    { yyval.FunctionalBlocks; }
    break;

  case 155:
#line 650 "parser1.1.ypp"
    { GroupObject* a=new GroupObject;stack.push(a);a->lineno=yylineno; }
    break;

  case 156:
#line 650 "parser1.1.ypp"
    {yyval.GroupObjects=(typeof(yyval.GroupObjects))stack.pop();}
    break;

  case 161:
#line 651 "parser1.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 162:
#line 652 "parser1.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->Type_lineno)parserError(_("%s already set at line %d"),"Type",a->Type_lineno);a->Type_lineno=yylineno;; a->Type=Map_GroupType(*yyvsp[-1].string);delete yyvsp[-1].string;}
    break;

  case 163:
#line 653 "parser1.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->on_update_lineno)parserError(_("%s already set at line %d"),"on_update",a->on_update_lineno);a->on_update_lineno=yylineno;; a->on_update=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 164:
#line 654 "parser1.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->eeprom_lineno)parserError(_("%s already set at line %d"),"eeprom",a->eeprom_lineno);a->eeprom_lineno=yylineno;; a->eeprom=yyvsp[-1].bval;}
    break;

  case 165:
#line 655 "parser1.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->Sending_lineno)parserError(_("%s already set at line %d"),"Sending",a->Sending_lineno);a->Sending_lineno=yylineno;; a->Sending=yyvsp[-1].bval;}
    break;

  case 166:
#line 656 "parser1.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->Receiving_lineno)parserError(_("%s already set at line %d"),"Receiving",a->Receiving_lineno);a->Receiving_lineno=yylineno;; a->Receiving=yyvsp[-1].bval;}
    break;

  case 167:
#line 657 "parser1.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->Reading_lineno)parserError(_("%s already set at line %d"),"Reading",a->Reading_lineno);a->Reading_lineno=yylineno;; a->Reading=yyvsp[-1].bval;}
    break;

  case 168:
#line 658 "parser1.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->Title_lineno)parserError(_("%s already set at line %d"),"Title",a->Title_lineno);a->Title_lineno=yylineno;; a->Title=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 169:
#line 659 "parser1.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->AddInfo_lineno)parserError(_("%s already set at line %d"),"AddInfo",a->AddInfo_lineno);a->AddInfo_lineno=yylineno;; a->AddInfo=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 170:
#line 660 "parser1.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->StateBased_lineno)parserError(_("%s already set at line %d"),"StateBased",a->StateBased_lineno);a->StateBased_lineno=yylineno;; a->StateBased=yyvsp[-1].bval;}
    break;

  case 171:
#line 663 "parser1.1.ypp"
    { yyval.GroupObjects; }
    break;

  case 172:
#line 663 "parser1.1.ypp"
    { yyval.GroupObjects; }
    break;

  case 175:
#line 664 "parser1.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->Priority_lineno)parserError(_("%s already set at line %d"),"Priority",a->Priority_lineno);a->Priority_lineno=yylineno;; a->Priority=Map_Prio(*yyvsp[-1].string);delete yyvsp[-1].string;}
    break;

  case 176:
#line 665 "parser1.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->SendAddress_lineno)parserError(_("%s already set at line %d"),"SendAddress",a->SendAddress_lineno);a->SendAddress_lineno=yylineno;; a->SendAddress=yyvsp[-1].intval;}
    break;

  case 177:
#line 666 "parser1.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top());if(a->ReadRequestAddress_lineno)parserError(_("%s already set at line %d"),"ReadRequestAddress",a->ReadRequestAddress_lineno);a->ReadRequestAddress_lineno=yylineno;; a->ReadRequestAddress=yyvsp[-1].intval;}
    break;

  case 178:
#line 667 "parser1.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top()); if(a->ReceiveAddress_lineno)parserError(_("%s already set at line %d"),"ReceiveAddress",a->ReceiveAddress_lineno);a->ReceiveAddress_lineno=yylineno;; a->ReceiveAddress=*yyvsp[-1].intarray; delete yyvsp[-1].intarray; }
    break;

  case 179:
#line 668 "parser1.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top()); if(a->ReadAddress_lineno)parserError(_("%s already set at line %d"),"ReadAddress",a->ReadAddress_lineno);a->ReadAddress_lineno=yylineno;; a->ReadAddress=*yyvsp[-1].intarray; delete yyvsp[-1].intarray; }
    break;

  case 180:
#line 669 "parser1.1.ypp"
    { typeof(yyval.GroupObjects) a =(typeof(yyval.GroupObjects))(stack.top()); if(a->UpdateAddress_lineno)parserError(_("%s already set at line %d"),"UpdateAddress",a->UpdateAddress_lineno);a->UpdateAddress_lineno=yylineno;; a->UpdateAddress=*yyvsp[-1].intarray; delete yyvsp[-1].intarray; }
    break;

  case 181:
#line 670 "parser1.1.ypp"
    { yyval.GroupObjects; }
    break;

  case 182:
#line 671 "parser1.1.ypp"
    { Property* a=new Property;stack.push(a);a->lineno=yylineno; }
    break;

  case 183:
#line 671 "parser1.1.ypp"
    {yyval.Propertys=(typeof(yyval.Propertys))stack.pop();}
    break;

  case 188:
#line 672 "parser1.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 189:
#line 673 "parser1.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->Type_lineno)parserError(_("%s already set at line %d"),"Type",a->Type_lineno);a->Type_lineno=yylineno;; a->Type=Map_PropertyType(*yyvsp[-1].string);delete yyvsp[-1].string;}
    break;

  case 190:
#line 674 "parser1.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->PropertyID_lineno)parserError(_("%s already set at line %d"),"PropertyID",a->PropertyID_lineno);a->PropertyID_lineno=yylineno;; a->PropertyID=yyvsp[-1].intval;}
    break;

  case 191:
#line 674 "parser1.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->PropertyID_lineno)parserError(_("%s already set at line %d"),"PropertyID",a->PropertyID_lineno);a->PropertyID_lineno=yylineno;; a->PropertyID=Map_PropertyID(*yyvsp[-1].string);delete yyvsp[-1].string;}
    break;

  case 192:
#line 675 "parser1.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->MaxArrayLength_lineno)parserError(_("%s already set at line %d"),"MaxArrayLength",a->MaxArrayLength_lineno);a->MaxArrayLength_lineno=yylineno;; a->MaxArrayLength=yyvsp[-1].intval;}
    break;

  case 193:
#line 676 "parser1.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->Writeable_lineno)parserError(_("%s already set at line %d"),"Writeable",a->Writeable_lineno);a->Writeable_lineno=yylineno;; a->Writeable=yyvsp[-1].bval;}
    break;

  case 194:
#line 677 "parser1.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->eeprom_lineno)parserError(_("%s already set at line %d"),"eeprom",a->eeprom_lineno);a->eeprom_lineno=yylineno;; a->eeprom=yyvsp[-1].bval;}
    break;

  case 195:
#line 678 "parser1.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->handler_lineno)parserError(_("%s already set at line %d"),"handler",a->handler_lineno);a->handler_lineno=yylineno;; a->handler=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 196:
#line 679 "parser1.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->Title_lineno)parserError(_("%s already set at line %d"),"Title",a->Title_lineno);a->Title_lineno=yylineno;; a->Title=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 197:
#line 680 "parser1.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->AddInfo_lineno)parserError(_("%s already set at line %d"),"AddInfo",a->AddInfo_lineno);a->AddInfo_lineno=yylineno;; a->AddInfo=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 198:
#line 681 "parser1.1.ypp"
    { yyval.Propertys; }
    break;

  case 199:
#line 681 "parser1.1.ypp"
    { yyval.Propertys; }
    break;

  case 202:
#line 682 "parser1.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->Disable_lineno)parserError(_("%s already set at line %d"),"Disable",a->Disable_lineno);a->Disable_lineno=yylineno;; a->Disable=yyvsp[-1].bval;}
    break;

  case 203:
#line 683 "parser1.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->ReadOnly_lineno)parserError(_("%s already set at line %d"),"ReadOnly",a->ReadOnly_lineno);a->ReadOnly_lineno=yylineno;; a->ReadOnly=yyvsp[-1].bval;}
    break;

  case 204:
#line 684 "parser1.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->ReadAccess_lineno)parserError(_("%s already set at line %d"),"ReadAccess",a->ReadAccess_lineno);a->ReadAccess_lineno=yylineno;; a->ReadAccess=yyvsp[-1].intval;}
    break;

  case 205:
#line 685 "parser1.1.ypp"
    { typeof(yyval.Propertys) a =(typeof(yyval.Propertys))(stack.top());if(a->WriteAccess_lineno)parserError(_("%s already set at line %d"),"WriteAccess",a->WriteAccess_lineno);a->WriteAccess_lineno=yylineno;; a->WriteAccess=yyvsp[-1].intval;}
    break;

  case 206:
#line 686 "parser1.1.ypp"
    { yyval.Propertys; }
    break;

  case 207:
#line 687 "parser1.1.ypp"
    { Object* a=new Object;stack.push(a);a->lineno=yylineno; }
    break;

  case 208:
#line 687 "parser1.1.ypp"
    {yyval.Objects=(typeof(yyval.Objects))stack.pop();}
    break;

  case 213:
#line 688 "parser1.1.ypp"
    { typeof(yyval.Objects) a =(typeof(yyval.Objects))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 214:
#line 689 "parser1.1.ypp"
    { typeof(yyval.Objects) a =(typeof(yyval.Objects))(stack.top());if(a->ObjectType_lineno)parserError(_("%s already set at line %d"),"ObjectType",a->ObjectType_lineno);a->ObjectType_lineno=yylineno;; a->ObjectType=yyvsp[-1].intval;}
    break;

  case 215:
#line 689 "parser1.1.ypp"
    { typeof(yyval.Objects) a =(typeof(yyval.Objects))(stack.top());if(a->ObjectType_lineno)parserError(_("%s already set at line %d"),"ObjectType",a->ObjectType_lineno);a->ObjectType_lineno=yylineno;; a->ObjectType=Map_ObjectType(*yyvsp[-1].string);delete yyvsp[-1].string;}
    break;

  case 216:
#line 690 "parser1.1.ypp"
    { typeof(yyval.Objects) a =(typeof(yyval.Objects))(stack.top()); a->Propertys.add(*yyvsp[0].Propertys); delete yyvsp[0].Propertys; }
    break;

  case 217:
#line 691 "parser1.1.ypp"
    { typeof(yyval.Objects) a =(typeof(yyval.Objects))(stack.top());if(a->Title_lineno)parserError(_("%s already set at line %d"),"Title",a->Title_lineno);a->Title_lineno=yylineno;; a->Title=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 218:
#line 692 "parser1.1.ypp"
    { typeof(yyval.Objects) a =(typeof(yyval.Objects))(stack.top());if(a->AddInfo_lineno)parserError(_("%s already set at line %d"),"AddInfo",a->AddInfo_lineno);a->AddInfo_lineno=yylineno;; a->AddInfo=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 219:
#line 696 "parser1.1.ypp"
    { yyval.Objects; }
    break;

  case 220:
#line 696 "parser1.1.ypp"
    { yyval.Objects; }
    break;

  case 223:
#line 697 "parser1.1.ypp"
    { yyval.Objects; }
    break;

  case 224:
#line 698 "parser1.1.ypp"
    { PollingMaster* a=new PollingMaster;stack.push(a);a->lineno=yylineno; }
    break;

  case 225:
#line 698 "parser1.1.ypp"
    {yyval.PollingMasters=(typeof(yyval.PollingMasters))stack.pop();}
    break;

  case 230:
#line 699 "parser1.1.ypp"
    { typeof(yyval.PollingMasters) a =(typeof(yyval.PollingMasters))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 231:
#line 700 "parser1.1.ypp"
    { typeof(yyval.PollingMasters) a =(typeof(yyval.PollingMasters))(stack.top());if(a->Title_lineno)parserError(_("%s already set at line %d"),"Title",a->Title_lineno);a->Title_lineno=yylineno;; a->Title=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 232:
#line 701 "parser1.1.ypp"
    { typeof(yyval.PollingMasters) a =(typeof(yyval.PollingMasters))(stack.top());if(a->AddInfo_lineno)parserError(_("%s already set at line %d"),"AddInfo",a->AddInfo_lineno);a->AddInfo_lineno=yylineno;; a->AddInfo=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 233:
#line 702 "parser1.1.ypp"
    { yyval.PollingMasters; }
    break;

  case 234:
#line 702 "parser1.1.ypp"
    { yyval.PollingMasters; }
    break;

  case 237:
#line 703 "parser1.1.ypp"
    { typeof(yyval.PollingMasters) a =(typeof(yyval.PollingMasters))(stack.top());if(a->PollingAddress_lineno)parserError(_("%s already set at line %d"),"PollingAddress",a->PollingAddress_lineno);a->PollingAddress_lineno=yylineno;; a->PollingAddress=yyvsp[-1].intval;}
    break;

  case 238:
#line 704 "parser1.1.ypp"
    { typeof(yyval.PollingMasters) a =(typeof(yyval.PollingMasters))(stack.top());if(a->PollingCount_lineno)parserError(_("%s already set at line %d"),"PollingCount",a->PollingCount_lineno);a->PollingCount_lineno=yylineno;; a->PollingCount=yyvsp[-1].intval;}
    break;

  case 239:
#line 705 "parser1.1.ypp"
    { yyval.PollingMasters; }
    break;

  case 240:
#line 706 "parser1.1.ypp"
    { PollingSlave* a=new PollingSlave;stack.push(a);a->lineno=yylineno; }
    break;

  case 241:
#line 706 "parser1.1.ypp"
    {yyval.PollingSlaves=(typeof(yyval.PollingSlaves))stack.pop();}
    break;

  case 246:
#line 707 "parser1.1.ypp"
    { typeof(yyval.PollingSlaves) a =(typeof(yyval.PollingSlaves))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 247:
#line 708 "parser1.1.ypp"
    { typeof(yyval.PollingSlaves) a =(typeof(yyval.PollingSlaves))(stack.top());if(a->Title_lineno)parserError(_("%s already set at line %d"),"Title",a->Title_lineno);a->Title_lineno=yylineno;; a->Title=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 248:
#line 709 "parser1.1.ypp"
    { typeof(yyval.PollingSlaves) a =(typeof(yyval.PollingSlaves))(stack.top());if(a->AddInfo_lineno)parserError(_("%s already set at line %d"),"AddInfo",a->AddInfo_lineno);a->AddInfo_lineno=yylineno;; a->AddInfo=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 249:
#line 710 "parser1.1.ypp"
    { yyval.PollingSlaves; }
    break;

  case 250:
#line 710 "parser1.1.ypp"
    { yyval.PollingSlaves; }
    break;

  case 253:
#line 711 "parser1.1.ypp"
    { typeof(yyval.PollingSlaves) a =(typeof(yyval.PollingSlaves))(stack.top());if(a->PollingAddress_lineno)parserError(_("%s already set at line %d"),"PollingAddress",a->PollingAddress_lineno);a->PollingAddress_lineno=yylineno;; a->PollingAddress=yyvsp[-1].intval;}
    break;

  case 254:
#line 712 "parser1.1.ypp"
    { typeof(yyval.PollingSlaves) a =(typeof(yyval.PollingSlaves))(stack.top());if(a->PollingSlot_lineno)parserError(_("%s already set at line %d"),"PollingSlot",a->PollingSlot_lineno);a->PollingSlot_lineno=yylineno;; a->PollingSlot=yyvsp[-1].intval;}
    break;

  case 255:
#line 713 "parser1.1.ypp"
    { yyval.PollingSlaves; }
    break;

  case 256:
#line 714 "parser1.1.ypp"
    { ListParameter* a=new ListParameter;stack.push(a);a->lineno=yylineno; }
    break;

  case 257:
#line 714 "parser1.1.ypp"
    {yyval.ListParameters=(typeof(yyval.ListParameters))stack.pop();}
    break;

  case 262:
#line 715 "parser1.1.ypp"
    { typeof(yyval.ListParameters) a =(typeof(yyval.ListParameters))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 263:
#line 716 "parser1.1.ypp"
    { typeof(yyval.ListParameters) a =(typeof(yyval.ListParameters))(stack.top()); if(a->Elements_lineno)parserError(_("%s already set at line %d"),"Elements",a->Elements_lineno);a->Elements_lineno=yylineno;; a->Elements=*yyvsp[-1].map; delete yyvsp[-1].map; }
    break;

  case 264:
#line 717 "parser1.1.ypp"
    { typeof(yyval.ListParameters) a =(typeof(yyval.ListParameters))(stack.top());if(a->Title_lineno)parserError(_("%s already set at line %d"),"Title",a->Title_lineno);a->Title_lineno=yylineno;; a->Title=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 265:
#line 718 "parser1.1.ypp"
    { typeof(yyval.ListParameters) a =(typeof(yyval.ListParameters))(stack.top());if(a->AddInfo_lineno)parserError(_("%s already set at line %d"),"AddInfo",a->AddInfo_lineno);a->AddInfo_lineno=yylineno;; a->AddInfo=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 266:
#line 719 "parser1.1.ypp"
    { typeof(yyval.ListParameters) a =(typeof(yyval.ListParameters))(stack.top());if(a->Default_lineno)parserError(_("%s already set at line %d"),"Default",a->Default_lineno);a->Default_lineno=yylineno;; a->Default=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 267:
#line 720 "parser1.1.ypp"
    { typeof(yyval.ListParameters) a =(typeof(yyval.ListParameters))(stack.top());if(a->Unit_lineno)parserError(_("%s already set at line %d"),"Unit",a->Unit_lineno);a->Unit_lineno=yylineno;; a->Unit=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 268:
#line 722 "parser1.1.ypp"
    { yyval.ListParameters; }
    break;

  case 269:
#line 722 "parser1.1.ypp"
    { yyval.ListParameters; }
    break;

  case 272:
#line 723 "parser1.1.ypp"
    { typeof(yyval.ListParameters) a =(typeof(yyval.ListParameters))(stack.top());if(a->Value_lineno)parserError(_("%s already set at line %d"),"Value",a->Value_lineno);a->Value_lineno=yylineno;; a->Value=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 273:
#line 724 "parser1.1.ypp"
    { yyval.ListParameters; }
    break;

  case 274:
#line 725 "parser1.1.ypp"
    { IntParameter* a=new IntParameter;stack.push(a);a->lineno=yylineno; }
    break;

  case 275:
#line 725 "parser1.1.ypp"
    {yyval.IntParameters=(typeof(yyval.IntParameters))stack.pop();}
    break;

  case 280:
#line 726 "parser1.1.ypp"
    { typeof(yyval.IntParameters) a =(typeof(yyval.IntParameters))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 281:
#line 727 "parser1.1.ypp"
    { typeof(yyval.IntParameters) a =(typeof(yyval.IntParameters))(stack.top());if(a->MinValue_lineno)parserError(_("%s already set at line %d"),"MinValue",a->MinValue_lineno);a->MinValue_lineno=yylineno;; a->MinValue=yyvsp[-1].intval;}
    break;

  case 282:
#line 728 "parser1.1.ypp"
    { typeof(yyval.IntParameters) a =(typeof(yyval.IntParameters))(stack.top());if(a->MaxValue_lineno)parserError(_("%s already set at line %d"),"MaxValue",a->MaxValue_lineno);a->MaxValue_lineno=yylineno;; a->MaxValue=yyvsp[-1].intval;}
    break;

  case 283:
#line 729 "parser1.1.ypp"
    { typeof(yyval.IntParameters) a =(typeof(yyval.IntParameters))(stack.top());if(a->Title_lineno)parserError(_("%s already set at line %d"),"Title",a->Title_lineno);a->Title_lineno=yylineno;; a->Title=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 284:
#line 730 "parser1.1.ypp"
    { typeof(yyval.IntParameters) a =(typeof(yyval.IntParameters))(stack.top());if(a->AddInfo_lineno)parserError(_("%s already set at line %d"),"AddInfo",a->AddInfo_lineno);a->AddInfo_lineno=yylineno;; a->AddInfo=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 285:
#line 731 "parser1.1.ypp"
    { typeof(yyval.IntParameters) a =(typeof(yyval.IntParameters))(stack.top());if(a->Default_lineno)parserError(_("%s already set at line %d"),"Default",a->Default_lineno);a->Default_lineno=yylineno;; a->Default=yyvsp[-1].intval;}
    break;

  case 286:
#line 732 "parser1.1.ypp"
    { typeof(yyval.IntParameters) a =(typeof(yyval.IntParameters))(stack.top());if(a->Unit_lineno)parserError(_("%s already set at line %d"),"Unit",a->Unit_lineno);a->Unit_lineno=yylineno;; a->Unit=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 287:
#line 733 "parser1.1.ypp"
    { typeof(yyval.IntParameters) a =(typeof(yyval.IntParameters))(stack.top());if(a->Precision_lineno)parserError(_("%s already set at line %d"),"Precision",a->Precision_lineno);a->Precision_lineno=yylineno;; a->Precision=yyvsp[-1].intval;}
    break;

  case 288:
#line 734 "parser1.1.ypp"
    { typeof(yyval.IntParameters) a =(typeof(yyval.IntParameters))(stack.top());if(a->Increment_lineno)parserError(_("%s already set at line %d"),"Increment",a->Increment_lineno);a->Increment_lineno=yylineno;; a->Increment=yyvsp[-1].intval;}
    break;

  case 289:
#line 736 "parser1.1.ypp"
    { yyval.IntParameters; }
    break;

  case 290:
#line 736 "parser1.1.ypp"
    { yyval.IntParameters; }
    break;

  case 293:
#line 737 "parser1.1.ypp"
    { typeof(yyval.IntParameters) a =(typeof(yyval.IntParameters))(stack.top());if(a->Value_lineno)parserError(_("%s already set at line %d"),"Value",a->Value_lineno);a->Value_lineno=yylineno;; a->Value=yyvsp[-1].intval;}
    break;

  case 294:
#line 738 "parser1.1.ypp"
    { yyval.IntParameters; }
    break;

  case 295:
#line 739 "parser1.1.ypp"
    { StringParameter* a=new StringParameter;stack.push(a);a->lineno=yylineno; }
    break;

  case 296:
#line 739 "parser1.1.ypp"
    {yyval.StringParameters=(typeof(yyval.StringParameters))stack.pop();}
    break;

  case 301:
#line 740 "parser1.1.ypp"
    { typeof(yyval.StringParameters) a =(typeof(yyval.StringParameters))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 302:
#line 741 "parser1.1.ypp"
    { typeof(yyval.StringParameters) a =(typeof(yyval.StringParameters))(stack.top());if(a->RegExp_lineno)parserError(_("%s already set at line %d"),"RegExp",a->RegExp_lineno);a->RegExp_lineno=yylineno;; a->RegExp=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 303:
#line 742 "parser1.1.ypp"
    { typeof(yyval.StringParameters) a =(typeof(yyval.StringParameters))(stack.top());if(a->MaxLength_lineno)parserError(_("%s already set at line %d"),"MaxLength",a->MaxLength_lineno);a->MaxLength_lineno=yylineno;; a->MaxLength=yyvsp[-1].intval;}
    break;

  case 304:
#line 743 "parser1.1.ypp"
    { typeof(yyval.StringParameters) a =(typeof(yyval.StringParameters))(stack.top());if(a->Default_lineno)parserError(_("%s already set at line %d"),"Default",a->Default_lineno);a->Default_lineno=yylineno;; a->Default=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 305:
#line 744 "parser1.1.ypp"
    { typeof(yyval.StringParameters) a =(typeof(yyval.StringParameters))(stack.top());if(a->Title_lineno)parserError(_("%s already set at line %d"),"Title",a->Title_lineno);a->Title_lineno=yylineno;; a->Title=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 306:
#line 745 "parser1.1.ypp"
    { typeof(yyval.StringParameters) a =(typeof(yyval.StringParameters))(stack.top());if(a->AddInfo_lineno)parserError(_("%s already set at line %d"),"AddInfo",a->AddInfo_lineno);a->AddInfo_lineno=yylineno;; a->AddInfo=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 307:
#line 746 "parser1.1.ypp"
    { typeof(yyval.StringParameters) a =(typeof(yyval.StringParameters))(stack.top());if(a->Unit_lineno)parserError(_("%s already set at line %d"),"Unit",a->Unit_lineno);a->Unit_lineno=yylineno;; a->Unit=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 308:
#line 747 "parser1.1.ypp"
    { yyval.StringParameters; }
    break;

  case 309:
#line 747 "parser1.1.ypp"
    { yyval.StringParameters; }
    break;

  case 312:
#line 748 "parser1.1.ypp"
    { typeof(yyval.StringParameters) a =(typeof(yyval.StringParameters))(stack.top());if(a->Value_lineno)parserError(_("%s already set at line %d"),"Value",a->Value_lineno);a->Value_lineno=yylineno;; a->Value=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 313:
#line 749 "parser1.1.ypp"
    { yyval.StringParameters; }
    break;

  case 314:
#line 750 "parser1.1.ypp"
    { FloatParameter* a=new FloatParameter;stack.push(a);a->lineno=yylineno; }
    break;

  case 315:
#line 750 "parser1.1.ypp"
    {yyval.FloatParameters=(typeof(yyval.FloatParameters))stack.pop();}
    break;

  case 320:
#line 751 "parser1.1.ypp"
    { typeof(yyval.FloatParameters) a =(typeof(yyval.FloatParameters))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 321:
#line 752 "parser1.1.ypp"
    { typeof(yyval.FloatParameters) a =(typeof(yyval.FloatParameters))(stack.top());if(a->MinValue_lineno)parserError(_("%s already set at line %d"),"MinValue",a->MinValue_lineno);a->MinValue_lineno=yylineno;; a->MinValue=yyvsp[-1].fval;}
    break;

  case 322:
#line 753 "parser1.1.ypp"
    { typeof(yyval.FloatParameters) a =(typeof(yyval.FloatParameters))(stack.top());if(a->MaxValue_lineno)parserError(_("%s already set at line %d"),"MaxValue",a->MaxValue_lineno);a->MaxValue_lineno=yylineno;; a->MaxValue=yyvsp[-1].fval;}
    break;

  case 323:
#line 754 "parser1.1.ypp"
    { typeof(yyval.FloatParameters) a =(typeof(yyval.FloatParameters))(stack.top());if(a->Title_lineno)parserError(_("%s already set at line %d"),"Title",a->Title_lineno);a->Title_lineno=yylineno;; a->Title=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 324:
#line 755 "parser1.1.ypp"
    { typeof(yyval.FloatParameters) a =(typeof(yyval.FloatParameters))(stack.top());if(a->AddInfo_lineno)parserError(_("%s already set at line %d"),"AddInfo",a->AddInfo_lineno);a->AddInfo_lineno=yylineno;; a->AddInfo=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 325:
#line 756 "parser1.1.ypp"
    { typeof(yyval.FloatParameters) a =(typeof(yyval.FloatParameters))(stack.top());if(a->Unit_lineno)parserError(_("%s already set at line %d"),"Unit",a->Unit_lineno);a->Unit_lineno=yylineno;; a->Unit=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 326:
#line 757 "parser1.1.ypp"
    { typeof(yyval.FloatParameters) a =(typeof(yyval.FloatParameters))(stack.top());if(a->Precision_lineno)parserError(_("%s already set at line %d"),"Precision",a->Precision_lineno);a->Precision_lineno=yylineno;; a->Precision=yyvsp[-1].fval;}
    break;

  case 327:
#line 758 "parser1.1.ypp"
    { typeof(yyval.FloatParameters) a =(typeof(yyval.FloatParameters))(stack.top());if(a->Increment_lineno)parserError(_("%s already set at line %d"),"Increment",a->Increment_lineno);a->Increment_lineno=yylineno;; a->Increment=yyvsp[-1].fval;}
    break;

  case 328:
#line 759 "parser1.1.ypp"
    { typeof(yyval.FloatParameters) a =(typeof(yyval.FloatParameters))(stack.top());if(a->Default_lineno)parserError(_("%s already set at line %d"),"Default",a->Default_lineno);a->Default_lineno=yylineno;; a->Default=yyvsp[-1].fval;}
    break;

  case 329:
#line 760 "parser1.1.ypp"
    { yyval.FloatParameters; }
    break;

  case 330:
#line 760 "parser1.1.ypp"
    { yyval.FloatParameters; }
    break;

  case 333:
#line 761 "parser1.1.ypp"
    { typeof(yyval.FloatParameters) a =(typeof(yyval.FloatParameters))(stack.top());if(a->Value_lineno)parserError(_("%s already set at line %d"),"Value",a->Value_lineno);a->Value_lineno=yylineno;; a->Value=yyvsp[-1].fval;}
    break;

  case 334:
#line 762 "parser1.1.ypp"
    { yyval.FloatParameters; }
    break;

  case 335:
#line 763 "parser1.1.ypp"
    { Timer* a=new Timer;stack.push(a);a->lineno=yylineno; }
    break;

  case 336:
#line 763 "parser1.1.ypp"
    {yyval.Timers=(typeof(yyval.Timers))stack.pop();}
    break;

  case 341:
#line 764 "parser1.1.ypp"
    { typeof(yyval.Timers) a =(typeof(yyval.Timers))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 342:
#line 765 "parser1.1.ypp"
    { typeof(yyval.Timers) a =(typeof(yyval.Timers))(stack.top());if(a->Type_lineno)parserError(_("%s already set at line %d"),"Type",a->Type_lineno);a->Type_lineno=yylineno;; a->Type=Map_TimerType(*yyvsp[-1].string);delete yyvsp[-1].string;}
    break;

  case 343:
#line 766 "parser1.1.ypp"
    { typeof(yyval.Timers) a =(typeof(yyval.Timers))(stack.top());if(a->Resolution_lineno)parserError(_("%s already set at line %d"),"Resolution",a->Resolution_lineno);a->Resolution_lineno=yylineno;; a->Resolution=Map_TimerResType(*yyvsp[-1].string);delete yyvsp[-1].string;}
    break;

  case 344:
#line 767 "parser1.1.ypp"
    { typeof(yyval.Timers) a =(typeof(yyval.Timers))(stack.top());if(a->on_expire_lineno)parserError(_("%s already set at line %d"),"on_expire",a->on_expire_lineno);a->on_expire_lineno=yylineno;; a->on_expire=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 345:
#line 769 "parser1.1.ypp"
    { yyval.Timers; }
    break;

  case 346:
#line 769 "parser1.1.ypp"
    { yyval.Timers; }
    break;

  case 349:
#line 770 "parser1.1.ypp"
    { yyval.Timers; }
    break;

  case 350:
#line 771 "parser1.1.ypp"
    { Debounce* a=new Debounce;stack.push(a);a->lineno=yylineno; }
    break;

  case 351:
#line 771 "parser1.1.ypp"
    {yyval.Debounces=(typeof(yyval.Debounces))stack.pop();}
    break;

  case 356:
#line 772 "parser1.1.ypp"
    { typeof(yyval.Debounces) a =(typeof(yyval.Debounces))(stack.top());if(a->Name_lineno)parserError(_("%s already set at line %d"),"Name",a->Name_lineno);a->Name_lineno=yylineno;; a->Name=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 357:
#line 773 "parser1.1.ypp"
    { typeof(yyval.Debounces) a =(typeof(yyval.Debounces))(stack.top());if(a->Time_lineno)parserError(_("%s already set at line %d"),"Time",a->Time_lineno);a->Time_lineno=yylineno;; a->Time=yyvsp[-1].fval;}
    break;

  case 358:
#line 774 "parser1.1.ypp"
    { yyval.Debounces; }
    break;

  case 359:
#line 774 "parser1.1.ypp"
    { yyval.Debounces; }
    break;

  case 362:
#line 775 "parser1.1.ypp"
    { yyval.Debounces; }
    break;

  case 363:
#line 776 "parser1.1.ypp"
    { Device* a=new Device;stack.push(a);a->lineno=yylineno; }
    break;

  case 364:
#line 776 "parser1.1.ypp"
    {yyval.Devices=(typeof(yyval.Devices))stack.pop();}
    break;

  case 369:
#line 777 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->ManufacturerCode_lineno)parserError(_("%s already set at line %d"),"ManufacturerCode",a->ManufacturerCode_lineno);a->ManufacturerCode_lineno=yylineno;; a->ManufacturerCode=yyvsp[-1].intval;}
    break;

  case 370:
#line 778 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->InternalManufacturerCode_lineno)parserError(_("%s already set at line %d"),"InternalManufacturerCode",a->InternalManufacturerCode_lineno);a->InternalManufacturerCode_lineno=yylineno;; a->InternalManufacturerCode=yyvsp[-1].intval;}
    break;

  case 371:
#line 779 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->DeviceType_lineno)parserError(_("%s already set at line %d"),"DeviceType",a->DeviceType_lineno);a->DeviceType_lineno=yylineno;; a->DeviceType=yyvsp[-1].intval;}
    break;

  case 372:
#line 780 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->Version_lineno)parserError(_("%s already set at line %d"),"Version",a->Version_lineno);a->Version_lineno=yylineno;; a->Version=yyvsp[-1].intval;}
    break;

  case 373:
#line 781 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->SyncRate_lineno)parserError(_("%s already set at line %d"),"SyncRate",a->SyncRate_lineno);a->SyncRate_lineno=yylineno;; a->SyncRate=yyvsp[-1].intval;}
    break;

  case 374:
#line 782 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->PEIType_lineno)parserError(_("%s already set at line %d"),"PEIType",a->PEIType_lineno);a->PEIType_lineno=yylineno;; a->PEIType=yyvsp[-1].intval;}
    break;

  case 375:
#line 783 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->PortADDR_lineno)parserError(_("%s already set at line %d"),"PortADDR",a->PortADDR_lineno);a->PortADDR_lineno=yylineno;; a->PortADDR=yyvsp[-1].intval;}
    break;

  case 376:
#line 784 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->PortCDDR_lineno)parserError(_("%s already set at line %d"),"PortCDDR",a->PortCDDR_lineno);a->PortCDDR_lineno=yylineno;; a->PortCDDR=yyvsp[-1].intval;}
    break;

  case 377:
#line 785 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->U_DELMSG_lineno)parserError(_("%s already set at line %d"),"U_DELMSG",a->U_DELMSG_lineno);a->U_DELMSG_lineno=yylineno;; a->U_DELMSG=yyvsp[-1].bval;}
    break;

  case 378:
#line 786 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->RouteCount_lineno)parserError(_("%s already set at line %d"),"RouteCount",a->RouteCount_lineno);a->RouteCount_lineno=yylineno;; a->RouteCount=yyvsp[-1].intval;}
    break;

  case 379:
#line 787 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->BusyLimit_lineno)parserError(_("%s already set at line %d"),"BusyLimit",a->BusyLimit_lineno);a->BusyLimit_lineno=yylineno;; a->BusyLimit=yyvsp[-1].intval;}
    break;

  case 380:
#line 788 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->INAKLimit_lineno)parserError(_("%s already set at line %d"),"INAKLimit",a->INAKLimit_lineno);a->INAKLimit_lineno=yylineno;; a->INAKLimit=yyvsp[-1].intval;}
    break;

  case 381:
#line 789 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->RateLimit_lineno)parserError(_("%s already set at line %d"),"RateLimit",a->RateLimit_lineno);a->RateLimit_lineno=yylineno;; a->RateLimit=yyvsp[-1].intval;}
    break;

  case 382:
#line 790 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->CPOL_lineno)parserError(_("%s already set at line %d"),"CPOL",a->CPOL_lineno);a->CPOL_lineno=yylineno;; a->CPOL=yyvsp[-1].bval;}
    break;

  case 383:
#line 791 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->CPHA_lineno)parserError(_("%s already set at line %d"),"CPHA",a->CPHA_lineno);a->CPHA_lineno=yylineno;; a->CPHA=yyvsp[-1].bval;}
    break;

  case 384:
#line 792 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->AutoPLMA_lineno)parserError(_("%s already set at line %d"),"AutoPLMA",a->AutoPLMA_lineno);a->AutoPLMA_lineno=yylineno;; a->AutoPLMA=yyvsp[-1].bval;}
    break;

  case 385:
#line 793 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->A_Event_lineno)parserError(_("%s already set at line %d"),"A_Event",a->A_Event_lineno);a->A_Event_lineno=yylineno;; a->A_Event=yyvsp[-1].bval;}
    break;

  case 386:
#line 794 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->BCU1_SEC_lineno)parserError(_("%s already set at line %d"),"BCU1_SEC",a->BCU1_SEC_lineno);a->BCU1_SEC_lineno=yylineno;; a->BCU1_SEC=yyvsp[-1].bval;}
    break;

  case 387:
#line 795 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->BCU1_PROTECT_lineno)parserError(_("%s already set at line %d"),"BCU1_PROTECT",a->BCU1_PROTECT_lineno);a->BCU1_PROTECT_lineno=yylineno;; a->BCU1_PROTECT=yyvsp[-1].bval;}
    break;

  case 388:
#line 796 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->BCU2_PROTECT_lineno)parserError(_("%s already set at line %d"),"BCU2_PROTECT",a->BCU2_PROTECT_lineno);a->BCU2_PROTECT_lineno=yylineno;; a->BCU2_PROTECT=yyvsp[-1].bval;}
    break;

  case 389:
#line 797 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->BCU2_WATCHDOG_lineno)parserError(_("%s already set at line %d"),"BCU2_WATCHDOG",a->BCU2_WATCHDOG_lineno);a->BCU2_WATCHDOG_lineno=yylineno;; a->BCU2_WATCHDOG=yyvsp[-1].bval;}
    break;

  case 390:
#line 798 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->PLM_FAST_lineno)parserError(_("%s already set at line %d"),"PLM_FAST",a->PLM_FAST_lineno);a->PLM_FAST_lineno=yylineno;; a->PLM_FAST=yyvsp[-1].bval;}
    break;

  case 391:
#line 799 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); if(a->include_lineno)parserError(_("%s already set at line %d"),"include",a->include_lineno);a->include_lineno=yylineno;; a->include=*yyvsp[-1].stringarray; delete yyvsp[-1].stringarray; }
    break;

  case 392:
#line 800 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->Title_lineno)parserError(_("%s already set at line %d"),"Title",a->Title_lineno);a->Title_lineno=yylineno;; a->Title=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 393:
#line 801 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->AddInfo_lineno)parserError(_("%s already set at line %d"),"AddInfo",a->AddInfo_lineno);a->AddInfo_lineno=yylineno;; a->AddInfo=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 394:
#line 802 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->OrderNo_lineno)parserError(_("%s already set at line %d"),"OrderNo",a->OrderNo_lineno);a->OrderNo_lineno=yylineno;; a->OrderNo=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 395:
#line 803 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->Manufacturer_lineno)parserError(_("%s already set at line %d"),"Manufacturer",a->Manufacturer_lineno);a->Manufacturer_lineno=yylineno;; a->Manufacturer=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 396:
#line 804 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->Category_lineno)parserError(_("%s already set at line %d"),"Category",a->Category_lineno);a->Category_lineno=yylineno;; a->Category=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 397:
#line 805 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->Author_lineno)parserError(_("%s already set at line %d"),"Author",a->Author_lineno);a->Author_lineno=yylineno;; a->Author=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 398:
#line 806 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->Copyright_lineno)parserError(_("%s already set at line %d"),"Copyright",a->Copyright_lineno);a->Copyright_lineno=yylineno;; a->Copyright=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 399:
#line 807 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->FunctionalBlocks.add(*yyvsp[0].FunctionalBlocks); delete yyvsp[0].FunctionalBlocks; }
    break;

  case 400:
#line 808 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->Test_Addr_Count_lineno)parserError(_("%s already set at line %d"),"Test_Addr_Count",a->Test_Addr_Count_lineno);a->Test_Addr_Count_lineno=yylineno;; a->Test_Addr_Count=yyvsp[-1].intval;}
    break;

  case 401:
#line 809 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->Test_Assoc_Count_lineno)parserError(_("%s already set at line %d"),"Test_Assoc_Count",a->Test_Assoc_Count_lineno);a->Test_Assoc_Count_lineno=yylineno;; a->Test_Assoc_Count=yyvsp[-1].intval;}
    break;

  case 402:
#line 810 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->PollingMasters.add(*yyvsp[0].PollingMasters); delete yyvsp[0].PollingMasters; }
    break;

  case 403:
#line 811 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->PollingSlaves.add(*yyvsp[0].PollingSlaves); delete yyvsp[0].PollingSlaves; }
    break;

  case 404:
#line 812 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->GroupObjects.add(*yyvsp[0].GroupObjects); delete yyvsp[0].GroupObjects; }
    break;

  case 405:
#line 813 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->Objects.add(*yyvsp[0].Objects); delete yyvsp[0].Objects; }
    break;

  case 406:
#line 814 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->ListParameters.add(*yyvsp[0].ListParameters); delete yyvsp[0].ListParameters; }
    break;

  case 407:
#line 815 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->IntParameters.add(*yyvsp[0].IntParameters); delete yyvsp[0].IntParameters; }
    break;

  case 408:
#line 816 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->FloatParameters.add(*yyvsp[0].FloatParameters); delete yyvsp[0].FloatParameters; }
    break;

  case 409:
#line 817 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->StringParameters.add(*yyvsp[0].StringParameters); delete yyvsp[0].StringParameters; }
    break;

  case 410:
#line 818 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->Debounces.add(*yyvsp[0].Debounces); delete yyvsp[0].Debounces; }
    break;

  case 411:
#line 819 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); a->Timers.add(*yyvsp[0].Timers); delete yyvsp[0].Timers; }
    break;

  case 412:
#line 820 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_run_lineno)parserError(_("%s already set at line %d"),"on_run",a->on_run_lineno);a->on_run_lineno=yylineno;; a->on_run=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 413:
#line 821 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_init_lineno)parserError(_("%s already set at line %d"),"on_init",a->on_init_lineno);a->on_init_lineno=yylineno;; a->on_init=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 414:
#line 822 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_save_lineno)parserError(_("%s already set at line %d"),"on_save",a->on_save_lineno);a->on_save_lineno=yylineno;; a->on_save=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 415:
#line 823 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_init_lineno)parserError(_("%s already set at line %d"),"on_pei_init",a->on_pei_init_lineno);a->on_pei_init_lineno=yylineno;; a->on_pei_init=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 416:
#line 824 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_message_lineno)parserError(_("%s already set at line %d"),"on_pei_message",a->on_pei_message_lineno);a->on_pei_message_lineno=yylineno;; a->on_pei_message=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 417:
#line 825 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_cycle_lineno)parserError(_("%s already set at line %d"),"on_pei_cycle",a->on_pei_cycle_lineno);a->on_pei_cycle_lineno=yylineno;; a->on_pei_cycle=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 418:
#line 826 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_user_lineno)parserError(_("%s already set at line %d"),"on_pei_user",a->on_pei_user_lineno);a->on_pei_user_lineno=yylineno;; a->on_pei_user=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 419:
#line 827 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_rc_even_lineno)parserError(_("%s already set at line %d"),"on_pei_rc_even",a->on_pei_rc_even_lineno);a->on_pei_rc_even_lineno=yylineno;; a->on_pei_rc_even=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 420:
#line 828 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_rc_odd_lineno)parserError(_("%s already set at line %d"),"on_pei_rc_odd",a->on_pei_rc_odd_lineno);a->on_pei_rc_odd_lineno=yylineno;; a->on_pei_rc_odd=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 421:
#line 829 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_tc_lineno)parserError(_("%s already set at line %d"),"on_pei_tc",a->on_pei_tc_lineno);a->on_pei_tc_lineno=yylineno;; a->on_pei_tc=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 422:
#line 830 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_tdre_lineno)parserError(_("%s already set at line %d"),"on_pei_tdre",a->on_pei_tdre_lineno);a->on_pei_tdre_lineno=yylineno;; a->on_pei_tdre=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 423:
#line 831 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_sci_idle_lineno)parserError(_("%s already set at line %d"),"on_pei_sci_idle",a->on_pei_sci_idle_lineno);a->on_pei_sci_idle_lineno=yylineno;; a->on_pei_sci_idle=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 424:
#line 832 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_spif_lineno)parserError(_("%s already set at line %d"),"on_pei_spif",a->on_pei_spif_lineno);a->on_pei_spif_lineno=yylineno;; a->on_pei_spif=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 425:
#line 833 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_oca_lineno)parserError(_("%s already set at line %d"),"on_pei_oca",a->on_pei_oca_lineno);a->on_pei_oca_lineno=yylineno;; a->on_pei_oca=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 426:
#line 834 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_ocb_lineno)parserError(_("%s already set at line %d"),"on_pei_ocb",a->on_pei_ocb_lineno);a->on_pei_ocb_lineno=yylineno;; a->on_pei_ocb=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 427:
#line 835 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_ica_lineno)parserError(_("%s already set at line %d"),"on_pei_ica",a->on_pei_ica_lineno);a->on_pei_ica_lineno=yylineno;; a->on_pei_ica=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 428:
#line 836 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->on_pei_icb_lineno)parserError(_("%s already set at line %d"),"on_pei_icb",a->on_pei_icb_lineno);a->on_pei_icb_lineno=yylineno;; a->on_pei_icb=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 429:
#line 839 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->BCU_lineno)parserError(_("%s already set at line %d"),"BCU",a->BCU_lineno);a->BCU_lineno=yylineno;; a->BCU=Map_BCUType(*yyvsp[-1].string);delete yyvsp[-1].string;}
    break;

  case 430:
#line 840 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->Model_lineno)parserError(_("%s already set at line %d"),"Model",a->Model_lineno);a->Model_lineno=yylineno;; a->Model=*yyvsp[-1].string; delete yyvsp[-1].string;}
    break;

  case 431:
#line 843 "parser1.1.ypp"
    { yyval.Devices; }
    break;

  case 432:
#line 843 "parser1.1.ypp"
    { yyval.Devices; }
    break;

  case 435:
#line 844 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top()); if(a->Keys_lineno)parserError(_("%s already set at line %d"),"Keys",a->Keys_lineno);a->Keys_lineno=yylineno;; a->Keys=*yyvsp[-1].keymaparray; delete yyvsp[-1].keymaparray; }
    break;

  case 436:
#line 845 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->PhysicalAddress_lineno)parserError(_("%s already set at line %d"),"PhysicalAddress",a->PhysicalAddress_lineno);a->PhysicalAddress_lineno=yylineno;; a->PhysicalAddress=yyvsp[-1].intval;}
    break;

  case 437:
#line 846 "parser1.1.ypp"
    { typeof(yyval.Devices) a =(typeof(yyval.Devices))(stack.top());if(a->InstallKey_lineno)parserError(_("%s already set at line %d"),"InstallKey",a->InstallKey_lineno);a->InstallKey_lineno=yylineno;; a->InstallKey=yyvsp[-1].intval;}
    break;

  case 438:
#line 847 "parser1.1.ypp"
    { yyval.Devices; }
    break;

  case 439:
#line 848 "parser1.1.ypp"
    { parser_dev=yyvsp[0].Devices; }
    break;


    }

/* Line 1010 of yacc.c.  */
#line 4399 "parser1.1.cpp"

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



