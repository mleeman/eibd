#SWIG extensions
PYTHON_VERSION=$(shell echo -e "import sys\nprint sys.version[:3]" |python -)
PYTHON_LIB=/usr/lib/python$(PYTHON_VERSION)
PYTHON_INCLUDE=/usr/include/python$(PYTHON_VERSION)

swig: _eibclient.so 

eibclient_wrap.o: eibclient_wrap.c 
	$(CC) -fPIC -I$(PYTHON_INCLUDE) -I../../eibd/include -I../../common $< -c -o $@

eibclient_wrap.c: eibclient.i
	swig -python $(AM_CPPFLAGS) -I../../eibd/include -I../../common eibclient.i
	ln eibclient.py eibclient

_eibclient.so: eibclient_wrap.o
	$(CC)  -fPIC -shared $(AM_CPPFLAGS) -I../../eibd/include -I../../common $(SOURCES) $< -o $@ -L../../eibd/client/c -leibclient

swig_clean:
	-rm -f _eibclient.so eibclient.pyc \
		eibclient.py eibclient_wrap.c \
		eibclient_wrap.o eibclient/eibclient.py

install:
	strip _eibclient.so
	cp _eibclient.so $(PYTHON_LIB)/site-packages/
	python ./setup.py install
