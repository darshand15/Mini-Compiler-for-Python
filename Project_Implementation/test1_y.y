%{

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include "test1.hpp"
#include <vector>

#define DEBUG 1

using namespace std;
symbol_table test;

int flag = 1;
int temp_no = 0;
int label_no = 0;
char *empty_string = strdup("");


extern my_stack_t *ptr_my_stack;

quadruple_t *ptr_quad;

void yyerror(const char *error_msg);

void init(my_stack_t *ptr_my_stack);
void push(my_stack_t *ptr_my_stack, int ind_lev);

int counter = 0;
int for_scope = 0;
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;
int scope_count;
string final_int_code;
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
%union 
{
    int indentation_level;
    char *text;

    struct s1 {char *addr; char *code; char *true_l; char *false_l; char *sym_tab_info;} inter_code;

    struct s2 {char *start_r; char *end_r; char *step_r; char *sym_tab_info;} range_icg;

}

%start prog_start

%token <indentation_level> T_Indent T_Dedent 

%token <text> T_import T_True T_False T_not T_and T_or T_if T_else T_elif T_for T_in T_range T_list T_plus T_minus T_star T_divide T_modulus T_LT T_GT T_LTE T_GTE T_EQ T_NEQ T_semicolon T_colon T_comma T_assignment T_left_sq_b T_right_sq_b T_left_par T_right_par T_number T_identifier T_string T_Newline

%type <inter_code> prog_start input_file statement simple_statement next_simple_statement small_statement import_statement expr_statement assignment_statement assignment_expr or_test and_test not_test comparison arith_exp arith_exp2 factor term constant compound_statement if_statement test suite suite_for suite1 repeat_statement elif_statement optional_else for_statement 

%type <text> list_index exprlist first_exprlist last_exprlist range_term

%type <range_icg> testlist range_fn


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

prog_start : input_file
             {
                $$.code = $1.code;
                final_int_code = $1.code;
                
                // printf("\n\n\n\nGenerated Intermediate Code: \n\n%s\n\n\n",$1.code);
                // FILE *fp = fopen("generated_intermediate_code.txt","w");

                // if(fp!=NULL)
                // {
                //   fputs($1.code,fp);
                // }
                // else
                // {
                //   printf("\nError: Unable to open file\n");
                // }

                //disp_quad(ptr_quad);
                

             }
             ;

input_file  : T_Newline input_file 
              {
                // vector<string> temp1{$1,$2}; 
                // $$ = conversion(temp1);

                $$.code = $2.code;
                $$.addr = $2.addr;
                $$.true_l = $2.true_l;
                $$.false_l = $2.false_l;
                $$.sym_tab_info = $2.sym_tab_info;

                #if DEBUG
                printf("\n\ninside input file newline(stmt):\n\n");
                printf("$2:\n%s\n",$2.code);
                #endif

                
                //printf("\n\n\n\n1. Generated Intermediate Code: \n %s\n\n\n",$$.code);

              }
            | statement input_file
              {
                // vector<string> temp1{$1,$2}; 
                // $$ = conversion(temp1);

                vector<string> gen_int_code{$1.code,$2.code};
                $$.code = conversion(gen_int_code);

                #if DEBUG
                printf("\n\ninside input file(stmt):\n\n");
                printf("$1:\n%s\n",$1.code);
                printf("$2:\n%s\n",$2.code);
                #endif

                
                $$.addr = $2.addr;
                $$.true_l = $2.true_l;
                $$.false_l = $2.false_l;

                vector<string> temp_sym_tab{$1.sym_tab_info,$2.sym_tab_info};
                $$.sym_tab_info = conversion(temp_sym_tab);

                //printf("\n\n\n\n2. Generated Intermediate Code: \n %s\n\n\n",$$.code);

              }
            | {
                #if DEBUG
                printf("\n\ninside input file blank(stmt):\n\n");
                printf("$$:\n%s\n",$$.code);
                #endif

                $$.code = empty_string;
                $$.addr = "";
                $$.true_l = "";
                $$.false_l = "";
                $$.sym_tab_info = "";

                //printf("\n\n\n3. Generated Intermediate Code: \n %s\n\n",$$.code);
              }
            ;

statement   : simple_statement
              {
                $$.code = $1.code;
                $$.addr = $1.addr;
                $$.true_l = $1.true_l;
                $$.false_l = $1.false_l;
                $$.sym_tab_info = $1.sym_tab_info;

              }

            | compound_statement
              {
                $$.code = $1.code;
                $$.addr = $1.addr;
                $$.true_l = $1.true_l;
                $$.false_l = $1.false_l;
                $$.sym_tab_info = $1.sym_tab_info;

                #if DEBUG
                printf("\n\ninside stmt (compound stmt):\n\n");
                printf("%s\n",$$.code);
                #endif

              }
            ;

simple_statement   : small_statement next_simple_statement
                     {
                      //  vector<string> temp1{$1,$2}; 
                      //  $$ = conversion(temp1);

                      vector<string> gen_int_code{$1.code,$2.code};
                      $$.code = conversion(gen_int_code);

                      $$.addr = $1.addr;
                      $$.true_l = $1.true_l;
                      $$.false_l = $1.false_l;

                      vector<string> temp_sym_tab{$1.sym_tab_info,$2.sym_tab_info};
                      $$.sym_tab_info = conversion(temp_sym_tab);

                      //printf("\n\n\n\nsimple_stmt Generated Intermediate Code: \n %s\n\n\n",$$.code);

                     }
                   ;

next_simple_statement   : T_Newline
                          {
                            $$.code = "";
                            $$.addr = "";
                            $$.true_l = "";
                            $$.false_l = "";
                            $$.sym_tab_info = "";


                          }

                        | T_semicolon T_Newline
                          {
                            // vector<string> temp1{$1,$2}; 
                            // $$ = conversion(temp1);

                            $$.code = "";
                            $$.addr = "";
                            $$.true_l = "";
                            $$.false_l = "";
                            $$.sym_tab_info = "";


                          }

                        | T_semicolon small_statement next_simple_statement
                          {
                            // vector<string> temp1{$1,$2,$3}; 
                            // $$ = conversion(temp1);

                            vector<string> gen_int_code{$2.code,$3.code};
                            $$.code = conversion(gen_int_code);

                            $$.addr = $2.addr;
                            $$.true_l = $2.true_l;
                            $$.false_l = $2.false_l;
                            
                            vector<string> temp_sym_tab{$2.sym_tab_info,$3.sym_tab_info};
                            $$.sym_tab_info = conversion(temp_sym_tab);


                          }
                    
                        ;


small_statement   : expr_statement
                    {
                      $$.code = $1.code;
                      $$.addr = $1.addr;
                      $$.true_l = $1.true_l;
                      $$.false_l = $1.false_l;
                      $$.sym_tab_info = $1.sym_tab_info;


                    }

                  | import_statement
                    {
                      $$.code = $1.code;
                      $$.addr = $1.addr;
                      $$.true_l = $1.true_l;
                      $$.false_l = $1.false_l;
                      $$.sym_tab_info = $1.sym_tab_info;


                    }
                  ;

import_statement   : T_import T_identifier
                     {
                       vector<string> temp1{$1,$2}; 
                       $$.code = conversion(temp1);

                       $$.addr = "";
                       $$.true_l = "";
                       $$.false_l = "";
                       $$.sym_tab_info = "";

                       
                     }
                   ;

expr_statement   : assignment_statement
                  {
                    $$.code = $1.code;
                    $$.addr = $1.addr;
                    $$.true_l = $1.true_l;
                    $$.false_l = $1.false_l;
                    $$.sym_tab_info = $1.sym_tab_info;


                    //printf("\n\n\n\n expr Generated Intermediate Code: \n %s\n\n\n",$$.code);

                  }

                 | or_test
                  {
                    $$.code = $1.code;
                    $$.addr = $1.addr;
                    $$.true_l = $1.true_l;
                    $$.false_l = $1.false_l;
                    $$.sym_tab_info = $1.sym_tab_info;


                  }
                 ;

assignment_statement    : T_identifier T_assignment assignment_expr
                          {
                                if(!test.declaration_exists($1, scope_count))
                                {
                                    test.insert($1, @1.first_line, $3.sym_tab_info, scope_count, @1.first_column);
                                }
                                else
                                {
                                    int temp2 = test.update_identifier($1, scope_count, $3.sym_tab_info);
                                }

                                //vector<string> temp1{$1,$2,$3}; 
                                //$$ = conversion(temp1); 

                                vector<string> gen_int_code{$3.code,$1,"=",$3.addr,"\n"};
                                $$.code = conversion(gen_int_code);

                                #if DEBUG
                                printf("\ninside assignment expression: %s\n",$$.code);
                                printf("\n$3:%s\n$1:%s\n$2:%s\n$3.addr:%s\n",$3.code,$1,$2,$3.addr);
                                #endif

                                $$.addr = $3.addr;
                                $$.true_l = $3.true_l;
                                $$.false_l = $3.false_l;
                                
                                vector<string> temp_sym_tab{$1,"=",$3.sym_tab_info};
                                $$.sym_tab_info = conversion(temp_sym_tab);

                                push_quad(ptr_quad, "=", $3.addr, "", $1);


                          }
                        ;

assignment_expr : or_test 
                  {
                    $$.code = $1.code;
                    $$.addr = $1.addr;
                    $$.true_l = $1.true_l;
                    $$.false_l = $1.false_l;
                    $$.sym_tab_info = $1.sym_tab_info;

                  }

                | T_list T_left_par T_right_par 
                  {
                    vector<string> temp1{$1,$2,$3}; 
                    $$.code = "";
                    $$.addr = conversion(temp1);
                    $$.true_l = "";
                    $$.false_l = "";
                    $$.sym_tab_info = conversion(temp1);


                  }

                | T_left_sq_b T_right_sq_b
                  {
                    vector<string> temp1{$1,$2}; 
                    $$.code = "";
                    $$.addr = conversion(temp1);
                    $$.true_l = "";
                    $$.false_l = "";
                    $$.sym_tab_info = conversion(temp1);

                  }
                ;

or_test   : or_test T_or and_test 
            {
              // vector<string> temp1{$1,$2,$3}; 
              // $$ = conversion(temp1);

              $$.addr = $1.addr;

              vector<string> gen_int_code{$1.code,$1.false_l,":\n",$3.code,"\n"};
              $$.code = conversion(gen_int_code);

              vector<string> label_t_temp{$3.true_l,":\n",$1.true_l};
              $$.true_l = conversion(label_t_temp);

              $$.false_l = $3.false_l;

              vector<string> temp_sym_tab{$1.sym_tab_info,$2,$3.sym_tab_info};
              $$.sym_tab_info = conversion(temp_sym_tab);

              

            }
          | and_test 
            {
              $$.code = $1.code;
              $$.addr = $1.addr;
              $$.true_l = $1.true_l;
              $$.false_l = $1.false_l;
              $$.sym_tab_info = $1.sym_tab_info;

            }
          ;

and_test   : and_test T_and not_test 
            {
              // vector<string> temp1{$1,$2,$3}; 
              // $$ = conversion(temp1);

              $$.addr = $1.addr;

              vector<string> gen_int_code{$1.code,$1.true_l,":\n",$3.code,"\n"};
              $$.code = conversion(gen_int_code);

              vector<string> label_t_temp{$3.false_l,":\n",$1.false_l};
              $$.false_l = conversion(label_t_temp);

              $$.true_l = $3.true_l;

              vector<string> temp_sym_tab{$1.sym_tab_info,$2,$3.sym_tab_info};
              $$.sym_tab_info = conversion(temp_sym_tab);


            }
           | not_test 
            {
              $$.code = $1.code;
              $$.addr = $1.addr;
              $$.true_l = $1.true_l;
              $$.false_l = $1.false_l;
              $$.sym_tab_info = $1.sym_tab_info;

            }
           ;

not_test   : T_not not_test 
            {
              // vector<string> temp1{$1,$2,$3}; 
              // $$ = conversion(temp1);

              $$.false_l = $2.true_l;
              $$.true_l = $2.false_l;
              $$.code = $2.code;
              $$.addr = $2.addr;
              vector<string> temp_sym_tab{$1,$2.sym_tab_info};
              $$.sym_tab_info = conversion(temp_sym_tab);
              
            }

           | comparison 
            {
              $$.code = $1.code;
              $$.addr = $1.addr;
              $$.true_l = $1.true_l;
              $$.false_l = $1.false_l;
              $$.sym_tab_info = $1.sym_tab_info;

            }
           ;

comparison  : comparison T_LT arith_exp 
              {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                $$.true_l = t2;

                string temp_l_2 = to_string(label_no);
                string l_no_2 = "L";
                temp_l_2 = l_no_2 + temp_l_2;
                char *t3 = new char[temp_l_2.size() + 1];
                copy(temp_l_2.begin(),temp_l_2.end(), t3);

                ++label_no;
                
                $$.false_l = t3;

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t4 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t4);

                $$.addr = t4;

                ++temp_no;

                vector<string> gen_int_code{$1.code,$3.code,t4,"=",$1.addr,$2,$3.addr,"\n","if",t4,"goto",$$.true_l,"\n","goto",$$.false_l,"\n"};
                $$.code = conversion(gen_int_code);

                string temp_val = string($1.addr) + string($2) + string($3.addr);

                test.insert(temp, @1.first_line, temp_val, scope_count, @1.first_column);

                vector<string> temp_sym_tab{$1.sym_tab_info,$2,$3.sym_tab_info};
                $$.sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, $2, $1.addr, $3.addr, t4);
                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "if", t4, "", t2);
                push_quad(ptr_quad, "Label", "", "", t3);
                push_quad(ptr_quad, "goto", "", "", t3);

              }

            | comparison T_GT arith_exp 
              {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                $$.true_l = t2;

                string temp_l_2 = to_string(label_no);
                string l_no_2 = "L";
                temp_l_2 = l_no_2 + temp_l_2;
                char *t3 = new char[temp_l_2.size() + 1];
                copy(temp_l_2.begin(),temp_l_2.end(), t3);

                ++label_no;
                
                $$.false_l = t3;

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t4 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t4);

                $$.addr = t4;

                ++temp_no;

                vector<string> gen_int_code{$1.code,$3.code,t4,"=",$1.addr,$2,$3.addr,"\n","if",t4,"goto",$$.true_l,"\n","goto",$$.false_l,"\n"};
                $$.code = conversion(gen_int_code);

                string temp_val = string($1.addr) + string($2) + string($3.addr);

                test.insert(temp, @1.first_line, temp_val, scope_count, @1.first_column);

                vector<string> temp_sym_tab{$1.sym_tab_info,$2,$3.sym_tab_info};
                $$.sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, $2, $1.addr, $3.addr, t4);
                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "if", t4, "", t2);
                push_quad(ptr_quad, "Label", "", "", t3);
                push_quad(ptr_quad, "goto", "", "", t3);

              }

            | comparison T_EQ arith_exp 
              {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                $$.true_l = t2;

                string temp_l_2 = to_string(label_no);
                string l_no_2 = "L";
                temp_l_2 = l_no_2 + temp_l_2;
                char *t3 = new char[temp_l_2.size() + 1];
                copy(temp_l_2.begin(),temp_l_2.end(), t3);

                ++label_no;
                
                $$.false_l = t3;

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t4 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t4);

                $$.addr = t4;

                ++temp_no;

                vector<string> gen_int_code{$1.code,$3.code,t4,"=",$1.addr,$2,$3.addr,"\n","if",t4,"goto",$$.true_l,"\n","goto",$$.false_l,"\n"};
                $$.code = conversion(gen_int_code);

                string temp_val = string($1.addr) + string($2) + string($3.addr);

                test.insert(temp, @1.first_line, temp_val, scope_count, @1.first_column);

                vector<string> temp_sym_tab{$1.sym_tab_info,$2,$3.sym_tab_info};
                $$.sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, $2, $1.addr, $3.addr, t4);
                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "if", t4, "", t2);
                push_quad(ptr_quad, "Label", "", "", t3);
                push_quad(ptr_quad, "goto", "", "", t3);

              }

            | comparison T_GTE arith_exp 
              {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                $$.true_l = t2;

                string temp_l_2 = to_string(label_no);
                string l_no_2 = "L";
                temp_l_2 = l_no_2 + temp_l_2;
                char *t3 = new char[temp_l_2.size() + 1];
                copy(temp_l_2.begin(),temp_l_2.end(), t3);

                ++label_no;
                
                $$.false_l = t3;

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t4 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t4);

                $$.addr = t4;

                ++temp_no;

                vector<string> gen_int_code{$1.code,$3.code,t4,"=",$1.addr,$2,$3.addr,"\n","if",t4,"goto",$$.true_l,"\n","goto",$$.false_l,"\n"};
                $$.code = conversion(gen_int_code);

                string temp_val = string($1.addr) + string($2) + string($3.addr);

                test.insert(temp, @1.first_line, temp_val, scope_count, @1.first_column);

                vector<string> temp_sym_tab{$1.sym_tab_info,$2,$3.sym_tab_info};
                $$.sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, $2, $1.addr, $3.addr, t4);
                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "if", t4, "", t2);
                push_quad(ptr_quad, "Label", "", "", t3);
                push_quad(ptr_quad, "goto", "", "", t3);
              
              }

            | comparison T_LTE arith_exp 
              {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                $$.true_l = t2;

                string temp_l_2 = to_string(label_no);
                string l_no_2 = "L";
                temp_l_2 = l_no_2 + temp_l_2;
                char *t3 = new char[temp_l_2.size() + 1];
                copy(temp_l_2.begin(),temp_l_2.end(), t3);

                ++label_no;
                
                $$.false_l = t3;

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t4 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t4);

                $$.addr = t4;

                ++temp_no;

                vector<string> gen_int_code{$1.code,$3.code,t4,"=",$1.addr,$2,$3.addr,"\n","if",t4,"goto",$$.true_l,"\n","goto",$$.false_l,"\n"};
                $$.code = conversion(gen_int_code);

                string temp_val = string($1.addr) + string($2) + string($3.addr);

                test.insert(temp, @1.first_line, temp_val, scope_count, @1.first_column);

                vector<string> temp_sym_tab{$1.sym_tab_info,$2,$3.sym_tab_info};
                $$.sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, $2, $1.addr, $3.addr, t4);
                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "if", t4, "", t2);
                push_quad(ptr_quad, "Label", "", "", t3);
                push_quad(ptr_quad, "goto", "", "", t3);
              
              }

            | comparison T_NEQ arith_exp 
              {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                $$.true_l = t2;

                string temp_l_2 = to_string(label_no);
                string l_no_2 = "L";
                temp_l_2 = l_no_2 + temp_l_2;
                char *t3 = new char[temp_l_2.size() + 1];
                copy(temp_l_2.begin(),temp_l_2.end(), t3);

                ++label_no;
                
                $$.false_l = t3;

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t4 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t4);

                $$.addr = t4;

                ++temp_no;

                vector<string> gen_int_code{$1.code,$3.code,t4,"=",$1.addr,$2,$3.addr,"\n","if",t4,"goto",$$.true_l,"\n","goto",$$.false_l,"\n"};
                $$.code = conversion(gen_int_code);

                string temp_val = string($1.addr) + string($2) + string($3.addr);

                test.insert(temp, @1.first_line, temp_val, scope_count, @1.first_column);

                vector<string> temp_sym_tab{$1.sym_tab_info,$2,$3.sym_tab_info};
                $$.sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, $2, $1.addr, $3.addr, t4);
                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "if", t4, "", t2);
                push_quad(ptr_quad, "Label", "", "", t3);
                push_quad(ptr_quad, "goto", "", "", t3);
              
              }

            | comparison T_in arith_exp 
              {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                $$.true_l = t2;

                string temp_l_2 = to_string(label_no);
                string l_no_2 = "L";
                temp_l_2 = l_no_2 + temp_l_2;
                char *t3 = new char[temp_l_2.size() + 1];
                copy(temp_l_2.begin(),temp_l_2.end(), t3);

                ++label_no;
                
                $$.false_l = t3;

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t4 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t4);

                $$.addr = t4;

                ++temp_no;

                vector<string> gen_int_code{$1.code,$3.code,t4,"=",$1.addr,$2,$3.addr,"\n","if",t4,"goto",$$.true_l,"\n","goto",$$.false_l,"\n"};
                $$.code = conversion(gen_int_code);

                string temp_val = string($1.addr) + string($2) + string($3.addr);

                test.insert(temp, @1.first_line, temp_val, scope_count, @1.first_column);

                vector<string> temp_sym_tab{$1.sym_tab_info,$2,$3.sym_tab_info};
                $$.sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, $2, $1.addr, $3.addr, t4);
                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "if", t4, "", t2);
                push_quad(ptr_quad, "Label", "", "", t3);
                push_quad(ptr_quad, "goto", "", "", t3);
              
              }

            | arith_exp 
              {
                $$.code = $1.code;
                $$.addr = $1.addr;
                $$.true_l = $1.true_l;
                $$.false_l = $1.false_l;
                $$.sym_tab_info = $1.sym_tab_info;

              }
            ;

