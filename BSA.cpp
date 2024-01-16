#include<bits/stdc++.h>
using namespace std;
int save=-1;
int BSA(int l,int h,int x,int a[]) /// Binary Search Algorithm
{
    int m=(l+h)/2;
    if(l>h) return -1;
    if(a[m]>x) return BSA(l,m-1,x,a);
    else if(a[m]<x) return BSA(m+1,h,x,a);
    else return m;
}

int Near_BSA(int l,int h,int x,int a[]) /// Nearest smaller number
{
    int m=(l+h)/2;
    if(l>h) return a[m];
    if(a[m]>x) return Near_BSA(l,m-1,x,a);
    else if(a[m]<x) return Near_BSA(m+1,h,x,a);
    else return m;
}

int FO_BSA(int l,int h,int x,int a[]) /// First Occurrence using Binary Search Algorithm
{
    int m=(l+h)/2;

    if(l>h) return save;
    if(a[m]>x)
        return FO_BSA(l,m-1,x,a);
    else if(a[m]<x)
        return FO_BSA(m+1,h,x,a);
    else
    {
        if(m==0) return 0;
        save=m;
        return FO_BSA(l,m-1,x,a);
    }
}

int LO_BSA(int l,int h,int x,int a[]) /// Last Occurrence using Binary Search Algorithm
{
    int m=(l+h)/2;

    if(l>h) return save;
    if(a[m]>x)
        return LO_BSA(l,m-1,x,a);
    else if(a[m]<x)
        return LO_BSA(m+1,h,x,a);
    else
    {
        if(m==0) return 0;
        save=m;
        return LO_BSA(m+1,h,x,a);
    }
}

int TotalOccurrence(int l,int h,int x,int a[])
{
    return LO_BSA(l,h,x,a)-FO_BSA(l,h,x,a)+1;
}

int Iterative_Linear_Search(int a[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
            return i;
    }
    return -1;
}

int Recursive_Linear_Search(int a[],int n,int x,int i)
{
    if(a[i]==x) return i;
    if(i<n) return Recursive_Linear_Search(a,n,x,i+1);
    else return -1;
}

/*
double SquareRoot(double h,double x,double l=0);
{
    double m=(l+h)/2;
    if(abs(l-h)) return h;
    if() return BSA(l,m-1,x,a);
    else if() return BSA(m+1,h,x,a);
    else return m;
}
*/


int main()
{
    int n,x;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    cin >> x;
    ///cout << LO_BSA(0,n-1,x,a);
    ///cout << N_BSA(0,n-1,x,a);
    ///cout << "Using Recursive Linear Search:" << Recursive_Linear_Search(a,n,x,0);
    cout << TotalOccurrence(0,n-1,x,a);
    return 0;
}
///if x is at left of mid (mid>x), then high=mid-1
///if x is at right of mid (mid<x), then low=mid+1
/// BSA(low,high,mid)
