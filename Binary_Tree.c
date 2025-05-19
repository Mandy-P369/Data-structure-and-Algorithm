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
            r=r->left;
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
        printf("\nMemory cannot be allocated");
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
            parent=Search(ptr->data,root);
            if(parent==NULL)
            {
                printf("\n The node already exists");
            }
            else
            {
                if(parent->data>ptr->data)
                    parent->left=ptr;
                else
                    parent->right=ptr;
                ptr->left=NULL;
                ptr->right=NULL;
            }
        }
    }
}
void inorder(struct Tree *r)
{
    if(r==NULL)
    {
        return ;
    }
    inorder(r->left);
    printf("\nThe data is %d",r->data);
    inorder(r->right);
}
void preorder(struct Tree *r)
{
    if(r==NULL)
    {
        return;
    }
    printf("\n The data is %d",r->data);
    preorder(r->left);
    preorder(r->right);
}
void postorder(struct Tree *r)
{
    if(r==NULL)
    {
        return;
    }
    printf("\n The data is %d",r->data);
    postorder(r->right);
    postorder(r->left);
}
NodeTraversal()
{
    int ch;
    do
    {
        printf("\n Inorder Traversal");
        printf("\n Preorder Traversal");
        printf("\n Postorder Traversal");
        scanf("\n%d",&ch);
        if(ch==1)
        {
            inorder(root);
        }
        else if(ch==2)
        {
            preorder(root);
        }
        else if(ch==3)
        {
            postorder(root);
        }
        else if(ch==4)
        {
            return ;

        }
    }
    while(ch!=5);
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
        else if (key==3)
        {
            nodeDeletion();
        }
    }
    while(key!=3);
}
