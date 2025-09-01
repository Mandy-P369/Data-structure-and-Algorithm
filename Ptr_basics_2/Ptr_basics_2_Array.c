#include<stdio.h>
void main()
{
    /*Array*/
    int arr[] = {10,20,30,40,50,60};
    int *p[5];
    for(int i=0; i<=5; i++)
    {
        p[i] = &arr[i+1];
        printf("\n The address of p is : %d",*p[i]);
    }


    int arr1[] = {97,98,99,100,101,102,103,104};
    for(int i=0; i<7; i++)
    {
        char *ch= &arr1[i];
        /*To check whether the letter at index of number*/
        printf("\n The array in words form : %d , %d",ch,*ch);
        ch++;
    }
}
