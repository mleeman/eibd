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

#include "gencode.h"
#include "map.h"
#include "addrtab.h"
#include "loadctl.h"
#include "check.h"

static const char *
inttype (int i)
{
  const char *utypes[] = { "unsigned char", "unsigned short", "unsigned long",
    "unsigned long long"
  };
  const char *stypes[] =
    { "signed char", "signed short", "signed long", "signed long long" };
  if (i > 0)
    return utypes[i - 1];
  return stypes[-i - 1];

}

void
GenListEnum (FILE * f, ListParameter & d)
{
  fprintf (f, "typedef enum { ");
  for (int i = 0; i < d.Elements (); i++)
    fprintf (f, "%s, ", d.Elements[i].Name ());
  fprintf (f, " } %s_t;\n", d.Name ());
}

void
GenGroupObjectASM (FILE * f, GroupObject & o, BCUType b)
{
  int flag = 0;
  if (o.ObjNo == -1)
    return;
  flag = GroupObjectFlag (o, b);
  fprintf (f, "\t.byte %s(%s),0x%02X,GROUPTYPE_%d\n",
	   (b == BCU_bcu12 ? "lo8" : "offset8"), o.Name (), flag, o.Type);
}

void
GenGroupObjectUpdate (FILE * f, GroupObject & o)
{
  if (o.ObjNo == -1)
    return;
  if (!o.on_update ())
    return;
  fprintf (f, "\tlda $%d\n", o.ObjNo);
  fprintf (f, "\tjsr U_testObj\n");
  fprintf (f, "\tbeq _NoChange%d\n", o.ObjNo);
  fprintf (f, "\tjsr %s_stub\n", o.on_update ());
  fprintf (f, "_NoChange%d:\n", o.ObjNo);
}

void
GenTimerUpdate (FILE * f, Timer & o)
{
  if (!o.on_expire ())
    return;
  fprintf (f, "\tlda $%d\n", o.TimerNo);
  switch (o.Type)
    {
    case TM_EnableUserTimer:
    case TM_UserTimer:
      fprintf (f, "\tjsr U_GetTMx\n");
      fprintf (f, "\tbne _NoTChange%d\n", o.TimerNo);
      break;
    case TM_CountDownTimer:
      fprintf (f, "\tjsr TM_GetFlg\n");
      fprintf (f, "\tbcs _NoTChange%d\n", o.TimerNo);
      break;
    }
  fprintf (f, "\tjsr %s_stub\n", o.on_expire ());
  fprintf (f, "_NoTChange%d:\n", o.TimerNo);
}

void
GenGroupObjectHeader (FILE * f, GroupObject & o)
{
  fprintf (f, "static const int %s_no = %d;\n", o.Name (), o.ObjNo);
  if (o.ObjNo == -1)
    fprintf (f, "static ");
  fprintf (f, "GROUP%d_T %s", o.Type, o.Name ());
  if (o.eeprom)
    fprintf (f, " EEPROM_ATTRIB EEPROM_SECTION");
  else
    fprintf (f, " RAM_SECTION");
  fprintf (f, ";\n");

  if (o.on_update ())
    fprintf (f, "static void %s();\n", o.on_update ());
  if (o.ObjNo == -1)
    {
      if (o.Sending)
	fprintf (f, "static void %s_transmit(){}\n", o.Name ());
      if (o.Reading)
	fprintf (f, "static void %s_readrequest(){}\n", o.Name ());
      if (o.Reading && o.Sending)
	fprintf (f, "static void %s_clear(){}\n", o.Name ());
    }
  else
    {
      if (o.on_update ())
	fprintf (f, "NOSAVE(void %s_stub()) {%s();}\n",
		 o.on_update (), o.on_update ());

      if (o.Sending)
	{
#ifdef BUILDMAX
	  if (o.Sending)
#else
	  if (o.SendAddress_lineno)
#endif
	    fprintf (f,
		     "static void inline %s_transmit(){__U_transRequest(%d);}\n",
		     o.Name (), o.ObjNo);
	  else
	    fprintf (f, "static void %s_transmit(){}\n", o.Name ());
	}

      if (o.Reading)
	{
#ifdef BUILDMAX
	  if (o.Reading)
#else
	  if (o.ReadRequestAddress_lineno)
#endif
	    fprintf (f,
		     "static void inline %s_readrequest(){__U_flag_Set(%d,2);__U_transRequest(%d);}\n",
		     o.Name (), o.ObjNo, o.ObjNo);
	  else
	    fprintf (f, "static void %s_readrequest(){}\n", o.Name ());
	}
      if (o.Reading && o.Sending)
	{
#ifdef BUILDMAX
	  if (o.Reading && o.Sending)
#else
	  if (o.ReadRequestAddress_lineno && o.SendAddress_lineno)
#endif
	    fprintf (f,
		     "static void inline %s_clear(){__U_flag_Clear(%d,2);}\n",
		     o.Name (), o.ObjNo);
	  else
	    fprintf (f, "static void %s_clear(){}\n", o.Name ());
	}


    }
}

