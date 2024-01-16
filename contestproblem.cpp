#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    string b;
    cin>>a;
    b=a;
    int c=0;
    int d=0;
    int len=b.size();
    int j=0;
    for(int i=0;i<b.size();i++)
    {
           while(a[j]!='\n')
           {
               if(b[i]==a[j])
               {
                   d=j;
                   break;
               }
           }
           a=a+b;
           if(c==len)
           {
               break;
           }
    }
    cout<<j;
    return 0;
}