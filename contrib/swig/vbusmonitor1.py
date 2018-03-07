#!/usr/bin/env python
#! -O
#
# python equivalent for vmonitor1, works same way


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


import sys
import os
import getopt
import eibclient.eibclient
from eibclient.common import *

if __name__ == "__main__":

    if len(sys.argv) != 2:
        print "usage: %s url" % sys.argv[0];
        sys.exit(1);

    try:
        con = eibclient.eibclient.EIBSocketURL (sys.argv[1])
    except (Exception), e:
        print e

    if con == None:
        print "Open failed";
        sys.exit(1);

    if eibclient.eibclient.EIBOpenVBusmonitorText (con) == -1:
        print "Open Busmonitor failed"
        sys.exit(1)
    
    while 1:
        buf = eibclient.eibclient.EIBGetBusmonitorPacket (con)
        if len(buf) == 0:
            print "Read failed"
            sys.exit(1)
        print "%s" % buf

    eibclient.EIBClose (con)
