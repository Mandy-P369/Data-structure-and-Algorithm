#include<stdio.h>
struct Student
{
    int rollno;
    struct Student *next,*prev;
}*start,*end;
struct Student *createNode()
{
    struct Student *ptr;
    ptr=(struct Student *)malloc(sizeof(struct Student));
    printf("\nEnter the rollno");
    scanf("%d",&ptr->rollno);
    return ptr ;
}
void addStudent()
{
    struct Student *ptr= createNode();
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
            end=ptr;
            ptr->next=NULL;
            ptr->prev=NULL;
        }
        else
        {
            end->next =ptr;
            ptr->prev =end;
            ptr->next = NULL;
            end=ptr;
        }
        printf("\n Node added Successfully");
    }
}
void showStudent()
{
    printf("\n Print the data from start to end :");
    struct Student *ptr;
    for(ptr=start ; (ptr); ptr=ptr->next)
    {
        printf("%d ->",ptr->rollno);
    }
}
void showAllStudent()
{
    printf("\n Print the data from start to end :");
    struct Student *ptr;
    for(ptr=end ; (ptr); ptr=ptr->prev)
    {
        printf("%d ->",ptr->rollno);
    }
}
void searchStudent()
{
    struct Student *ptr ;
    int rno,flag=0;
    printf("Enter the rollno which you want to search ");
    scanf("%d",&rno);
    for(ptr=start; (ptr); ptr=ptr->next)
    {
        if(ptr->rollno==rno)
        {
            printf("\n Student Data Found !!");
            printf("\n The rollno is %d : ",ptr->rollno);
            printf("\n _______________________________");
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\n No Student with roll-no %d found",rno);
    }
}
void deleteStudent()
{
    struct Student *ptr ;
    int rno;
    printf("\n Enter the node which you want to delete :");
    scanf("%d",&rno);
    for(ptr=start ; (ptr); ptr=ptr->next)
    {
        if(ptr->rollno==rno)
        {
            if(start==NULL)
            {
                printf("First insert some node first ");
                return ;
            }
            if(ptr==start)
            {
                start = start->next;
                start->prev = NULL;
                return ;
            }
            else if(ptr==end)
            {
                end=end->prev;
                end->next=NULL;
                return ;
            }
            else
            {
                ptr->prev->next = ptr->next ;
                ptr->next->prev = ptr->prev ;
            }
            free(ptr);
            printf("\n Node deleted successfully");
            break;
        }
    }
}
void addAtBeginning()
{
    struct Student *ptr=createNode();
    if(ptr==NULL)
    {
        printf("\nCan't allocate memory for the node");
        return ;
    }
    else
    {
        ptr->prev=NULL;
        ptr->next=start;
        start->prev = ptr;
        start=ptr;
    }
    printf("\n New node added at the beginning");
}
void addAtEnd()
{
    struct Student *ptr ;
    ptr = createNode();
    if(ptr==NULL)
    {
        printf("\n Can't allocate memory for the node");
        return ;
    }
    else
    {
        ptr->prev=end;
        end->next= ptr;
        end=ptr;
        ptr->next = NULL;

    }
    printf("\n New node added at the End");
}
void addAtMiddle()
{
    if (start == NULL)
    {
        printf("\nList is empty. Cannot insert in the middle.");
        return;
    }

    struct Student *ptr = createNode(); // create new node
    if (ptr == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }

    int rno;
    printf("\nEnter the roll number after which you want to insert: ");
    scanf("%d", &rno);

    struct Student *p = start;
    while (p != NULL)
    {
        if (p->rollno == rno)
        {
            // Insert after p
            ptr->next = p->next;
            ptr->prev = p;

            if (p->next != NULL)
            {
                p->next->prev = ptr;
            }
            else
            {
                end = ptr;
            }

            p->next = ptr;
            printf("\nNode inserted successfully after roll number %d", rno);
            return; // insertion done
        }
        p = p->next;
    }

    printf("\nRoll number %d not found in the list!", rno);
}

void sortStudents()
{
    if(start==NULL)
    {
        printf("\n Nothing to sort,becuase of empty list");
        return;
    }
    else
    {
        struct Student *p1,*p2;
        int temp ;
        for(p1=start; (p1); p1=p1->next)
        {
            for(p2=start; (p2); p2=p2->next)
            {
                if(p1->rollno>p2->rollno)
                {
                    temp=p1->rollno;
                    p1->rollno=p2->rollno;
                    p2->rollno=temp;
                }
            }
        }
        printf("\n Student sorted according to the Roll number");
    }
}
void  main()
{
    start=NULL;
    end=NULL;
    int key;
    int c ;
    do
    {
        printf("\n\n\n1.Add Student");
        printf("\n2.Show All Student (Start-End");
        printf("\n3.Show All Student (End-Start)");
        printf("\n4.Search Student");
        printf("\n5.Delete Student");
        printf("\n6.Add Student at beginning");
        printf("\n7.Add Student at middle");
        printf("\n8.Add Student at end");
        printf("\n9.To sort the node : ");
        printf("\n10.Exit");
        printf("\nEnter the key from 1-10 : ");
        scanf("%d",&key);
        if(key==1)
        {
            addStudent();
        }
        else if(key==2)
        {
            showStudent();
        }
        else if(key==3)
        {
            showAllStudent();
        }
        else if (key==4)
        {
            searchStudent();
        }
        else if(key==5)
        {
            deleteStudent();
        }
        else if(key==6)
        {
            addAtBeginning();
        }
        else if (key==7)
        {
            addAtMiddle();
        }
        else if(key==8)
        {
            addAtEnd();
        }
        else if (key==9)
        {
            sortStudents();
        }
    }
    while(key!=10);
}
