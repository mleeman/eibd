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

#ifndef ADDRTAB_H
#define ADDRTAB_H

#include "classes.h"
#include <stdio.h>

typedef struct {
    Array < eibgaddr_t > addr;
    Array < int >ObjNo;
    Array < int >Addr;
} AddrTable;

void BuildObjAddress (GroupObject & o, BCUType b);
void BuildAddrTable (AddrTable & t, Device & d);
int GroupObjectFlag (GroupObject & o, BCUType b);


void printAddrTab (FILE * f, Device & d);
void printPseudoAddrTab (FILE * f, Device & d);

#endif
