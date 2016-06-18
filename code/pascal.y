%{
#define YYPARSER
#include "global.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreePtr

static TreePtr theTree;
extern FILE * yyin;
int yylex();
int yyerror(char*);
%}
%token NOT
%token MUL DIV IDIV MOD AND
%token PLUS MINUS OR
%token DOT COLON COMMA SEMI ASSIGN EQUAL UNEQUAL GE GT LE LT LP RP LB RB
%token TRUE FALSE MAXINT
%token SYST_BOOLEAN SYST_CHAR SYST_INTEGER SYST_REAL SYST_STRING
%token SYSP_WRITELN SYSP_WRITE SYSP_READLN SYSP_READ
%token PROGRAM TYPE VAR CONST ARRAY RECORD FUNCTION PROCEDURE OF PBEGIN END IF THEN ELSE REPEAT UNTIL WHILE DO FOR TO DOWNTO CASE GOTO
%token ID INTEGER REAL CHAR STRING
%%
program		:PROGRAM ID SEMI routing DOT
				{	$$ = newModuleNode(ProgramK);
					$$ -> child[0] = $4;
					$$ -> lineno = lineno;
					$$ -> attr.name = (char*)$2;
					theTree = $$;}
			|routing DOT
				{	$$ = newModuleNode(ProgramK);
					$$ -> child[0] = $1;
					$$ -> lineno = lineno;
					$$ -> attr.name =NULL;}
			;
routing		:routing_head routing_body
				{	$$ = newModuleNode(RoutingK);
					$$ -> child[0] = $1;
					$$ -> child[1] = $2;
					$$ -> lineno = lineno;}
			;
routing_head:const_part type_part var_part routing_part
				{	$$ = newModuleNode(Routing_headK);
					$$ -> child[0] = $1;
					$$ -> child[1] = $2;
					$$ -> child[2] = $3;
					$$ -> child[3] = $4;
					$$ -> lineno = lineno;}
			;
const_part	:CONST const_expr_list {$$ = $2;}
			| {$$ = NULL;}
			;
const_expr_list:const_expr_list ID EQUAL const_value SEMI
				{	TreePtr p = $1;
					if(p){
						while(p -> sibling) p = p -> sibling;
						p -> sibling = newDeclNode(ConstK);
						p -> sibling -> child[0] = $4;
						p -> sibling -> attr.name = (char*)$2;
						p -> sibling -> lineno = lineno;
					}
					$$ = $1;}
			|ID EQUAL const_value SEMI
				{	$$ = newDeclNode(ConstK);
                    $$ -> child[0] = $3;
                    $$ -> attr.name = (char*)$2;
                    $$ -> lineno = lineno;
				}
			;
const_value	:INTEGER {	$$ = newExprNode(IntK);
						$$ -> attr.intval = atoi((char*)$1);
						$$ -> lineno = lineno;}
			|REAL {		$$ = newExprNode(RealK);
						$$ -> attr.realval = atof((char*)$1);
						$$ -> lineno = lineno;}
			|CHAR {		$$ = newExprNode(CharK);
						if(((char*)$1)[0] == '#') $$ -> attr.charval = atoi((char*)$1 + 1);
						else $$ -> attr.charval = ((char*)$1)[1];
						$$ -> lineno = lineno;}
			|STRING {	$$ = newExprNode(StringK);
						((char*)$1)[strlen((char*)$1) - 1] = 0;
						$$ -> attr.strval = (char*)$1+1;
						$$ -> lineno = lineno;}
			|TRUE {		$$ = newExprNode(BoolK);
						$$ -> attr.intval = 1;
						$$ -> lineno = lineno;}
			|FALSE {	$$ = newExprNode(BoolK);
						$$ -> attr.intval = 0;
						$$ -> lineno = lineno;}
			|MAXINT {	$$ = newExprNode(IntK);
						$$ -> attr.intval = 32767;
						$$ -> lineno = lineno;}
			;
type_part	:TYPE type_decl_list {$$ = $2;}
			| {$$ = NULL;}
			;
