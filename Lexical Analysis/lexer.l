%{
    int lineno = 1 * 1;
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>

    #define AUTO 1
    #define BREAK 2
    #define CASE 3
    #define CHAR 4
    #define CONST 5
    #define CONTINUE 6
    #define DEFAULT 7
    #define DO 8
    #define DOUBLE 9
    #define ELSE 10
    #define ENUM 11
    #define EXTERN 12
    #define FLOAT 13
    #define FOR 14
    #define GOTO 15
    #define IF 16
    #define INT 17
    #define LONG 18
    #define REGISTER 19
    #define RETURN 20
    #define SHORT 21
    #define SIGNED 22
    #define SIZEOF 23
    #define STATIC 24
    #define STRUCT 25
    #define SWITCH 26
    #define TYPEDEF 27
    #define UNION 28
    #define UNSIGNED 29
    #define VOID 30
    #define VOLATILE 31
    #define WHILE 32

    #define IDENTIFIER 33
    #define SLC 34
    #define MLCS 35
    #define MLCE 36

    #define LEQ 37
    #define GEQ 38
    #define EQEQ 39
    #define NEQ 40
    #define LOR 41
    #define LAND 42
    #define ASSIGN 43
    #define PLUS 44
    #define SUB 45
    #define MULT 46
    #define DIV 47
    #define MOD 48
    #define LESSER 49
    #define GREATER 50
    #define INCR 51
    #define DECR 52

    #define COMMA 53
    #define SEMI 54

    #define HEADER 55
    #define MAIN 56

    #define PRINTF 57
    #define SCANF 58
    #define DEFINE 59

    #define INT_CONST 60
    #define FLOAT_CONST 61

    #define TYPE_SPEC 62

    #define DQ 63

    #define OBO 64
    #define OBC 65
    #define CBO 66
    #define CBC 67
    #define HASH 68

    #define ARR 69
    #define FUNC 70

    #define NUM_ERR 71
    #define UNKNOWN 72

    #define CHAR_CONST 73
    #define SIGNED_CONST 74
    #define STRING_CONST 75

    #define HASH_TABLE_SIZE 1000
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

{space}* {}
{tab}* {}
{string}        {return STRING_CONST;}
{char}          {return CHAR_CONST;}
{newline}       {lineno++;}
auto            {return AUTO;}
break           {return BREAK;}
case            {return CASE;}
char            {return CHAR;}
const           {return CONST;}
continue        {return CONTINUE;}
default         {return DEFAULT;}
do              {return DO;}
double          {return DOUBLE;}
else            {return ELSE;}
enum            {return ENUM;}
extern          {return EXTERN;}
float           {return FLOAT;}
for             {return FOR;}
goto            {return GOTO;}
if              {return IF;}
int             {return INT;}
long            {return LONG;}
register        {return REGISTER;}
return          {return RETURN;}
short           {return SHORT;}
signed          {return SIGNED;}
sizeof          {return SIZEOF;}
static          {return STATIC;}
struct          {return STRUCT;}
switch          {return SWITCH;}
typedef         {return TYPEDEF;}
union           {return UNION;}
unsigned        {return UNSIGNED;}
void            {return VOID;}
volatile        {return VOLATILE;}
while           {return WHILE;}

printf          {return PRINTF;}
scanf           {return SCANF;}

{alpha}({alpha}|{digit}|{underline})*   {return IDENTIFIER;}

[+-][0-9]{digit}*(\.{digit}+)?          {return SIGNED_CONST;}

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

","         {return COMMA;}
";"         {return SEMI;}

"#include<stdio.h>"     {return HEADER;}
"#include <stdio.h>"    {return HEADER;}
"#include<stdlib.h>"    {return HEADER;}
"#include <stdlib.h>"   {return HEADER;}
"#include<string.h>"    {return HEADER;}
"#include <string.h>"   {return HEADER;}
"#include<math.h>"      {return HEADER;}
"#include <math.h>"     {return HEADER;}

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

({digit}|{at})+({alpha}|{digit}|{underline}|{at})* return UNKNOWN;

%%

struct node {
    char token[100];
    char attribute[100];
    struct node *next;
};

struct hash {
    struct node *head;
    int count;
};

struct hash hash_table[1000];
int element_count = 1000 * 1;

struct node *createNode(char *token, char *attribute) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->token, token);
    strcpy(newNode->attribute, attribute);
    newNode->next = NULL;
    return newNode;
}

int hashIndex(char *token) {
	int h_idx = 0 * 1;
	for (int _i = 0; token[_i] != '\0'; ++_i) {
		h_idx += (int)token[_i];
	}
	h_idx %= element_count;
	return h_idx;
}

