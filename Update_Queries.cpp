#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;


void solve()
{
    ll n,m;
    cin>>n>>m;
    string s; cin>>s;
    vector<ll> ind(m);
    vector<ll> fr(n+1,false);
    for(ll i=0;i<m;i++)
    {
        cin>>ind[i];
    }
    string c; cin>>c;
    sort(c.begin(),c.end());
    sort(ind.begin(),ind.end());
    ll i=0,j=m-1;
    for(ll k=0;k<m;k++)
    {
        if(j<i) break;
        if(fr[ind[k]]==false)
        {
            //cout<<c[i]<<" ";
            //cout<<k<<" ";
            s[ind[k]-1]=c[i++];
            fr[ind[k]]=true;
        }
        else j--;
        //cout<<s[ind[k]-1]<<" ";
    }
    cout<<s<<endl;
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