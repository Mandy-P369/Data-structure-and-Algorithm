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
    struct Student *ptr;
    ptr=start;
    do
    {
        printf("%d ->  ",ptr->rollno);
        ptr=ptr->next;
    }
    while(ptr!=start);
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
void DeleteNode()
{
    if(start==NULL)
    {
        printf("No nodes insert in this list ");
        return ;
    }
    else
    {
        struct Student *prev,*ptr=start;
        int no ;
        printf("\n Enter number which you want to delete");
        scanf("%d",&no);
        while(ptr->next!=start)
        {
            if(ptr->rollno==no)
            {
                if(ptr==start)
                {
                    start = start->next;
                    prev->next =start;
                    return ;
                }
                else if( prev->next = ptr)
                {
                    prev->next =start;
                    return ;
                }
                else
                {
                    prev->next = ptr->next;
                    return;
                }
                ptr=ptr->next;
            }
            prev=ptr;
            free(ptr);
            printf("\n node deleted successfully \n");
            break ;
        }
    }
}
void SortNode()
{
    struct Student *ptr,*dtr;
    int temp ;
    ptr=start;
    while(ptr->next!=start)
    {
        dtr=start;
        while(dtr->next!=start)
        {
            temp=ptr;
            ptr=dtr;
            dtr=temp;
            dtr=dtr->next ;
        }
        ptr=ptr->next ;
    }
   printf("\n->",temp);
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
        printf("\n5.Deletion of Node");
        printf("\n6.Traverse");
        printf("\n7.Sorting of Node");
        printf("\n8.Exit");
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
        else if (key==5)
        {
            DeleteNode();
        }
        else if(key==6)
        {
            Traverse();
        }
        else if (key==7)
        {
            SortNode();
        }
    }
    while(key!=8);
}
