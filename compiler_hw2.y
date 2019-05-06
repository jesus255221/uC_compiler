/*	Definition section */
%{
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <string.h>
    #define MAX_SYMBOL 1024
    #define MAX_SCOPE 1024

    extern int yylineno;
    extern int yylex();
    extern void yyerror(char*);
    extern char* yytext;   // Get current token from lex
    extern char buf[256];  // Get current code line from lex

    int Scope_num = 0;

    typedef struct symbol {
        int Index;
        int Scope;
        char *Name, *Kind, *Type, *Attribute;
        // union {
        //     int i_value;
        //     double f_value;
        //     char* s_value;
        //     bool b_value;
        // };
        struct symbol* next_node;
    } Symbol;

    typedef struct scope {
        int Scope_number;
        int Scope_index;
        struct scope* next_scope;
        Symbol* first_node;
    } Scope;

    // Scope** Scopes = NULL;
    Scope** Scopes;
    // Scope* Scopes = NULL;

    /* Symbol table function - you can add new function if needed. */
    int lookup_symbol();
    void create_symbol(Scope**, int);
    // Scope* create_symbol(Scope*, int);
    void insert_symbol(Scope**, int, char *, char *, char *, char*);
    void dump_symbol(Symbol*);

%}


/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    bool b_val;
    char *type;
    char *name;
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
%type <type> type param_declaration
%type <f_val> expression equality_expression relational_expression additive_expression 
%type <f_val> multiplicative_expression unary_expression primary_expression

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
	: external_declaration {
        if (Scopes == NULL) {
            Scopes = (Scope**) malloc(sizeof(Scope*));
        }
        create_symbol(Scopes, Scope_num);
    }
	| program external_declaration {
        if (Scopes == NULL) {
            Scopes = (Scope**) malloc(sizeof(Scope*));
        }
        create_symbol(Scopes, Scope_num);
    }
;

external_declaration
	: function_definition 
	| declaration_stat
;

function_definition
	: type function_declarator compound_stat
;

function_declarator
    : ID LB RB {
        Scope_num++;
    }
    | ID LB param_list RB {
        Scope_num++;
    }
;

param_list
    : param_declaration
    | param_list COMMA param_declaration 
;

param_declaration
    : type ID {
        // Scopes = create_symbol(Scopes, Scope_num + 1);
        create_symbol(Scopes, Scope_num+1);
    }
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

void create_symbol(Scope** Scopes, int Scope_num) {
    Scope* cursor;
    if (*Scopes == NULL) {
        *Scopes = (Scope*) malloc(sizeof(Scope));
        ((Scope*) *Scopes)->Scope_number = 0;// Init
        ((Scope*) *Scopes)->Scope_index = 0;
        ((Scope*) *Scopes)->next_scope = NULL;
        ((Scope*) *Scopes)->first_node = NULL;
    }
    else {
        cursor = ((Scope*) *Scopes);
        while(cursor->next_scope != NULL) { //Walk to the end
            cursor = cursor->next_scope;
        }
        if (cursor->Scope_number < Scope_num) {
            cursor->next_scope = (Scope*) malloc(sizeof(Scope));
            ((Scope*) cursor->next_scope)->Scope_number = Scope_num;
            ((Scope*) cursor->next_scope)->Scope_index = 0;
            ((Scope*) cursor->next_scope)->next_scope = NULL;
            ((Scope*) cursor->next_scope)->first_node = NULL;
        }
    }
}

// Scope** create_symbol(Scope** Scopes, int Scope_num) {
//     Scope* cursor;
//     if (Scopes == NULL) {
//         Scopes = (Scope**) malloc(sizeof(Scope*));
//         *Scopes = (Scope*) malloc(sizeof(Scope));
//         ((Scope*) *Scopes)->Scope_number = 0;// Init
//         ((Scope*) *Scopes)->Scope_index = 0;
//         ((Scope*) *Scopes)->next_scope = NULL;
//         ((Scope*) *Scopes)->first_node = NULL;
//         return Scopes;
//     }
//     else {
//         cursor = ((Scope*) *Scopes);
//         while(cursor->next_scope != NULL) { //Walk to the end
//             cursor = cursor->next_scope;
//         }
//         if (cursor->Scope_number < Scope_num) {
//             cursor->next_scope = (Scope*) malloc(sizeof(Scope));
//             ((Scope*) cursor->next_scope)->Scope_number = Scope_num;
//             ((Scope*) cursor->next_scope)->Scope_index = 0;
//             ((Scope*) cursor->next_scope)->next_scope = NULL;
//             ((Scope*) cursor->next_scope)->first_node = NULL;
//         }
//         return Scopes;
//     }
// }

