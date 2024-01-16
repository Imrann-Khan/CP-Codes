#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a[100];
  int b[100];
  int d,n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  for(int i=0;i<d;i++)
  {
    b[n-1-i]=a[i];
  }
  for(int i=0;i<(n-d);i++)
  {
    a[i+d]=b[i];
  }
  for(int i=0;i<n;i++)
  {
    cout<<b[i];
  }
  return 0;
}