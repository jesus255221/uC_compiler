%option yylineno

/* Definition section */
%{
	#include <stdio.h>
	#include <stdbool.h>
	#include "y.tab.h"

	#define BUF_SIZE 256
	char buf[BUF_SIZE];
	#define CONCAT { strncat(buf, yytext, BUF_SIZE - strlen(buf) - 1); }
%}

/* Define regular expression label */

letter [a-zA-Z]
digit [0-9]
id {letter}+({letter}|{digit})*
number {digit}+
f_number {digit}+.{digit}+
cpp_comment \/\/.*$
blank_chars	[ ]+

%x c_comment
%x string

/* Rules section */
%%
	int comment_line = 0;

"+" 	{ CONCAT; return ADD; }
"-"		{ CONCAT; return SUB; }
"*"		{ CONCAT; return MUL; }
"/"		{ CONCAT; return DIV; }
"%"		{ CONCAT; return MOD; }
"++"	{ CONCAT; return INC; }
"--"	{ CONCAT; return DEC; }
"="		{ CONCAT; return ASGN; }
"+=" 	{ CONCAT; return ADDASGN; }
"-="	{ CONCAT; return SUBASGN; }
"*=" 	{ CONCAT; return MULASGN; }
"/="	{ CONCAT; return DIVASGN; }
"%="	{ CONCAT; return MODASGN; }
"<"		{ CONCAT; return LT; }
">"		{ CONCAT; return MT; }
"<="	{ CONCAT; return LTE; }
">="	{ CONCAT; return MTE; }
"=="	{ CONCAT; return EQ; }
"!="	{ CONCAT; return NE; }
"&&"	{ CONCAT; return AND; }
"||" 	{ CONCAT; return OR; }
"!"		{ CONCAT; return NOT; }
"int"	{ CONCAT; return INT; }
"float" { CONCAT; return FLOAT; }
"string" { CONCAT; return STRING; }
"bool" 	{ CONCAT; return BOOL; }
"void" 	{ CONCAT; return VOID; }
"print" { CONCAT; return PRINT; }
"if" 	{ CONCAT; return IF; }
"else" 	{ CONCAT; return ELSE; }
"for"	{ CONCAT; return FOR; }
"while" { CONCAT; return WHILE; }
"true" 	{ CONCAT; return TRUE; }
"false" { CONCAT; return FALSE; }
"return" { CONCAT; return RTN; }
"continue" { CONCAT; return CONTINUE; }
"break" { CONCAT; return BREAK; }

"(" 	{ CONCAT; return LB; }
")"		{ CONCAT; return RB; }
"["		{ CONCAT; return LSB; }
"]"		{ CONCAT; return RSB; }
"{"		{ CONCAT; return LCB; }
"}"		{ CONCAT; return RCB; }
";"		{ CONCAT; return SEMICOLON; }
","		{ CONCAT; return COMMA; }

"}\n" { CONCAT; printf("%d: %s", yylineno, buf); 
		memset(buf, 0, sizeof buf); return RCB;}


{cpp_comment} { CONCAT; comment_line++; }

"/*" { CONCAT; BEGIN(c_comment); }
<c_comment>[^*\n]+ { CONCAT; }
<c_comment>"*" { CONCAT; }
<c_comment>\n { printf("%d: %s\n", yylineno, buf); 
				memset(buf, 0, sizeof buf); }
<c_comment>"*/" { CONCAT; BEGIN(INITIAL); }

"\"" { CONCAT; BEGIN(string); return QUOTA;}
<string>([^\\\"]|\\\")* { CONCAT; return STR_CONST; }
<string>\" { CONCAT; BEGIN(INITIAL); return QUOTA; }


{id}	{ CONCAT; yylval.name = strdup(yytext); return ID;}
{number} { CONCAT; yylval.i_val = atoi(yytext); return I_CONST; }
{f_number} { CONCAT; yylval.f_val = atof(yytext); return F_CONST; }
{blank_chars} { CONCAT; }
\n			{	printf("%d: %s\n", yylineno, buf); 
				memset(buf, 0, sizeof buf); }

<<EOF>> { /* printf("\nParse over, the line number is %d\n\n", yylineno - 1); 
		printf("comment: %d lines\n", comment_line); */
		return 0;}
%%

/*	C Code section */
int yywrap(void)
{
    return 1;
}


