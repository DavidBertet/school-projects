TARNAME=creff_n-chess

all:
	if [ ! -d build ]; then ./configure; fi
	cd build && gmake && mv chess ../ && mv libai/libai.so ../

chess:
	cd build && gmake && mv chess ../

ai:
	cd build && gmake && mv libai/libai.so ../

clean:
	find . -type d -exec clean '{}' ';'
	if [ -d build ]; then cd build && gmake clean; fi

# autocreate parser files
	rm -f src/parser/location.hh
	rm -f src/parser/position.hh
	rm -f src/parser/stack.hh
	rm -f src/parser/scanchess.cc
	rm -f src/parser/parsechess.cc
	rm -f src/parser/parsechess.hh

check: all
	cd check && ./test.pl -t 10

doc:
	doxygen doc/Doxyfile

distclean: clean
	rm -rf doc/html
	rm -rf build
	rm -rf chess
	rm -rf libai.so

dist: distclean put_right
	mkdir -p -m755 ../tar/${TARNAME}
	cp -r * ../tar/${TARNAME}
	cd ../tar && gtar -cvjf ../creff_n/${TARNAME}.tar.bz2 ${TARNAME} --exclude "\.svn"
	rm -rf ../tar
	echo -e "\033[33m$$(find $$(pwd) -name '*tar.bz2')\033[0m" && \
 echo -e "\033[31m$$(file $$(find $$(pwd) -name '*tar.bz2'))\033[0m" && \
 echo -e "\033[32m$$(md5 ${TARNAME}.tar.bz2)\033[0m"

put_right:
	find . -type d -exec chmod 755 '{}' ';'
	find . -type f -exec chmod 644 '{}' ';'
	chmod 755 configure
	chmod 755 check/test.pl

.PHONY: doc check
