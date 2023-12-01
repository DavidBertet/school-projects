include makefile.rules

all : $(NAME_TARGET_DAEMON) $(NAME_TARGET_CLIENT)

.PHONY : check $(NAME_TARGET_DAEMON) $(NAME_TARGET_CLIENT)

$(NAME_TARGET_DAEMON) :
	cd src ; $(MAKE) ../$(NAME_TARGET_DAEMON)

$(NAME_TARGET_CLIENT) :
	cd src ; $(MAKE) ../$(NAME_TARGET_CLIENT)

check : $(NAME_TARGET_DAEMON) $(NAME_TARGET_CLIENT)
	echo Sorry

clean :
	find . -name "#*#" -delete
	find . -name "*~" -delete
	find . -name "*.core" -delete
	find . -name "*#*" -delete
	find . -name "*.tar.*" -delete
	find . -name "*.txt" -delete
	rm -Rf doc

distclean : clean
	find . -name "*.rules" -delete
	find . -name "*.o" -delete
	find . -name "*.a" -delete
	find . -name "*.so" -delete
	find . -name "*.exe" -delete
	find . -name "$(NAME_TARGET_DAEMON)" -delete
	find . -name "$(NAME_TARGET_CLIENT)" -delete

perm :
	chmod 750 `find .`
	chmod 640 `find . -name "*.c"`
	chmod 640 `find . -name "*.h"`
	chmod 640 `find . -name "AUTHORS"`
	chmod 640 `find . -name "README"`
	chmod 640 `find . -name "TODO"`
	chmod 640 `find . -name "ChangeLog"`
	chmod 640 `find . -name "Makefile"`

dist : perm distclean
	mkdir ../KTEMP
	mkdir ../KTEMP/$(NAME_DIR_TAR)
	chmod 750 ../KTEMP/$(NAME_DIR_TAR)
	cp -R * ../KTEMP/$(NAME_DIR_TAR)
	cd ../KTEMP && tar -cjf $(NAME_TAR) $(NAME_DIR_TAR) && rm -Rf $(NAME_DIR_TAR)
	mv ../KTEMP/$(NAME_TAR) .
	rmdir ../KTEMP

doc :
	mkdir doc
	chmod 750 doc
	echo "\documentclass [12 pt]{article} \setlength{\parindent}{0cm}" >> doc/doc.txt
	echo "\begin {document}" >> doc/doc.txt
	echo "\Huge Project : $(NAME_PROJECT) (EPITA'11/2009)\newline\newline" >> doc/doc.txt
	echo "\normalsize Hi, it's an automatic generated doc with Bash, LaTeX and Sed.\newline" >> doc/doc.txt
	echo "Doc-K version 0.58\newline" >> doc/doc.txt
	echo "Done by gallet\_c (gallet\_c@epita.fr).\newline\newline" >> doc/doc.txt
	echo "Date (of creation of the documentation) :\newline \today \newline \newline" >> doc/doc.txt
	echo "Team (from the AUTHORS file) :\newline" >> doc/doc.txt
	cat AUTHORS | check/latex_txt.sed >> doc/doc.txt
	echo "\newpage" >> doc/doc.txt
	cat ChangeLog | check/latex_txt.sed >>  doc/doc.txt
	echo "\newpage" >> doc/doc.txt
	cat TODO | check/latex_txt.sed >>  doc/doc.txt
	echo "\newpage" >> doc/doc.txt
	cat README | check/latex_txt.sed >>  doc/doc.txt
	echo "\newpage" >> doc/doc.txt
	cat $(HEADERS_DOC) | check/latex_car.sed | check/latex_h.sed >> doc/doc.txt
	echo "\textit{End of the documentation of $(NAME_PROJECT).} See you !" >> doc/doc.txt
	echo "\end {document}" >> doc/doc.txt
	cd doc ; pdflatex doc.txt

hi :
	echo "Hi !"