arith_exp   : arith_exp T_plus arith_exp2 
              {
                //vector<string> temp1{$1,$2,$3}; 
                //$$ = conversion(temp1);

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t2 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t2);

                $$.addr = t2;

                ++temp_no;

                vector<string> gen_int_code{$1.code,$3.code,temp,"=",$1.addr,"+",$3.addr,"\n"};
                $$.code = conversion(gen_int_code);

                string temp_val = string($1.addr) + string("+") + string($3.addr);

                test.insert(temp, @1.first_line, temp_val, scope_count, @1.first_column);

                $$.true_l = $1.true_l;
                $$.false_l = $1.false_l;

                vector<string> temp_sym_tab{$1.sym_tab_info,"+",$3.sym_tab_info};
                $$.sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, "+", $1.addr, $3.addr, t2);

                #if DEBUG
                printf("\ninside arith exp (plus):\n%s \n\n",$$.code);
                #endif

              }
            | arith_exp T_minus arith_exp2 
              {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t2 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t2);

                $$.addr = t2;

                ++temp_no;

                vector<string> gen_int_code{$1.code,$3.code,temp,"=",$1.addr,"-",$3.addr,"\n"};
                $$.code = conversion(gen_int_code);

                string temp_val = string($1.addr) + string("-") + string($3.addr);

                test.insert(temp, @1.first_line, temp_val, scope_count, @1.first_column);

                $$.true_l = $1.true_l;
                $$.false_l = $1.false_l;

                vector<string> temp_sym_tab{$1.sym_tab_info,"-",$3.sym_tab_info};
                $$.sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, "-", $1.addr, $3.addr, t2);


              }
            | arith_exp2 
              {
                $$.code = $1.code;
                $$.addr = $1.addr;
                $$.true_l = $1.true_l;
                $$.false_l = $1.false_l;
                $$.sym_tab_info = $1.sym_tab_info;
              }
            ;

