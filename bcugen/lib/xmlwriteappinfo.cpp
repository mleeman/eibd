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

#include "xmlwriteappinfo.h"
#include <libxml/tree.h>

static char buf[4096];

static void
a (xmlNodePtr p, const char *name, const char *val)
{
  xmlNewProp (p, (const xmlChar *) name, (const xmlChar *) val);
}

xmlNodePtr
nn (const char *name)
{
  return xmlNewNode (0, (const xmlChar *) name);
}

xmlNodePtr
nc (xmlNodePtr parent, const char *name, const char *val)
{
  return xmlNewTextChild (parent, 0, (const xmlChar *) name,
			  (const xmlChar *) val);
}

static xmlNodePtr
GenDeviceDesc (const Device & d)
{
  xmlNodePtr n = nn ("Description");
  sprintf (buf, "%04X", d.MaskVersion);
  nc (n, "MaskVersion", buf);
  nc (n, "Title", d.Title ());
  if (d.AddInfo ())
    nc (n, "AddInfo", d.AddInfo ());
  if (d.OrderNo ())
    nc (n, "OrderNo", d.OrderNo ());
  if (d.Manufacturer ())
    nc (n, "Manufacturer", d.Manufacturer ());
  if (d.Category ())
    nc (n, "Category", d.Category ());
  if (d.Author ())
    nc (n, "Author", d.Author ());
  if (d.Copyright ())
    nc (n, "Copyright", d.Copyright ());
  return n;
}

static xmlNodePtr
GenInterface (const Interface & d)
{
  if (!d.ID_lineno)
    return 0;
  xmlNodePtr p;
  int count = 0;
  xmlNodePtr n = nn ("Interface");
  a (n, "id", d.ID ());
  sprintf (buf, "%0.3f", d.DPType);
  nc (n, "DPType", buf);
  if (d.Abbreviation ())
    nc (n, "Abbreviation", d.Abbreviation ());
  if (d.Title ())
    nc (n, "Title", d.Title ());
  if (d.AddInfo ())
    nc (n, "AddInfo", d.AddInfo ());
  if (d.GroupTitle ())
    nc (n, "GroupTitle", d.GroupTitle ());
  if (d.InvisibleIf_lineno)
    nc (n, "InvisibleIf", printExpression (d.InvisibleIf) ());

  for (int i = 0; i < d.References (); i++)
    {
      p = nn ("Reference");
      a (p, "idref", d.References[i] ());
      xmlAddChild (n, p);
      count++;
    }
  if (!count)
    {
      xmlFreeNode (n);
      n = 0;
    }
  return n;
}

static xmlNodePtr
GenFunctionalBlock (const FunctionalBlock & d)
{
  if (!d.ID_lineno)
    return 0;
  int count = 0;
  xmlNodePtr p;
  xmlNodePtr n = nn ("FunctionalBlock");
  a (n, "id", d.ID ());
  sprintf (buf, "%d", d.ProfileID);
  nc (n, "ProfileID", buf);
  nc (n, "Title", d.Title ());
  if (d.AddInfo ())
    nc (n, "AddInfo", d.AddInfo ());
  for (int i = 0; i < d.Interfaces (); i++)
    {
      p = GenInterface (d.Interfaces[i]);
      if (p)
	xmlAddChild (n, p);
      count++;
    }
  if (!count)
    {
      xmlFreeNode (n);
      n = 0;
    }
  return n;
}

static xmlNodePtr
GenGroupObject (const GroupObject & d)
{
  if (!d.ID_lineno)
    return 0;
  xmlNodePtr n = nn ("GroupObject");
  a (n, "id", d.ID ());
  nc (n, "Title", d.Title ());
  if (d.AddInfo ())
    nc (n, "AddInfo", d.AddInfo ());
  sprintf (buf, "%d", d.Type);
  nc (n, "GroupType", buf);
  nc (n, "Sending", d.Sending ? "true" : "false");
  nc (n, "Receiving", d.Receiving ? "true" : "false");
  nc (n, "Reading", d.Reading ? "true" : "false");
  nc (n, "StateBased", d.StateBased ? "true" : "false");
  return n;
}

