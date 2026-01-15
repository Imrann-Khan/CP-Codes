#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main()
{
    fast
    ll n; cin>>n;
    if(n==1) cout<<1<<endl;
    else if(n==4) cout<<"2 4 1 3\n";
    else if(n==3 || n==2) cout<<"NO SOLUTION\n";
    else 
    {
        for(ll i=1;i<=n;i+=2) cout<<i<<" ";
        for(ll i=2;i<=n;i+=2) cout<<i<<" ";
        cout<<endl;
    }
}