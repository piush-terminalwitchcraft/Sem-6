%{ 
int flag; 
int count=0; 
void display(int,char); 
%} 
%% 
[a|e|i|o|u] { 
 flag=1; %{ 
int flag; 
int count=0; 
void display(int,char); 
%} 
%% 
[a|e|i|o|u] { 
 flag=1; 
 display(flag,yytext); 
} 
. { 
 flag=0; 
 display(flag,yytext); 
} 
%% 
int yywrap(){ 
 return 1; 
} 
void display(int flag,char yytext) 
{ 
 if(flag==0) printf("\n%s is consonent",yytext); 
 
 else printf("\n%s is vowel",yytext); 
} 
void main(){ 
 printf("Enter the input character : "); 
 yylex(); 
}
 display(flag,yytext); 
} 
. { 
 flag=0; 
 display(flag,yytext); 
} 
%% 
int yywrap(){ 
 return 1; 
} 
void display(int flag,char yytext) 
{ 
 if(flag==0) printf("\n%s is consonent",yytext); 
 
 else printf("\n%s is vowel",yytext); 
} 
int main(){ 
 printf("Enter the input character : "); 
 yylex();
 return 0;
}
