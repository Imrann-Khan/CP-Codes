#include<bits/stdc++.h>
using namespace std;

template<typename P,typename Q>
class operation
{
    P a;
    Q b;
public:
    operation(P a,Q b)
    {
        this->a=a;
        this->b=b;
    }
    P addition()
    {
        return a+b;
    }
    P subs()
    {
        return a-b;
    }
    template<typename R> R multiplication()
    {
        return a*b;
    }
    template<typename R> R division()
    {
        return a/b;
    }
};
int main()
{
    operation <double,double>o(32,6.7);
    cout<<o.addition()<<endl;
    cout<<o.subs()<<endl;
    cout<<o.multiplication<char>()<<endl;
    cout<<o.division<char>()<<endl;
    return 0;
}