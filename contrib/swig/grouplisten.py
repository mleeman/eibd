#!/usr/bin/env python
#! -O
#
# python equivalent for grouplisten, works same way


#
    #EIBD client library
    #Copyright (C) 2006 Tony Przygienda, Z2 GmbH

    #This program is free software; you can redistribute it and/or modify
    #it under the terms of the GNU General Public License as published by
    #the Free Software Foundation; either version 2 of the License, or
    #(at your option) any later version.

    #In addition to the permissions in the GNU General Public License,
    #you may link the compiled version of this file into combinations
    #with other programs, and distribute those combinations without any
    #restriction coming from the use of this file. (The General Public
    #License restrictions do apply in other respects; for example, they
    #cover modification of the file, and distribution when not linked into
    #a combine executable.)

    #This program is distributed in the hope that it will be useful,
    #but WITHOUT ANY WARRANTY; without even the implied warranty of
    #MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    #GNU General Public License for more details.

    #You should have received a copy of the GNU General Public License
    #along with this program; if not, write to the Free Software
    #Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#


import sys
import os
import getopt
import eibclient.eibclient
from eibclient.common import *

if __name__ == "__main__":

    if len(sys.argv) != 3:
        print "usage: %s url <group address>" % sys.argv[0];
        sys.exit(1);

    try:
        con = eibclient.eibclient.EIBSocketURL (sys.argv[1])
    except (Exception), e:
        print e
	
    for i in sys.argv[2:]:
	dest = readgaddr (i)
	if (eibclient.eibclient.EIBOpenT_Group (con, dest, 0) == -1):
	    print "Connect failed"
	    sys.exit(1);

    if con == None:
        print "Open failed";
        sys.exit(1);

    while 1:
        (result, buf, src) = eibclient.eibclient.EIBGetAPDU_Src (con)
        if len(buf) < 2:
            print "Read failed"
            sys.exit(1)
	if (ord(buf[0]) & 0x3 or (ord(buf[1]) & 0xc0) == 0xc0):
	    print"Unknown APDU from %s" % individual2string(src)

	ps = ""
	if (ord(buf[1]) & 0xC0) == 0:
	    ps = ps + "Read"
	elif (ord(buf[1]) & 0xC0) == 0x40:
	    ps = ps + "Response"
	elif (ord(buf[1]) & 0xC0) == 0x80:
	    ps = ps + "Write"
	else:
	    ps = ps + "???"
	    
	ps = ps + " from "
	ps = ps + individual2string (src);
	if (ord(buf[1]) & 0xC0):	
	    ps = ps + ": "
	    if result == 2:
		ps = ps + ( "%02X" % (ord(buf[1]) & 0x3F) )
	    else:
		printHex (len - 2, buf + 2);
	  
	print ps;

    eibclient.EIBClose (con)
