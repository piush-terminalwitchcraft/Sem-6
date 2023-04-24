#include<stdio.h>
main()
{
char buff[5];
printf("My stack looks  like:\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n");
buff[5]='abcdefghijklmnophsgkgfks';
printf("%c\n",buff[5]);
printf("My new stack looks like:\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n");
}

