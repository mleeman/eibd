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

#include <stdlib.h>
#include "check.h"
#include "regexp.h"
#include "symboltab.h"

bool
UsePEI (const Device & d)
{
  return d.on_pei_init () || d.on_pei_message ()
    || d.on_pei_cycle ()
    || d.on_pei_user ()
    || d.on_pei_rc_even ()
    || d.on_pei_rc_odd ()
    || d.on_pei_tc ()
    || d.on_pei_tdre ()
    || d.on_pei_sci_idle ()
    || d.on_pei_spif ()
    || d.on_pei_oca ()
    || d.on_pei_ocb () || d.on_pei_ica () || d.on_pei_icb ();
}


int
UsedbyInterface (const Device & d, const String & name)
{
  int i, j, k;
  for (i = 0; i < d.FunctionalBlocks (); i++)
    for (j = 0; j < d.FunctionalBlocks[i].Interfaces (); j++)
      for (k = 0; k < d.FunctionalBlocks[i].Interfaces[j].Reference (); k++)
	if (d.FunctionalBlocks[i].Interfaces[j].Reference[k] == name)
	  return 1;
  return 0;
}

int
ObjectName (const Device & d, const String & Name)
{
  int i, j;
  for (i = 0; i < d.StringParameters (); i++)
    if (d.StringParameters[i].Name == Name)
      return 1;
  for (i = 0; i < d.FloatParameters (); i++)
    if (d.FloatParameters[i].Name == Name)
      return 1;
  for (i = 0; i < d.IntParameters (); i++)
    if (d.IntParameters[i].Name == Name)
      return 1;
  for (i = 0; i < d.ListParameters (); i++)
    if (d.ListParameters[i].Name == Name)
      return 1;

  for (i = 0; i < d.PollingMasters (); i++)
    if (d.PollingMasters[i].Name == Name)
      return 1;
  for (i = 0; i < d.PollingSlaves (); i++)
    if (d.PollingSlaves[i].Name == Name)
      return 1;
  for (i = 0; i < d.Objects (); i++)
    for (j = 0; j < d.Objects[i].Propertys (); j++)
      if (d.Objects[i].Propertys[j].Name == Name)
	return 1;
  for (i = 0; i < d.GroupObjects (); i++)
    if (d.GroupObjects[i].Name == Name)
      return 1;

  return 0;
}

void
undefined (const char *object, const char *value, int lineno)
{
  die (_("line %d: missing attribute %s of %s"), lineno, value, object);
}

void
CheckStringParameter (Device & d, StringParameter & o)
{
  if (!o.Name ())
    undefined ("StringParameter", "Name", o.lineno);
  if (!o.MaxLength_lineno)
    undefined ("StringParameter", "MaxLength", o.lineno);
  if (o.MaxLength < 0)
    die (_("line %d: negative string len"), o.MaxLength_lineno);
  if (o.RegExp ())
    if (!checkRegExp (o.RegExp ()))
      die (_("line %d: invalid regular expression"), o.RegExp_lineno);
#ifdef CHECK1
  if (!o.Title ())
    undefined ("StringParameter", "Title", o.lineno);
  if (!o.Default ())
    undefined ("StringParameter", "Default", o.lineno);
  if (strlen (o.Default ()) >= o.MaxLength)
    die (_("line %d: default value too long"), o.Default_lineno);
  if (o.RegExp ())
    if (!validateString (o.RegExp (), o.Default ()))
      die (_("line %d: Default does not match regular expression"),
	   o.Default_lineno);
  o.ID = NewSymbol (o.Name, o.lineno);
  if (!UsedbyInterface (d, o.Name))
    {
      o.ID = 0;
      o.Value = o.Default;
      o.Value_lineno = o.Default_lineno;
    }
  else
    o.ID_lineno = o.lineno;
#endif
#ifdef CHECK2
  if (!o.Value ())
    die (_("line %d: No value defined"), o.lineno);
  if (strlen (o.Value ()) >= o.MaxLength)
    die (_("line %d: value too long"), o.lineno);
  if (o.RegExp ())
    if (!validateString (o.RegExp (), o.Value ()))
      die (_("line %d: value does not match regular expression"), o.lineno);
#endif

}

void
CheckFloatParameter (Device & d, FloatParameter & o)
{
  if (!o.Name ())
    undefined ("FloatParameter", "Name", o.lineno);
  if (!o.MinValue_lineno)
    undefined ("FloatParameter", "MinValue", o.lineno);
  if (!o.MaxValue_lineno)
    undefined ("FloatParameter", "MaxValue", o.lineno);
  if (o.MinValue > o.MaxValue)
    die (_("line %d: MinValue > MaxValue"), o.MaxValue_lineno);

#ifdef CHECK1
  if (!o.Title ())
    undefined ("FloatParameter", "Title", o.lineno);
  if (!o.Default_lineno)
    undefined ("FloatParameter", "Default", o.lineno);
  if (o.Default < o.MinValue)
    die (_("line %d: Default< MinValue"), o.Default_lineno);
  if (o.Default > o.MaxValue)
    die (_("line %d: Default> MaxValue"), o.Default_lineno);

  o.ID = NewSymbol (o.Name, o.lineno);
  if (!UsedbyInterface (d, o.Name))
    {
      o.ID = 0;
      o.Value = o.Default;
      o.Value_lineno = o.Default_lineno;
    }
  else
    o.ID_lineno = o.lineno;
#endif
#ifdef CHECK2
  if (!o.Value_lineno)
    die (_("line %d: No value defined"), o.lineno);
  if (o.Value < o.MinValue)
    die (_("line %d: Value< MinValue"), o.lineno);
  if (o.Value > o.MaxValue)
    die (_("line %d: Value> MaxValue"), o.lineno);
#endif

}

