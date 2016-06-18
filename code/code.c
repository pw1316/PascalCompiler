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
			generateExpr(node,tbl,0,9);
			break;
	}
	generateCode(node->sibling,tbl);
}

void generateModule(TreePtr node,symbolNode * tbl){
	int i;
	varNode * varL;
	procNode * procL;
	switch(node->kind.module){
		case RoutingK:
			generateCode(node->child[0]->child[3],tbl);/*function and procedures*/
			fprintf(out,"MAIN:\n");
			generateCalleeHead();
			generateVar(tbl);/*push var*/
			generateCode(node->child[1],tbl);/*program body*/
			generateCalleeTail();
			break;
		case ProcedureK:
		case FunctionK:
			fprintf(out,"FUNC%d:\n",ModuleLbl);
			generateCalleeHead();
			procL = lookupProcTbl(tbl,node->child[0]->attr.name,0);/*find in table*/
			procL->label = ModuleLbl;/*save label*/
			ModuleLbl++;
			generateVar(procL->tbl);/*push local var*/
			generateCode(node->child[1]->child[1],procL->tbl);/*program body*/
			varL = procL->tbl->var_part->next;
			if(procL->returntype != cVoidT){
				if(varL->type == cIntT || varL->type == cRealT){
					fprintf(out,"  lw $v0,%d($fp)\n", -(varL->memoffset));
				}
				else if(varL->type == cCharT || varL->type == cBoolT){
					fprintf(out,"  lb $v0,%d($fp)\n", -(varL->memoffset));
				}
				else if(varL->type == cStringT){
					fprintf(out,"  la $v0,BUF%d\n",StrBuf);
					fprintf(out,"  addi $t1,$zero,0\n");//t1=0
					fprintf(out,"  add $t2,$fp,$t1:\n");//t2=src addr
					fprintf(out,"JUMP%d:\n", JumpLbl);
					fprintf(out,"  lb $t3,%d($t2)\n", -(varL->memoffset));
					fprintf(out,"  sb $t3,0($v0)\n");
					fprintf(out,"  addi $v0,$v0,1\n");
					fprintf(out,"  addi $t2,$t2,1\n");
					fprintf(out,"  addi $t1,$t1,1\n");
					fprintf(out,"  subi $t4,$t1,256\n");
					fprintf(out,"  bne $t4,$zero,JUMP%d\n",JumpLbl);
					fprintf(out,"  la $v0,BUF%d\n",StrBuf);
					JumpLbl++;
					StrBuf++;
				}
			}
			generateCalleeTail();
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
				fprintf(out,"LABEL%d:\n", node->attr.label);
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
						fprintf(out,"  sw $t0,%d($fp)\n", -(varL->memoffset));
					}
					else if(varL->type == cCharT || varL->type == cBoolT){
						fprintf(out,"  sb $t0,%d($fp)\n", -(varL->memoffset));
					}
					else if(varL->type == cStringT){
						fprintf(out,"  addi $t1,$zero,0\n");//t1=0
						fprintf(out,"  addi $t2,$fp,$t1:\n");//t2=fp
						fprintf(out,"JUMP%d:\n", JumpLbl);
						fprintf(out,"  lb $t3,0($t0)\n");//t3=t0[0]
						fprintf(out,"  sb $t3,%d($t2)\n", -(varL->memoffset));
						fprintf(out,"  addi $t0,$t0,1\n");
						fprintf(out,"  addi $t1,$t1,1\n");
						fprintf(out,"  addi $t2,$t2,1\n");
						fprintf(out,"  subi $t4,$t1,256\n");
						fprintf(out,"  bne $t4,$zero,JUMP%d\n",JumpLbl);
						JumpLbl++;
					}
				}
			}
			else if(node->child[1]){/*ID[expression] := expression*/
				varL = lookupVarTbl(tbl,node->attr.name,0);
				if(varL){
					generateCode(node->child[1],tbl);
					fprintf(out,"  addi $s1,$t0,0\n");
					fprintf(out,"  addi $s1,$s1,%d\n",-(varL->min));
					generateCode(node->child[2],tbl);
					if(varL->subtype == cIntT || varL->subtype == cRealT){
						fprintf(out,"  sll $s1,$s1,2\n");
						fprintf(out,"  add $s1,$s1,$fp\n");
						fprintf(out,"  sw $t0,%d($s1)\n", -(varL->memoffset));
					}
					else if(varL->type == cCharT || varL->type == cBoolT){
						fprintf(out,"  add $s1,$s1,$fp\n");
						fprintf(out,"  sb $t0,%d($s1)\n", -(varL->memoffset));
					}
					else if(varL->type == cStringT){
						fprintf(out,"  sll $s1,$s1,8\n");
						fprintf(out,"  add $s1,$s1,$fp\n");
						fprintf(out,"  addi $t1,$zero,0\n");//t1=0
						fprintf(out,"  addi $t2,$s1,$t1:\n");//t2=fp
						fprintf(out,"JUMP%d:\n", JumpLbl);
						fprintf(out,"  lb $t3,0($t0)\n");//t3=t0[0]
						fprintf(out,"  sb $t3,%d($t2)\n", -(varL->memoffset));
						fprintf(out,"  addi $t0,$t0,1\n");
						fprintf(out,"  addi $t1,$t1,1\n");
						fprintf(out,"  addi $t2,$t2,1\n");
						fprintf(out,"  subi $t4,$t1,256\n");
						fprintf(out,"  beq $t4,$zero,JUMP%d\n",JumpLbl);
						JumpLbl++;
					}
				}
			}
			else if(node->child[3]){/*ID.ID := expression*/
				varL = lookupVarTbl(tbl,node->attr.name,0);
				if(varL){
					varLL = varL->member->next;
					while(varLL){
						printf("member name:%s\n", varLL->name);
						if(strcmp(varLL->name,node->child[3]->attr.name) == 0){
							off = varLL->memoffset;
							break;
						}
						varLL = varLL->next;
					}
					generateCode(node->child[4],tbl);
					if(varLL->type == cIntT || varLL->type == cRealT){
						fprintf(out,"  sw $t0,%d($fp)\n", -(varL->memoffset)+off);
					}
					else if(varLL->type == cCharT || varLL->type == cBoolT){
						fprintf(out,"  sb $t0,%d($fp)\n", -(varL->memoffset)+off);
					}
					else if(varLL->type == cStringT){
						fprintf(out,"  addi $t1,$zero,0\n");//t1=0
						fprintf(out,"  addi $t2,$s1,$t1:\n");//t2=fp
						fprintf(out,"JUMP%d:\n", JumpLbl);
						fprintf(out,"  lb $t3,0($t0)\n");//t3=t0[0]
						fprintf(out,"  sb $t3,%d($t2)\n", -(varL->memoffset)+off);
						fprintf(out,"  addi $t0,$t0,1\n");
						fprintf(out,"  addi $t1,$t1,1\n");
						fprintf(out,"  addi $t2,$t2,1\n");
						fprintf(out,"  subi $t4,$t1,256\n");
						fprintf(out,"  beq $t4,$zero,JUMP%d\n",JumpLbl);
						JumpLbl++;
					}
				}
			}
			break;
	}
}

