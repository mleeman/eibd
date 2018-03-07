<?xml version="1.0" encoding="utf-8"?>
<!--
    Create a sample Configuration Description from a Application Information
    Copyright (C) 2005-2011 Martin Koegler mkoegler@auto.tuwien.ac.at

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

-->
<!-- version 0.0.0 -->
<xsl:transform xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
  <xsl:template xmlns:ai="http://www.auto.tuwien.ac.at/~mkoegler/eib/xml/appinfo.xsd" match="ai:DeviceDesc">
    <xsl:element name="DeviceConfig">
      <xsl:attribute name="version">
        <xsl:value-of select="@version"/>
      </xsl:attribute>
      <xsl:attribute name="xmlns">http://www.auto.tuwien.ac.at/~mkoegler/eib/xml/configdesc.xsd</xsl:attribute>
      <xsl:attribute namespace="http://www.w3.org/2001/XMLSchema-instance" name="schemaLocation">http://www.auto.tuwien.ac.at/~mkoegler/eib/xml/configdesc.xsd</xsl:attribute>
      <ProgramID>
        <xsl:value-of select="ai:ProgramID"/>
      </ProgramID>
      <PhysicalAddress>0.0.0</PhysicalAddress>
      <InstallKey>00000000</InstallKey>
      <Key id="1">00000000</Key>
      <xsl:for-each select="ai:GroupObject">
        <xsl:element name="GroupObject">
          <xsl:attribute name="id">
            <xsl:value-of select="@id"/>
          </xsl:attribute>
          <xsl:comment>
            <xsl:value-of select="ai:Title"/>
          </xsl:comment>
          <Priority>low</Priority>
          <SendAddress>0/0/0</SendAddress>
          <ReadRequestAddress>0/0/0</ReadRequestAddress>
          <ReceiveAddress>
            <GroupAddr>0/0/0</GroupAddr>
          </ReceiveAddress>
          <ReadAddress>
            <GroupAddr>0/0/0</GroupAddr>
          </ReadAddress>
          <UpdateAddress>
            <GroupAddr>0/0/0</GroupAddr>
          </UpdateAddress>
        </xsl:element>
      </xsl:for-each>
      <xsl:for-each select="ai:Property">
        <xsl:element name="Property">
          <xsl:attribute name="id">
            <xsl:value-of select="@id"/>
          </xsl:attribute>
          <xsl:comment>
            <xsl:value-of select="ai:Title"/>
          </xsl:comment>
          <Disable>false</Disable>
          <ReadOnly>false</ReadOnly>
          <ReadAccess>1</ReadAccess>
          <WriteAccess>1</WriteAccess>
        </xsl:element>
      </xsl:for-each>
      <xsl:for-each select="ai:PollingSlave">
        <xsl:element name="PollingSlave">
          <xsl:attribute name="id">
            <xsl:value-of select="@id"/>
          </xsl:attribute>
          <xsl:comment>
            <xsl:value-of select="ai:Title"/>
          </xsl:comment>
          <PollingAddress>0000</PollingAddress>
          <PollingSlot>0</PollingSlot>
        </xsl:element>
      </xsl:for-each>
      <xsl:for-each select="ai:PollingMaster">
        <xsl:element name="PollingMaster">
          <xsl:attribute name="id">
            <xsl:value-of select="@id"/>
          </xsl:attribute>
          <xsl:comment>
            <xsl:value-of select="ai:Title"/>
          </xsl:comment>
          <PollingAddress>0000</PollingAddress>
          <PollingCount>0</PollingCount>
        </xsl:element>
      </xsl:for-each>
      <xsl:for-each select="ai:Parameter">
        <Parameter>
          <xsl:for-each select="ai:ListParameter">
            <xsl:element name="ListParameter">
              <xsl:attribute name="id">
                <xsl:value-of select="@id"/>
              </xsl:attribute>
              <xsl:comment>
                <xsl:value-of select="ai:Title"/>
              </xsl:comment>
              <Value>
                <xsl:value-of select="ai:ListDefault/@idref"/>
              </Value>
            </xsl:element>
          </xsl:for-each>
          <xsl:for-each select="ai:IntParameter">
            <xsl:element name="IntParameter">
              <xsl:attribute name="id">
                <xsl:value-of select="@id"/>
              </xsl:attribute>
              <xsl:comment>
                <xsl:value-of select="ai:Title"/>
              </xsl:comment>
              <Value>
                <xsl:value-of select="ai:Default"/>
              </Value>
            </xsl:element>
          </xsl:for-each>
          <xsl:for-each select="ai:FloatParameter">
            <xsl:element name="FloatParameter">
              <xsl:attribute name="id">
                <xsl:value-of select="@id"/>
              </xsl:attribute>
              <xsl:comment>
                <xsl:value-of select="ai:Title"/>
              </xsl:comment>
              <Value>
                <xsl:value-of select="ai:Default"/>
              </Value>
            </xsl:element>
          </xsl:for-each>
          <xsl:for-each select="ai:StringParameter">
            <xsl:element name="StringParameter">
              <xsl:attribute name="id">
                <xsl:value-of select="@id"/>
              </xsl:attribute>
              <xsl:comment>
                <xsl:value-of select="ai:Title"/>
              </xsl:comment>
              <Value>
                <xsl:value-of select="ai:Default"/>
              </Value>
            </xsl:element>
          </xsl:for-each>
        </Parameter>
      </xsl:for-each>
    </xsl:element>
  </xsl:template>
</xsl:transform>
