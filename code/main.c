#include "global.h"
#include "util.h"
#include "scan.h"
#include "parse.h"
#include "sematic.h"

#define ENDFILE 0
int lineno = 0;
FILE* source;
FILE* listing;

/*sematic*/
typedef union{int d;float f;char c;char* str;} cValue;
typedef enum{cIntT,cBoolT,cCharT,cRealT,cStringT,cArrayT,cRecordT,cVoidT} cType;
struct const_symbol;
struct type_symbol;
struct var_symbol;
struct proc_symbol;
typedef struct symbol_table{
	struct const_symbol * const_part;
	struct type_symbol * type_part;
	struct var_symbol * var_part;
	struct proc_symbol * proc_part;
} symbolNode;
symbolNode * symbolTable = NULL;

	/*const*/
typedef struct const_symbol{
	char* name;
	cType type;
	cValue val;
	struct const_symbol* next;
} constNode;
int createConstTbl(TreePtr const_part,symbolNode * tbl);
constNode * lookupConstTbl(symbolNode * tbl,char * name,int check);
void printConstTbl(symbolNode * tbl,int space);

	/*type*/
typedef struct type_symbol{
	char* name;
	cType type;
	cType subtype;
	int max;
	int min;
	int submax;
	int submin;
	struct var_symbol* member;
	struct type_symbol* next;
} typeNode;
int createTypeTbl(TreePtr type_part,symbolNode * tbl);
typeNode * lookupTypeTbl(symbolNode * tbl,char * name,int check);
void printTypeTbl(symbolNode * tbl,int space);
	
	/*var*/
typedef struct var_symbol{
	char* name;
	cType type;
	cType subtype;
	int max;
	int min;
	int submax;
	int submin;
	struct var_symbol* member;
	struct var_symbol* next;
	int memoffset;
	int size;
	int var;
	int ret;
} varNode;
int createVarTbl(TreePtr var_part,symbolNode * tbl);
varNode * lookupVarTbl(symbolNode * tbl,char * name,int check);
void printVarTbl(symbolNode * tbl,int space);

	/*proc*/
typedef struct proc_symbol{
	char* name;
	cType returntype;
	int returnmax;
	int returnmin;
	varNode * params;
	int paramsnum;
	symbolNode * tbl;
	struct proc_symbol * next;
	int label;
} procNode;
int createProcTbl(TreePtr proc_part,symbolNode * tbl);
procNode * lookupProcTbl(symbolNode * tbl,char * name,int check);
void printProcTbl(symbolNode * tbl,int space);

int analyze(TreePtr syntaxtree);
typeNode * getSimpleType(TreePtr node,symbolNode * tbl,int simpleID);
typeNode * getType(TreePtr node,symbolNode * tbl);
int checkType(TreePtr node,symbolNode * tbl);

/*codegen*/
void generateCode(TreePtr node,symbolNode * tbl);
void generateModule(TreePtr node,symbolNode * tbl);
void generateStmt(TreePtr node,symbolNode * tbl);
void generateExpr(TreePtr node,symbolNode * tbl);
int generateVar(symbolNode * tbl);

char programName[100];
int ModuleLbl = 0;
int LabelLbl = 0;
int JumpLbl = 0;

int main(int argc, char* argv[]){
	TreePtr syntaxTree;
	TreePtr p;
	int CRC = 0;

	char pgm[120];
	if (argc != 2){
		fprintf(stderr,"usage: %s <filename>\n",argv[0]);
    	exit(1);
    }
	strcpy(pgm,argv[1]) ;
	if(strchr (pgm, '.') == NULL) strcat(pgm,".tny");
  	source = fopen(pgm,"r");
  	if(source==NULL){
  		fprintf(stderr,"File %s not found\n",pgm);
    	exit(1);
	}
	listing = stdout;
	fprintf(listing,"\nTINY COMPILATION: %s\n",pgm);

	syntaxTree = parse();
	if(!syntaxTree) return 1;
	if(syntaxTree -> attr.name){
		strcpy(programName,syntaxTree -> attr.name);
	}
	p = syntaxTree;
	syntaxTree = syntaxTree -> child[0];
	free(p);
	printf("Parse Successfully!\n");

	symbolTable = (symbolNode*)malloc(sizeof(symbolNode));
	symbolTable->const_part = (constNode*)malloc(sizeof(constNode));
	symbolTable->const_part->next = NULL;
	symbolTable->type_part = (typeNode*)malloc(sizeof(typeNode));
	symbolTable->type_part->next = NULL;
	symbolTable->var_part = (varNode*)malloc(sizeof(varNode));
	symbolTable->var_part->next = NULL;
	symbolTable->proc_part = (procNode*)malloc(sizeof(procNode));
	symbolTable->proc_part->next = NULL;

	CRC = analyze(syntaxTree);
	if(CRC) printf("Create table failed!\n");
	else{
		printConstTbl(symbolTable,0);
		printTypeTbl(symbolTable,0);
		printVarTbl(symbolTable,0);
		printProcTbl(symbolTable,0);
	}
	printf("Create table Successfully!\n");
	generateCode(syntaxTree,symbolTable);
	fclose(source);
	return 0;
}

