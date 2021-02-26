%option yylineno

%{

    extern "C"
    {
        int yylex(void);
    }

#include<stdio.h>
#include "y.tab.h"
#include<string.h>
#include "test1.hpp"


#define YY_USER_ACTION \
    yylloc.first_line = yylloc.last_line; \
    yylloc.first_column = yylloc.last_column; \
    for(int i = 0; yytext[i] != '\0'; i++) { \
        if(yytext[i] == '\n') { \
            yylloc.last_line++; \
            yylloc.last_column = 0; \
        } \
        else { \
            yylloc.last_column++; \
        } \
    }


//function to initialize the my_stack
void init(my_stack_t *ptr_my_stack)
{
    ptr_my_stack->head = NULL;
    ptr_my_stack->top = NULL;
}

//function to retrieve the level of indentation at the top of the my_stack
int top(my_stack_t *ptr_my_stack)
{
    return ptr_my_stack->top->level_of_indentation;
}

//function to push an element into the my_stack
void push(my_stack_t *ptr_my_stack, int ind_lev)
{
    node_t *temp = (node_t*)malloc(sizeof(node_t));
    temp->level_of_indentation = ind_lev;
    temp->next = NULL;
    temp->prev = NULL;

    //my_stack is empty
    if(ptr_my_stack->head==NULL)
    {
        ptr_my_stack->head = temp;
        ptr_my_stack->top = temp;
    }

    //my_stack is not empty
    else
    {
        ptr_my_stack->top->next = temp;
        temp->prev = ptr_my_stack->top;
        ptr_my_stack->top = temp;
    }

}

//function to pop an element from the my_stack
void pop(my_stack_t *ptr_my_stack)
{
    //my_stack is not empty
    if(ptr_my_stack->head!=NULL)
    {
        //my_stack has only one node
        if(ptr_my_stack->head == ptr_my_stack->top)
        {
            free(ptr_my_stack->head);
            ptr_my_stack->head = NULL;
            ptr_my_stack->top = NULL;
        }

        //my_stack has more than one node
        else
        {
            ptr_my_stack->top->prev->next = NULL;
            node_t *temp = ptr_my_stack->top;
            ptr_my_stack->top = temp->prev;
            free(temp);
            
        }
    }
}

int find_level_indentation_tab(char *text)
{
    int n = strlen(text);
    int count = 0;
    for(int i = 0;i<n;++i)
    {
        if(text[i]=='\t')
        {
            ++count;
        }
        else
        {
            return count;
        }
    }

    return count;
}

int find_level_indentation_space(char *text)
{
    int n = strlen(text);
    int count = 0;
    for(int i = 0;i<n;++i)
    {
        if(text[i]==' ')
        {
            ++count;
        }
        else
        {
            return count;
        }
    }

    return count;
}


int current_depth = 0;
my_stack_t *ptr_my_stack;

%}

%x REALLYEND

%%

^[ \t]*\n$       {;}

^[\t]*          {
                    current_depth = find_level_indentation_tab(yytext);
                    int prev_ind = top(ptr_my_stack);

                    //current indentation is the same as the previous line's indentation
                    /*if(current_depth == prev_ind)
                    {
                        yylval.indentation_level = current_depth;
                        return T_Same_indent;
                    }*/

                    //current indentation is larger than the previous line's indentation
                    if(current_depth > prev_ind)
                    {
                        push(ptr_my_stack,current_depth);
                        yylval.indentation_level = current_depth;
                        return T_Indent;

                    }

                    //current indentation is smaller than the previous line's indentation
                    else if(current_depth <  prev_ind)
                    {
                        int temp_scopes = 0;
                        while(current_depth < top(ptr_my_stack))
                        {
                            pop(ptr_my_stack);
                            temp_scopes += 1;
                        }
                        yylval.indentation_level = temp_scopes;
                        return T_Dedent;

                    }


                }

^[ ]*           {
                    current_depth = find_level_indentation_space(yytext);
                    int prev_ind = top(ptr_my_stack);

                    //current indentation is the same as the previous line's indentation
                    /*if(current_depth == prev_ind)
                    {
                        yylval.indentation_level = current_depth;
                        return T_Same_indent;
                    }*/

                    //current indentation is larger than the previous line's indentation
                    if(current_depth > prev_ind)
                    {
                        push(ptr_my_stack,current_depth);
                        yylval.indentation_level = current_depth;
                        return T_Indent;

                    }

                    //current indentation is smaller than the previous line's indentation
                    else if(current_depth <  prev_ind)
                    {
                        int temp_scopes = 0;
                        while(current_depth < top(ptr_my_stack))
                        {
                            pop(ptr_my_stack);
                            temp_scopes += 1;
                        }
                        yylval.indentation_level = temp_scopes;
                        return T_Dedent;

                    }

                }

#.*                         ;
\'\'\'([^\']|[\r\n])*?\'\'\'     ;
\"\"\"([^\"]|[\r\n])*?\"\"\"     ;

^"import"   {
                int prev_ind = top(ptr_my_stack);

                if(prev_ind!=0)
                {
                    int temp_scopes = 0;
                    while(top(ptr_my_stack)!=0)
                    {
                        pop(ptr_my_stack);
                        temp_scopes += 1;
                    }
                    yylval.indentation_level = temp_scopes;
                    yyless(0);
                    return T_Dedent;
                                
                }

                yylval.text = strdup(yytext); 
                return T_import;

            }

"import"    {yylval.text = strdup(yytext); return T_import;}

