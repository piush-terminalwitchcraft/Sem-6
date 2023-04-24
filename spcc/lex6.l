%{
#include <stdio.h>
%}

%%

[0-9]+       { printf("Input is a number.\n"); }
[a-zA-Z]+    { printf("Input is a word.\n"); }
[a-zA-Z0-9]+ { printf("Input is a combination of word and number.\n"); }
.            { printf("Invalid input.\n"); }

%%

int main()
{
    yylex();
    return 0;
}

