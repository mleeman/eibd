#    BCU SDK bcu development enviroment
#    Copyright (C) 2005-2011 Martin Koegler <mkoegler@auto.tuwien.ac.at>
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    In addition to the permissions in the GNU General Public License, 
#    you may link the compiled version of this file into combinations
#    with other programs, and distribute those combinations without any 
#    restriction coming from the use of this file. (The General Public 
#    License restrictions do apply in other respects; for example, they 
#    cover modification of the file, and distribution when not linked into 
#    a combine executable.)
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

	.global OR_TAB, AND_TAB, U_flagsGet, U_flagsSet, U_testObj, U_transRequest
	.global EEwrite, EEsetChecksum, U_debounce, U_deb10, U_deb30, U_delMsgs
	.global U_readAD, U_map, U_ioAST, S_AstShift, S_LAstShift, U_SerialShift
	.global	TM_Load, TM_GetFlg, U_SetTM, U_GetTM, U_Delay, AllocBuf, FreeBuf
	.global PopBuf, multDE_FG, divDE_BC, shlA4, shlA5, shlA6, shlA7, shrA4
	.global	shrA5, shrA6, shrA7, rolA1, rolA2, rolA3, rolA4, U_SetBit, U_GetBit
	.global U_SetTMx, U_GetTMx, rolA7

#mask-version 1.2
	.set OR_TAB,		0x0020
	.set AND_TAB,		0x0028
	.set U_flagsGet,	0x0C9D
	.set U_flagsSet,	0x0CB3
	.set U_testObj,		0x0CA5
	.set U_transRequest,	0x0DB9
	.set EEwrite,		0x0C38
	.set EEsetChecksum,	0x0C68
	.set U_debounce,	0x0C75
	.set U_deb10,		0x0C73
	.set U_deb30,		0x0C6F
	.set U_delMsgs,		0x0C93
	.set U_readAD,		0x0D54
	.set U_map,		0x0CBA
	.set U_ioAST,		0x0DCF
	.set S_AstShift,	0x1117
	.set S_LastShift,	0x1115
	.set U_SerialShift,	0x0C90
	.set TM_Load,		0x0E2B
	.set TM_GetFlg,		0x0E49
	.set U_SetTM,		0x0DB2
	.set U_GetTM,		0x0D71
	.set U_SetTMx,		0x0DAF
	.set U_GetTMx,		0x0D6C
	.set U_Delay,		0x0DFA
	.set AllocBuf,		0x117E
	.set FreeBuf,		0x11A0
	.set PopBuf,		0x11C0
	.set multDE_FG,		0x0B4B
	.set divDE_BC,		0x0B0B
	.set shlA4,		0x0BA9
	.set shlA5,		0x0BA8
	.set shlA6,		0x0BA7
	.set shlA7,		0x0BA6
	.set shrA4,		0x0BE9
	.set shrA5,		0x0BE8
	.set shrA6,		0x0BE7
	.set shrA7,		0x0BE6
	.set rolA1,		0x0AF4
	.set rolA2,		0x0AF2
	.set rolA3,		0x0AF0
	.set rolA4,		0x0AEE
	.set rolA7,		0x0AEC
	.set U_SetBit,		0x0E18
	.set U_GetBit,		0x0E0C
	