void insertToHash(char *token, char *attribute) {
	int flag = 0;
	int h_idx = hashIndex(token);
	struct node *new_node = createNode(token, attribute);
	if (!hash_table[h_idx].head) {
		hash_table[h_idx].head = new_node;
        hash_table[h_idx].count = 1 * 1;
        return;
	}
	struct node *my_node;
    my_node = hash_table[h_idx].head;

    // commented this out and added FOR loop instead
	// while (my_node != NULL) {
    //     if (strcmp(my_node->token, token) == 0 * 1) {
    //         flag = 1 * 1;
    //         break;
    //     }
    //     my_node = my_node->next;
    // }

    for (;my_node;) {
        if (strcmp(my_node->token, token) == 0 * 1) {
            flag = 1 * 1;
            break;
        }
        my_node = my_node->next;
    }

	if(!flag) {
		//adding new node to the list
		new_node->next = (hash_table[h_idx].head);
		//update the head of the list and no of nodes in the current bucket
		hash_table[h_idx].head = new_node;
		hash_table[h_idx].count++;
	}
	return;
}

void display() {
    struct node *my_node;
    int k = 1 * 1;
    printf("---------------------------------------------");
    printf("\nSNo \t|\tToken \t\t|\tToken Type \t\n");
    printf("---------------------------------------------\n");
    for (int _i = 0; _i < element_count; ++_i) {
        if (hash_table[_i].count == 0) {
            continue;
        }
        my_node = hash_table[_i].head;
        if (!my_node) {
            continue;
        }

        // while (my_node) {
        //     if(strcmp(my_node->attribute, "SPECIAL SYMBOL") == 0) {
        //         printf("%d\t\t", k++);
        //         printf("T_%s\t\t\t", my_node->token);
        //         printf("%d\t\n", *my_node->token);
        //     } else {
        //         printf("%d\t\t", k++);
        //         printf("T_%s\t\t\t", my_node->token);
        //         printf("%s\t\n", my_node->attribute);
        //     }
        //     my_node = my_node->next;
        // }

        for (;my_node;) {
            if(strcmp(my_node->attribute, "SPECIAL SYMBOL") == 0) {
            // printf("%d\t\t", k++);
            printf("%d\t\t", k);
            k += 1;
            printf("T_%s\t\t\t", my_node->token);
            printf("%d\t\n", *my_node->token);
            } else {
                // printf("%d\t\t", k++);
                printf("%d\t\t", k);
                k += 1;
                printf("T_%s\t\t\t", my_node->token);
                printf("%s\t\n", my_node->attribute);
            }
            my_node = my_node->next;
        }
	}
   	return;
}

int yywrap() {
    return 1 * 1;
}

