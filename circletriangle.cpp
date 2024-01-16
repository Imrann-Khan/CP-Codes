#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int,vector<string> > m;
    for(int i=1;i<=n;i++)
    {
        int l;
        cin>>l;
        string a,b;
        cin>>a>>b;
        vector<string> v;
        v.push_back(a);
        v.push_back(b);
        m[l]=v;
    }
    map<int,vector<string> >::reverse_iterator it;
    for(it=m.rbegin();it!=m.rend();++it)
    {
        cout<<it->first<<" "<<it->second[0]<<" "<<it->second[1]<<endl;
    }
}
