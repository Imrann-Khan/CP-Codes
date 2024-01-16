#include <iostream>
using namespace std;


class Circular_Queue{
    int front;
    int rear;
    int capacity;
    int *queue;
    int count;
public:
    Circular_Queue (int c){
        front=-1;
        rear=-1;
        capacity=c;
        count=0;
        queue=new int(c);
    }

    bool overflow(){
        //check whether the queue is full or not
        if((rear+1)%capacity==front) return true;
    }

    bool underflow(){
        //check whether the queue is empty or not
        if(front==-1 && rear==-1)
        {
            return true;
        }
        else false;
    }

    void enqueue(int value){
        //enqueue an item at the rear of the queue
        if(overflow()==true)
        {
            cout<<"Stack is Full!"<<endl;
        }
        else if(front==-1 && rear==-1)   // condition to check queue is empty
        {
        front=0;
        rear=0;
        queue[rear]=value;
        cout<<"Value enqueued succesfully."<<endl;
        }
        else
        {
            rear=(rear+1)%capacity;
            queue[rear]=value;
            cout<<"Value enqueued succesfully."<<endl;
        }
    }

    void dequeue(){
        //dequeue an item from the front of the queue
        if(underflow()==true)
        {
            cout<<"The Queue is Empty!"<<endl;
        }
        else if(front=rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%capacity;
        }
    }

    int Front(){
        //must return the item which is situated at front
        return queue[front];
    }

    void display(){
        //Items should be displayed in the order of First In First Out
        //Maintain the display in circular manner
            if(front==-1 && rear==-1)
            {
                cout<<"Queue is empty"<<endl;
            }
            else
            {
                int i=front;
                while(i<=rear)
                {
                    cout<<queue[i]<<" ";
                    i=(i+1)%capacity;
                }
            cout<<endl;
            }
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

        while(1)
        {
            cin>>choice;
            switch(choice)
            {
                case 0:
                    break;
                case 1:
                    cout<<"Enter the value:";
                    int a;
                    cin>>a;
                    cq.enqueue(a);
                    break;
                case 2:
                    cq.dequeue();
                    break;
                case 3:
                    cout<<cq.Front()<<endl;
                    break;
                case 4:
                    cq.display();
                    break;
            }
        }
    return 0;
}
