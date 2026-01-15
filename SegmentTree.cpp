#include <bits/stdc++.h>
using namespace std;


int seg[10000];
int arr[6];

int constructTree(int st, int ed, int si)
{
    if(st==ed)
    {
        seg[si]=arr[st];
        return arr[st];
    }
    int mid = (st+ed)/2;
    seg[si]=constructTree(st,mid,2*si+1)+constructTree(mid+1,ed,2*si+2);
    return seg[si];
}

int getSum(int st, int ed, int qs, int qe, int si)
{
    if(qe<st or qs>ed) return 0;
    if(qs<=st and qe>=ed) return seg[si];

    int mid = (st+ed)/2;
    seg[si] = getSum(st,mid, qs,qe, 2*si+1)+getSum(mid+1,ed, qs,qe, 2*si+2);
    return seg[si];
}

void Update(int st, int ed, int i, int si, int diff)
{
    if(i < st || i > ed)
        return; 

    seg[si] += diff;

    if(st < ed)
    {
        int mid = (st + ed) / 2;
        Update(st, mid, i, 2*si+1, diff);
        Update(mid+1, ed, i, 2*si+2, diff);
    }
}

void UpdateRange(int i, int val)
{
    int diff = val - arr[i];
    arr[i] = val;
    Update(0, 5, i, 0, diff);
}


signed main()
{
    int val=10;
    for(int i=0;i<6;i++)
    {
        arr[i]=val;
        val+=10;
    }
    constructTree(0,5,0);
    // for(int i=0;i<24;i++)
    // {
    //     cout<<seg[i]<<" ";
    // }
    // cout<<endl;
    cout<<getSum(0,5,1,4,0)<<endl;
    UpdateRange(2,70);
    cout<<getSum(0,5,1,4,0)<<endl;
    for(int i=0;i<24;i++)
    {
        cout<<seg[i]<<" ";
    }
    cout<<endl;
}
