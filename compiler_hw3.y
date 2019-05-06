/*	Definition section */
%{
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #define MAX_SYMBOL 1024

    extern int yylineno;
    extern int yylex();
    extern void yyerror(char*);
    extern char* yytext;   // Get current token from lex
    extern char buf[256];  // Get current code line from lex

    int Scope_num = 0;

    typedef struct symbol {
        int Index;
        char* Name, Kind, Type;
        int Scope;
        char* Attribute;
        union {
            int i_value;
            double f_value;
            char* s_value;
            bool b_value;
        };
        struct symbol* next_node;
    } Symbol;

    typedef struct scope {
        int Scope_number;
        struct scope* next_scope;
        struct symbol* first_node;
    } Scope;

    /* Symbol table function - you can add new function if needed. */
    int lookup_symbol();
    void create_symbol();
    void insert_symbol();
    void dump_symbol(symbol*);

    void create_scope(Scope*, int);


%}


/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    bool b_val;
    char* type, name;
}

/* Token without return */
%token PRINT
%token IF ELSE FOR WHILE 
%token SEMICOLON COMMA
%token INC DEC
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token LT MT LTE MTE
%token EQ NE 
%token AND OR NOT 
%token RTN CONTINUE BREAK
%token LB RB LSB RSB LCB RCB 
%token QUOTA STR_CONST
%token INT FLOAT BOOL VOID STRING

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%right ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%left ADD SUB 
%left MUL DIV MOD 

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST 
%token <f_val> F_CONST
%token <b_val> TRUE FALSE
%token <name> ID

/* Nonterminal with return, which need to sepcify type */
%type <type> type
%type <f_val> expression equality_expression relational_expression additive_expression 
%type <f_val> multiplicative_expression unary_expression primary_expression

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
	: external_declaration
	| program external_declaration 
;

external_declaration
	: function_definition { dump_symbol(); }
	| declaration_stat
;

function_definition
	: type function_declarator compound_stat
;

function_declarator
    : ID LB RB {

    }
    | ID LB param_list RB
;

param_list
    : param_declaration
    | param_list COMMA param_declaration
;

param_declaration
    : type ID ASGN initializer
    | type ID
;

compound_stat
    : LCB RCB
    | LCB stats RCB
;

stats
    : stat stats
    | stat
;

stat
    : declaration_stat
    | compound_stat
    | expression_stat
    | selection_stat
    | iteration_stat
    | jump_stat
    | print_func
;

declaration_stat
    : type ID ASGN initializer SEMICOLON {
        
    }
    | type ID SEMICOLON {

    }
;

/* actions can be taken when meet the token or rule */

type
    : INT { $$ = "int"; }
    | FLOAT { $$ = "float"; }
    | BOOL { $$ = "bool"; }
    | STRING { $$ = "string"; }
    | VOID { $$ = "void"; }
;

initializer
    : assignment_expression
;

constant
    : I_CONST 
    | F_CONST
    | QUOTA STR_CONST QUOTA
    | TRUE
    | FALSE
;

print_func
    : PRINT LB expression RB SEMICOLON
;

selection_stat
    : IF LB expression RB stat %prec LOWER_THAN_ELSE
    | IF LB expression RB stat ELSE stat
;

expression_stat
    : SEMICOLON
    | expression SEMICOLON
;

expression
    : assignment_expression
;

assignment_expression
    : logical_or_experssion
    | ID assignment_operator assignment_expression
;

assignment_operator
    : ASGN 
    | ADDASGN 
    | SUBASGN 
    | MULASGN 
    | DIVASGN 
    | MODASGN
;

logical_or_experssion
    : logical_and_experssion
    | logical_or_experssion OR logical_and_experssion
;

logical_and_experssion
    : equality_expression
    | logical_and_experssion AND equality_expression
;

equality_expression
	: relational_expression
	| equality_expression EQ relational_expression { $$ = $1 == $3; }
	| equality_expression NE relational_expression { $$ = $1 != $3; }
;

relational_expression
    : additive_expression
    | relational_expression LT additive_expression { $$ = $1 < $3; }
    | relational_expression MT additive_expression { $$ = $1 > $3; }
    | relational_expression LTE additive_expression { $$ = $1 <= $3; }
    | relational_expression MTE additive_expression { $$ = $1 >= $3; }
;

additive_expression
	: multiplicative_expression
	| additive_expression ADD multiplicative_expression { $$ = $1 + $3; }
	| additive_expression SUB multiplicative_expression { $$ = $1 - $3; }
	;

multiplicative_expression
	: unary_expression
	| multiplicative_expression MUL unary_expression { $$ = $1 * $3; }
	| multiplicative_expression DIV unary_expression { 
        if ($3 == 0)
            yyerror("Divide by zero !!");
        else
            $$ = $1 / $3; }
	| multiplicative_expression MOD unary_expression { 
        if ($3 == 0)
            yyerror("Moded by zero !!");
        else
            $$ = $<i_val>1 % $<i_val>3; }
;

unary_expression
    : postfix_expression
    | INC unary_expression { $$ = ++$2; }
    | DEC unary_expression { $$ = --$2; }
    | NOT unary_expression { $$ = !$2; }
    | ADD unary_expression { $$ = $2; }
    | SUB unary_expression { $$ = -$2; }
;

postfix_expression
	: primary_expression
	| postfix_expression LB RB
	| postfix_expression LB argument_expression_list RB
	| postfix_expression INC
	| postfix_expression DEC
;

argument_expression_list
	: assignment_expression
	| argument_expression_list COMMA assignment_expression
;

primary_expression
	: ID
	| constant
	| LB expression RB { $$ = $2; }
;


iteration_stat
	: WHILE LB expression RB stat
	| FOR LB expression_stat expression_stat RB stat
	| FOR LB expression_stat expression_stat expression RB stat
	| FOR LB declaration_stat expression_stat RB stat
	| FOR LB declaration_stat expression_stat expression RB stat
;

jump_stat
    : BREAK SEMICOLON
    | CONTINUE SEMICOLON
    | RTN SEMICOLON
    | RTN expression SEMICOLON
%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;
    yyparse();
	printf("\nTotal lines: %d \n",yylineno);
    return 0;
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

void create_symbol(Scope* s, int Scope_num) {
    Scope* cursor = s;
    while (cursor->Scope_number < Scope_num) {
        cursor = cursor->next_scope;
    }


}
void insert_symbol() {}

int lookup_symbol() { return 0; }

void dump_symbol(symbol* symtbl) {
    if (symtbl) {
        printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
    }
}

void create_scope(Scope* s, int Start_scope_num) {
    Scope* cursor = s;
    int cursor_scope_number = Start_scope_num;
    while (cursor) {
        cursor = cursor->next_scope;
        cursor_scope_number++;
    }
    cursor = malloc(sizeof(Scope));
    cursor->Scope_number = cursor_scope_number;
    cursor->next_scope = NULL;
    cursor->first_node = NULL;
}