void
GenEIBObject (FILE * f, Object & o)
{
  int i;
  fprintf (f, "%s:\n", o.Name ());
  fprintf (f, "\t.byte 0x%02X,%d\n", (o.RAccess << 4) | (o.WAccess),
	   o.PropCount + 1);
  fprintf (f, "\t.byte %d,%d\n", 1, 4);
  fprintf (f, "\t.hword 0x%04X\n", o.ObjectType);
  for (i = 0; i < o.Propertys (); i++)
    {
      if (o.Propertys[i].Disable)
	continue;
      fprintf (f, "\t.byte %d,%d\n", o.Propertys[i].PropertyID,
	       (o.Propertys[i].Type & 0x1f) | (o.Propertys[i].
					       ReadOnly ? 0x00 : 0x80) | (o.
									  Propertys
									  [i].
									  MaxArrayLength
									  ==
									  1 ?
									  0x00
									  :
									  0x40)
	       | 0x20);
      fprintf (f, "\t.hword %s%s\n", o.Propertys[i].Name (),
	       o.Propertys[i].handler () !=
	       0 ? "_stub+0x8000" : (o.Propertys[i].MaxArrayLength >
				     1 ? "_array" : ""));
    }
  for (i = 0; i < o.Propertys (); i++)
    {
      if (!o.Propertys[i].handler () && (o.Propertys[i].MaxArrayLength > 1)
	  && !o.Propertys[i].Disable)
	{
	  fprintf (f, "%s_array:\n", o.Propertys[i].Name ());
	  fprintf (f, "\t.byte %d\n", o.Propertys[i].MaxArrayLength);
	  fprintf (f, "\t.hword %s\n", o.Propertys[i].Name ());
	}
      if (o.Propertys[i].handler () && !o.Propertys[i].Disable)
	{
	  fprintf (f, "%s_stub:\n", o.Name ());
	  fprintf (f, "\tclra\n", o.Name ());
	  fprintf (f, "\tbcc L1_%s\n", o.Name ());
	  fprintf (f, "\tinca\n", o.Name ());
	  fprintf (f, "L1_%s:\n", o.Name ());
	  fprintf (f, "\tsta __tmp_space\n");
	  fprintf (f, "\tstx __tmp_space+1\n");
	  fprintf (f, "\tjsr %s_stub1\n", o.Name ());
	  fprintf (f, "\tldx __tmp_space+1\n");
	  fprintf (f, "\tlda __tmp_space+2\n");
	  fprintf (f, "\tclc\n");
	  fprintf (f, "\ttst __tmp_space\n");
	  fprintf (f, "\tbeq L2_%s\n", o.Name ());
	  fprintf (f, "\tsec\n");
	  fprintf (f, "L2_%s:\n", o.Name ());
	  fprintf (f, "\trts\n", o.Name ());
	}
    }
}

void
GenInclude (FILE * f, Device & d)
{
  int i;
  for (i = 0; i < d.include (); i++)
    fprintf (f, "#include \"%s\"\n", escapeString (d.include[i]) ());
}

