#include<stdio.h>
void main ()
{
    int a =10;
    int *ptr;
    ptr= &a;
    printf("\n%d",ptr); //Address of the value a
    printf("\n%d",*ptr);//This is the reflection of the address of the ptr.
  printf("\n%d",a); //This is the value ..
}
