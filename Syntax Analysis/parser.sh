# first parameter is the name of the test file in C
# COMMAND eg: ./parser.sh test1.c
lex parser.l
yacc -d parser.y
gcc y.tab.c -ll -w
./a.out $1