void
CheckIntParameter (Device & d, IntParameter & o)
{
  if (!o.Name ())
    undefined ("IntParameter", "Name", o.lineno);
  if (!o.MinValue_lineno)
    undefined ("IntParameter", "MinValue", o.lineno);
  if (!o.MaxValue_lineno)
    undefined ("IntParameter", "MaxValue", o.lineno);
  if (o.MinValue > o.MaxValue)
    die (_("line %d: MinValue > MaxValue"), o.MaxValue_lineno);

#ifdef CHECK1
  if (!o.Title ())
    undefined ("IntParameter", "Title", o.lineno);
  if (!o.Default_lineno)
    undefined ("IntParameter", "Default", o.lineno);
  if (o.Default < o.MinValue)
    die (_("line %d: Default< MinValue"), o.Default_lineno);
  if (o.Default > o.MaxValue)
    die (_("line %d: Default> MaxValue"), o.Default_lineno);

  o.ID = NewSymbol (o.Name, o.lineno);
  if (!UsedbyInterface (d, o.Name))
    {
      o.ID = 0;
      o.Value = o.Default;
      o.Value_lineno = o.Default_lineno;
    }
  else
    o.ID_lineno = o.lineno;
#endif
#ifdef CHECK2
  if (!o.Value_lineno)
    die (_("line %d: No value defined"), o.lineno);
  if (o.Value < o.MinValue)
    die (_("line %d: Value< MinValue"), o.lineno);
  if (o.Value > o.MaxValue)
    die (_("line %d: Value> MaxValue"), o.lineno);
#endif

  if (o.MinValue < 0)
    {
      int i = abs (o.MinValue);
      int j = abs (o.MaxValue);
      if (i < j)
	j = i;
      if (i <= 127)
	o.SIZE = -1;
      else if (i <= 32767)
	o.SIZE = -2;
      else if (i <= 2147483647)
	o.SIZE = -3;
      else
	o.SIZE = -4;
    }
  else
    {
      int i = abs (o.MinValue);
      int j = abs (o.MaxValue);
      if (i < j)
	j = i;
      if (i <= 255)
	o.SIZE = 1;
      else if (i <= 65535)
	o.SIZE = 2;
      else if (i <= 4294967295U)
	o.SIZE = 3;
      else
	o.SIZE = 4;
    }
}

void
CheckListParameter (Device & d, ListParameter & o)
{
  int i, df = -1, vl = -1;
  if (!o.Name ())
    undefined ("ListParameter", "Name", o.lineno);

  if (!o.Elements_lineno)
    undefined ("ListParameter", "Elements", o.lineno);
  if (!o.Elements ())
    die (_("line %d: no enumeration values"), o.Elements_lineno);

#ifdef CHECK1
  if (!o.Title ())
    undefined ("ListParameter", "Title", o.lineno);
  if (!o.Default ())
    undefined ("ListParameter", "Default", o.lineno);

  o.ListElements.resize (o.Elements ());
  for (i = 0; i < o.Elements (); i++)
    {
      o.ListElements[i].Name =
	NewSymbol (o.Elements[i].Name, o.Elements_lineno);
      o.ListElements[i].Value = o.Elements[i].Value;
      if (o.Elements[i].Name == o.Default)
	df = i;
      if (o.Value_lineno && o.Elements[i].Name == o.Value)
	vl = i;
      o.Elements[i].Value = o.ListElements[i].Name;
    }
  if (df == -1)
    die (_("line %d: unknown default value"), o.Default_lineno);

  o.ListDefault = o.Elements[df].Value;

  if (o.Value_lineno && vl == -1)
    die (_("line %d: unknown value"), o.Value_lineno);

  if (o.Value_lineno)
    o.Value = o.Elements[vl].Value;

  NewSymbol (o.Name + "_t", o.lineno);
  o.ID = NewSymbol (o.Name, o.lineno);
  if (!UsedbyInterface (d, o.Name))
    {
      o.ID = 0;
      o.Value = o.Elements[df].Value;
      o.Value_lineno = o.Default_lineno;
    }
  else
    o.ID_lineno = o.lineno;


#endif
#ifdef CHECK2
  if (!o.Value ())
    undefined ("ListParameter", "Value", o.lineno);
  for (i = 0; i < o.Elements (); i++)
    {
      if (o.Elements[i].Value == o.Value)
	df = i;
    }

  if (df == -1)
    die (_("line %d: unknown default value"), o.Default_lineno);

#endif

  o.def = df;
}

