CC = g++42
PACKAGE = calc
VERSION = a.0

BISON_FLAGS = --report=all
FLEXF=scanchess.ll
PARSEF=parsechess.yy
CCL=$(FLEXF:.ll=.cc)
CCP=$(PARSEF:.yy=.cc)
XSLTPROC = xsltproc
XSLTPROC_FLAGS = $$($(BISON) --print-datadir)/xslt/xml2xhtml.xsl
BISON=/u/all/acu/public/bin/bison
BISON_FLAGS=--report=all
FLEX=/usr/bin/flex
OBJECTS=$(SRC CCL CCP:.cc=.o)
CFLAGS = -Wall -Wextra -W
SRC = chessdriver.cc

all: chess

%.yy:%.cc
	$(BISON) $(BISON_FLAGS) $< -o ${CCP}

%.ll:%.cc
	$(FLEX) $<  -o${CCL}

%.o:%.cc
	$(BISON) $(BISON_FLAGS) $< -o ${CCP}
	$(FLEX) $(FLEX_FLAGS) $<  -o${CCL}
	${CC} ${CFLAGS} $< -o${OBJECTS}



chess:
	$(BISON) $(BISON_FLAGS) parsechess.yy -o parsechess.cc
	$(FLEX) $(FLEX_FLAGS)  -oscanchess.cc  scanchess.ll
	$(CC) ${CFLAGS}  ${SRC} scanchess.cc parsechess.cc  -o $@


clean:
	rm -rf location.hh
dist:
	cd .. && tar -cvjf fouqui_a-tc-0.tar.bz2 fouqui_a-tc-0

distcheck: dist