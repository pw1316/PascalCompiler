%{
/*
	Pascal Token Generator
*/
#include "global.h"
#include "pascal.tab.h"
#include "util.h"
#include "scan.h"
char* yytext0;
char tokenString[MAXTOKENLEN+1];
%}
%option noyywrap

alphabet [a-zA-Z]
digit [0-9]

number "-"?{digit}+
char "'"."'"|"#"{number}
real {number}"."{digit}+
string (\").*(\")
id {alphabet}({alphabet}|{digit})*
%%
"not" {return NOT;}

"*" {return MUL;}
"/" {return DIV;}
"div" {return IDIV;}
"mod" {return MOD;}
"and" {return AND;}

"+" {return PLUS;}
"-" {return MINUS;}
"or" {return OR;}

"." {return DOT;}
":" {return COLON;}
"," {return COMMA;}
";" {return SEMI;}
":=" {return ASSIGN;}
"=" {return EQUAL;}
"<>" {return UNEQUAL;}
">=" {return GE;}
">" {return GT;}
"<=" {return LE;}
"<" {return LT;}
"(" {return LP;}
")" {return RP;}
"[" {return LB;}
"]" {return RB;}

"true" {return TRUE;}
"false" {return FALSE;}
"maxint" {return MAXINT;}

"boolean" {return SYST_BOOLEAN;}
"char" {return SYST_CHAR;}
"integer" {return SYST_INTEGER;}
"real" {return SYST_REAL;}
"string" {return SYST_STRING;}

"writeln" {return SYSP_WRITELN;}
"write" {return SYSP_WRITE;}
"readln" {return SYSP_READLN;}
"read" {return SYSP_READ;}

"program" {return PROGRAM;}
"type" {return TYPE;}
"var" {return VAR;}
"const" {return CONST;}
"array" {return ARRAY;}
"record" {return RECORD;}
"function" {return FUNCTION;}
"procedure" {return PROCEDURE;}
"of" {return OF;}
"begin" {return PBEGIN;}
"end" {return END;}
"if" {return IF;}
"then" {return THEN;}
"else" {return ELSE;}
"repeat" {return REPEAT;}
"until" {return UNTIL;}
"while" {return WHILE;}
"do" {return DO;}
"for" {return FOR;}
"to" {return TO;}
"downto" {return DOWNTO;}
"case" {return CASE;}
"goto" {return GOTO;}

{id} {char* p = (char*)malloc(strlen(yytext)+1);p = strdup(yytext);yylval = (TreePtr*)p; return ID;}
{number} {char* p = (char*)malloc(strlen(yytext)+1);p = strdup(yytext);yylval = (TreePtr*)p; return INTEGER;}
{real} {char* p = (char*)malloc(strlen(yytext)+1);p = strdup(yytext);yylval = (TreePtr*)p; return REAL;}
{char} {char* p = (char*)malloc(strlen(yytext)+1);p = strdup(yytext);yylval = (TreePtr*)p; return CHAR;}
{string} {char* p = (char*)malloc(strlen(yytext)+1);p = strdup(yytext);yylval = (TreePtr*)p; return STRING;}
\n {lineno++;}
\t {}
" " {}
%%

TokenType getToken(){
	static int flag = 1;
	TokenType token;
	if(flag){
		flag = 0;
		lineno ++;
		yyin = source;
		yyout = listing;
	}
	token = yylex();
	strcpy(tokenString,yytext);
	printf("\t%d: ",lineno);
    printf("%s\n",tokenString);
	return token;
}