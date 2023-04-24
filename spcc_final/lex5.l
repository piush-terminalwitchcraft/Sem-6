%{
    char name[100];
%}

%%

[\n] {
        printf("Hello %s", name);
    }

%%

int main(){
    printf("Enter name \n");
    scanf("%s",name);
    yylex();
    return 0;
}
