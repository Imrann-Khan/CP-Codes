#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

signed main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        if(n%2==1) cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            string sc1="AA";
            string sc2="BB";
            bool f=false;
            for(ll i=0;i<n/2;i++)
            {
                if(!f)
                {
                    cout<<sc1;
                    f=true;
                }
                else 
                {
                    cout<<sc2;
                    f=false;
                }
            }
            cout<<endl;
        }
    }
}