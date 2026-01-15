#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main()
{
    ll tc; cin>>tc;
    while(tc--)
    {
        ll n,k;
        cin>>n>>k;
        ll pos[n],health[n];
        vector<ll> v(n+1);
        for(ll i=0;i<n;i++) cin>>health[i];
        ll max=0;
        for(ll i=0;i<n;i++) 
        {
            cin>>pos[i];
            if(pos[i]<0) pos[i]*=(-1);
            v[pos[i]]+=health[i];
            if(pos[i]>=max) max=pos[i];
        }
        //for(ll i=1;i<max+1;i++) cout<<i<<" "<<v[i]<<endl;
        ll lft=0;
        bool f=false;
        for(ll i=1;i<max+1;i++)
        {
            //cout<<v[i]<<endl;
            if(v[i]<=(lft+k))
            {
                lft=(lft+k)-v[i];
            }
            else
            {
                f=true;
                break;
            }
        }
        if(f) cout<<"NO\n";
        else cout<<"YES\n";
        //v.clear();
    }
}