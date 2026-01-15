#include<bits/stdc++.h>
using namespace std;

vector<int> ans;



void DFSS(vector<vector<int>> &edge, int s, vector<bool> &vis)
{
    vis[s]=true;
    ans.push_back(s);
    for(auto i: edge[s])
    {
        if(!vis[i])
            DFSS(edge, i, vis);
    }
}

void DFS(vector<vector<int>> &edge, int v)
{
    vector<bool> vis(v,false);
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
            DFSS(edge, i, vis);
    }
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
        edge[q].push_back(p);
    }

    DFS(edge, v);

    for(int node : ans)
    {
        cout << node << " ";
    }
    return 0;
}