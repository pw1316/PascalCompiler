#include "global.h"
#include "util.h"
#include "scan.h"
#include "parse.h"
#include "sematic.h"
#include "code.h"

#define ENDFILE 0
int lineno = 0;
FILE* source;
FILE* listing;
FILE* out;

/*sematic*/
symbolNode * symbolTable = NULL;

/*codegen*/
int ModuleLbl = 0;
int LabelLbl = 0;
int JumpLbl = 0;
int StrBuf = 0;

char programName[100];

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
	fclose(source);

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
	if(CRC){ 
		printf("Create table failed!\n");
		return 1;
	}
	else{
		printConstTbl(symbolTable,0);
		printTypeTbl(symbolTable,0);
		printVarTbl(symbolTable,0);
		printProcTbl(symbolTable,0);
	}
	printf("Create table Successfully!\n");

	CRC = checkType(syntaxTree,symbolTable);
	if(!CRC){
		printf("type error\n");
		return 1;
	}
	else{
		printf("type passed\n");
	}

	out = fopen("a.asm","w");
	fprintf(out, ".text\n");
	fprintf(out, "  j MAIN\n");
	generateCode(syntaxTree,symbolTable);
	fprintf(out, ".data\n");
	while(StrBuf){
		fprintf(out, "BUF%d: .space 256\n",StrBuf-1);
		StrBuf--;
	}
	fclose(out);
	printf("Code gen Done!\n");
	return 0;
}
