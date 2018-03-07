Name:           bcusdk
Version:        0.0.5
Release:        1
Summary:        BCU SDK

Group:          Development/Tools
License:        GPL
URL:            http://www.auto.tuwien.ac.at/~mkoegler/index.php/bcusdk
Source0:        bcusdk_%{version}.tar.gz
BuildRoot:      %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

BuildRequires:  libxml2-devel, gcc-c++, make, flex, bison, libpthsem-devel, m68hc05-gcc, gcc-java, indent
%if 0%{?suse_version} > 910
BuildRequires:  fastjar 
%endif
Requires:       eibd-server, eibd-clients, eibd-client-sources, libeibclient-devel, bcusdk-build

%description
A SDK to develop application for EIB BCU 1 and 2.

%package -n eibd-server
Summary:       eibd server
Group:         Development/Tools

%description -n eibd-server
eibd is a daemon, which supports connection to an EIB bus over various
access devices and provide its services over TCP/IP or Unix domain sockets.
Note: Some backends may crash Linux 2.6 kernels before 2.6.11.

%package -n eibd-clients
Summary: eibd clients
Group:         Development/Tools

%description -n eibd-clients
provides simple example programs to perform some management task on a EIB system.

%package -n libeibclient0
Summary: eibd client library
Group:         Development/Tools

%description -n libeibclient0
provides a simple client library written in C to access the EIB bus over eibd.

%package -n libeibclient-devel
Summary: eibd client library
Requires: libeibclient0
Group:         Development/Tools

%description -n libeibclient-devel
provides a simple client library written in C to access the EIB bus over eibd.

%package -n eibd-client-sources
Summary: sources of the eibd client programs
Group:         Development/Tools

%description -n eibd-client-sources
provides the source of the eibd client programs as examples how to use
the eibd client library.

%package -n bcusdk-build
Requires: m68hc05-gcc, libxslt
Summary: BCU SDK image building programs
Group:         Development/Tools

%description -n bcusdk-build
contains all files and programs to build BCU images

# no debug package + strip
%define __spec_install_post %{nil}
%define debug_package %{nil}


%prep
%setup -q -n bcusdk-%{version}


%build
%configure --enable-ft12 --enable-pei16 --enable-tpuart --enable-pei16s --enable-tpuarts \
   --enable-eibnetip --enable-eibnetipserver --enable-eibnetiptunnel --enable-usb --enable-groupcache --enable-java
make %{?_smp_mflags}


%install
rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT


%clean
rm -rf $RPM_BUILD_ROOT

%post   -n libeibclient0 -p /sbin/ldconfig

%postun -n libeibclient0 -p /sbin/ldconfig

%files
%defattr(-,root,root,-)
%doc README

%files -n bcusdk-build
%defattr(-,root,root,-)
/usr/share/bcusdk/include
/usr/share/bcusdk/ldscripts
/usr/share/bcusdk/xml
%{_libdir}/bcusdk/lib
/usr/bin/build.ai
/usr/bin/build.img
/usr/bin/build.dev
/usr/bin/bcugen1
/usr/bin/bcugen2
/usr/bin/bcugen3
/usr/bin/embedprogid
/usr/bin/extractprogid
/usr/bin/gencitemplate
/usr/bin/viewimage
/usr/bin/loadimage
/usr/bin/imageedit
/usr/share/bcusdk/examples/*.xml

%files -n eibd-server
%defattr(-,root,root,-)
/usr/bin/eibd
/usr/bin/bcuaddrtab
/usr/bin/bcuread
/usr/bin/eibnetdescribe
/usr/bin/eibnetsearch
/usr/bin/findknxusb

%files -n eibd-clients
%defattr(-,root,root,-)
/usr/bin/busmonitor1
/usr/bin/busmonitor2
/usr/bin/vbusmonitor1
/usr/bin/vbusmonitor1poll
/usr/bin/vbusmonitor2
/usr/bin/groupread
/usr/bin/groupswrite
/usr/bin/groupwrite
/usr/bin/groupsresponse
/usr/bin/groupresponse
/usr/bin/grouplisten
/usr/bin/madcread
/usr/bin/maskver
/usr/bin/mmaskver
/usr/bin/mread
/usr/bin/mwrite
/usr/bin/mprogmodeon
/usr/bin/mprogmodeoff
/usr/bin/mprogmodestatus
/usr/bin/mprogmodetoggle
/usr/bin/progmodeon
/usr/bin/progmodeoff
/usr/bin/progmodestatus
/usr/bin/progmodetoggle
/usr/bin/mpropdesc
/usr/bin/mpropread
/usr/bin/mpropwrite
/usr/bin/mpropscan
/usr/bin/mpropscanpoll
/usr/bin/readindividual
/usr/bin/writeaddress
/usr/bin/mpeitype
/usr/bin/msetkey
/usr/bin/groupsocketlisten
/usr/bin/groupsocketread
/usr/bin/groupsocketwrite
/usr/bin/groupsocketswrite
/usr/bin/groupreadresponse
/usr/bin/groupcacheenable
/usr/bin/groupcachedisable
/usr/bin/groupcacheclear
/usr/bin/groupcacheremove
/usr/bin/groupcachereadsync
/usr/bin/groupcacheread
/usr/bin/groupcachelastupdates
/usr/bin/mrestart
/usr/bin/mwriteplain
/usr/bin/knxtool
/usr/bin/xpropread
/usr/bin/xpropwrite

%files -n libeibclient0
%defattr(-,root,root,-)
%{_libdir}/libeibclient.so.*

%files -n libeibclient-devel
%defattr(-,root,root,-)
/usr/include/*
%{_libdir}/libeibclient.la
%{_libdir}/libeibclient.a
%{_libdir}/libeibclient.so
/usr/share/bcusdk/eibclient.php
/usr/share/bcusdk/EIBConnection.cs
/usr/share/bcusdk/EIBConnection.pm
/usr/share/bcusdk/EIBConnection.py
/usr/share/bcusdk/EIBD.pas
/usr/share/java/eibclient.jar

%files -n eibd-client-sources
%defattr(-,root,root,-)
/usr/share/bcusdk/examples/*.c
/usr/share/bcusdk/examples/*.h


%changelog
* Sat Jul 30 2005 Martin Koegler <mkoegler@auto.tuwien.ac.at> - 0:0.0.0-3
- first version