/*sematic*/
int createConstTbl(TreePtr const_part,symbolNode * tbl){
	constNode * p;
	p = lookupConstTbl(tbl,const_part->attr.name,1);
	if(p == NULL){
		printf("Name duplicated: %s ! (line %d)\n", const_part->attr.name,const_part->lineno+1);
		return 1;
	}
	switch(const_part->child[0]->kind.expr){
		case IntK:
			p->type = cIntT;
			p->val.d = const_part->child[0]->attr.intval;
			p->next = NULL;
			break;
		case RealK:
			p->type = cRealT;
			p->val.f = const_part->child[0]->attr.realval;
			p->next = NULL;
			break;
		case CharK:
			p->type = cCharT;
			p->val.c = const_part->child[0]->attr.charval;
			p->next = NULL;
			break;
		case StringK:
			p->type = cStringT;
			p->val.str = const_part->child[0]->attr.strval;
			p->next = NULL;
			break;
		case BoolK:
			p->type = cBoolT;
			p->val.d = const_part->child[0]->attr.intval;
			p->next = NULL;
			break;
	}
	if(!const_part->sibling) return 0;
	else return createConstTbl(const_part->sibling,tbl);
}

constNode * lookupConstTbl(symbolNode * tbl,char * name,int check){
	constNode * p = tbl->const_part->next;
	constNode * oldp = NULL;
	/*find*/
	if(check == 0){
		while(p){
			if(strcmp(p->name,name) == 0) return p;
			p = p -> next;
		}
		return NULL;
	}
	/*check*/
	while(p){
		if(strcmp(p->name,name) == 0) return NULL;
		oldp = p;
		p = p -> next;
	}
	if(oldp){
		oldp->next = (constNode*)malloc(sizeof(constNode));
		p = oldp->next;
	}
	else{
		tbl->const_part->next = (constNode*)malloc(sizeof(constNode));
		p = tbl->const_part->next;
	}
	p->name = (char*)malloc(sizeof(strlen(name)+1));
	strcpy(p->name,name);
	return p;
}

void printConstTbl(symbolNode * tbl,int space){
	constNode * p;
	char* offset = (char*)malloc(space+1);
	offset[space] = 0;
	while(space){
		offset[space-1] = ' ';
		space--;
	}
	printf("%sconst list:\n",offset);
	if(!tbl) return;
	else if(!tbl->const_part) return;
	p = tbl->const_part->next;
	while(p){
		switch(p->type){
			case cIntT:
			case cBoolT:
				printf("%s  %s = %d\n",offset,p->name,p->val.d);
				break;
			case cCharT:
				printf("%s  %s = %c\n",offset,p->name,p->val.c);
				break;
			case cRealT:
				printf("%s  %s = %f\n",offset,p->name,p->val.f);
				break;
			case cStringT:
				printf("%s  %s = %s\n",offset,p->name,p->val.str);
				break;
		}
		p = p->next;
	}
	free(offset);
}

int createTypeTbl(TreePtr type_part,symbolNode * tbl){
	constNode * constL;
	typeNode * p;
	typeNode * q;
	varNode * memp;
	varNode * memoldp;
	TreePtr node;
	TreePtr memnamelist;
	int ret = 0;

	constL = lookupConstTbl(tbl,type_part->attr.name,0);
	if(constL != NULL){
		printf("Name duplicated: %s ! (line %d)\n", type_part->attr.name, type_part->lineno+1);
		return 1;
	}
	p = lookupTypeTbl(tbl,type_part->attr.name,1);
	if(p == NULL){
		printf("Name duplicated: %s ! (line %d)\n", type_part->attr.name, type_part->lineno+1);
		return 1;
	}

	switch(type_part->child[0]->kind.decl){
		case SimpleK:
			q = getSimpleType(type_part->child[0],tbl,0);
			if(q == NULL) return 1;
			p->type = q->type;
			p->subtype = q->subtype;
			p->min = q->min;
			p->max = q->max;
			p->submin = q->submin;
			p->submax = q->submax;
			p->member = q->member;
			free(q);
			break;
		case ArrayK:
			node = type_part->child[0];
			p->type = cArrayT;
			if(!node->child[0]->child[0]){
				printf("Index should be range! (line %d)\n",node->lineno+1);
				return 1;
			}
			else if(node->child[0]->child[0]->kind.expr != IntK){
				printf("Index should be integer! (line %d)\n",node->lineno+1);
				return 1;
			}
			else if(node->child[0]->child[1]->kind.expr != IntK){
				printf("Index should be integer! (line %d)\n",node->lineno+1);
				return 1;
			}
			else{
				p->max = node->child[0]->child[1]->attr.intval;
				p->min = node->child[0]->child[0]->attr.intval;
			}
			q = getSimpleType(node->child[1],tbl,1);
			if(q == NULL) return 1;
			p->subtype = q->type;
			p->submin = q->min;
			p->submax = q->max;
			free(q);
			break;
		case FieldK:
			node = type_part->child[0];/*0:namelist 1:type*/
			p->type = cRecordT;
			p->member = (varNode*)malloc(sizeof(varNode));
			p->member->next = NULL;
			while(node){
				q = getSimpleType(node->child[1],tbl,1);
				if(q == NULL) return 1;

				memnamelist = node->child[0];
				while(memnamelist){
					memp = p->member->next;
					memoldp = NULL;
					while(memp){
						if(strcmp(memp->name,memnamelist->attr.name) == 0){
							printf("Name duplicated in record:%s.%s ! (line %d)\n", p->name, memp->name, node->lineno+1);
							free(q);
							return 1;
						}
						memoldp = memp;
						memp = memp->next;
					}
					if(memoldp){
						memoldp->next = (varNode*)malloc(sizeof(varNode));
						memp = memoldp->next;
					}
					else{
						p->member->next = (varNode*)malloc(sizeof(varNode));
						memp = p->member->next;
					}
					memp->name = (char*)malloc(sizeof(strlen(memnamelist->attr.name)+1));
					strcpy(memp->name,memnamelist->attr.name);
					memp->type = q->type;
					memp->max = q->max;
					memp->min = q->min;
					memnamelist = memnamelist->sibling;
				}
				free(q);
				node = node->sibling;
			}
			break;
	}
	p->next = NULL;
	if(!type_part->sibling) return 0;
	else return createTypeTbl(type_part->sibling,tbl);
}