type_decl_list 	:type_decl_list type_definition {
												TreePtr p = $1;
                   								if (p){
                   									while(p -> sibling) p = p -> sibling;
                   									p -> sibling = $2;
                   									$$ = $1;
                   								}
                   								else $$ = $2;}
			| type_definition {$$ = $1;}
			;
type_definition	:ID EQUAL type_decl SEMI
					{	$$ = newDeclNode(TypeK);
						$$ -> child[0] = $3;
						$$ -> attr.name = (char*)$1;
						$$ -> lineno = lineno;}
				;
type_decl 	:type_decl_simple {$$ = $1;}
			|type_decl_array {$$ = $1;}
			|type_decl_record {$$ = $1;}
			;
type_decl_simple 	:SYST_BOOLEAN {$$ = newDeclNode(SimpleK);$$ -> type = BooleanT;$$ -> lineno = lineno;}
					|SYST_CHAR {$$ = newDeclNode(SimpleK);$$ -> type = CharacterT;$$ -> lineno = lineno;}
					|SYST_INTEGER {$$ = newDeclNode(SimpleK);$$ -> type = IntegerT;$$ -> lineno = lineno;}
					|SYST_REAL {$$ = newDeclNode(SimpleK);$$ -> type = RealT;$$ -> lineno = lineno;}
					|SYST_STRING {$$ = newDeclNode(SimpleK);$$ -> type = StringT;$$ -> lineno = lineno;}
					|ID {$$ = newDeclNode(SimpleK);$$ -> type = IDT;$$ -> attr.name = (char*)$1;$$ -> lineno = lineno;}
					|const_value DOT DOT const_value {$$ = newDeclNode(SimpleK);$$ -> child[0] = $1;$$ -> child[1] = $4;$$ -> attr.intval = 0;$$ -> lineno = lineno;}
					;
type_decl_array :ARRAY LB type_decl_simple RB OF type_decl_simple
					{	$$ = newDeclNode(ArrayK);
                     	$$->child[0] = $3;
                     	$$->child[1] = $6;
                     	$$ -> lineno = lineno;}
                ;
type_decl_record 	: RECORD field_decl_list END {$$ = $2;}
					;
field_decl_list :field_decl_list field_decl 
					{	TreePtr p = $1;
                        if(p){ 
                        	while(p -> sibling)
                            p = p -> sibling;
                            p -> sibling = $2;
                            $$ = $1; 
                        }
                        else $$ = $2;
                   	}
				|field_decl {$$ = $1;}
				;
field_decl 	:name_list COLON type_decl_simple SEMI
				{ 	$$ = newDeclNode(FieldK);
                	$$ -> child[0] = $1;
                	$$ -> child[1] = $3;
                	$$ -> lineno = lineno;}
            ;
name_list 	:name_list COMMA ID
				{ 	TreePtr p = $1;
                   	if(p){
                   		while (p -> sibling) p = p -> sibling;
                     	p -> sibling = newExprNode(IdK);
                     	p -> sibling -> attr.name = (char*)$3;
                     	p -> sibling -> lineno = lineno;
                     	$$ = $1; 
              		}
                   	else{
                    	$$ = newExprNode(IdK);
		     			$$ -> attr.name=(char*)$3;
		     			$$ -> lineno = lineno;
                   	}}
			|ID { $$ = newExprNode(IdK);
                  $$ -> attr.name = (char*)$1;
                  $$ -> lineno = lineno;
                }
			;
var_part 	:VAR var_decl_list {$$ = $2;}
			| {$$ = NULL;}
			;
var_decl_list 	:var_decl_list var_decl
					{	TreePtr p = $1;
                        if(p){
                        	while (p -> sibling)
                            p = p -> sibling;
                            p -> sibling = $2;
                            $$ = $1; 
                        }
                        else $$ = $2;}  
				|var_decl {$$ = $1;}
				;
var_decl 	:name_list COLON type_decl SEMI
				{	$$ = newDeclNode(VarK);
					$$ -> child[0] = $1;
					$$ -> child[1] = $3;
					$$ -> lineno = lineno;}
			;
