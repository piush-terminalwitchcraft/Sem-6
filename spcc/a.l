%{
%}
%%
\n {printf("Hello world!");}
%%
int yywrap(){}
int main(){
        yylex();
        return 0;
}
