#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    cout<<v.size()<<endl;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(7);
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;
    cout<<v.size()<<endl;
    v.pop_back();
    v.pop_back();
    cout<<v.size()<<endl;
    v.push_back(3);
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;
    cout<<v.back();
}