void
GenCommonHeader (FILE * f, Device & d)
{
  int i;
  if (d.on_init ())
    fprintf (f, "static void %s();\n", d.on_init ());
  if (d.on_run ())
    fprintf (f, "static void %s();\n", d.on_run ());
  if (d.on_save ())
    fprintf (f, "static void %s();\n", d.on_save ());

  if (d.on_pei_init ())
    fprintf (f, "static void %s();\n", d.on_pei_init ());
  if (d.on_pei_message ())
    fprintf (f, "static void %s();\n", d.on_pei_message ());
  if (d.on_pei_cycle ())
    fprintf (f, "static void %s();\n", d.on_pei_cycle ());
  if (d.on_pei_user ())
    fprintf (f, "static void %s(uchar event);\n", d.on_pei_user ());
  if (d.on_pei_rc_even ())
    fprintf (f, "static void %s();\n", d.on_pei_rc_even ());
  if (d.on_pei_rc_odd ())
    fprintf (f, "static void %s();\n", d.on_pei_rc_odd ());
  if (d.on_pei_tc ())
    fprintf (f, "static void %s();\n", d.on_pei_tc ());
  if (d.on_pei_tdre ())
    fprintf (f, "static void %s();\n", d.on_pei_tdre ());
  if (d.on_pei_sci_idle ())
    fprintf (f, "static void %s();\n", d.on_pei_sci_idle ());
  if (d.on_pei_spif ())
    fprintf (f, "static void %s();\n", d.on_pei_spif ());
  if (d.on_pei_oca ())
    fprintf (f, "static void %s();\n", d.on_pei_oca ());
  if (d.on_pei_ocb ())
    fprintf (f, "static void %s();\n", d.on_pei_ocb ());
  if (d.on_pei_ica ())
    fprintf (f, "static void %s();\n", d.on_pei_ica ());
  if (d.on_pei_icb ())
    fprintf (f, "static void %s();\n", d.on_pei_icb ());

  if (UsePEI (d))
    {
      fprintf (f,
	       "NOSAVE(void _PEI_Handler_stub())\n{\nuchar event=__tmp_space[0];\n");
      if (d.on_pei_init ())
	fprintf (f, "if (event==PM_INIT) %s();\n", d.on_pei_init ());
      if (d.on_pei_message ())
	fprintf (f, "if (event==PM_MESSAGE) %s();\n", d.on_pei_message ());
      if (d.on_pei_cycle ())
	fprintf (f, "if (event==PM_CYCLE) %s();\n", d.on_pei_cycle ());
      if (d.on_pei_rc_even ())
	fprintf (f, "if (event==PM_rc_even) %s();\n", d.on_pei_rc_even ());
      if (d.on_pei_rc_odd ())
	fprintf (f, "if (event==PM_rc_odd) %s();\n", d.on_pei_rc_odd ());
      if (d.on_pei_tc ())
	fprintf (f, "if (event==PM_rc_tc) %s();\n", d.on_pei_tc ());
      if (d.on_pei_tdre ())
	fprintf (f, "if (event==PM_tdre) %s();\n", d.on_pei_tdre ());
      if (d.on_pei_sci_idle ())
	fprintf (f, "if (event==PM_sci_idle) %s();\n", d.on_pei_sci_idle ());
      if (d.on_pei_spif ())
	fprintf (f, "if (event==PM_spif) %s();\n", d.on_pei_spif ());
      if (d.on_pei_oca ())
	fprintf (f, "if (event==PM_OCA) %s();\n", d.on_pei_oca ());
      if (d.on_pei_ocb ())
	fprintf (f, "if (event==PM_OCB) %s();\n", d.on_pei_ocb ());
      if (d.on_pei_ica ())
	fprintf (f, "if (event==PM_ICA) %s();\n", d.on_pei_ica ());
      if (d.on_pei_icb ())
	fprintf (f, "if (event==PM_ICB) %s();\n", d.on_pei_icb ());
      if (d.on_pei_user ())
	fprintf (f, "%s(uchar event);\n", d.on_pei_user ());
      fprintf (f, "}\n\n");
    }

  if (d.on_init ())
    fprintf (f, "NOSAVE(void %s_stub()) {%s();}\n",
	     d.on_init (), d.on_init ());
  if (d.on_run ())
    fprintf (f, "NOSAVE(void %s_stub()) {%s();}\n", d.on_run (), d.on_run ());
  if (d.on_save ())
    fprintf (f, "NOSAVE(void %s_stub()) {%s();}\n",
	     d.on_save (), d.on_save ());
  if (d.Debounces ())
    {
      if (d.Debounces[0].Time_lineno)
	{
	  int t = (int) (d.Debounces[0].Time / 0.5);
	  if (t == 60)
	    fprintf (f,
		     "static uchar inline %s(uchar val){return _U_deb30(val);}\n",
		     d.Debounces[0].Name ());
	  else if (t == 20)
	    fprintf (f,
		     "static uchar inline %s(uchar val){return _U_deb10(val);}\n",
		     d.Debounces[0].Name ());
	  else
	    fprintf (f,
		     "static uchar inline %s(uchar val){return _U_debounce(val,%d);}\n",
		     d.Debounces[0].Name (), t);
	}
      else
	fprintf (f,
		 "static uchar inline %s(uchar val,uchar time){return _U_debounce(val,time);}\n",
		 d.Debounces[0].Name ());
    }
  for (i = 0; i < d.Timers (); i++)
    {
      Timer & o = d.Timers[i];
      fprintf (f, "static const uchar %s_no=%d;\n", o.Name (), o.TimerNo);
      if (o.on_expire_lineno)
	{
	  fprintf (f, "static void %s();\n", o.on_expire ());
	  if (o.Type != TM_EnableUserTimer)
	    fprintf (f, "NOSAVE(void %s_stub()) { %s(); }\n",
		     o.on_expire (), o.on_expire ());
	}
      switch (o.Type)
	{
	case TM_EnableUserTimer:
	  fprintf (f, "static bool %s_enable=false;\n", o.Name ());
	  fprintf (f,
		   "static void inline %s_set(uchar time){%s_enable=true;_U_SetTMx(%d,time);}\n",
		   o.Name (), o.Name (), o.TimerNo);
	  fprintf (f, "static bool inline %s_get(){return _U_GetTMx(%d);}\n",
		   o.Name (), o.TimerNo);
	  fprintf (f, "static void inline %s_del(){%s_enable=false;}\n",
		   o.Name (), o.Name ());
	  fprintf (f, "extern uchar %s;\n", o.Name ());
	  fprintf (f,
		   "NOSAVE(void %s_stub()) { if(!%s_enable) return; %s_enable=false; %s(); }\n",
		   o.on_expire (), o.Name (), o.Name (), o.on_expire ());
	  break;
	case TM_UserTimer:
	  fprintf (f,
		   "static void inline %s_set(uchar time){_U_SetTMx(%d,time);}\n",
		   o.Name (), o.TimerNo);
	  fprintf (f, "static bool inline %s_get(){return _U_GetTMx(%d);}\n",
		   o.Name (), o.TimerNo);
	  fprintf (f, "extern uchar %s;\n", o.Name ());
	  break;
	case TM_SystemTimer:
	  break;
	case TM_CountDownTimer:
	  fprintf (f,
		   "static void inline %s_set(uchar time){_TM_Load(0x%x,time);}\n",
		   o.Name (),
		   (o.TimerNo << 4) | ((o.Resolution - TM_RES_0_5ms) & 0x07));
	  fprintf (f,
		   "static bool inline %s_get(){return _TM_GetFlg_M0(%d);}\n",
		   o.Name (), o.TimerNo);
	  break;
	case TM_DifferenceCounter:
	  fprintf (f,
		   "static void inline %s_set(uchar time){_TM_Load(0x%x,time);}\n",
		   o.Name (),
		   (o.
		    TimerNo << 4) | ((o.Resolution -
				      TM_RES_0_5ms) & 0x07) | 0x08);
	  fprintf (f,
		   "static bool inline %s_get(){return _TM_GetFlg_M1(%d);}\n",
		   o.Name (), o.TimerNo);
	  break;
	case TM_MessageTimer:
	  fprintf (f,
		   "static void inline %s_set(uchar time){_U_TS_Set(%d,0x30,0x%x,time,0);}\n",
		   o.Name (), o.TimerNo,
		   (((o.Resolution - TM_RES_0_4ms) & 0x07) << 5));
	  fprintf (f, "static void inline %s_del(){_U_TS_Del(%d);}\n",
		   o.Name (), o.TimerNo);
	  break;
	case TM_MessageCyclicTimer:
	  fprintf (f,
		   "static void inline %s_set(uchar param){_U_TS_Set(%d,0x40,0x%x,0,param);}\n",
		   o.Name (), o.TimerNo,
		   (((o.Resolution - TM_RES_100ms + 1) & 0x07) << 2));
	  fprintf (f, "static void inline %s_del(){_U_TS_Del(%d);}\n",
		   o.Name (), o.TimerNo);
	  break;
	}
    }
  for (i = 0; i < d.Objects (); i++)
    {
      Object & o1 = d.Objects[i];
      for (int j = 0; j < o1.Propertys (); j++)
	{
	  Property & o = o1.Propertys[j];
	  if (o.handler ())
	    {
	      fprintf (f, "static PropertyResult %s(PropertyRequest r);\n");
	      if (!o.Disable)
		{
		  fprintf (f, "extern volatile uint1 __tmp_space[4];\n");
		  fprintf (f, "NOSAVE(void %s_stub1())\n");
		  fprintf (f, "{PropertyRequest r1;PropertyResult r2;\n");
		  fprintf (f,
			   "r1.write=__tmp_space[0];r1.ptr=__tmp_space[1];\n");
		  fprintf (f, "r2=%s(r1);\n", o.handler ());
		  fprintf (f,
			   "__tmp_space[0]=r2.error;__tmp_space[1]=r2.ptr;__tmp_space[2]=r2.length\n");
		  fprintf (f, "}\n");
		}
	    }
	  else if (o.MaxArrayLength > 1)
	    {
	      if (o.Disable)
		fprintf (f, "static ");
	      fprintf (f, "struct { int count; PROP%d_T elements[%d]; } %s ",
		       o.Type, o.Name (), o.MaxArrayLength);
	      fprintf (f, "%s",
		       o.eeprom ? "EEPROM_ATTRIB EEPROM_SECTION" : "");
	      fprintf (f, " = { %d };\n", o.MaxArrayLength);
	    }
	  else
	    {
	      if (o.Disable)
		fprintf (f, "static PROP%d_T %s", o.Type, o.Name ());
	      else
		fprintf (f, "PROP%d_T %s", o.Type, o.Name ());
	      if (o.eeprom)
		fprintf (f, " EEPROM_SECTION EEPROM_ATTRIB");
	      fprintf (f, ";\n");
	    }
	}
    }
}

