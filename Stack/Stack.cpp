#include<iostream>
using namespace std;
class Node
{
public :
    int data ;
    Node *next;
};
class Stack
{
private:
    Node *top;

public :
    Stack()
    {
        top=NULL; // If the top of the stack is NULL...
    }
    void push(int value)
    {
        Node *ptr = new Node;
        ptr->data =value;
        if(ptr==nullptr)
        {
            cout<<"Can't allocate the memory"<<endl;
            return ;
        }
        else
        {
            ptr->next = top;
            top = ptr;
            cout<<value<<"pushed to stack \n"<<endl;
        }
    }
    void pop()
    {
        if(Empty())
        {
            cout<<"Stack is Empty"<<endl;
            return ;
        }
        Node *ptr=top;
        cout<<top->data<<"Node popped from the stack"<<endl;
        top = top->next;
        delete ptr;
    }
    void peek()
    {
        if(Empty())
        {
            cout<<"Stack is empty"<<endl;
            return ;
        }
        cout<<"Top element  : "<<top->data<<endl;
    }

    void display()
    {
        if(Empty())
        {
            cout<<"Stack is empty /n"<<endl;
            return;
        }
        else
        {
            cout<<"\n Traversal of the node : "<<endl;
            Node *ptr = top;
            while(ptr!=nullptr)
            {
                cout<<ptr->data<<" -> ";
                ptr=ptr->next;
            }
            cout<<endl;
        }
    }
    //Method to check if the stack is Empty .
    bool Empty()
    {
        return top==nullptr;
    }
};
int main()
{
    Stack s ;
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.push(16);
    s.push(17);
    s.push(18);
    s.push(19);
    s.push(20);

    s.peek();
    s.peek();

    s.push(21);

    s.display();
    s.peek();
    s.display();

    s.pop();
    s.display();
    s.pop();
    s.display();
}

