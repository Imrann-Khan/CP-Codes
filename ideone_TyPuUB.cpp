#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *L, *R;
};
Node *head, *tail;

void insertAtLast(int x){
    Node *n = (Node*)malloc(sizeof(Node));
    n->key = x;
    n->L = NULL;
    n->R = NULL;
    if(head==NULL){
        head = n;
        tail = n;
        return;
    }
    tail->R = n;
    n->L = tail;
    tail = n;
}

void print(){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->key<<" ";
        temp = temp->R;
    }
    cout<<endl;
}

Node* findFirstOccurrence(int x){
    Node *temp = head;
    while(temp!=NULL){
        if(temp->key==x)    return temp;
        temp = temp->R;
    }
    cout<<endl;
}

void findAllPairs(int x){

}

void cutPasteFromMiddle(){

}

int main(){

    head = NULL;
    tail = NULL;

    cout<<"1. Insert at first"<<endl<<"2. Find first occurrence"<<endl<<"3. Print"<<endl;
    cout<<"4. Find all pairs"<<endl<<"5. Cut Paste From Middle"<<endl<<endl;

    while(1){
        int choice;
        cout<<"Choice: ";
        cin>>choice;
        if(choice==1){
            cout<<"Enter value: ";
            int x;
            cin>>x;
            insertAtLast(x);
            cout<<x<<" is inserted!"<<endl;
        }
        else if(choice==2){

        }
        else if(choice==3){
            print();
            cout<<endl;
        }
        else if(choice==4){
            cout<<"Enter value: ";
            int x;
            cin>>x;
            findAllPairs(x);
        }
        else if(choice==5){
            cutPasteFromMiddle();
            print();
        }
        else{
            cout<<"Invalid choice.";
        }

        cout<<endl;
    }
}