arith_exp2  : arith_exp2 T_star factor 
              {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t2 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t2);

                $$.addr = t2;

                ++temp_no;

                vector<string> gen_int_code{$1.code,$3.code,temp,"=",$1.addr,"*",$3.addr,"\n"};
                $$.code = conversion(gen_int_code);

                string temp_val = string($1.addr) + string("*") + string($3.addr);

                test.insert(temp, @1.first_line, temp_val, scope_count, @1.first_column);

                $$.true_l = $1.true_l;
                $$.false_l = $1.false_l;

                vector<string> temp_sym_tab{$1.sym_tab_info,"*",$3.sym_tab_info};
                $$.sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, "*", $1.addr, $3.addr, t2);

              }

            | arith_exp2 T_divide factor 
              {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t2 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t2);

                $$.addr = t2;

                ++temp_no;

                vector<string> gen_int_code{$1.code,$3.code,temp,"=",$1.addr,"/",$3.addr,"\n"};
                $$.code = conversion(gen_int_code);

                string temp_val = string($1.addr) + string("/") + string($3.addr);

                test.insert(temp, @1.first_line, temp_val, scope_count, @1.first_column);

                $$.true_l = $1.true_l;
                $$.false_l = $1.false_l;

                vector<string> temp_sym_tab{$1.sym_tab_info,"/",$3.sym_tab_info};
                $$.sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, "/", $1.addr, $3.addr, t2);

              }

            | arith_exp2 T_modulus factor 
              {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t2 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t2);

                $$.addr = t2;

                ++temp_no;

                vector<string> gen_int_code{$1.code,$3.code,temp,"=",$1.addr,"%",$3.addr,"\n"};
                $$.code = conversion(gen_int_code);

                string temp_val = string($1.addr) + string("%") + string($3.addr);

                test.insert(temp, @1.first_line, temp_val, scope_count, @1.first_column);

                $$.true_l = $1.true_l;
                $$.false_l = $1.false_l;

                vector<string> temp_sym_tab{$1.sym_tab_info,"%",$3.sym_tab_info};
                $$.sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, "%", $1.addr, $3.addr, t2);

              }

            | factor 
              {
                $$.code = $1.code;
                $$.addr = $1.addr;
                $$.true_l = $1.true_l;
                $$.false_l = $1.false_l;
                $$.sym_tab_info = $1.sym_tab_info;
              }
            ;

