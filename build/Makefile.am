BINDIR=$(bindir)
LIBDIR=$(pkglibdir)/lib
LDDIR=$(pkgdatadir)/ldscripts
INCDIR=$(pkgdatadir)/include
XMLDIR=$(pkgdatadir)/xml

do_subst = sed -e 's,[@]VERSION[@],$(VERSION),g' \
                 -e 's,[@]TAS[@],$(TAS),g' \
                 -e 's,[@]TLD[@],$(TLD),g' \
                 -e 's,[@]TGCC[@],$(TGCC),g' \
                 -e 's,[@]TRANLIB[@],$(TRANLIB),g' \
                 -e 's,[@]TAR[@],$(TAR),g' \
                 -e 's,[@]LDDIR[@],$(LDDIR),g' \
                 -e 's,[@]LIBDIR[@],$(LIBDIR),g' \
                 -e 's,[@]INCDIR[@],$(INCDIR),g' \
                 -e 's,[@]BINDIR[@],$(BINDIR),g' \
                 -e 's,[@]XMLDIR[@],$(XMLDIR),g'

SCRIPT=build.ai build.img build.dev gencitemplate
EXTRA_DIST=build.ai.in build.img.in build.dev.in gencitemplate.in

bin_SCRIPTS=$(SCRIPT)
CLEANFILES=$(SCRIPT)

% : $(srcdir)/%.in Makefile
	$(do_subst) < $<  > $@
	chmod a+x $@

