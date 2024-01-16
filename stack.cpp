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
        arr=new int[n];
    }
    bool isStackFull(){
        if(top==capacity-1) return true;
        else false;
    }

    bool isStackEmpty(){
        if(top==-1) return true;
        else false;
    }

    void push(int value){
        if(isStackFull()==true) cout<<"Stack overflow"<<endl;
        else
        {
            top++;
            arr[top]=value;
        }
    }

    int pop(){
        if(isStackEmpty()==true) cout<<"Stack underflow"<<endl;
        else
        {
            int s=arr[top];
            top--;
            return s;
        }
        return -1;
    }

    void sizeofStack(){
        cout<<top<<endl;
    }

    void printStack(){
        if(isStackEmpty()==true) cout<<"No elements in stack."<<endl;
        else 
        {
            for(int i=0;i<=top;i++)
            {
                cout<<arr[i]<<"  ";
            }
        }
    }
    void free()
    {
        delete arr;
    }
};



int main(){

    int choice, n, value;
    bool x=true;
    cout<<"Enter the size of Stack: ";
    cin>>n;
    Stack stk(n);
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
                stk.free();
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
