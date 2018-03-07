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

#undef OBJECT
#define OBJECT(A) void A::init_ci() { bool ci=false;
#undef CI_OBJECT
#define CI_OBJECT(A) ci=true;
#undef END_OBJECT
#define END_OBJECT }
#undef ATTRIB_STRING
#define ATTRIB_STRING(A) if(ci)A##_lineno=0;
#undef ATTRIB_IDENT
#define ATTRIB_IDENT(A) if(ci)A##_lineno=0;
#undef ATTRIB_FLOAT
#define ATTRIB_FLOAT(A) if(ci)A##_lineno=0;
#undef ATTRIB_INT
#define ATTRIB_INT(A) if(ci)A##_lineno=0;
#undef ATTRIB_BOOL
#define ATTRIB_BOOL(A) if(ci)A##_lineno=0;
#undef ATTRIB_ENUM_MAP
#define ATTRIB_ENUM_MAP(A) if(ci) A##_lineno=0;
#undef ATTRIB_ARRAY_OBJECT
#define ATTRIB_ARRAY_OBJECT(A) for(int i=0;i<A##s();i++)A##s[i].init_ci();
#undef ATTRIB_INT_MAP
#define ATTRIB_INT_MAP(A,B) if(ci) A##_lineno=0;
#undef ATTRIB_FLOAT_MAP
#define ATTRIB_FLOAT_MAP(A,B) if(ci) A##_lineno=0;
#undef ATTRIB_ENUM
#define ATTRIB_ENUM(A,B,C) if(ci) A##_lineno=0;
#undef ATTRIB_KEY_MAP
#define ATTRIB_KEY_MAP(A) if(ci) { A.resize (0); A##_lineno=0; }
#undef ATTRIB_IDENT_ARRAY
#define ATTRIB_IDENT_ARRAY(A) if(ci) A##_lineno=0;
#undef ATTRIB_INT_ARRAY
#define ATTRIB_INT_ARRAY(A) if(ci) { A.resize (0); A##_lineno=0; }
#undef ATTRIB_String_ARRAY
#define ATTRIB_String_ARRAY(A) if(ci) A##_lineno=0;

#undef PRIVATE_VAR
#define PRIVATE_VAR(A)
#undef ATTRIB_EXPR
#define ATTRIB_EXPR(A) if(ci) A##_lineno=0;
