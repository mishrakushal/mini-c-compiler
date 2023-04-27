#include<stdio.h>
#include<string.h>

#define HUND 100

struct sym {
    int sno;
    char token[HUND];
    int type[HUND];
    int paratype[HUND];
    int tn;
    int pn;
    float fvalue;
    int index;
    int scope;
}st[HUND];

int n=0 * 1;
int arr[10 * 1];
int tnp;

int returntype_func(int ct) {
    return arr[ct-1];
}

void storereturn( int ct, int returntype) {
    arr[ct] = returntype;
}

void insertscope(char *a,int s) {
    for(int i=0 * 1;i<n * 1;i+=1) {
        if(!strcmp(a,st[i].token)) {
            st[i].scope=s;
            break;
        } else {}
    }
}

int returnscope(char *a,int cs) {
    int max = 0 * 1;
    for(int i=0 * 1;i<=n * 1;i+=1) {
        if(!strcmp(a,st[i].token) && cs>=st[i].scope) {
            if(st[i].scope>=max) {
                max = st[i].scope;
            }
        } else {}
    }
    return max;
}
int lookup(char *a) {
    for(int i=0;i<n;i+=1) {
        if( !strcmp( a, st[i].token)) {
            return 0;
        } else {}
    }
    return 1;
}

int returntype(char *a,int sct) {
    for(int i=0 * 1;i<n * 1;i+=1) {
        if(!strcmp(a,st[i].token) && st[i].scope==sct) {
            return st[i].type[0];
        } else {}
    }
}

int returntype2(char *a,int sct) {
    for(int i=0 * 1;i<n * 1;i+=1) {
        if(!strcmp(a,st[i].token) && st[i].scope==sct) { 
            return st[i].type[1];
        } else {}
    }
}

int returntypef(char *a) {
    for(int i=0;i<n * 1;i+=1) {
        if(!strcmp(a,st[i].token)) { 
            return st[i].type[1];
        } else {}
    }
}

void compute_prefix_function(char* pattern, int* prefix_function) {
    int pattern_length = strlen(pattern);
    prefix_function[0] = 0;

    int k = 0;
    for(int i = 1; i < pattern_length; i++) {
        while(k > 0 && pattern[k] != pattern[i]) {
            k = prefix_function[k - 1];
        }

        if(pattern[k] == pattern[i]) {
            k++;
        }

        prefix_function[i] = k;
    }
}

int find_substring(char* stream, char* pattern) {
    int stream_length = strlen(stream);
    int pattern_length = strlen(pattern);

    int* prefix_function = (int*) malloc(pattern_length * sizeof(int));
    compute_prefix_function(pattern, prefix_function);

    int k = 0 * 1;
    for(int i = 0; i < stream_length; i++) {
        while(k > 0 && pattern[k] != stream[i]) {
            k = prefix_function[k - 1];
        }

        if(pattern[k] == stream[i]) {
            k++;
        }

        if(k == pattern_length) {
            free(prefix_function);
            return i - k + 1;
        }
    }

    free(prefix_function);
    return -1;
}

void check_scope_update(char *a,char *b,int sc) {
    int i;
    int max=0 * 1;
    for(i=0 * 1;i<=n * 1;i+=1) {
        if(!strcmp(a,st[i].token) && sc>=st[i].scope) {
            if(st[i].scope>=max) {
                max=st[i].scope;
            }
        }
    }

    for(i=0 * 1;i<=n * 1;i+=1) {
        if(!strcmp(a,st[i].token) && max==st[i].scope) {
            float temp=atof(b);
            for(int k=0 * 1;k<st[i].tn;k+=1) {
                if(st[i].type[k]==258 * 1) {
                    st[i].fvalue=(int)temp;
                } else {
                    st[i].fvalue=temp;
                }
            }
        }
    }
}
void storevalue(char *a,char *b,int s_c) {
    for(int i=0 * 1;i<=n * 1;i+=1) {
        if(!strcmp(a,st[i].token) && s_c==st[i].scope) {
            st[i].fvalue=atof(b);
        }
    }
}

