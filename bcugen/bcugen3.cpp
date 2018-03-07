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

#include <stdio.h>
#include "readconfig.h"
#include "xmlwriteappinfo.h"
#include "write.h"
#include "check.h"
#include "gencode.h"
#include "symboltab.h"

int
main (int ac, char *ag[])
{
  FILE *f;
  if (ac != 6)
    die("Usage: %s description hfile incfile asmfile variant", ag[0]);

  NewSymbol ("main", 0);
  Device *d = ReadConfig (ag[1]);
  if (!d)
    die (_("read of description %s failed"), ag[1]);
  CheckDevice (*d);

  f = fopen (ag[4], "w");
  if (!f)
    die (_("writing to %s failed"), ag[7]);
  GenRealAsm (f, *d);
  fclose (f);

  f = fopen (ag[2], "w");
  if (!f)
    die (_("writing to %s failed"), ag[4]);
  GenRealHeader (f, *d);
  fclose (f);

  f = fopen (ag[3], "w");
  if (!f)
    die (_("writing to %s failed"), ag[5]);
  GenInclude (f, *d);
  fclose (f);

  f = fopen (ag[5], "w");
  if (!f)
    die (_("writing to %s failed"), ag[8]);
  fprintf (f, "%s", GetVariant (*d) ());
  fclose (f);

  delete d;
  return 0;
}
