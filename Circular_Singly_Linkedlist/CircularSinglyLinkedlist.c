#include<stdio.h>
#include<stdbool.h>
struct Student
{
    int rollno ;
    struct Student *next;
}*start;
struct Student *createNode()
{
    struct Student *ptr;
    ptr=(struct Student *)malloc(sizeof(struct Student));
    printf("\n Enter the rollno ");
    scanf("%d",&ptr->rollno);
    return ptr;
};
void addStudent()
{
    struct Student *ptr;
    ptr=createNode();
    if(ptr==NULL)
    {
        printf("\nCan't allocate the memory");
        return ;
    }
    else
    {
        if(start==NULL)
        {
            start=ptr;
            ptr->next=start;
        }
        else
        {
            struct Student *p;
            p=start ;
            while(p->next!=start)
            {
                p=p->next;
            }
            p->next=ptr;
            ptr->next =start;
            printf("\n New node added successfully");
        }
    }
}
void addAtBeginning()
{
    struct Student *ptr=createNode();
    if(ptr==NULL)
    {
        printf("\nCan't allocate the memory");
        return;
    }
    else
    {
        if(start==NULL)
        {
            start = ptr;
            ptr->next = start;
        }
        else
        {
            struct Student *last;
            last =start;
            do
            {
                last=last->next;
            }
            while(last->next!=start);
            last->next = ptr;
            ptr->next =start;
            start = ptr;
            printf("\n New node added successfully at the beginning");
            return ;
        }
    }
}
void Traverse()
{
    struct Student *p;
    p=start;
    do
    {
        printf("%d ->  ",p->rollno);
        p=p->next;
    }
    while(p!=start);
}
void AddAtMiddle()
{
    struct Student *ptr=createNode();
    if(ptr==NULL)
    {
        printf("\nCan't allocate the memory");
        return ;
    }
    else
    {
        struct Student *last ;
        if(start==NULL)
        {
            start = ptr ;
            ptr->next =start;
        }
        else
        {
            int no ;
            printf("\nEnter the number after which you insert the values");
            scanf("%d",&no);
            if(ptr->rollno==no)
            {
                last =start;
                while(last->next!=start)
                {
                    last = last->next ;
                }
                last =ptr;
                ptr->next = last->next;
                last->next =ptr;
            }
            printf("\n New node added at the beginning");
        }
    }
}
void AddAtEnd()
{
    struct Student *ptr=createNode();
    if(ptr==NULL)
    {
        printf("\nCan't allocate the memory");
    }
    else
    {
        struct Student *p ;
        if(start==NULL)
        {
            start = ptr;
            ptr->next =start;
        }
        else
        {
            p=start ;
            while(p->next!=start)
            {
                p=p->next;
            }
            p->next=ptr;
            ptr->next =start;
            printf("\n New node added successfully");
        }
    }
}
void main()
{
    int start =NULL;
    int key ;
    do
    {
        printf("\n1.Add Student");
        printf("\n2.Add at beginning");
        printf("\n3.Add at Middle");
        printf("\n4.Add at End");
        printf("\n5.Traverse Node");
        printf("\n6.Exit");
        printf("\n.Enter the key from 1-3\t");
        scanf("%d",&key);
        if(key==1)
        {
            addStudent();
        }
        else if(key==2)
        {
            addAtBeginning();
        }
        else if (key==3)
        {
            AddAtMiddle();
        }
        else if(key==4)
        {
            AddAtEnd();
        }
        else if(key==5)
        {
            Traverse();
        }
    }
    while(key!=6);
}