routing_part 	:routing_part function_decl
					{	TreePtr p = $1;
                        if(p){ 
                        	while(p -> sibling) p = p -> sibling;
                            p -> sibling = $2;
                            $$ = $1; 
                        }
                        else $$ = $2;}
				|routing_part procedure_decl
					{	TreePtr p = $1;
                        if(p){ 
                        	while(p -> sibling) p = p -> sibling;
                            p -> sibling = $2;
                            $$ = $1; 
                        }
                        else $$ = $2;}
				|function_decl {$$ = $1;}
				|procedure_decl {$$ = $1;}
				| {$$ = NULL;}
				;
function_decl 	:function_head SEMI routing SEMI
					{	$$ = newModuleNode(FunctionK);
						$$ -> child[0] = $1;
						$$ -> child[1] = $3;
						$$ -> lineno = lineno;}
				;
function_head 	:FUNCTION ID parameters COLON type_decl_simple
					{	$$ = newModuleNode(Function_headK);
						$$ -> attr.name = (char*)$2;
						$$ -> lineno = lineno;
						$$ -> child[0] = $3;
						$$ -> child[1] = $5;}
				;
procedure_decl 	:procedure_head SEMI routing SEMI
					{	$$ = newModuleNode(ProcedureK);
						$$ -> child[0] = $1;
						$$ -> child[1] = $3;
						$$ -> lineno = lineno;}
				;
procedure_head 	:PROCEDURE ID parameters
					{	$$ = newModuleNode(Procedure_headK);
						$$ -> attr.name = (char*)$2;
						$$ -> lineno = lineno;
						$$ -> child[0] = $3;}
				;
parameters 	:LP para_decl_list RP {$$ = $2;}
			| {$$ = NULL;}
			;
para_decl_list 	:para_decl_list SEMI para_type_list
					{	TreePtr p = $1;
                        if(p){
                        	while(p -> sibling) p = p -> sibling;
                            p -> sibling = $2;
                            $$ = $1; 
                        }
                        else $$ = $2;}
				|para_type_list {$$ = $1;}
				;
para_type_list 	:var_para_list COLON type_decl_simple
					{	$$ = newDeclNode(ParaK);
						$$ -> child[0] = $1;
                    	$$ -> child[2] = $3;
                   		$$ -> lineno = lineno;}
				|val_para_list COLON type_decl_simple
					{	$$ = newDeclNode(ParaK);
						$$ -> child[1] = $1;
                    	$$ -> child[2] = $3;
                   		$$ -> lineno = lineno;}
                ;
var_para_list 	:VAR name_list {$$ = $2;}
				;
val_para_list 	:name_list {$$ = $1;}
				;
routing_body 	:PBEGIN stmt_list END {$$ = $2;}
				;
stmt_list 	: stmt_list stmt
				{
					TreePtr p = $1;
                    if(p){
                        while(p -> sibling) p = p -> sibling;
                        p -> sibling = $2;
                        $$ = $1; 
                    }
                    else $$ = $2;}
			| {$$ = NULL;}
			;
stmt 	: INTEGER COLON non_label_stmt
			{	$$ = newStmtNode(LabelK);
				$$ -> child[0] = $3;
				$$ -> attr.label = atoi((char*)$1);}
		| non_label_stmt {$$ = newStmtNode(LabelK);$$ -> child[1] = $1;}
		;
non_label_stmt 	: assign_stmt SEMI {$$ = $1;} 
				| proc_stmt SEMI {$$ = $1;}
				| compound_stmt {$$ = $1;}
				| if_stmt {$$ = $1;}
				| repeat_stmt SEMI {$$ = $1;}
				| while_stmt {$$ = $1;}
				| for_stmt {$$ = $1;}
				| case_stmt {$$ = $1;}
				| goto_stmt SEMI {$$ = $1;}
				;
assign_stmt	: ID ASSIGN expression
				{	$$ = newStmtNode(AssignK);
					$$ -> child[0] = $3;
					$$ -> attr.name = (char*)$1;} 
			| ID LB expression RB ASSIGN expression
				{	$$ = newStmtNode(AssignK);
					$$ -> child[1] = $3;
					$$ -> child[2] = $6;
					$$ -> attr.name = (char*)$1;} 
			| ID DOT ID ASSIGN expression
				{	$$ = newStmtNode(AssignK);
					$$ -> child[3] = newExprNode(IdK);
					$$ -> child[3] -> attr.name = (char*)$3;
					$$ -> child[4] = $5;
					$$ -> attr.name = (char*)$1;} 
			;
