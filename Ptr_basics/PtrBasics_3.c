#include<stdio.h>
void main()
{
    int a = 7;
    int *aptr,*bptr;
    /*Address of a*/
    /*On incrementing or decrementing the value of a , the
    address will remaun as same as earlier*/
    aptr =&a;
    printf("\na : %d,aptr : %d,*aptr : %d",a,aptr,*aptr);

    a+=1 ;
    printf("\na : %d,aptr : %d,*aptr : %d",a,aptr,*aptr);

    a+=14;
    printf("\na : %d,aptr : %d,*aptr : %d",a,aptr,*aptr);

    a+=8;
    printf("\na : %d,aptr : %d,*aptr : %d",a,aptr,*aptr);
    /*------------------------------------------------*/

    *aptr+=35;
    printf("\n%d",*aptr);

    int *cptr = & *aptr;
    printf("\n%d",cptr);

    aptr = aptr+1;
    printf("\n %d",aptr);/*There will be the increment of 4 byte in the address*/

    aptr += 10;
    printf("\n %d",aptr);/*Increment of 40 byte*/

    /*--------------------------------------------------*/
    /*We cannot use the operands * and / for the operation of the pointer address*/
    //    aptr = aptr*5;
    //    printf("\n%d",aptr);
    /*--------------------------------------------------*/
    /*We can only use the operands * and / for the operation of pointer not for their address*/
    *aptr = *aptr*8;
    printf("\n%d",*aptr);
    /*--------------------------------------------------*/



}