factor  : T_plus factor
          { 
            // vector<string> temp1{$1,$2}; 
            // $$ = conversion(temp1);

            string temp = to_string(temp_no);
            string t_no = "t";
            temp = t_no + temp;
            char *t2 = new char[temp.size() + 1];
            copy(temp.begin(),temp.end(), t2);

            $$.addr = t2;

            ++temp_no;

            vector<string> gen_int_code{$2.code,temp,"=",$1,$2.addr,"\n"};
            $$.code = conversion(gen_int_code);

            string temp_val = string($1) + string($2.addr);

            test.insert(temp, @1.first_line, temp_val, scope_count, @1.first_column);

            $$.true_l = $2.true_l;
            $$.false_l = $2.false_l;

            vector<string> temp_sym_tab{$1,$2.sym_tab_info};
            $$.sym_tab_info = conversion(temp_sym_tab);

            push_quad(ptr_quad, $1, $2.addr, "", t2);

          }

        | T_minus factor
          {
            // vector<string> temp1{$1,$2}; 
            // $$ = conversion(temp1);

            string temp = to_string(temp_no);
            string t_no = "t";
            temp = t_no + temp;
            char *t2 = new char[temp.size() + 1];
            copy(temp.begin(),temp.end(), t2);

            $$.addr = t2;

            ++temp_no;

            vector<string> gen_int_code{$2.code,temp,"=",$1,$2.addr,"\n"};
            $$.code = conversion(gen_int_code);

            string temp_val = string($1) + string($2.addr);

            test.insert(temp, @1.first_line, temp_val, scope_count, @1.first_column);

            $$.true_l = $2.true_l;
            $$.false_l = $2.false_l;

            vector<string> temp_sym_tab{$1,$2.sym_tab_info};
            $$.sym_tab_info = conversion(temp_sym_tab);

            push_quad(ptr_quad, $1, $2.addr, "", t2);
            
          }
        | term 
          {
            $$.code = $1.code;
            $$.addr = $1.addr;
            $$.true_l = $1.true_l;
            $$.false_l = $1.false_l;
            $$.sym_tab_info = $1.sym_tab_info;
          }
        ;

