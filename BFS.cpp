#include<bits/stdc++.h>
using namespace std;

vector<int> ans,dis(1e5+1,-1);

void BFS(vector<vector<int>> &edge, int v, int s, vector<bool> &vis)
{
    queue<int> q;
    vis[s] = true;
    q.push(s);
    dis[s]=0;

    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        ans.push_back(p);

        for(auto j : edge[p])
        {
            if(!vis[j])
            {
                vis[j] = true;
                dis[j]=dis[p]+1;
                q.push(j);
            }
        }
    }
}

void BFSS(vector<vector<int>> &edge, int v, int s)
{
    vector<bool> vis(v, false);
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
            BFS(edge,v,i, vis);
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

    BFSS(edge, v, 0);

    for(int node : ans)
    {
        cout << node << " " <<dis[node]<<endl;
    }
    return 0;
}