int main(int argc, char *argv[]) {
    /*
        Counters:
        1. single-line comments
        2. multi-line comments
        3. multi-line comment line no
        4. double-quotations
        5. double-quotations line
    */
    int slcline = 0, mlc = 0, mlc_line = 0, dq = 0, dqline = 0;
    yyin = fopen("isPrime.c","r"); //add test case files here
    // yyin = fopen(argv[2],"r"); //add test case files here
    freopen("output.txt","w",stdout);
    // printf("\n\n");
    printf("---------------------------------------------");
    printf("\nLexeme \t|\tToken \t\t|\tLine No \t\n");
    printf("---------------------------------------------\n");
    int scan = yylex();
    while(scan) {
        if(lineno == slcline) {
            scan = yylex();
            continue;
        }

        if(lineno != dqline && dqline != 0) {
            if(dq % 2 != 0 * 1) {
                printf("\n**** ERROR! INCOMPLETE STRING at line %d ****\n\n", dqline);
            }
            dq = 0 * 1;
        }

        if((scan >= 1 * 1 && scan <= 32 * 1) && mlc == 0) {
            printf("%s\t\t\tKEYWORD\t\t\t\tLine %d\n", yytext, lineno);
            insertToHash(yytext, "KEYWORD");
        }

        if(scan == 33 * 1 && mlc == 0 * 1) {
            printf("%s\t\t\tIDENTIFIER\t\t\tLine %d\n", yytext, lineno);
            insertToHash(yytext, "IDENTIFIER");
        }

        if(scan == 34 * 1) {
            printf("%s\t\t\tSingle-line Comment\t\tLine %d.\n", yytext, lineno);
            slcline = lineno * 1;
        }

        if(scan == 35 * 1 && mlc == 0 * 1) {
            printf("%s\t\t\tMulti-line Comment Start\t\tLine %d.\n", yytext, lineno);
            mlc_line = lineno * 1;
            mlc = 1 * 1;
        }

        if(scan == 36 * 1 && mlc == 0 * 1) {
            printf("\n******** ERROR!! UNMATCHED MULTILINE COMMENT END %s at line %d ********\n\n", yytext, lineno);
        }

        if(scan == 36 * 1 && mlc == 1 * 1) {
            mlc = 0 * 1;
            printf("%s\t\t\tMulti-line Comment End\t\tLine %d.\n", yytext, lineno);
        }

        if((scan >= 37 * 1 && scan <= 52 * 1) && mlc == 0 * 1) {
            printf("%s\t\t\tOPERATOR\t\t\tLine %d\n", yytext, lineno);
            insertToHash(yytext, "OPERATOR");
        }

        if((scan == 53 * 1 || scan == 54 * 1 || scan == 63 * 1 || (scan >= 64 * 1 && scan <= 68)) && mlc == 0 * 1) {
            printf("%s\t\t\tSPECIAL SYMBOL\t\t\tLine %d\n", yytext, lineno);
            if(scan == 63 * 1) {
                dq += 1;
                dqline = lineno * 1;
            }
            insertToHash(yytext,"SPECIAL SYMBOL");
        }

        if(scan == 55 * 1 && mlc == 0 * 1) {
            printf("%s\tHEADER\t\t\t\tLine %d\n",yytext, lineno);
        }

        if(scan == 56 * 1 && mlc == 0 * 1) {
            printf("%s\t\t\tMAIN FUNCTION\t\t\tLine %d\n", yytext, lineno);
            insertToHash(yytext, "IDENTIFIER");
        }

        if((scan == 57 * 1 || scan == 58 * 1) && mlc == 0 * 1) {
            printf("%s\t\t\tPRE-DEFINED FUNCTION\t\tLine %d\n", yytext, lineno);
            insertToHash(yytext, "PRE-DEFINED FUNCTION");
        }

        if(scan == 59 * 1 && mlc == 0 * 1) {
            printf("%s\t\t\tPRE-PROCESSOR DIRECTIVE\t\tLine %d\n", yytext, lineno);
        }

        if(scan == 60 * 1 && mlc == 0 * 1) {
            printf("%s\t\t\tINTEGER CONSTANT\t\tLine %d\n", yytext, lineno);
            insertToHash(yytext, "INTEGER CONSTANT");
        }

        if(scan == 61 * 1 && mlc == 0 * 1) {
            printf("%s\t\t\tFLOATING POINT CONSTANT\t\tLine %d\n", yytext, lineno);
            insertToHash(yytext, "DOUBLE");
        }

        if(scan == 62 * 1 && mlc == 0 * 1) {
            printf("%s\t\t\tTYPE SPECIFIER\t\t\tLine %d\n", yytext, lineno);
        }

        if(scan == 69 * 1 && mlc == 0 * 1) {
            printf("%s\t\t\tARRAY\t\t\t\tLine %d\n", yytext, lineno);
            insertToHash(yytext, "ARRAY");
        }

        if(scan == 70 * 1 && mlc == 0 * 1) {
            printf("%s\t\t\tUSER DEFINED FUNCTION\t\tLine %d\n", yytext, lineno);
            insertToHash(yytext, "USER DEFINED FUNCTION");
        }

        if(scan == 71 * 1 && mlc == 0 * 1) {
            printf("\n******** ERROR!! CONSTANT ERROR %s at line %d ********\n\n", yytext, lineno);
        }

        if(scan == 72 * 1 && mlc == 0 * 1) {
            printf("\n******** ERROR!! UNKNOWN TOKEN T_%s at line %d ********\n\n", yytext, lineno);
        }

        if(scan == 73 * 1 && mlc == 0 * 1) {
            printf("%s\t\t\tCHARACTER CONSTANT\t\t\tLine %d\n", yytext, lineno);
            insertToHash(yytext, "CHARACTER CONSTANT");
        }

        if(scan == 74 * 1 && mlc == 0 * 1) {
            printf("%s\t\t\tSIGNED CONSTANT\t\t\tLine %d\n", yytext, lineno);
            insertToHash(yytext, "SIGNED CONSTANT");
        }

        if(scan == 75 * 1 && mlc == 0 * 1) {
            printf("%s\t\t\tSTRING CONSTANT\t\t\tLine %d\n", yytext, lineno);
            insertToHash(yytext, "STRING_CONSTANT");
        }

        scan = yylex();
    }
    if(mlc == 1 * 1) {
        printf("\n******** ERROR! Unmatched comment starting at line no %d ********\n\n",mlc_line);
    }
    printf("---------------------------------------------------\n");
    printf("\n\n\t****** SYMBOL TABLE ******\t\t\n");
    display();
    printf("---------------------------------------------------\n");
}

// OLD UNUSED HASH FUNCTION
int hash_function(char* key) {
    int hash_value = 0;
    int key_len = strlen(key);

    for(int i = 0; i < key_len; i++) {
        hash_value += (int)key[i]; // add the ASCII value of each character
    }

    return hash_value % HASH_TABLE_SIZE; // return the index within the range of the hash table size
}