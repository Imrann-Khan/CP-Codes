#include<bits/stdc++.h>
using namespace std;

class Node{
private:
    int val;
    Node *next;
public:
    Node(){
        next = NULL;
    }

    int getValue(){
        return val;
    }
    friend class Stack;
};

class Stack{
private:
    Node *top;
    int SIZE;
public:
    Stack(){
        top = NULL;
        SIZE = 0;
    }

    void push(int n){
        ///Stack functionality: Inserts n in the stack
        ///Linked list functionality: Creates a node and inserts at the head of the list
        Node* newItem=(Node*)malloc(sizeof(Node));
        if(top==NULL)
        {
            newItem->val=n;
            newItem->next=NULL;
            top=newItem;
        }
        else
        {
            newItem->val=n;
            newItem->next=top;
            top=newItem;
        }
    }

    bool isEmpty(){
        ///Stack functionality: Returns true if the stack is empty, otherwise returns false
        if(top==NULL) return true;
        else return false;
    }

    int showTop(){
        ///Stack functionality: Returns the last inserted value/top value of the stack (doesn't remove from stack)
        ///Linked list functionality: Returns the value located at head
        ///If the user calls this function for an empty stack, it will generate runtime error
        if(isEmpty())
        {
            cout<<"Runtime Error(Stack is Empty) "<<endl;
            return 0;
        }
        else return top->val;
    }

    void pop(){
        ///Stack functionality: Removes the top value of the stack
        ///Linked list functionality: if the list is not empty then removes the node under head and declares new head
        ///If the user calls this function for an empty stack, it will generate runtime error
        Node* temp=top;
        top=top->next;
        delete temp;
    }

    int size(){
        ///Returns the size of stack
        int l=0;
        Node* temp=top;
        while(temp!=NULL)
        {
            l++;
            temp=temp->next;
        }
        return l;
    }

    void displaystack(){
        ///Prints the stack
        Node* temp=top;
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
};


int main(){
    int choice;
    bool x=true;
    Stack n;
    while(x)
    {
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - View Top Item."<<endl;
        cout<<"4 - Size of Stack."<<endl;
        cout<<"5 - Display Items (Print STACK)."<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 0:
                x=false;
                break;

            case 1:
                int val;
                cout<<"Enter the value: ";
                cin>>val;
                n.push(val);
                x=true;
                break;

            case 2:
                ///Must check whether the stack is empty or not before popping
                n.pop();
                break;

            case 3:
                ///Must check whether the stack is empty or not before viewing top item
                cout<<n.showTop();
                break;

            case 4:
                cout<<"Size of Stack: ";
                cout<<n.size();
                break;

            case 5:
                n.displaystack();
                break;

            default:
                cout<<"An Invalid choice."<<endl;
        }

        cout<<endl<<endl;
    }


    return 0;
}
