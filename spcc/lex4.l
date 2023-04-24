%{
%}
%%
^[0-9]+$ {
    printf("Input is a number \n");
    }
^[A-Za-z]+$ {
    printf("Input is a character of a word\n");
    }
%%

int yywrap(){return 0;}
int main(){
        yylex();
}