typeNode * lookupTypeTbl(symbolNode * tbl,char * name,int check){
	typeNode * p = tbl->type_part->next;
	typeNode * oldp = NULL;
	/*find*/
	if(check == 0){
		while(p){
			if(strcmp(p->name,name) == 0) return p;
			p = p->next;
		}
		return NULL;
	}
	/*check*/
	while(p){
		if(strcmp(p->name,name) == 0) return NULL;
		oldp = p;
		p = p->next;
	}
	if(oldp){
		oldp->next = (typeNode*)malloc(sizeof(typeNode));
		p = oldp->next;
	}
	else{
		tbl->type_part->next = (typeNode*)malloc(sizeof(typeNode));
		p = tbl->type_part->next;
	}
	p->name = (char*)malloc(sizeof(strlen(name)+1));
	strcpy(p->name,name);
	return p;
}

void printTypeTbl(symbolNode * tbl,int space){
	typeNode * p;
	varNode * mem;
	char* offset = (char*)malloc(space+1);
	offset[space] = 0;
	while(space){
		offset[space-1] = ' ';
		space--;
	}
	printf("%stype list:\n",offset);
	if(!tbl) return;
	if(!tbl->type_part) return;
	p = tbl->type_part->next;
	while(p){
		switch(p->type){
			case cIntT:
				printf("%s  %s = int(%d,%d)\n",offset,p->name,p->min,p->max);
				break;
			case cBoolT:
				printf("%s  %s = bool(%d,%d)\n",offset,p->name,p->min,p->max);
				break;
			case cCharT:
				printf("%s  %s = char(%d,%d)\n",offset,p->name,p->min,p->max);
				break;
			case cRealT:
				printf("%s  %s = real\n",offset,p->name);
				break;
			case cStringT:
				printf("%s  %s = string(%d,%d)\n",offset,p->name,p->min,p->max);
				break;
			case cArrayT:
				printf("%s  %s = array[%d,%d] of ",offset,p->name,p->min,p->max);
				switch(p->subtype){
					case cIntT:
						printf("integer(%d,%d)\n",p->submin,p->submax);
						break;
					case cBoolT:
						printf("boolean(%d,%d)\n",p->submin,p->submax);
						break;
					case cCharT:
						printf("char(%d,%d)\n",p->submin,p->submax);
						break;
					case cRealT:
						printf("real\n");
						break;
					case cStringT:
						printf("string(%d,%d)\n",p->submin,p->submax);
						break;
				}
				break;
			case cRecordT:
				printf("%s  %s : record\n",offset,p->name);
				if(p->member){
					mem = p->member->next;
					while(mem){
						switch(mem->type){
							case cIntT:
								printf("%s    %s : int(%d,%d)\n",offset,mem->name,mem->min,mem->max);
								break;
							case cBoolT:
								printf("%s    %s : bool(%d,%d)\n",offset,mem->name,mem->min,mem->max);
								break;
							case cCharT:
								printf("%s    %s : char(%d,%d)\n",offset,mem->name,mem->min,mem->max);
								break;
							case cRealT:
								printf("%s    %s : real\n",offset,mem->name);
								break;
							case cStringT:
								printf("%s    %s : string(%d,%d)\n",offset,mem->name,mem->min,mem->max);
								break;
						}
						mem = mem->next;
					}
				}
				printf("%s  end\n",offset);
				break;
		}
		p = p->next;
	}
	free(offset);
}