static xmlNodePtr
GenProperty (const Property & d, itype objindex)
{
  if (!d.ID_lineno)
    return 0;
  xmlNodePtr n = nn ("Property");
  a (n, "id", d.ID ());
  nc (n, "Title", d.Title ());
  if (d.AddInfo ())
    nc (n, "AddInfo", d.AddInfo ());
  sprintf (buf, "%d", d.Type);
  nc (n, "PropertyType", buf);

  sprintf (buf, "%d", objindex);
  nc (n, "ObjectIndex", buf);
  sprintf (buf, "%d", d.PropertyID);
  nc (n, "PropertyId", buf);

  nc (n, "Writeable", d.Writeable ? "true" : "false");
  sprintf (buf, "%d", d.MaxArrayLength);
  nc (n, "MaxArrayLength", buf);

  return n;
}

static xmlNodePtr
GenPollingMaster (const PollingMaster & d)
{
  if (!d.ID_lineno)
    return 0;
  xmlNodePtr n = nn ("PollingMaster");
  a (n, "id", d.ID ());
  nc (n, "Title", d.Title ());
  if (d.AddInfo ())
    nc (n, "AddInfo", d.AddInfo ());

  return n;
}

static xmlNodePtr
GenPollingSlave (const PollingSlave & d)
{
  if (!d.ID_lineno)
    return 0;
  xmlNodePtr n = nn ("PollingSlave");
  a (n, "id", d.ID ());
  nc (n, "Title", d.Title ());
  if (d.AddInfo ())
    nc (n, "AddInfo", d.AddInfo ());

  return n;
}

static xmlNodePtr
GenListParameter (const ListParameter & d)
{
  xmlNodePtr p;
  if (!d.ID ())
    return 0;
  xmlNodePtr n = nn ("ListParameter");
  a (n, "id", d.ID ());
  nc (n, "Title", d.Title ());
  if (d.AddInfo ())
    nc (n, "AddInfo", d.AddInfo ());

  p = nn ("ListDefault");
  a (p, "idref", d.ListDefault ());
  xmlAddChild (n, p);
  for (int i = 0; i < d.ListElements (); i++)
    {
      p = nc (n, "ListElement", d.ListElements[i].Value ());
      a (p, "id", d.ListElements[i].Name ());
    }
  if (d.Unit ())
    nc (n, "Unit", d.Unit ());
  return n;
}

static xmlNodePtr
GenIntParameter (const IntParameter & d)
{
  if (!d.ID_lineno)
    return 0;
  xmlNodePtr n = nn ("IntParameter");
  a (n, "id", d.ID ());
  nc (n, "Title", d.Title ());
  if (d.AddInfo ())
    nc (n, "AddInfo", d.AddInfo ());
  sprintf (buf, "%d", d.MinValue);
  nc (n, "MinValue", buf);
  sprintf (buf, "%d", d.MaxValue);
  nc (n, "MaxValue", buf);
  sprintf (buf, "%d", d.Default);
  nc (n, "Default", buf);
  if (d.Unit ())
    nc (n, "Unit", d.Unit ());
  if (d.Precision_lineno)
    {
      sprintf (buf, "%d", d.Precision);
      nc (n, "Precision", buf);
    }
  if (d.Increment_lineno)
    {
      sprintf (buf, "%d", d.Increment);
      nc (n, "Increment", buf);
    }
  return n;
}

static xmlNodePtr
GenFloatParameter (const FloatParameter & d)
{
  if (!d.ID_lineno)
    return 0;
  xmlNodePtr n = nn ("FloatParameter");
  a (n, "id", d.ID ());
  nc (n, "Title", d.Title ());
  if (d.AddInfo ())
    nc (n, "AddInfo", d.AddInfo ());
  sprintf (buf, "%f", d.MinValue);
  nc (n, "MinValue", buf);
  sprintf (buf, "%f", d.MaxValue);
  nc (n, "MaxValue", buf);
  sprintf (buf, "%f", d.Default);
  nc (n, "Default", buf);
  if (d.Unit ())
    nc (n, "Unit", d.Unit ());
  if (d.Precision_lineno)
    {
      sprintf (buf, "%f", d.Precision);
      nc (n, "Precision", buf);
    }
  if (d.Increment_lineno)
    {
      sprintf (buf, "%f", d.Increment);
      nc (n, "Increment", buf);
    }

  return n;
}

