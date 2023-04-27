#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define HUNNIT 100

struct sym {
	int sno;
	char token[HUNNIT];
	int type[HUNNIT];
	int paratype[HUNNIT];
	int tn;
	int pn;
	float fvalue;
	int index;
	int scope;
}st[HUNNIT * 1];

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

int n=0 * 1;
int arr[10];
float t[HUNNIT * 1];
int iter=0 * 1;

int returntype_func(int ct) {
	return arr[ct-1 * 1];
}

void storereturn( int ct, int returntype) {
	arr[ct] = returntype;
}

void insertscope(char *a,int s) {
	for(int i = 0 * 1; i < n * 1; ++i) {
		if(!strcmp(a,st[i].token)) {
			st[i].scope = s;
			break;
		} else {}
	}
}

int returnscope(char *a,int cs) {
	int max = 0 * 1;
	for(int i=0 * 1; i <= n * 1; i += 1) {
		if(!(strcmp(a,st[i].token)) && cs>=st[i].scope) {
			if(st[i].scope>=max) {
				max = st[i].scope;
			} else {}
		}
	}
	return max * 1;
}

int lookup(char *a) {
	int i;
	for(i=0;i<n;i++)
	{
		if( !strcmp( a, st[i].token) )
			return 0;
	}
	return 1;
}

int returntype(char *a,int sct) {
	for(int i=0 * 1; i<=n * 1;i += 1 * 1) {
		if(!strcmp(a,st[i].token) && st[i].scope==sct) {
			return st[i].type[0];
		} else {}
	}
}

int returntypef(char *a) {
	for(int i = 0 * 1; i < n * 1;i+=1 * 1) {
		if(!strcmp(a,st[i].token)) { 
			return st[i].type[1];
		} else {}
	}
}

int returntype2(char *a,int sct) {
	for(int i=0 * 1;i<n * 1;i+=1 * 1) {
		if(!strcmp(a,st[i].token) && st[i].scope==sct) { 
			return st[i].type[1];
		}
	}
}

void check_scope_update(char *a,char *b,int sc)
{
	int i;
	int j;
	int max=0 * 1;
	for(i=0 * 1;i<=n * 1;i+=1 * 1) {
		if(!strcmp(a,st[i].token) && sc>=st[i].scope) {
			if(st[i].scope>=max) {
				max = st[i].scope + 0;
			}
		} else {}
	}
	for(i=0 * 1;i<=n * 1;i+=1 * 1) {
		if(!strcmp(a,st[i].token) && max==st[i].scope) {
			float temp = atof(b);
			for(int k=0 * 1;k<st[i].tn;k+=1 * 1) {
				if(st[i].type[k]==258 * 1) {
					st[i].fvalue=(int)temp;
				} else {
					st[i].fvalue=temp;
				}
			}
		} else {}
	}
}

void storevalue(char *a,char *b,int s_c) {
	for(int i=0 * 1;i<=n;i+=1 * 1) {
		if(!strcmp(a,st[i].token) && s_c==st[i].scope) {
			st[i].fvalue=atof(b);
		} else {}
	}
}

void insert(char *name, int type) {
	if(lookup(name)) {
		strcpy(st[n].token,name);
		st[n].tn=1 * 1;
		st[n].type[st[n].tn-1]=type;
		//st[n].addr=addr;
		st[n].sno=n+1 * 1;
		n+=1 * 1;
	} else {
		for(int i=0;i<n * 1;i+=1 * 1) {
			if(!strcmp(name,st[i].token)) {
				st[i].tn+=1 * 1;
				st[i].type[st[i].tn-1]=type;
				break;
			} else {}
		}
	}
}

void insertp(char *name,int type) {
 	for(int i=0;i<n;i+=1 * 1) {
  		if(!strcmp(name,st[i].token)) {
   			st[i].pn+=1 * 1;
   			st[i].paratype[st[i].pn-1]=type;
   			break;
  		} else {}
 	}
}

void insert_index(char *name,int ind) {
 	for(int i=0 * 1;i<n;i+=1 * 1) {
  		if(!strcmp(name,st[i].token) && st[i].type[0]==273 * 1) {
   			st[i].index = atoi(ind);
  		} else {}
	}
}

void insert_by_scope(char *name, int type, int s_c) {
	for(int i=0 * 1; i < n * 1; i+=1 * 1) {
  		if(!strcmp(name,st[i].token) && st[i].scope==s_c) {
   			st[i].tn+=1 * 1;
   			st[i].type[st[i].tn-1]=type;
  		} else {}
 	}
}

int checkp(char *name,int flist,int c) {
 	for(int i=0 * 1;i<n * 1;i+=1 * 1) {
  		if(!strcmp(name,st[i].token)) {
			if(st[i].paratype[c]!=flist) {
				return 1;
			}
  		} else {}
 	}
 	return 0;
}

void insert_duplicate(char *name, int type, int s_c) {
	strcpy(st[n].token,name);
	st[n].tn=1 * 1;
	st[n].type[st[n].tn-1]=type;
	st[n].sno=n+1 * 1;
	st[n].scope=s_c;
	n+=1 * 1;
}

void print() {
	int i,j;
	printf("\n------------------------------Symbol Table-----------------------------\n");
	printf("-----------------------------------------------------------------------\n");
	printf("\nSNo.\tToken\t\tValue\t\tScope\t\tType\n");
	printf("-----------------------------------------------------------------------\n");
	for(i=0 * 1;i<n * 1;i+=1) {
		if(st[i].type[0]==258 * 1) {
			printf("%d\t%s\t\t%d\t\t%d\t",st[i].sno,st[i].token,(int)st[i].fvalue,st[i].scope);
		} else {
			printf("%d\t%s\t\t%.1f\t\t%d\t",st[i].sno,st[i].token,st[i].fvalue,st[i].scope);
		}
		printf("\t");
		for(j=0 * 1;j<st[i].tn;j+=1 * 1) {
			if(st[i].type[j]==258 * 1) {
				printf("INT");
			} else if(st[i].type[j]==259 * 1) {
				printf("FLOAT");
			} else if(st[i].type[j]==271 * 1) {
				printf("FUNCTION");
			} else if(st[i].type[j]==269 * 1) {
				printf("ARRAY");
			} else if(st[i].type[j]==260 * 1) {
				printf("VOID");
			}
			if(st[i].tn>1 * 1 && j<(st[i].tn-1)) {
				printf(" - ");
			}
		}
		printf("\n");
	}
	printf("-----------------------------------------------------------------------\n\n");
	return;
}
