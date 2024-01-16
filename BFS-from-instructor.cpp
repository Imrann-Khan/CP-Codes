#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100];
int visited[100];
int par[100];
int dis[100];

void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s]=1;
    par[s]=-1;
    dis[s]=0;

    while(q.size()!=0){
        int u = q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(visited[v]==0){
                q.push(v);
                visited[v]=1;
                par[v]=u;
                dis[v]=dis[u]+1;
            }
        }
    }
}

void path(int x){
    if(x==-1)   return;
    path(par[x]);
    cout<<x<<" ";
}

int main(){
    int n,e,s;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>e;
    cout<<"Enter "<<e<<" edges"<<endl;

    while(e--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<<"Enter the source: ";
    cin>>s;

    bfs(s);

    while(1){
        cout<<"Enter the vertex whose shortest path and shortest distance from "<<s<<" to be displayed: ";
        int x;
        cin>>x;
        cout<<"Shortest distance from "<<s<<" to "<<x<<" is: "<<dis[x]<<endl;
        cout<<"Shortest path from "<<s<<" to "<<x<<" is: ";
        path(x);
        cout<<endl;
    }
}

/*
5 6
0 1
0 3
0 4
1 2
1 3
2 3
0
0 1 2 3 4
*/
