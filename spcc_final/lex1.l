%{

%}

%%

a|e|i|o|u|A|E|I|O|U {
    printf("Character %s is a vowel\n", yytext);
}

. {
    printf("Character %s is a consonant\n", yytext);
}

%%

int main(){
    yylex();
    return 0;
}
