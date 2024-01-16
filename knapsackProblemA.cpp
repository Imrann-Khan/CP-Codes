#include<bits/stdc++.h>
using namespace std;

int c[1000];
int knapsack(int w,int i)
{
    if(w==0 || i==0) return 0;
    return max(knapsack(w,i-1),knapsack(w-1,i-1)+c[i-1]);
}

int main()
{
    int w,n;
    cin>>w>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    cout<<knapsack(w,n);
    return 0;
}