#include<bits/stdc++.h>
using namespace std;

class Queue
{
    int rear;
    int front;
    int size;
    int *arr;
    public:
    Queue(int n)
    {
        rear=-1;
        front=-1;
        size=n;
        arr=new int[n];
    }
    void push(int value)
    {
        if((rear+1)%size==front) 
        {
            cout<<"Queue is Full."<<endl;
            return;
        }
        if(front==-1) front=0;
        rear++;
        arr[rear]=value;
    }
    int pop()
    {
        if(rear==-1 && front==-1)
        {
            cout<<"Queue is Empty."<<endl;
            return -1;
        }
        int s=arr[front];
        if(front==rear) rear=front=-1;
        else front=(front+1)%size;
        return s;
    }
    void printStack()
    {
       if (front == -1)
        {
            printf("\nQueue is Empty");
            return;
        }
        printf("\nElements in Circular Queue are: ");
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            printf("%d ",arr[i]);
        }
        else
        {
            for (int i = front; i < size; i++)
            printf("%d ", arr[i]);
 
            for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
        }
    }
    int peek()
    {
        return arr[rear];
    }
};
int main()
{
    Queue q(5);
    q.printStack();
    return 0;
}