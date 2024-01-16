#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    string b;
    string t;
    cin>>a>>b;
    int c=0;
    int l1=a.size();
    int l2=b.size();
    if(l1>l2)
    {
        int d=l1-l2;
        char g='0';
        for(int i=0;i<d;i++)
        {
            b=g+b;
        }
    }
    else
    {
        int d=l2-l1;
        char g='0';
        for(int i=0;i<d;i++)
        {
            a=g+a;
        }
    }
    if(l1=l2)
    {
        for(int i=a.size()-1;i>=0;i--)
    {
        int s=(a[i]-48)+(b[i]-48)+c;
        int p=(s%10);
        c=s/10;
        char x=p+48;
        t[i]=x;
    }
    if(c!=0)
    {
        cout<<c;
    }
    for(int i=0;i<a.size();i++)
    {
        cout<<t[i];
    }
    }
    return 0;
}