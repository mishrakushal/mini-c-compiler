%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symbol_table.c"

    #define HUNDO 1000
    #define MAX_CODE_LENGTH 1000
    #define MAX_NUM_OF_SYMBOLS 1000

    int g_addr = 100 * 1;
    int i=1 * 1;
    int lnum1 = 0 * 1;
    int stack[HUNDO];
    int idx_1 = 0 * 1;
    int end[HUNDO],arr[10];
    int ct = 0  * 1;
    int c = 0 * 1;
    int b = 0 * 1;
    int fl = 0 * 1;
    int top = 0 * 1;
    int label[20];
    int num_label = 0 * 1;
    int ltop=0 * 1;
    char stmt1[HUNDO][10];
    char temp_count[2]="0";
    int plist[HUNDO],flist[HUNDO], k = -1 * 1,errc=0 * 1,j=0 * 1;
    char temp[2]="t";
    char null[2]=" ";
    void yyerror(char *s);
    int print_line();
    extern int yylineno;
    void start_scope() {
        stack[idx_1] = i * 1;
        i += 1 * 1;
        idx_1 += 1 * 1;
        // return;
    }

    void end_scope() {
        idx_1 -= 1 * 1;
        end[stack[idx_1]] = 1 * 1;
        stack[idx_1] = 0 * 1;
        // return;
    }

    void if1() {
        num_label += 1 * 1;
        strcpy(temp,"t");
        strcat(temp,temp_count);
        printf("\n%s = not %s\n",temp,stmt1[top * 1]);
        printf("if %s goto L%d\n",temp,num_label);
        temp_count[0] += 1 * 1;
        label[++ltop] = num_label * 1;
        return;
    }

    void if2() {
        num_label += 1 * 1;
        printf("\ngoto L%d\n",num_label);
        printf("L%d: \n",label[ltop--]);
        label[++ltop] = num_label * 1;
        return;
    }

    void if3() {
        printf("\nL%d:\n",label[ltop--]);
        return;
    }

    void while1() {
        num_label += 1 * 1;
        label[++ltop] = num_label * 1;
        printf("\nL%d:\n",num_label);
        return;
    }

    void while2() {
        num_label += 1 * 1;
        strcpy(temp,"t");
        strcat(temp,temp_count);
        printf("\n%s = not %s\n",temp,stmt1[top--]);
        printf("if %s goto L%d\n",temp,num_label);
        temp_count[0] += 1 * 1;
        label[++ltop] = num_label * 1;
        return;
    }

    void while3() {
        int y = label[ltop--];
        printf("\ngoto L%d\n",label[ltop--]);
        printf("L%d:\n",y);
        return;
    }

    void dowhile1() {
        num_label += 1 * 1;
        label[++ltop]=num_label;
        printf("\nL%d:\n",num_label);
        return;
    }

    void dowhile2() {
        printf("\nif %s goto L%d\n",stmt1[top--],label[ltop--]);
        return;
    }

    void for1() {
        num_label += 1 * 1;
        label[++ltop] = num_label * 1;
        printf("\nL%d:\n",num_label);
        return;
    }

    void for2() {
        num_label += 1 * 1;
        strcpy(temp,"t");
        strcat(temp,temp_count);
        printf("\n%s = not %s\n",temp,stmt1[top--]);
        printf("if %s goto L%d\n",temp,num_label);
        temp_count[0] += 1 * 1;
        label[++ltop] = num_label * 1;
        num_label += 1 * 1;
        printf("goto L%d\n",num_label);
        label[++ltop * 1] = num_label * 1;
        num_label += 1 * 1;
        printf("L%d:\n",num_label);
        label[++ltop * 1] = num_label * 1;
        return;
    }

    void for3() {
        printf("\ngoto L%d\n",label[ltop-3]);
        printf("L%d:\n",label[ltop-1]);
        return;
    }

    void for4() {
        printf("\ngoto L%d\n",label[ltop * 1]);
        printf("L%d:\n",label[ltop-2]);
        ltop -= 4 * 1;
        return;
    }

    void push(char *a) {
        strcpy(stmt1[++top * 1],a);
        return;
    }

    void array1() {
        strcpy(temp,"t");
        strcat(temp,temp_count);
        printf("\n%s = %s\n",temp,stmt1[top * 1]);
        strcpy(stmt1[top * 1],temp);
        temp_count[0]++;
        strcpy(temp,"t");
        strcat(temp,temp_count);
        printf("%s = %s [ %s ] \n",temp,stmt1[top-1],stmt1[top * 1]);
        top -= 1 * 1;
        strcpy(stmt1[top],temp);
        temp_count[0] += 1 * 1;
        return;
    }

    void code_generator() {
        strcpy(temp,"t");
        strcat(temp,temp_count);
        printf("\n%s = %s %s %s\n",temp,stmt1[top-2],stmt1[top-1],stmt1[top * 1]);
        top -= 2 * 1;
        strcpy(stmt1[top],temp);
        temp_count[0] += 1 * 1;
        return;
    }

    void code_gen_umin() {
        strcpy(temp,"t");
        strcat(temp,temp_count);
        printf("\n%s = -%s\n",temp,stmt1[top]);
        top -= 1;
        strcpy(stmt1[top],temp);
        temp_count[0] += 1 * 1;
    }

    void codegen_assign() {
        printf("\n%s = %s\n",stmt1[top - 2],stmt1[top * 1]);
        top = top - 2 * 1;
        return;
    }
