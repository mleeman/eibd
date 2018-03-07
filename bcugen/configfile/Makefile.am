DEF=class_gen.h class_init.h parser_gentoken.h parser_genunion.h parser_objectdesc.h scanner_gen.h write_gen.h class_init_ci.h
READ=parser.pre parser1.pre parser2.pre scanner.pre class_init_ci.h class_init.ci.cpp

dist_noinst_DATA=$(DEF)
EXTRA_DIST=parser.pre parser1.pre parser2.pre scanner.pre

AM_CPPFLAGS=-I$(top_srcdir)/common -I$(top_srcdir)/bcugen/struct -I$(top_srcdir)/bcugen/lib -I$(top_srcdir)/bcugen/configfile
AM_YFLAGS=-d
BUILT_SOURCES=parser1.post parser1.1.ypp parser1.1.h scanner.post scanner.1.lpp parser2.post parser2.1.ypp parser2.1.h
CLEANFILES=parser2.post parser1.post scanner.post scanner.1.lpp parser1.1.ypp parser1.1.h parser1.1.cpp parser2.1.ypp \
	parser2.1.h parser2.1.cpp scanner.1.cpp
noinst_LIBRARIES=libread1.a libread2.a

libread1_a_SOURCES=scanner.1.lpp parser1.1.ypp readconfig.cpp class_init_ci.cpp readconfig.h

libread2_a_SOURCES=scanner.1.lpp parser2.1.ypp readconfig.cpp class_init_ci.cpp readconfig.h

@AMDEP_TRUE@-@am__include@ @am__quote@./$(DEPDIR)/scanner.Po@am__quote@
@AMDEP_TRUE@-@am__include@ @am__quote@./$(DEPDIR)/parser1.Po@am__quote@
@AMDEP_TRUE@-@am__include@ @am__quote@./$(DEPDIR)/parser2.Po@am__quote@


%.1.lpp : %.post
	sed -e "s/YYinclude/#include/g" < $< > $@
%.1.ypp : %.post
	sed -e "s/YYinclude/#include/g" < $< > $@

.pre.post:
@am__fastdepCXX_TRUE@	if $(CXXCOMPILE) -D__cplusplus -MT $@ -MD -MP -MF "$(DEPDIR)/$*.Tpo" -E -P -x c -O0 -o $@ $<; \
@am__fastdepCXX_TRUE@	then mv -f "$(DEPDIR)/$*.Tpo" "$(DEPDIR)/$*.Po"; else rm -f "$(DEPDIR)/$*.Tpo"; exit 1; fi
@AMDEP_TRUE@@am__fastdepCXX_FALSE@	source='$<' object='$@' libtool=no @AMDEPBACKSLASH@
@AMDEP_TRUE@@am__fastdepCXX_FALSE@	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) @AMDEPBACKSLASH@
@am__fastdepCXX_FALSE@	$(CXXCOMPILE) -D__cplusplus -E -P -x c -O0 -o $@ $<
