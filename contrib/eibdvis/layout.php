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

function html_header($title, $refresh = 0)
{
?>
<html>
  <head>
    <title><?php print htmlentities($title);?></title>
    <link rel="stylesheet" type="text/css" href="main.css" />
<?php
if ($refresh != 0)
  print "<meta http-equiv='refresh' content='$refresh' />";
?>
  </head>
  <body>
<?php
}

function html_end()
{
?>
  </body>
</html>
<?php
}

function send_form($title, $gaddr, $typ, $value, $edit = 0)
{
  printf('<form action="send.php" target="send" onsubmit="window.setTimeout(\'document.location.reload()\',1000)">');
  printf('<input type="hidden" name="typ" value="%s"/>',htmlentities($typ));
  printf('<input type="hidden" name="addr" value="%s"/>',htmlentities($gaddr));
  printf('<input type="%s" class ="%s" name="val" value="%s"/>',$edit?"text":"hidden",$edit?"text":"hidden",htmlentities($value));
  printf('<input type="submit" value="%s" class="button"/>',htmlentities($title));
  printf('</form>');
}

function control_begin($typ, $title)
{
  printf('<div class="%s"><h2>%s</h2><div class="stats">',htmlentities($typ),htmlentities($title));
}

function control_main()
{
  printf('</div><div class="actions">');
}

function control_end()
{
  printf('</div></div>');
}

function fetchstats($con, $addr, $age)
{
  $res=cacheread($con, $addr, $age);
  if($res[1]==-1)
    {
      printf("EIBD not usable");
      return false;
    }
  if($res[1]==-2)
    {
      printf("not readable");
      return false;
    }
  if($res[1]==-3)
    {
      printf("unknown status");
      return false;
    }
  return array_slice($res, 2);
}

?>
