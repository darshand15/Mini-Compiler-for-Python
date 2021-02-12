%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
%}

%union {
    int indentation_level;
    char *text;
    char *identifier;
    char *keyword;
};

%start input_file
%token T_Same_indent T_Indent T_Dedent T_import T_from T_True T_False T_not T_and T_or T_None T_if T_else T_elif T_for T_in T_as T_range T_list T_plus T_minus T_star T_divide T_modulus T_LT T_GT T_LTE T_GTE T_EQ T_NEQ T_semicolon T_dot T_colon T_comma T_assignment T_left_sq_b T_right_sq_b T_left_par T_right_par T_number T_identifier T_string T_string T_Newline T_eof
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

input_file  : %empty
            | T_Newline input_file 
            | statement input_file
            | T_eof
            ;

statement   : simple_statement
            | compound_statement
            ;

simple_statement   : small_statement next_simple_statement
                   ;

next_simple_statement   : end_simple_statement
                        | T_semicolon small_statement next_simple_statement
                        ;

end_simple_statement   : T_Newline
                       | T_semicolon T_Newline
                       | %empty
                       ;

small_statement   : expr_statement
                  | import_statement
                  ;

import_statement   : T_import T_identifier
                   ;

expr_statement   : assignment_statement
                 | or_test
                 ;

assignment_statement    : T_identifier T_assignment assignment_expr
                        ;

assignment_expr : or_test
                | T_list T_left_par T_right_par
                | T_left_sq_b T_right_sq_b
                ;

or_test   : T_left_par or_test T_right_par
          | or_test T_or and_test
          | and_test
          ;

and_test   : and_test T_and not_test
           | not_test
           ;

not_test   : not_test T_not comparison
           | comparison
           ;

comparison  : comparison T_LT arith_exp
            | comparison T_GT arith_exp
            | comparison T_EQ arith_exp
            | comparison T_GTE arith_exp
            | comparison T_LTE arith_exp
            | comparison T_NEQ arith_exp
            | comparison T_in arith_exp
            | arith_exp
            ;

arith_exp   : arith_exp T_plus arith_exp2
            | arith_exp T_minus arith_exp2
            | arith_exp2
            ;

arith_exp2  : arith_exp2 T_star factor
            | arith_exp2 T_divide factor
            | arith_exp2 T_modulus factor
            | factor
            ;

factor  : T_plus factor
        | T_minus factor
        | term
        ;

term    : T_identifier
        | constant
        | list_index
        ;

constant    : T_number
            | T_string
            | T_True
            | T_False
            ;

list_index  : T_identifier T_left_sq_b or_test T_right_sq_b
            ;


compound_statement  : if_statement
                    | for_statement
                    ;

if_statement    : T_if test T_colon suite elif_statement optional_else
                ;

test    : or_test optional_if_else
        ;

optional_if_else    : %empty
                    | T_if or_test T_else test
                    ;

suite   : simple_statement
        | T_Newline T_Indent statement repeat_statement T_Dedent
        ;

repeat_statement    : %empty
                    | statement repeat_statement
                    ;

elif_statement  : %empty
                | T_elif test T_colon suite elif_statement
                ;

optional_else   : %empty
                | T_else T_colon suite
                ;

for_statement   : T_for exprlist T_in testlist T_colon suite optional_else
                ;

exprlist    : first_exprlist last_exprlist optional_comma
            ;

first_exprlist  : T_identifier
                ;

last_exprlist   : %empty
                | T_comma first_exprlist last_exprlist
                ;

optional_comma  : %empty
                | T_comma
                ;

testlist    : test repeat_test optional_comma
            | range_fn
            ;

repeat_test : %empty
            | T_comma test repeat_test
            ;

range_fn : T_range T_left_par range_term T_right_par
         | T_range T_left_par range_term T_comma range_term T_right_par
         | T_range T_left_par range_term T_comma range_term T_comma range_term T_right_par
         ;

range_term  : T_identifier
            | T_number
            | list_index
            ;






%%