int createVarTbl(TreePtr var_part,symbolNode * tbl){
	constNode * constL;
	typeNode * q;
	typeNode * qq;
	TreePtr node;
	TreePtr namelist;
	varNode * memp;
	varNode * memoldp;

	switch(var_part->child[1]->kind.decl){
		case SimpleK:
			q = getSimpleType(var_part->child[1],tbl,0);
			if(q == NULL) return 1;
			break;
		case ArrayK:
			node = var_part->child[1];/*0:index 1:type*/
			q = getSimpleType(node->child[1],tbl,1);
			if(q == NULL) return 1;
			q->subtype = q->type;
			q->submin = q->min;
			q->submax = q->max;
			q->type = cArrayT;
			if(!node->child[0]->child[0]){
				printf("Index should be range! (line %d)\n",node->lineno+1);
				free(q);
				return 1;
			}
			else if(node->child[0]->child[0]->kind.expr != IntK){
				printf("Index should be integer! (line %d)\n",node->lineno+1);
				free(q);
				return 1;
			}
			else if(node->child[0]->child[1]->kind.expr != IntK){
				printf("Index should be integer! (line %d)\n",node->lineno+1);
				free(q);
				return 1;
			}
			else{
				q->max = node->child[0]->child[1]->attr.intval;
				q->min = node->child[0]->child[0]->attr.intval;
			}
			break;
		case FieldK:
			node = var_part->child[1];/*0:namelist 1:type*/
			q = (typeNode*)malloc(sizeof(typeNode));
			q->type = cRecordT;
			q->member = (varNode*)malloc(sizeof(varNode));
			q->member->next = NULL;
			while(node){
				qq = getSimpleType(node->child[1],tbl,1);
				if(qq == NULL) return 1;

				namelist = node->child[0];
				while(namelist){
					memp = q->member->next;
					memoldp = NULL;
					while(memp){
						if(strcmp(memp->name,namelist->attr.name) == 0){
							printf("Name duplicated in record:%s.%s ! (line %d)\n", q->name, memp->name, node->lineno+1);
							free(q);
							free(qq);
							return 1;
						}
						memoldp = memp;
						memp = memp->next;
					}
					if(memoldp){
						memoldp->next = (varNode*)malloc(sizeof(varNode));
						memp = memoldp->next;
					}
					else{
						q->member->next = (varNode*)malloc(sizeof(varNode));
						memp = q->member->next;
					}
					memp->name = (char*)malloc(sizeof(strlen(namelist->attr.name)+1));
					strcpy(memp->name,namelist->attr.name);
					memp->type = qq->type;
					memp->max = qq->max;
					memp->min = qq->min;
					namelist = namelist->sibling;
				}
				free(qq);
				node = node->sibling;
			}
			break;
	}

	namelist = var_part->child[0];
	while(namelist){
		constL = lookupConstTbl(tbl,namelist->attr.name,0);
		if(constL){
			printf("Name duplicated: %s ! (line %d)\n", namelist->attr.name, namelist->lineno+1);
			free(q);
			return 1;
		}

		qq = lookupTypeTbl(tbl,namelist->attr.name,0);
		if(qq){
			printf("Name duplicated: %s ! (line %d)\n", namelist->attr.name, namelist->lineno+1);
			free(q);
			return 1;
		}
		memp = lookupVarTbl(tbl,namelist->attr.name,1);
		if(memp == NULL){
			printf("Name duplicated: %s ! (line %d)\n", namelist->attr.name, namelist->lineno+1);
			free(q);
			return 1;
		}
		memp->type = q->type;
		memp->subtype = q->subtype;
		memp->max = q->max;
		memp->min = q->min;
		memp->submin = q->submin;
		memp->submax = q->submax;
		memp->member = q->member;
		memp->next = NULL;
		namelist = namelist->sibling;
	}
	free(q);
	if(!var_part->sibling) return 0;
	else return createVarTbl(var_part->sibling,tbl);
}

varNode * lookupVarTbl(symbolNode * tbl,char * name,int check){
	varNode * p = tbl->var_part->next;
	varNode * oldp = NULL;
	/*find*/
	if(check == 0){
		while(p){
			if(strcmp(p->name,name) == 0) return p;
			p = p->next;
		}
		return NULL;
	}
	/*check*/
	while(p){
		if(strcmp(p->name,name) == 0) return NULL;
		oldp = p;
		p = p->next;
	}
	if(oldp){
		oldp->next = (varNode*)malloc(sizeof(varNode));
		p = oldp->next;
	}
	else{
		tbl->var_part->next = (varNode*)malloc(sizeof(varNode));
		p = tbl->var_part->next;
	}
	p->name = (char*)malloc(sizeof(strlen(name)+1));
	strcpy(p->name,name);
	return p;
}

void printVarTbl(symbolNode * tbl,int space){
	varNode * p;
	varNode * mem;
	char* offset = (char*)malloc(space+1);
	offset[space] = 0;
	while(space){
		offset[space-1] = ' ';
		space--;
	}
	printf("%svar list:\n",offset);
	if(!tbl) return;
	if(!tbl->var_part) return;
	p = tbl->var_part->next;
	while(p){
		switch(p->type){
			case cIntT:
				printf("%s  %s : int(%d,%d) at %d\n",offset,p->name,p->min,p->max,p->memoffset);
				break;
			case cBoolT:
				printf("%s  %s : bool(%d,%d) at %d\n",offset,p->name,p->min,p->max,p->memoffset);
				break;
			case cCharT:
				printf("%s  %s : char(%d,%d) at %d\n",offset,p->name,p->min,p->max,p->memoffset);
				break;
			case cRealT:
				printf("%s  %s : real at %d\n",offset,p->name,p->memoffset);
				break;
			case cStringT:
				printf("%s  %s : string(%d,%d) at %d\n",offset,p->name,p->min,p->max,p->memoffset);
				break;
			case cArrayT:
				printf("%s  %s : array[%d,%d] of ",offset,p->name,p->min,p->max);
				switch(p->subtype){
					case cIntT:
						printf("integer(%d,%d)\n",p->submin,p->submax);
						break;
					case cBoolT:
						printf("boolean(%d,%d)\n",p->submin,p->submax);
						break;
					case cCharT:
						printf("char(%d,%d)\n",p->submin,p->submax);
						break;
					case cRealT:
						printf("real\n");
						break;
					case cStringT:
						printf("string(%d,%d)\n",p->submin,p->submax);
						break;
				}
				break;
			case cRecordT:
				printf("%s  %s : record\n",offset,p->name);
				if(p->member){
					mem = p->member->next;
					while(mem){
						switch(mem->type){
							case cIntT:
								printf("%s    %s : int(%d,%d)\n",offset,mem->name,mem->min,mem->max);
								break;
							case cBoolT:
								printf("%s    %s : bool(%d,%d)\n",offset,mem->name,mem->min,mem->max);
								break;
							case cCharT:
								printf("%s    %s : char(%d,%d)\n",offset,mem->name,mem->min,mem->max);
								break;
							case cRealT:
								printf("%s    %s : real\n",offset,mem->name);
								break;
							case cStringT:
								printf("%s    %s : string(%d,%d)\n",offset,mem->name,mem->min,mem->max);
								break;
						}
						mem = mem->next;
					}
				}
				printf("%s  end\n",offset);
				break;
		}
		p = p->next;
	}
	free(offset);
}

