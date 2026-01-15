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
        ll cnt=1;
        while(n>1)
        {
            cnt+=n;
            n/=2;
        }
        cout<<cnt<<endl;
    }
}