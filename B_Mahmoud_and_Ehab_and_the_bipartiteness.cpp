#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

bool flag=0;
vector<ll> A,B;

void DFS(vector<set<int>> &edge, int s, vector<bool> &vis, int color)
{
    vis[s] = true;
    if(color == 0)
        A.push_back(s);
    else
        B.push_back(s);
    for(auto j : edge[s])
    {
        if(!vis[j])
            DFS(edge, j, vis, 1 - color);
    }
}



int main()
{
    int v;
    cin>>v;
    vector<set<int>> edge(v);
    for(int i=0;i<v-1;i++)
    {
        int p,q;
        cin>>p>>q;
        p--;q--;
        edge[p].insert(q);
        edge[q].insert(p);
    }
    vector<bool> vis(v,false);
    DFS(edge, 0, vis, 0);
    ll ans = (ll)A.size() * (ll)B.size() - (v - 1);
    cout << ans << endl;
    return 0;
}