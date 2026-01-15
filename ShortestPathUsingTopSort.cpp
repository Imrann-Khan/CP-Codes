#include<bits/stdc++.h>
using namespace std;


vector<int> TopSort(vector<vector<pair<int,int>>> &edge, int v, vector<int> indeg)
{
    vector<int> ans;
    queue<int> q;
    for(int i = 0; i < v; i++)
    {
        if(indeg[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        //cout << p << " ";
        ans.push_back(p);
        for(auto j : edge[p])
        {
            indeg[j.first]--;
            if(indeg[j.first] == 0)
                q.push(j.first);
        }
    }
    return ans;
}

void ShortestDistance(vector<int> &topSort, vector<vector<pair<int,int>>> &edge, int v, int s)
{
    vector<int> dist(v, INT_MAX);
    dist[s] = 0;
    for (auto u : topSort)
    {
        if (dist[u] == INT_MAX) continue;
        for (auto &e : edge[u])
        {
            int w = e.first;
            int wt = e.second;
            if (dist[u] + wt < dist[w])
                dist[w] = dist[u] + wt;
        }
    }

    for (auto d : dist) cout << d << " ";
    cout << endl;
}


int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>> edge(v);
    vector<int> indeg(v,0);
    for(int i=0;i<e;i++)
    {
        int p,q,w;
        cin>>p>>q>>w;
        edge[p].push_back({q,w});
        indeg[q]++;
    }
    vector<int> topSort = TopSort(edge,v,indeg);
    ShortestDistance(topSort, edge, v, 0);
    return 0;
}