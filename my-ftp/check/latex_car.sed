#! /usr/bin/sed -f

s/\\/\\\\/g

s/&/\\&/g
s/_/\\_/g
s/#/\\#/g
s/~/\\~/g
s/%/\\%/g
s/{/\\{/g
s/}/\\}/g