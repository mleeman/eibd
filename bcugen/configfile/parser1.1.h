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
/* Line 1241 of yacc.c.  */
#line 568 "parser1.1.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



