#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m,n;
    cin>>n>>m;
    vector<int>v;
    int s=0;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        s+=tmp;
        v.push_back(tmp);
    }
    double lim=ceil((s/(4*m))),cnt=0;
    cout<<lim<<" "<<s<<endl;
    for(int i=0;i<n;i++)
    {
        if(v[i]>=lim)
        {
            cnt++;
        }
    }
    if(cnt>=m)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }


    return 0;
}