#include <bits/stdc++.h>
using namespace std;


class Queue{
    int front;
    int rear;
    int capacity;
    int *queue;
    int count;
public:
    Queue (int c){
    front=0;
    rear=0;
    capacity=c;
    queue=(int*)malloc(sizeof(int));
    }

    bool overflow(){
    if(rear==capacity)
    {
        return 1;
    }
    else return 0;
    }

    bool underflow(){
        if(front==rear)
            return 1;
        else return 0;

    }

    void enqueue(int value){
    if(overflow()==1)
        cout<<"Queue is full"<<endl;
    else
    {
        queue[rear]=value;
        rear++;
    }
    }

    int dequeue(){
        if(underflow()==0)
            cout<<"Queue is empty"<<endl;
        else
        {
            int x=queue[front];
            front++;
            return x;
        }

    }

    void display(){
    if(underflow()==1)
    {
        cout<<"Queue is empty"<<endl;
    }
    for(int i=front;i<rear;i++)
    {
        cout<<queue[i]<<"-->";
    }
    cout<<endl;
    }

};

int main(){

    Queue q(4);
    q.enqueue(11);
    q.enqueue(33);
    q.enqueue(34);
    q.display();
    q.dequeue();
    q.enqueue(44);
    q.dequeue();
    q.display();





}

