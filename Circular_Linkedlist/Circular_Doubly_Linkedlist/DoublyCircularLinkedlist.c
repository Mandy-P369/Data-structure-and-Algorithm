#include<stdio.h>
struct Student
{
    int data ;
    struct Student *next,*prev;
}*start,*end;
struct Student *createNode()
{
    struct Student *ptr;
    ptr=(struct Student *)malloc(sizeof(struct Student));
    printf("\n Enter the data :");
    scanf("%d",&ptr->data);
    return ptr ;
};
void AddStudent()
{
    struct Student *ptr ;
    ptr=createNode();
    if(ptr==NULL)
    {
        printf("\n Can't allocate the memory");
        return ;
    }
    else
    {
        if(start==NULL)
        {
            start = ptr ;
            end=ptr;
            ptr->next=start ;
            ptr->prev=end;
        }
        else
        {
            end->next = ptr;
            ptr ->prev =end ;
            ptr->next =start;
            end = ptr ;
            start->prev =end;
        }
        printf("\n New node added successfully");

    }
}
void Traverse()
{
    struct Student *ptr ;
    ptr=start ;
    do
    {
        printf("%d  ->",ptr->data);
        ptr=ptr->next;
    }
    while(ptr!=start);
}
void rTraverse()
{
    struct Student *ptr;
    ptr=end;
    do
    {
        printf("%d  ->",ptr->data);
        ptr=ptr->prev;
    }
    while(ptr!=end);
}
void InsertAtBeginning()
{
    struct Student *ptr=createNode();
    if(ptr==NULL)
    {
        printf("\nCan't allocate the memory for the Node");
        return;
    }
    else
    {
        if(start==NULL)
        {
            start=ptr;
            end=ptr;
            ptr->next =start;
            ptr->prev=end;
        }
        else
        {
            ptr->next = start ;
            start->prev = ptr;
            start = ptr ;
            end->next=start;
            start->prev=end;
        }
        printf("\n New node added at the beginning of the list ");
    }
}
void InsertAtEnd()
{
    struct Student *ptr ;
    ptr = createNode();
    if(ptr==NULL)
    {
        printf("Can't allocate the memory for the node");
        return ;
    }
    else
    {
        if(start==NULL)
        {
            start=ptr;
            end=ptr;
            ptr->next = start;
            ptr->prev = end;
        }
        else
        {
            end ->next = ptr;
            ptr->next = start;
            ptr->prev =end;
            end=ptr;
            start->prev= end;
        }
        printf("\n New node added at the end of the List");
    }
}
void InsertAtMiddle()
{
    struct Student *ptr;
    ptr=createNode();
    if(ptr==NULL)
    {
        printf("\n Can't allocate the memory");
        return ;
    }
    else
    {
        if(start==NULL)
        {
            start=ptr;
            end=ptr;
            ptr->next = start;
            ptr->prev = end;
        }
        else
        {
            struct Student *p;
            int no  ;
            printf("\n Enter the roll-no which you want to delete :");
            scanf("%d",&no);
            p=start;
            do
            {
                if(p->data==no)
                {
                    p->next->prev = ptr ;
                    ptr->next = p->next ;
                    ptr->prev = p;
                    p->next = ptr;
                }
                p=p->next;
            }
            while(p!=start);
            printf("\nNew node added at the middle ");
        }
    }
}
void main()
{
    start = NULL;
    end= NULL;
    int key ;
    do
    {
        printf("\n1.Add Student");
        printf("\n2.Traverse (START-END)");
        printf("\n3.Traverse (END-START)");
        printf("\n4.Insert the Node at beginning");
        printf("\n5.Insert the Node at end");
        printf("\n6.Insert the Node at middle");
        printf("\nEnter the key from 1-7");
        scanf("%d",&key);
        if(key==1)
        {
            AddStudent();
        }
        else if(key==2)
        {
            Traverse();
        }
        else if(key==3)
        {
            rTraverse();
        }
        else if (key==4)
        {
            InsertAtBeginning();
        }
        else if(key==5)
        {
            InsertAtEnd();
        }
        else if(key==6)
        {
            InsertAtMiddle();
        }
    }
    while(key!=7);
}
