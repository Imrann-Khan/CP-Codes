#include<bits/stdc++.h>

using namespace std;

class Stack{
    int top;
    int capacity;
    int *arr;
public:
    Stack(int n){
        top=-1;
        capacity=n;
        arr=(int*)malloc(sizeof(int));
    }
    bool isStackFull(){
        if(top==capacity-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isStackEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int value){
        if(isStackFull()){
            cout<<"Stack is full (overflow)!"<<endl;
        }
        else{
            top++;
            arr[top]=value;
            cout<<value<<" is pushed into the Stack"<<endl;
        }
    }

    void pop(){
        if(isStackEmpty()){
            cout<<"Stack is empty (underflow)!"<<endl;
        }
        else{
            int tmp=arr[top];
            top--;
            cout<<"Popped value is "<<tmp<<endl;
        }
    }

    void sizeofStack(){
        int count=0;
        for(int i=top;i>=0;i--){
            count++;
        }
        cout<<"Number of elements: "<<count<<endl;
    }



    void printStack(){
        if(isStackEmpty()){
            cout<<"Empty stack can't be printed!"<<endl;
        }
        else{
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<endl;
            }
        }
    }
};



int main(){

    int choice, n, value,xx=1,yy=-1;
    bool x=true;
    Stack stk(5);
    while(x){

        cout<<endl;
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - Count Number of Items."<<endl;
        cout<<"4 - Display Items (Print STACK)."<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice){
            case 0:
                x=false;
                break;

            case 1:
                cout<<"Enter Value:";
                cin>>value;
                stk.push(value);
                break;

            case 2:
                stk.pop();
                break;

            case 3:
                stk.sizeofStack();
                break;
            case 4:
                stk.printStack();
                break;

            default:
                cout<<"An Invalid choice."<<endl;
        }
    }

    return 0;


}

