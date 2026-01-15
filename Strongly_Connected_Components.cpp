#include<bits/stdc++.h>
using namespace std;

stack<int> res;

void dfsVis(vector<vector<int>> &adj, int u, vector<bool> &vis, vector<int> &res){
    vis[u]=1;
    for(auto v:adj[u]){
        if(!vis[v]) 
            dfsVis(adj, v, vis, res);
    }
    res.push_back(u);
}



int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>> adj(v);
    vector<vector<int>> Tadj(v);
    for(int i=0;i<e;i++)
    {
        int p,q;
        cin>>p>>q;
        adj[p].push_back(q);
        Tadj[q].push_back(p);
    }
    vector<bool> vis(v,0);
    vector<int> list;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfsVis(adj,i,vis,list);
        }
    }

    // for(auto i:list) cout<<i<<" ";
    // cout<<endl;

    vector<vector<int>> ans;
    fill(vis.begin(), vis.end(), false);
    reverse(list.begin(),list.end());

     for(auto i:list){
        if(!vis[i]){
            vector<int> scc;
            dfsVis(Tadj,i,vis,scc);
            ans.push_back(scc);
        }
    }

    for(auto it:ans){
        for(auto j:it){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}