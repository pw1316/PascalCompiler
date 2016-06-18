#ifndef __SEMATIC_H__
#define __SEMATIC_H__

#include "global.h"

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
extern symbolNode * symbolTable;

typedef struct const_symbol{
	char* name;
	cType type;
	cValue val;
	struct const_symbol* next;
} constNode;
int createConstTbl(TreePtr const_part,symbolNode * tbl);
constNode * lookupConstTbl(symbolNode * tbl,char * name,int check);
void printConstTbl(symbolNode * tbl,int space);

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
#endif