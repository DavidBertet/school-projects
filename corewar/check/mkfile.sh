#! /bin/sh

if [ $# -ne 2 ]; then
    echo Usage: ./mkfile.sh folder name
    exit 1;
fi

filename="$1/$2.test";

echo "desc:" > $filename
echo "desc:"
read inside
if [ "$inside" != "" ]; then
    echo "$inside" >> $filename
fi
echo "in:" >> $filename
echo "in:"
read inside
if [ "$inside" != "" ]; then
    echo "$inside" >> $filename
fi
echo -n "out:" >> $filename
echo "out cmd:"
read inside
if [ "$inside" != "" ]; then
    echo " $inside" >> $filename
else
    echo >> $filename
    echo "out text:"
    read inside
    if [ "$inside" != "" ]; then
	echo "$inside" >> $filename
    fi
fi
echo "err:" >> $filename
echo "err:"
read inside
if [ "$inside" != "" ]; then
    echo "$inside" >> $filename
fi
echo "ret:" >> $filename
echo "ret:"
read inside
if [ "$inside" != "" ]; then
    echo "$inside" >> $filename
fi