%{
    void display(int, char*);
    int flag;
%}

%%
[a|e|i|o|u] {flag = 1; display(flag, yytext);}
. {flag = 0; display(flag, yytext);}
%%

int yywrap(){return 0;}

int main(){
    printf("\nEnter the word: ");
    yylex();
    return 0;
}

void display(int flag, char *t){
if(flag==1){
printf("\nThe given character %s is a vowel\n", t);
}
else{
printf("\nThe given character %s is not vowel\n", t);
}
}

