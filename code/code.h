#ifndef __CODE_H__
#define __CODE_H__

#include "global.h"
#include "sematic.h"

extern FILE * out;
extern int ModuleLbl;
extern int LabelLbl;
extern int JumpLbl;
void generateCode(TreePtr node,symbolNode * tbl);
void generateModule(TreePtr node,symbolNode * tbl);
void generateStmt(TreePtr node,symbolNode * tbl);
void generateExpr(TreePtr node,symbolNode * tbl);
int generateVar(symbolNode * tbl);

#endif