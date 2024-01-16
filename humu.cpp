#include<bits/stdc++.h>
using namespace std;

template<typename p,typename q>
class P
{
    p a;
    q b;
public:
    P(p a,q b)
    {
        this->a=a;
        this->b=b;
    }
    template<typename r>
    r Add()
    {
        return a+b;
    }
};
int main()
{
    P <float,double>o(7.8f,9.10);
    cout<<o.Add<int>()<<endl;
    cout<<o.Add<double>()<<endl;
    cout<<o.Add<char>()<<endl;
    return 0;
}