"True"      {yylval.text = strdup(yytext); return T_True;}
"False"     {yylval.text = strdup(yytext); return T_False;}
"not"       {yylval.text = strdup(yytext); return T_not;}
"and"       {yylval.text = strdup(yytext); return T_and;}
"or"        {yylval.text = strdup(yytext); return T_or;}

^"if"       {
                int prev_ind = top(ptr_my_stack);

                if(prev_ind!=0)
                {
                    int temp_scopes = 0;
                    while(top(ptr_my_stack)!=0)
                    {
                        pop(ptr_my_stack);
                        temp_scopes += 1;
                    }
                    yylval.indentation_level = temp_scopes;
                    yyless(0);
                    return T_Dedent;
                                
                }

                yylval.text = strdup(yytext); 
                return T_if;
            }

"if"        {yylval.text = strdup(yytext); return T_if;}

^"else"     {
                int prev_ind = top(ptr_my_stack);

                if(prev_ind!=0)
                {
                    int temp_scopes = 0;
                    while(top(ptr_my_stack)!=0)
                    {
                        pop(ptr_my_stack);
                        temp_scopes += 1;
                    }
                    yylval.indentation_level = temp_scopes;
                    yyless(0);
                    return T_Dedent;
                                
                }

                yylval.text = strdup(yytext); 
                return T_else;
            }

"else"      {yylval.text = strdup(yytext); return T_else;}

^"elif"     {
                int prev_ind = top(ptr_my_stack);

                if(prev_ind!=0)
                {
                    int temp_scopes = 0;
                    while(top(ptr_my_stack)!=0)
                    {
                        pop(ptr_my_stack);
                        temp_scopes += 1;
                    }
                    yylval.indentation_level = temp_scopes;
                    yyless(0);
                    return T_Dedent;
                                
                }
                yylval.text = strdup(yytext); 
                return T_elif;
            }

"elif"      {yylval.text = strdup(yytext); return T_elif;}

^"for"      {
                int prev_ind = top(ptr_my_stack);

                if(prev_ind!=0)
                {
                    int temp_scopes = 0;
                    while(top(ptr_my_stack)!=0)
                    {
                        pop(ptr_my_stack);
                        temp_scopes += 1;
                    }
                    yylval.indentation_level = temp_scopes;
                    yyless(0);
                    return T_Dedent;
                                
                }
                yylval.text = strdup(yytext); 
                return T_for;
            }

"for"       {yylval.text = strdup(yytext); return T_for;}

"in"        {yylval.text = strdup(yytext); return T_in;}

"range"     {yylval.text = strdup(yytext); return T_range;}
"list"      {yylval.text = strdup(yytext); return T_list;}

"+"     {yylval.text = strdup(yytext); return T_plus;}
"-"     {yylval.text = strdup(yytext); return T_minus;}
"*"     {yylval.text = strdup(yytext); return T_star;}
"/"     {yylval.text = strdup(yytext); return T_divide;}
"%"     {yylval.text = strdup(yytext); return T_modulus;}

"<"     {yylval.text = strdup(yytext); return T_LT;}
">"     {yylval.text = strdup(yytext); return T_GT;}
"<="    {yylval.text = strdup(yytext); return T_LTE;}
">="    {yylval.text = strdup(yytext); return T_GTE;}
"=="    {yylval.text = strdup(yytext); return T_EQ;}
"!="    {yylval.text = strdup(yytext); return T_NEQ;}

";"     {yylval.text = strdup(yytext); return T_semicolon;}
":"     {yylval.text = strdup(yytext); return T_colon;}
","     {yylval.text = strdup(yytext); return T_comma;}
"="     {yylval.text = strdup(yytext); return T_assignment;}
"["     {yylval.text = strdup(yytext); return T_left_sq_b;}
"]"     {yylval.text = strdup(yytext); return T_right_sq_b;}
"("     {yylval.text = strdup(yytext); return T_left_par;}
")"     {yylval.text = strdup(yytext); return T_right_par;}

[0-9]+  {yylval.text = strdup(yytext); return T_number;}



^[a-zA-Z_][a-zA-Z_0-9]* {
                            int prev_ind = top(ptr_my_stack);

                            if(prev_ind!=0)
                            {
                                int temp_scopes = 0;
                                while(top(ptr_my_stack)!=0)
                                {
                                    pop(ptr_my_stack);
                                    temp_scopes += 1;
                                }
                                yylval.indentation_level = temp_scopes;
                                yyless(0);
                                return T_Dedent;
                                
                            }

                            yylval.text = strdup(yytext); 
                            return T_identifier;
                        }  

[a-zA-Z_][a-zA-Z_0-9]*  {
                            yylval.text = strdup(yytext); return T_identifier;
                        }                      

\"([^\"\n])*\"  {yylval.text = strdup(yytext); return T_string;}
\'([^\'\n])*\'  {yylval.text = strdup(yytext); return T_string;}

"\n"    {yylval.text = strdup(yytext); return T_Newline;}


<INITIAL><<EOF>>        {  

                            BEGIN(REALLYEND);
                            int prev_ind = top(ptr_my_stack);
                            printf("\n\n\t%d\n\n\n", prev_ind);
                            if(prev_ind!=0)
                            {
                                int temp_scopes = 0;
                                while(top(ptr_my_stack)!=0)
                                {
                                    pop(ptr_my_stack);
                                    temp_scopes += 1;
                                }
                                yylval.indentation_level = temp_scopes;
                                //yyless(0);
                                return T_Dedent;
                                            
                            }
                            return T_Newline; 
                        }
<REALLYEND><<EOF>>      { return 0; }


%%

