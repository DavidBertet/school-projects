#!/bin/bash

../pit $1 || echo -e "\033[32mOur pit KO\033[0m"

cor=$(echo $1 | sed 's/\.s$/.cor/')

mv $cor tmp1

/goinfre/acu/bin/pit $1 || echo -e "\033[32mRef pit KO\033[0m"

mv $cor tmp2

diff tmp1 tmp2

res=$?

if [ $res -ne 0 ] ; then
    echo -e "\033[31m\tERROR ON FILE : $1\033[0m"
fi

rm -rf tmp1 tmp2

exit $res
