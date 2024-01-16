#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[],int n, int x, int l, int h)
{
	if(a[0]==x) return 0;
	if(l>h) return -1;
	int mid = (l + h)/2;
	if(a[mid]==x && a[mid-1]!=x)
	return mid;
	if(x <= a[mid] ) return binarySearch(a, n, x, l,mid-1);
	else return binarySearch(a,n,x,mid+1,h);
}

int main()
{
    int n,a[1000],x;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++) cin>> a[i];
    cout<<"Enter the value: ";
    cin>>x;
    cout<<"First Occurence: "<<binarySearch(a,n,x,a[0],a[n-1]);
    return 0;
}
