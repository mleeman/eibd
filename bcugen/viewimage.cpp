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

#include "image.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include "loadimage.h"

int
main (int ac, char *ag[])
{
  CArray p;
  uchar buf[200];
  bool dump = 0;
  if (ac != 2 && ac != 3)
    die (_("%s [-d] image"), ag[0]);

  if (ac == 3 && strcmp (ag[1], "-d"))
    die (_("%s [-d] image"), ag[0]);
  if (ac == 3)
    ag++, dump = 1;

  FILE *f = fopen (ag[1], "r");
  if (!f)
    die (_("open of %s failed"), ag[1]);

  while (!feof (f))
    {
      int i = fread (buf, 1, sizeof (buf), f);
      p.setpart (buf, p (), i);
    }
  fclose (f);

  if (dump)
    printf ("%s", HexDump (p) ());

  Image *i = Image::fromArray (p);
  if (!i)
    die (_("not a image"));

  if (!i->isValid ())
    die (_("not a valid image\n"));

  printf ("%s\n", i->decode ()());

  BCUImage *im;

  BCU_LOAD_RESULT r = PrepareLoadImage (p, im);

  printf ("%s\n", decodeBCULoadResult (r) ());

  return 0;
}
