%{

#include<stdio.h>
#include<iostream>
#include<string.h>
#include "test1.hpp"
#include <vector>

using namespace std;
symbol_table test;

int flag = 1;
char *empty_string = strdup("");


extern my_stack_t *ptr_my_stack;

void yyerror(const char *error_msg);

void init(my_stack_t *ptr_my_stack);
void push(my_stack_t *ptr_my_stack, int ind_lev);

int counter = 0;
int for_scope = 0;
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;
int scope_count;
extern "C"
{
    int yyparse(void);
    int yylex(void);
    int yywrap()
    {
        return 1;
    }
}


%}

%locations
%union {
    int indentation_level;
    char *text;
}

%start input_file

%token <indentation_level> T_Indent T_Dedent 

%token <text> T_import T_True T_False T_not T_and T_or T_if T_else T_elif T_for T_in T_range T_list T_plus T_minus T_star T_divide T_modulus T_LT T_GT T_LTE T_GTE T_EQ T_NEQ T_semicolon T_colon T_comma T_assignment T_left_sq_b T_right_sq_b T_left_par T_right_par T_number T_identifier T_string T_Newline 

%type <text> input_file statement simple_statement next_simple_statement small_statement import_statement expr_statement assignment_statement assignment_expr or_test and_test not_test comparison arith_exp arith_exp2 factor term constant list_index compound_statement if_statement test optional_if_else suite suite1 repeat_statement elif_statement optional_else for_statement exprlist first_exprlist last_exprlist testlist repeat_test range_fn range_term


%right T_assignment
%left T_or
%left T_and
%left T_not
%left T_in
%left T_EQ T_NEQ
%left T_LT T_LTE T_GT T_GTE
%left T_plus T_minus
%left T_star T_divide T_modulus
%left T_left_par T_right_par

%%

input_file  : T_Newline input_file 
              {vector<string> temp1{$1,$2}; $$ = conversion(temp1);}
            | statement input_file
              {vector<string> temp1{$1,$2}; $$ = conversion(temp1);}
            | {$$ = empty_string;}
            ;

statement   : simple_statement
            | compound_statement
            ;

simple_statement   : small_statement next_simple_statement
                     {vector<string> temp1{$1,$2}; $$ = conversion(temp1);}
                   ;

