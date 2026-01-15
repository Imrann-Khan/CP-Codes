#include<bits/stdc++.h>
using namespace std;

vector<int> ans;



bool DFSS(vector<vector<int>> &edge, int s, vector<bool> &vis, vector<bool> &par)
{
    vis[s]=true;
    par[s]=true;
    //ans.push_back(s);
    for(auto i: edge[s])
    {
        if(!vis[i] and DFSS(edge, i, vis, par))
            return true;
        else if(par[i]) return true;
    }
    par[s]=false;
    return false;
}

bool isCycle(vector<vector<int>> &edge, int v)
{
    vector<bool> vis(v,false);
    vector<bool> par(v,false);
    for(int i=0;i<v;i++)
    {
        if(!vis[i] and DFSS(edge, i, vis, par))
            return true;
    }
    return false;
}


int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>> edge(v);
    for(int i=0;i<e;i++)
    {
        int p,q;
        cin>>p>>q;
        edge[p].push_back(q);
        //edge[q].push_back(p);
    }

    if(isCycle(edge, v)) 
        cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}