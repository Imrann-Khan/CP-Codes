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



int findPath(int sx, int sy)
{
    if (sx==0 && sy==0) return 0;
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

    map<pair<int, int>, int> vis;
    queue<pair<pair<int, int>, int>> q;
    q.push({{sx, sy}, 0});
    vis[make_pair(sx, sy)] = 1;

    while (!q.empty()) 
    {
        pair<pair<int, int>, int> curr = q.front();
        q.pop();
        int x = curr.first.first;
        int y = curr.first.second;
        int moves = curr.second;

        if (x == 0 and y == 0) return moves;

        for (int i = 0; i < 8; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx > -1000 && nx < 1000 && ny > -1000 && ny < 1000 && !vis[make_pair(nx, ny)]) 
            {
                vis[make_pair(nx, ny)] = 1;
                q.push({{nx, ny}, moves + 1});
            }
        }
    }
    return -1;
}

void solve()
{
    int s1,s2;
    cin>>s1>>s2;
    cout<<findPath(s1,s2)-2<<endl;
}

signed main()
{
    fast

        ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
