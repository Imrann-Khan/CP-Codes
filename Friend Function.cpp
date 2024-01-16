#include<bits\stdc++.h>
using namespace std;


class A
{
    int i;
    double d;
    char c;
public:

int sum(A s2)
{
    return i+s2.i;
}
public:
    A(int x)
    {
        i=x;
    }
};

int main()

{

    A ob1(15),ob2(30);
    int sum=ob1.sum(ob2);
    cout << sum;

    return 0;
}