term    : T_identifier
          {
              if(!test.declaration_exists($1, scope_count))
              {
                  flag = 0;
                  printf("\n\nvariable \'%s\' not declared before\n\n\n",$1);
                  yyerror("Undeclared variable");
              }
              $$.addr = $1;
              $$.code = "";
              $$.true_l = "";
              $$.false_l = "";
              $$.sym_tab_info = $1;

          }
        | constant 
          {
            $$.code = $1.code;
            $$.addr = $1.addr;
            $$.true_l = $1.true_l;
            $$.false_l = $1.false_l;
            $$.sym_tab_info = $1.sym_tab_info;

          }

        | list_index 
          {
            $$.code = $1;
            $$.addr = "";
            $$.true_l = "";
            $$.false_l = "";
            $$.sym_tab_info = $1;

          }

        | T_left_par or_test T_right_par 
          {
            // vector<string> temp1{$1,$2,$3}; 
            // $$ = conversion(temp1);

            $$.code = $2.code;
            $$.addr = $2.addr;
            $$.true_l = $2.true_l;
            $$.false_l = $2.false_l;

            vector<string> temp_sym_tab{$1,$2.sym_tab_info,$3};
            $$.sym_tab_info = conversion(temp_sym_tab);

          }
        ;

constant    : T_number 
              {
                $$.addr = $1;
                $$.code = "";
                $$.true_l = "";
                $$.false_l = "";
                $$.sym_tab_info = $1;

              }

            | T_string 
              {
                $$.addr = $1;
                $$.code = "";
                $$.true_l = "";
                $$.false_l = "";
                $$.sym_tab_info = $1;

              }

            | T_True
              {
                $$.addr = $1;

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                $$.true_l = t2;

                $$.false_l = "";

                vector<string> gen_int_code{"goto",$$.true_l,"\n"};
                $$.code = conversion(gen_int_code);

                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "goto", "", "", t2);

                $$.sym_tab_info = $1;

              }  

            | T_False
              {
                $$.addr = $1;

                $$.true_l = "";

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                $$.false_l = t2;

                vector<string> gen_int_code{"goto",$$.false_l,"\n"};
                $$.code = conversion(gen_int_code);

                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "goto", "", "", t2);

                $$.sym_tab_info = $1;

              }
            ;

