#include<bits/stdc++.h>

using namespace std;

class node
{
    int key;
    node* next;
public:
    node()
    {
        next=NULL;
        this->key=key;
    }
};
class stackk{
public:
    friend class node;
    Stack()
    {
        node *top=NULL;
    }
    void push(int val)
    {
        node* temp=(node*)malloc(sizeof(node));
        if(top==NULL)
        {
            temp->key=val;
            temp->next=NULL;
            top=temp;
        }
        else
        {
            temp->key=val;
            temp->next=top;
            top=temp;
        }
    }
    void pop()
    {
        if(top==NULL) cout<<"Stack is underflow"<<endl;
        else
        {
            node* temp=top->next;
            free(top);
            top=temp;
        }
    }
    void curtop()
    {
        return top->key;
    }
    void print()
    {
        for(node* temp=top; temp!=NULL;temp=temp->next)
        {
            cout<<temp->key<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    stackk u;

    return 0;
}
