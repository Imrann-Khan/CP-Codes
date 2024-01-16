#include<bits/stdc++.h>
using namespace std;

int wt[]={2,3,4,5};
int price[]={3,4,5,6};
int mxwt=5;
int k[6][5]={};


int knapsack(int w,int i)
{
    if(w==0 || i==0) return 0;
    if(w<wt[i]) return knapsack(w,i-1);
    return max(knapsack(w,i-1),knapsack(w-wt[i],i-1)+price[i]);
}

int main()
{
    
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<knapsack(i,j)<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
