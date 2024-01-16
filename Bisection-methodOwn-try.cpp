#include<bits/stdc++.h>
using namespace std;
double a,b,c;
double f(double x)
{
    return a*x*x+b*x+c;
    ///return pow(x,3)-x-11.0;
}
int main()
{
    cout << "Enter a,b,c:";
    cin >> a >> b >> c;
    double p,q;
    cout << "Enter range:";
    cin >> p >> q;

    while(f(p)*f(q)>0)
    {
        cout << "Wrong range. Please Enter new range:";
        cin >> p >> q;
    }
    if(p<q) swap(p,q);
    double eps,r;
    cout << "Enter point of accuracy:";
    cin >> eps;

    while(fabs(p-q)>=eps)
    {
        r=(p+q)/2;
        if(f(r)==0) break;
        if(f(p)*f(r)>0) p=r;
        else if(f(p)*f(r)<0) q=r;

    }
    cout << "Root is: " << r;
    return 0;
}