int createProcTbl(TreePtr proc_part,symbolNode * tbl){
	TreePtr head = proc_part->child[0];
	TreePtr routing = proc_part->child[1];
	TreePtr params = head->child[0];
	TreePtr ret = head->child[1];
	TreePtr routingh = routing->child[0];
	TreePtr namelist;
	constNode * constL;
	typeNode * typeL;
	varNode * varL;
	varNode * varLL;
	procNode * procL;
	procNode * old = NULL;

	constL = lookupConstTbl(tbl,head->attr.name,0);
	if(constL){
		printf("Name duplicated: %s ! (line %d)\n", head->attr.name, head->lineno+1);
		return 1;
	}
	typeL = lookupTypeTbl(tbl,head->attr.name,0);
	if(typeL){
		printf("Name duplicated: %s ! (line %d)\n", head->attr.name, head->lineno+1);
		return 1;
	}
	varL = lookupVarTbl(tbl,head->attr.name,0);
	if(varL){
		printf("Name duplicated: %s ! (line %d)\n", head->attr.name, head->lineno+1);
		return 1;
	}
	procL = lookupProcTbl(tbl,head->attr.name,1);
	if(procL == NULL){
		printf("Name duplicated: %s ! (line %d)\n", head->attr.name, head->lineno+1);
		return 1;
	}

	procL->tbl = (symbolNode*)malloc(sizeof(symbolNode));
	procL->tbl->const_part = (constNode*)malloc(sizeof(constNode));
	procL->tbl->type_part = (typeNode*)malloc(sizeof(typeNode));
	procL->tbl->var_part = (varNode*)malloc(sizeof(varNode));
	procL->tbl->proc_part = NULL;

	if(ret){
		typeL = getSimpleType(ret,tbl,1);
		if(typeL == NULL) return 1;
		varL = lookupVarTbl(procL->tbl,head->attr.name,1);
		procL->returntype = typeL->type;
		procL->returnmin = typeL->min;
		procL->returnmax = typeL->max;
		varL->type = typeL->type;
		varL->min = typeL->min;
		varL->max = typeL->max;
		varL->ret = 1;
		varL->var = 0;
		varL->next = NULL;
		free(typeL);
	}
	else{
		procL->returntype = cVoidT;
	}

	procL->paramsnum = 0;
	if(params){
		int var;
		procL->params = (varNode*)malloc(sizeof(varNode));
		procL->params->next = NULL;
		while(params){
			typeL = getSimpleType(params->child[2],tbl,1);
			if(typeL == NULL) return 1;
			if(params->child[0]){
				var = 1;
				namelist = params->child[0];
			}
			else{
				var = 0;
				namelist = params->child[1];
			}
			while(namelist){
				varL = procL->params->next;
				varLL = NULL;
				while(varL){
					if(strcmp(varL->name,namelist->attr.name) == 0){
						printf("Name duplicated in params: %s ! (line %d)\n", namelist->attr.name,namelist->lineno);
						free(typeL);
						return 1;
					}
					varLL = varL;
					varL = varL->next;
				}
				if(varLL){
					varLL->next = (varNode*)malloc(sizeof(varNode));
					varL = varLL->next;
				}
				else{
					procL->params->next = (varNode*)malloc(sizeof(varNode));
					varL = procL->params->next;
				}
				varL->name = (char*)malloc(sizeof(strlen(namelist->attr.name)+1));
				strcpy(varL->name,namelist->attr.name);
				varL->type = typeL->type;
				varL->min = typeL->min;
				varL->max = typeL->max;
				varL->var = var;
				varL->next = NULL;
				varL->ret = 0;
				namelist = namelist->sibling;
				procL->paramsnum++;
			}
			params = params->sibling;
			free(typeL);
		}
	}
	if(procL->params){
		varL = procL->tbl->var_part;
		while(varL->next) varL = varL->next;
		varL->next = procL->params->next;
	}

	if(routingh->child[0]) createConstTbl(routingh->child[0],procL->tbl);
	if(routingh->child[1]) createTypeTbl(routingh->child[1],procL->tbl);
	if(routingh->child[2]) createVarTbl(routingh->child[2],procL->tbl);
	if(routingh->child[3]){
		printf("Sub proc not allowed! (line %d)\n", routingh->child[3]->lineno);
		return 1;
	}
	procL->next = NULL;

	if(!proc_part->sibling) return 0;
	else return createProcTbl(proc_part->sibling,tbl);
}