next_simple_statement   : T_Newline
                        | T_semicolon T_Newline
                          {vector<string> temp1{$1,$2}; $$ = conversion(temp1);}
                        | T_semicolon small_statement next_simple_statement
                          {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
                    
                        ;


small_statement   : expr_statement
                  | import_statement
                  ;

import_statement   : T_import T_identifier
                     {vector<string> temp1{$1,$2}; $$ = conversion(temp1);}
                   ;

expr_statement   : assignment_statement
                 | or_test
                 ;

assignment_statement    : T_identifier T_assignment assignment_expr
                          {
                                if(!test.declaration_exists($1, scope_count))
                                {
                                    test.insert($1, @1.first_line, $3, scope_count, @1.first_column);
                                }
                                else
                                {
                                    int temp2 = test.update_identifier($1, scope_count, $3);
                                }

                                vector<string> temp1{$1,$2,$3}; 
                                $$ = conversion(temp1); 
                              
                          }
                        ;

assignment_expr : or_test {$$ = $1;}
                | T_list T_left_par T_right_par 
                  {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
                | T_left_sq_b T_right_sq_b
                  {vector<string> temp1{$1,$2}; $$ = conversion(temp1);}
                ;

or_test   : T_left_par or_test T_right_par 
            {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
          | or_test T_or and_test 
            {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
          | and_test {$$ = $1;}
          ;

and_test   : and_test T_and not_test 
              {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
           | not_test {$$ = $1;}
           ;

not_test   : not_test T_not comparison 
              {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
           | comparison {$$ = $1;}
           ;

comparison  : comparison T_LT arith_exp 
              {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
            | comparison T_GT arith_exp 
              {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
            | comparison T_EQ arith_exp 
              {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
            | comparison T_GTE arith_exp 
              {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
            | comparison T_LTE arith_exp 
              {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
            | comparison T_NEQ arith_exp 
              {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
            | comparison T_in arith_exp 
              {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
            | arith_exp {$$ = $1;}
            ;

arith_exp   : arith_exp T_plus arith_exp2 
              {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
            | arith_exp T_minus arith_exp2 
              {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
            | arith_exp2 {$$ = $1;}
            ;

arith_exp2  : arith_exp2 T_star factor 
              {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
            | arith_exp2 T_divide factor 
              {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
            | arith_exp2 T_modulus factor 
              {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
            | factor {$$ = $1;}
            ;

factor  : T_plus factor
          { vector<string> temp1{$1,$2}; $$ = conversion(temp1);}
        | T_minus factor
          {vector<string> temp1{$1,$2}; $$ = conversion(temp1);}
        | term {$$ = $1;}
        ;

term    : T_identifier
          {
              if(!test.declaration_exists($1, scope_count))
              {
                  flag = 0;
                  printf("variable \' %s \' not declared before\n",$1);

              }
              $$ = $1;

          }
        | constant {$$ = $1;}
        | list_index {$$ = $1;}
        ;

constant    : T_number {$$ = $1;}
            | T_string {$$ = $1;}
            | T_True {$$ = $1;}
            | T_False {$$ = $1;}
            ;

list_index  : T_identifier T_left_sq_b or_test T_right_sq_b
              {
                if(!test.declaration_exists($1, scope_count))
                {
                    flag = 0;
                    printf("variable \' %s \' not declared before\n",$1);

                }

                vector<string> temp1{$1,$2,$3,$4}; 
                $$ = conversion(temp1);
                  
              }
            ;


compound_statement  : if_statement
                    | for_statement
                    ;

if_statement    : T_if test T_colon suite elif_statement optional_else
                ;

test    : or_test optional_if_else
          {vector<string> temp1{$1,$2}; $$ = conversion(temp1);}
        ;

optional_if_else    : {$$ = empty_string;}
                    | T_if or_test T_else test
                      {vector<string> temp1{$1,$2,$3,$4}; $$ = conversion(temp1);}
                    ;

suite   : simple_statement
        | T_Newline T_Indent  
          {
              scope_count += 1;
              test.create_map(scope_count);
          }
          suite1
        ;

suite1  : statement T_Dedent
          {
              scope_count -= $2;
          }
        | statement repeat_statement T_Dedent
          {
              scope_count -= $3;
          }
        ;

repeat_statement    : statement repeat_statement
                    | statement
                    ;

elif_statement  : {$$ = empty_string;}
                | T_elif test T_colon suite elif_statement
                ;

optional_else   : {$$ = empty_string;}
                | T_else T_colon suite
                ;

for_statement   : T_for exprlist T_in testlist T_colon suite optional_else
                ;

exprlist    : first_exprlist last_exprlist 
            ;

first_exprlist  : T_identifier
                  {
                    test.insert($1, @1.first_line, "" , scope_count + 1, @1.first_column);
                  }
                ;

last_exprlist   : {$$ = empty_string;}
                | T_comma
                | T_comma first_exprlist last_exprlist
                ;

testlist    : test repeat_test
              {vector<string> temp1{$1,$2}; $$ = conversion(temp1);}
            | range_fn
            ;

repeat_test : {$$ = empty_string;}
            | T_comma
            | T_comma test repeat_test
              {vector<string> temp1{$1,$2,$3}; $$ = conversion(temp1);}
            ;

range_fn : T_range T_left_par range_term T_right_par
           {vector<string> temp1{$1,$2,$3,$4}; $$ = conversion(temp1);}
         | T_range T_left_par range_term T_comma range_term T_right_par
           {vector<string> temp1{$1,$2,$3,$4,$5,$6}; $$ = conversion(temp1);}
         | T_range T_left_par range_term T_comma range_term T_comma range_term T_right_par
           {vector<string> temp1{$1,$2,$3,$4,$5,$6,$7,$8}; $$ = conversion(temp1);}
         ;

range_term  : T_identifier
              {
                  if(!test.declaration_exists($1, scope_count))
                  {
                      flag = 0;
                      printf("variable \' %s \' not declared before\n",$1);

                  }
                  $$ = $1;
              }
            | T_number
            | list_index
            ;






%%

void yyerror(const char *error_msg)
{
    printf("\nSyntax Error at Line %d, Column : %d %s\n",  yylineno, yylloc.last_column,error_msg);
    exit(0);
}

#include<stdio.h>
extern char yytext[];
extern int column;

int main()
{

    #ifdef YYDEBUG
      yydebug = 1;
    #endif

    scope_count = 0;

    ptr_my_stack = (my_stack_t*)malloc(sizeof(my_stack_t));
    init(ptr_my_stack);
    push(ptr_my_stack,0);


    if (!yyparse() && flag) {
            printf("\n\n\nParsing is successful\n\n\n");
        } else {
            printf("unsuccessful\n");
        }
            cout<<"DISPLAY is \n";
        cout << test;
        
        return 0;

}