void
CheckPollingMaster (Device & d, PollingMaster & o)
{

  if (!o.Name ())
    undefined ("PollingMaster", "Name", o.lineno);

#ifdef CHECK1
  if (!o.Title ())
    undefined ("PollingMaster", "Title", o.lineno);

  o.ID = NewSymbol (o.Name, o.lineno);
  if (!UsedbyInterface (d, o.Name))
    {
      o.ID = 0;
    }
  else
    o.ID_lineno = o.lineno;
#endif
#ifdef CHECK2
  if (!o.PollingAddress_lineno && o.PollingCount_lineno)
    die (_("line %d: missing PollingAddress"), o.lineno);
  if (o.PollingAddress_lineno && !o.PollingCount_lineno)
    die (_("line %d: missing PollingCount"), o.lineno);
  if (o.PollingAddress_lineno && o.PollingCount_lineno)
    {
      if (o.PollingAddress & (~0xffff))
	die (_("line %d: wrong polling address %04X"), o.lineno,
	     o.PollingAddress);
      if (o.PollingCount < 0)
	die (_("line %d: negative polling count"), o.lineno);
      if (o.PollingCount > 15)
	die (_("line %d: polling count>15"), o.lineno);
    }
#endif

}
void
CheckPollingSlave (Device & d, PollingSlave & o)
{
  if (!o.Name ())
    undefined ("PollingSlave", "Name", o.lineno);

#ifdef CHECK1
  if (!o.Title ())
    undefined ("PollingSlave", "Title", o.lineno);

  o.ID = NewSymbol (o.Name, o.lineno);
  if (!UsedbyInterface (d, o.Name))
    {
      o.ID = 0;
    }
  else
    o.ID_lineno = o.lineno;
#endif
#ifdef CHECK2
  if (!o.PollingAddress_lineno && o.PollingSlot_lineno)
    die (_("line %d: missing PollingAddress"), o.lineno);
  if (o.PollingAddress_lineno && !o.PollingSlot_lineno)
    die (_("line %d: missing PollingSlot"), o.lineno);
  if (o.PollingAddress_lineno && o.PollingSlot_lineno)
    {
      if (o.PollingAddress & (~0xffff))
	die (_("line %d: wrong polling address %04X"), o.lineno,
	     o.PollingAddress);
      if (o.PollingSlot < 0)
	die (_("line %d: negative polling slot"), o.lineno);
      if (o.PollingSlot > 15)
	die (_("line %d: polling slot>15"), o.lineno);
    }
#endif
}
void
CheckProperty (Device & d, Property & o, Object & o1)
{
  if (!o.Name ())
    undefined ("Property", "Name", o.lineno);

  if (!o.MaxArrayLength_lineno)
    {
      o.MaxArrayLength = 1;
      o.MaxArrayLength_lineno = o.lineno;
    }
  if (o.MaxArrayLength <= 0)
    die (_("line %d: negative array size"), o.lineno);

  if (o.MaxArrayLength > 0xff)
    die (_("line %d: maximum array size to big"), o.lineno);

  if (!o.PropertyID_lineno)
    undefined ("Property", "PropertyID", o.lineno);

  if (!o.Type_lineno)
    undefined ("Property", "Type", o.lineno);

  if (o.PropertyID & (~0xffff) || o.PropertyID == 0)
    die (_("line %d: wrong Property ID %d"), o.lineno, o.PropertyID);

  if (o.handler ())
    NewSymbol (o.handler, o.handler_lineno);

  if (!o.Writeable_lineno)
    {
      o.Writeable_lineno = o.lineno;
      o.Writeable = 1;
    }

  if (!o.eeprom_lineno)
    {
      o.eeprom_lineno = o.lineno;
      o.eeprom = 0;
    }

#ifdef CHECK1
  if (!o.Title ())
    undefined ("Property", "Title", o.lineno);

  o.ID = NewSymbol (o.Name, o.lineno);
  if (!UsedbyInterface (d, o.Name))
    {
      o.ID = 0;
      o.Disable = 1;
      o.Disable_lineno = o.lineno;
      o.ReadOnly = !o.Writeable;
      o.ReadOnly_lineno = o.lineno;
    }
  else
    o.ID_lineno = o.lineno;
#endif
#ifdef CHECK2

  if (!o.WriteAccess_lineno)
    {
      o.WriteAccess_lineno = o.lineno;
      o.WriteAccess = 3;
    }
  if (!o.ReadAccess_lineno)
    {
      o.ReadAccess_lineno = o.lineno;
      o.ReadAccess = 3;
    }
  if (o.ReadAccess < 0 || o.ReadAccess > 3)
    die (_("line %d: invalid access level"), o.ReadAccess_lineno);

  if (o.WriteAccess < 0 || o.WriteAccess > 3)
    die (_("line %d: invalid access level"), o.WriteAccess_lineno);

#endif

  if (!o.Disable_lineno)
    {
      o.Disable_lineno = o.lineno;
      o.Disable = 0;
    }

  if (!o.ReadOnly_lineno)
    {
      o.ReadOnly_lineno = o.lineno;
      o.ReadOnly = !o.Writeable;
    }
}