procNode * lookupProcTbl(symbolNode * tbl,char * name,int check){
	procNode * p = tbl->proc_part->next;
	procNode * oldp = NULL;
	/*find*/
	if(check == 0){
		while(p){
			if(strcmp(p->name,name) == 0) return p;
			p = p->next;
		}
		return NULL;
	}
	/*check*/
	while(p){
		if(strcmp(p->name,name) == 0) return NULL;
		oldp = p;
		p = p->next;
	}
	if(oldp){
		oldp->next = (procNode*)malloc(sizeof(procNode));
		p = oldp->next;
	}
	else{
		tbl->proc_part->next = (procNode*)malloc(sizeof(procNode));
		p = tbl->proc_part->next;
	}
	p->name = (char*)malloc(sizeof(strlen(name)+1));
	strcpy(p->name,name);
	return p;
}

void printProcTbl(symbolNode * tbl,int space){
	procNode * p;
	varNode * params;
	char* offset = (char*)malloc(space+1);
	int i;
	offset[space] = 0;
	while(space){
		offset[space-1] = ' ';
		space--;
	}
	printf("%sproc list:\n",offset);
	if(!tbl) return;
	if(!tbl->proc_part) return;
	p = tbl->proc_part->next;
	while(p){
		if(p->returntype == cVoidT) printf("%s  proc:%s",offset, p->name);
		else printf("%s  %d[%d,%d] func:%s",offset,p->returntype,p->returnmin,p->returnmax,p->name);
		if(p->params){
			params = p->params->next;
			i = p->paramsnum;
			printf("(");
			while(i){
				printf("%s:%d,", params->name,params->type);
				params = params->next;
				i--;
			}
			printf(")");
		}
		printf(" begin\n");
		printConstTbl(p->tbl,4);
		printTypeTbl(p->tbl,4);
		printVarTbl(p->tbl,4);
		printf("%s  end\n",offset);
		p = p->next;
	}
}

int analyze(TreePtr syntaxtree){
	TreePtr const_part;
	TreePtr type_part;
	TreePtr var_part;
	TreePtr proc_part;
	int rec = 0;
	const_part = syntaxtree->child[0]->child[0];
	type_part = syntaxtree->child[0]->child[1];
	var_part = syntaxtree->child[0]->child[2];
	proc_part = syntaxtree->child[0]->child[3];

	if(const_part) rec = createConstTbl(const_part,symbolTable);
	if(rec) return rec;
	if(type_part) rec = createTypeTbl(type_part,symbolTable);
	if(rec) return rec;
	if(var_part) rec = createVarTbl(var_part,symbolTable);
	if(rec) return rec;
	if(proc_part) rec = createProcTbl(proc_part,symbolTable);
	if(rec) return rec;


	return rec;
}

typeNode * getSimpleType(TreePtr node,symbolNode * tbl,int simpleID){
	typeNode * typeL;
	typeNode * p = (typeNode*)malloc(sizeof(typeNode));
	if(node->child[0]){
		if(node->child[0]->kind.expr == IntK && node->child[1]->kind.expr == IntK){
			p->type = cIntT;
			p->max = node->child[1]->attr.intval;
			p->min = node->child[0]->attr.intval;
		}
		else if(node->child[0]->kind.expr == CharK && node->child[1]->kind.expr == CharK){
			p->type = cCharT;
			p->max = node->child[1]->attr.charval;
			p->min = node->child[0]->attr.charval;
		}
		else{
			printf("Range should be integer or char! (line %d)\n",node->lineno+1);
			free(p);
			return NULL;
		}
		if(p->min > p->max){
			printf("Wrong range : [%d,%d] ! (line %d)\n",p->min,p->max,node->lineno+1);
			free(p);
			return NULL;
		}
	}
	else{
		switch(node->type){
			case BooleanT:
				p->type = cBoolT;
				p->max = 1;
				p->min = 0;
				break;
			case CharacterT:
				p->type = cCharT;
				p->max = 255;
				p->min = 0;
				break;
			case IntegerT:
				p->type = cIntT;
				p->max = 0x7FFFFFFF;
				p->min = 0x80000000;
				break;
			case RealT:
				p->type = cRealT;
				break;
			case StringT:
				p->type = cStringT;
				p->max = 255;
				p->min = 0;
				break;
			case IDT:
				typeL = tbl->type_part->next;
				while(typeL){
					if(strcmp(typeL->name,node->attr.name) == 0){
						if(!simpleID){
							p->type=typeL->type;
							p->subtype=typeL->subtype;
							p->max=typeL->max;
							p->min=typeL->min;
							p->submax=typeL->submax;
							p->submin=typeL->submin;
							p->member=typeL->member;
						}
						else{
							if(typeL->type == cArrayT || typeL->type == cRecordT){
								printf("Type not simple for array or record! (line %d)\n", node->lineno+1);
								free(p);
								return NULL;
							}
							p->type=typeL->type;
							p->max=typeL->max;
							p->min=typeL->min;
						}
						break;
					}
					typeL = typeL->next;
				}
				if(!typeL){
					printf("Name undefined:%s ! (line %d)\n", node->attr.name,node->lineno+1);
					free(p);
					return NULL;
				}
				break;
		}
	}
	return p;
}

