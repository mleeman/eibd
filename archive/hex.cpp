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

#include "hex.h"

static const uchar hexc[] = "0123456789ABCDEF";

CArray
encode_hex (CArray c)
{
  CArray erg;
  int i, j;
  erg.resize (c () * 2 + 1);
  for (j = i = 0; i < c (); i++, j += 2)
    {
      erg[j] = hexc[(c[i] >> 4) & 0x0f];
      erg[j + 1] = hexc[(c[i] >> 0) & 0x0f];
    }
  erg[j] = 0;
  return erg;
}

CArray
decode_hex (CArray c)
{
  CArray erg;
  int i, j;
  uchar c1, c2;
  erg.resize (c () / 2);
  if (c () % 2)
    return CArray ();
  for (j = i = 0; i < c (); i += 2, j++)
    {
      c1 = c[i];
      c2 = c[i + 1];
      if ('0' <= c1 && c1 <= '9')
	c1 = c1 - '0';
      else if ('A' <= c1 && c1 <= 'F')
	c1 = c1 - 'A' + 0xA;
      else if ('a' <= c1 && c1 <= 'f')
	c1 = c1 - 'a' + 0xA;
      else
	c1 = 0;
      if ('0' <= c2 && c2 <= '9')
	c2 = c2 - '0';
      else if ('A' <= c2 && c2 <= 'F')
	c2 = c2 - 'A' + 0xA;
      else if ('a' <= c2 && c2 <= 'f')
	c2 = c2 - 'a' + 0xA;
      else
	c2 = 0;
      erg[j] = (c1 << 4) | c2;
    }
  return erg;
}
