# COMMAND eg: ./parser.sh test1.c
clear
lex parser.l
yacc -d parser.y
cc y.tab.c -ll -w
./a.out $1