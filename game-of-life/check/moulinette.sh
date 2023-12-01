#! /bin/bash

i=1
ok=1

while [ $ok -eq 1 ];
do
   i=$(($i + 1))

   ../jdv -vvv maps/map_fighter $i > test_mine
   /goinfre/acu/bin/jdv -vvv maps/map_fighter $i > test_ref

   echo $i

   if [ "`diff test_mine test_ref`" != "" ]; then
       ok=0
   fi
done

diff test_mine test_ref
echo "ERROR AT LOOP "$i