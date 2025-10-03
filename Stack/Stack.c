#include<stdio.h>
struct Student
{
    int data ;
    struct Student *next;
}*top;
struct Student *createNode()
{
    struct Student *ptr;
    ptr=(struct Student *)malloc(sizeof(struct Student));
    printf("\n Enter the data to insert inside the node");
    scanf("%d",&ptr->data );
    return ptr;
};
void AddNode()
{
    struct Student *ptr = createNode();
    if(ptr==NULL)
    {
        printf("\n Can't allocate the memory");
        return ;
    }
    else
    {
        if(top==NULL)
        {
            top=ptr;
            ptr->next=NULL;
        }
        else
        {
            ptr->next = top;
            top =ptr ;
        }
        printf("\n New node added successfully");
    }
}
void Traverse()
{
    struct Student *ptr;
    ptr = top ;
    do
    {
        printf("\n The nodes are : %d",ptr->data );
        ptr=ptr->next ;

    }
    while(ptr!=NULL);
}
void AddBeginning()
{
    struct Student *ptr;
    ptr=createNode();
    if(ptr==NULL)
    {
        printf("\n Can't allocate  the memory");
        return;
    }
    else
    {
        if(top==NULL)
        {
            top=ptr;
            ptr->next = NULL;
        }
        else
        {
            ptr->next=top;
            top=ptr;
        }
    }
}
void Pop()
{
    if(top==NULL)
    {
        printf("\n First please insert some node");
        return ;
    }
    else
    {
        struct Student *ptr;
        ptr=top;
        top= top->next;
        free(ptr);
        printf("\n Node deleted successfully");
    }
}
void main ()
{
    top = NULL;
    int key;
    do
    {
        printf("\n1 Add the node inside the stack");
        printf("\n2.Traverse node of stack");
        printf("\n Enter key from 1-3 \t:");
        scanf("%d",&key);
        if(key==1)
        {
            AddNode();
        }
        else if(key==2)
        {
            Traverse();
        }
        else if (key==3)
        {
            AddBeginning();
        }
        else if (key==4)
        {
            Pop();
        }
    }
    while(key!=5);
}

