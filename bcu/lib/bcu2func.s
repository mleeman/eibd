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
	.global AL_SAPcallback, EE_WriteBlock, U_GetAccess, U_SetPollingRsp, U_Char_Out
	.global U_TS_Set, U_TS_Del, U_TS_Seti, U_MS_Post, U_MS_Switch, FP_Flt2Int, FP_Int2Flt
	.global U_FT12_Reset, U_FT12_GetStatus, U_SCI_Init, U_SPI_Init
	.global PEI_Interface, PEI_Info, PEI_SndBuf, PEI_RecBuf
#only with mask version 2.1
	.global U_EE_WriteHI

#mask-version 2.x
	.set OR_TAB,		0x0020
	.set AND_TAB,		0x0028
	.set U_flagsGet,	0x505A
	.set U_flagsSet,	0x505D
	.set U_testObj,		0x507B
	.set U_transRequest,	0x507E
	.set EEwrite,		0x503F
	.set EEsetChecksum,	0x503C
	.set U_debounce,	0x5051
	.set U_deb10,		0x504B
	.set U_deb30,		0x504E
	.set U_delMsgs,		0x5057
	.set U_readAD,		0x506C
	.set U_map,		0x5069
	.set U_ioAST,		0x5066
	.set S_AstShift,	0x5042
	.set S_LAstShift,	0x5045
	.set U_SerialShift,	0x5048
	.set TM_Load,		0x5039
	.set TM_GetFlg,		0x5036
	.set U_SetTM,		0x506F
	.set U_GetTM,		0x5060
	.set U_SetTMx,		0x5072
	.set U_GetTMx,		0x5063
	.set U_Delay,		0x5054
	.set AllocBuf,		0x5000
	.set FreeBuf,		0x5006
	.set PopBuf,		0x5003
	.set multDE_FG,		0x5033
	.set divDE_BC,		0x5030
	.set shlA4,		0x5018
	.set shlA5,		0x501B
	.set shlA6,		0x501E
	.set shlA7,		0x5021
	.set shrA4,		0x5024
	.set shrA5,		0x5027
	.set shrA6,		0x502A
	.set shrA7,		0x502D
	.set rolA1,		0x5009
	.set rolA2,		0x500C
	.set rolA3,		0x500F
	.set rolA4,		0x5012
	.set rolA7,		0x5015
	.set U_SetBit,		0x5078
	.set U_GetBit,		0x5075
	
	.set AL_SAPcallback,	0x5081
	.set U_EE_WriteBlock,	0x5099
	.set U_GetAccess,	0x5096
	.set U_SetPollingRsp,	0x50AE
	.set U_Char_Out,	0x508A
	.set U_TS_Set,		0x5090
	.set U_TS_Del,		0x5093
	.set U_TS_Seti,		0x50AB
	.set U_MS_Post,		0x508D
	.set U_MS_Switch,	0x508A
	.set FP_Flt2Int,	0x5087
	.set FP_Int2Flt,	0x5084
	.set U_FT12_Reset,	0x509C
	.set U_FT12_GetStatus,	0x509F
	.set U_SCI_Init,	0x50A2
	.set U_SPI_Init,	0x50A5

	.set PEI_Interface,     0x00C4
	.set PEI_Info,          0x00C5
	.set PEI_RecBuf,        0x098A
	.set PEI_SndBuf,        0x09A3
		
#mask-version 2.1
	.set U_EE_WriteHI,	0x50B2
	
