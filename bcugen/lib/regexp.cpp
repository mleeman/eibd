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

#include "regexp.h"
#include <libxml/xmlregexp.h>

bool
checkRegExp (const char *regexp)
{
  xmlRegexpPtr x = xmlRegexpCompile ((const xmlChar *) regexp);
  if (!x)
    return 0;
  xmlRegFreeRegexp (x);
  return 1;
}

bool
validateString (const char *regexp, const char *str)
{
  xmlRegexpPtr x = xmlRegexpCompile ((const xmlChar *) regexp);
  if (!x)
    return 0;
  int r = xmlRegexpExec (x, (const xmlChar *) str);
  xmlRegFreeRegexp (x);
  return r == 1;
}
