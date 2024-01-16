#include<bits/stdc++.h>
using namespace std;

class gf
{
    int r;
    public:
     gf(int r)
     {
        this->r=r;
        cout<<"gf constructor"<<endl;
     }
     ~gf()
     {
        cout<<"gf destructor"<<endl;
     }
};
class df
{
    int a;
    public:
    df(int a)
    {
        cout<<"df constructor"<<endl;
    }
    ~df()
    {
        cout<<"df desturctor"<<endl;
    }
};
class ff: public gf, public df
{
    int g;
    public:
    ff(int g,int a,int r) : df(a),gf(r)
    {
        cout<<"ff constructor"<<endl;
    }
    ~ff()
    {
        cout<<"ff destructor"<<endl;
    }
};
int main()
{
    ff f(3,1,2);
    return 0;
}