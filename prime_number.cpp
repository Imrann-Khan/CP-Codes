#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n; cin>>n;
    cout<<2<<" "<<3<<" ";
    for(int i=1;i<=n;i++)
    {
        if((6*i-1)%5==0 and (6*i+1)%5==0) continue;
        if((6*i-1)%5==0) cout<<6*i+1<<" ";
        else if((6*i+11)%5==0) cout<<6*i+1<<" ";
        else cout<<6*i-1<<" "<<6*i+1<<" ";
    }
}