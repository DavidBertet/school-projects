ARCHIVENAME=bertet_d-minishell

all:
	gmake -C ./src all

clean:
	gmake -C ./src clean
	find . -type d -exec clean '{}' ';'

distclean: clean
	rm -rf doc
	rm -f minishell

dist: distclean
	echo "* bertet_d" > AUTHORS
	mkdir ${ARCHIVENAME}/
	chmod 755 ${ARCHIVENAME}
	cp -r [!b]* ${ARCHIVENAME}
	tar cvjf ${ARCHIVENAME}.tar.bz2 ${ARCHIVENAME}
	rm -r ${ARCHIVENAME}
	md5 ${ARCHIVENAME}.tar.bz2

minishell: all

check: check1
	./check/moulinette.sh

check1: all

doc:
	doxygen Doxyfile

.PHONY: check