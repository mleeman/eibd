AUTOMAKE_OPTIONS=1.9
ACLOCAL_AMFLAGS = -I m4
EXTRA_DIST=bcusdk.spec SubmittingPatches .gitignore

if HAVE_ONLYEIBD
BUILDDIRS = 
else
BUILDDIRS = xml bcu bcugen archive build 
endif

SUBDIRS=. common eibd $(BUILDDIRS) debian contrib

BUILT_SOURCES=path.h
CLEANFILES=path.h

path.h : Makefile
	echo "#define PKGDATADIR \"${pkgdatadir}\"" >$@
	echo "#define PKGLIBDIR \"${pkglibdir}\"" >>$@
