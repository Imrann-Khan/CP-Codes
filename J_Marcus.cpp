#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pi 3.141592653589793238462643383279502884197
using namespace std;


bool dfs(vector<vector<char>> &grid, int i, int j, int r, int c, vector<string> &path, int idx)
{
    if(idx == 6)
    {
        int di[3] = {-1, 0, 0};
        int dj[3] = {0, 1, -1};
        string dir[3] = {"forth", "right", "left"};
        for(int d=0; d<3; d++)
        {
            int ni = i + di[d];
            int nj = j + dj[d];
            if(ni >= 0 and ni < r and nj >= 0 and nj < c and grid[ni][nj] == '#')
            {
                path.push_back(dir[d]);
                return true;
            }
        }
        return false;
    }
    int di[3] = {-1, 0, 0};
    int dj[3] = {0, 1, -1};
    string dir[3] = {"forth", "right", "left"};
    string way = "IEHOVA";
    for(int d=0; d<3; d++)
    {
        int ni = i + di[d];
        int nj = j + dj[d];
        if(ni >= 0 && ni < r && nj >= 0 && nj < c && grid[ni][nj] == way[idx])
        {
            path.push_back(dir[d]);
            if(dfs(grid, ni, nj, r, c, path, idx+1))
                return true;
            path.pop_back();
        }
    }
    return false;
}


void solve()
{
    int r, c;
    cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    pair<int, int> st;
    vector<string> path;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '@')
            {
                st = {i, j};
            }
        }
    }
    if (dfs(grid, st.first, st.second, r, c, path, 0))
    {
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i];
            if (i + 1 < path.size())
                cout << " ";
        }
        cout << endl;
    }
}

signed main()
{
    fast

    ll t;
    cin >> t;
    int c=1;
    while (t--)
    {
        //cout<<"Case "<<c++<<": ";
        solve();
    }
    return 0;
}