typeNode * getType(TreePtr node,symbolNode * tbl){return NULL;}
int checkType(TreePtr node,symbolNode * tbl){return 0;}

void generateCode(TreePtr node,symbolNode * tbl){
	if(!node) return;
	switch(node->nodekind){
		case ModuleK:
			generateModule(node,tbl);
			break;
		case StmtK:
			generateStmt(node,tbl);
			break;
		case ExprK:
			generateExpr(node,tbl);
			break;
	}
	generateCode(node->sibling,tbl);
}

void generateModule(TreePtr node,symbolNode * tbl){
	int i;
	procNode * procL;
	switch(node->kind.module){
		case RoutingK:
			generateCode(node->child[0]->child[3],tbl);/*function and procedures*/
			printf("MAIN:\n");
			printf("  addi $sp,$sp,-8\n");/*callee-save*/
			printf("  sw $ra,4($sp)\n");
			printf("  sw $fp,0($sp)\n");
			printf("  addi $sp,$sp,-32\n");
			for(i=0;i<8;i++) printf("  sw $s%d,%d($sp)\n",i,i*4);
			printf("  addi $fp,$sp,0\n");
			generateVar(tbl);/*push var*/
			generateCode(node->child[1],tbl);/*program body*/
			printf("  addi $sp,$fp,0\n");/*callee-getback*/
			for(i=0;i<8;i++) printf("  lw $s%d,%d($sp)\n",i,i*4);
			printf("  addi $sp,$sp,32\n");
			printf("  lw $fp,0($sp)\n");
			printf("  lw $ra,4($sp)\n");
			printf("  addi $sp,$sp,8\n");
			printf("  jr $ra\n");
			break;
		case ProcedureK:
			printf("FUNC%d:\n",ModuleLbl);
			printf("  addi $sp,$sp,-8\n");/*callee-save*/
			printf("  sw $ra,4($sp)\n");
			printf("  sw $fp,0($sp)\n");
			printf("  addi $sp,$sp,-32\n");
			for(i=0;i<8;i++) printf("  sw $s%d,%d($sp)\n",i,i*4);
			printf("  addi $fp,$sp,0\n");
			procL = lookupProcTbl(tbl,node->child[0]->attr.name,0);/*find in table*/
			if(procL == NULL){
				printf("No such proc! (line %d)\n", node->lineno);
				return;
			}
			procL->label = ModuleLbl;/*save label*/
			ModuleLbl++;
			generateVar(procL->tbl);/*push local var*/
			generateCode(node->child[1]->child[1],tbl);/*program body*/
			printf("  addi $sp,$fp,0\n");/*callee-getback*/
			for(i=0;i<8;i++) printf("  lw $s%d,%d($sp)\n",i,i*4);
			printf("  addi $sp,$sp,32\n");
			printf("  lw $fp,0($sp)\n");
			printf("  lw $ra,4($sp)\n");
			printf("  addi $sp,$sp,8\n");
			printf("  jr $ra\n");
			break;
		case FunctionK:
			break;
	}
}