void
GenTestHeader (FILE * f, Device & d)
{
  int i;
  fprintf (f, "#include <bcu_%04x.h>\n", d.BCU);
  for (i = 0; i < d.StringParameters (); i++)
    {
      StringParameter & s = d.StringParameters[i];
      fprintf (f, "extern const char %s[%d];\n", s.Name (), s.MaxLength + 1);
    }
  for (i = 0; i < d.FloatParameters (); i++)
    {
      FloatParameter & s = d.FloatParameters[i];
      fprintf (f, "extern const float %s;\n", s.Name ());
    }
  for (i = 0; i < d.IntParameters (); i++)
    {
      IntParameter & s = d.IntParameters[i];
      fprintf (f, "extern const %s %s;\n", inttype (s.SIZE), s.Name ());
    }
  for (i = 0; i < d.ListParameters (); i++)
    {
      ListParameter & s = d.ListParameters[i];
      GenListEnum (f, s);
      fprintf (f, "extern const %s_t %s;\n", s.Name (), s.Name ());
    }
  for (i = 0; i < d.GroupObjects (); i++)
    GenGroupObjectHeader (f, d.GroupObjects[i]);
  GenCommonHeader (f, d);
}

void
GenTestData (FILE * f, Device & d)
{
  int i;
  for (i = 0; i < d.StringParameters (); i++)
    {
      StringParameter & s = d.StringParameters[i];
      fprintf (f,
	       "const char %s[%d] __attribute__ ((section (\".parameter\")))=\"%s\";\n",
	       s.Name (), s.MaxLength + 1, escapeString (s.Default) ());
    }
  for (i = 0; i < d.FloatParameters (); i++)
    {
      FloatParameter & s = d.FloatParameters[i];
      fprintf (f,
	       "const float %s __attribute__ ((section (\".parameter\"))) =%f;\n",
	       s.Name (), s.Default);
    }
  for (i = 0; i < d.IntParameters (); i++)
    {
      IntParameter & s = d.IntParameters[i];
      fprintf (f,
	       "const %s %s __attribute__ ((section (\".parameter\"))) =%d;\n",
	       inttype (s.SIZE), s.Name (), s.Default);
    }
  for (i = 0; i < d.ListParameters (); i++)
    {
      ListParameter & s = d.ListParameters[i];
      GenListEnum (f, s);
      fprintf (f,
	       "const %s_t %s __attribute__ ((section (\".parameter\"))) = %s;\n",
	       s.Name (), s.Name (), s.Elements[s.def].Name ());
    }
}
void
printParameterInfo (FILE * f, Device & d)
{
  int i;
  fprintf (f, "\t.section .loadcontrol\n");
  for (i = 0; i < d.StringParameters (); i++)
    {
      StringParameter & s = d.StringParameters[i];
      if (!s.ID_lineno)
	continue;
      fprintf (f, "\t.hword %d\n", strlen (s.ID ()) + 7);
      fprintf (f, "\t.hword %d\n", L_STRING_PAR);
      fprintf (f, "\t.hword %s\n", s.Name ());
      fprintf (f, "\t.hword %d\n", s.MaxLength + 1);
      fprintf (f, "\t.string \"%s\"\n", s.ID ());
    }
  for (i = 0; i < d.FloatParameters (); i++)
    {
      FloatParameter & s = d.FloatParameters[i];
      if (!s.ID_lineno)
	continue;
      fprintf (f, "\t.hword %d\n", strlen (s.ID ()) + 5);
      fprintf (f, "\t.hword %d\n", L_FLOAT_PAR);
      fprintf (f, "\t.hword %s\n", s.Name ());
      fprintf (f, "\t.string \"%s\"\n", s.ID ());
    }
  for (i = 0; i < d.IntParameters (); i++)
    {
      IntParameter & s = d.IntParameters[i];
      if (!s.ID_lineno)
	continue;
      fprintf (f, "\t.hword %d\n", strlen (s.ID ()) + 6);
      fprintf (f, "\t.hword %d\n", L_INT_PAR);
      fprintf (f, "\t.hword %s\n", s.Name ());
      fprintf (f, "\t.byte %d\n", s.SIZE);
      fprintf (f, "\t.string \"%s\"\n", s.ID ());
    }
  for (i = 0; i < d.ListParameters (); i++)
    {
      int j, l = 0;
      ListParameter & s = d.ListParameters[i];
      if (!s.ID_lineno)
	continue;
      for (j = 0; j < s.Elements (); j++)
	l += strlen (s.Elements[j].Value ()) + 1;
      fprintf (f, "\t.hword %d\n", strlen (s.ID ()) + 7 + l);
      fprintf (f, "\t.hword %d\n", L_LIST_PAR);
      fprintf (f, "\t.hword %s\n", s.Name ());
      fprintf (f, "\t.hword %d\n", s.Elements ());
      fprintf (f, "\t.string \"%s\"\n", s.ID ());
      for (j = 0; j < s.Elements (); j++)
	fprintf (f, "\t.string \"%s\"\n", s.Elements[j].Value ());
    }
  for (i = 0; i < d.GroupObjects (); i++)
    {
      GroupObject & s = d.GroupObjects[i];
      if (!s.ID_lineno)
	continue;
      fprintf (f, "\t.hword %d\n", strlen (s.ID ()) + 4);
      fprintf (f, "\t.hword %d\n", L_GROUP_OBJECT);
      fprintf (f, "\t.byte %d\n", i);
      fprintf (f, "\t.string \"%s\"\n", s.ID ());
    }
}


