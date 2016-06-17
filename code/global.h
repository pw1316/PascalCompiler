#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TokenType;
extern FILE* source;
extern FILE* listing;
extern int lineno;

typedef enum {ModuleK,DeclK,StmtK,ExprK} NodeKind;
typedef enum {ProgramK,RoutingK,Routing_headK,ProcedureK,FunctionK,Procedure_headK,Function_headK} ModuleKind;
typedef enum {ArrayK,FieldK,SimpleK,VarK,ConstK,TypeK,ParaK} DeclKind;
typedef enum {EqualK,AssignK,ProcK,CompK,IfK,RepeatK,WhileK,LabelK,ForK,CaseK,GotoK} StmtKind;
typedef enum {OpK,IntK,RealK,CharK,StringK,IdK,Case_exprK,FactorK,BoolK,DirK} ExprKind;
typedef enum {IntegerT,BooleanT,CharacterT,RealT,StringT,IDT} ExprType;

#define MAXCHILDREN 20
typedef struct treeNode{
	struct treeNode * child[MAXCHILDREN];
	struct treeNode * sibling;
	int lineno;
	NodeKind nodekind;
	union {ModuleKind module;StmtKind stmt;ExprKind expr;DeclKind decl;} kind;
	union {TokenType op;int label;int direction;int intval;char charval;float realval;char* strval;char* name;} attr;
	ExprType type;
} TreeNode;
typedef TreeNode * TreePtr;

#endif