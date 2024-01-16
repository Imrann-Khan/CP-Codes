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
        Node* newNode=(Node*)malloc(sizeof(Node));
        if(newNode==NULL){cout<<"Stack overflow"<<endl; exit(1);}
        newNode->val=n;
        newNode->next=NULL;
        newNode->next=top;
        top=newNode;
    }

    bool isEmpty(){
        if(top==NULL)return true;
        else return false;
    }

    int showTop(){
        ///Stack functionality: Returns the last inserted value/top value of the stack (doesn't remove from stack)
        ///Linked list functionality: Returns the value located at head
        ///If the user calls this function for an empty stack, it will generate runtime error
        if(isEmpty()){
            cout<<"Empty"<<endl;
            return 0;
        }
        return top->val;
    }

    void pop(){
        ///Stack functionality: Removes the top value of the stack
        ///Linked list functionality: if the list is not empty then removes the node under head and declares new head
        ///If the user calls this function for an empty stack, it will generate runtime error
        if(top==NULL){cout<<"Stack underflow."<<endl; exit(1);}
        Node* temp=top;
        top=top->next;
        delete temp;
    }

    int size(){
        Node* temp=top;int l=0;
        while(temp!=NULL){
            temp=temp->next;
            l++;
        }
        return l;
    }

    void displaystack(){
        Node* temp=top;
        cout<<"Stack: ";
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
};


int main(){
    int choice;
    bool x=true;
    Stack s;
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
                int n;
                cout<<"Enter value: ";
                cin>>n;
                s.push(n);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                ///Must check whether the stack is empty or not before viewing top item
                cout<<"The top is: "<<s.showTop();
                break;

            case 4:
                cout<<"Size of the stack: ";
                cout<<s.size();
                break;

            case 5:
                s.displaystack();
                break;

            default:
                cout<<"An Invalid choice."<<endl;
        }

        cout<<endl<<endl;
    }


    return 0;
}
