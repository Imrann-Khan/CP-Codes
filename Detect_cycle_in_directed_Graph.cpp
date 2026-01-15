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
int sum;
vector<int> ans;

void dfs(vector<vector<int>> &adj, int src, vector<int> &path, set<int> &pathSet, vector<bool> &vis){
    vis[src] = true;
    path.push_back(src);
    pathSet.insert(src);
    for(int v:adj[src]){
        if(pathSet.count(v)){
            vector<int> cycle;
            bool found = false;
            for(int node : path){
                if(node == v) found = true;
                if(found) cycle.push_back(node);
            }
            int curSum = accumulate(cycle.begin(), cycle.end(), 0);
            if(curSum < sum){
                sum = curSum;
                ans = cycle;
            }
        }
        else if(!vis[v]){
            dfs(adj, v, path, pathSet, vis);
        }
    }
    path.pop_back();
    pathSet.erase(src);
    vis[src] = false;
}



signed main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v+1);
    rep(i, 0, e-1){
        int p, q;
        cin >> p >> q;
        adj[p].push_back(q);
    }
    sum = INT_MAX;
    vector<bool> vis(v+1, false);
    for(int i = 1; i <= v; i++){
        fill(vis.begin(), vis.end(), false);
        vector<int> path;
        set<int> pathSet;
        dfs(adj, i, path, pathSet, vis);
    }
    sort(ans.begin(), ans.end());
    for(int x : ans) cout << x << " ";
    cout << endl;
}
