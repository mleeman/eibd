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
#include <stdarg.h>
#include <stdlib.h>

#include "scanner.h"

void
parserError (const char *msg, ...)
{
  va_list ap;
  va_start (ap, msg);
  printf (_("Line %d: "), yylineno);
  vprintf (msg, ap);
  printf ("\n");
  va_end (ap);
  exit (1);
}

String *
unescapeString (const char *str)
{
  String s = str;
  char *a = (char *) s ();
  char *b = a;
  a++;
  while (*a)
    {
      if (*a == '\\')
	{
	  switch (*(a + 1))
	    {
	    case '"':
	      *b = '"';
	      a += 2;
	      b++;
	      break;
	    case 'b':
	      *b = '\b';
	      a += 2;
	      b++;
	      break;
	    case '\\':
	      *b = '\\';
	      a += 2;
	      b++;
	      break;
	    case 'f':
	      *b = '\f';
	      a += 2;
	      b++;
	      break;
	    case 'n':
	      *b = '\n';
	      a += 2;
	      b++;
	      break;
	    case 'r':
	      *b = '\r';
	      a += 2;
	      b++;
	      break;
	    case 't':
	      *b = '\t';
	      a += 2;
	      b++;
	      break;
	    case '0'...'7':
	      {
		int no = *(a + 1) - '0';
		a += 2;
		while (('0' <= *a && *a <= '7'))
		  {
		    no = no * 8 + (*a - '0');
		    a++;
		  }
		*b = no & 0xff;
		b++;
	      }
	      break;
	    case 'X':
	    case 'x':
	      {
		int no = 0;
		a += 2;
		while (('0' <= *a && *a <= '9') || ('a' <= *a && *a <= 'f')
		       || ('A' <= *a && *a <= 'F'))
		  {
		    int s;
		    if (('0' <= *a && *a <= '9'))
		      s = *a - '0';
		    if (('A' <= *a && *a <= 'Z'))
		      s = *a - 'A' + 10;
		    if (('a' <= *a && *a <= 'z'))
		      s = *a - 'a' + 10;
		    no = no * 16 + s;
		    a++;
		  }
		*b = no & 0xff;
		b++;
	      }
	      break;
	    default:
	      *b = *a;
	      a++;
	      b++;
	      *b = *a;
	      a++;
	      b++;
	    }
	}
      else if (*a == '"')
	{
	  a++;
	  break;
	}
      else
	{
	  *b = *a;
	  a++;
	  b++;
	}
    }
  *b = 0;
  return new String (s ());
}

extern void yyrestart (FILE * f);

Device *
ReadConfig (const char *file)
{
  FILE *f = fopen (file, "r");
  if (!f)
    die (_("can not open %s"), file);
  yyrestart (f);
  yyparse ();
  fclose (f);
  return parser_dev;
}
