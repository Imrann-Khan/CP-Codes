#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(13);

    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
}
