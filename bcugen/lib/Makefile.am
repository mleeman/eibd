AM_CPPFLAGS=-I$(top_srcdir)/common -I$(top_srcdir)/bcugen/struct -I$(top_srcdir)/bcugen/configfile $(XML_CPPFLAGS)

noinst_LIBRARIES=libbcugen.a libcheck1.a libcheck2.a libcheck3.a
libbcugen_a_SOURCES=common.h common.cpp regexp.h regexp.cpp symboltab.h symboltab.cpp \
	map.cpp map.h write.cpp write.h classes.h classes.cpp scanner.h \
	xmlreadconfig.cpp xmlreadconfig.h xmlwriteappinfo.cpp xmlwriteappinfo.h \
	addrtab.h addrtab.cpp expr.h expr.cpp

libcheck1_a_SOURCES=check.cpp check.h gencode.cpp gencode.h
libcheck1_a_CPPFLAGS=-D CHECK1 -D BUILDMAX $(AM_CPPFLAGS)
libcheck2_a_SOURCES=check.cpp check.h gencode.cpp gencode.h
libcheck2_a_CPPFLAGS=-D CHECK2 $(AM_CPPFLAGS)
libcheck3_a_SOURCES=check.cpp check.h gencode.cpp gencode.h
libcheck3_a_CPPFLAGS=-D CHECK1 -D CHECK2 $(AM_CPPFLAGS)
