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

#ifndef MAP_H
#define MAP_H

#include "common.h"

itype Map_ProfileID (const String & s);
ftype Map_DPType (const String & s);
GroupType Map_GroupType (const String & s);
PropertyType Map_PropertyType (const String & s);
BCUType Map_BCUType (const String & s);
itype Map_PropertyID (const String & s);
itype Map_ObjectType (const String & s);
TimerType Map_TimerType (const String & s);
TimerResType Map_TimerResType (const String & s);
prio_t Map_Prio (const String & s);

String escapeString (const String & s);
const char *unMap_GroupType (GroupType s);
const char *unMap_PropertyType (PropertyType s);
const char *unMap_BCUType (BCUType s);
const char *unMap_TimerType (TimerType s);
const char *unMap_TimerResType (TimerResType s);
const char *unMap_Prio (const String & s);
#endif
