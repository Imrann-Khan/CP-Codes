#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,cnt=0;
    int a[50];
    cin>>n;
    cin>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=a[k]&&a[i]>0)
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}