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
#include <stdlib.h>
#include <libxml/parser.h>
#include <libxml/xmlschemas.h>
#include <assert.h>
#include "xmlreadconfig.h"
#include "path.h"

#define SCHEMA PKGDATADIR "/xml/configdesc.xsd"

static eibaddr_t
readaddr (const char *addr)
{
  eibaddr_t k;
  int a, b, c;
  if (sscanf (addr, "%d.%d.%d", &a, &b, &c) == 3)
    return ((a & 0x0f) << 12) | ((b & 0x0f) << 8) | ((c & 0xff));
  sscanf (addr, "%hX", &k);
  return k;

}

static eibpaddr_t
readpaddr (const char *key)
{
  eibpaddr_t k;
  sscanf (key, "%hX", &k);
  return k;
}

static eibgaddr_t
readgaddr (const char *key)
{
  eibgaddr_t k;
  int a, b, c;
  if (sscanf (key, "%d/%d/%d", &a, &b, &c) == 3)
    return ((a & 0x1f) << 11) | ((b & 0x07) << 8) | ((c & 0xff));
  if (sscanf (key, "%d/%d", &a, &b) == 2)
    return ((a & 0x1f) << 11) | ((b & 0x7FF));
  sscanf (key, "%hX", &k);
  return k;
}

static eibkey_t
readkey (const char *key)
{
  eibkey_t k;
  sscanf (key, "%lx", &k);
  return k;
}

static bool
readbool (const char *x)
{
  if (!strcmp (x, "true"))
    return 1;
  return 0;
}

static prio_t
readprio (const char *x)
{
  if (!strcmp (x, "system"))
    return PRIO_SYSTEM;
  if (!strcmp (x, "urgent"))
    return PRIO_URGENT;
  if (!strcmp (x, "normal"))
    return PRIO_NORMAL;
  return PRIO_LOW;
}

static const char *
gc (xmlNodePtr n)
{
  const char *c = (const char *) xmlNodeGetContent (n);
  assert (c != 0);
  return c;
}
static const char *
gp (xmlNodePtr n, const char *p)
{
  const char *c = (const char *) xmlGetProp (n, (const xmlChar *) p);
  assert (c != 0);
  return c;
}
static void
f (const char *f)
{
  xmlFree ((char *) f);
}

static void
parseGroupObject (Device & d, xmlNodePtr n)
{
  int i;
  const char *id = gp (n, "id");
  for (i = 0; i < d.GroupObjects (); i++)
    if (d.GroupObjects[i].ID_lineno)
      if (d.GroupObjects[i].ID == id)
	break;
  if (i == d.GroupObjects ())
    die (_("unknown group object"));
  GroupObject & o = d.GroupObjects[i];

  xmlNodePtr cld = n->children;
  while (cld)
    {
      if (cld->type == XML_ELEMENT_NODE)
	{
	  const char *name = (const char *) cld->name;
	  if (!strcmp (name, "Priority"))
	    {
	      const char *v = gc (cld);
	      o.Priority = readprio (v);
	      o.Priority_lineno = 1;
	      f (v);
	    }
	  if (!strcmp (name, "SendAddress"))
	    {
	      const char *v = gc (cld);
	      o.SendAddress = readgaddr (v);
	      o.SendAddress_lineno = 1;
	      f (v);
	    }
	  if (!strcmp (name, "ReadRequestAddress"))
	    {
	      const char *v = gc (cld);
	      o.ReadRequestAddress = readgaddr (v);
	      o.ReadRequestAddress_lineno = 1;
	      f (v);
	    }
	  if (!strcmp (name, "ReceiveAddress"))
	    {
	      const char *v = gc (cld);
	      o.ReceiveAddress.add (readgaddr (v));
	      f (v);
	    }
	  if (!strcmp (name, "ReadAddress"))
	    {
	      const char *v = gc (cld);
	      o.ReadAddress.add (readgaddr (v));
	      f (v);
	    }
	  if (!strcmp (name, "UpdateAddress"))
	    {
	      const char *v = gc (cld);
	      o.UpdateAddress.add (readgaddr (v));
	      f (v);
	    }

	}
      cld = cld->next;
    }
}

static void
parseProperty (Device & d, xmlNodePtr n)
{
  int i, j;
  const char *id = gp (n, "id");
  for (i = 0; i < d.Objects (); i++)
    for (j = 0; j < d.Objects[j].Propertys (); i++)
      if (d.Objects[i].Propertys[j].ID_lineno)
	if (d.Objects[i].Propertys[j].ID == id)
	  goto ok;
  die (_("unknown property"));
ok:
  Property & o = d.Objects[i].Propertys[j];

  xmlNodePtr cld = n->children;
  while (cld)
    {
      if (cld->type == XML_ELEMENT_NODE)
	{
	  const char *name = (const char *) cld->name;
	  if (!strcmp (name, "Disable"))
	    {
	      const char *v = gc (cld);
	      o.Disable = readbool (v);
	      o.Disable_lineno = 1;
	      f (v);
	    }
	  if (!strcmp (name, "ReadOnly"))
	    {
	      const char *v = gc (cld);
	      o.ReadOnly = readbool (v);
	      o.ReadOnly_lineno = 1;
	      f (v);
	    }
	  if (!strcmp (name, "ReadAccess"))
	    {
	      const char *v = gc (cld);
	      o.ReadAccess = atoi (v);
	      o.ReadAccess_lineno = 1;
	      f (v);
	    }
	  if (!strcmp (name, "WriteAccess"))
	    {
	      const char *v = gc (cld);
	      o.WriteAccess = atoi (v);
	      o.WriteAccess_lineno = 1;
	      f (v);
	    }
	}
      cld = cld->next;
    }
}