void generateStmt(TreePtr node,symbolNode * tbl){
	varNode * varL;
	varNode * varLL;
	typeNode * typeL;
	int off;
	switch(node->kind.stmt){
		case LabelK:
			if(node->child[0]){
				printf("LABEL%d:\n", node->attr.label);
				generateCode(node->child[0],tbl);
			}
			else{
				generateCode(node->child[1],tbl);
			}
			break;
		case AssignK:
			if(node->child[0]){/*ID := expression*/
				varL = lookupVarTbl(tbl,node->attr.name,0);
				if(varL){
					generateCode(node->child[0],tbl);
					if(varL->type == cIntT || varL->type == cRealT){
						printf("  sw $t0,%d($fp)\n", -(varL->memoffset));
					}
					else if(varL->type == cCharT || varL->type == cBoolT){
						printf("  sb $t0,%d($fp)\n", -(varL->memoffset));
					}
					else if(varL->type == cStringT){
						printf("  addi $t1,$zero,0\n");//t1=0
						printf("  addi $t2,$fp,$t1:\n");//t2=fp
						printf("JUMP%d:\n", JumpLbl);
						printf("  lb $t3,0($t0)\n");//t3=t0[0]
						printf("  sb $t3,%d($t2)\n", -(varL->memoffset));
						printf("  addi $t0,$t0,1\n");
						printf("  addi $t2,$t2,1\n");
						printf("  subi $t4,$t1,256\n");
						printf("  beq $t4,$zero,JUMP%d\n",JumpLbl);
						JumpLbl++;
					}
				}
			}
			else if(node->child[1]){/*ID[expression] := expression*/
				varL = lookupVarTbl(tbl,node->attr.name,0);
				if(varL){
					generateCode(node->child[1],tbl);
					printf("  addi $s1,$t0,0\n");
					printf("  addi $s1,$s1,%d\n",-(varL->min));
					generateCode(node->child[2],tbl);
					if(varL->subtype == cIntT || varL->subtype == cRealT){
						printf("  sll $s1,$s1,2\n");
						printf("  add $s1,$s1,$fp\n");
						printf("  sw $t0,%d($s1)\n", -(varL->memoffset));
					}
					else if(varL->type == cCharT || varL->type == cBoolT){
						printf("  add $s1,$s1,$fp\n");
						printf("  sb $t0,%d($s1)\n", -(varL->memoffset));
					}
					else if(varL->type == cStringT){
						printf("  sll $s1,$s1,8\n");
						printf("  add $s1,$s1,$fp\n");
						printf("  addi $t1,$zero,0\n");//t1=0
						printf("  addi $t2,$s1,$t1:\n");//t2=fp
						printf("JUMP%d:\n", JumpLbl);
						printf("  lb $t3,0($t0)\n");//t3=t0[0]
						printf("  sb $t3,%d($t2)\n", -(varL->memoffset));
						printf("  addi $t0,$t0,1\n");
						printf("  addi $t2,$t2,1\n");
						printf("  subi $t4,$t1,256\n");
						printf("  beq $t4,$zero,JUMP%d\n",JumpLbl);
						JumpLbl++;
					}
				}
			}
			else if(node->child[3]){/*ID.ID := expression*/
				varL = lookupVarTbl(tbl,node->attr.name,0);
				if(varL){
					varLL = varL->member->next;
					while(varLL){
						if(strcmp(varLL->name,node->child[3]->attr.name) == 0){
							off = varLL->memoffset;
							break;
						}
						varLL = varLL->next;
					}
					generateCode(node->child[4],tbl);
					if(varLL->type == cIntT || varLL->type == cRealT){
						printf("  sw $t0,%d($fp)\n", -(varL->memoffset)+off);
					}
					else if(varL->type == cCharT || varL->type == cBoolT){
						printf("  sb $t0,%d($fp)\n", -(varL->memoffset)+off);
					}
					else if(varL->type == cStringT){
						printf("  addi $t1,$zero,0\n");//t1=0
						printf("  addi $t2,$s1,$t1:\n");//t2=fp
						printf("JUMP%d:\n", JumpLbl);
						printf("  lb $t3,0($t0)\n");//t3=t0[0]
						printf("  sb $t3,%d($t2)\n", -(varL->memoffset)+off);
						printf("  addi $t0,$t0,1\n");
						printf("  addi $t2,$t2,1\n");
						printf("  subi $t4,$t1,256\n");
						printf("  beq $t4,$zero,JUMP%d\n",JumpLbl);
						JumpLbl++;
					}
				}
			}
			break;
	}
}

void generateExpr(TreePtr node,symbolNode * tbl){
	switch(node->kind.expr){
		case FactorK:
			if(node->child[0]){

			}
			else if(node->child[1]){
				switch(node->child[1]->kind.expr){
					case IntK:
					case RealK:
						printf("  addi $t0,$zero,%d\n", node->child[1]->attr.intval);
						break;
				}
			}
			break;
	}
}

int generateVar(symbolNode * tbl){
	varNode * varL = tbl->var_part->next;
	varNode * varLL;
	int offset = 0;
	int rsize;
	int roff;
	while(varL){
		switch(varL->type){
			case cIntT:
			case cRealT:
				varL->size = 4;
				while(offset%4 != 0) offset++;
				offset += 4;
				varL->memoffset = offset;
				break;
			case cBoolT:
			case cCharT:
				varL->size = 1;
				offset += 1;
				varL->memoffset = offset;
				break;
			case cStringT:
				varL->size =  256;
				offset += 256;
				varL->memoffset = offset;
				break;
			case cArrayT:
				switch(varL->subtype){
					case cIntT:
					case cRealT:
						varL->size = (varL->max-varL->min+1)*4;
						while(offset%4 != 0) offset++;
						offset += varL->size;
						varL->memoffset = offset;
						break;
					case cBoolT:
					case cCharT:
						varL->size = varL->max-varL->min+1;
						offset += varL->size;
						while(offset%4 != 0) offset++;
						varL->memoffset = offset;
						break;
					case cStringT:
						varL->size =  (varL->max-varL->min+1)*256;
						while(offset%4 != 0) offset++;
						offset += varL->size;
						varL->memoffset = offset;
						break;
				}
				break;
			case cRecordT:
				varLL = varL->member->next;
				rsize = 0;
				roff = 0;
				while(varLL){
					switch(varLL->type){
						case cIntT:
						case cRealT:
							varLL->size = 4;
							while(offset%4 != 0) {roff++;rsize++;}
							varLL->memoffset = roff;
							roff += 4;
							rsize += 4;
							break;
						case cBoolT:
						case cCharT:
							varLL->size = 1;
							varLL->memoffset = offset;
							roff += 1;
							rsize += 1;
							break;
						case cStringT:
							varLL->size = 256;
							while(offset%4 != 0) {roff++;rsize++;}
							varLL->memoffset = roff;
							roff += 256;
							rsize += 256;
							break;
					}
					varLL = varLL->next;
				}
				varL->size = rsize;
				while(offset%4 != 0) offset++;
				offset += varL->size;
				varL->memoffset = offset;
				break;
		}
		varL = varL->next;
	}
	while(offset%4 !=0) offset++;
	printf("  addi $sp,$sp,%d\n",-offset);
}