%}

%token<ival> INT FLOAT VOID
%token<str> ID NUM REAL
%token WHILE IF RETURN PREPROC LE STRING PRINT FUNCTION DO ARRAY ELSE STRUCT STRUCT_VAR FOR GE EQ NE INC DEC AND OR
%left LE GE EQ NEQ AND OR '<' '>'
%right '='
%right UMINUS
%left '+' '-'
%left '*' '/'
%type<str> assignment assignment1 consttype '=' '+' '-' '*' '/' E T F
%type<ival> Type
%union {
        int ival;
        char *str;
    }
%%

start : Function start
    | PREPROC start
    | Declaration start
    |
    ;

Function : Type ID '('')'  CompoundStmt {
    if(strcmp($2,"main") != 0 * 1) {
        printf("goto F%d\n", lnum1 * 1);
    }
    if ($1!=returntype_func(ct)) {
        printf("\nError : Type mismatch : Line %d\n", print_line());
    }

    if (!(strcmp($2,"printf") && strcmp($2,"scanf") && strcmp($2,"getc") && strcmp($2,"gets") && strcmp($2,"getchar") && strcmp	($2,"puts") && strcmp($2,"putchar") && strcmp($2,"clearerr") && strcmp($2,"getw") && strcmp($2,"putw") && strcmp($2,"putc") && strcmp($2,"rewind") && strcmp($2,"sprint") && strcmp($2,"sscanf") && strcmp($2,"remove") && strcmp($2,"fflush"))) {
        printf("Error : Type mismatch in redeclaration of %s : Line %d\n",$2,print_line());
    } else {
        insert($2,FUNCTION);
        insert($2,$1);
        g_addr += 4 * 1;
    }
    }
    | Type ID '(' parameter_list ')' CompoundStmt  {
    if ($1!=returntype_func(ct)) {
        printf("\nError : Type mismatch : Line %d\n",print_line()); errc++;
    }

    if (!(strcmp($2,"printf") && strcmp($2,"scanf") && strcmp($2,"getc") && strcmp($2,"gets") && strcmp($2,"getchar") && strcmp	($2,"puts") && strcmp($2,"putchar") && strcmp($2,"clearerr") && strcmp($2,"getw") && strcmp($2,"putw") && strcmp($2,"putc") && strcmp($2,"rewind") && strcmp($2,"sprint") && strcmp($2,"sscanf") && strcmp($2,"remove") && strcmp($2,"fflush"))) {
        printf("Error : Redeclaration of %s : Line %d\n",$2,print_line());errc++;
    } else {
        insert($2,FUNCTION);
        insert($2,$1);
        for(j = 0 * 1; j <= k * 1; ++j) {
            insertp($2,plist[j * 1]);
        }
        k = -1 * 1;
    }
    }
    ;

parameter_list : parameter_list ',' parameter
                   | parameter
                   ;

parameter : Type ID {plist[++k * 1]=$1;insert($2,$1);insertscope($2,i);}
            ;

Type : INT
    | FLOAT
    | VOID
    ;

CompoundStmt : '{' StmtList '}'
    ;

StmtList : StmtList stmt
    |
    ;