proc_stmt 	: ID args
				{	$$ = newStmtNode(ProcK);
					$$ -> attr.name = (char*)$1;
					$$ -> child[0] = $2;}
			| SYSP_READ args
				{	$$ = newStmtNode(ProcK);
					$$ -> attr.name = (char*)malloc(5);
					strcpy($$ -> attr.name,"read");
					$$ -> child[0] = $2;}
			| SYSP_READLN args
				{	$$ = newStmtNode(ProcK);
					$$ -> attr.name = (char*)malloc(7);
					strcpy($$ -> attr.name,"readln");
					$$ -> child[0] = $2;}
			| SYSP_WRITE args
				{	$$ = newStmtNode(ProcK);
					$$ -> attr.name = (char*)malloc(6);
					strcpy($$ -> attr.name,"write");
					$$ -> child[0] = $2;}
			| SYSP_WRITELN args
				{	$$ = newStmtNode(ProcK);
					$$ -> attr.name = (char*)malloc(8);
					strcpy($$ -> attr.name,"writeln");
					$$ -> child[0] = $2;}
			;
args 	: LP expression_list RP {$$ = $2;}
		| {$$ = NULL;}
		;
compound_stmt 	: PBEGIN stmt_list END
					{	$$ = newStmtNode(CompK);
						$$ -> child[0] = $2;}
				;
if_stmt : IF expression THEN stmt else_clause
			{	$$ = newStmtNode(IfK);
				$$ -> child[0] = $2;
				$$ -> child[1] = $4;
				$$ -> child[2] = $5;}
		;
else_clause : ELSE stmt {$$ = $2;} 
			| {$$ = NULL;}
			;
repeat_stmt : REPEAT stmt_list UNTIL expression
				{	$$ = newStmtNode(RepeatK);
					$$ -> child[0] = $2;
					$$ -> child[1] = $4;}
			;
while_stmt 	: WHILE expression DO stmt
				{	$$ = newStmtNode(WhileK);
					$$ -> child[0] = $2;
					$$ -> child[1] = $4;}
			;
for_stmt 	: FOR ID ASSIGN expression direction expression DO stmt
				{	$$ = newStmtNode(ForK);
					$$ -> attr.name = (char*)$2;
					$$ -> child[0] = $4;
					$$ -> child[1] = $5;
					$$ -> child[2] = $6;
					$$ -> child[3] = $8;}
			;
direction 	: TO {$$ = newExprNode(DirK);$$ -> attr.direction = 1;}
			| DOWNTO {$$ = newExprNode(DirK);$$ -> attr.direction = 0;}
			;
case_stmt 	: CASE expression OF case_expr_list END
				{	$$ = newStmtNode(CaseK);
					$$ -> child[0] = $2;
					$$ -> child[1] = $4;}
			;
case_expr_list 	: case_expr_list case_expr
					{	TreePtr p = $1;
                   		if(p){
                   			while(p -> sibling) p = p -> sibling;
                   		  	p -> sibling = $2;
                   		  	$$ = $1;
                   		}
                    	else $$ = $2;}
				| case_expr {$$ = $1;}
				;
case_expr 	: const_value COLON stmt SEMI
				{	$$ = newExprNode(Case_exprK);
					$$ -> child[0] = $1;
					$$ -> child[1] = $3;}
			| ID COLON stmt SEMI
				{	$$ = newExprNode(Case_exprK);
					$$ -> attr.name = (char*)$1;
					$$ -> child[1] = $3;}
			;
goto_stmt 	: GOTO INTEGER
				{	$$ = newExprNode(GotoK);
					$$ -> attr.label = atoi((char*)$2);}
			;
expression_list : expression_list COMMA expression
					{	TreePtr p = $1;
                   		if(p){
                   			while(p -> sibling) p = p -> sibling;
                   		  	p -> sibling = $3;
                   		  	$$ = $1;
                   		}
                    	else $$ = $3;}
				| expression {$$ =$1;}
				;
