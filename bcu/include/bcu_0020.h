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

#ifndef _BCU_0020_H
#define _BCU_0020_H

#include "bcu_common.h"

#define BCU_0020_H
#include "bcu_funcs.h"

/* PEI Events */

#define PM_INIT 0xF3
#define PM_MESSAGE 0xF1
#define PM_CYCLE 0xF2

#define PM_rc_even 0x03
#define PM_rc_odd 0x13
#define PM_rc_tc 0x14
#define PM_tdre 0x05
#define PM_sci_idle 0x06
#define PM_spif 0x08
#define PM_OCA 0x10
#define PM_OCB 0x20
#define PM_ICA 0x30
#define PM_ICB 0x40

extern uchar PEI_Interface;
extern uchar PEI_Info;
extern uchar PEI_RecBuf[25];
extern uchar PEI_SndBuf[25];

#define TASK_LL_ID 1
#define TASK_NL_ID 2
#define TASK_TL_ID 3
#define TASK_TC_ID 4
#define TASK_LC_ID 5
#define TASK_AL_ID 6
#define TASK_MG_ID 7
#define TASK_PM_ID 8
#define TASK_US_ID 9

#endif
