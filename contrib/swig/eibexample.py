#!/usr/bin/python
#
#Class based approach for using eibd client library - proof of concept
#Based on existing demo code coming with bcusdk 0.0.3 and later.
#Copyright (c) 2009 Marcel Gehrlein <m@rcel.de>
#
#This program is free software; you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation; either version 2 of the License, or
#(at your option) any later version.
#
#In addition to the permissions in the GNU General Public License,
#you may link the compiled version of this file into combinations
#with other programs, and distribute those combinations without any
#restriction coming from the use of this file. (The General Public
#License restrictions do apply in other respects; for example, they
#cover modification of the file, and distribution when not linked into
#a combine executable.)
#
#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License
#along with this program; if not, write to the Free Software
#Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#

from eibclient.common import readgaddr, individual2string
from eibclient.eibclient import EIBSocketURL, EIBClose, EIB_Cache_Read_Sync, \
                                EIBOpenT_Group, EIBSendAPDU

class EIB(object):
  def __init__(self,eibd='ip:192.168.1.11'):
    self.eibd = eibd
  
  def int2hex(self,i,l=0):
    h = ''
    lhi = len(hex(i))-2
    if lhi % 2: lhi += 1
    if l and (lhi < l*2):
      for p in range(1,l*2-lhi):
        h += '\x00'
    hi = hex(i)
    if len(hi) % 2: hi = hi.replace('0x','0x0')
    h += hi.replace('0x','\\x').decode('string_escape')
    return h

  def hex2int(self,h):
    hx = '0x'+h.encode('string_escape').replace('\\x','').replace('@','')
    return int(hx,16)

  def raw_cache_read_sync(self,dst):
    con = EIBSocketURL(self.eibd)
    res = EIB_Cache_Read_Sync(con,readgaddr(dst),0)
    EIBClose(con)
    return res

  def cache_read_sync(self,dst):
    '''Submit group address to get current state'''
    res = self.raw_cache_read_sync(dst)
    return (self.hex2int(res[2]) & 0x3f,individual2string(res[1]))

  def groupswrite(self,dst,val):
    '''Submit group address and new value'''
    con = EIBSocketURL(self.eibd)
    grp = EIBOpenT_Group(con,readgaddr(dst),1)
    if grp == -1: return grp
    res = EIBSendAPDU(con,self.int2hex(val | 0x80,2))
    EIBClose(con)
    return res

