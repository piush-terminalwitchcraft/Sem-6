%{

%}

%%
auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|inline|int|long|register|restrict|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while|main {
    printf("%s is a keyword\n",yytext);
}

[a-zA-Z][a-zA-Z0-9]* {
        printf("%s is an identifier\n", yytext);
    }

[0-9]+ {
        printf("%s is constants\n", yytext);
    }

[=*/%+-] {
        printf("%s is operator\n", yytext);
    }

[{}()"%] {
        printf("%s is delimitor\n", yytext);
    }

[;,] {
        printf("%s is seperator\n", yytext);
    }

#.* {
        printf("%s is preprocessor declarative\n", yytext);
    } 

%%

int main(){
    FILE *file; 
    file = fopen("code.c","r");
    if(!file){
        printf("Couldnt read the file\n");
        exit(0);
    }
    yyin = file;
    yylex();
    return 0;
}
