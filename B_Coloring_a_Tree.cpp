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


void solve()
{
    int n;
    cin>>n;
    vector<int> adj[n];
    for(int i=1;i<n;i++)
    {
        int x;
        cin>>x;
        adj[x-1].push_back(i);
    }
    vector<int> col(n);
    for(int i=0;i<n;i++) cin>>col[i];
    queue<pair<int,int>> q;
    q.push({0,0});
    int ans=0;
    while(!q.empty())
    {
        int child = q.front().first;
        int par = q.front().second;
        q.pop();
        if(col[par]!=col[child]) ans++;
        for(auto i:adj[child])
        {
            q.push({i,child});
        }
    }
    ans++;
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
