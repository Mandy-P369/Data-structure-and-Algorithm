#include<stdio.h>
int main()
{
    int a = 10 ; //initialise the value a ..
    int *aptr,*bptr;
    int b ;
    /*We have not yet give the address of a */


    /*Giving  the address of a */
     aptr = &a;
     printf("\n A%d , aptr %d , *aptr : %d",a,aptr,*aptr);
    /*If we store the address of 'a' the bptr */
     bptr = &aptr ;//address of aptr is also stored  inside the bptr..
     /*If we store the address of bptr inside the cptr*/
     int c=5;
     int *cptr ;
     cptr = &bptr;
     printf("\n C%d , cptr %d , *cptr : %d",c,cptr,*cptr);
     /*=================================================*/
     printf("\n B%d , bptr %d , *bptr : %d",b,bptr,*bptr);

     bptr = &b ; //The address of the b is given to the bptr ..



}
