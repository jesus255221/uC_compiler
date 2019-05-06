%option yylineno

/* Definition section */
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"

	#define BUF_SIZE 256
	char buf[BUF_SIZE];
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

"+" 	{ printf("%s \t ADD \n", yytext); }
"-"		{ printf("%s \t SUB \n", yytext); }
"*"		{ printf("%s \t MUL \n", yytext); }
"/"		{ printf("%s \t DIV \n", yytext); }
"%"		{ printf("%s \t MOD \n", yytext); }
"++"	{ printf("%s \t INC \n", yytext); }
"--"	{ printf("%s \t DEC \n", yytext); }
"="		{ printf("%s \t ASGN \n", yytext); }
"+=" 	{ printf("%s \t ADDASGN \n", yytext); }
"-="	{ printf("%s \t SUBASGN \n", yytext); }
"*=" 	{ printf("%s \t MULASGN \n", yytext); }
"/="	{ printf("%s \t DIVASGN \n", yytext); }
"%="	{ printf("%s \t MODASGN \n", yytext); }
"<"		{ printf("%s \t LT \n", yytext); }
">"		{ printf("%s \t MT \n", yytext); }
"<="	{ printf("%s \t LTE \n", yytext); }
">="	{ printf("%s \t MTE \n", yytext); }
"=="	{ printf("%s \t EQ \n", yytext); }
"!="	{ printf("%s \t NE \n", yytext); }
"&&"	{ printf("%s \t AND \n", yytext); }
"||" 	{ printf("%s \t OR \n", yytext); }
"!"		{ printf("%s \t NOT \n", yytext); }
"int"	{ printf("%s \t INT \n", yytext); }
"float" { printf("%s \t FLOAT \n", yytext); }
"string" { printf("%s \t STRING \n", yytext); }
"bool" 	{ printf("%s \t BOOL \n", yytext); }
"void" 	{ printf("%s \t VOID \n", yytext); }
"print" { printf("%s \t PRINT \n", yytext); }
"if" 	{ printf("%s \t IF \n", yytext); }
"else" 	{ printf("%s \t ELSE \n", yytext); }
"for"	{ printf("%s \t FOR \n", yytext); }
"while" { printf("%s \t WHILE \n", yytext); }
"true" 	{ printf("%s \t TRUE \n", yytext); }
"false" { printf("%s \t FALSE \n", yytext); }
"return" { printf("%s \t RTN \n", yytext); }
"continue" { printf("%s \t CONTINUE \n", yytext); }
"break" { printf("%s \t BREAK \n", yytext); }

"(" 	{ printf("%s \t LB \n", yytext); }
")"		{ printf("%s \t RB \n", yytext); }
"["		{ printf("%s \t LSB \n", yytext); }
"]"		{ printf("%s \t RSB \n", yytext); }
"{"		{ printf("%s \t LCB \n", yytext); }
"}"		{ printf("%s \t RCB \n", yytext); }
";"		{ printf("%s \t SEMICOLON \n", yytext); }
","		{ printf("%s \t COMMA \n", yytext); }


{cpp_comment} { printf("%s \t C++ Comment \n", yytext); comment_line++; }
"/*" { printf("%s", yytext); BEGIN(c_comment);}
<c_comment>[^*\n]* { printf("%s", yytext); }
<c_comment>"*"+[^*/\n]* { printf("%s", yytext); }
<c_comment>\n { printf("\n"); comment_line++; }
<c_comment>"*"+"/" { printf("%s \t C Comment \n", yytext); comment_line++; BEGIN(INITIAL);}

"\"" { printf("%s \t QUOTA \n", yytext); BEGIN(string); }
<string>([^\\\"]|\\\")* { printf("%s \t STR_CONST \n", yytext); }
<string>\" { printf("%s \t QUOTA \n", yytext); BEGIN(INITIAL); }


{id}	{ printf("%s \t ID \n", yytext); }
{number} { printf("%s \t I_CONST \n", yytext); }
{f_number} { printf("%s \t F_CONST \n", yytext); }
{blank_chars} {}
\n			{;}

<<EOF>> { printf("\nParse over, the line number is %d\n\n", yylineno - 1); 
		printf("comment: %d lines\n", comment_line);
		return 0;}


%%

/*	C Code section */
int yywrap(void)
{
    return 1;
}
