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

#ifndef _BCU_TYPES_H
#define _BCU_TYPES_H

#include <stdbool.h>

#define EEPROM_ATTRIB __attribute__ ((eeprom))
#define EEPROM_PTR_ATTRIB __attribute__ ((eepromt))

#define LORAM_ATTRIB __attribute__ ((loram))
#define LORAM_PTR_ATTRIB __attribute__ ((loramt))

#define EEPROM_SECTION __attribute__ ((section (".eeprom")))
#define LOW_CONST_SECTION __attribute__ ((section (".loconst")))
#define RAM_SECTION __attribute__ ((section (".ram")))

#define NOSAVE(PROTO) PROTO __attribute__ ((nosave)); PROTO

typedef signed int sint1 __attribute__ ((mode (QI)));
typedef signed int sint2 __attribute__ ((mode (HI)));
typedef signed int sint3 __attribute__ ((mode (AI)));
typedef signed int sint4 __attribute__ ((mode (SI)));
typedef signed int sint5 __attribute__ ((mode (FI)));
typedef signed int sint6 __attribute__ ((mode (CI)));
typedef signed int sint7 __attribute__ ((mode (EI)));
typedef signed int sint8 __attribute__ ((mode (DI)));

typedef unsigned int uint1 __attribute__ ((mode (QI)));
typedef unsigned int uint2 __attribute__ ((mode (HI)));
typedef unsigned int uint3 __attribute__ ((mode (AI)));
typedef unsigned int uint4 __attribute__ ((mode (SI)));
typedef unsigned int uint5 __attribute__ ((mode (FI)));
typedef unsigned int uint6 __attribute__ ((mode (CI)));
typedef unsigned int uint7 __attribute__ ((mode (EI)));
typedef unsigned int uint8 __attribute__ ((mode (DI)));

typedef uint1 uchar;
typedef uchar* uchar_loptr LORAM_PTR_ATTRIB;

#endif
