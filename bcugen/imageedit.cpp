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
#include "classes.h"
#include "xmlreadconfig.h"
#include "addrtab.h"

void
ToTargetFloat (uchar v[4], float f)
{
  memcpy (v, &f, 4);		/* TODO: conversation */
}

void
ImageToDevice (Image & i, Device & d)
{
  int j;
  for (j = 0; j < i.str (); j++)
    {
      switch (i.str[j]->getType ())
	{
	case S_StringParameter:
	  {
	    StringParameter p;
	    STR_StringParameter *l = ((STR_StringParameter *) i.str[j]);
	    p.ID = l->name;
	    p.ID_lineno = 1;
	    d.StringParameters.add (p);
	  }
	  break;
	case S_IntParameter:
	  {
	    IntParameter p;
	    STR_IntParameter *l = ((STR_IntParameter *) i.str[j]);
	    p.ID = l->name;
	    p.ID_lineno = 1;
	    d.IntParameters.add (p);
	  }
	  break;
	case S_FloatParameter:
	  {
	    FloatParameter p;
	    STR_FloatParameter *l = ((STR_FloatParameter *) i.str[j]);
	    p.ID = l->name;
	    p.ID_lineno = 1;
	    d.FloatParameters.add (p);
	  }
	  break;
	case S_ListParameter:
	  {
	    ListParameter p;
	    STR_ListParameter *l = ((STR_ListParameter *) i.str[j]);
	    p.ID = l->name;
	    p.ID_lineno = 1;
	    for (int k = 0; k < l->elements (); k++)
	      {
		Map m;
		m.Value = l->elements[k];
		p.Elements.add (m);
	      }
	    d.ListParameters.add (p);
	  }
	  break;
	case S_GroupObject:
	  {
	    GroupObject p;
	    STR_GroupObject *l = ((STR_GroupObject *) i.str[j]);
	    p.ID = l->name;
	    p.ID_lineno = 1;
	    p.ObjNo = l->no;
	    d.GroupObjects.add (p);
	  }
	  break;
	case S_BCUType:
	  d.BCU = (BCUType) ((STR_BCUType *) i.str[j])->bcutype;
	  break;
	}
    }
}

