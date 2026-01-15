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

ll dfs(vector<vector<int>> &adj, int s, vector<ll> &cost, vector<bool> &vis)
{
    vis[s]=true;
    ll ans = cost[s];
    for(auto i:adj[s])
    {
        if(!vis[i])
        {
            ans=min(ans,dfs(adj,i,cost,vis));
        }
    }
    return ans;
}


void solve()
{
    ll n,e;
    cin>>n>>e;
    vector<ll> cost(n);
    for(int i=0;i<n;i++)
    {
        cin>>cost[i];
    }
    vector<vector<int>> adj(n);
    for(int i=0;i<e;i++)
    {
        int p,q;
        cin>>p>>q;
        adj[p-1].push_back(q-1);
        adj[q-1].push_back(p-1);
    }
    vector<bool> vis(n,false);
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i]) ans+=dfs(adj,i,cost,vis);
    }
    cout<<ans<<endl;
}

signed main()
{
    fast

        ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
