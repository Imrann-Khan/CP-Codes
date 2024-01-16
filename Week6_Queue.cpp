#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int front;
    int rear;
    int capacity;
    int *queue;
    int count;
public:
    Queue (int c)
    {
        front=0;
        rear=0;
        capacity= c;
        queue= (int *)malloc(sizeof(int));
    }

    bool overflow()
    {
        if(rear ==capacity)
            return 1;
        else
            return 0;
    }

    bool underflow()
    {
        if(rear ==front)
            return 1;
        else
            return 0;
    }

    void enqueue(int value)
    {
        if(overflow()==1)
            cout<<"Que is full"<<endl;
        else
        {
            queue[rear]=value;
            rear++;
        }
    }

    int dequeue()
    {
        if(underflow()==1)
            cout<<"que is empty"<<endl;
        else
        {
            int x = queue[front];
            front++;
            return x;
            ///return queue[front++];
        }
    }

    void display()
    {
        if(underflow()==1)
        {
            cout<<"que is empty"<<endl;
        }
        else
        {
            for(int i= front; i<rear; i++)
            {
                cout<<queue[i]<<"-->";
            }
            cout<<endl;
        }
    }

};

int main()
{
    Queue que(4);
    que.display();

    que.enqueue(11);
    que.enqueue(22);
    que.enqueue(33);
    que.enqueue(44);
    que.display();
    que.enqueue(44);
    ///que.dequeue();
    que.display();
    que.dequeue();
    que.display();
}

