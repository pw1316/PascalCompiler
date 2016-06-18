#include "code.h"

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