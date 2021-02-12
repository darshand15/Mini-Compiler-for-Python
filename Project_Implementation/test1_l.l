%{
#include "y.tab.h"
#include<string.h>

// void yyerror(char *s);
// int yylex();

//node of the stack
struct node
{
    int level_of_indentation; 
    struct node *next;
    struct node *prev;
};
typedef struct node node_t;

//stack used to maintain information about the level of indentation
struct stack
{
    node_t *head;
    node_t *top;
};
typedef struct stack stack_t;

//function to initialize the stack
void init(stack_t *ptr_stack)
{
    ptr_stack->head = NULL;
    ptr_stack->top = NULL;
}

//function to retrieve the level of indentation at the top of the stack
int top(stack_t *ptr_stack)
{
    return ptr_stack->top->level_of_indentation;
}

//function to push an element into the stack
void push(stack_t *ptr_stack, int ind_lev)
{
    node_t *temp = (node_t*)malloc(sizeof(node_t));
    temp->level_of_indentation = ind_lev;
    temp->next = NULL;
    temp->prev = NULL;

    //stack is empty
    if(ptr_stack->head==NULL)
    {
        ptr_stack->head = temp;
        ptr_stack->top = temp;
    }

    //stack is not empty
    else
    {
        ptr_stack->top->next = temp;
        temp->prev = ptr_stack->top;
        ptr_stack->top = temp;
    }

}

//function to pop an element from the stack
void pop(stack_t *ptr_stack)
{
    //stack is not empty
    if(ptr_stack->head!=NULL)
    {
        //stack has only one node
        if(ptr_stack->head == ptr_stack->top)
        {
            free(ptr_stack->head);
            ptr_stack->head = NULL;
            ptr_stack->top = NULL;
        }

        //stack has more than one node
        else
        {
            ptr_stack->top->prev->next = NULL;
            node_t *temp = ptr_stack->top;
            ptr_stack->top = temp->prev;
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
    }

    return count;
}

int yycol_num = 1;
int current_depth = 0;
stack_t *ptr_stack = (stack_t*)malloc(sizeof(stack_t));
init(stack_t);
push(stack_t,0);

%}
%option yylineno

%%

^[\t]+          {
                    current_depth = find_level_indentation_tab(yytext);
                    int prev_ind = top(ptr_stack);

                    //current indentation is the same as the previous line's indentation
                    if(current_depth == prev_ind)
                    {
                        yylval.indentation_level = current_depth;
                        return T_Same_indent;
                    }

                    //current indentation is larger than the previous line's indentation
                    else if(current_depth > prev_ind)
                    {
                        push(ptr_stack,current_depth);
                        yylval.indentation_level = current_depth;
                        return T_Indent;

                    }

                    //current indentation is smaller than the previous line's indentation
                    else if(current_depth <  prev_ind)
                    {
                        while(current_depth < top(ptr_stack))
                        {
                            pop(ptr_stack);
                        }
                        yylval.indentation_level = current_depth;
                        return T_Dedent;

                    }


                }

^[ ]+           {
                    current_depth = find_level_indentation_space(yytext);
                    int prev_ind = top(ptr_stack);

                    //current indentation is the same as the previous line's indentation
                    if(current_depth == prev_ind)
                    {
                        yylval.indentation_level = current_depth;
                        return T_Same_indent;
                    }

                    //current indentation is larger than the previous line's indentation
                    else if(current_depth > prev_ind)
                    {
                        push(ptr_stack,current_depth);
                        yylval.indentation_level = current_depth;
                        return T_Indent;

                    }

                    //current indentation is smaller than the previous line's indentation
                    else if(current_depth <  prev_ind)
                    {
                        while(current_depth < top(ptr_stack))
                        {
                            pop(ptr_stack);
                        }
                        yylval.indentation_level = current_depth;
                        return T_Dedent;

                    }

                }

#.*                         ;
\'\'\'([^\']|[\r\n])*?\'\'\'     ;
\"\"\"([^\"]|[\r\n])*?\"\"\"     ;

"import"    {yylval.keyword = "import"; return T_import;}
"from"      {yylval.keyword = "from"; return T_from;}
"True"      {yylval.keyword = "True"; return T_True;}
"False"     {yylval.keyword = "False"; return T_False;}
"not"       {yylval.keyword = "not"; return T_not;}
"and"       {yylval.keyword = "and"; return T_and;}
"or"        {yylval.keyword = "or"; return T_or;}
"None"      {yylval.keyword = "None"; return T_None;}
"if"        {yylval.keyword = "if"; return T_if;}
"else"      {yylval.keyword = "else"; return T_else;}
"elif"      {yylval.keyword = "elif"; return T_elif;}
"for"       {yylval.keyword = "for"; return T_for;}
"in"        {yylval.keyword = "in"; return T_in;}
"as"        {yylval.keyword = "as"; return T_as;}

"range"     {yylval.text = "range"; return T_range;}
"list"      {yylval.text = "list"; return T_list;}

"+"     {yylval.text = "+"; return T_plus;}
"-"     {yylval.text = "-"; return T_minus;}
"*"     {yylval.text = "*"; return T_star;}
"/"     {yylval.text = "/"; return T_divide;}
"%"     {yylval.text = "%"; return T_modulus;}

"<"     {yylval.text = "<"; return T_LT;}
">"     {yylval.text = ">"; return T_GT;}
"<="    {yylval.text = "<="; return T_LTE;}
">="    {yylval.text = ">="; return T_GTE;}
"=="    {yylval.text = "=="; return T_EQ;}
"!="    {yylval.text = "!="; return T_NEQ;}

";"     {yylval.text = ";"; return T_semicolon;}
"."     {yylval.text = "."; return T_dot;}
":"     {yylval.text = ":"; return T_colon;}
","     {yylval.text = ","; return T_comma;}
"="     {yylval.text = "="; return T_assignment;}
"["     {yylval.text = "["; return T_left_sq_b;}
"]"     {yylval.text = "]"; return T_right_sq_b;}
"("     {yylval.text = "("; return T_left_par;}
")"     {yylval.text = ")"; return T_right_par;}

[0-9]+  {yylval.text = strdup(yytext); return T_number;}

[a-zA-Z_][a-zA-Z_0-9]*  {yylval.text = strdup(yytext); return T_identifier;}

\"([^\"\n])*\"  {yylval.text = strdup(yytext); return T_string;}
\'([^\'\n])*\'  {yylval.text = strdup(yytext); return T_string;}

"\n"    {yylval.text = "\n"; return T_Newline;}

<<EOF>>     {yylval = "eof"; return T_eof;}






%%

