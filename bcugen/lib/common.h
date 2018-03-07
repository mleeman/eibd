/*
    BCU SDK bcu development enviroment
    Copyright (C) 2005-2011 Martin Koegler <mkoegler@auto.tuwien.ac.at>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef COMMON_H
#define COMMON_H

#define _(A) (A)

#include "array.h"
#include "my_strings.h"
#include "types.h"

typedef unsigned long utype;
typedef long itype;
typedef double ftype;
typedef struct
{
  String Name;
  String Value;
} Map;
typedef Array < Map > IdentMap;
typedef Array < int >IntArray;
typedef Array < String > IdentArray;
typedef Array < String > StringArray;
typedef unsigned short eibaddr_t;
typedef unsigned short eibpaddr_t;
typedef unsigned short eibgaddr_t;
typedef unsigned long eibkey_t;

typedef enum
{ PRIO_LOW = 0, PRIO_NORMAL = 1, PRIO_URGENT = 2, PRIO_SYSTEM = 3 } prio_t;


class KeyMap
{
public:
  int level;
  eibkey_t key;

    KeyMap ()
  {
    level = 0;
    key = 0;
  }
  KeyMap (int l, eibkey_t k)
  {
    level = l;
    key = k;
  }
};
typedef Array < KeyMap > KeyMapArray;

typedef enum
{
#define MAP(A,B) GO_##B=A,
#include "GroupObjectType.lst"
#undef MAP
} GroupType;

typedef enum
{
#define MAP(A,B) B=A,
#include "PropertyType.lst"
#undef MAP
} PropertyType;

typedef enum
{
#define MAP(A,B) BCU_##B=A,
#include "BCUType.lst"
#undef MAP
} BCUType;

typedef enum
{
#define MAP(A,B) TM_##B=A,
#include "TimerType.lst"
#undef MAP
} TimerType;

typedef enum
{
#define MAP(A,B) TM_##B=A,
#include "TimerResType.lst"
#undef MAP
} TimerResType;


void die (const char *msg, ...);
void warn (const char *msg, ...);

#endif
