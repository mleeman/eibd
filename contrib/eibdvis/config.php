<?php

$config = new Config ("GTK 2 status", "127.0.0.1");

$room = new Room ("living room");
$akt=new EIBDimmer("light A", "1/1/0", "1/1/10", "1/1/20", "1/1/30", "1/1/40");
$room->add($akt);
$akt=new EIBDimmer("light B", "1/1/1", "1/1/11", "1/1/21", "1/1/31", "1/1/41");
$room->add($akt);
$akt=new EIBDimmer("light C", "1/1/2", "1/1/12", "1/1/22", "1/1/32", "1/1/42");
$room->add($akt);
$akt=new EIBDimmer("light D", "1/1/3", "1/1/13", "1/1/23", "1/1/33", "1/1/43");
$room->add($akt);
$akt=new EIBBlind("Blind M1", "1/2/0", "1/2/2", "1/2/6", "");
$room->add($akt);


$config->addRoom($room);

$room = new Room ("office");
$akt=new EIBDimmer("light E", "1/1/4", "1/1/14", "1/1/24", "1/1/34", "1/1/44");
$room->add($akt);
$akt=new EIBDimmer("light F", "1/1/5", "1/1/15", "1/1/25", "1/1/35", "1/1/45");
$room->add($akt);
$akt=new EIBBlind("blind M2", "1/2/1", "1/2/3", "1/2/7", "");
$room->add($akt);
$akt=new EIBDimmer("light office", "1/1/201", "1/1/202", "", "", 0, 0);
$room->add($akt);

$config->addRoom($room);

$room = new Room ("studio");

$akt=new EIBDimmer("group 1", "3/0/1", "3/0/11", "3/0/31", "3/0/61", "3/0/41", 0, 60);
$room->add($akt);
$akt=new EIBDimmer("group 2", "3/0/2", "3/0/12", "3/0/32", "3/0/62", "3/0/42", 0, 60);
$room->add($akt);

$config->addRoom($room);

$room = new Room ("heating");

$akt=new EIBSwitch("comfort mode", "1/3/7", "1/3/7", 60);
$room->add($akt);
$akt=new EIBTemperature("room temperature", "1/3/4", "1/3/4", 0);
$room->add($akt);
$akt=new EIBTemperature("setpoint", "1/3/5", "1/3/5", 0);
$room->add($akt);
$akt=new EIBDimmer("heating", "", "", "", "1/3/10", "1/3/11", 0, 0);
$room->add($akt);
$akt=new EIBDimmer("cooling", "", "", "", "1/3/12", "1/3/13", 0, 0);
$room->add($akt);


$config->addRoom($room);

$room = new Room ("miscellaneous");

$akt=new EIBSwitch("master switch", "1/0/0", "", 0);
$room->add($akt);
$akt=new EIBSwitch("master switch living room", "1/0/1", "", 0);
$room->add($akt);
$akt=new EIBSwitch("all lighting", "1/1/200", "", 0);
$room->add($akt);
$akt=new EIBSwitch("wind alarm", "1/0/2", "1/0/2", 0);
$room->add($akt);

$config->addRoom($room);

?>