void
GenRealHeader (FILE * f, Device & d)
{
  int i;
  fprintf (f, "#include <bcu_%04x.h>\n", d.BCU);
  for (i = 0; i < d.StringParameters (); i++)
    {
      StringParameter & s = d.StringParameters[i];
      fprintf (f, "static const char %s[/*%d*/]=\"%s\";\n", s.Name (),
	       s.MaxLength + 1, escapeString (s.Value) ());
    }
  for (i = 0; i < d.FloatParameters (); i++)
    {
      FloatParameter & s = d.FloatParameters[i];
      fprintf (f, "static const float %s=%f;\n", s.Name (), s.Value);
    }
  for (i = 0; i < d.IntParameters (); i++)
    {
      IntParameter & s = d.IntParameters[i];
      fprintf (f, "static const %s %s=%d;\n", inttype (s.SIZE), s.Name (),
	       s.Value);
    }
  for (i = 0; i < d.ListParameters (); i++)
    {
      ListParameter & s = d.ListParameters[i];
      GenListEnum (f, s);
      fprintf (f, "static const %s_t %s= %s;\n", s.Name (), s.Name (),
	       s.Elements[s.def].Name ());
    }
  for (i = 0; i < d.GroupObjects (); i++)
    GenGroupObjectHeader (f, d.GroupObjects[i]);
  GenCommonHeader (f, d);
}

