#include<iostream>
using namespace std;

class Node{
public:
    int key;
    Node *next;
};

class LinkedList{
public:
    Node *head, *tail;

    LinkedList(){
        head = NULL;
        tail = NULL;
    }

private:
    Node* findFirstOccurrence(int v)
    {

    }
    Node* findLastOccurence(int v);
    Node* findMiddleElement();
    Node* findPreviousNode(Node  *cur);

public:
    void insertAtFirst(int v)
    {
        head->key=v;
        head->next=NULL;
        head=tail;
    }
    void insertAtLast(int v)
    {
        Node *temp=(Node*)malloc(sizeof(Node));
        temp->key=v;
        temp->next=NULL;
        tail->next=temp;
        tail=temp;
    }
    bool insertAfterFirstOccurrence(int v, int nV)
    {
        Node* temp;
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            if(temp->key==v) break;
        }
        if(temp->key!=v) return false;
        Node *N=(Node*)malloc(sizeof(Node));
        N->key=nV;
        N->next=temp->next;
        temp->next=N;
    }
    bool insertAfterLastOccurrence(int v, int nV)
    {
        Node* temp;
        Node* last;
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            if(temp->key==v) 
            last=temp;
        }
        if(last->key!=v) return false;
        Node *N=(Node*)malloc(sizeof(Node));
        N->key=nV;
        N->next=last->next;
        last->next=N;
    }
    bool deleteFromFirst()
    {
        Node* temp=head->next;
        temp=head;
        delete head;
    }
    bool deleteFromLast()
    {
        Node* temp;
        for(temp=head;temp!=NULL;temp=temp->next->next)
        {}
        delete tail;
        tail=temp;
    }
    bool deleteFirstOccurrence(int v);
    bool deleteLastOccurrence(int v);
    void bubbleSort();
    void print();
};

int main(){
    cout<<"1. Insert At First."<<endl<<"2. Insert at last."<<endl<<"3. Insert after first occurrence."<<endl<<"4. Insert after last occurrence."<<endl;
    cout<<"5. Delete from first."<<endl<<"6. Delete from last."<<endl<<"7. Delete first occurrence."<<endl<<"Delete last occurrence."<<endl;
    cout<<"9. Sort."<<endl<<"10. Print."<<endl<<"11. Exit"<<endl<<endl;

    int choice;
    LinkedList l;

    while(1){
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice==1){
            cout<<"Enter the value: ";
            int v;
            cin>>v;
            l.insertAtFirst(v);
            cout<<v<<" is inserted at the first."<<endl;
        }
        else if(choice==2){
            cout<<"Enter the value: ";
            int v;
            cin>>v;
            l.insertAtLast(v);
            cout<<v<<" is inserted at the last."<<endl;
        }
        else if(choice==3){
            cout<<"Enter the value after which you want to insert: ";
            int v;
            cin>>v;
            cout<<"Enter the value which you want to insert: ";
            int nV;
            cin>>nV;
            if(l.insertAfterFirstOccurrence(v, nV)) cout<<nV<<" inserted successfully after the first occurrence of "<<v<<"."<<endl;
            else    cout<<"Insertion failed."<<endl;
        }
        else if(choice==4){
            cout<<"Enter the value after which you want to insert: ";
            int v;
            cin>>v;
            cout<<"Enter the value which you want to insert: ";
            int nV;
            cin>>nV;
            if(l.insertAfterLastOccurrence(v, nV)) cout<<nV<<" inserted successfully after the last occurrence of "<<v<<"."<<endl;
            else    cout<<"Insertion failed."<<endl;
        }
        else if(choice==5){
            if(l.deleteFromFirst()) cout<<"First element is deleted."<<endl;
            else    cout<<"Deletion failed."<<endl;
        }
        else if(choice==6){
            if(l.deleteFromLast()) cout<<"Last element is deleted."<<endl;
            else    cout<<"Deletion failed."<<endl;
        }
        else if(choice==7){
            cout<<"Enter the value which you want to delete ";
            int v;
            cin>>v;
            if(l.deleteFirstOccurrence(v)) cout<<"First occurrence of "<<v<<" deleted successfully"<<"."<<endl;
            else    cout<<"Deletion failed."<<endl;
        }
        else if(choice==8){
            cout<<"Enter the value which you want to delete ";
            int v;
            cin>>v;
            if(l.deleteLastOccurrence(v)) cout<<"Last occurrence of "<<v<<" deleted successfully"<<"."<<endl;
            else    cout<<"Deletion failed."<<endl;
        }
        else if(choice==9){
            l.bubbleSort();
            cout<<"List sorted."<<endl;
        }
        else if(choice==10){
            cout<<"The list is: ";
            l.print();
            cout<<endl;
        }
        else if(choice==11){
            break;
        }
        else{
            cout<<"Invalid choice."<<endl;
        }

        cout<<endl<<endl;
    }
}
