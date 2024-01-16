#include<iostream>
using namespace std;
class A
{
public:
    int p;
    A(int c)
    {
        p=c;
        cout<<p<<endl;
    }
    A()
    {
        p=10;
        cout<<p;
    }
};
int main()
{
    A ob1(5);
    A ob2();
}