list_index  : T_identifier T_left_sq_b or_test T_right_sq_b
              {
                if(!test.declaration_exists($1, scope_count))
                {
                    flag = 0;
                    printf("\n\nvariable \' %s \' not declared before\n\n\n",$1);
                    yyerror("Undeclared variable");

                }

                vector<string> temp1{$1,$2,$3.code,$4}; 
                $$ = conversion(temp1);
                  
              }
            ;


compound_statement  : if_statement
                      {
                        $$.code = $1.code;
                        $$.addr = $1.addr;
                        $$.true_l = $1.true_l;
                        $$.false_l = $1.false_l;
                        $$.sym_tab_info = $1.sym_tab_info;

                        #if DEBUG
                        printf("\n\ninside compound statement(if):\n\n");
                        printf("%s\n\n",$$.code);
                        #endif
                      }

                    | for_statement
                      {
                        $$.code = $1.code;
                        $$.addr = $1.addr;
                        $$.true_l = $1.true_l;
                        $$.false_l = $1.false_l;
                        $$.sym_tab_info = $1.sym_tab_info;
                      }
                    ;

if_statement    : T_if test T_colon suite elif_statement optional_else
                  {
                    string temp_l = to_string(label_no);
                    string l_no = "L";
                    temp_l = l_no + temp_l;
                    char *t2 = new char[temp_l.size() + 1];
                    copy(temp_l.begin(),temp_l.end(), t2);

                    ++label_no;
                
                    $$.true_l = t2;

                    int ret_elif = strcmp($5.code,"");
                    int ret_else = strcmp($6.code,"");

                    //there exists both elif and else statements
                    if(ret_elif!=0 && ret_else!=0)
                    {
                      #if DEBUG
                      printf("\n\n\ntest1\n\n\n");
                      #endif
                      vector<string> gen_int_code{$2.code,$2.true_l,":\n",$4.code,"goto ",t2,"\n",$2.false_l,":\n",$5.code,$6.code,t2,":\n"};
                      $$.code = conversion(gen_int_code);

                      push_quad(ptr_quad, "Label", "", "", t2);
                      push_quad(ptr_quad, "goto", "", "", t2);

                    }

                    //there exists only elif but no else statement
                    else if(ret_elif!=0 && ret_else==0)
                    {
                      #if DEBUG
                      printf("\n\n\ntest2\n\n\n");
                      #endif
                      vector<string> gen_int_code{$2.code,$2.true_l,":\n",$4.code,"goto ",t2,"\n",$2.false_l,":\n",$5.code,"goto ",t2,"\n",t2,":\n"};
                      $$.code = conversion(gen_int_code);

                      push_quad(ptr_quad, "Label", "", "", t2);
                      push_quad(ptr_quad, "goto", "", "", t2);

                    }

                    //there exists no elif statement but there is an else statement
                    else if(ret_elif==0 && ret_else!=0)
                    {
                      #if DEBUG
                      printf("\n\n\ntest3\n\n\n");
                      #endif

                      vector<string> gen_int_code{$2.code,$2.true_l,":\n",$4.code,"goto ",t2,"\n",$2.false_l,":\n",$6.code,t2,":\n"};
                      $$.code = conversion(gen_int_code);

                      push_quad(ptr_quad, "Label", "", "", t2);
                      push_quad(ptr_quad, "goto", "", "", t2);

                      #if DEBUG
                      printf("\n\ninside if:\n\n");
                      printf("%s\n",$$.code);
                      #endif

                    }

                    //both elif and else statements don't exist
                    else if(ret_elif==0 && ret_else==0)
                    {
                      #if DEBUG
                      printf("\n\n\ntest4\n\n\n");
                      #endif

                      vector<string> gen_int_code{$2.code,$2.true_l,":\n",$4.code,$2.false_l,":\n"};
                      $$.code = conversion(gen_int_code);

                      #if DEBUG
                      printf("\n\ninside if:\n\n");
                      printf("%s\n",$$.code);
                      #endif

                    }

                    $$.addr = $2.addr;
                    $$.false_l = $2.false_l;

                    $$.sym_tab_info = $2.sym_tab_info;


                    
                  }
                ;

