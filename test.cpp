#include <bits/stdc++.h>
using namespace std;

int dis[10000];
int vis[10000];

int bfs(int x, int y) 
{
    queue <int> q;
    int u, v;
    q.push(x);
    dis[x] = 0, vis[x] = 1;
    while (!q.empty()) 
    {
        u = q.front();
        q.pop();
        for (int i = 1; i <= 2; i++) 
        {
            if (i == 1)
                v = u - 1;
            else
                v = u * 2;
            if (vis[v]==0) 
            {
                q.push(v);
                dis[v] = dis[u] + 1;
                vis[v] = 1;
            }
            if (v == y)
                return dis[v];
        }
    }
}
int main() 
{
    long long n, m;
    cin >> n >> m;
    if (n >= m)    cout << n - m << endl;
    else
        cout << bfs(n, m) << endl;
}