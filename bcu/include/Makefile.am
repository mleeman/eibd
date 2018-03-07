include ../VARIANT

BCU1_H=bcu_0012.h
BCU2_H=bcu_0020.h
COMMON_H=bcu_common.h grouptypes.h bcu_funcs.h types.h proptypes.h

BCU1_INC=bcu_0012.inc
BCU2_INC=bcu_0020.inc
COMMON_INC=bcu_common.inc

incdir=$(pkgdatadir)/include
dist_inc_HEADERS=$(COMMON_H) $(COMMON_INC) $(BCU1_H) $(BCU1_INC) $(BCU2_H) $(BCU2_INC) 

install-data-hook:
	$(mkinstalldirs) $(DESTDIR)$(incdir)
	cd $(top_srcdir)/bcu/include ; \
	for a in $(addsuffix .h,$(BCU_LIST)) $(addsuffix .inc,$(BCU_LIST)) ; do $(top_srcdir)/bcu/addmissing.sh $(DESTDIR)$(incdir) $$a; done