void
GenBCUHeader (FILE * f, Device & d)
{
  int i, j;
  fprintf (f, "\t.include \"bcu_%04x.inc\"\n", d.BCU);
  fprintf (f, "\t.section .loadcontrol\n");
  fprintf (f, "\t.hword %d\n", 4);
  fprintf (f, "\t.hword %d\n", L_BCU_TYPE);
  fprintf (f, "\t.hword %d\n", d.BCU);
  if (d.BCU != BCU_bcu12)
    {
      fprintf (f, "\t.hword %d\n", 4 * 4 + 2);
      fprintf (f, "\t.hword %d\n", L_BCU2_KEY);
      fprintf (f, "\t.long 0x%08X\n", d.InstallKey);
      for (i = 0; i < 3; i++)
	fprintf (f, "\t.long 0x%08X\n", d.Key[i]);
      fprintf (f, "\t.hword %d\n", 45);
      fprintf (f, "\t.hword %d\n", L_BCU2_INIT);
      fprintf (f, "\t.hword addrtab\n");
      fprintf (f, "\t.hword addrtab_end-addrtab\n");
      fprintf (f, "\t.hword assoctab\n");
      fprintf (f, "\t.hword assoctab_end-assoctab\n");

      fprintf (f, "\t.hword readonly_start\n");
      fprintf (f, "\t.hword readonly_end\n");
      fprintf (f, "\t.hword param_start\n");
      fprintf (f, "\t.hword param_end\n");
      fprintf (f, "\t.hword eibobjects\n");
      fprintf (f, "\t.hword %d #ObjCount\n", d.Objects ());
      fprintf (f, "\t.hword AL_SAPcallback\n");
      fprintf (f, "\t.hword commobjs\n");
      fprintf (f, "\t.hword ram_start\n");
      fprintf (f, "\t.hword eeprom_start\n");
      if (UsePEI (d))
	fprintf (f, "\t.hword peihandler #SPHandler\n");
      else
	fprintf (f, "\t.hword 0x0000 #SPHandler\n");

      fprintf (f, "\t.hword _UserInit\n");
      fprintf (f, "\t.hword _UserRun\n");
      fprintf (f, "\t.hword _UserSave\n");
      fprintf (f, "\t.hword eeprom_start\n");
      fprintf (f, "\t.hword eeprom_end\n");
      fprintf (f, "\t.hword 0\n");
      fprintf (f, "\t.byte 0\n");
    }
  fprintf (f, "\t.section .bcuconfig\n");
  if (d.BCU == BCU_bcu12)
    i = (d.BCU1_PROTECT ? 0x00 : 0x02) | (d.BCU1_SEC ? 0x00 : 0x01);
  else
    i = (d.BCU2_PROTECT ? 0x00 : 0x02) | (d.BCU2_WATCHDOG ? 0x01 : 0x00);

  fprintf (f, "\t.byte 0x%02X # OptionReg\n", 0xfc | i);
  fprintf (f, "\t.hword 0x%04X # manufacturer\n", d.ManufacturerCode);
  fprintf (f, "\t.hword 0x%04X # internal manufacturer\n",
	   d.InternalManufacturerCode);
  fprintf (f, "\t.hword 0x%04X # DevType\n", d.DeviceType);
  fprintf (f, "\t.byte 0x%02X # version\n", d.Version);
  if (d.BCU == BCU_bcu12)
    fprintf (f, "\t.byte _end_readonly-0x100 # CheckLim\n");
  else
    fprintf (f, "\t.byte 0x09 # CheckLim\n");
  fprintf (f, "\t.byte 0x%02X # PEI_Type\n", d.PEIType);
  fprintf (f, "\t.byte 0x%02X # SyncRate\n", d.SyncRate);
  fprintf (f, "\t.byte 0x%02X # PortCDDR\n", d.PortCDDR);
  fprintf (f, "\t.byte 0x%02X # PortADDR\n", d.PortADDR);
  fprintf (f, "\t.byte 0xFF # RunError\n");
  fprintf (f, "\t.byte 0x%02X # RouteCnt\n",
	   (d.RouteCount << 4) | (d.U_DELMSG ? 0x80 : 0x00));
  fprintf (f, "\t.byte 0x%02X # MaxRstCnt\n",
	   (d.BusyLimit << 5) | (d.INAKLimit << 0));

  if (d.BCU == BCU_bcu12)
    i = (d.AutoPLMA ? 0x00 : 0x01) | 0xA0;
  else
    i = (d.PLM_FAST ? 0x80 : 0x00) | 0x20;
  i |= (d.RateLimit_lineno ? 0x00 : 0x08);

  if (d.CPOL)
    i |= 0x04;
  if (d.CPHA)
    i |= 0x02;
  if (!d.A_Event)
    i |= 0x40;

  fprintf (f, "\t.byte 0x%02X # ConfigDes\n", i);

  if (d.BCU == BCU_bcu12)
    {
      fprintf (f, "\t.byte assoctab-0x100\n");
      fprintf (f, "\t.byte commobjs-0x100\n");
      fprintf (f, "\t.byte _UserInit-0x100\n");
      fprintf (f, "\t.byte _UserRun-0x100\n");
      fprintf (f, "\t.byte _UserSave-0x100\n");
    }
  else
    {
      fprintf (f, "\t.byte 0 #BCU1 pointer\n");
      fprintf (f, "\t.byte 0 #BCU1 pointer\n");
      fprintf (f, "\t.byte %s #RateLimit Pointer\n",
	       (d.RateLimit_lineno ? "_ratelimit_ptr-0x100+1" : "0"));
      fprintf (f, "\t.byte %s # Timer Pointer\n",
	       (d.UserTimer ? "_timer_ptr-0x100+1" : "0"));
      fprintf (f, "\t.byte %d # BCU2 Mark\n", 0);
    }
  if (d.RateLimit_lineno)
    fprintf (f,
	     "\t.section .ratelimit\n_ratelimit_ptr:\n\t.byte %d # RateLimit\n",
	     d.RateLimit);
  if (d.Debounces ())
    fprintf (f, "\t.section .debounce\n\t.hword 0\n");
  if (d.UserTimer)
    {
      fprintf (f, "\t.section .timerval\n");
      fprintf (f, "_timer_vals:\n");
      for (i = 0; i < d.Timers (); i++)
	if (d.Timers[i].Type == TM_UserTimer
	    || d.Timers[i].Type == TM_EnableUserTimer)
	  fprintf (f, "\t.global %s\n%s:\n\t.byte 0\n", d.Timers[i].Name (),
		   d.Timers[i].Name ());
      fprintf (f, "\t.section .timer\n");
      fprintf (f, "_timer_table:\n");
      fprintf (f, "\t.byte _timer_vals\n");
      for (i = 0; i < d.Timers (); i++)
	if (d.Timers[i].Type == TM_UserTimer
	    || d.Timers[i].Type == TM_EnableUserTimer)
	  {
	    if (d.Timers[i].TimerNo % 2)
	      {
		fprintf (f, "\t.byte 0x%x\n",
			 ((d.Timers[i].Resolution - TM_RES_133ms) << 4) | j);
	      }
	    else
	      j = (d.Timers[i].Resolution - TM_RES_133ms);
	  }
      if ((d.UserTimer % 2))
	fprintf (f, "\t.byte 0x%x\n", j);
      fprintf (f, "\t.section .timerptr\n");
      fprintf (f, "\t_timer_ptr:\n");
      fprintf (f, "\t.byte (_timer_table-0x100)\n");
    }
}

