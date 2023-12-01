all:
	if [ ! -d build ]; then ./configure; fi
	cd build && make && mv jdv ../

jdv:
	cd build && make && mv jdv ../

clean:
	find . -type d -exec clean '{}' ';'
	if [ -d build ]; then cd build && make clean; fi

check: all
	cd check && ./test.pl -t 10

doc:
	doxygen doc/Doxyfile

distclean: clean
	rm -rf doc/html
	rm -rf build

dist: distclean
	mkdir bertet_d-jdv
	cp -r [!b]* bertet_d-jdv
	gtar -cvjf bertet_d-jdv.tar.bz2 bertet_d-jdv
	rm -rf bertet_d-jdv
	md5 bertet_d-jdv.tar.bz2

.PHONY: doc