void
CheckObject (Device & d, Object & o, int &no)
{
  int i, j;
  int ra, wa;
  int PropCount;

  if (!o.Name ())
    undefined ("Object", "Name", o.lineno);

#ifdef CHECK1
  o.ObjectIndex = no;
  o.ObjectIndex_lineno = o.lineno;
  no++;

  NewSymbol (o.Name, o.lineno);
#endif
#ifdef CHECK2

#endif

  if (!o.ObjectType_lineno)
    undefined ("Object", "ObjectType", o.lineno);

  if (o.ObjectType & (~0xffff))
    die (_("line %d: wrong object type %04X"), o.lineno, o.ObjectType);

  for (i = 0; i < o.Propertys (); i++)
    CheckProperty (d, o.Propertys[i], o);

  for (i = 0; i < o.Propertys (); i++)
    for (j = i + 1; j < o.Propertys (); j++)
      if (o.Propertys[i].PropertyID == o.Propertys[j].PropertyID)
	die (_("line %d: duplicate property ID with %s"),
	     o.Propertys[i].lineno, o.Propertys[j].Name ());
#ifdef CHECK1
  o.PropCount = o.Propertys ();
  o.RAccess = 3;
  o.WAccess = 3;
#endif
#ifdef CHECK2
  ra = 4;
  wa = 4;
  PropCount = 0;
  for (i = 0; i < o.Propertys (); i++)
    {
      Property & p = o.Propertys[i];
      if (p.Disable)
	continue;
      PropCount++;
      if (!p.ReadOnly)
	{
	  if (p.WriteAccess < wa)
	    {
	      if (wa != 4)
		warn (_
		      ("line %d: inconsistent access settings for property %s"),
		      o.lineno, p.Name ());
	      wa = p.WriteAccess;
	    }
	  else if (p.WriteAccess != wa && wa != 4)
	    warn (_("line %d: inconsistent access settings for property %s"),
		  o.lineno, p.Name ());
	}
      if (p.ReadAccess < ra)
	{
	  if (ra != 4)
	    warn (_("line %d: inconsistent access settings for property %s"),
		  o.lineno, p.Name ());
	  ra = p.ReadAccess;
	}
      else if (p.ReadAccess != ra && ra != 4)
	warn (_("line %d: inconsistent access settings for property %s"),
	      o.lineno, p.Name ());

    }
  if (ra == 4)
    ra = 3;
  if (wa == 4)
    wa = 3;
  o.RAccess = ra;
  o.WAccess = wa;
  o.PropCount = PropCount;
#endif
  if (o.PropCount > 255)
    die (_("line %d: too many properties"), o.lineno);
}

void
CheckGroupObject (Device & d, GroupObject & o)
{
  if (!o.Name ())
    undefined ("GroupObject", "Name", o.lineno);

  if (!o.Type_lineno)
    undefined ("GroupObject", "Type", o.lineno);

#ifdef CHECK1
  if (!o.Title ())
    undefined ("GroupObject", "Title", o.lineno);

  if (!o.StateBased_lineno)
    undefined ("GroupObject", "StateBased", o.lineno);

  o.ID = NewSymbol (o.Name, o.lineno);
  NewSymbol (o.Name + "_no", o.lineno);
  if (!UsedbyInterface (d, o.Name))
    {
      o.ID = 0;
    }
  else
    o.ID_lineno = o.lineno;

  if (o.on_update ())
    NewSymbol (o.on_update, o.on_update_lineno);

  if (o.on_update () && !o.Receiving_lineno)
    {
      o.Receiving = 1;
      o.Receiving_lineno = o.lineno;
    }

#endif
#ifdef CHECK2

  if (!o.Priority_lineno)
    {
      o.Priority_lineno = o.lineno;
      o.Priority = PRIO_LOW;
    }

#endif
  if (!o.Sending_lineno)
    {
      o.Sending = 0;
      o.Sending_lineno = o.lineno;
    }
  if (!o.Reading_lineno)
    {
      o.Reading = 0;
      o.Reading_lineno = o.lineno;
    }
  if (!o.Receiving_lineno)
    {
      o.Receiving = 0;
      o.Receiving_lineno = o.lineno;
    }
  if (!o.eeprom_lineno)
    {
      o.eeprom_lineno = 0;
      o.eeprom = 0;
    }
#ifdef CHECK1
  if (o.Sending)
    NewSymbol (o.Name + "_transmit", o.lineno);

  if (o.Reading)
    NewSymbol (o.Name + "_readrequest", o.lineno);

  if (o.Reading && o.Sending)
    NewSymbol (o.Name + "_clear", o.lineno);
#endif
#ifdef CHECK2
  if (!o.Sending && o.SendAddress_lineno)
    die (_("line %d: can not send on this group object"), o.lineno);

  if (!o.Reading && o.ReadRequestAddress_lineno)
    die (_("line %d: can not read on this group object"), o.lineno);

  if (!o.Receiving && o.ReceiveAddress ())
    die (_("line %d: can not receive on this group object"), o.lineno);

#endif
}
void CheckExpressionBool (Expr * s, int l, const Device & d);

