#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

using namespace std;

int main() {
    fast
    ll t; cin>>t;
    while(t--)
    {
        ll a,b,m,cnt=0;
        cin>>a>>b>>m;
        cnt= m/a+m/b;
        cout<<cnt+2<<endl;
    }
}
