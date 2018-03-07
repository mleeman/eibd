<?php
/*
    EIBD client library examples
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

class EIBSwitch implements Display {
  protected $title;
  protected $switchaddr;
  protected $stateaddr;
  protected $age;

  function __construct ($title, $switchaddr, $stateaddr, $age = 0)
    {
      $this->title=$title;
      $this->switchaddr = $switchaddr;
      $this->stateaddr = $stateaddr;
      $this->age = $age;
    }

  function display($con)
    {
      control_begin('switch', $this->title);
      if($this->stateaddr != "" && $r=fetchstats($con, $this->stateaddr, $this->age))
	{
	  if($r[0] & 1)
	    printf("On");
	  else
	    printf("Off");
	}
      control_main();
      if ($this->switchaddr != "")
	{
	  if(!$r || ($r[0] & 1))
	    send_form ("Off", $this->switchaddr, "small", 0);
	  if(!$r || !($r[0] & 1))
	    send_form ("On", $this->switchaddr, "small", 1);
	}
      control_end();
    }
}

class EIBDimmer implements Display {
  protected $title;
  protected $switchaddr;
  protected $dimmeraddr;
  protected $valueaddr;
  protected $switchstateaddr;
  protected $dimmerstateaddr;
  protected $switchage;
  protected $dimmerage;

  function __construct ($title, $switchaddr, $dimmeraddr, $valueaddr, $switchstateaddr, $dimmerstateaddr, $switchage = 0, $dimmerage = 0)
    {
      $this->title=$title;
      $this->switchaddr = $switchaddr;
      $this->dimmeraddr = $dimmeraddr;
      $this->valueaddr = $valueaddr;
      $this->switchstateaddr = $switchstateaddr;
      $this->dimmerstateaddr = $dimmerstateaddr;
      $this->switchage = $switchage;
      $this->dimmerage = $dimmerage;
    }

  function display($con)
    {
      control_begin('dimmer', $this->title);
      if ($this->switchstateaddr != "")
	$r = fetchstats ($con, $this->dimmerstateaddr, $this->dimmerage);
      if ($this->dimmerstateaddr != "")
	$r1 = fetchstats ($con, $this->switchstateaddr, $this->switchage);
      $off = -1;
      if ($r)
	{ 
	  if ($r[0] == 0 || ($r1 && ($r1[0] & 1) == 0))
	    {
	      print ("Off");
	      $off = 1;
	    }
	  else
	    {
	      printf("%d %%", ($r[0]*100)/255);
	      $off = 0;
	    }
	}
      else if($r1)
	{
	  if($r1[0] & 1)
	    {
	      printf("On");
	      $off = 0;
	    }
	  else
	    {
	      printf("Off");
	      $off = 1;
	    }
	}
      control_main();
      if ($this->switchaddr != "")
	{
	  if ($off != 1)
	    send_form ("Off", $this->switchaddr, "small", 0);
	  if ($off != 0)
	    send_form ("On", $this->switchaddr, "small", 1);
	}
      if ($this->dimmeraddr != "")
	{
	  send_form ("-", $this->dimmeraddr, "small", 1);
	  send_form ("Stop", $this->dimmeraddr, "small", 0);
	  send_form ("+", $this->dimmeraddr, "small", 9);
	}
      if ($this->valueaddr != "")
	send_form ("%", $this->valueaddr, "p1", ($r ? (int)($r[0]*100/255) : ($off == 1 ? 100: 0)), 1);

      control_end();
    }
}

class EIBBlind implements Display {
  protected $title;
  protected $blindaddr;
  protected $slataddr;
  protected $blindstateaddr;
  protected $slatstateaddr;
  protected $blindage;
  protected $slatage;

  function __construct ($title, $blindaddr, $slataddr, $blindstateaddr, $slatstateaddr, $blindage = 0, $slatage = 0)
    {
      $this->title=$title;
      $this->blindaddr = $blindaddr;
      $this->slataddr = $slataddr;
      $this->blindstateaddr = $blindstateaddr;
      $this->slatstateaddr = $slatstateaddr;
      $this->blindage = $blindage;
      $this->slatage = $slatage;
    }

  function display($con)
    {
      control_begin('blind', $this->title);
      if ($this->blindstateaddr != "")
	{
	  print "Blinds: ";
	  if ($r = fetchstats ($con, $this->blindstateaddr, $this->blindage))
	      printf("%d %%", ($r[0]*100)/255);
	}
      if ($this->slatstateaddr != "")
	{
	  print "Slat: ";
	  if ($r = fetchstats ($con, $this->slatstateaddr, $this->slatage))
	      printf("%d %%", ($r[0]*100)/255);
	}

      control_main();
      if ($this->blindaddr != "")
	{
	  print "Blinds: ";
	  send_form ("-", $this->blindaddr, "small", 0);
	  send_form ("+", $this->blindaddr, "small", 1);
	}
      if ($this->slataddr != "")
	{
	  print "Slats: ";
	  send_form ("-", $this->slataddr, "small", 0);
	  send_form ("+", $this->slataddr, "small", 1);
	}
      control_end();
    }
}

class EIBTemperature implements Display {
  protected $title;
  protected $tempaddr;
  protected $stateaddr;
  protected $age;

  function __construct ($title, $tempaddr, $tempstateaddr, $age = 0)
    {
      $this->title=$title;
      $this->tempaddr = $tempaddr;
      $this->stateaddr = $tempstateaddr;
      $this->age = $age;
    }

  function display($con)
    {
      control_begin('temp', $this->title);
      $temp = "20";
      if($this->stateaddr != "" && $r=fetchstats($con, $this->stateaddr, $this->age))
	{
	  if (count ($r) == 2)
	    {
	      $temp = f2_decode($r);
	      printf("%s °C", $temp);
	    }
	}
      control_main();
      if ($this->tempaddr != "")
	{
	  send_form ("Send", $this->tempaddr, "f2", $temp, 1);
	}
      control_end();
    }
}

?>