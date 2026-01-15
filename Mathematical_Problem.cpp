#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;


void solve()
{
    ll n;
    cin>>n;
    string s; cin>>s;
    ll zero=0;
    vector<pair<ll,ll>> v;
    for(ll i=0;i<n;i++) if(s[i]=='0') zero++;
    if(n<3)
    {
        for(ll i=1;i<n;i++)
        {
            ll y=(ll)s[i-1]-'0';
            y*=10;
            y+=(ll)s[i]-'0';
            cout<<y<<endl;
            return;
        }
    }
    // if(zero<n-2 and zero!=0)
    // {
    //     cout<<0<<endl;
    //     return;
    // }
    ll z=n-2;
    bool x=1;
    if(s[n-1]==1)
    {
        if(s[n-2]==1)
        {
            x=0;
        }
    }
    vector<ll> f;
    f.push_back((ll)s[0]-'0');
    if(!x and z!=1)
    {
        for(ll i=1;i<n-1;i++)
        {
            f.push_back((ll)s[i]-'0');
            ll y=(ll)s[i-1]-'0';
            y*=10;
            y+=(ll)s[i]-'0';
            v.push_back({y,i});
        }
    }
    else
    {
        for(ll i=1;i<n;i++)
        {
            f.push_back((ll)s[i]-'0');
            ll y=(ll)s[i-1]-'0';
            y*=10;
            y+=(ll)s[i]-'0';
            v.push_back({y,i});
        }
    }
    sort(v.begin(),v.end());
    //for(auto i:v) cout<<i.first<<" "<<i.second<<" ";
    ll mn=INT_MAX;
    for(auto i:v)
    {
        ll p=i.second;
        ll q=p-1;
        ll sum=i.first;
        if(sum==0)
        {
            cout<<0<<endl;
            return;
        }
        for(auto j=0;j<n;j++)
        {
            if(j==p or j==q) continue;
            if(f[j]==0)
            {
                cout<<0<<endl;
                return;
            }
            if(f[j]!=1)
            {
                if(sum==1) sum=f[j];
                else sum+=f[j];
            }
        }
        if(mn>sum) mn=sum;
    }
    cout<<mn<<endl;
}


signed main()
{
    fast
    ll t;cin>>t;
    while(t--)
    {
        solve();
    }
}