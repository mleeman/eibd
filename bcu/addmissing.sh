#!/bin/bash
#    BCU SDK bcu development enviroment - install helper
#    Copyright (C) 2005-2011 Martin Koegler <mkoegler@auto.tuwien.ac.at>
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

# searches replacement for missing (or equal) SDK files
# parameter: destdir installfilename

if [ $# != 2 ]; then
	echo wrong parameters
	exit 1
fi

F=$2

if [ ! -f $F ]; then
    
    prefix="`echo $F|sed -e 's/\([A-Za-z0-9]*_\).*/\1/g'`"
    last="`echo $F|sed -e 's/[A-Za-z0-9]*_\(.*\)/\1/g'`"

    base="`echo "$last" | sed -e 's/\([0-9A-Fa-f]\{4\}\)[^.]*\([.].*\)/\1\2/g'`"
    
    if [ -f "$prefix$base" ]; then
	echo "using $prefix$base for $F"
	
	cp "$prefix$base" "$1/$2" || exit 1
	
    else
	
	ext="`echo $base | sed -e 's/[0-9A-Fa-f]\{4\}\([.].*\)/\1/g'`"
	mask="`echo $base | sed -e 's/\([0-9A-Fa-f]\{4\}\)[.].*/\1/g'`"
	var="`echo $last | sed -e 's/[0-9A-Fa-f]\{4\}\([^.]*\)[.].*/\1/g'`"
	
	case "$mask" in
	    0021) mask="0020"  ;;
	    *) echo "unknown mask version $mask"
	       exit 1 ;;
	esac
    
	for a in "$mask"; do
	    
	    if [ -f "$prefix$a$var$ext" ]; then
		echo using "$prefix$a$var$ext for $F"
		
		cp "$prefix$a$var$ext" "$1/$2" || exit 1
		
		exit 0;
	    fi
	    
	    if [ -f "$prefix$a$ext" ]; then
		echo "using $prefix$a$ext for $F"
		
		cp "$prefix$a$ext" "$1/$2" || exit 1
		
		exit 0;
	    fi
	    
	done
	
	echo "no file found for $F"
	exit 1
	
    fi
fi

exit 0
