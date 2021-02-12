#include<stdio.h>
#include "tester.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

int main()
{
    int ntoken, vtoken;
    ntoken = yylex();
    while(ntoken)
    {
        if(ntoken==comment_1)
        {
            printf("single line comment %d %s\n",yylineno,yytext);
        }
        else if(ntoken==comment_m1)
        {
            printf("multiline comment single quotes %d %s\n",yylineno,yytext);
        }
        else if(ntoken==comment_m2)
        {
            printf("multiline comment double quotes %d %s\n",yylineno,yytext);
        }
        else if(ntoken==tab)
        {
            printf("tab at beginning %d %s\n",yylineno,yytext);
        }
        else if(ntoken==space)
        {
            printf("space at beginning %d %s\n",yylineno,yytext);
        }
        else if(ntoken==error)
        {
            printf("Error: Unterminated comment\n");
            break;
        }
        ntoken = yylex();

    }
    return 0;
}