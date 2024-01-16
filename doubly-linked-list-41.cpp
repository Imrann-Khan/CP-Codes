
    //Mayesha tasnim 202114041

#include<iostream>
#include<cstdlib>
using namespace std;
#define LinkedList LL

class Node{
public:
    int key;
    Node *L,*R;
};
///// jate onek linked list nea jai tai head r tail ke linked list er moddhe rakha hoyeche
class LinkedList{
public:
    Node *head, *tail;

    LinkedList(){//constructor
        head = NULL;
        tail = NULL;
    }
//funtion prototype kora hoyeche,public eo lekha jabe
private:
    void createFirstElement(int v);
    Node* findFirstOccurrence(int v);
    Node* findLastOccurence(int v);
    Node* findKthNode(int k);

public:
    void insertAtFirst(int v);
    void insertAtLast(int v);
    bool insertAfterFirstOccurrence(int v, int nV);
    bool insertAfterLastOccurrence(int v, int nV);
    bool deleteFromFirst();
    bool deleteFromLast();
    bool deleteFirstOccurrence(int v);
    bool deleteLastOccurrence(int v);
    int length();
    void bubbleSort();
    void cutPaste(int k);
    void swap(int k1, int k2);
    void shuffle();
    Node* findMiddleElement();
    void print();
};

void LL::createFirstElement(int v){
    head=(Node*)malloc(sizeof(Node));
    head->key=v;
    head->L=NULL;
    head->R=NULL;
    tail=head;
}
Node* LL::findFirstOccurrence(int v){
    Node *temp=head;
    while(temp!=NULL){
            if(temp->key==v)break;
            temp=temp->R;
    }
  return temp;
}
Node* LL::findLastOccurence(int v){}
//link list e kothin ,array te soja,disadvantage of linked list
Node* LL::findKthNode(int k){
    Node *temp=head;
    for(int i=1;i<=k;i++)
    {
        temp=temp->R;
    }
    return temp;
}

void LL::insertAtFirst(int v){
    if(head==NULL)
    {
        createFirstElement(v);
        return ;
    }
    Node*temp=(Node*)malloc(sizeof(Node));
    temp->key=v;
    head->L=temp;
    temp->R=head;
    head=temp;
    head->L=NULL;
}
void LL::insertAtLast(int v){
    if(head==NULL)
    {
        createFirstElement(v);
        return ;
    }
    Node*temp=(Node*)malloc(sizeof(Node));
    temp->key=v;
    temp->L=tail;
    tail->R=temp;
    tail=temp;
    tail->R=NULL;
}
bool LL::insertAfterFirstOccurrence(int v, int nV){
        Node*temp=findFirstOccurrence(v);
        if(temp==NULL)return false;
        if(temp==tail)
        {
            insertAtLast(nV);
            return true;
        }
        Node*newNode=(Node*)malloc(sizeof(Node));
        newNode->L=temp;
        temp->R->L=newNode;
        newNode->R=temp->R;
        temp->R=newNode;
        newNode->key=nV;
        return true;
}
bool LL::insertAfterLastOccurrence(int v, int nV){



}
bool LL::deleteFromFirst(){
    if(head==NULL)return false;
    if(head==tail)
    {
        free(head);
        head=NULL;
        return true;
    }
    head=head->R;
    free(head->L);
    head->L=NULL;
    return true;
}
bool LL::deleteFromLast(){}
bool LL::deleteFirstOccurrence(int v){}
bool LL::deleteLastOccurrence(int v){}
int LL::length(){
    Node *temp=head;
    int len=0;
    //int len=0;
    //for(Node *temp=head;temp!=NULL;temp=temp->R,len++){}return len;
    while(temp!=NULL)
    {
        temp=temp->R;
        len++;
    }
    return len;
}
void LL::bubbleSort(){}
//////////////popular interview question,time complexity o(n),but o(1) e kora possible
void LL::cutPaste(int k){
    Node *first=head;
    Node *last=findKthNode(k-1);
    head=last->R;
    head->L=NULL;
    last->R=NULL;
    tail->R=first;
    first->L=tail;
    tail=last;
}
void LL::swap(int k1, int k2){}
void LL::shuffle(){}
Node* LL::findMiddleElement(){}
void LL::print(){
    for(Node *temp=head;temp!=NULL;temp=temp->R){
        cout<<temp->key<<" ";
    }
}


int main(){
    cout<<"1. Insert At First."<<endl<<"2. Insert at last."<<endl<<"3. Insert after first occurrence."<<endl<<"4. Insert after last occurrence."<<endl;
    cout<<"5. Delete from first."<<endl<<"6. Delete from last."<<endl<<"7. Delete first occurrence."<<endl<<"8: Delete last occurrence."<<endl;
    cout<<"9. Length."<<endl<<"10.Sort."<<endl<<"11.Cut Paste"<<"12.Swap"<<endl<<"13.Shuffle"<<endl;
    cout<<"14.Middle element"<<endl<<"15.Print"<<endl<<"16.Exit"<<endl<<endl;

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
            cout<<"Length of the list is: "<<l.length()<<endl;
        }
        else if(choice==10){
            l.bubbleSort();
            cout<<"List sorted."<<endl;
        }
        else if(choice==11){
            cout<<"Enter the value of k: ";
            int k;
            cin>>k;
            l.cutPaste(k%l.length() + 1);
        }
        else if(choice==12){
            int a,b;
            cout<<"Enter the value of a: ";
            cin>>a;
            cout<<"Enter the value of b: ";
            cin>>b;
            l.swap(a%l.length(), b%l.length());
        }
        else if(choice==13){
            l.shuffle();
            cout<<"List shuffled"<<endl;
        }
        else if(choice==14){
            cout<<"Middle element of the list is: "<<l.findMiddleElement()->key<<endl;
        }
        else if(choice==15){
            cout<<"The list is: ";
            l.print();
            cout<<endl;
        }
        else if(choice==16){
            break;
        }
        else{
            cout<<"Invalid choice."<<endl;
        }

        cout<<endl<<endl;
    }
}