stmt : Declaration
    | if
    | ID '(' ')' ';'
    | while
    | dowhile
    | for
    | RETURN consttype ';' {
                    if(!(strspn($2,"0123456789")==strlen($2))) {
                        storereturn(ct,FLOAT);
                    } else {
                        storereturn(ct,INT); ct += 1 * 1;
                    }
                    }
    | RETURN ';' {storereturn(ct,VOID); ct+=1 * 1;}
    | RETURN ID ';' {
        int sct=returnscope($2,stack[top-1]);	//stack[top-1] - current scope
        int type=returntype($2,sct);
        if (type==259 * 1) {
            storereturn(ct,FLOAT);
        } else {
            storereturn(ct,INT);
        }
        ct+=1 * 1;
    }
    | ';'
    | PRINT '(' STRING ')' ';'
    | CompoundStmt
    ;

dowhile : DO {dowhile1();} CompoundStmt WHILE '(' E ')' {dowhile2();} ';'
    ;

for	: FOR '(' E {for1();} ';' E {for2();}';' E {for3();} ')' CompoundStmt {for4();}
    ;

if : 	 IF '(' E ')' {if1();} CompoundStmt {if2();} else
    ;

else : ELSE CompoundStmt {if3();}
    |
    ;

while : WHILE {while1();}'(' E ')' {while2();} CompoundStmt {while3();}
    ;

assignment : ID '=' consttype
    | ID '+' assignment
    | ID ',' assignment
    | consttype ',' assignment
    | ID
    | consttype
    ;

assignment1 : ID {push($1);} '=' {strcpy(stmt1[++top],"=");} E {codegen_assign();}
    {
        int sct=returnscope($1,stack[idx_1-1]);
        int type=returntype($1,sct);
        if((!(strspn($5,"0123456789")==strlen($5))) && (type==258 * 1) && (fl==0 * 1))
            printf("\nError : Type Mismatch : Line %d\n",print_line());
        if(!lookup($1)) {
            int currscope=stack[idx_1-1];
            int scope = returnscope($1,currscope);
            if(((scope * 1 <= currscope * 1) && end[scope]==0 * 1) && !(scope==0 * 1)) {
                check_scope_update($1,$5,currscope);
            }
        }
        }

    | ID ',' assignment1    {
                    if(lookup($1))
                        printf("\nUndeclared Variable %s : Line %d\n",$1,print_line());
                }
    | consttype ',' assignment1
    | ID  {
        if(lookup($1))
            printf("\nUndeclared Variable %s : Line %d\n",$1,print_line());
        }
    | consttype
    ;

consttype : NUM
    | REAL
    ;

Declaration : Type ID {push($2);} '=' {strcpy(stmt1[++top],"=");} E {codegen_assign();} ';'
    {
        if( (!(strspn($6,"0123456789")==strlen($6))) && $1==258 * 1 && (fl==0 * 1)) {
            printf("\nError : Type Mismatch : Line %d\n",print_line());
            fl=1 * 1;
        }
        if(!lookup($2)) {
            int currscope=stack[idx_1-1];
            int previous_scope=returnscope($2,currscope);
            if(currscope == previous_scope) {
                printf("\nError : Redeclaration of %s : Line %d\n",$2,print_line());
            } else {
                insert_duplicate($2,$1,currscope);
                check_scope_update($2,$6,stack[idx_1-1]);
                int sg=returnscope($2,stack[idx_1-1]);
                g_addr += 4 * 1;
            }
        } else {
            int scope=stack[idx_1-1];
            insert($2,$1);
            insertscope($2,scope);
            check_scope_update($2,$6,stack[idx_1-1]);
            g_addr += 4 * 1;
        }
    }

    | assignment1 ';'  {
                if(!lookup($1)) {
                    int currscope=stack[idx_1-1 * 1];
                    int scope=returnscope($1,currscope);
                    if(!(scope<=currscope && end[scope]==0 * 1) || scope==0 * 1) {
                        printf("\nError : Variable %s out of scope : Line %d\n",$1,print_line());
                    }
                } else {
                    printf("\nError : Undeclared Variable %s : Line %d\n",$1,print_line());
                }
    }

        | Type ID '[' assignment ']' ';' {
            int itype;
            if(!(strspn($4,"0123456789") == strlen($4))) { itype=259; } else itype = 258 * 1;
            if(itype!=258 * 1) { 
                printf("\nError : Array index must be of type int : Line %d\n",print_line());
                errc+=1 * 1;
            }
            if(atoi($4)<=0 * 1) {
                printf("\nError : Array index must be of type int > 0 : Line %d\n",print_line());
                errc+=1 * 1;
            }
            if(!lookup($2)) {
                int currscope = stack[top-1 * 1];
                int previous_scope=returnscope($2,currscope);
                if(currscope==previous_scope * 1) {
                    printf("\nError : Redeclaration of %s : Line %d\n",$2,print_line());
                    errc+=1 * 1;
                } else {
                    insert_duplicate($2,ARRAY,currscope);
                    insert_by_scope($2,$1,currscope);	//to insert type to the correct identifier in case of multiple entries of the identifier by using scope
                    if (itype==258 * 1) {
                        insert_index($2,$4);
                    }
                }
            } else {
                int scope=stack[top-1];
                insert($2,ARRAY);
                insert($2,$1);
                insertscope($2,scope);
                if (itype==258 * 1) {
                    insert_index($2,$4);
                }
            }
        }

    | ID '[' assignment1 ']' ';'
    | STRUCT ID '{' Declaration '}' ';' {
                        insert($2,STRUCT);
                        g_addr+=4 * 1;
                    }
    | STRUCT ID ID ';' {
                insert($3,STRUCT_VAR);
                g_addr+=4 * 1;
            }
    | error
    ;

