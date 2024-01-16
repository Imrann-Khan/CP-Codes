#include<bits/stdc++.h>
using namespace std;

class complx;
class calculator
{
public:
    void add(complx , complx );
    void sub(complx , complx );
    void multiply(complx , complx );
    friend void abs(complx );
};
class complx
{
    float real;
    float imag;
public:
    cons(float real, float imag)
    {
        this->real=real;
        this->imag=imag;
    }
    friend calculator;
    friend void calculator::add(complx, complx);
    friend void calculator::sub(complx, complx);
    friend void calculator::multiply(complx, complx);
    friend void abs(complx a);
};
void calculator::add(complx a, complx b)
    {
        float x=a.real+b.real;
        float y=a.imag+b.imag;
        cout<<"Sum: "<<x<<"+"<<y<<"i"<<endl;
    }
void calculator::sub(complx a, complx b)
    {
        float x=a.real-b.real;
        float y=a.imag-b.imag;
        cout<<"Substraction: "<<x;
        if(y<0)
        {
            cout<<y<<"i"<<endl;
        }
        else
        {
            cout<<"+"<<y<<"i"<<endl;
        }
    }
void calculator::multiply(complx a, complx b)
    {
        float x=(a.real*b.real-a.imag*b.imag);
        float y=(a.real*b.imag+a.imag*b.real);
        cout<<"Multiplication: "<<x;
        if(y<0)
        {
            cout<<y<<"i"<<endl;
        }
        else
        {
            cout<<"+"<<y<<"i"<<endl;
        }
    }
void abs(complx a)
{
    cout<<"Absolute value: "<<sqrt((a.real*a.real+a.imag*a.imag))<<endl;
}
int main()
{
    complx a,b;
    calculator s;
    float x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    a.cons(x1,y1);
    b.cons(x2,y2);
    abs(a);
    abs(b);
    s.add(a,b);
    s.sub(a,b);
    s.multiply(a,b);
}
