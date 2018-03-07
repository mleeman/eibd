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

#ifndef EXPR_H
#define EXPR_H

#include "common.h"

class Expr
{

public:
  Expr ();
  virtual ~ Expr ();

  Expr *op1, *op2;
  ftype f;
  itype i;
  String s;
  IdentArray id;
  enum
  {
    E_AND, E_OR, E_NOT, E_LE, E_LT, E_GT, E_GE, E_EQ, E_NE, E_NOTNULL, E_IN,
    E_PLUS, E_MINUS, E_NEG, E_MUL, E_DIV, E_MOD, E_INT, E_FLOAT, E_STRING,
    E_PAR, E_NONE,
  } Type;

};

String printExpression (Expr * s);

#endif