void generateExpr(TreePtr node,symbolNode * tbl,int start,int end){
	int i,off;
	constNode * constL;
	typeNode * typeL;
	varNode * varL;
	varNode * varLL;
	procNode * procL;
	TreePtr arg;
	switch(node->kind.expr){
		case FactorK:
			if(node->child[1]){/*const value*/
				switch(node->child[1]->kind.expr){
					case IntK:
					case RealK:
					case BoolK:
						fprintf(out,"  addi $t%d,$zero,%d\n",start,node->child[1]->attr.intval);
						break;
					case CharK:
						fprintf(out,"  addi $t%d,$zero,%d\n",start,node->child[1]->attr.charval);
						break;
					case StringK:
						fprintf(out,"  la $t%d,BUF%d\n",start,StrBuf);
						if(start == end){
							fprintf(out,"  addi $sp,$sp,-4\n");
							fprintf(out,"  sw $t%d,0($sp)\n",(start+1)%10);	
						}
						fprintf(out,"  addi $t%d,$zero,%d\n",(start+1)%10,strlen(node->child[1]->attr.strval));
						fprintf(out,"  sb $t%d,0($t%d)\n",(start+1)%10,start);
						for(i = 0;i < strlen(node->child[1]->attr.strval) && i < 255 ;i++){
							fprintf(out,"  addi $t%d,$zero,%d\n",(start+1)%10,node->child[1]->attr.strval[i]);
							fprintf(out,"  sb $t%d,%d($t%d)\n",(start+1)%10,i+1,start);
						}
						if(start == end){
							fprintf(out,"  lw $t%d,0($sp)\n",(start+1)%10);	
							fprintf(out,"  addi $sp,$sp,4\n");
						}
						StrBuf++;
						break;
				}
			}
			else if(node->child[2]){/*ID[expr]*/
				generateExpr(node->child[2],tbl,start,end);//t[start] = index
				varL = lookupVarTbl(tbl,node->attr.name,0);
				if(varL){
					fprintf(out,"  addi $t%d,$t%d,%d\n",start,start,-(varL->min));
					if(varL->subtype == cIntT || varL->subtype == cRealT){
						fprintf(out,"  sll $t%d,$t%d,2\n",start,start);
						fprintf(out,"  add $t%d,$t%d,$fp\n",start,start);
						fprintf(out,"  lw $t%d,%d($t%d)\n",start,-(varL->memoffset),start);
					}
					else if(varL->subtype == cCharT || varL->subtype == cBoolT){
						fprintf(out,"  add $t%d,$t%d,$fp\n",start,start);
						fprintf(out,"  lw $t%d,%d($t%d)\n",start,-(varL->memoffset),start);
					}
					else if(varL->subtype == cStringT){
						fprintf(out,"  sll $t%d,$t%d,8\n",start,start);
						fprintf(out,"  add $t%d,$t%d,$fp\n",start,start);
						fprintf(out,"  addi $t%d,$t%d,%d\n",start,start,-(varL->memoffset));
					}
				}
			}
			else if(node->child[3]){/*ID.ID*/
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
					if(varLL->type == cIntT || varLL->type == cRealT){
						fprintf(out,"  lw $t%d,%d($fp)\n",start,-(varL->memoffset)+off);
					}
					else if(varLL->type == cCharT || varLL->type == cBoolT){
						fprintf(out,"  lb $t%d,%d($fp)\n",start,-(varL->memoffset)+off);
					}
					else if(varLL->type == cStringT){
						fprintf(out,"  addi $t%d,$fp,%d\n",start,-(varL->memoffset)+off);
					}
				}
			}
			else if(node->child[1]){/*ID(args)*/
				procL = lookupProcTbl(tbl,node->attr.name,0);
				if(procL){
					i = 0;
					varL = procL->params->next;
					arg = node->child[1];
					while(varL && i < 4){
						generateCode(arg,tbl);
						fprintf(out,"  addi $a%d,$t%d,0\n",i,start);
						i++;
						varL = varL->next;
						arg = arg->sibling;
					}
					generateCallerHead();
					fprintf(out,"  jal FUNC%d\n",procL->label);
					generateCallerTail();
					fprintf(out,"  addi $t%d,$v0,0\n",start);
				}
			}
			else{/*ID*/
				constL = lookupConstTbl(tbl,node->attr.name,0);
				varL = lookupVarTbl(tbl,node->attr.name,0);
				procL = lookupProcTbl(tbl,node->attr.name,0);
				if(constL){
					switch(constL->type){
						case cIntT:
						case cRealT:
						case cBoolT:
							fprintf(out,"  addi $t%d,$zero,%d\n",start,constL->val.d);
							break;
						case cCharT:
							fprintf(out,"  addi $t%d,$zero,%d\n",start,constL->val.c);
							break;
						case cStringT:
							fprintf(out,"  la $t%d,BUF%d\n",start,StrBuf);
							if(start == end){
								fprintf(out,"  addi $sp,$sp,-4\n");
								fprintf(out,"  sw $t%d,0($sp)\n",(start+1)%10);	
							}
							fprintf(out,"  addi $t%d,$zero,%d\n",(start+1)%10,strlen(constL->val.str));
							fprintf(out,"  sb $t%d,0($t%d)\n",(start+1)%10,start);
							for(i = 0;i < strlen(constL->val.str) && i < 255 ;i++){
								fprintf(out,"  addi $t%d,$zero,%d\n",(start+1)%10,constL->val.str[i]);
								fprintf(out,"  sb $t%d,%d($t%d)\n",(start+1)%10,i+1,start);
							}
							if(start == end){
								fprintf(out,"  lw $t%d,0($sp)\n",(start+1)%10);	
								fprintf(out,"  addi $sp,$sp,4\n");
							}
							StrBuf++;
							break;
					}
				}
				else if (varL){
					if(varL->type == cIntT || varL->type == cRealT){
						fprintf(out,"  lw $t%d,%d($fp)\n",start,-(varL->memoffset));
					}
					else if(varL->type == cCharT || varL->type == cBoolT){
						fprintf(out,"  lw $t%d,%d($fp)\n",start,-(varL->memoffset));
					}
					else if(varL->type == cStringT){
						fprintf(out,"  addi $t%d,$fp,%d\n",start,-(varL->memoffset));
					}
				}
				else if(procL){
					generateCallerHead();
					fprintf(out,"  jal FUNC%d\n",procL->label);
					generateCallerTail();
					fprintf(out,"  addi $t%d,$v0,0\n",start);
				}
			}
			break;
		case OpK:
			switch(node->attr.op){
				case NOT:
					generateExpr(node->child[0],tbl,start,end);
					fprintf(out, "  sltu $t%d,$zero,$t%d\n",start,start);
					fprintf(out, "  xori $t%d,$t%d,1\n", start,start);
					break;
				case MINUS:
					typeL = getExprType(node->child[0],tbl);
					if(node->child[1]){
						if(typeL->type == cRealT){
							fprintf(out, " #floating not implemented yet\n");
						}
						else{
							if(start == end){
								fprintf(out,"  addi $sp,$sp,-4\n");
								fprintf(out,"  sw $t%d,0($sp)\n",(start+1)%10);
								generateExpr(node->child[0],tbl,start,(end+1)%10);
								generateExpr(node->child[0],tbl,(start+1)%10,(end+1)%10);
								fprintf(out,"  sub $t%d,$t%d,$t%d\n", start,start,(start+1)%10);
								fprintf(out,"  lw $t%d,0($sp)\n",(start+1)%10);	
								fprintf(out,"  addi $sp,$sp,4\n");
							}
							else{
								generateExpr(node->child[0],tbl,start,end);
								generateExpr(node->child[0],tbl,(start+1)%10,end);
								fprintf(out,"  sub $t%d,$t%d,$t%d\n", start,start,(start+1)%10);
							}
						}
					}
					else{
						generateExpr(node->child[0],tbl,start,end);
						if(typeL->type == cRealT){
							fprintf(out, " #floating not implemented yet\n");
						}
						else{
							fprintf(out, "  sub $t%d,$zero,$t%d\n", start,start);
						}
					}
					break;
				case MUL:
					if(start == end){
						fprintf(out,"  addi $sp,$sp,-4\n");
						fprintf(out,"  sw $t%d,0($sp)\n",(start+1)%10);
						generateExpr(node->child[0],tbl,start,(end+1)%10);
						generateExpr(node->child[0],tbl,(start+1)%10,(end+1)%10);
						fprintf(out, "  mult $t%d,$t%d\n", start,(start+1)%10);
						fprintf(out, "  mflo $t%d\n", start);
						fprintf(out,"  lw $t%d,0($sp)\n",(start+1)%10);	
						fprintf(out,"  addi $sp,$sp,4\n");
					}
					else{
						generateExpr(node->child[0],tbl,start,end);
						generateExpr(node->child[0],tbl,(start+1)%10,end);
						fprintf(out, "  mult $t%d,$t%d\n", start,(start+1)%10);
						fprintf(out, "  mflo $t%d\n", start);
					}
					break;
				case DIV:
				case IDIV:
					if(start == end){
						fprintf(out,"  addi $sp,$sp,-4\n");
						fprintf(out,"  sw $t%d,0($sp)\n",(start+1)%10);
						generateExpr(node->child[0],tbl,start,(end+1)%10);
						generateExpr(node->child[0],tbl,(start+1)%10,(end+1)%10);
						fprintf(out, "  div $t%d,$t%d\n", start,(start+1)%10);
						fprintf(out, "  mflo $t%d\n", start);
						fprintf(out,"  lw $t%d,0($sp)\n",(start+1)%10);	
						fprintf(out,"  addi $sp,$sp,4\n");
					}
					else{
						generateExpr(node->child[0],tbl,start,end);
						generateExpr(node->child[0],tbl,(start+1)%10,end);
						fprintf(out, "  div $t%d,$t%d\n", start,(start+1)%10);
						fprintf(out, "  mflo $t%d\n", start);
					}
					break;
				case MOD:
					if(start == end){
						fprintf(out,"  addi $sp,$sp,-4\n");
						fprintf(out,"  sw $t%d,0($sp)\n",(start+1)%10);
						generateExpr(node->child[0],tbl,start,(end+1)%10);
						generateExpr(node->child[0],tbl,(start+1)%10,(end+1)%10);
						fprintf(out, "  div $t%d,$t%d\n", start,(start+1)%10);
						fprintf(out, "  mfhi $t%d\n", start);
						fprintf(out,"  lw $t%d,0($sp)\n",(start+1)%10);	
						fprintf(out,"  addi $sp,$sp,4\n");
					}
					else{
						generateExpr(node->child[0],tbl,start,end);
						generateExpr(node->child[0],tbl,(start+1)%10,end);
						fprintf(out, "  div $t%d,$t%d\n", start,(start+1)%10);
						fprintf(out, "  mfhi $t%d\n", start);
					}
					break;
				case AND:
					if(start == end){
						fprintf(out,"  addi $sp,$sp,-4\n");
						fprintf(out,"  sw $t%d,0($sp)\n",(start+1)%10);
						generateExpr(node->child[0],tbl,start,(end+1)%10);
						generateExpr(node->child[0],tbl,(start+1)%10,(end+1)%10);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", start,start);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", (start+1)%10,(start+1)%10);
						fprintf(out, "  and $t%d,$t%d,$t%d\n", start,start,(start+1)%10);
						fprintf(out,"  lw $t%d,0($sp)\n",(start+1)%10);	
						fprintf(out,"  addi $sp,$sp,4\n");
					}
					else{
						generateExpr(node->child[0],tbl,start,end);
						generateExpr(node->child[0],tbl,(start+1)%10,end);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", start,start);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", (start+1)%10,(start+1)%10);
						fprintf(out, "  and $t%d,$t%d,$t%d\n", start,start,(start+1)%10);
					}
					break;
				case PLUS:
					typeL = getExprType(node,tbl);
					if(start == end){
						fprintf(out,"  addi $sp,$sp,-4\n");
						fprintf(out,"  sw $t%d,0($sp)\n",(start+1)%10);
						generateExpr(node->child[0],tbl,start,(end+1)%10);
						generateExpr(node->child[0],tbl,(start+1)%10,(end+1)%10);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", start,start);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", (start+1)%10,(start+1)%10);
						fprintf(out, "  and $t%d,$t%d,$t%d\n", start,start,(start+1)%10);
						fprintf(out,"  lw $t%d,0($sp)\n",(start+1)%10);	
						fprintf(out,"  addi $sp,$sp,4\n");
					}
					else{
						generateExpr(node->child[0],tbl,start,end);
						generateExpr(node->child[0],tbl,(start+1)%10,end);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", start,start);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", (start+1)%10,(start+1)%10);
						fprintf(out, "  and $t%d,$t%d,$t%d\n", start,start,(start+1)%10);
					}
					break;
				case OR:
					if(start == end){
						fprintf(out,"  addi $sp,$sp,-4\n");
						fprintf(out,"  sw $t%d,0($sp)\n",(start+1)%10);
						generateExpr(node->child[0],tbl,start,(end+1)%10);
						generateExpr(node->child[0],tbl,(start+1)%10,(end+1)%10);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", start,start);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", (start+1)%10,(start+1)%10);
						fprintf(out, "  or $t%d,$t%d,$t%d\n", start,start,(start+1)%10);
						fprintf(out,"  lw $t%d,0($sp)\n",(start+1)%10);	
						fprintf(out,"  addi $sp,$sp,4\n");
					}
					else{
						generateExpr(node->child[0],tbl,start,end);
						generateExpr(node->child[0],tbl,(start+1)%10,end);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", start,start);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", (start+1)%10,(start+1)%10);
						fprintf(out, "  or $t%d,$t%d,$t%d\n", start,start,(start+1)%10);
					}
					break;
				case GE:
					if(start == end){
						fprintf(out,"  addi $sp,$sp,-4\n");
						fprintf(out,"  sw $t%d,0($sp)\n",(start+1)%10);
						generateExpr(node->child[0],tbl,start,(end+1)%10);
						generateExpr(node->child[0],tbl,(start+1)%10,(end+1)%10);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", start,start);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", (start+1)%10,(start+1)%10);
						fprintf(out, "  slt $t%d,$t%d,$t%d\n", start,start,(start+1)%10);
						fprintf(out, "  xori $t%d,$t%d,1\n", start,start);
						fprintf(out,"  lw $t%d,0($sp)\n",(start+1)%10);	
						fprintf(out,"  addi $sp,$sp,4\n");
					}
					else{
						generateExpr(node->child[0],tbl,start,end);
						generateExpr(node->child[0],tbl,(start+1)%10,end);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", start,start);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", (start+1)%10,(start+1)%10);
						fprintf(out, "  slt $t%d,$t%d,$t%d\n", start,start,(start+1)%10);
						fprintf(out, "  xori $t%d,$t%d,1\n", start,start);
					}
					break;
				case GT:
					if(start == end){
						fprintf(out,"  addi $sp,$sp,-4\n");
						fprintf(out,"  sw $t%d,0($sp)\n",(start+1)%10);
						generateExpr(node->child[0],tbl,start,(end+1)%10);
						generateExpr(node->child[0],tbl,(start+1)%10,(end+1)%10);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", start,start);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", (start+1)%10,(start+1)%10);
						fprintf(out, "  slt $t%d,$t%d,$t%d\n", start,(start+1)%10,start);
						fprintf(out,"  lw $t%d,0($sp)\n",(start+1)%10);	
						fprintf(out,"  addi $sp,$sp,4\n");
					}
					else{
						generateExpr(node->child[0],tbl,start,end);
						generateExpr(node->child[0],tbl,(start+1)%10,end);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", start,start);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", (start+1)%10,(start+1)%10);
						fprintf(out, "  slt $t%d,$t%d,$t%d\n", start,(start+1)%10,start);
					}
					break;
				case LE:
					if(start == end){
						fprintf(out,"  addi $sp,$sp,-4\n");
						fprintf(out,"  sw $t%d,0($sp)\n",(start+1)%10);
						generateExpr(node->child[0],tbl,start,(end+1)%10);
						generateExpr(node->child[0],tbl,(start+1)%10,(end+1)%10);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", start,start);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", (start+1)%10,(start+1)%10);
						fprintf(out, "  slt $t%d,$t%d,$t%d\n", start,(start+1)%10,start);
						fprintf(out, "  xori $t%d,$t%d,1\n", start,start);
						fprintf(out,"  lw $t%d,0($sp)\n",(start+1)%10);	
						fprintf(out,"  addi $sp,$sp,4\n");
					}
					else{
						generateExpr(node->child[0],tbl,start,end);
						generateExpr(node->child[0],tbl,(start+1)%10,end);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", start,start);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", (start+1)%10,(start+1)%10);
						fprintf(out, "  slt $t%d,$t%d,$t%d\n", start,(start+1)%10,start);
						fprintf(out, "  xori $t%d,$t%d,1\n", start,start);
					}
					break;
				case LT:
					if(start == end){
						fprintf(out,"  addi $sp,$sp,-4\n");
						fprintf(out,"  sw $t%d,0($sp)\n",(start+1)%10);
						generateExpr(node->child[0],tbl,start,(end+1)%10);
						generateExpr(node->child[0],tbl,(start+1)%10,(end+1)%10);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", start,start);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", (start+1)%10,(start+1)%10);
						fprintf(out, "  slt $t%d,$t%d,$t%d\n", start,start,(start+1)%10);
						fprintf(out,"  lw $t%d,0($sp)\n",(start+1)%10);	
						fprintf(out,"  addi $sp,$sp,4\n");
					}
					else{
						generateExpr(node->child[0],tbl,start,end);
						generateExpr(node->child[0],tbl,(start+1)%10,end);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", start,start);
						fprintf(out, "  sltu $t%d,$zero,$t%d\n", (start+1)%10,(start+1)%10);
						fprintf(out, "  slt $t%d,$t%d,$t%d\n", start,start,(start+1)%10);
					}
					break;
				case EQUAL:
					if(start == end){
						fprintf(out,"  addi $sp,$sp,-4\n");
						fprintf(out,"  sw $t%d,0($sp)\n",(start+1)%10);
						generateExpr(node->child[0],tbl,start,(end+1)%10);
						generateExpr(node->child[0],tbl,(start+1)%10,(end+1)%10);
						fprintf(out, "  sub $t%d,$t%d,$t%d\n", start,start,(start+1)%10);
						fprintf(out, "  xori $t%d,$t%d,1\n", start,start);
						fprintf(out,"  lw $t%d,0($sp)\n",(start+1)%10);	
						fprintf(out,"  addi $sp,$sp,4\n");
					}
					else{
						generateExpr(node->child[0],tbl,start,end);
						generateExpr(node->child[0],tbl,(start+1)%10,end);
						fprintf(out, "  slt $t%d,$t%d,$t%d\n", start,start,(start+1)%10);
					}
					break;
				case UNEQUAL:
					if(start == end){
						fprintf(out,"  addi $sp,$sp,-4\n");
						fprintf(out,"  sw $t%d,0($sp)\n",(start+1)%10);
						generateExpr(node->child[0],tbl,start,(end+1)%10);
						generateExpr(node->child[0],tbl,(start+1)%10,(end+1)%10);
						fprintf(out, "  sub $t%d,$t%d,$t%d\n", start,start,(start+1)%10);
						fprintf(out,"  lw $t%d,0($sp)\n",(start+1)%10);	
						fprintf(out,"  addi $sp,$sp,4\n");
					}
					else{
						generateExpr(node->child[0],tbl,start,end);
						generateExpr(node->child[0],tbl,(start+1)%10,end);
						fprintf(out, "  slt $t%d,$t%d,$t%d\n", start,start,(start+1)%10);
					}
					break;
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
							while(roff%4 != 0) {roff++;rsize++;}
							varLL->memoffset = roff;
							roff += 4;
							rsize += 4;
							break;
						case cBoolT:
						case cCharT:
							varLL->size = 1;
							varLL->memoffset = roff;
							roff += 1;
							rsize += 1;
							break;
						case cStringT:
							varLL->size = 256;
							while(roff%4 != 0) {roff++;rsize++;}
							varLL->memoffset = roff;
							roff += 256;
							rsize += 256;
							break;
					}
					varLL = varLL->next;
				}
				varL->size = rsize;
				offset += varL->size;
				while(offset%4 != 0) offset++;
				varL->memoffset = offset;
				break;
		}
		varL = varL->next;
	}
	while(offset%4 !=0) offset++;
	fprintf(out,"  addi $sp,$sp,%d\n",-offset);
}