void
GenAsmEntry (FILE * f, Device & d)
{
  int i, j;

  fprintf (f, "\t.section .commobjs\n");
  fprintf (f, "commobjs:\n");
  fprintf (f, "\t.byte %d,ramflag_pointer\n", d.ObjCount);
  for (i = 0; i < d.GroupObjects (); i++)
    GenGroupObjectASM (f, d.GroupObjects[i], d.BCU);
  fprintf (f, "\t.section .ramflags\n");
  fprintf (f, "\t.global ramflag_pointer\n");
  fprintf (f, "ramflag_pointer:\n");
  j = d.ObjCount;
  if (j % 2)
    j++;
  j = j >> 1;
  for (i = 0; i < j; i++)
    fprintf (f, "\t.byte 0\n");

  fprintf (f, "\t.section .eibpeihandler\n");
  if (UsePEI (d))
    {
      fprintf (f, "peihandler:\n");
      fprintf (f, "\tsta __tmp_space\n");
      fprintf (f, "\tjmp _PEI_Handler_stub\n");
    }
  fprintf (f, "\t.section .eibobjects\n");
  fprintf (f, "eibobjects:\n");
  for (i = 0; i < d.Objects (); i++)
    fprintf (f, "\t.hword %s\n", d.Objects[i].Name ());
  for (i = 0; i < d.Objects (); i++)
    GenEIBObject (f, d.Objects[i]);

  fprintf (f, "\t.section .init\n");
  fprintf (f, "_UserInit:\n");
  fprintf (f, "\tjsr _initmem\n");
  if (d.on_init ())
    fprintf (f, "\tjmp %s_stub\n", d.on_init ());
  else
    fprintf (f, "\trts\n");
  fprintf (f, "_UserSave:\n");
  if (d.on_save ())
    {
      fprintf (f, "\tjsr _initstack\n");
      fprintf (f, "\tjmp %s_stub\n", d.on_save ());
    }
  else
    fprintf (f, "\trts\n");

  fprintf (f, "\t.section .init.1\n");
  fprintf (f, "_UserRun:\n");
  fprintf (f, "\tjsr _initstack\n");

  for (i = 0; i < d.GroupObjects (); i++)
    GenGroupObjectUpdate (f, d.GroupObjects[i]);

  for (i = 0; i < d.Timers (); i++)
    GenTimerUpdate (f, d.Timers[i]);

  if (d.on_run ())
    fprintf (f, "\tjmp %s_stub\n", d.on_run ());
  else
    fprintf (f, "\trts\n");
}

void
GenTestAsm (FILE * f, Device & d)
{
  GenBCUHeader (f, d);
  printPseudoAddrTab (f, d);

  GenAsmEntry (f, d);

  printParameterInfo (f, d);
}

void
GenRealAsm (FILE * f, Device & d)
{
  GenBCUHeader (f, d);
  printAddrTab (f, d);

  GenAsmEntry (f, d);
}

String
GetVariant (Device & d)
{
  char buf[1000];
  sprintf (buf, "bcu_%04x%s", d.BCU, d.Model_lineno ? d.Model () : "");
  return buf;
}
