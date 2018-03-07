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
#include "eibclient.h"
#include "common.h"
#include "types.h"
#include "image.h"
#include "loadimage.h"

int
main (int ac, char *ag[])
{
  Array < uint8_t > p;
  int len;
  uint8_t buf[200];
  EIBConnection *con;

  bool dump = 0;
  if (ac != 3 && ac != 4)
    die (_("%s [-d] url image"), ag[0]);

  if (ac == 4 && strcmp (ag[1], "-d"))
    die (_("%s [-d] url image"), ag[0]);
  if (ac == 4)
    ag++, dump = 1;

  FILE *f = fopen (ag[2], "r");
  if (!f)
    die (_("open of %s failed"), ag[2]);

  while (!feof (f))
    {
      int i = fread (buf, 1, sizeof (buf), f);
      p.setpart (buf, p (), i);
    }
  fclose (f);

  if (dump)
    printf ("%s", HexDump (p) ());

  BCUImage *i;
  int res;

  BCU_LOAD_RESULT r = PrepareLoadImage (p, i);

  if (r != IMG_IMAGE_LOADABLE)
    {
      printf ("%s\n", decodeBCULoadResult (r) ());
      return 1;
    }

  con = EIBSocketURL (ag[1]);
  if (!con)
    die ("Open failed");

  res = EIB_LoadImage (con, p (), p.array ());

  if (res == - 1)
    printf ("Communication with EIBD failed\n");
  else
    printf ("%s\n", decodeBCULoadResult (res) ());

  EIBClose (con);
  return 0;
}
