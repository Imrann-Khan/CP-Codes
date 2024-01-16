#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int st,end;
    cin>>st>>end;
    int a[100];
    int i=0;
    a[0]=st;
    while(a[i]<=end)
    {
        cout<<a[i]<<" ";
        i++;
        a[i]++;
    }

}