%{

%}

%%

([a-zA-z]*) {
    printf("%s is a text", yytext);
}
([0-9]*) {

    printf("%s is a number", yytext);
}
([a-zA-Z0-9]*) {

    printf("%s is a alpha-numeric text", yytext);
    }

%%
int yywrap(){return 0;}
int main(){
   printf("Enter expression \n");
   yylex();
   return 0;
}
