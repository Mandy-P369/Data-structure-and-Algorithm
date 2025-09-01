#include<stdio.h>
struct Student
{
    struct Student *next;
    int rollno ;

}*start;
struct Student *createNode()
{
    struct Student *ptr = NULL;
    ptr = (struct Student *)malloc(sizeof(struct Student));
    printf("\n Enter the rollno");
    scanf("\n%d",&ptr->rollno);
    return ptr;
};
void addStudent()
{
    struct Student *ptr= NULL;
    ptr = createNode();
    if(ptr==NULL)
    {
        printf("Memory cannot be alloted");
    }
    else
    {
        if(start == NULL)
        {
            start = ptr;
            ptr->next = NULL;
        }
        else
        {
            struct Student *p,*prev;
            for(p=start; p!=NULL; p=p->next)
            {
                prev = p;
            }
            prev->next= ptr;
            ptr ->next =NULL;
        }
    }
}

void ShowAllStudents()
{
    struct Student *p;
    for(p=start; (p); p=p->next)
    {
        printf("\n The rollno are : %d",p->rollno);
        printf("\n------------------");
    }
}

void addbeg()
{
    struct Student *ptr;
    ptr= createNode();
    ptr->next =start;
    start=ptr;
    printf("\nNode created at the beginning");
}

void addmid()
{
    if(start==NULL)
    {
        printf("\n Insert some nodes first ");
        return ;
    }
    else
    {
        int no ;
        struct Student *p;
        struct Student *ptr=createNode();
        printf("\n Enter the p value ");
        scanf("\n%d",&no);
        for(p=start; p!=NULL; p=p->next)
        {
            if(p->rollno==no)
            {
                ptr->next=p->next;
                p->next=ptr;
            }
        }
    }
}

void addend()
{
    printf("Insert the node at the end");
    struct Student *ptr =createNode();

    if(start==NULL)
    {
        printf("\n Insert some nodes first.....");
    }
    else
    {
        struct Student *last,*p;
        for(p=start;p!=NULL;p=p->next)
        {
            last=p;
        }
        last->next=ptr;
        ptr->next=NULL;
        printf("\n New node inserted at the end ....");
    }
}
void main ()
{
    start=NULL;
    int key,mchoice;
    do
    {
        printf("\n1. Enter a Student");
        printf("\n2.Show All Students");
        printf("\n3.Delete Students");
        printf("\n4.Exit");
        printf("\n Enter a key");
        scanf("\n%d",&key);
        if(key==1)
        {
            addbeg();
        }
        else if (key==2)
        {
            addmid();
        }
        else if (key==3)
        {
            addend();
        }
        else if (key==4)
        {
            ShowAllStudents();
        }
    }
    while(key!=5);
}
