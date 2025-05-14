#include<stdio.h>
struct List
{
    int data ;
    struct List *next;
}*start;
struct List *createNode()
{
    struct List *ptr;
    ptr=(struct List *)malloc(sizeof(struct List));
    printf("\n Enter the data to insert");
    scanf("\n%d",&ptr->data);
    return ptr;
};
void Insertion()
{
    struct List *ptr=createNode();
    if(ptr==NULL)
    {
        printf("\n Segmentation Faults ");//Memory cannot be allocated
        return;
    }
    else
    {
        if(start==NULL)
        {
            start=ptr;
            ptr->next=NULL;
        }
        else
        {
            struct List *prev,*p;
            for(p=start; (p); p=p->next)
            {
                prev=p;
            }
            prev->next=ptr;
            ptr->next=NULL;
            printf("\n New node insert Successfully \t");
        }
    }
}
void Traverse()
{
    printf("\n Traversal of the node from START to END");
    struct List *ptr;
    for(ptr=start; ptr!=NULL; ptr=ptr=ptr->next)
    {
        printf("\n Data is %d",ptr->data);
    }

}
void Deletion()
{
    struct List *ptr,*prev;
    int no ;
    printf("\n Enter the node which you want to delete");
    scanf("\n%d",&no);
    printf("\n The node you want to delete is %d:",no);
    for(ptr=start; ptr!=NULL; ptr=ptr->next)
    {
        if(ptr->data==no)
        {
            if(ptr==start)
            {
                start=start->next;
            }
            else if(ptr->next==NULL)
            {
                prev->next=NULL;
            }
            else
            {
                prev->next = ptr->next;
            }
            free(ptr);
            printf("\n Node deleted successfully");
            break;
        }
        prev=ptr;
    }
}
void updation()
{
    struct List *ptr,*prev;
    printf("\n Updation of the Entered node");
    int no ;
    printf("\n Enter the node which you want to update");
    scanf("\n%d",&no);
    printf("\n The node which you want to update is   : ",no);
    if(ptr==NULL)
    {
        printf("\n Underflow");
    }
    else
    {
        if(ptr->data==no)
        {
            if(ptr==start)
            {
                start=start->next;
                addatBeg();
            }
            else if(ptr->next==NULL)
            {
                prev->next = NULL;
                addAtEnd();
            }
            else
            {
                prev->next = ptr->next;
                addAtMiddle();
            }
            free(ptr);
            printf("\n Updation of the node");

        }
        prev=ptr;
    }
}
void addAtMiddle()
{

    printf("\n Insertion of the node at the beginning");
    struct List *ptr;
    ptr=createCode();
    if(ptr==NULL)
    {
        printf("\n Memory cannnot be allocated");
    }
    else{
        if(start==NULL)
        {
            printf("\n No records of nodes exists of which you insert the node at beginning");
            ptr->prev=NULL;
            ptr->next=NULL;
            start=ptr;
        }
        else
        {

        }
    }
}
void main()
{
    start=NULL;
    int key;
    do
    {
        printf("\n Insert node");
        printf("\n Traverse nodes");
        printf("\n Delete node");
        printf("\n Update node");
        printf("\n Select your choice from (1-4) :");
        scanf("\n%d",&key);
        if(key==1)
        {
            Insertion();
        }
        else if(key==2)
        {
            Traverse();
        }
        else if(key==3)
        {
            Deletion();
        }
         else if(key==4)
         {
             Updation();
         }
    }
    while(key!=5);
}
