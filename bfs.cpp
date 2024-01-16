#include<bits/stdc.h>
using namespace std;

int n,e;
int adj[100][100];
int level[100], visited[100], parent[100];

void bfs(int s){
    queue<int>q;
    q.push(s);
    level[s] = 0;
    visited[s] = 1;
    parent[s] = -1;

    while(q.size()>0){
        int senior = q.front();
        q.pop();

        for(int i=0; i<n; i++){
            if(adj[senior][i]==1){
                int junior = i;
                if(visited[junior]==0){
                    q.push(junior);
                    visited[junior] = 1;
                    parent[junior] = senior;
                    level[junior] = level[senior] + 1;
                }
            }
        }
    }
}

int main(){
    cin>>n>>e;
    for(int i=1; i<=e; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        ///adj[v][u] = 1;
    }
    bfs(0);
}
