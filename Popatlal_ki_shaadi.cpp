#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pi 3.141592653589793238462643383279502884197
using namespace std;

const int N = 1e7 + 1;
vector<bool> prime(N);
vector<int> pr;

void SieveOfEratosthenes()
{
    fill(prime.begin(), prime.end(), true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p < N; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i < N; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p < N; p++)
        if (prime[p])
            pr.push_back(p);
}

int DFSS(vector<vector<int>> &edge, int s, vector<bool> &vis)
{
    vis[s]=1;
    int res = 1;
    for( auto i: edge[s])
    {
        if(!vis[i])
        {
            res+=DFSS(edge,i,vis);
        }
    }
    return res;
}


int DFS(vector<vector<int>> &edge, int n)
{
    vector<bool> vis(n+1,0);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            ans = max(ans, DFSS(edge,i,vis));
        }
    }
    return ans;
}

void solve()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> edge(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        edge[u-1].push_back(v-1);
        edge[v-1].push_back(u-1);
    }
    if(m==0)
    {
        cout<<-1<<endl;
        return;
    }
    int ans = DFS(edge,n);
    cout<<pr[ans-1]<<endl;
}

signed main()
{
    fast
    SieveOfEratosthenes();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
