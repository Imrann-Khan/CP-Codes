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

const ll MOD = 1e9 + 7;
const int N = 1e7 + 1;


int bfs(map<int, vector<int>> &adj, int src, int ttl){
    map<int, bool> vis;
    queue<pair<int, int>> q;
    q.push({src, ttl});
    vis[src] = true;
    int count = 1;
    
    while(!q.empty()){
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if(dist > 0){
            for(auto v: adj[node]){
                if(!vis[v]){
                    vis[v] = true;
                    count++;
                    q.push({v, dist-1});
                }
            }
        }
    }
    return count;
}

signed main()
{
    fast
    int n;
    int c=1;
    while(cin>>n){
        map<int, vector<int>> adj;
        set<int> nodes;
        for(int i=0;i<n;i++){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            nodes.insert(u);
            nodes.insert(v);
        }
        
        int node, ttl;
        while(cin>>node>>ttl){
            if(node == 0 and ttl == 0) break;
            cout<<"Case "<<c++<<": ";

            int reachable = 0;
            if(nodes.find(node) != nodes.end()){
                reachable = bfs(adj, node, ttl);
            } else {
                reachable = 0;
            }

            cout<<nodes.size() - reachable
                <<" nodes not reachable from node "<<node<<" with TTL = "<<ttl<<".\n";
        }
    }
    return 0;
}
