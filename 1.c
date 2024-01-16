#include<bits/stdc++.h>
using namespace std;

int k;
class Circular_Queue{
    int front;
    int rear;
    int capacity;
    int *queue;//*a
    int count;
public:
    Circular_Queue (int c){
        front=0;
        rear=0;
        capacity=c;
        count=0;
        queue=&k;
    }

    bool overflow(){
        //check whether the queue is full or not
        if(count==capacity) return true;
        else return false;
    }

    bool underflow(){
        //check whether the queue is empty or not
        if(count==0) return true;
        else return false;
    }

    void enqueue(int value){
        //enqueue an item at the rear of the queue
        if(overflow()) cout<<"Queue is already full\n";
        else{
            *(queue+rear)=value;
            count++;
            rear=(rear+1)%(capacity);
        }
    }

    void dequeue(){
        //dequeue an item from the front of the queue
        if(underflow()) cout<<"Queue is already empty\n";
        else{
            cout<<*(queue+front)<<" is deleted\n";
            front=(front+1)%(capacity);
            count--;
        }
    }

    int Front(){
        //must return the item which is situated at front
        return *(queue+front);
    }

    void display(){
        //Items should be displayed in the order of First In First Out
        //Maintain the display in circular manner
        if(front>=rear){
            for(int i=front;i<capacity ;i++){
                cout<<*(queue+i)<<" ";
            }
            for(int i=0;i<rear;i++){
                cout<<*(queue+i)<<" ";
            }
        }
        else{
            for(int i=front;i<rear;i++){
                cout<<*(queue+i)<<" ";
            }
        }
        cout<<"\n";
    }

};

int main(){


        Circular_Queue cq(5);
        int choice;

        cout<<"0 - Exit."<<endl;
        cout<<"1 - Enqueue Item."<<endl;
        cout<<"2 - Dequeue Item."<<endl;
        cout<<"3 - View Front Item."<<endl;
        cout<<"4 - Display Items (Print Queue)."<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;
        while(choice!=0){
            if(choice==1){
                cout<<"Enter value to insert: ";
                int x;
                cin>>x;
                cq.enqueue(x);
            }
            else if(choice==2){
                cq.dequeue();
            }
            else if(choice==3){
                cout<<"Front element: "<<cq.Front()<<"\n";
            }
            else{
                cq.display();
            }
            cout<<"Enter your choice: ";
            cin>>choice;
        }
        return 0;
}
