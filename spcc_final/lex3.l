%{
    int w, c, l;
%}

%% 

[\n]  {
    l++;  w++;
    }
[A-Z] {
        c++;
    }
[a-z] {
        c++;
    }
[ ] {
    w++;
}

%%
int main(){
    printf("Enter sentences \n");
    yylex();
    printf("%d word, %d character, %d line",w,c,l);
    return 0;
}
