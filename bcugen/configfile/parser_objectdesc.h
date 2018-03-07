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
#define OBJECT(A) A##_struct :  TOK_##A '{' { A* a=new A;stack.push(a);a->lineno=yylineno; } A##_bodys '}' ';' {$$=(typeof($$))stack.pop();} ; A##_bodys :  | A##_body A##_bodys ; A##_body : A##_bodys_CI | Empty_CI | 
#undef CI_OBJECT
#define CI_OBJECT(A) NEVER_OCCUR { $$; } ; A##_bodys_CI : Begin_CI A##_bodys_CI_i End_CI { $$; } ; A##_bodys_CI_i : A##_body_CI | A##_body_CI A##_bodys_CI_i; A##_body_CI :
#undef END_OBJECT
#define END_OBJECT  NEVER_OCCUR { $$; } ;

#define ATTRIB_INIT(A) typeof($$) a =(typeof($$))(stack.top())
#define ATTRIB_CHECKDOUBLE(A) if(a->A##_lineno)parserError(_("%s already set at line %d"),#A,a->A##_lineno);a->A##_lineno=yylineno;

#undef ATTRIB_STRING
#define ATTRIB_STRING(A)  TOK_##A string ';' { ATTRIB_INIT(A);ATTRIB_CHECKDOUBLE(A); a->A=*$2; delete $2;} |
#undef ATTRIB_IDENT
#define ATTRIB_IDENT(A)  TOK_##A ident ';' { ATTRIB_INIT(A);ATTRIB_CHECKDOUBLE(A); a->A=*$2; delete $2;}|
#undef ATTRIB_INT
#define ATTRIB_INT(A)  TOK_##A intc ';' { ATTRIB_INIT(A);ATTRIB_CHECKDOUBLE(A); a->A=$2;}|
#undef ATTRIB_BOOL
#define ATTRIB_BOOL(A)  TOK_##A bool ';' { ATTRIB_INIT(A);ATTRIB_CHECKDOUBLE(A); a->A=$2;}|
#undef ATTRIB_FLOAT
#define ATTRIB_FLOAT(A)  TOK_##A floatc ';' { ATTRIB_INIT(A);ATTRIB_CHECKDOUBLE(A); a->A=$2;}|
#undef ATTRIB_ARRAY_OBJECT
#define ATTRIB_ARRAY_OBJECT(A)  A##_struct { ATTRIB_INIT(A); a->A##s.add(*$1); delete $1; }|
#undef ATTRIB_ENUM_MAP
#define ATTRIB_ENUM_MAP(A)  TOK_##A identmap ';' { ATTRIB_INIT(A); ATTRIB_CHECKDOUBLE(A); a->A=*$2; delete $2; }|

#undef ATTRIB_INT_MAP
#define ATTRIB_INT_MAP(A,B)  TOK_##A intc ';' { ATTRIB_INIT(A);ATTRIB_CHECKDOUBLE(A); a->A=$2;}| TOK_##A ident ';' { ATTRIB_INIT(A);ATTRIB_CHECKDOUBLE(A); a->A=B(*$2);delete $2;}|
#undef ATTRIB_FLOAT_MAP
#define ATTRIB_FLOAT_MAP(A,B)  TOK_##A floatc ';' { ATTRIB_INIT(A);ATTRIB_CHECKDOUBLE(A); a->A=$2;}| TOK_##A ident ';' { ATTRIB_INIT(A);ATTRIB_CHECKDOUBLE(A); a->A=B(*$2);delete $2;}|

#undef ATTRIB_ENUM
#define ATTRIB_ENUM(A,B,C) TOK_##A ident ';' { ATTRIB_INIT(A);ATTRIB_CHECKDOUBLE(A); a->A=C(*$2);delete $2;}|

#undef ATTRIB_KEY_MAP
#define ATTRIB_KEY_MAP(A) TOK_##A keymaparray ';' { ATTRIB_INIT(A); ATTRIB_CHECKDOUBLE(A); a->A=*$2; delete $2; }|
#undef ATTRIB_IDENT_ARRAY
#define ATTRIB_IDENT_ARRAY(A) TOK_##A identarray ';' { ATTRIB_INIT(A); ATTRIB_CHECKDOUBLE(A); a->A=*$2; delete $2; }|
#undef ATTRIB_INT_ARRAY
#define ATTRIB_INT_ARRAY(A) TOK_##A intarray ';' { ATTRIB_INIT(A); ATTRIB_CHECKDOUBLE(A); a->A=*$2; delete $2; }|
#undef ATTRIB_STRING_ARRAY
#define ATTRIB_STRING_ARRAY(A) TOK_##A stringarray ';' { ATTRIB_INIT(A); ATTRIB_CHECKDOUBLE(A); a->A=*$2; delete $2; }|

#undef PRIVATE_VAR
#define PRIVATE_VAR(A)
#undef ATTRIB_EXPR
#define ATTRIB_EXPR(A) TOK_##A expr ';' { ATTRIB_INIT(A); ATTRIB_CHECKDOUBLE(A); a->A=$2; }|
