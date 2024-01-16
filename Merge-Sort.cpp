#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int l,int m, int r)
{
    int n1=m-l+1,n2=r-m;
    int a[n1],b[n2]; /// temporary arrays
    for(int i=0;i<n1;i++)
        a[i]=arr[l+i];
    for(int i=0;i<n2;i++)
        b[i]=arr[m+1+i];
    int i=0,j=0,k=l;
    for(i=0,j=0,k=l; i<n1 && j<n2 ; k++)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            i++;
        }
        else
        {
            arr[k]=b[j];
            j++;
        }
    }
    while(i<n1) arr[k++]=a[i++]; /// PostFix= First assign then add (arr[k]=a[i]; k++; i++;)
    while(j<n2) arr[k++]=b[j++];

}
void mergeSort(vector<int> &arr, int l, int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main()
{
    int n,x;
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    return 0;
}
