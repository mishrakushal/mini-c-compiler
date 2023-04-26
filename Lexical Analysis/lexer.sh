# COMMAND EG: ./lexer.sh
lex lexer.l
cc lex.yy.c -ll
./a.out 