void
PatchImage (Image & i, Device & d)
{
  int j, k;
  STR_Code *co = (STR_Code *) i.findStream (S_Code);
  uchar *c = (uchar *) co->code.array ();
  for (j = 0; j < i.str (); j++)
    {
      switch (i.str[j]->getType ())
	{
	case S_StringParameter:
	  {
	    STR_StringParameter *l = ((STR_StringParameter *) i.str[j]);
	    for (k = 0; k < d.StringParameters (); k++)
	      if (d.StringParameters[k].ID == l->name)
		break;
	    const StringParameter & p = d.StringParameters[k];
	    if (!p.Value_lineno)
	      die (_("missing parameter value for %s"), p.ID ());
	    if (strlen (p.Value ()) + 1 > l->length)
	      die (_("string value for %s too long"), p.ID ());
	    strcpy ((char *) c + l->addr - 0x100, p.Value ());
	  }
	  break;
	case S_IntParameter:
	  {
	    STR_IntParameter *l = ((STR_IntParameter *) i.str[j]);
	    for (k = 0; k < d.IntParameters (); k++)
	      if (d.IntParameters[k].ID == l->name)
		break;
	    const IntParameter & p = d.IntParameters[k];
	    if (!p.Value_lineno)
	      die (_("missing parameter value for %s"), p.ID ());
	    switch (l->type)
	      {
	      case 1:
	      case -1:
		c[l->addr - 0x100] = p.Value & 0xff;
		break;
	      case 2:
	      case -2:
		c[l->addr + 0 - 0x100] = (p.Value >> 8) & 0xff;
		c[l->addr + 1 - 0x100] = p.Value & 0xff;
		break;
	      case 3:
	      case -3:
		c[l->addr + 0 - 0x100] = (p.Value >> 24) & 0xff;
		c[l->addr + 1 - 0x100] = (p.Value >> 16) & 0xff;
		c[l->addr + 2 - 0x100] = (p.Value >> 8) & 0xff;
		c[l->addr + 3 - 0x100] = p.Value & 0xff;
		break;
	      case 4:
	      case -4:
		c[l->addr + 0 - 0x100] = (p.Value >> 56) & 0xff;
		c[l->addr + 1 - 0x100] = (p.Value >> 48) & 0xff;
		c[l->addr + 2 - 0x100] = (p.Value >> 40) & 0xff;
		c[l->addr + 3 - 0x100] = (p.Value >> 32) & 0xff;
		c[l->addr + 4 - 0x100] = (p.Value >> 24) & 0xff;
		c[l->addr + 5 - 0x100] = (p.Value >> 16) & 0xff;
		c[l->addr + 6 - 0x100] = (p.Value >> 8) & 0xff;
		c[l->addr + 7 - 0x100] = p.Value & 0xff;
		break;
	      default:
		die (_("unknown type %d for parameter %s"), l->type, p.ID ());
	      }
	  }
	  break;
	case S_FloatParameter:
	  {
	    STR_FloatParameter *l = ((STR_FloatParameter *) i.str[j]);
	    for (k = 0; k < d.FloatParameters (); k++)
	      if (d.FloatParameters[k].ID == l->name)
		break;
	    const FloatParameter & p = d.FloatParameters[k];
	    if (!p.Value_lineno)
	      die (_("missing parameter value for %s"), p.ID ());
	    float f = p.Value;
	    uchar v[4];
	    ToTargetFloat (v, f);
	    memcpy (c + l->addr - 0x100, v, 4);
	  }
	  break;
	case S_ListParameter:
	  {
	    STR_ListParameter *l = ((STR_ListParameter *) i.str[j]);
	    for (k = 0; k < d.ListParameters (); k++)
	      if (d.ListParameters[k].ID == l->name)
		break;
	    const ListParameter & p = d.ListParameters[k];
	    if (!p.Value_lineno)
	      die (_("missing parameter value for %s"), p.ID ());
	    int i;
	    for (i = 0; i < l->elements (); i++)
	      if (l->elements[i] == p.Value)
		break;
	    if (i == l->elements ())
	      die (_("unknown element %s for parameter %s"), p.Value (),
		   p.ID ());
	    if (i < 0x100)
	      {
		c[l->addr - 0x100] = i & 0xff;
	      }
	    else
	      {
		c[l->addr + 0 - 0x100] = (i >> 8) & 0xff;
		c[l->addr + 1 - 0x100] = i & 0xff;
	      }
	  }
	  break;
	}
    }
  /*Addresstable */
  int addrtab_start;
  int assoctab_start;
  int groupobj_start;
  if (d.BCU == BCU_bcu12)
    {
      addrtab_start = 0x16;
      assoctab_start = c[0x11];
      groupobj_start = c[0x12];
    }
  else
    {
      STR_BCU2Start *s = (STR_BCU2Start *) i.findStream (S_BCU2Start);
      addrtab_start = s->addrtab_start - 0x100;
      assoctab_start = s->assoctab_start - 0x100;
      groupobj_start = s->groupobj_ptr - 0x100;
    }
  {
    AddrTable t;
    int i;
    int maxs = 0;
    for (i = 0; i < d.GroupObjects (); i++)
      BuildObjAddress (d.GroupObjects[i], d.BCU);

    BuildAddrTable (t, d);

    maxs = t.Addr ();

    if (t.addr () + 1 > c[addrtab_start])
      die (_("need %d addresses, only space for %d addresses"), t.addr () + 1,
	   c[addrtab_start]);
    c[addrtab_start] = t.addr () + 1;
    c[addrtab_start + 1] = (d.PhysicalAddress >> 8) & 0xff;
    c[addrtab_start + 2] = (d.PhysicalAddress) & 0xff;
    for (i = 0; i < t.addr (); i++)
      {
	c[addrtab_start + i * 2 + 3] = (t.addr[i] >> 8) & 0xff;
	c[addrtab_start + i * 2 + 4] = (t.addr[i]) & 0xff;
      }
    if (maxs > c[addrtab_start])
      die (_("need %d associations, only space for %d assocations"), maxs,
	   c[assoctab_start]);
    c[assoctab_start] = maxs;
    for (i = 0; i < maxs; i++)
      {
	c[assoctab_start + i * 2 + 1] = t.Addr[i] + 1;
	c[assoctab_start + i * 2 + 2] = t.ObjNo[i];
      }
    for (i = 0; i < d.GroupObjects (); i++)
      {
	uchar f = GroupObjectFlag (d.GroupObjects[i], d.BCU);
	c[groupobj_start + 2 + 3 * d.GroupObjects[i].ObjNo + 1] = f;
      }
  }
  /*Key handling */
  {
    STR_BCU2Key *k = (STR_BCU2Key *) i.findStream (S_BCU2Key);
    if (!k)
      {
	k = new STR_BCU2Key;
	i.str.add (k);
      }
    if (d.InstallKey_lineno)
      k->installkey = d.InstallKey;
    k->keys.resize (3);
    int i;
    for (i = 0; i < 3; i++)
      k->keys[i] = 0xffffffff;
    for (i = 0; i < d.Keys (); i++)
      {
	if (d.Keys[i].level < 0 || d.Keys[i].level > 2)
	  die (_("unsupported key level %d"), d.Keys[i].level);
	k->keys[d.Keys[i].level] = d.Keys[i].key;
      }
  }
}

int
main (int ac, char *ag[])
{
  CArray p;
  uchar buf[200];
  int dump = 0;
  Device d;

  if (ac != 4)
    die (_("%s image config output"), ag[0]);

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
  if (r != IMG_IMAGE_LOADABLE)
    die (_("%s"), decodeBCULoadResult (r) ());

  ImageToDevice (*i, d);

  xmlReadConfigInformation (d, ag[2]);

  PatchImage (*i, d);

  printf ("%s\n", i->decode ()());

  f = fopen (ag[3], "w");
  if (!f)
    die (_("can not write to %s"), ag[3]);
  p = i->toArray ();
  if (dump)
    printf ("%s", HexDump (p) ());
  fwrite (p.array (), 1, p (), f);
  fclose (f);

}