void generateCalleeHead(){
	int i;
	fprintf(out,"  addi $sp,$sp,-8\n");/*callee-save*/
	fprintf(out,"  sw $ra,4($sp)\n");
	fprintf(out,"  sw $fp,0($sp)\n");
	fprintf(out,"  addi $sp,$sp,-32\n");
	for(i=0;i<8;i++) fprintf(out,"  sw $s%d,%d($sp)\n",i,i*4);
	fprintf(out,"  addi $fp,$sp,0\n");
}

void generateCalleeTail(){
	int i;
	fprintf(out,"  addi $sp,$fp,0\n");/*callee-getback*/
	for(i=0;i<8;i++) fprintf(out,"  lw $s%d,%d($sp)\n",i,i*4);
	fprintf(out,"  addi $sp,$sp,32\n");
	fprintf(out,"  lw $fp,0($sp)\n");
	fprintf(out,"  lw $ra,4($sp)\n");
	fprintf(out,"  addi $sp,$sp,8\n");
	fprintf(out,"  jr $ra\n");
}

void generateCallerHead(){
	int i;
	fprintf(out,"  addi $sp,$sp,-40\n");
	for(i=0;i<10;i++) fprintf(out,"  sw $t%d,%d($sp)\n",i,i*4);
}

void generateCallerTail(){
	int i;
	for(i=0;i<10;i++) fprintf(out,"  lw $t%d,%d($sp)\n",i,i*4);
	fprintf(out,"  addi $sp,$sp,40\n");
}