static void
parsePollingMaster (Device & d, xmlNodePtr n)
{
  int i;
  const char *id = gp (n, "id");
  for (i = 0; i < d.PollingMasters (); i++)
    if (d.PollingMasters[i].ID_lineno)
      if (d.PollingMasters[i].ID == id)
	break;
  if (i == d.PollingMasters ())
    die (_("unknown polling master"));
  PollingMaster & o = d.PollingMasters[i];

  xmlNodePtr cld = n->children;
  while (cld)
    {
      if (cld->type == XML_ELEMENT_NODE)
	{
	  const char *name = (const char *) cld->name;
	  if (!strcmp (name, "PollingAddress"))
	    {
	      const char *v = gc (cld);
	      o.PollingAddress = readpaddr (v);
	      o.PollingAddress_lineno = 1;
	      f (v);
	    }
	  if (!strcmp (name, "PollingCount"))
	    {
	      const char *v = gc (cld);
	      o.PollingCount = atoi (v);
	      o.PollingCount_lineno = 1;
	      f (v);
	    }

	}
      cld = cld->next;
    }
}

static void
parsePollingSlave (Device & d, xmlNodePtr n)
{
  int i;
  const char *id = gp (n, "id");
  for (i = 0; i < d.PollingSlaves (); i++)
    if (d.PollingSlaves[i].ID_lineno)
      if (d.PollingSlaves[i].ID == id)
	break;
  if (i == d.PollingSlaves ())
    die (_("unknown polling slave"));
  PollingSlave & o = d.PollingSlaves[i];

  xmlNodePtr cld = n->children;
  while (cld)
    {
      if (cld->type == XML_ELEMENT_NODE)
	{
	  const char *name = (const char *) cld->name;
	  if (!strcmp (name, "PollingAddress"))
	    {
	      const char *v = gc (cld);
	      o.PollingAddress = readpaddr (v);
	      o.PollingAddress_lineno = 1;
	      f (v);
	    }
	  if (!strcmp (name, "PollingSlot"))
	    {
	      const char *v = gc (cld);
	      o.PollingSlot = atoi (v);
	      o.PollingSlot_lineno = 1;
	      f (v);
	    }
	}
      cld = cld->next;
    }
}

static void
parseListParameter (Device & d, xmlNodePtr n)
{
  int i;
  const char *id = gp (n, "id");
  for (i = 0; i < d.ListParameters (); i++)
    if (d.ListParameters[i].ID_lineno)
      if (d.ListParameters[i].ID == id)
	break;
  if (i == d.ListParameters ())
    die (_("unknown list parameter"));
  ListParameter & o = d.ListParameters[i];

  xmlNodePtr cld = n->children;
  while (cld)
    {
      if (cld->type == XML_ELEMENT_NODE)
	{
	  const char *name = (const char *) cld->name;
	  if (!strcmp (name, "Value"))
	    {
	      const char *v = gc (cld);
	      o.Value = v;
	      o.Value_lineno = 1;
	      f (v);
	    }
	}
      cld = cld->next;
    }
}

static void
parseIntParameter (Device & d, xmlNodePtr n)
{
  int i;
  const char *id = gp (n, "id");
  for (i = 0; i < d.IntParameters (); i++)
    if (d.IntParameters[i].ID_lineno)
      if (d.IntParameters[i].ID == id)
	break;
  if (i == d.IntParameters ())
    die (_("unknown int parameter"));
  IntParameter & o = d.IntParameters[i];

  xmlNodePtr cld = n->children;
  while (cld)
    {
      if (cld->type == XML_ELEMENT_NODE)
	{
	  const char *name = (const char *) cld->name;
	  if (!strcmp (name, "Value"))
	    {
	      const char *v = gc (cld);
	      o.Value = atoi (v);
	      o.Value_lineno = 1;
	      f (v);
	    }
	}
      cld = cld->next;
    }
}

