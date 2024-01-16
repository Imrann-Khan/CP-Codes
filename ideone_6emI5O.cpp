//push_costly
#include<bits/stdc++.h>
using namespace std;

class Queue_push_costly
{
    stack<int>s1,s2;
    int len;

    public:
        Queue_push_costly()
        {
            this->len=0;
        }

        void push(int x)
        {
            while(!s1.empty()) s2.push(s1.top()), s1.pop();
            s1.push(x);
            while(!s2.empty()) s1.push(s2.top()), s2.pop();
            ++len;
        }

        void pop()
        {
            if(!s1.empty()) s1.pop(), --len;
        }

        bool empty()
        {
            return s1.empty();
        }

        int front()
        {
            return s1.top();
        }

        int back()
        {
            while(!s1.empty()) s2.push(s1.top()), s1.pop();
            int x=s2.top();
            while(!s2.empty()) s1.push(s2.top()), s2.pop();
            return x;
        }

        int size()
        {
            return len;
        }

        void print()
        {
            cout<<"Front-> ";
            while(!s1.empty()) cout<<s1.top()<<" ", s1.pop();
            cout<<"<-Back"<<endl;
        }
};
int main()
{
    Queue_push_costly s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(5);
    s1.print();
    return 0;
}
