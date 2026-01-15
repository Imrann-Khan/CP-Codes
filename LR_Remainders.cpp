#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;


int main()
{
    fast
    ll t; cin>>t;
    while (t--)
    {
        ll n,m;
        string s;
        cin>>n>>m;
        ll arr[n];
        for(ll i=0;i<n;i++) cin>>arr[i];
        cin>>s;
        ll r=0,k=n-1;
        stack<ll> b;
        for(ll i=0;i<s.size();i++)
        {
            if(s[i]=='L')
            {
                b.push(arr[r]);
                r++;
            }
            else
            {
                b.push(arr[k]);
                k--;
            }
        }
        ll pos;
        stack<ll> st;
        ll x=1;
        for(ll i=0;i<n;i++)
        {
            x*=b.top();
            x=x%m;
            st.push((x)%m);
            b.pop();
        }
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
    }
}