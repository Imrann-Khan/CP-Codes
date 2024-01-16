#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    if(m<=16&&n<=16)
    {
        int p=ceil((m*n)/2);
        cout<<p;
    }
    return 0;
}