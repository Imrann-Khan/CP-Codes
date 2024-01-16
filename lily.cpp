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
        front=0;
        rear=0;
        capacity=c;
        count=0;
        queue=new int(c);
    }

    bool overflow(){
        //check whether the queue is full or not
        if(count==capacity) return true;
        else return false;
    }

    bool underflow(){
        //check whether the queue is empty or not
        if(count==0)
        {
            return true;
        }
        else false;
    }

    void enqueue(int value){
        //enqueue an item at the rear of the queue
        if(overflow()==true){
            cout<<"Queue is Full!"<<endl;
        }
        else{
            queue[rear]=value;
            rear=(rear+1)%capacity;
            count++;
            cout<<"Enqueued successfully."<<endl;
        }
    }

    void dequeue(){
        //dequeue an item from the front of the queue
        if(underflow()==true)
        {
            cout<<"The Queue is Empty!"<<endl;
        }
        else{
            front=(front+1)%capacity;
            count--;
            cout<<"Dequeued successfully."<<endl;
        }
    }

    int Front(){
        //must return the item which is situated at front
        return queue[front];
    }

    void display(){
        //Items should be displayed in the order of First In First Out
        //Maintain the display in circular manner
        if(underflow()==true)
            {

                cout<<"The Queue is Empty!"<<endl;
            }

            else
            {
                if(front>=rear){
            for(int i=front;i<capacity ;i++){
                cout<<queue[i]<<" ";
            }
            for(int i=0;i<rear;i++){
                cout<<queue[i]<<" ";
            }
        }
        else{
            for(int i=front;i<rear;i++){
                cout<<queue[i]<<" ";
            }
            }
            cout<<endl;
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