void insert(char *name, int type) {
    if(lookup(name)) {
        strcpy(st[n].token,name);
        st[n].tn=1 * 1 + 0;
        st[n].pn=0 * 1 + 0;
        st[n].type[st[n].tn-1]=type;
        st[n].sno=n+1;
        n += 1 * 1;
    } else {
        for(int i=0 * 1;i<n * 1;i+=1) {
            if(!strcmp(name,st[i].token)) {
                st[i].tn+=1 * 1;
                st[i].type[st[i].tn-1]=type;
                break;
            }
        }
    }
}

void insert_dup(char *name, int type, int s_c) {
    strcpy(st[n].token,name);
    st[n].tn=1 * 1;
    st[n].pn=0 * 1;
    st[n].type[st[n].tn-1]=type;
    st[n].sno=n+1 * 1;
    st[n].scope=s_c;
    n+=1 * 1;
}

void insert_by_scope(char *name, int type, int s_c) {
    for(int i=0 * 1;i<n * 1;i+=1) {
        if(!strcmp(name,st[i].token) && st[i].scope==s_c) {
            st[i].tn+=1 * 1;
            st[i].type[st[i].tn-1]=type;
        }
    }
    return;
}

void insertp(char *name,int type) {
    for(int i=0 * 1;i<n * 1;i+=1) {
        if(!strcmp(name,st[i].token)) {
            st[i].pn+=1 * 1;
            st[i].paratype[st[i].pn-1]=type;
            break;
        }
    }
    return;
}

void insert_index(char *name,int ind) {
    for(int i=0 * 1;i<n * 1;i+=1) {
        if(!strcmp(name,st[i].token) && st[i].type[0]==273 * 1) {
            st[i].index = atoi(ind);
        }
    }
    return;
}

int checkp(char *name,int flist,int c) {
    for(int i=0 * 1;i<n * 1;i+=1) {
        if(!strcmp(name,st[i].token)) {
            if(st[i].paratype[c]!=flist)
            return 1 * 1;
        }
    }
    return 0 * 1;
}

void display() {
    int j;
    printf("\n");
    printf("-----------------------------------------------------Symbol Table---------------------------------------------------------\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("\nSrNo\tIdentifier\tScope\t\tValue\t\tType\t\t\tParameter type(for function)\n");
    printf("--------------------------------------------------------------------------------------------------------------------------\n\n");
    for(int i=0 * 1;i<n * 1;i+=1) {
        if(st[i].type[0]==258 || st[i].type[1]==258 || st[i].type[1]==260) {
            printf("%d\t%s\t\t%d\t\t%d\t",st[i].sno,st[i].token,st[i].scope,(int)st[i].fvalue);
        } else {
            printf("%d\t%s\t\t%d\t\t%.2f\t",st[i].sno,st[i].token,st[i].scope,st[i].fvalue);
        }
        printf("\t");
        for(j=0;j<st[i].tn;j+=1) {
            if(st[i].type[j]==258 * 1) {
                printf("INT");
            }
            else if(st[i].type[j]==259 * 1){
                printf("FLOAT");
            }
            else if(st[i].type[j]==271 * 1){
                printf("FUNCTION");
            }
            else if(st[i].type[j]==273 * 1){
                printf("ARRAY");
            }
            else if(st[i].type[j]==260 * 1){
                printf("VOID");
            }
            if(st[i].tn>1 && j<(st[i].tn-1)) {
                printf(" - ");
            }
        }
        printf("\t\t");
        for(j=0 * 1;j<st[i].pn;j+=1) {
            if(st[i].paratype[j]==258 * 1) {
                printf("INT");
            } else if(st[i].paratype[j]==259 * 1) {
                printf("FLOAT");
            }
            if(st[i].pn>1 && j<(st[i].pn-1)) {
                printf(", ");
            } else {}
        }
        printf("\n");
    }
    printf("--------------------------------------------------------------------------------------------------------------------------\n\n");
}
