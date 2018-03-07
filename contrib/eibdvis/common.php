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

include_once('eibclient.php');
include_once('help.php');
include_once('layout.php');

interface Display {
  function display($con);
}

class Room {
  public $title;
  public $ent;

  function __construct ($title)
    {
      $this->title = $title;
      $this->ent = array();
    }

  function add(Display $ent)
    {
      $this->ent[] = $ent;
    }
}

class Config {
  public $title;
  public $hostname;
  public $rooms;
 
  private $connection;

    function __construct ($title, $hostname)
    {
      $this->title=$title;
      $this->hostname=$hostname;
      $this->connection = -1;
      $this->rooms = array();
    }
    
    function connect()
      {
	if ($this->connection !== -1)
	  return $this->connection;

	$this->connection = new EIBConnection($this->hostname);
	$this->connection->EIB_Cache_Enable ();
	return $this->connection;
      }
	
    function addRoom($room)
      {
	$this->rooms[]=$room;
      }

}

include_once("elements.php");

include_once("config.php");

?>