static void
parseFloatParameter (Device & d, xmlNodePtr n)
{
  int i;
  const char *id = gp (n, "id");
  for (i = 0; i < d.FloatParameters (); i++)
    if (d.FloatParameters[i].ID_lineno)
      if (d.FloatParameters[i].ID == id)
	break;
  if (i == d.FloatParameters ())
    die (_("unknown float parameter"));
  FloatParameter & o = d.FloatParameters[i];

  xmlNodePtr cld = n->children;
  while (cld)
    {
      if (cld->type == XML_ELEMENT_NODE)
	{
	  const char *name = (const char *) cld->name;
	  if (!strcmp (name, "Value"))
	    {
	      const char *v = gc (cld);
	      o.Value = atof (v);
	      o.Value_lineno = 1;
	      f (v);
	    }

	}
      cld = cld->next;
    }
}

static void
parseStringParameter (Device & d, xmlNodePtr n)
{
  int i;
  const char *id = gp (n, "id");
  for (i = 0; i < d.StringParameters (); i++)
    if (d.StringParameters[i].ID_lineno)
      if (d.StringParameters[i].ID == id)
	break;
  if (i == d.StringParameters ())
    die (_("unknown string parameter"));
  StringParameter & o = d.StringParameters[i];

  xmlNodePtr cld = n->children;
  while (cld)
    {
      if (cld->type == XML_ELEMENT_NODE)
	{
	  const char *name = (const char *) cld->name;
	  if (!strcmp (name, "Value"))
	    {
	      const char *v = gc (cld);
	      o.Value = v;
	      o.Value_lineno = 1;
	      f (v);
	    }
	}
      cld = cld->next;
    }
}

static void
parseParameter (Device & d, xmlNodePtr n)
{
  xmlNodePtr cld = n->children;
  while (cld)
    {
      if (cld->type == XML_ELEMENT_NODE)
	{
	  const char *name = (const char *) cld->name;
	  if (!strcmp (name, "ListParameter"))
	    parseListParameter (d, cld);
	  if (!strcmp (name, "IntParameter"))
	    parseIntParameter (d, cld);
	  if (!strcmp (name, "FloatParameter"))
	    parseFloatParameter (d, cld);
	  if (!strcmp (name, "StringParameter"))
	    parseStringParameter (d, cld);
	}
      cld = cld->next;
    }
}


static void
parseDeviceDesc (Device & d, xmlNodePtr n)
{
  if (n->type != XML_ELEMENT_NODE
      || strcmp ((const char *) n->name, "DeviceConfig"))
    die (_("wrong format"));
  xmlNodePtr cld = n->children;
  while (cld)
    {
      if (cld->type == XML_ELEMENT_NODE)
	{
	  const char *name = (const char *) cld->name;
	  if (!strcmp (name, "ProgramID"))
	    {
	      const char *pid = gc (cld);
//            if (d.ProgramID != pid)
//              printf (_("ProgramID mismatch\n"));
	      f (pid);
	    }
	  if (!strcmp (name, "PhysicalAddress"))
	    {
	      const char *pid = gc (cld);
	      d.PhysicalAddress = readaddr (pid);
	      d.PhysicalAddress_lineno = 1;
	      f (pid);
	    }
	  if (!strcmp (name, "InstallKey"))
	    {
	      const char *pid = gc (cld);
	      d.InstallKey = readkey (pid);
	      d.InstallKey_lineno = 1;
	      f (pid);
	    }
	  if (!strcmp (name, "Key"))
	    {
	      const char *pid = gc (cld);
	      const char *id = gp (cld, "id");
	      KeyMap m;
	      m.level = atoi (id);
	      m.key = readkey (pid);
	      d.Keys.add (m);
	      f (id);
	      f (pid);
	    }
	  if (!strcmp (name, "GroupObject"))
	    parseGroupObject (d, cld);
	  if (!strcmp (name, "Property"))
	    parseProperty (d, cld);
	  if (!strcmp (name, "PollingMaster"))
	    parsePollingMaster (d, cld);
	  if (!strcmp (name, "PollingSlave"))
	    parsePollingSlave (d, cld);
	  if (!strcmp (name, "Parameter"))
	    parseParameter (d, cld);
	}
      cld = cld->next;
    }
}

void
xmlReadConfigInformation (Device & d, const char *file)
{
  xmlDocPtr f;
  f = xmlParseFile (file);
  if (!f)
    die (_("can not parse %s"), file);

  {
    xmlSchemaParserCtxtPtr cp = xmlSchemaNewParserCtxt (SCHEMA);
    if (!cp)
      die (_("can not load schema %s"), SCHEMA);
    xmlSchemaPtr sp = xmlSchemaParse (cp);
    if (!sp)
      die (_("can not parse schema %s"), SCHEMA);
    xmlSchemaValidCtxtPtr vc = xmlSchemaNewValidCtxt (sp);
    if (!vc)
      die (_("creation of validation context failed"));

    if (xmlSchemaValidateDoc (vc, f))
      die (_("%s does not validate"), file);
    xmlSchemaFreeValidCtxt (vc);
    xmlSchemaFree (sp);
    xmlSchemaFreeParserCtxt (cp);
  }
  xmlNodePtr root = xmlDocGetRootElement (f);
  parseDeviceDesc (d, root);
  xmlFreeDoc (f);
}
