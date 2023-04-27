# COMMAND eg: ./tac.sh test1.c
clear
lex parser.l
yacc parser.y
gcc y.tab.c -ll
./a.out $1