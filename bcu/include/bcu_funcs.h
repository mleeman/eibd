/*
    BCU SDK bcu development enviroment
    Copyright (C) 2005-2011 Martin Koegler <mkoegler@auto.tuwien.ac.at>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    In addition to the permissions in the GNU General Public License, 
    you may link the compiled version of this file into combinations
    with other programs, and distribute those combinations without any 
    restriction coming from the use of this file. (The General Public 
    License restrictions do apply in other respects; for example, they 
    cover modification of the file, and distribution when not linked into 
    a combine executable.)

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef _BCU_FUNCS_H
#define _BCU_FUNCS_H

#include <stdbool.h>

typedef struct
{
  bool newstate;
  uchar stateok;
} FT12_GetStatus_Result;

typedef struct
{
  unsigned short quotient;
  unsigned short remainder;
  bool error;
} U_Div_Result;

typedef struct
{
  unsigned short product;
  bool overflow;
} U_Mul_Result;

typedef struct
{
  uchar_loptr pointer;
  bool found;
} PopBuf_Result;

typedef struct
{
  uchar_loptr pointer;
  bool valid;
} AllocBuf_Result;

typedef struct
{
  bool expired;
  uchar time;
} TM_GetFlg_Result;

typedef struct
{
  uchar octet;
  bool error;
} U_SerialShift_Result;

typedef struct
{
  uchar pointer;
  bool error;
} S_xxShift_Result;

typedef struct
{
  signed short value;
  bool error;
} U_map_Result;

#define SETAONCARRY "\n\tclra\n\tbcc _L_%=\n\tinca\n_L_%=:\n\t"
#define SETAONZERO "\n\tclra\n\tbne _L_%=\n\tinca\n_L_%=:\n\t"
#define SETAONNZERO "\n\tclra\n\tbeq _L_%=\n\tinca\n_L_%=:\n\t"

static void inline
reset_watchdog ()
{
  asm volatile ("bset.0 0x00C");
}

extern const uchar OR_TAB[8];
extern const uchar AND_TAB[8];

static uchar inline
_U_flagsGet (uchar no)
{
  uchar ret;
  if (!__builtin_constant_p (no))
    asm volatile ("lda %1\n\tjsr U_flagsGet":"=z" (ret):"r" (no):"A", "X",
		  "RegC", "RegJ");
  else
  asm volatile ("lda $%1\n\tjsr U_flagsGet":"=z" (ret):"i" (no):"A", "X",
		"RegC", "RegJ");
  return ret;
}

static void inline
_U_flagsSet (uchar no, uchar flag)
{
  if (!__builtin_constant_p (no))
    asm volatile ("lda %0\n\tjsr U_flagsSet"::"r" (no), "z" (flag):"A", "X",
		  "RegC", "RegJ");
  else
  asm volatile ("lda $%0\n\tjsr U_flagsSet"::"i" (no), "z" (flag):"A", "X",
		"RegC", "RegJ");
}

static void inline
_U_transRequest (uchar no)
{
  if (!__builtin_constant_p (no))
    asm volatile ("lda %0\n\tjsr U_transRequest"::"r" (no):"A", "X", "RegB",
		  "RegC", "RegJ");
  else
  asm volatile ("lda $%0\n\tjsr U_transRequest"::"i" (no):"A", "X", "RegB",
		"RegC", "RegJ");
}

static uchar inline
_U_testObj (uchar no)
{
  uchar ret;
  if (!__builtin_constant_p (no))
    asm volatile ("lda %1\n\tjsr U_testObj":"=c" (ret):"r" (no):"A", "X",
		  "RegB", "RegJ");
  else
  asm volatile ("lda $%1\n\tjsr U_testObj":"=c" (ret):"i" (no):"A", "X",
		"RegB", "RegJ");
  return ret;
}

static void inline
_EEwrite (uchar offset, uchar value)
{
  if (!__builtin_constant_p (offset))
    {
      if (!__builtin_constant_p (value))
	asm volatile ("lda %0\n\tldx %1\n\tjsr EEwrite"::"r" (value),
		      "r" (offset):"A", "X", "RegB", "RegC", "RegH");
      else
      asm volatile ("lda %0\n\tldx $%1\n\tjsr EEwrite"::"r" (value),
		    "i" (offset):"A", "X", "RegB", "RegC", "RegH");
    }
  else
    {
      if (!__builtin_constant_p (value))
	asm volatile ("lda $%0\n\tldx %1\n\tjsr EEwrite"::"i" (value),
		      "r" (offset):"A", "X", "RegB", "RegC", "RegH");
      else
      asm volatile ("lda $%0\n\tldx $%1\n\tjsr EEwrite"::"i" (value),
		    "i" (offset):"A", "X", "RegB", "RegC", "RegH");
    }
}

static void inline
_EEsetChecksum ()
{
  asm volatile ("jsr EEsetChecksum":::"A", "X", "RegB", "RegC", "RegH");
}

static uchar inline
_U_debounce (uchar value, uchar time)
{
  uchar ret;
  if (!__builtin_constant_p (time))
    asm
      volatile ("lda %1\n\tldx %2\n\tjsr U_debounce\n\tsta %0":"=r" (ret):"r"
		(value), "r" (time):"X", "A", "RegB", "RegC", "RegD", "RegE",
		"RegF", "RegG");
  else
  asm
    volatile ("lda %1\n\tldx $%2\n\tjsr U_debounce\n\tsta %0":"=r" (ret):"r"
	      (value), "i" (time):"X", "A", "RegB", "RegC", "RegD", "RegE",
	      "RegF", "RegG");
  return ret;
}

static uchar inline
_U_deb10 (uchar value)
{
  uchar ret;
  asm volatile ("lda %1\n\tjsr U_deb10\n\tsta %0":"=r" (ret):"r" (value):"X",
		"A", "RegB", "RegC", "RegD", "RegE", "RegF", "RegG");
  return ret;
}

static uchar inline
_U_deb30 (uchar value)
{
  uchar ret;
  asm volatile ("lda %1\n\tjsr U_deb30\n\tsta %0":"=r" (ret):"r" (value):"X",
		"A", "RegB", "RegC", "RegD", "RegE", "RegF", "RegG");
  return ret;
}

static void inline
_U_delMsgs ()
{
  asm volatile ("jsr U_delMsgs":::"A", "X", "RegB");
}

static short inline
_U_readAD (uchar channel, uchar count)
{
  short ret;
  if (!__builtin_constant_p (count))
    {
      if (!__builtin_constant_p (channel))
	asm
	  volatile ("lda %1\n\tldx %2\n\tjsr U_readAD":"=t" (ret):"r"
		    (channel), "r" (count):"A", "X");
      else
      asm
	volatile ("lda %1\n\tldx $%2\n\tjsr U_readAD":"=t" (ret):"r"
		  (channel), "i" (count):"A", "X");
    }
  else
    {
      if (!__builtin_constant_p (channel))
	asm
	  volatile ("lda $%1\n\tldx %2\n\tjsr U_readAD":"=t" (ret):"i"
		    (channel), "r" (count):"A", "X");
      else
      asm
	volatile ("lda $%1\n\tldx $%2\n\tjsr U_readAD":"=t" (ret):"i"
		  (channel), "i" (count):"A", "X");
    }
  return ret;
}

static U_map_Result inline
_U_map (signed short value, uchar ptr)
{
  U_map_Result ret;
  if (!__builtin_constant_p (ptr))
    asm
      volatile
      ("ldx %2\n\tjsr U_map" SETAONCARRY "sta %1":"=q"
       (ret.value), "=r" (ret.error):"r" (ptr), "q" (value):"A", "X", "RegD",
       "RegE", "RegF", "RegG", "RegH", "RegI");
  else
  asm
    volatile
    ("ldx $%2\n\tjsr U_map" SETAONCARRY "sta %1":"=q"
     (ret.value), "=r" (ret.error):"i" (ptr), "q" (value):"A", "X", "RegD",
     "RegE", "RegF", "RegG", "RegH", "RegI");
  return ret;
}

static signed short inline
_U_map_NE (signed short value, uchar ptr)
{
  signed short ret;
  if (!__builtin_constant_p (ptr))
    asm
      volatile
      ("ldx %1\n\tjsr U_map":"=q"
       (ret):"r" (ptr), "q" (value):"A", "X", "RegD",
       "RegE", "RegF", "RegG", "RegH", "RegI");
  else
  asm
    volatile
    ("ldx $%1\n\tjsr U_map":"=q"
     (ret):"i" (ptr), "q" (value):"A", "X", "RegD",
     "RegE", "RegF", "RegG", "RegH", "RegI");
  return ret;
}

static uchar inline
_U_ioAST (uchar val)
{
  uchar ret;
  if (!__builtin_constant_p (val))
    asm volatile ("lda %1\n\tjsr U_ioAST":"=z" (ret):"r" (val):"A", "X",
		  "RegC", "RegD");
  else
  asm volatile ("lda $%1\n\tjsr U_ioAST":"=z" (ret):"i" (val):"A", "X",
		"RegC", "RegD");
  return ret;
}

static S_xxShift_Result inline
_S_AstShift (uchar ptr)
{
  S_xxShift_Result ret;
  if (!__builtin_constant_p (ptr))
    asm
      volatile
      ("ldx %2\n\tjsr S_AstShift\n\tstx %0" SETAONCARRY "sta %1":"=r"
       (ret.pointer), "=r" (ret.error):"r" (ptr):"A", "X", "RegB", "RegC",
       "RegD", "RegE", "RegF", "RegG", "RegH", "RegI");
  else
  asm
    volatile
    ("ldx $%2\n\tjsr S_AstShift\n\tstx %0" SETAONCARRY "sta %1":"=r"
     (ret.pointer), "=r" (ret.error):"i" (ptr):"A", "X", "RegB", "RegC",
     "RegD", "RegE", "RegF", "RegG", "RegH", "RegI");
  return ret;
}

static uchar inline
_S_AstShift_NE (uchar ptr)
{
  uchar ret;
  if (!__builtin_constant_p (ptr))
    asm
      volatile
      ("ldx %1\n\tjsr S_AstShift\n\tstx %0":"=r"
       (ret):"r" (ptr):"A", "X", "RegB", "RegC",
       "RegD", "RegE", "RegF", "RegG", "RegH", "RegI");
  else
  asm
    volatile
    ("ldx $%1\n\tjsr S_AstShift\n\tstx %0":"=r"
     (ret):"i" (ptr):"A", "X", "RegB", "RegC",
     "RegD", "RegE", "RegF", "RegG", "RegH", "RegI");
  return ret;
}

static S_xxShift_Result inline
_S_LastShift (uchar ptr)
{
  S_xxShift_Result ret;
  if (!__builtin_constant_p (ptr))
    asm
      volatile
      ("ldx %2\n\tjsr S_LastShift\n\tstx %0" SETAONCARRY "sta %1":"=r"
       (ret.pointer), "=r" (ret.error):"r" (ptr):"A", "X", "RegB", "RegC",
       "RegD", "RegE", "RegF", "RegG", "RegH", "RegI");
  else
  asm
    volatile
    ("ldx $%2\n\tjsr S_LastShift\n\tstx %0" SETAONCARRY "sta %1":"=r"
     (ret.pointer), "=r" (ret.error):"i" (ptr):"A", "X", "RegB", "RegC",
     "RegD", "RegE", "RegF", "RegG", "RegH", "RegI");
  return ret;
}

static uchar inline
_S_LastShift_NE (uchar ptr)
{
  uchar ret;
  if (!__builtin_constant_p (ptr))
    asm
      volatile
      ("ldx %1\n\tjsr S_LastShift\n\tstx %0":"=r"
       (ret):"r" (ptr):"A", "X", "RegB", "RegC",
       "RegD", "RegE", "RegF", "RegG", "RegH", "RegI");
  else
  asm
    volatile
    ("ldx $%1\n\tjsr S_LastShift\n\tstx %0":"=r"
     (ret):"i" (ptr):"A", "X", "RegB", "RegC",
     "RegD", "RegE", "RegF", "RegG", "RegH", "RegI");
  return ret;
}

static U_SerialShift_Result inline
_U_SerialShift (uchar octet)
{
  U_SerialShift_Result ret;
  if (!__builtin_constant_p (octet))
    asm
      volatile
      ("lda %2\n\tjsr U_SerialShift\n\tsta %0" SETAONCARRY "sta %1":"=r"
       (ret.octet), "=r" (ret.error):"r" (octet):"A", "X", "RegB", "RegC",
       "RegD", "RegE", "RegF", "RegG", "RegI");
  else
  asm
    volatile
    ("lda $%2\n\tjsr U_SerialShift\n\tsta %0" SETAONCARRY "sta %1":"=r"
     (ret.octet), "=r" (ret.error):"i" (octet):"A", "X", "RegB", "RegC",
     "RegD", "RegE", "RegF", "RegG", "RegI");
  return ret;
}

static uchar inline
_U_SerialShift_NE (uchar octet)
{
  uchar ret;
  if (!__builtin_constant_p (octet))
    asm
      volatile
      ("lda %1\n\tjsr U_SerialShift\n\tsta %0":"=r"
       (ret):"r" (octet):"A", "X", "RegB", "RegC",
       "RegD", "RegE", "RegF", "RegG", "RegI");
  else
  asm
    volatile
    ("lda $%1\n\tjsr U_SerialShift\n\tsta %0":"=r"
     (ret):"i" (octet):"A", "X", "RegB", "RegC",
     "RegD", "RegE", "RegF", "RegG", "RegI");
  return ret;
}

static void inline
_TM_Load (uchar setup, uchar runtime)
{
  if (!__builtin_constant_p (runtime))
    {
      if (!__builtin_constant_p (setup))
	asm volatile ("lda %0\n\tldx %1\n\tjsr TM_Load"::"r" (setup),
		      "r" (runtime):"A", "X", "RegB", "RegC", "RegD", "RegE",
		      "RegF");
      else
      asm volatile ("lda %0\n\tldx $%1\n\tjsr TM_Load"::"r" (setup),
		    "i" (runtime):"A", "X", "RegB", "RegC", "RegD", "RegE",
		    "RegF");
    }
  else
    {
      if (!__builtin_constant_p (setup))
	asm volatile ("lda $%0\n\tldx %1\n\tjsr TM_Load"::"i" (setup),
		      "r" (runtime):"A", "X", "RegB", "RegC", "RegD", "RegE",
		      "RegF");
      else
      asm volatile ("lda $%0\n\tldx $%1\n\tjsr TM_Load"::"i" (setup),
		    "i" (runtime):"A", "X", "RegB", "RegC", "RegD", "RegE",
		    "RegF");
    }
}

static TM_GetFlg_Result inline
_TM_GetFlg (uchar timer)
{
  TM_GetFlg_Result ret;
  if (!__builtin_constant_p (timer))
    asm
      volatile
      ("lda %2\n\tjsr TM_GetFlg\n\tsta %0" SETAONCARRY "sta %1":"=r"
       (ret.time), "=r" (ret.expired):"r" (timer):"A", "X", "RegB", "RegC",
       "RegD", "RegE");
  else
  asm
    volatile
    ("lda $%2\n\tjsr TM_GetFlg\n\tsta %0" SETAONCARRY "sta %1":"=r"
     (ret.time), "=r" (ret.expired):"i" (timer):"A", "X", "RegB", "RegC",
     "RegD", "RegE");
  return ret;
}

static bool inline
_TM_GetFlg_M0 (uchar timer)
{
  bool ret;
  if (!__builtin_constant_p (timer))
    asm
      volatile
      ("lda %1\n\tjsr TM_GetFlg" SETAONCARRY "sta %0":"=r"
       (ret):"r" (timer):"A", "X", "RegB", "RegC", "RegD", "RegE");
  else
  asm
    volatile
    ("lda $%1\n\tjsr TM_GetFlg" SETAONCARRY "sta %1":"=r"
     (ret):"i" (timer):"A", "X", "RegB", "RegC", "RegD", "RegE");
  return ret;
}

static uchar inline
_TM_GetFlg_M1 (uchar timer)
{
  uchar ret;
  if (!__builtin_constant_p (timer))
    asm
      volatile
      ("lda %1\n\tjsr TM_GetFlg\n\tsta %0":"=r"
       (ret):"r" (timer):"A", "X", "RegB", "RegC", "RegD", "RegE");
  else
  asm
    volatile
    ("lda $%1\n\tjsr TM_GetFlg\n\tsta %0":"=r"
     (ret):"i" (timer):"A", "X", "RegB", "RegC", "RegD", "RegE");
  return ret;
}

static void inline
_U_SetTM (uchar timer, uchar pointer, uchar time)
{
  if (!__builtin_constant_p (pointer))
    {
      if (!__builtin_constant_p (timer))
	asm
	  volatile ("lda %1\n\tldx %2\n\tjsr U_SetTM"::"e" (time),
		    "r" (timer), "r" (pointer):"A", "X", "RegB", "RegC",
		    "RegD");
      else
      asm volatile ("lda %1\n\tldx $%2\n\tjsr U_SetTM"::"e" (time),
		    "r" (timer), "i" (pointer):"A", "X", "RegB", "RegC",
		    "RegD");
    }
  else
    {
      if (!__builtin_constant_p (timer))
	asm
	  volatile ("lda $%1\n\tldx %2\n\tjsr U_SetTM"::"e" (time),
		    "i" (timer), "r" (pointer):"A", "X", "RegB", "RegC",
		    "RegD");
      else
      asm
	volatile ("lda $%1\n\tldx $%2\n\tjsr U_SetTM"::"e" (time),
		  "i" (timer), "i" (pointer):"A", "X", "RegB", "RegC",
		  "RegD");
    }
}

static void inline
_U_SetTMx (uchar timer, uchar time)
{
  if (!__builtin_constant_p (timer))
    asm volatile ("lda %1\n\tjsr U_SetTMx"::"e" (time), "r" (timer):"A", "X",
		  "RegB", "RegC", "RegD");
  else
  asm volatile ("lda %1\n\tjsr U_SetTMx"::"e" (time), "r" (timer):"A", "X",
		"RegB", "RegC", "RegD");
}

static bool inline
_U_GetTM (uchar timer, uchar pointer)
{
  uchar ret;
  if (!__builtin_constant_p (pointer))
    {
      if (!__builtin_constant_p (timer))
	asm
	  volatile
	  ("lda %1\n\tldx %2\n\tjsr U_GetTM" SETAONZERO "sta %0":"=r"
	   (ret):"r" (timer), "r" (pointer):"A", "X", "RegB", "RegC", "RegD");
      else
      asm
	volatile
	("lda $%1\n\tldx %2\n\tjsr U_GetTM" SETAONZERO "sta %0":"=r"
	 (ret):"i" (timer), "r" (pointer):"A", "X", "RegB", "RegC", "RegD");
    }
  else
    {
      if (!__builtin_constant_p (timer))
	asm
	  volatile
	  ("lda %1\n\tldx $%2\n\tjsr U_GetTM" SETAONZERO "sta %0":"=r"
	   (ret):"r" (timer), "i" (pointer):"A", "X", "RegB", "RegC", "RegD");
      else
      asm
	volatile
	("lda $%1\n\tldx $%2\n\tjsr U_GetTM" SETAONZERO "sta %0":"=r"
	 (ret):"i" (timer), "i" (pointer):"A", "X", "RegB", "RegC", "RegD");
    }
  return ret;
}

static bool inline
_U_GetTMx (uchar timer)
{
  uchar ret;
  if (!__builtin_constant_p (timer))
    asm
      volatile
      ("lda %1\n\tjsr U_GetTM" SETAONZERO "sta %0":"=r"
       (ret):"r" (timer):"A", "X", "RegB", "RegC", "RegD");
  else
  asm
    volatile
    ("lda $%1\n\tjsr U_GetTM" SETAONZERO "sta %0":"=r"
     (ret):"i" (timer):"A", "X", "RegB", "RegC", "RegD");
  return ret;
}

static void inline
_U_Delay (uchar delay)
{
  if (!__builtin_constant_p (delay))
    asm volatile ("lda %0\n\tjsr U_Delay"::"r" (delay):"A", "X", "RegB");
  else
  asm volatile ("lda $%0\n\tjsr U_Delay"::"i" (delay):"A", "X", "RegB");
}

static AllocBuf_Result inline
_AllocBuf (bool longbuf)
{
  AllocBuf_Result ret;
  uchar e;
  if (longbuf)
    asm
      volatile
      ("sec\n\tjsr AllocBuf\n\tstx %1" SETAONCARRY "sta %0":"=r"
       (ret.valid), "=r" (e)::"A", "X");
  else
  asm
    volatile
    ("clc\n\tjsr AllocBuf\n\tstx %1" SETAONCARRY "sta %0":"=r"
     (ret.valid), "=r" (e)::"A", "X");
  ret.pointer = (uchar_loptr) (uint1) e;
  return ret;
}

static uchar_loptr inline
_AllocBuf_NE (bool longbuf)
{
  uchar ret;
  if (longbuf)
    asm volatile ("sec\n\tjsr AllocBuf\n\tstx %0":"=r" (ret)::"A", "X");
  else
  asm volatile ("clc\n\tjsr AllocBuf\n\tstx %0":"=r" (ret)::"A", "X");
  return (uchar_loptr) (uint1) ret;
}

static void inline
_FreeBuf (uchar_loptr pointer)
{
  uchar x = ((uint1) pointer);
  if (!__builtin_constant_p (x))
    asm volatile ("ldx %0\n\tjsr FreeBuf"::"r" (x):"A", "X", "RegB");
  else
  asm volatile ("ldx $%0\n\tjsr FreeBuf"::"i" (x):"A", "X", "RegB");
}

static PopBuf_Result inline
_PopBuf (uchar msg)
{
  PopBuf_Result ret;
  uchar e;
  if (!__builtin_constant_p (msg))
    asm
      volatile
      ("lda %2\n\tjsr PopBuf\n\tstx %1" SETAONCARRY "sta %0":"=r"
       (ret.found), "=r" (e):"r" (msg):"A", "X", "RegB");
  else
  asm
    volatile
    ("lda $%2\n\tjsr PopBuf\n\tstx %1" SETAONCARRY "sta %0":"=r"
     (ret.found), "=r" (e):"i" (msg):"A", "X", "RegB");
  ret.pointer = (uchar_loptr) (uint1) e;
  return ret;
}

static uchar_loptr inline
_PopBuf_NE (uchar msg)
{
  uchar ret;
  if (!__builtin_constant_p (msg))
    asm
      volatile
      ("lda %1\n\tjsr PopBuf\n\tstx %0":"=r"
       (ret):"r" (msg):"A", "X", "RegB");
  else
  asm
    volatile
    ("lda $%1\n\tjsr PopBuf\n\tstx %1":"=r" (ret):"i" (msg):"A", "X", "RegB");
  return (uchar_loptr) (uint1) ret;
}

static U_Mul_Result inline
_multDE_FG (unsigned short v1, unsigned short v2)
{
  U_Mul_Result ret;
  asm
    volatile
    ("jsr multDE_FG" SETAONCARRY "sta %0":"=r"
     (ret.overflow), "=q" (ret.product):"t" (v1), "u" (v2):"A", "X");
  return ret;
}
static unsigned short inline
_multDE_FG_NE (unsigned short v1, unsigned short v2)
{
  unsigned short ret;
  asm volatile ("jsr multDE_FG":"=q" (ret):"t" (v1), "u" (v2):"A", "X");
  return ret;
}

static U_Div_Result inline
_divDE_BC (unsigned short dividend, unsigned short divisor)
{
  U_Div_Result ret;
  asm
    volatile
    ("jsr divDE_BC" SETAONCARRY "sta %0":"=r"
     (ret.error), "=u" (ret.quotient), "=t" (ret.remainder):"q" (divisor),
     "t" (dividend):"A", "X");
  return ret;
}
static unsigned short inline
_divDE_BC_quotient (unsigned short dividend, unsigned short divisor)
{
  U_Div_Result ret;
  asm
    volatile
    ("jsr divDE_BC":"=u" (ret.quotient), "=t" (ret.remainder):"q" (divisor),
     "t" (dividend):"A", "X");
  return ret.quotient;
}

static unsigned short inline
_divDE_BC_remainder (unsigned short dividend, unsigned short divisor)
{
  U_Div_Result ret;
  asm
    volatile
    ("jsr divDE_BC":"=u" (ret.quotient), "=t" (ret.remainder):"q" (divisor),
     "t" (dividend):"A", "X");
  return ret.remainder;
}

#define DEF_SHIFTROT(NAME) static uchar inline _##NAME(uchar val){uchar ret;asm volatile ("lda %1\n\t jsr " #NAME "\n\tsta %1":"=r"(ret):"r"(val):"A");return ret; }

DEF_SHIFTROT (shlA4)
DEF_SHIFTROT (shlA5)
DEF_SHIFTROT (shlA6)
DEF_SHIFTROT (shlA7)
DEF_SHIFTROT (shrA4)
DEF_SHIFTROT (shrA5)
DEF_SHIFTROT (shrA6)
DEF_SHIFTROT (shrA7)
DEF_SHIFTROT (rolA1)
DEF_SHIFTROT (rolA2)
DEF_SHIFTROT (rolA3) DEF_SHIFTROT (rolA4) DEF_SHIFTROT (rolA7)
     static
       uchar
       inline
     _U_SetBit (uchar octet, uchar bit, bool set)
{
  if (!__builtin_constant_p (bit))
    {
      if (set)
	asm volatile ("sec\n\tlda %1\n\tjsr U_SetBit":"=h" (octet):"r" (bit),
		      "0" (octet):"RegB", "A");
      else
      asm volatile ("clc\n\tlda %1\n\tjsr U_SetBit":"=h" (octet):"r" (bit),
		    "0" (octet):"RegB", "A");
    }
  else
    {
      if (set)
	asm volatile ("sec\n\tlda $%1\n\tjsr U_SetBit":"=h" (octet):"i" (bit),
		      "0" (octet):"RegB", "A");
      else
      asm volatile ("clc\n\tlda $%1\n\tjsr U_SetBit":"=h" (octet):"i" (bit),
		    "0" (octet):"RegB", "A");
    }
  return octet;
}

static bool inline
_U_GetBit (uchar octet, uchar bit)
{
  uchar ret;
  if (!__builtin_constant_p (bit))
    asm
      volatile
      ("lda %1\n\tjsr U_GetBit" SETAONNZERO "sta %0":"=r"
       (ret):"r" (bit), "h" (octet):"A", "X", "RegB");
  else
  asm
    volatile
    ("lda $%1\n\tjsr U_GetBit" SETAONNZERO "sta %0":"=r"
     (ret):"i" (bit), "h" (octet):"A", "X", "RegB");
  return ret;
}

#ifdef BCU_0020_H

static void inline
_U_EE_WriteBlock (void *ptr, long data)
{
  asm volatile ("jsr U_EE_WriteBlock"::"v" (ptr), "y" (data):"A", "X", "RegB",
		"RegC", "RegJ");
}

static uchar inline
_U_GetAccess ()
{
  uchar ret;
  asm volatile ("jsr U_GetAccess\n\tsta %0":"=r" (ret)::"A");
  return ret;
}

static void inline
_U_SetPollingRsp (uchar val)
{
  if (!__builtin_constant_p (val))
    asm volatile ("lda %0\n\tjsr U_SetPollingRsp"::"r" (val):"A");
  else
  asm volatile ("lda $%0\n\tjsr U_SetPollingRsp"::"i" (val):"A");
}

static void inline
_U_Char_Out (uchar val)
{
  if (!__builtin_constant_p (val))
    asm volatile ("lda %0\n\tjsr U_Char_Out"::"r" (val):"A", "X");
  else
  asm volatile ("lda $%0\n\tjsr U_Char_Out"::"i" (val):"A", "X");
}

static void inline
_U_TS_Set (uchar timer, uchar mode, uchar scale, uchar value, uchar param)
{
  if (!__builtin_constant_p (timer))
    {
      if (!__builtin_constant_p (mode))
	asm volatile ("lda %1\n\tldx %2\n\tjsr U_TS_Set"::"z" (scale),
		      "r" (mode), "r" (timer), "c" (value), "d" (param):"A",
		      "X", "RegB", "RegC", "RegD", "RegE", "RegF");
      else
      asm volatile ("lda %1\n\tldx $%2\n\tjsr U_TS_Set"::"z" (scale),
		    "r" (mode), "i" (timer), "c" (value), "d" (param):"A",
		    "X", "RegB", "RegC", "RegD", "RegE", "RegF");
    }
  else
    {
      if (!__builtin_constant_p (mode))
	asm volatile ("lda $%1\n\tldx %2\n\tjsr U_TS_Set"::"z" (scale),
		      "i" (mode), "r" (timer), "c" (value), "d" (param):"A",
		      "X", "RegB", "RegC", "RegD", "RegE", "RegF");
      else
      asm volatile ("lda $%1\n\tldx $%2\n\tjsr U_TS_Set"::"z" (scale),
		    "i" (mode), "i" (timer), "c" (value), "d" (param):"A",
		    "X", "RegB", "RegC", "RegD", "RegE", "RegF");
    }
}

static void inline
_U_TS_Del (uchar val)
{
  if (!__builtin_constant_p (val))
    asm volatile ("ldx %0\n\tjsr U_TS_Del"::"r" (val):"X");
  else
  asm volatile ("ldx $%0\n\tjsr U_TS_Del"::"i" (val):"X");
}

static void inline
_U_MS_Post (uchar msgid, uchar_loptr pointer)
{
  if (!__builtin_constant_p (msgid))
    {
      if (!__builtin_constant_p (pointer))
	asm volatile ("lda %0\n\tldx %1\n\tjsr U_MS_Post"::"r" (msgid),
		      "r" (pointer):"A", "X", "RegB", "RegL", "RegM", "RegN");
      else
      asm volatile ("lda %0\n\tldx $%1\n\tjsr U_MS_Post"::"r" (msgid),
		    "i" (pointer):"A", "X", "RegB", "RegL", "RegM", "RegN");
    }
  else
    {
      if (!__builtin_constant_p (pointer))
	asm volatile ("lda $%0\n\tldx %1\n\tjsr U_MS_Post"::"i" (msgid),
		      "r" (pointer):"A", "X", "RegB", "RegL", "RegM", "RegN");
      else
      asm volatile ("lda $%0\n\tldx $%1\n\tjsr U_MS_Post"::"i" (msgid),
		    "i" (pointer):"A", "X", "RegB", "RegL", "RegM", "RegN");
    }
}

static void inline
_U_MS_Switch (uchar msgid, uchar destination)
{
  if (!__builtin_constant_p (msgid))
    {
      if (!__builtin_constant_p (destination))
	asm volatile ("lda %0\n\tldx %1\n\tjsr U_MS_Switch"::
		      "r" (destination), "r" (msgid):"A", "X", "RegB", "RegL",
		      "RegM", "RegN");
      else
      asm volatile ("lda %0\n\tldx $%1\n\tjsr U_MS_Switch"::"r" (destination),
		    "i" (msgid):"A", "X", "RegB", "RegL", "RegM", "RegN");
    }
  else
    {
      if (!__builtin_constant_p (destination))
	asm volatile ("lda $%0\n\tldx %1\n\tjsr U_MS_Switch"::
		      "i" (destination), "r" (msgid):"A", "X", "RegB", "RegL",
		      "RegM", "RegN");
      else
      asm volatile ("lda $%0\n\tldx $%1\n\tjsr U_MS_Switch"::
		    "i" (destination), "i" (msgid):"A", "X", "RegB", "RegL",
		    "RegM", "RegN");
    }
}

static short inline
_FP_Flt2Int (uchar ptr, uchar exponent)
{
  short ret;
  if (!__builtin_constant_p (ptr))
    asm volatile ("ldx %1\n\tjsr FP_Flt2Int":"=q" (ret):"r" (ptr),
		  "f" (exponent):"A", "X", "RegD", "RegE");
  else
  asm volatile ("ldx $%1\n\tjsr FP_Flt2Int":"=q" (ret):"i" (ptr),
		"f" (exponent):"A", "X", "RegD", "RegE");
  return ret;
}

static void inline
_FP_Int2Flt (short val, uchar ptr, uchar exponent)
{
  if (!__builtin_constant_p (ptr))
    asm volatile ("ldx %0\n\tjsr FP_Int2Flt"::"r" (ptr), "f" (exponent),
		  "q" (val));
  else
  asm volatile ("ldx $%0\n\tjsr FP_Int2Flt"::"i" (ptr), "f" (exponent),
		"q" (val));
}

static void inline
_U_FT12_Reset (uchar baudrate)
{
  if (!__builtin_constant_p (baudrate))
    asm volatile ("lda %0\n\tjsr U_FT12_Reset"::"r" (baudrate):"A", "X",
		  "RegB", "RegC", "RegD", "RegE", "RegF", "RegG", "RegH",
		  "RegI", "RegJ", "RegK", "RegL", "RegM", "RegN");
  else
  asm volatile ("lda $%0\n\tjsr U_FT12_Reset"::"i" (baudrate):"A", "X",
		"RegB", "RegC", "RegD", "RegE", "RegF", "RegG", "RegH",
		"RegI", "RegJ", "RegK", "RegL", "RegM", "RegN");
}

static FT12_GetStatus_Result inline
_U_FT12_GetStatus (bool force_reset)
{
  FT12_GetStatus_Result ret;
  if (force_reset)
    asm
      volatile
      ("sec\n\tjsr U_FT12_GetStatus\n\tsta %0" SETAONCARRY "sta %1":"=r"
       (ret.stateok), "=r" (ret.newstate)::"A");
  else
  asm
    volatile
    ("clc\n\tjsr U_FT12_GetStatus\n\tsta %0" SETAONCARRY "sta %1":"=r"
     (ret.stateok), "=r" (ret.newstate)::"A");
  return ret;
}

static void inline
_U_SCI_Init (uchar baudrate)
{
  if (!__builtin_constant_p (baudrate))
    asm volatile ("lda %0\n\tjsr U_SCI_Init"::"r" (baudrate):"A", "X");
  else
  asm volatile ("lda $%0\n\tjsr U_SCI_Init"::"i" (baudrate):"A", "X");
}

static void inline
_U_SPI_Init ()
{
  asm volatile ("jsr U_SPI_Init":::"A", "X");
}

#undef SETAONCARRY
#undef SETAONZERO
#undef SETAONNZERO

#endif

static inline void
__U_flag_Set (uchar no, uchar bit)
{
  if (__builtin_constant_p (no) && __builtin_constant_p (bit))
    asm volatile ("bset.%1 %0+ramflag_pointer"::"i" (no / 2),
		  "i" ((bit % 4) + (no % 2) * 4));
  else
  _U_flagsSet (no, _U_flagsGet (no) | (1 << bit));
}

static inline void
__U_flag_Clear (uchar no, uchar bit)
{
  if (__builtin_constant_p (no) && __builtin_constant_p (bit))
    asm volatile ("bclr.%1 %0+ramflag_pointer"::"i" (no / 2),
		  "i" ((bit % 4) + (no % 2) * 4));
  else
  _U_flagsSet (no, _U_flagsGet (no) & ~(1 << bit));
}

static inline void
__U_transRequest (uchar no)
{
  if (__builtin_constant_p (no))
    {
      __U_flag_Set (no, 0);
      __U_flag_Set (no, 1);
    }
  else
    _U_transRequest (no);
}


/* not implemented:
AL_SAPcallback
U_EE_WriteHI

not supported:
U_TS_Seti
 */

#endif
