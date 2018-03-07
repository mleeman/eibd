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
#define OBJECT(A) static void Write##A(FILE* f,const A&d) { int i; fprintf(f,"%s {\n",#A);
#undef CI_OBJECT
#define CI_OBJECT(A)
#undef END_OBJECT
#define END_OBJECT fprintf(f,"};\n"); }
#undef ATTRIB_IDENT
#define ATTRIB_IDENT(A) if(d.A##_lineno) fprintf(f,"%s %s;\n",#A,d.A());
#undef ATTRIB_FLOAT
#define ATTRIB_FLOAT(A) if(d.A##_lineno) fprintf(f,"%s %f;\n",#A,d.A);
#undef ATTRIB_INT
#define ATTRIB_INT(A) if(d.A##_lineno) fprintf(f,"%s %d;\n",#A,d.A);
#undef ATTRIB_BOOL
#define ATTRIB_BOOL(A) if(d.A##_lineno) fprintf(f,"%s %s;\n",#A,d.A?"true":"false");
#undef ATTRIB_INT_MAP
#define ATTRIB_INT_MAP(A,B) if(d.A##_lineno) fprintf(f,"%s %d;\n",#A,d.A);
#undef ATTRIB_FLOAT_MAP
#define ATTRIB_FLOAT_MAP(A,B) if(d.A##_lineno) fprintf(f,"%s %f;\n",#A,d.A);
#undef ATTRIB_KEY_MAP
#define ATTRIB_KEY_MAP(A) if(d.A##_lineno){fprintf(f,"%s {",#A);for(i=0;i<d.A();i++) fprintf(f,"%d=%d,",d.A[i].level,d.A[i].key);fprintf(f,"};\n"); }
#undef ATTRIB_INT_ARRAY
#define ATTRIB_INT_ARRAY(A) if(d.A##_lineno){fprintf(f,"%s {",#A);for(i=0;i<d.A();i++) fprintf(f,"%d,",d.A[i]);fprintf(f,"};\n"); }
#undef ATTRIB_IDENT_ARRAY
#define ATTRIB_IDENT_ARRAY(A) if(d.A##_lineno){fprintf(f,"%s {",#A);for(i=0;i<d.A();i++) fprintf(f,"%s,",d.A[i]());fprintf(f,"};\n"); }
#undef ATTRIB_STRING_ARRAY
#define ATTRIB_STRING_ARRAY(A) if(d.A##_lineno){fprintf(f,"%s {",#A);for(i=0;i<d.A();i++) fprintf(f,"\"%s\",",escapeString(d.A[i])());fprintf(f,"};\n"); }

#undef ATTRIB_ENUM_MAP
#define ATTRIB_ENUM_MAP(A) if(d.A##_lineno){fprintf(f,"%s {",#A);for(i=0;i<d.A();i++) fprintf(f,"%s=\"%s\";",d.A[i].Name(),escapeString(d.A[i].Value)());fprintf(f,"};\n"); }
#undef ATTRIB_STRING
#define ATTRIB_STRING(A) if(d.A##_lineno) fprintf(f,"%s \"%s\";\n",#A,escapeString(d.A)());
#undef ATTRIB_ARRAY_OBJECT
#define ATTRIB_ARRAY_OBJECT(A) for(i=0;i<d.A##s();i++)Write##A(f,d.A##s[i]);
#undef ATTRIB_ENUM
#define ATTRIB_ENUM(A,B,C) if(d.A##_lineno) fprintf(f,"%s %s;\n",#A,un##C(d.A));
#undef PRIVATE_VAR
#define PRIVATE_VAR(A)
#undef ATTRIB_EXPR
#define ATTRIB_EXPR(A) if(d.A##_lineno) fprintf(f,"%s=%s;\n",#A,printExpression(d.A)());
