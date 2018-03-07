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
#define OBJECT(A) A::A() { lineno=0;
#undef CI_OBJECT
#define CI_OBJECT(A)
#undef END_OBJECT
#define END_OBJECT }
#undef ATTRIB_STRING
#define ATTRIB_STRING(A) A##_lineno=0;
#undef ATTRIB_IDENT
#define ATTRIB_IDENT(A) A##_lineno=0;
#undef ATTRIB_FLOAT
#define ATTRIB_FLOAT(A) A=0;A##_lineno=0;
#undef ATTRIB_INT
#define ATTRIB_INT(A) A=0;A##_lineno=0;
#undef ATTRIB_BOOL
#define ATTRIB_BOOL(A) A=0;A##_lineno=0;
#undef ATTRIB_ENUM_MAP
#define ATTRIB_ENUM_MAP(A) A##_lineno=0;
#undef ATTRIB_ARRAY_OBJECT
#define ATTRIB_ARRAY_OBJECT(A)
#undef ATTRIB_INT_MAP
#define ATTRIB_INT_MAP(A,B) A=0;A##_lineno=0;
#undef ATTRIB_FLOAT_MAP
#define ATTRIB_FLOAT_MAP(A,B) A=0;A##_lineno=0;
#undef ATTRIB_ENUM
#define ATTRIB_ENUM(A,B,C) A##_lineno=0;
#undef ATTRIB_KEY_MAP
#define ATTRIB_KEY_MAP(A) A##_lineno=0;
#undef ATTRIB_INT_ARRAY
#define ATTRIB_INT_ARRAY(A) A##_lineno=0;
#undef ATTRIB_IDENT_ARRAY
#define ATTRIB_IDENT_ARRAY(A) A##_lineno=0;
#undef ATTRIB_String_ARRAY
#define ATTRIB_String_ARRAY(A) A##_lineno=0;

#undef PRIVATE_VAR
#define PRIVATE_VAR(A)
#undef ATTRIB_EXPR
#define ATTRIB_EXPR(A) A##_lineno=0;