static xmlNodePtr
GenStringParameter (const StringParameter & d)
{
  if (!d.ID_lineno)
    return 0;
  xmlNodePtr n = nn ("StringParameter");
  a (n, "id", d.ID ());
  nc (n, "Title", d.Title ());
  if (d.AddInfo ())
    nc (n, "AddInfo", d.AddInfo ());

  nc (n, "Default", d.Default ());
  if (d.RegExp ())
    nc (n, "RegExp", d.RegExp ());
  sprintf (buf, "%d", d.MaxLength);
  nc (n, "MaxLength", buf);
  if (d.Unit ())
    nc (n, "Unit", d.Unit ());

  return n;
}

static xmlNodePtr
GenParameters (const Device & d)
{
  int i;
  int cnt = 0;
  xmlNodePtr p;
  xmlNodePtr n = nn ("Parameter");
  for (i = 0; i < d.ListParameters (); i++)
    {
      p = GenListParameter (d.ListParameters[i]);
      if (p)
	xmlAddChild (n, p), cnt++;
    }
  for (i = 0; i < d.IntParameters (); i++)
    {
      p = GenIntParameter (d.IntParameters[i]);
      if (p)
	xmlAddChild (n, p), cnt++;
    }
  for (i = 0; i < d.FloatParameters (); i++)
    {
      p = GenFloatParameter (d.FloatParameters[i]);
      if (p)
	xmlAddChild (n, p), cnt++;
    }
  for (i = 0; i < d.StringParameters (); i++)
    {
      p = GenStringParameter (d.StringParameters[i]);
      if (p)
	xmlAddChild (n, p), cnt++;
    }
  if (!cnt)
    {
      xmlFreeNode (n);
      n = 0;
    }
  return n;
}

void
GenChild (xmlNodePtr n, const Device & d)
{
  xmlNodePtr p;
  int i, j;

  for (i = 0, j = 0; i < d.FunctionalBlocks (); i++)
    {
      p = GenFunctionalBlock (d.FunctionalBlocks[i]);
      if (p)
	xmlAddChild (n, p), j++;
    }
  if (!j)
    die (_("no functional block with enabled interfaces"));
  for (i = 0; i < d.GroupObjects (); i++)
    {
      p = GenGroupObject (d.GroupObjects[i]);
      if (p)
	xmlAddChild (n, p);
    }
  for (i = 0; i < d.Objects (); i++)
    {
      if (!d.Objects[i].ObjectIndex)
	continue;
      for (j = 0; j < d.Objects[i].Propertys (); j++)
	{
	  p =
	    GenProperty (d.Objects[i].Propertys[j], d.Objects[i].ObjectIndex);
	  if (p)
	    xmlAddChild (n, p);
	}
    }
  for (i = 0; i < d.PollingMasters (); i++)
    {
      p = GenPollingMaster (d.PollingMasters[i]);
      if (p)
	xmlAddChild (n, p);
    }
  for (i = 0; i < d.PollingSlaves (); i++)
    {
      p = GenPollingSlave (d.PollingSlaves[i]);
      if (p)
	xmlAddChild (n, p);
    }

  p = GenParameters (d);
  if (p)
    xmlAddChild (n, p);
}

void
WriteAppInfo (const Device * d, const char *file)
{
  xmlDocPtr doc = 0;
  xmlNodePtr root = 0;

  if (!d)
    die (_("no device defined"));
  LIBXML_TEST_VERSION;

  doc = xmlNewDoc ((const xmlChar *) "1.0");
  xmlCreateIntSubset (doc, (const xmlChar *) "DeviceDesc", NULL,
		      (const xmlChar *)
		      "http://www.auto.tuwien.ac.at/~mkoegler/eib/xml/appinfo.dtd");
  root = xmlNewNode (NULL, (const xmlChar *) "DeviceDesc");
  xmlDocSetRootElement (doc, root);

  a (root, "xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
  a (root, "xsi:schemaLocation",
     "http://www.auto.tuwien.ac.at/~mkoegler/eib/appinfo.xsd");
  a (root, "xmlns",
     "http://www.auto.tuwien.ac.at/~mkoegler/eib/xml/appinfo.xsd");
  a (root, "version", "0.0.0");

  nc (root, "ProgramID", d->ProgramID ());
  xmlAddChild (root, GenDeviceDesc (*d));


  GenChild (root, *d);

  if (xmlSaveFormatFileEnc (file, doc, "UTF-8", 1) < 0)
    die (_("write to %s failed"), file);

  xmlFreeDoc (doc);
}
