#! /bin/bash

ERR=0;

function print_green
{
    set_color -o green
    echo -n "$1"
    set_color normal
}

function print_red
{
    set_color -o red
    echo -n "$1"
    set_color normal
}

function print_yellow
{
    set_color -o yellow
    echo "$1"
    set_color normal
}

function test_cmd
{
    set_color -o cyan
    echo "$1"
    set_color normal
    echo "$1" | ./minishell > tmp1 2> tmp1_err
    RET1=$?
    echo "$1" | bash  > tmp2 2> tmp2_err
    RET2=$?
    if diff tmp1 tmp2 > /dev/null && diff tmp1_err tmp2_err > /dev/null; then
	print_green "Test reussi -->  "
    else
	print_red "Test rate -->  "
	echo
	diff tmp1 tmp2
	diff tmp1_err tmp2_err
	ERR=$(($ERR + 1));
    fi
    if [ $RET1 -eq $RET2 ]; then
	print_green "Retour OK"
    else
	print_red "Retour KO"
    fi
    echo
}

print_yellow "----- DEBUT DU TEST ------"
print_yellow "----- NIVEAU 1 ------"
test_cmd "echo"
test_cmd "ls"
test_cmd "ls | grep a || grep b"
test_cmd "ns_who -Alg | grep epita_2011 | grep sm"
test_cmd "ls || pwd && ls; echo coucou || ls ; ls; ls"
test_cmd "ls||pwd&&ls;echo coucou||ls;ls;ls"

print_yellow "----- NIVEAU 2 ------"

test_cmd "< README cat -n"
test_cmd "echo coucou >> toto"
test_cmd "> titi echo > toto coucou > tata"
test_cmd "ls>toto"

print_yellow "------- NIVEAU 3 -------"
test_cmd 'echo $HOME'
test_cmd 'pwd -P'
test_cmd 'cd && ls'
test_cmd 'export PS1=42sh$ && echo $PS1'
test_cmd 'exit'
test_cmd 'exit 42'
print_yellow "------- FIN DU TEST -------"
print_yellow $ERR" errors"

rm -f tmp1 tmp2 tmp1_err tmp2_err toto tata titi