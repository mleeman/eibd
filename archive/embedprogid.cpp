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
#include <libxml/parser.h>
#include "types.h"
#include "common.h"
#include "hex.h"

void
setcontent (xmlNodePtr n, CArray data)
{
  CArray d = encode_hex (data);
  xmlNodeSetContent (n, (const xmlChar *) d.array ());
}

int
main (int ac, char *ag[])
{
  CArray p;
  uchar buf[200];
  int set = 0;

  if (ac != 4)
    die (_("%s input file output"), ag[0]);

  {
    FILE *f = fopen (ag[2], "r");
    if (!f)
      die (_("open of %s failed"), ag[1]);

    while (!feof (f))
      {
	int i = fread (buf, 1, sizeof (buf), f);
	p.setpart (buf, p (), i);
      }
    fclose (f);
  }

  xmlDocPtr f;
  f = xmlParseFile (ag[1]);
  if (!f)
    die (_("can not parse %s"), ag[1]);

  xmlNodePtr n = xmlDocGetRootElement (f);

  if (n->type != XML_ELEMENT_NODE
      || (strcmp ((const char *) n->name, "DeviceConfig")
	  && strcmp ((const char *) n->name, "DeviceDesc")))
    die (_("wrong format"));

  xmlNodePtr cld = n->children;
  while (cld)
    {
      if (cld->type == XML_ELEMENT_NODE)
	{
	  const char *name = (const char *) cld->name;
	  if (!strcmp (name, "ProgramID"))
	    {
	      setcontent (cld, p);
	      set = 1;
	    }
	}
      cld = cld->next;
    }
  if (!set)
    die (_("ProgramID not found"));

  if (xmlSaveFormatFileEnc (ag[3], f, "UTF-8", 1) < 0)
    die (_("write to %s failed"), ag[3]);

  xmlFreeDoc (f);

}
