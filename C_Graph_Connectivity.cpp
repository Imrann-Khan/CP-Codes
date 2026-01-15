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


void dfs(vector<vector<int>> &adj, int src, vector<bool> &vis){
    vis[src] = true;

    for(int v:adj[src]){
        if(!vis[v])
            dfs(adj, v, vis);
    }
}


signed main()
{
    fast
    int tc;
    cin>>tc;
    while(tc--){
        char m;
        cin>>m;
        int v = m-'A'+1;
        cin.ignore();
        vector<vector<int>> adj(26);
        string line;
        while(getline(cin,line) and line!=""){
            adj[line[0]-'A'].push_back(line[1]-'A');
            adj[line[1]-'A'].push_back(line[0]-'A');
        }
        vector<bool> vis(26);
        int ans=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(adj, i, vis);
                ans++;
            }
        }
        cout<<ans<<endl;
        if(tc) cout<<endl;
    }
    return 0;
}
