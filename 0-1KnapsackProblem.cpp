#include<bits/stdc++.h>
using namespace std;


vector<int> weight;
vector<int> price;
int k[100][100]={};
int knapsack(int w,int i)
{
    if(w==0 || i==0) return 0;
    if(k[w][i]!=-1) return k[w][i];
    if(w<weight[i-1]) return knapsack(w,i-1);
    int m=max(knapsack(w,i-1),knapsack(w-weight[i-1],i-1)+price[i-1]);
    k[w][i]=m;
    return m;
}

int main()
{
    int n,e,mw;
    cout<<"Enter max weight: ";
    cin>>mw;
    cout<<"Number of item: ";
    cin>>n;
    cout<<"Number of elements price: ";
    cin>>e;
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        weight.push_back(p);
    }
    for(int i=0;i<e;i++)
    {
        int q;
        cin>>q;
        price.push_back(q);
    }
    for(int i=0;i<mw+1;i++)
    {
        for(int j=0;j<e+1;j++)
        {
            if(i==0 || j==0) k[i][j]=0;
            else k[i][j]=-1;
        }
    }
    cout<<knapsack(mw,n)<<"\n";
    for(int i=0;i<mw+1;i++)
    {
        for(int j=0;j<e+1;j++)
        {
            k[i][j]=knapsack(i,j);
            cout<<k[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
