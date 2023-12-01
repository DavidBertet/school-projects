all:
	if [ ! -d build ]; then ./configure; fi
	cd build && gmake && cp pit ../ && cp track ../

track:
	cd build && gmake track && cp track ../

pit:
	cd build && gmake pit && cp pit ../

clean:
	find . -type d -exec clean '{}' ';'
	if [ -d build ]; then cd build && gmake clean; fi

check: all
	cd check && ./test.pl

ocheck: check
	firefox check/index.html

doc:
	doxygen doc/Doxyfile

distclean: clean
	rm -rf doc/html
	rm -rf build
	rm -rf track
	rm -rf pit
	rm -rf bertet_d-corewar.tar.bz2 ../tar/bertet_d-corewar

dist: distclean put_right
	mkdir -p -m755 ../tar/bertet_d-corewar
	cp -r * ../tar/bertet_d-corewar
	cd ../tar && gtar -cvjf ../bertet_d-corewar/bertet_d-corewar.tar.bz2 \
bertet_d-corewar --exclude "\.svn"
	rm -rf ../tar
	echo -e "\033[33m$$(find $$(pwd) -name '*tar.bz2')\033[0m" && \
echo -e "\033[31m$$(file $$(find $$(pwd) -name '*tar.bz2'))\033[0m" && \
echo -e "\033[32m$$(md5 bertet_d-corewar.tar.bz2)\033[0m"

distcheck: dist
	gtar -xjf bertet_d-corewar.tar.bz2 --exclude "\.svn"
	touch tmp_err && cd bertet_d-corewar && ./configure &&\
gmake check 2> tmp_err && rm -rf bertet_d-corewar
	gtar -tvjf bertet_d-corewar.tar.bz2 bertet_d-corewar --exclude "\.svn"
	rm -rf bertet_d-corewar
	echo -e "\033[31m$$(cat tmp_err)\033[0m" && rm -rf tmp_err
	echo -e "\033[33m$$(find $$(pwd) -name '*tar.bz2')\033[0m" && \
echo -e "\033[31m$$(file $$(find $$(pwd) -name '*tar.bz2'))\033[0m" && \
echo -e "\033[32m$$(md5 bertet_d-corewar.tar.bz2)\033[0m"

put_right:
	find . -type d -exec chmod 755 '{}' ';'
	find . -type f -exec chmod 644 '{}' ';'
	chmod 755 configure
	chmod 755 check/test.pl
	chmod 755 check/diff.sh
.PHONY: doc pit track