test    : or_test
          {
            // vector<string> temp1{$1,$2}; 
            // $$ = conversion(temp1);

            $$.code = $1.code;
            $$.addr = $1.addr;
            $$.true_l = $1.true_l;
            $$.false_l = $1.false_l;
            $$.sym_tab_info = $1.sym_tab_info;


          }
        ;



suite   : simple_statement
          {
            $$.code = $1.code;
            $$.addr = $1.addr;
            $$.true_l = $1.true_l;
            $$.false_l = $1.false_l;
            $$.sym_tab_info = $1.sym_tab_info;
          }

        | T_Newline T_Indent  
          {
            scope_count += 1;
            test.create_map(scope_count);
          }
          suite1
          {
            $$.code = $4.code;
            $$.addr = $4.addr;
            $$.true_l = $4.true_l;
            $$.false_l = $4.false_l;
            $$.sym_tab_info = $4.sym_tab_info;
          }
        ;

suite_for   : simple_statement
              {
                $$.code = $1.code;
                $$.addr = $1.addr;
                $$.true_l = $1.true_l;
                $$.false_l = $1.false_l;
                $$.sym_tab_info = $1.sym_tab_info;
              }

            | T_Newline T_Indent suite1
              {
                $$.code = $3.code;
                $$.addr = $3.addr;
                $$.true_l = $3.true_l;
                $$.false_l = $3.false_l;
                $$.sym_tab_info = $3.sym_tab_info;
              }
            ;

suite1  : statement T_Dedent
          {
              scope_count -= $2;

              $$.code = $1.code;
              $$.addr = $1.addr;
              $$.true_l = $1.true_l;
              $$.false_l = $1.false_l;
              $$.sym_tab_info = $1.sym_tab_info;

          }

        | statement repeat_statement T_Dedent
          {
              scope_count -= $3;

              vector<string> gen_int_code{$1.code,$2.code,"\n"};
              $$.code = conversion(gen_int_code);

              $$.addr = $1.addr;
              $$.true_l = $1.true_l;
              $$.false_l = $1.false_l;

              vector<string> temp_sym_tab{$1.sym_tab_info,$2.sym_tab_info};
              $$.sym_tab_info = conversion(temp_sym_tab);

              

          }
        ;

repeat_statement    : statement repeat_statement
                      {
                        vector<string> gen_int_code{$1.code,$2.code,"\n"};
                        $$.code = conversion(gen_int_code);

                        $$.addr = $1.addr;
                        $$.true_l = $1.true_l;
                        $$.false_l = $1.false_l;

                        vector<string> temp_sym_tab{$1.sym_tab_info,$2.sym_tab_info};
                        $$.sym_tab_info = conversion(temp_sym_tab);

                      }

                    | statement
                      {
                        $$.code = $1.code;
                        $$.addr = $1.addr;
                        $$.true_l = $1.true_l;
                        $$.false_l = $1.false_l;
                        $$.sym_tab_info = $1.sym_tab_info;
                      }

                    | T_Newline repeat_statement
                      {
                        $$.code = $2.code;
                        $$.addr = $2.addr;
                        $$.true_l = $2.true_l;
                        $$.false_l = $2.false_l;
                        $$.sym_tab_info = $2.sym_tab_info;
                      }

                    | T_Newline
                      {
                        $$.code = "";
                        $$.addr = "";
                        $$.true_l = "";
                        $$.false_l = "";
                        $$.sym_tab_info = "";

                      }
                    ;

elif_statement  : {
                    $$.code = "";
                    $$.addr = "";
                    $$.true_l = "";
                    $$.false_l = "";
                    $$.sym_tab_info = "";

                  }

                | T_elif test T_colon suite elif_statement
                  {

                    string temp_l = to_string(label_no);
                    string l_no = "L";
                    temp_l = l_no + temp_l;
                    char *t2 = new char[temp_l.size() + 1];
                    copy(temp_l.begin(),temp_l.end(), t2);

                    $$.sym_tab_info = $2.sym_tab_info;


                    //no more elif statements
                    if(strcmp($5.code,"")==0)
                    {
                      vector<string> gen_int_code{$2.code,$2.true_l,":\n",$4.code,"goto ",t2,"\n",$2.false_l,":\n"};
                      $$.code = conversion(gen_int_code);
                      $$.addr = "";
                      $$.true_l = "";
                      $$.false_l = "";

                    }

                    //contains more elif statements
                    else
                    {
                      vector<string> gen_int_code{$2.code,$2.true_l,":\n",$4.code,"goto ",t2,"\n",$2.false_l,":\n",$5.code};
                      $$.code = conversion(gen_int_code);
                      $$.addr = "";
                      $$.true_l = "";
                      $$.false_l = "";

                    }

                  }
                ;

optional_else :   {
                    $$.code = "";
                    $$.addr = "";
                    $$.true_l = "";
                    $$.false_l = "";
                    $$.sym_tab_info = "";

                  }

                | T_else T_colon suite
                  {
                    $$.code = $3.code;
                    $$.addr = $3.addr;
                    $$.true_l = $3.true_l;
                    $$.false_l = $3.false_l;
                    $$.sym_tab_info = $3.sym_tab_info;

                  }
                ;