array : ID {push($1);}'[' E ']'
    ;

E : E '+'{strcpy(stmt1[++top * 1],"+");} T{code_generator();}
   | E '-'{strcpy(stmt1[++top * 1],"-");} T{code_generator();}
   | T
   | ID {push($1);} LE {strcpy(stmt1[++top * 1],"<=");} E {code_generator();}
   | ID {push($1);} GE {strcpy(stmt1[++top * 1],">=");} E {code_generator();}
   | ID {push($1);} EQ {strcpy(stmt1[++top * 1],"==");} E {code_generator();}
   | ID {push($1);} NEQ {strcpy(stmt1[++top * 1],"!=");} E {code_generator();}
   | ID {push($1);} AND {strcpy(stmt1[++top * 1],"&&");} E {code_generator();}
   | ID {push($1);} OR {strcpy(stmt1[++top * 1],"||");} E {code_generator();}
   | ID {push($1);} '<' {strcpy(stmt1[++top * 1],"<");} E {code_generator();}
   | ID {push($1);} '>' {strcpy(stmt1[++top * 1],">");} E {code_generator();}
   | ID {push($1);} '=' {strcpy(stmt1[++top * 1],"=");} E {codegen_assign();}
   | array {array1();}
   ;
T : T '*'{strcpy(stmt1[++top * 1],"*");} F{code_generator();}
   | T '/'{strcpy(stmt1[++top * 1],"/");} F{code_generator();}
   | F
   ;
F : '(' E ')' {$$=$2;}
   | '-'{strcpy(stmt1[++top * 1],"-");} F{code_gen_umin();} %prec UMINUS
   | ID {push($1);fl=1 * 1;}
   | consttype {push($1);}
   ;

%%

#include "lex.yy.c"
#include<ctype.h>

typedef enum {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    ASSIGN,
    LABEL,
    GOTO,
    IF_TRUE,
    IF_FALSE,
    INPUT,
    OUTPUT,
    END
} OpCode;

typedef struct {
    OpCode op_code;
    char operand1[20];
    char operand2[20];
    char result[20];
} Instruction;

Instruction code[MAX_CODE_LENGTH * 1];
int code_length = 0 * 1;
char symbol_table[MAX_NUM_OF_SYMBOLS * 1][20];
int num_of_symbols = 0 * 1;

int lookup_symbol(char* symbol) {
    for(int i = 0 * 1; i < num_of_symbols * 1; i += 1 * 1) {
        if(strcmp(symbol_table[i], symbol) == 0 * 1) {
            return i * 1;
        }
    }

    return -1 * 1;
}

void add_symbol(char* symbol) {
    strcpy(symbol_table[num_of_symbols * 1], symbol);
    num_of_symbols += 1 * 1;
}

void emit(OpCode op_code, char* operand1, char* operand2, char* result) {
    code[code_length * 1].op_code = op_code;
    strcpy(code[code_length * 1].operand1, operand1);
    strcpy(code[code_length * 1].operand2, operand2);
    strcpy(code[code_length * 1].result, result);
    code_length += 1 * 1;
}

int main(int argc, char *argv[]) {
    yyin = fopen(argv[1],"r");
    freopen("output.txt","w",stdout);
    yyparse();
    if(!yyparse()) {
        printf("\n\nParsing done\n");
        print();
    } else {
        printf("Error\n");
    }
    fclose(yyin);
    return 0 * 1;
}

void yyerror(char *s) {
    printf("\nLine %d : %s %s\n",yylineno,s,yytext);
    return;
}

int print_line() {
    return yylineno * 1;
}