void
CheckInterface (Device & d, Interface & o)
{

#ifdef CHECK1

  if (!o.Reference_lineno)
    undefined ("Interface", "Reference", o.lineno);

  if (!o.Reference ())
    die (_("line %d: no references"), o.Reference_lineno);

  o.References.resize (o.Reference ());
  for (int i = 0; i < o.Reference (); i++)
    {
      Symbol s = FindSymbol (o.Reference[i], o.References_lineno);
      o.References[i] = s.Id;
      if (!ObjectName (d, o.Reference[i]))
	die (_("line %d: %s referes to wrong object"), o.References_lineno,
	     o.Reference[i] ());
    }

  o.ID = NewSymbolAn (o.lineno);
  o.ID_lineno = o.lineno;

  if (!o.Abbreviation ())
    undefined ("Interface", "Abbreviation", o.lineno);

  if (!o.DPType_lineno)
    undefined ("Interface", "DPType", o.lineno);

  if (o.DPType < 0)
    die (_("line %d: invalid DPType"), o.DPType_lineno);

  if (o.InvisibleIf_lineno)
    CheckExpressionBool (o.InvisibleIf, o.InvisibleIf_lineno, d);

#endif
#ifdef CHECK2

#endif

}

void
CheckFunctionalBlock (Device & d, FunctionalBlock & o)
{
  int i;

#ifdef CHECK1
  if (!o.Title ())
    undefined ("FunctionalBlock", "Title", o.lineno);

  o.ID = NewSymbolAn (o.lineno);
  o.ID_lineno = o.lineno;

  if (!o.ProfileID_lineno)
    undefined ("FunctionalBlock", "ProfileID", o.lineno);

  if (o.ProfileID <= 0)
    die (_("line %d: invalid ProfileID"), o.ProfileID_lineno);

#endif
#ifdef CHECK2

#endif

  for (i = 0; i < o.Interfaces (); i++)
    CheckInterface (d, o.Interfaces[i]);

}

void
CheckExpressionList (Expr * s, int l, const Device & d)
{
  int i, j;
  if (!s || s->Type != Expr::E_IN)
    die (_("line %d: no list expression"), l);
  for (i = 0; i < d.ListParameters (); i++)
    if (d.ListParameters[i].Name == s->s)
      break;
  if (i == d.ListParameters ())
    die (_("line %d: undefined list parameter %s"), l, s->s ());
  const ListParameter & o = d.ListParameters[i];
  for (i = 0; i < s->id (); i++)
    {
      for (j = 0; j < o.Elements (); j++)
	if (o.Elements[j].Name == s->id[i])
	  break;
      if (j == o.Elements ())
	die (_("line %d: undefined list element %s"), l, s->id[i] ());
      s->id[i] = o.Elements[j].Value;
    }
  s->s = o.ID;
  if (!o.ID_lineno)
    {
      int found = 0;
      for (i = 0; i < s->id (); i++)
	if (o.ListDefault == s->id[i])
	  found = 1;
      Expr *s1 = new Expr;
      s1->i = found;
      s1->Type = Expr::E_INT;
      s->op1 = s1;
      s->Type = Expr::E_NOTNULL;
    }
}

typedef enum
{ EX_INT, EX_FLOAT, EX_STRING } EX_Type;

EX_Type
GetExpressionType (Expr * s, int l, const Device & d)
{
  int i;
  EX_Type e1, e2;
  if (!s)
    die (_("line %d: no expression"), l);
  switch (s->Type)
    {
    case Expr::E_PAR:
      for (i = 0; i < d.StringParameters (); i++)
	if (d.StringParameters[i].Name == s->s)
	  break;
      if (d.StringParameters () != i)
	{
	  s->s = d.StringParameters[i].ID;
	  if (!d.StringParameters[i].ID_lineno)
	    {
	      s->s = d.StringParameters[i].Default;
	      s->Type = Expr::E_STRING;
	    }
	  return EX_STRING;
	}
      for (i = 0; i < d.IntParameters (); i++)
	if (d.IntParameters[i].Name == s->s)
	  break;
      if (d.IntParameters () != i)
	{
	  s->s = d.IntParameters[i].ID;
	  if (!d.IntParameters[i].ID_lineno)
	    {
	      s->i = d.IntParameters[i].Default;
	      s->Type = Expr::E_INT;
	    }
	  return EX_INT;
	}
      for (i = 0; i < d.FloatParameters (); i++)
	if (d.FloatParameters[i].Name == s->s)
	  break;
      if (d.FloatParameters () != i)
	{
	  s->s = d.FloatParameters[i].ID;
	  if (!d.FloatParameters[i].ID_lineno)
	    {
	      s->f = d.FloatParameters[i].Default;
	      s->Type = Expr::E_FLOAT;
	    }
	  return EX_FLOAT;
	}
      die (_("line %d: undefined parameter %s"), l, s->s ());
      break;
    case Expr::E_INT:
      return EX_INT;
    case Expr::E_FLOAT:
      return EX_FLOAT;
    case Expr::E_STRING:
      return EX_STRING;
    case Expr::E_NEG:
      e1 = GetExpressionType (s->op1, l, d);
      if (e1 != EX_INT && e1 != EX_FLOAT)
	die (_("line %d: unsupported type for negation"), l);
      return e1;
    case Expr::E_PLUS:
    case Expr::E_MINUS:
    case Expr::E_MUL:
    case Expr::E_DIV:
      e1 = GetExpressionType (s->op1, l, d);
      if (e1 != EX_INT && e1 != EX_FLOAT)
	die (_("line %d: unsupported type for aritmetic operation"), l);

      e2 = GetExpressionType (s->op2, l, d);
      if (e2 != EX_INT && e2 != EX_FLOAT)
	die (_("line %d: unsupported type for aritmetic operation"), l);

      if (e1 == EX_FLOAT)
	return EX_FLOAT;
      if (e2 == EX_FLOAT)
	return EX_FLOAT;
      return EX_INT;
    case Expr::E_MOD:
      e1 = GetExpressionType (s->op1, l, d);
      if (e1 != EX_INT)
	die (_("line %d: unsupported type for modulo operation"), l);

      e2 = GetExpressionType (s->op2, l, d);
      if (e2 != EX_INT)
	die (_("line %d: unsupported type for modulo operation"), l);

      return EX_INT;

    default:
      die (_("line %d: invalid expression"), l);
    }
}
void
CheckExpressionCompare (Expr * s1, Expr * s2, int l, const Device & d)
{
  EX_Type e1, e2;
  e1 = GetExpressionType (s1, l, d);
  e2 = GetExpressionType (s2, l, d);
  if (e1 == EX_INT && e2 == EX_FLOAT)
    e1 = EX_FLOAT;
  if (e1 == EX_FLOAT && e2 == EX_INT)
    e2 = EX_FLOAT;
  if (e1 != e2)
    die (_("line %d: different types for compare expression"), l);
}

