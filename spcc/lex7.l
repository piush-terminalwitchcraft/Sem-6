%{
#include <stdio.h>
%}

%%
[^\n]+  { 
        printf("Hello %s!\n", yytext);
    }
%%

int yywrap(){return 0;}
int main()
{
    printf("Enter you username :\n");
        yylex();

    return 0;
}

