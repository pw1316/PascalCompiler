#include "global.h"
#include "util.h"

void printToken(TokenType type,const char* p){

}

TreeNode* newStmtNode(StmtKind kind){
	int i;
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	for (i=0;i<MAXCHILDREN;i++) p->child[i] = NULL;
    p->sibling = NULL;
    p->nodekind = StmtK;
    p->kind.stmt = kind;
    p->lineno = lineno;
    return p;
}

TreeNode* newExprNode(ExprKind kind){
	int i;
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	for (i=0;i<MAXCHILDREN;i++) p->child[i] = NULL;
    p->sibling = NULL;
    p->nodekind = ExprK;
    p->kind.stmt = kind;
    p->lineno = lineno;
    return p;
}

TreeNode* newModuleNode(ModuleKind kind){
	int i;
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	for (i=0;i<MAXCHILDREN;i++) p->child[i] = NULL;
    p->sibling = NULL;
    p->nodekind = ModuleK;
    p->kind.stmt = kind;
    p->lineno = lineno;
    return p;
}

TreeNode* newDeclNode(DeclKind kind){
	int i;
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	for (i=0;i<MAXCHILDREN;i++) p->child[i] = NULL;
    p->sibling = NULL;
    p->nodekind = DeclK;
    p->kind.stmt = kind;
    p->lineno = lineno;
    return p;
}

char* copyString(char* s){
	int n;
	char * t;
	if (s==NULL) return NULL;
	n = strlen(s)+1;
	t = malloc(n);
	if (t==NULL) fprintf(listing,"Out of memory error at line %d\n",lineno);
	else strcpy(t,s);
	return t;
}

void printTree(TreeNode* tree){
	int i;
	if(tree){
		if(tree -> nodekind == ModuleK) printf("module:%p\n",tree);
		else if(tree -> nodekind == DeclK) printf("decl:%p\n",tree);
		else if(tree -> nodekind == StmtK) printf("stmt:%p\n",tree);
		else if(tree -> nodekind == ExprK) printf("expr:%p\n",tree);
		else printf("unknown:%p\n",tree);
		if(tree -> sibling){
			printf("%p->sibling:\n",tree);
			printTree(tree->sibling);
		}
		for(i=0;i<MAXCHILDREN;i++){
			if(tree->child[i]){
				printf("%p->child%d:\n",tree,i);
				printTree(tree->child[i]);
			}
		}
	}
}