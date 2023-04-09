%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include <math.h>

    /*
        Lexical Analysis [5 marks]- For this phase, write a LEX program that broked down the input program into 
        tokens (identifiers, operators, numbers, keywords, punctuators). A symbol table is created with the list of 
        tokens obtained from the input. Also, report if any printf and scanf statements are in the given program.
    */

    /*
        1. Type: int, float, char 
        2. Basic statements: expression statement, assignment statements, and compound statements, declaration statement. 
        3. Control and looping statements: if statement, for statement, while statement, and switch statement. (note that nesting of these statements is also possible.) 
        4. System functions: printf and scanf statements. 
        5. Other: Variables, arrays, and function
    */
    #define AUTO 1
    #define BREAK 2
    #define CHAR 3
    #define CASE 4
    #define CONTINUE 5
    #define CONST 6
    #define DOUBLE 7
    #define DO 8
    #define DEFAULT 9
    #define EXTERN 10
    #define ELSE 11
    #define ENUM 12
    #define FOR 13
    #define FLOAT 14
    #define GOTO 15
    #define INT 16
    #define IF 17
    #define LONG 18
    #define RETURN 19
    #define REGISTER 20
    #define SWITCH 21
    #define STATIC 22
    #define SIGNED 23
    #define SIZEOF 24
    #define SHORT 25
    #define STRUCT 26
    #define TYPEDEF 27
    #define UNSIGNED 28
    #define UNION 29
    #define VOLATILE 30
    #define VOID 31
    #define WHILE 32

    #define IDENTIFIER 33
    #define SLC 34
    #define MLCE 35
    #define MLCS 36

    #define GEQ 37
    #define LEQ 38
    #define NEQ 39
    #define EQEQ 40
    #define LAND 41
    #define LOR 42
    #define PLUS 43
    #define ASSIGN 44
    #define MULT 45
    #define SUB 46
    #define MOD 47
    #define DIV 48
    #define GREATER 49
    #define LESSER 50
    #define DECR 51
    #define INCR 52

    #define SEMI 53
    #define COMMA 54

    #define MAIN 55
    #define HEADER 56

    #define SCANF 57
    #define PRINTF 58
    #define DEFINE 59

    #define INT_CONST 60
    #define FLOAT_CONST 61

    #define TYPE_SPEC 62

    #define DQ 63

    #define OBC 64
    #define OBO 65
    #define CBC 66
    #define CBO 67
    #define HASH 68

    #define FUNC 69
    #define ARR 70

    #define UNKNOWN 71
    #define NUM_ERR 72

    #define STRING_CONST 73
    #define CHAR_CONST 74
    #define SIGNED_CONST 75

    int line_number = 1;
%}

alpha [a-zA-Z]
digit [0-9]
underline [_]
space [ ]
tab [   ]
newline [\n]
char \'.\'
at [@]
string \"(.^([%d]|[%f]|[%s]|[%c]))\"

%%

{space}*    {}
{tab}*      {}
{string}    {return STRING_CONST;}
{char}      {return CHAR_CONST;}
{line}      {line_number++;}
auto        {return AUTO;}
break       {return BREAK;}



%%

int yywrap() {
    return 1;
}

int main(void)
{
    yylex();
    return 0;
}