for_statement   : T_for  
                  {
                    scope_count += 1;
                    test.create_map(scope_count);
                  }
                  exprlist T_in testlist T_colon suite_for
                  {
                    string temp_l = to_string(label_no);
                    string l_no = "L";
                    temp_l = l_no + temp_l;
                    char *t2 = new char[temp_l.size() + 1];
                    copy(temp_l.begin(),temp_l.end(), t2);

                    ++label_no;

                    string temp_l_2 = to_string(label_no);
                    string l_no_2 = "L";
                    temp_l_2 = l_no_2 + temp_l_2;
                    char *t3 = new char[temp_l_2.size() + 1];
                    copy(temp_l_2.begin(),temp_l_2.end(), t3);

                    ++label_no;

                    string temp = to_string(temp_no);
                    string t_no = "t";
                    temp = t_no + temp;
                    char *t4 = new char[temp.size() + 1];
                    copy(temp.begin(),temp.end(), t4);

                    ++temp_no;

                    string temp_2 = to_string(temp_no);
                    string t_no_2 = "t";
                    temp_2 = t_no_2 + temp_2;
                    char *t5 = new char[temp_2.size() + 1];
                    copy(temp_2.begin(),temp_2.end(), t5);

                    ++temp_no;

                    vector<string> gen_int_code{$3,"=",$5.start_r,"\n",t2,":\n",$7.code,temp," = ",$3," + ",$5.step_r,"\n",$3,"=",temp,"\n",temp_2,"=",$3," < ",$5.end_r,"\nif ",temp_2," goto ",t2,"\ngoto ",t3,"\n",t3,":\n"};
                    $$.code = conversion(gen_int_code);

                    string temp_val_1 = string($3) + string("+") + string($5.step_r);
                    test.insert(temp, @1.first_line, temp_val_1, scope_count + 1, @1.first_column);

                    string temp_val_2 = string($3) + string("<") + string($5.end_r);
                    test.insert(temp_2, @1.first_line, temp_val_2, scope_count + 1, @1.first_column);

                    push_quad(ptr_quad, "=",$5.start_r, "", $3);

                    push_quad(ptr_quad, "+", $3, $5.step_r, t4);
                    push_quad(ptr_quad, "=",t4, "", $3);

                    push_quad(ptr_quad, "<", $3, $5.end_r, t5);
                                        
                    push_quad(ptr_quad, "Label", "", "", t2);
                    push_quad(ptr_quad, "if", t4, "", t2);
                    push_quad(ptr_quad, "Label", "", "", t3);
                    push_quad(ptr_quad, "goto", "", "", t3);

                    $$.addr = "";
                    $$.true_l = "";
                    $$.false_l = "";

                    #if DEBUG
                    printf("\nprinting start of range(inside for block action rule: %s\n\n",$5.start_r);
                    #endif

                    

                    test.insert($3, @3.first_line, $5.start_r , scope_count + 1, @3.first_column);
                    

                    #if DEBUG
                    printf("scope count%d\n",scope_count);
                    int temp2 = test.update_identifier($3, scope_count, $5.start_r);
                    int temp3 = test.declaration_exists($3, scope_count);
                    printf("\nprinting dec exists: %d\n\n",temp3);
                    printf("\nprinting identifier: %s\n",$3);
                    printf("\nprinting return value of updating symbol table %d\n\n",temp2);
                    #endif

                    $$.sym_tab_info = "";
                    

                  }
                ;

exprlist    : first_exprlist last_exprlist 
              {
                $$ = $1;
              }
            ;

first_exprlist  : T_identifier
                  {
                    $$ = $1;
                  }
                ;

last_exprlist   : {$$ = empty_string;}
                | T_comma
                | T_comma first_exprlist last_exprlist
                  {
                    $$ = $2;
                  }
                ;

testlist    : range_fn
              {
                $$.start_r = $1.start_r;
                $$.end_r = $1.end_r;
                $$.step_r = $1.step_r;

              }
            ;



range_fn : T_range T_left_par range_term T_right_par
           {
            //  vector<string> temp1{$1,$2,$3,$4}; 
            //  $$ = conversion(temp1);

            $$.start_r = "0";
            $$.end_r = $3;
            $$.step_r = "1";

           }

         | T_range T_left_par range_term T_comma range_term T_right_par
           {
            //  vector<string> temp1{$1,$2,$3,$4,$5,$6}; 
            //  $$ = conversion(temp1);

            $$.start_r = $3;
            $$.end_r = $5;
            $$.step_r = "1";

           }

         | T_range T_left_par range_term T_comma range_term T_comma range_term T_right_par
           {
            //  vector<string> temp1{$1,$2,$3,$4,$5,$6,$7,$8}; 
            //  $$ = conversion(temp1);

            $$.start_r = $3;
            $$.end_r = $5;
            $$.step_r = $7;

           }
         ;

range_term  : T_identifier
              {
                  if(!test.declaration_exists($1, scope_count))
                  {
                      flag = 0;
                      printf("\n\nvariable \'%s\' not declared before\n",$1);
                      yyerror("Undeclared Variable");
                      
                  }

                  $$ = $1;
              }

            | T_number
              {
                $$ = $1;
              }

            | list_index
              {
                $$ = $1;
              }
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

    ptr_quad = (quadruple_t*)malloc(sizeof(quadruple_t));
    init_quad(ptr_quad);




    if (!yyparse() && flag) 
    {
        printf("\n\n\nParsing is successful\n\n\n");
    } 
    else 
    {
        printf("\n\nParsing is unsuccessful\n\n");
    }
            
    cout<<"SYMBOL TABLE: \n";
    cout << test;

    cout<<"\n\n\n\nGenerated Intermediate Code: \n\n" << final_int_code << "\n\n\n";
    FILE *fp = fopen("generated_intermediate_code.txt","w");

    if(fp!=NULL)
    {
      fputs(final_int_code.c_str(),fp);
    }
    else
    {
      printf("\nError: Unable to open file\n");
    }

    disp_quad(ptr_quad,1);
    disp_quad(ptr_quad,0);
        
    return 0;

}