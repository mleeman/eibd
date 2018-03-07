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

include ("common.php");

html_header($config->title);

if ($_GET["addr"] != "" && $_GET["val"] != "" )
{
  $addr = $_GET["addr"];
  $typ = $_GET["typ"];
  $value = $_GET["val"];
  $res = -1;

  $con = $config->connect ();

  switch($typ)
    {
    case "small":
      $res=groupswrite ($con, $addr, $value);
      break;

    case "p1":
      if ($value < 0)
	$value = 0;
      if ($value > 100)
	$value = 100;
      $value = (int)(($value * 255) / 100 + 0.5);
      $res=groupwrite ($con, $addr, array ($value & 0xff));
      break;

    case "b1":
      $res=groupwrite ($con, $addr, array ($value & 0xff));
      break;

    case "b2":
      $res=groupwrite ($con, $addr, array (($value >> 8) & 0xff, $value & 0xff));
      break;

    case "f2":
      $res=groupwrite ($con, $addr, f2_encode($value));
      break;
    }

  if($res == -1)
    printf("<div class='result'>sending of %s to %s failed</div>", htmlentities($value), htmlentities($addr));
  else
    printf("<div class='result'>sent %s to %s </div>", htmlentities($value), htmlentities($addr));

}  
html_end();
?>
