#include<stdio.h>
struct List
{
    int data ;
    struct List *next,*prev;
}*start,*end;
struct List *createCode()
{
    struct List *ptr;
    ptr=(struct List *)malloc(sizeof(struct List));
    printf("\n Enter the data");
    scanf("\n%d",&ptr->data);
    return ptr;
};
void Insertion()
{
    struct List *ptr=createCode();
    struct List *p;
    if(ptr==NULL)
    {
        printf("\n Memory cannot be allocated");
    }
    else
    {
        if(start==NULL)
        {
            ptr->next=NULL;
            ptr->prev=NULL;
            start=ptr;
            end=ptr;
        }
        else
        {
            end->next=ptr;
            ptr->next=NULL;
            ptr->prev=end;
            end=ptr;
        }
        printf("\n New node added successfully");
    }
}
void TraversalThroughWhileLoop()
{
    struct List *ptr=start;
    while(ptr!=NULL)
    {
        printf("\n The data is %d",ptr->data);
        ptr=ptr->next;
    }
}
void TraversalThroughForLoop()
{
    struct List *ptr;
    for(ptr=start; (ptr); ptr=ptr->next)
    {
        printf("\n The data is %d",ptr->data);
    }
}
void TraversalThroughDo_WhileLoop()
{
    struct List *ptr;
    ptr=start;
    do
    {
        printf("\n The data is %d",ptr->data);
        ptr=ptr->next;
    }
    while(ptr!=NULL);
}
void NodeAddAtBeginning()
{
    struct List *ptr;
    ptr=createCode();
    if(ptr==NULL)
    {
        printf("\n Memory cannot be allocated");
    }
    else
    {
        if(start==NULL)
        {
            printf("\n No Record of node exist ");
            return ;
        }
        else
        {
            ptr->next=start;
            start->prev=ptr;
            start=ptr;
            ptr->prev = NULL;
        }
    }
}
void NodeAddAtMiddle()
{
    struct List *ptr;
    ptr=createCode();
    if(ptr==NULL)
    {
        printf("\n Memory cannot allocated");
        return;
    }
    else
    {
        if(start==NULL)
        {
            printf("\n No Record of node exist ");
            return ;
        }
        else
        {
            int rollno;
            printf("\n Enter the rollno after which you insert the node");
            scanf("\n%d",&rollno);
            struct List *p;
            for(p=start; (p); p=p->next)
            {
                if(p->data==rollno)
                {
                    p->next->prev = ptr;
                    ptr->next=p->next;
                    ptr->prev = p;
                    p->next=ptr;
                }
            }
        }
    }
}
void main()
{
    start=NULL;
    end =NULL;
    int key;
    do
    {
        printf("\n 1.Insertion of node");
        printf("\n 2.Traversal of node");
        printf("\n 3.Deletion of node");
        printf("\n 4.Updation of node");
        printf("\n 5.Exit");
        printf("\n Select the choice from 1-4 :");
        scanf("\n%d",&key);
        if(key==1)
        {
            Insertion();
        }
        else if(key==2)
        {
            TraversalThroughForLoop();
        }
        else if(key==3)
        {
            TraversalThroughWhileLoop();
        }
        else if (key==4)
        {
            TraversalThroughDo_WhileLoop();
        }
        else if(key==5)
        {
            NodeAddAtBeginning();
        }
        else if (key==6)
        {
            NodeAddAtMiddle();
        }
         else if(key==6)
         {
             NodeAddAtEnd();
         }
    }
    while(key!=7);
}
