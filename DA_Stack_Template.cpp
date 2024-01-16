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
        if(top==capacity) return true;
    }

    bool isStackEmpty(){
        if(top==-1) return true;
    }

    void push(int value){
        if(isStackFull()) cout<<"Stack overflow"<<endl;
        else if(top==-1)
        {
            top++;
            arr[top]=value;
        }
        else
        {
            top++;
            arr=(int*)realloc((top)*sizeof(int));
            arr[top]=value;
        }
    }

    void pop(){
        int s=arr[top];
        free(arr[top]);
        top--;
    }

    void sizeofStack(){
        int l=0;
        for(int i=0;i<arr.size();i++)
        {l++;}
        return l;
    }

    void printStack(){
        for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i]<<"  ";
        }
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
