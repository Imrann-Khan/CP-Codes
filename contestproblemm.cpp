#include<bits/stdc++.h>
using namespace std;
bool status=false;
int main()
{
    string a,b;
    cin>>a;
    cin>>b;
    int c=0,i=0,j=0;
    int l=0;
   for(i=0;i<b.size();i++)
   {
       for(j=l;j<a.size();j++)
       {
           if(b[i]==a[j])
           {
               status=true;
               l=l+b.size();
               a=a+a;
               break;
           }
           else
           {
               status=false;
           }
       }
       if(status==false)
       {
           cout<<"Not possible";
           break;
       }
   }
   if(status==true)
   {
       cout<<j;
   }
    return 0;
}
