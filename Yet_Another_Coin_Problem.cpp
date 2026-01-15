#include<bits/stdc++.h>
#define ll long long int
using namespace std;


ll Count(ll n)
{
    if(n==0) return 0;
    vector<ll> v;
    ll a=0,b=0,c=0,d=0,e=0;
    if(n>=15)  a=n/15 + Count(n%15);
    if(n>=10)  b=n/10 + Count(n%10);
    if(n>=6)  c=n/6 + Count(n%6);
    if(n>=3)  d=n/3 + Count(n%3);
    if(n>=1)  e=n;
    if(a>0) v.push_back(a);
    if(b>0) v.push_back(b);
    if(c>0) v.push_back(c);
    if(d>0) v.push_back(d);
    if(e>0) v.push_back(e);
    sort(v.begin(),v.end());
    if(v.size()>0) return v.front();
    else return 0;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        ll cnt=0;
        if(n>20 and n!=21) cnt =2+ Count(n-20);
        else  cnt = Count(n);
        cout<<cnt<<endl;
    }
}