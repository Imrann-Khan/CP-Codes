#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool prime[100000001];
void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
    prime[0]=prime[1]=false;
    for (int p = 2; p * p <= 100000000; p++) {
        
        if (prime[p] == true) {
            for (int i = p * p; i <= 100000000; i += p)
                prime[i] = false;
        }
    }
}

int main()
{
    ll tc; cin>>tc;
    SieveOfEratosthenes();
    while(tc--)
    {
        ll n; cin>>n;
        set<ll> s;
        for(ll i=0;i<n;i++)
        {
            ll x; cin>>x;
            if(prime[x]==true) s.insert(x);
        }
        for(auto i=s.begin();i!= s.end();i++)
            cout<<*i<<" ";
        if(s.size()>1) cout<<"YES\n";
        else cout<<"NO\n";
    }
}