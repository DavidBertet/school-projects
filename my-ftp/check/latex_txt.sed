#! /usr/bin/sed -f

s/\\/\\\\/g

s/&/\\&/g
s/_/\\_/g
s/#/\\#/g
s/~/\\~/g
s/%/\\%/g
s/{/\\{/g
s/}/\\}/g

s/^| \(.*\) |$/\\texttt{|~~\1~~|}/
/^\\texttt{/s/ /~/g

s/`.*`/\\textbf{\\textit{&}}/g
s/^*.*$/\\underline{&}/

s/$/\\newline/