void
CheckExpressionInt (Expr * s1, int l, const Device & d)
{
  EX_Type e1;
  e1 = GetExpressionType (s1, l, d);
  if (e1 != EX_INT)
    die (_("line %d: expect integer value"), l);
}

void
CheckExpressionBool (Expr * s, int l, const Device & d)
{
  if (!s)
    die (_("line %d: no expression"), l);
  switch (s->Type)
    {
    case Expr::E_AND:
    case Expr::E_OR:
      CheckExpressionBool (s->op1, l, d);
      CheckExpressionBool (s->op2, l, d);
      break;
    case Expr::E_NOT:
      CheckExpressionBool (s->op1, l, d);
      break;
    case Expr::E_IN:
      CheckExpressionList (s, l, d);
      break;
    case Expr::E_EQ:
    case Expr::E_NE:
    case Expr::E_LT:
    case Expr::E_GT:
    case Expr::E_LE:
    case Expr::E_GE:
      CheckExpressionCompare (s->op1, s->op2, l, d);
      break;
    case Expr::E_NOTNULL:
      CheckExpressionInt (s->op1, l, d);
      break;
    default:
      die (_("line %d: invalid expression"), l);
    }
}

void
CheckDebounce (Device & d, Debounce & o)
{
  if (!o.Name ())
    undefined ("Debounce", "Name", o.lineno);
  NewSymbol (o.Name, o.lineno);
  if (o.Time_lineno < 0.5 || o.Time_lineno > 127)
    die (_("line %d: debounce time not in the range of 0.5 to 127 ms"),
	 o.Time_lineno);
}

void
CheckTimer (Device & d, Timer & o)
{
  if (!o.Name ())
    undefined ("Timer", "Name", o.lineno);
  NewSymbol (o.Name, o.lineno);
  NewSymbol (o.Name + "_no", o.lineno);
  NewSymbol (o.Name + "_set", o.lineno);
  NewSymbol (o.Name + "_get", o.lineno);
  NewSymbol (o.Name + "_del", o.lineno);
  if (!o.Type_lineno)
    undefined ("Timer", "Type", o.lineno);
  switch (o.Type)
    {
    case TM_EnableUserTimer:
    case TM_UserTimer:
      o.TimerNo = d.UserTimer++;
      break;
    case TM_CountDownTimer:
    case TM_DifferenceCounter:
    case TM_SystemTimer:
    case TM_MessageTimer:
    case TM_MessageCyclicTimer:
      o.TimerNo = d.NextTimer++;
    }
  switch (o.Type)
    {
    case TM_EnableUserTimer:
    case TM_UserTimer:
      if (!o.Resolution_lineno)
	undefined ("Timer", "Resolution", o.lineno);
      if (o.Resolution < TM_RES_133ms || o.Resolution > TM_RES_72min48s)
	die (_("line %d: unsupported timer resolution"), o.Resolution_lineno);
      if (o.on_expire ())
	NewSymbol (o.on_expire, o.on_expire_lineno);
      break;
    case TM_SystemTimer:
      if (o.on_expire_lineno)
	die (_("line %d: on_expire not supported"), o.on_expire_lineno);
      if (o.Resolution_lineno)
	die (_("line %d: Resolution not supported"), o.Resolution_lineno);
      break;
    case TM_CountDownTimer:
      if (!o.Resolution_lineno)
	undefined ("Timer", "Resolution", o.lineno);
      if (o.Resolution < TM_RES_0_5ms || o.Resolution > TM_RES_33s)
	die (_("line %d: unsupported timer resolution"), o.Resolution_lineno);
      if (o.on_expire ())
	NewSymbol (o.on_expire, o.on_expire_lineno);
      break;
    case TM_DifferenceCounter:
      if (!o.Resolution_lineno)
	undefined ("Timer", "Resolution", o.lineno);
      if (o.Resolution < TM_RES_0_5ms || o.Resolution > TM_RES_33s)
	die (_("line %d: unsupported timer resolution"), o.Resolution_lineno);
      if (o.on_expire_lineno)
	die (_("line %d: on_expire not supported"), o.on_expire_lineno);
      break;
    case TM_MessageTimer:
      if (o.on_expire_lineno)
	die (_("line %d: on_expire not supported"), o.on_expire_lineno);
      if (!o.Resolution_lineno)
	undefined ("Timer", "Resolution", o.lineno);
      if (o.Resolution < TM_RES_0_4ms || o.Resolution > TM_RES_27s)
	die (_("line %d: unsupported timer resolution"), o.Resolution_lineno);
      if (d.BCU == BCU_bcu12)
	die (_("line %d: timertype not supported on a BCU 1"), o.Type_lineno);
      break;
    case TM_MessageCyclicTimer:
      if (o.on_expire_lineno)
	die (_("line %d: on_expire not supported"), o.on_expire_lineno);
      if (!o.Resolution_lineno)
	undefined ("Timer", "Resolution", o.lineno);
      if (o.Resolution < TM_RES_100ms || o.Resolution > TM_RES_1min)
	die (_("line %d: unsupported timer resolution"), o.Resolution_lineno);
      if (d.BCU == BCU_bcu12)
	die (_("line %d: timertype not supported on a BCU 1"), o.Type_lineno);
    }
}