// Scope* create_symbol(Scope* Scopes, int Scope_num) {
    
//     if (Scopes == NULL) {
//         Scopes = (Scope*) malloc(sizeof(Scope));
//         Scopes->Scope_number = 0;
//         Scopes->Scope_index = 0;
//         Scopes->next_scope = NULL;
//         Scopes->first_node = NULL;
//     }
//     else {
//         Scope* cursor = Scopes;
//         while (cursor->next_scope != NULL) {
//             cursor = cursor->next_scope;
//         }
//         printf("%d\n", cursor->Scope_number );
//         if (cursor->Scope_number < Scope_num) {
//             cursor->next_scope = (Scope*) malloc(sizeof(Scope));
//             cursor->next_scope->Scope_number = 0;
//             cursor->next_scope->Scope_index = 0;
//             cursor->next_scope->next_scope = NULL;
//             cursor->next_scope->first_node = NULL;
//             printf("%d\n", Scope_num);
//             printf("MALLOC\n");
//         }
//     }
//     return Scopes;
// }

// Scope* insert_symbol(Scope* Scopes, int Scope_num, char *Name, char *Kind, char *Type, char* Attribute) {

//     Scope* current_scope = Scopes;
//     while (current_scope->Scope_number < Scope_num) {
//         current_scope = current_scope->next_scope;
//     }
//     Symbol* current_symbol = current_scope->first_node;
//     if (current_symbol == NULL) {
//         current_symbol = (Symbol*) malloc(sizeof(Symbol));
//     }
//     else {
//         while (current_symbol->next_node != NULL) {
//             if (current_symbol->Name == Name && current_symbol->Scope == Scope_num) {
//                 char msg[1024];
//                 strcpy(msg, "Redeclared ");
//                 strcat(msg, Type);
//                 strcat(msg, "<");
//                 strcat(msg, Name);
//                 strcat(msg, ">");
//                 yyerror(msg);
//                 return Scopes;
//             }
//             else {
//                 current_symbol = current_symbol->next_node;
//             }
//         }
//         current_symbol = (Symbol*) malloc(sizeof(Symbol));
//     }
//     current_symbol->Index = current_scope->Scope_index;
//     current_scope->Scope_index++;
//     current_symbol->Scope = Scope_num;
//     current_symbol->Name = strdup(Name);
//     current_symbol->Kind = strdup(Kind);
//     current_symbol->Type = strdup(Type);
//     current_symbol->Attribute = strdup(Attribute);
//     return Scopes;
// }

// Scope** insert_symbol(Scope** Scopes, int Scope_num, char *Name, char *Kind, char *Type, char* Attribute) {

//     Scope* current_scope = Scopes;
//     while (current_scope->Scope_number < Scope_num) {
//         current_scope = current_scope->next_scope;
//     }
//     Symbol* current_symbol = current_scope->first_node;
//     if (current_symbol == NULL) {
//         current_symbol = (Symbol*) malloc(sizeof(Symbol));
//     }
//     else {
//         while (current_symbol->next_node != NULL) {
//             if (current_symbol->Name == Name && current_symbol->Scope == Scope_num) {
//                 char msg[1024];
//                 strcpy(msg, "Redeclared ");
//                 strcat(msg, Type);
//                 strcat(msg, "<");
//                 strcat(msg, Name);
//                 strcat(msg, ">");
//                 yyerror(msg);
//                 return Scopes;
//             }
//             else {
//                 current_symbol = current_symbol->next_node;
//             }
//         }
//         current_symbol = (Symbol*) malloc(sizeof(Symbol));
//     }
//     current_symbol->Index = current_scope->Scope_index;
//     current_scope->Scope_index++;
//     current_symbol->Scope = Scope_num;
//     current_symbol->Name = strdup(Name);
//     current_symbol->Kind = strdup(Kind);
//     current_symbol->Type = strdup(Type);
//     current_symbol->Attribute = strdup(Attribute);
//     return Scopes;
// }

int lookup_symbol() { return 0; }

void dump_symbol(Symbol* symtbl) {
    if (symtbl) {
        printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
    }
}
