/*Here ch is a pointer and str is the String*/
#include<stdio.h>
void main()
{
    char str[10],*ch;
    printf("\n Enter the String");
    scanf("\n%s",&str);
    ch = &str;
    printf("\n%s",str);
    printf("\n%x",ch);

    ch = ch+2;
    printf("\n The address increased : %d",ch);
}




