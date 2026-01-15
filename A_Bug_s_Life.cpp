#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;




bool isBipartite(vector<vector<int>> &edge, int n) 
{
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) 
    {
        if (color[i] == -1) 
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty()) 
            {
                int u = q.front();
                q.pop();
                for (auto v : edge[u]) {
                    if (color[v] == -1) 
                    {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } 
                    else if (color[v] == color[u]) 
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void solve()
{
    int n,e;
    cin>>n>>e;
    vector<vector<int>> edge(n);
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        edge[u-1].push_back(v-1);
        edge[v-1].push_back(u-1);
    }
    if(!isBipartite(edge,n))
        cout<<"Suspicious bugs found!\n";
    else
        cout<<"No suspicious bugs found!\n";
}

signed main()
{
    int t;
    cin>>t;
    int c=0;
    while(t--)
    {
        cout<<"Scenario #"<<++c<<":\n";
        solve();
    }
}
