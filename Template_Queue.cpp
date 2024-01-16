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
        front=-1; rear=-1;
        capacity=c;
        count=0;
        queue=(int*)malloc(c*sizeof(int));
    }

    bool overflow(){
        //check whether the queue is full or not
        if (front==(rear+1)%capacity) return true;
    }

    bool underflow(){
        //check whether the queue is empty or not
         if ((front==-1&&rear==-1)) return true;
    }

    void enqueue(int value){
        //enqueue an item at the rear of the queue
        rear=(rear+1)%capacity;
        if(overflow()==true) cout<<"Circular Queue is Full!"<<endl;
        else if(underflow()==true)
        {
            queue[rear]=value;
        }
        else
        {
            queue[rear]=value;
        }
    }

    void dequeue(){
        //dequeue an item from the front of the queue
        front=(front+1)%capacity;
        if(underflow()==true) cout<<"Circular Queue is Empty!"<<endl;
        else if(overflow()==true)
        {
            rear--;
            int s=queue[front];
        }
    }

    int Front(){
        //must return the item which is situated at front
        return queue[front];
    }

    void display(){
        //Items should be displayed in the order of First In First Out
        //Maintain the display in circular manner
        if(rear>front)
        {
            for(int i=front;i<=rear;i++)
            {
                cout<<queue[i]<<"  ";
            }
        }
        else if(front>rear)
            {
                for(int i=rear;i>=0;i--)
                {
                    cout<<queue[i]<<"  ";
                }
                for(int i=front;i<capacity;i++)
                {
                    cout<<queue[i]<<"  ";
                }
            }
        else if(rear=front&&rear!=0)
        {
            for(int i=rear;i>=0;i--)
                {
                    cout<<queue[i]<<"  ";
                }
                for(int i=front;i<capacity;i++)
                {
                    cout<<queue[i]<<"  ";
                }
        }
        else
        {
            cout<<"Circular Queue is Empty!"<<endl;
        }
    }
};

int main(){


        Circular_Queue cq(5);
        int choice;
        while(1)
        {
            cout<<"0 - Exit."<<endl;
            cout<<"1 - Enqueue Item."<<endl;
            cout<<"2 - Dequeue Item."<<endl;
            cout<<"3 - View Front Item."<<endl;
            cout<<"4 - Display Items (Print Queue)."<<endl;

            cout<<"Enter your choice: ";
            cin>>choice;
            switch(choice)
            {
                case 0:
                    break;
                case 1:
                    int s;
                    cout<<"Enter the element: ";
                    cin>>s;
                    cq.enqueue(s);
                    break;
                case 2:
                    cq.dequeue();
                    break;
                case 3:
                    cq.Front();
                    break;
                case 4:
                    cq.display();
                    break;
            }
        }
        return 0;
}
