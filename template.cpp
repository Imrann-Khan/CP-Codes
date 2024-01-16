#include<bits/stdc++.h>
using namespace std;

/*int subtract(int a,int b)
{
    int d=a-b;
    cout<<"Type of q: "<<typeid(a).name()
    <<", Value of a: "<<a<<endl;
    cout<<"Type of b: "<<typeid(b).name()
    <<", Value of b: "<<b<<endl;\
    cout<<"Type of d: "<<typeid(d).name()
    <<", Value of d: "<<d<<endl;
}
double subtract(double a,double b)
{
    double d=a-b;
    cout<<"Type of q: "<<typeid(a).name()
    <<", Value of a: "<<a<<endl;
    cout<<"Type of b: "<<typeid(b).name()
    <<", Value of b: "<<b<<endl;\
    cout<<"Type of d: "<<typeid(d).name()
    <<", Value of d: "<<d<<endl;
}*/
/*template <typename q, typename p, typename pq>
q subtract(q a,p b)
{
    pq r=a-b;
    cout<<"Type of q: "<<typeid(a).name()
    <<", Value of a: "<<a<<endl;
    cout<<"Type of b: "<<typeid(b).name()
    <<", Value of b: "<<b<<endl;
    cout<<"Type of d: "<<typeid(r).name()
    <<", Value of r: "<<r<<endl;
}*/
/*template <typename p, typename q>p add(p a, q b){
                p s=a+b;
                cout<<"Type of a: "<<typeid(a).name()
                <<", Value of a: "<<a<<endl;
                cout<<"Type of b: "<<typeid(b).name()
                <<", Value of b: "<<b<<endl;
                cout<<"Type of s: "<<typeid(s).name()
                <<", Value of s: "<<s<<endl;
                return s;
}*/
template <typename id1, typename  id2>
class subtraction
{
    id1 a,b;
public:
    subtraction(id1 a,id2 b)
    {
        this->a=a;
        this->b=b;
    }
    id1 calc(){
        return (a-b);
    }
    template <typename idx>idx calc2(){
        return (a-b)*(a-b);
    }
};
int main()
{
    double a,b;
    cin>>a>>b;
    subtraction <int,float>s(a,b);
    //cout<<s.calc()<<endl;
    cout<<s.calc2<double>()<<endl;
}
