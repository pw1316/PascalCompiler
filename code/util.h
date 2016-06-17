#ifndef __UTIL_H__
#define __UTIL_H__

void printToken(TokenType,const char*);

TreeNode* newStmtNode(StmtKind);

TreeNode* newExprNode(ExprKind);

TreeNode* newModuleNode(ModuleKind);

TreeNode* newDeclNode(DeclKind);

char* copyString(char*);

void printTree(TreeNode* tree);

#endif