void
CheckDevice (Device & d)
{
  int i;
  int objno = 4;

  if (!d.BCU_lineno)
    undefined ("Device", "BCU", d.lineno);
  d.MaskVersion = d.BCU;

  for (i = 0; i < d.StringParameters (); i++)
    CheckStringParameter (d, d.StringParameters[i]);
  for (i = 0; i < d.FloatParameters (); i++)
    CheckFloatParameter (d, d.FloatParameters[i]);
  for (i = 0; i < d.IntParameters (); i++)
    CheckIntParameter (d, d.IntParameters[i]);
  for (i = 0; i < d.ListParameters (); i++)
    CheckListParameter (d, d.ListParameters[i]);

  for (i = 0; i < d.PollingMasters (); i++)
    CheckPollingMaster (d, d.PollingMasters[i]);
  for (i = 0; i < d.PollingSlaves (); i++)
    CheckPollingSlave (d, d.PollingSlaves[i]);
  for (i = 0; i < d.Objects (); i++)
    CheckObject (d, d.Objects[i], objno);
  for (i = 0; i < d.GroupObjects (); i++)
    CheckGroupObject (d, d.GroupObjects[i]);

  for (i = 0; i < d.FunctionalBlocks (); i++)
    CheckFunctionalBlock (d, d.FunctionalBlocks[i]);

  for (i = 0; i < d.Debounces (); i++)
    CheckDebounce (d, d.Debounces[i]);
  if (d.Debounces () > 1)
    die (_("only one debouncer supported"));

  d.UserTimer = 0;
  d.NextTimer = 2;
  if (d.Debounces ())
    d.NextTimer = 3;

  for (i = 0; i < d.Timers (); i++)
    CheckTimer (d, d.Timers[i]);

  if (d.NextTimer > 4)
    die (_("too many system timers in used"));

  if (!d.ManufacturerCode_lineno)
    {
      d.ManufacturerCode_lineno = d.lineno;
      d.ManufacturerCode = 0xffff;
    }
  if (d.ManufacturerCode < 0 || d.ManufacturerCode > 0xffff)
    die (_("line %d: invalid manufacturer code"), d.ManufacturerCode_lineno);
  if (!d.InternalManufacturerCode_lineno)
    {
      d.InternalManufacturerCode_lineno = d.lineno;
      d.InternalManufacturerCode = d.ManufacturerCode;
    }

  if (d.InternalManufacturerCode < 0 || d.InternalManufacturerCode > 0xffff)
    die (_("line %d: invalid internal manufacturer code"),
	 d.InternalManufacturerCode_lineno);

  if (!d.DeviceType_lineno)
    {
      d.DeviceType_lineno = d.lineno;
      d.DeviceType = 0xfff0;
    }
  if (d.DeviceType < 0 || d.DeviceType > 0xffff)
    die (_("line %d: invalid devicetype"), d.DeviceType_lineno);

  if (!d.Version_lineno)
    {
      d.Version_lineno = d.lineno;
      d.Version = 0;
    }
  if (d.Version < 0 || d.Version > 0xff)
    die (_("line %d: invalid version"), d.Version_lineno);


  if (!d.SyncRate_lineno)
    {
      d.SyncRate_lineno = d.lineno;
      d.SyncRate = 0xff;
    }
  if (d.SyncRate < 0 || d.SyncRate > 0xff)
    die (_("line %d: invalid sync rate"), d.SyncRate_lineno);

  if (!d.PEIType_lineno)
    undefined ("Device", "PEIType", d.lineno);
  if (d.PEIType < 0 || d.PEIType >= 20)
    die (_("line %d: invalid PEI Type"), d.PEIType_lineno);

  if (!d.PortADDR_lineno)
    {
      d.PortADDR_lineno = d.lineno;
      d.PortADDR = 0;
    }
  if (d.PortADDR < 0 || d.PortADDR > 0xff)
    die (_("line %d: invalid PortADDR"), d.PortADDR_lineno);

  if (!d.PortCDDR_lineno)
    {
      d.PortCDDR_lineno = d.lineno;
      d.PortCDDR = 0;
    }
  if (d.PortCDDR < 0 || d.PortCDDR > 0xff)
    die (_("line %d: invalid PortCDDR"), d.PortCDDR_lineno);

  if (d.BCU1_SEC_lineno && d.BCU != BCU_bcu12)
    die (_("line %d: not supported for this bcu type"), d.BCU1_SEC_lineno);
  if (d.BCU1_PROTECT_lineno && d.BCU != BCU_bcu12)
    die (_("line %d: not supported for this bcu type"),
	 d.BCU1_PROTECT_lineno);
  if (d.AutoPLMA_lineno && d.BCU != BCU_bcu12)
    die (_("line %d: not supported for this bcu type"), d.AutoPLMA_lineno);

  if (d.BCU2_PROTECT_lineno && d.BCU == BCU_bcu12)
    die (_("line %d: not supported for this bcu type"),
	 d.BCU2_PROTECT_lineno);
  if (d.BCU2_WATCHDOG_lineno && d.BCU == BCU_bcu12)
    die (_("line %d: not supported for this bcu type"),
	 d.BCU2_WATCHDOG_lineno);
  if (d.PLM_FAST_lineno && d.BCU == BCU_bcu12)
    die (_("line %d: not supported for this bcu type"), d.PLM_FAST_lineno);

  if (d.RouteCount_lineno)
    {
      if (d.RouteCount < 0 || d.RouteCount > 7)
	die (_("line %d: invalid value for RouteCount"), d.RouteCount_lineno);
    }
  else
    d.RouteCount = 6;

  if (d.BusyLimit_lineno)
    {
      if (d.BusyLimit < 0 || d.BusyLimit > 7)
	die (_("line %d: invalid value for BusyLimit"), d.BusyLimit_lineno);
    }
  else
    d.BusyLimit = 3;

  if (d.INAKLimit_lineno)
    {
      if (d.INAKLimit < 0 || d.INAKLimit > 7)
	die (_("line %d: invalid value for INAKLimit"), d.INAKLimit_lineno);
    }
  else
    d.INAKLimit = 3;

  if (d.RateLimit_lineno)
    {
      if (d.RateLimit < 1 || d.RateLimit > 127)
	die (_("line %d: invalid value for RateLimit"), d.RateLimit_lineno);
    }

  if (!d.U_DELMSG_lineno)
    d.U_DELMSG = 1;
  if (!d.CPOL_lineno)
    d.CPOL_lineno = 1;
  if (!d.CPHA_lineno)
    d.CPHA_lineno = 1;
  if (!d.AutoPLMA_lineno)
    d.AutoPLMA = 0;

  if (!d.BCU1_SEC_lineno)
    d.BCU1_SEC = 0;
  if (!d.BCU1_PROTECT_lineno)
    d.BCU1_PROTECT = 0;
  if (!d.BCU2_PROTECT_lineno)
    d.BCU2_PROTECT = 0;
  if (!d.BCU2_WATCHDOG_lineno)
    d.BCU2_WATCHDOG = 1;
  if (!d.PLM_FAST_lineno)
    d.PLM_FAST = 0;
  if (!d.A_Event_lineno)
    d.A_Event = 1;

#ifdef CHECK1
  if (!d.Title ())
    undefined ("Device", "Title", d.lineno);

#endif
#ifdef CHECK2
  if (!d.PhysicalAddress_lineno)
    undefined ("Device", "PhyiscalAddress", d.lineno);
#endif
  if (d.BCU == BCU_bcu12 && d.Objects ())
    die (_("BCU1 supports no objects"));

  if (d.BCU == BCU_bcu12 && d.PollingMasters ())
    die (_("BCU1 supports no polling"));

  if (d.BCU == BCU_bcu12 && d.PollingSlaves ())
    die (_("BCU1 supports no polling"));

  if (d.BCU == BCU_bcu12 && d.InstallKey_lineno)
    die (_("installkey not supported"));
  if (d.BCU == BCU_bcu12 && d.Keys ())
    die (_("BCU1 supports no access protection"));

  if (d.BCU == BCU_bcu12 && UsePEI (d))
    die (_("BCU1 supports no custom PEI handler"));

  if (d.BCU != BCU_bcu12)
    {
      d.Key.resize (3);
      for (i = 0; i < 3; i++)
	d.Key[i] = 0xFFFFFFFF;
      if (d.Keys ())
	{
	  for (i = 0; i < d.Keys (); i++)
	    {
	      if (d.Keys[i].level < 0 || d.Keys[i].level > 2)
		die (_("unsupported key level %d"), d.Keys[i].level);
	      for (int j = 0; j < i; j++)
		if (d.Keys[i].level == d.Keys[j].level)
		  die (_("duplicate key level %d"), d.Keys[i].level);
	      d.Key[d.Keys[i].level] = d.Keys[i].key;
	    }
	}
      if (!d.InstallKey_lineno)
	d.InstallKey = 0xFFFFFFFF;

      if (d.PollingMasters ())
	die (_("not yet supported"));

      if (d.PollingSlaves ())
	die (_("not yet supported"));

    }

}
