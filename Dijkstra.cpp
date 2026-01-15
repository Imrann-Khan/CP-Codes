#include<bits/stdc++.h>
using namespace std;

vector<int> dist(1e5,INT_MAX);

void Disjktra(vector<vector<pair<int,int>>> &edge, int s){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,s});
    dist[s]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();

        for(auto v:edge[u]){
            int w=v.second;
            if(dist[v.first]>dist[u]+w){
                dist[v.first]=dist[u]+w;
                pq.push({dist[v.first],v.first});
            }
        }
    }
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
    }

    Disjktra(edge,0);

    for(int i=0;i<v;i++){
       cout<<dist[i]<<" "; 
    }

    return 0;
}