expression 	: expression GE expr
				{	$$ = newExprNode(OpK);
					$$ -> child[0] = $1;
					$$ -> child[1] = $3;
					$$ -> attr.op = GE;}
			| expression GT expr
				{	$$ = newExprNode(OpK);
					$$ -> child[0] = $1;
					$$ -> child[1] = $3;
					$$ -> attr.op = GT;}
			| expression LE expr
				{	$$ = newExprNode(OpK);
					$$ -> child[0] = $1;
					$$ -> child[1] = $3;
					$$ -> attr.op = LE;}
			| expression LT expr
				{	$$ = newExprNode(OpK);
					$$ -> child[0] = $1;
					$$ -> child[1] = $3;
					$$ -> attr.op = LT;}
			| expression EQUAL expr
				{	$$ = newExprNode(OpK);
					$$ -> child[0] = $1;
					$$ -> child[1] = $3;
					$$ -> attr.op = EQUAL;}
			| expression UNEQUAL expr
				{	$$ = newExprNode(OpK);
					$$ -> child[0] = $1;
					$$ -> child[1] = $3;
					$$ -> attr.op = UNEQUAL;}
			| expr {$$ = $1;}
			;
expr 	: expr PLUS term
			{	$$ = newExprNode(OpK);
				$$ -> child[0] = $1;
				$$ -> child[1] = $3;
				$$ -> attr.op = PLUS;}
		| expr MINUS term
			{	$$ = newExprNode(OpK);
				$$ -> child[0] = $1;
				$$ -> child[1] = $3;
				$$ -> attr.op = MINUS;}
		| expr OR term
			{	$$ = newExprNode(OpK);
				$$ -> child[0] = $1;
				$$ -> child[1] = $3;
				$$ -> attr.op = OR;}
		| term {$$ = $1;}
		;
term 	: term MUL factor
			{	$$ = newExprNode(OpK);
				$$ -> child[0] = $1;
				$$ -> child[1] = $3;
				$$ -> attr.op = MUL;}
		| term DIV factor
			{	$$ = newExprNode(OpK);
				$$ -> child[0] = $1;
				$$ -> child[1] = $3;
				$$ -> attr.op = DIV;}
		| term MOD factor
			{	$$ = newExprNode(OpK);
				$$ -> child[0] = $1;
				$$ -> child[1] = $3;
				$$ -> attr.op = MOD;}
		| term AND factor
			{	$$ = newExprNode(OpK);
				$$ -> child[0] = $1;
				$$ -> child[1] = $3;
				$$ -> attr.op = AND;}
		| term IDIV factor
			{	$$ = newExprNode(OpK);
				$$ -> child[0] = $1;
				$$ -> child[1] = $3;
				$$ -> attr.op = IDIV;}
		| factor {$$ = $1;}
		;
factor 	: ID args
			{	$$ = newExprNode(FactorK);
				$$ -> attr.name = (char*)$1;
				$$ -> child[0] = $2;}
		| const_value
			{	$$ = newExprNode(FactorK);
				$$ -> child[1] = $1;}
		| LP expression RP {$$ = $2;}
		| NOT factor
			{	$$ = newExprNode(OpK);
				$$ -> child[0] = $2;
				$$ -> attr.op = NOT;}
		| MINUS factor
			{	$$ = newExprNode(OpK);
				$$ -> child[0] = $2;
				$$ -> attr.op = MINUS;}
		| ID LB expression RB
			{	$$ = newExprNode(FactorK);
				$$ -> attr.name = (char*)$1;
				$$ -> child[2] = $3;}
		| ID DOT ID
			{	$$ = newExprNode(FactorK);
				$$ -> attr.name = (char*)$1;
				$$ -> child[3] = newExprNode(IdK);
				$$ -> child[3] -> attr.name = (char*)$3;}
		;
%%
int yyerror(char * msg){
	printf("Syntax error at line %d: %s\n",lineno,msg);
	return 0;
}

TreePtr parse(void){
	yyin = source;
	yyparse();
	return theTree;
}