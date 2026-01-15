#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main()
{
    fast
    ll tc; cin>>tc;
    while(tc--)
    {
        ll n; cin>>n;
        unordered_set<ll> s;
        for(ll i=0;i<n-1;i++)
        {
            ll x; cin>>x;
            s.insert(x);
        }

        for(ll i=1;i<=n;i++)
        {
            if(s.find(i)==s.end())
            {
                cout<<i<<endl;
                break;
            }
        }
    }
}