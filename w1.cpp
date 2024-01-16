#include<bits/stdc++.h>
using namespace std;
class student
{
    int j;
    float z;
};
/*
int subtract(int a,int b)
{
    int r=a-b;
    cout << "Type of a: " << typeid(a).name() << ",value of a: " << a << endl;
    cout << "Type of b: " << typeid(b).name() << ",value of b: " << b << endl;
    cout << "Type of r: " << typeid(r).name() << ",value of r: " << r << endl;
    return r;
}

float subtract(float a,float b)
{
    float r=a-b;
    cout << "Type of a: " << typeid(a).name() << ",value of a: " << a << endl;
    cout << "Type of b: " << typeid(b).name() << ",value of b: " << b << endl;
    cout << "Type of r: " << typeid(r).name() << ",value of r: " << r << endl;
    return r;
}
*/

template <typename q,typename p,typename pq>
p subtract(q a,p b)
{
    p r=a-b;
    cout << "Type of a: " << typeid(a).name() << ",value of a: " << a << endl;
    cout << "Type of b: " << typeid(b).name() << ",value of b: " << b << endl;
    cout << "Type of r: " << typeid(r).name() << ",value of r: " << r << endl;
    return r;
}

template <typename m,typename n,typename o>
o Add(m a,n b)
{
    o add=a+b;
    cout << "Type of a: " << typeid(a).name() << ",value of a: " << a << endl;
    cout << "Type of b: " << typeid(b).name() << ",value of b: " << b << endl;
    cout << "Type of add: " << typeid(add).name() << ",value of add: " << add << endl;
    return add;
}
int main()
{
    ///subtract(255555555555555,1999999999999);
    ///subtract<int,float,double>(225, 1.256);
    Add<int,int,int>(3,4);
    int i;
    float f;
    double d;
    long long int l;
    unsigned int u;
    char c;

    cout
    << typeid(i).name()
    << typeid(f).name()
    << typeid(d).name()
    << typeid(l).name()
    << typeid(u).name()
    << typeid(c).name();

}
