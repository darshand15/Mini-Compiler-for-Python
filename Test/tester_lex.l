%{
#include "tester.h"
#include<string.h>


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

int current_depth = 0;
%}
%option nounput yylineno

%%


^[\t]*           {
                    current_depth = find_level_indentation_tab(yytext);
                    printf("%d\n",current_depth);
                    return tab;


                }

^[ ]*            {
                    current_depth = find_level_indentation_space(yytext);
                    printf("%d\n",current_depth);
                    return space;

                }

#.*                         {return comment_1;}
\'\'\'([^\']|[\r\n])*?\'\'\'     {return comment_m1;}
\"\"\"([^\"]|[\r\n])*?\"\"\"     {return comment_m2;}

.           ;

%%

int yywrap(void)
{
    return 1;
}