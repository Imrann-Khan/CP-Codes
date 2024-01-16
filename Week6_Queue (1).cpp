#include <iostream>
using namespace std;


class Queue{
    int front;
    int rear;
    int capacity;
    int *queue;
    int count;
public:
    Queue (int c){
        front=-1;
        rear=-1;
        capacity=c; 
        count=0;
        queue=(int*)malloc(sizeof(int));
    }

    bool overflow(){
        if(count==capacity) return true;
    }

    bool underflow(){
        if(count==0) return true;
    }

    void enqueue(int value){
        if(overflow()==true) cout<<"Stack overflow"<<endl;
        else if(front==-1&&rear==-1)
        {
            front++; rear++;
            queue[front]=value;
            queue[rear]=value;
            count++;
        }
        else
        {
            rear++;
            queue=(int*)realloc(queue,rear*sizeof(int));
            queue[rear]=value;
        }
    }

    int dequeue(){
        int s=queue[front];
        front++;
        count--;
        return s;
    }

    void display(){
        for(int i=front;i<=rear;i++)
        {
            cout<<queue[i]<<"  ";
        }
    }

};

int main(){
    int choice, n, value;
    cout<<"Enter the size of Queue: ";
    cin>>n;
    Queue que(n);
    while(1){
    cout<<endl;
    cout<<"0 - Exit."<<endl;
    cout<<"1 - Push Item."<<endl;
    cout<<"2 - Pop Item."<<endl;
    cout<<"3 - Display Items (Print STACK)."<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice){
            case 0:
                break;

            case 1:
                cout<<"Enter Value:";
                cin>>value;
                que.enqueue(value);
                break;

            case 2:
                que.dequeue();
                break;

            case 3:
                que.display();
                break;

            default:
                cout<<"An Invalid choice."<<endl;
        }
    }

    return 0;
}

