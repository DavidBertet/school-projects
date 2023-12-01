#! /usr/bin/sed -nf

s/ s\\_[_[:alpha:]]*/\\textbf{\\textit{&}}/g
s/ u\\_[_[:alpha:]]*/\\textbf{\\textit{&}}/g
s/ g\\_[_[:alpha:]]*/\\textbf{\\textit{&}}/g
s/[[:alpha:]\\_-]*()/\\textbf{\\textit{&}}/g
s/[[:alpha:]\/\\_-]*\.h/\\textbf{&}/g

s/^\*\//\\newline/p
s/^\*\* \(.*\)/\1\\newline/p
s/^\\\#endif.*$/Was : documentation of a .h file.\\newpage/p
