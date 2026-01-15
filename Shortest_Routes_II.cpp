#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repl(i, a, b) for (ll i = a; i <= b; i++)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pi 3.141592653589793238462643383279502884197
using namespace std;

void floydWarshall(int n, vector<vector<ll>> &dist){
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]!=LLONG_MAX and dist[k][j]!=LLONG_MAX){
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}

signed main()
{
    int n, m, q;
    cin>>n>>m>>q;
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, LLONG_MAX));
    for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=min(dist[u][v], w);
        dist[v][u]=min(dist[v][u], w);
    }
    floydWarshall(n, dist);
    while(q--){
        int u,v;
        cin>>u>>v;
        if(dist[u][v]==LLONG_MAX) cout<<-1<<endl;
        else cout<<dist[u][v]<<endl;
    }
}
