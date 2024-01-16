// Fibonacci Series using Optimized Method
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n; cin>>n;
    ll res=0;
    ll m=n/3;
    ll c=n%3;
    res+=m*(m+1);
    while(c<n)
    {
        res+=c;
        c+=3;
    }
    cout<<res<<endl;
    return 0;
}