#include<stdio.h>
struct Tree
{
    int data ;
    struct Tree *left,*right;
}*root;
struct Tree *Search(int d,struct Tree *r)
{
    struct Tree *prev;
    while(r!=NULL)
    {
        if(r->data==d)
        {
            return NULL;
        }
        else if(r->data>d)
        {
            prev=r;
            r=r->left ;
        }
        else if(r->data<d)
        {
            prev=r;
            r=r->right;
        }
    }
    return prev;
};
void NodeInsertion()
{
    struct Tree *ptr,*parent;
    ptr = (struct Tree *)malloc(sizeof(struct Tree));
    printf("\n Enter the data");
    scanf("\n%d",&ptr->data);
    if(ptr==NULL)
    {
        printf("\n Memory cannot be allocated");
    }
    else
    {
        if(root==NULL)
        {
            root=ptr;
            ptr->left=NULL;
            ptr->right=NULL;
        }
        else
        {
            Parent=Search(ptr->data,root);
            if(parent==NULL)
            {
                printf("\n The node already exists");
            }
            else
            {
                if(parent->data>ptr->data)
                {
                    parent->left=ptr;
                }
                else if
                {
                parent->right=ptr;
                }
                ptr->left=NULL;
                ptr->right=NULL;
            }
        }
    }
}
void NodeTraversal()
{
    struct Tree *ptr;
}
int main()
{
    root = NULL;
    int key ;
    do
    {
        printf("\n 1.Insertion of node");
        printf("\n 2.Traverse");
        printf("\n 3.Deletion of node");
        printf("\n Exit");
        printf("\n Select the choice from 1-3");
        scanf("\n%d",&key);
        if(key==1)
        {
            NodeInsertion();
        }
        else if(key==2)
        {
            NodeTraversal();
        }
        else if (Key==3)
        {
            NodeDeletion();
        }
    }
    while(key!=4)
    }


