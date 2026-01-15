#include<bits/stdc++.h>
using namespace std;


int Prims(vector<vector<pair<int,int>>> &edge, int v)
{
    // initialization
    vector<bool> mSet(v,false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    int res=0;
    pq.push({0,0});

    while(!pq.empty())
    {
        auto p=pq.top();
        pq.pop();

        int w=p.first;
        int u=p.second;
        if(mSet[u]) continue;

        mSet[u]=true;
        res+=w;

        for(auto v:edge[u])
        {
            if(!mSet[v.first])
            {
                pq.push({v.second, v.first});
            }
        }
    }

    return res;
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>> edge(v);
    for(int i=0;i<e;i++)
    {
        int p,q,w;
        cin>>p>>q>>w;
        edge[p].push_back({q,w});
        edge[q].push_back({p,w});
    }
    cout<<Prims(edge,v)<<endl;
    return 0;
}