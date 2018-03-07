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

#ifndef PROP_TYPES_H
#define PROP_TYPES_H

typedef sint1 PROP1_T;
typedef uint1 PROP2_T;
typedef sint2 PROP3_T;
typedef uint2 PROP4_T;
typedef uint2 PROP5_T;
typedef uint3 PROP6_T;
typedef uint3 PROP7_T;
typedef sint4 PROP8_T;
typedef uint4 PROP9_T;
typedef float PROP10_T;
typedef double PROP11_T;
typedef uint1 PROP12_T[10];
typedef uint3 PROP13_T;
typedef uint5 PROP14_T;

typedef uint1 PROP17_T;
typedef uint2 PROP18_T;
typedef uint3 PROP19_T;
typedef uint4 PROP20_T;
typedef uint5 PROP21_T;
typedef uint6 PROP22_T;
typedef uint7 PROP23_T;
typedef uint8 PROP24_T;
typedef uint1 PROP25_T[9];
typedef uint1 PROP26_T[10];

typedef struct
{
  bool write;
  uint1 ptr;
} PropertyRequest;
typedef struct
{
  bool error;
  uint1 ptr;
  uint1 length;
} PropertyResult;

#endif
