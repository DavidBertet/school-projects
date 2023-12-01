ARCHIVENAME=bertet_d-malloc

all:
	gmake -C ./src all

clean:
	gmake -C ./src clean
	gmake -C ./check clean
	find . -type d -exec clean '{}' ';'

distclean: clean
	rm -rf doc

dist: distclean
	echo "* bertet_d" > AUTHORS
	mkdir ${ARCHIVENAME}/
	chmod 755 ${ARCHIVENAME}
	cp -r [!b]* ${ARCHIVENAME}
	tar cvjf ${ARCHIVENAME}.tar.bz2 ${ARCHIVENAME}
	rm -r ${ARCHIVENAME}

libmalloc: all

check: check1
	./check/main
	echo "Now you can used ./check/test.sh 'BINARY' to launch a binary with my malloc"

check1: all
	gmake -C ./check all

doc:
	doxygen Doxyfile

.PHONY: check