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
tab [	]
newline [\n]
char \'.\'
at [@]
string \"(.^([%d]|[%f]|[%s]|[%c]))\"

%%

{space}*    {}
{tab}*      {}
{string}    {return STRING_CONST;}
{char}      {return CHAR_CONST;}
{newline}   {line_number++;}
auto        {return AUTO;}
break       {return BREAK;}
case        {return CASE;}
char        {return CHAR;}
const       {return CONST;}
continue    {return CONTINUE;}
default     {return DEFAULT;}
do          {return DO;}
double      {return DOUBLE;}
else        {return ELSE;}
enum        {return ENUM;}
extern      {return EXTERN;}
float       {return FLOAT;}
for         {return FOR;}
goto        {return GOTO;}
if          {return IF;}
int         {return INT;}
long        {return LONG;}
register    {return REGISTER;}
return      {return RETURN;}
short       {return SHORT;}
signed      {return SIGNED;}
sizeof      {return SIZEOF;}
static      {return STATIC;}
struct      {return STRUCT;}
switch      {return SWITCH;}
typedef     {return TYPEDEF;}
union       {return UNION;}
unsigned    {return UNSIGNED;}
void        {return VOID;}
volatile    {return VOLATILE;}
while       {return WHILE;}

printf      {return PRINTF;}
scanf       {return SCANF;}

{alpha}({alpha}|{digit}|{underline})*   {return IDENTIFIER;}

[+-]{digit}+(\.{digit}+)?               {return SIGNED_CONST;}

"//"        {return SLC;}
"/*"        {return MLCS;}
"*/"        {return MLCE;}

"<="        {return LEQ;}
">="        {return GEQ;}
"=="        {return EQEQ;}
"!="        {return NEQ;}

"||"        {return LOR;}
"&&"        {return LAND;}
"="         {return ASSIGN;}

"+"         {return PLUS;}
"-"         {return SUB;}
"*"         {return MULT;}
"/"         {return DIV;}
"%"         {return MOD;}

"<"         {return LESSER;}
">"         {return GREATER;}

"++"        {return INCR;}
"--"        {return DECR;}

";"         {return SEMI;}
","         {return COMMA;}

"#include<stdio.h>"         {return HEADER;}
"#include <stdio.h>"        {return HEADER;}
"#include<stdlib.h>"        {return HEADER;}
"#include <stdlib.h>"       {return HEADER;}

"main()"        {return MAIN;}
"main ()"       {return MAIN;}

{digit}+                    {return INT_CONST;}
({digit}+)\.({digit}+)      {return FLOAT_CONST;}

"%d"|"%f"|"%u"|"%s"         {return TYPE_SPEC;}
"\""            {return DQ;}
"("             {return OBO;}
")"             {return OBC;}
"{"             {return CBO;}
"}"             {return CBC;}
"#"             {return HASH;}

{alpha}({alpha}|{digit}|{underline})*\[{digit}*\]       {return ARR;}

{alpha}({alpha}|{digit}|_)*\((({alpha}|{digit}|{underline}|{space})*((\,)({alpha}|{digit}|{underline}|{space})*)*)\)        {return FUNC;}

({digit}+)\.({digit}+)\.({digit}|\.)*       {return NUM_ERR;}


%%

struct node {
    char token[100];
    char attr[100];
    struct node *next;
};

struct hash {
    struct node *head;
    int count;
};

struct hash hashTable[1000];
int elementCount = 1000;

struct node *createNode(char *token, char *attr) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->token, token);
    strcpy(newNode->attr, attr);
    newNode->next = NULL;
    return newNode;
}

int hashIndex(char *token) {
	int hi = 0;
	for (int i = 0; token[i] != '\0'; ++i) {
		hi += (int)token[i];
	}
	hi %= elementCount;
	return hi;
}

void insertToHash(char *token, char *attr) {
	int flag = 0;
	int hi;
	hi = hashIndex(token);
	struct node *newnode = createNode(token, attr);
	/* head of list for the bucket with index "hashIndex" */
	if (!hashTable[hi].head) {
		hashTable[hi].head = newnode;
        hashTable[hi].count = 1;
        return;
	}
	struct node *myNode;
    myNode = hashTable[hi].head;
	while (myNode != NULL) {
        if (strcmp(myNode->token, token) == 0) {
            flag = 1;
            break;
        }
        myNode = myNode->next;
    }
	if(!flag) {
		//adding new node to the list
		newnode->next = (hashTable[hi].head);
		//update the head of the list and no of nodes in the current bucket
		hashTable[hi].head = newnode;
		hashTable[hi].count++;
	}
	return;
}

void display ()  {
    struct node *myNode;
    int k = 1;
    printf("-------------------------------------------------------------------");
    printf("\nSNo \t|\tToken \t\t|\tToken Type \t\n");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < elementCount; ++i) {
        if (hashTable[i].count == 0) {
            continue;
        }
        myNode = hashTable[i].head;
        if (!myNode) {
            continue;
        }
        while (myNode) {
            if(strcmp(myNode->attr, "SPECIAL SYMBOL") == 0) {
                printf("%d\t\t", k++);
                printf("T_%s\t\t\t", myNode->token);
                printf("%d\t\n", *myNode->token);
            } else {
                printf("%d\t\t", k++);
                printf("T_%s\t\t\t", myNode->token);
                printf("%s\t\n", myNode->attr);
            }
            myNode = myNode->next;
        }
    }
   	return;
}

int yywrap() {
    return 1;
}

int main(void) {
    yylex();
    return 0;
}