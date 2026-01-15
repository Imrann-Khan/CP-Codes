#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pi 3.141592653589793238462643383279502884197
using namespace std;



ll BFSS(const vector<vector<pair<int,ll>>> &edge, int s, vector<ll> &dist)
{
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto i : edge[u])
        {
            if(dist[i.first]==-1)
            {
                dist[i.first]=dist[u]+i.second;
                q.push(i.first);
            }
        }
    }
    return max_element(dist.begin(),dist.end()) - dist.begin();
}

ll BFS(vector<vector<pair<int,ll>>> &edge, int n, int s)
{
    vector<ll> dist1(n, -1);
    int farthest = BFSS(edge, s, dist1);

    vector<ll> dist2(n, -1);
    BFSS(edge, farthest, dist2);

    return *max_element(dist2.begin(), dist2.end());
}


void solve()
{
    int n;
    cin>>n;
    vector<vector<pair<int,ll>>> edge(n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        edge[u].push_back({v,w});
        edge[v].push_back({u,w});
    }
    cout<<BFS(edge,n,0)<<endl;
}

signed main()
{
    fast

    ll t;
    cin >> t;
    int c=1;
    while (t--)
    {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}
