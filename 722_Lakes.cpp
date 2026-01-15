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


int dfs(vector<string> &grid, vector<vector<bool>> &vis, int i, int j, int r, int c){
    if(i<0 or j<0 or i>=r or j>=c) return 0;
    if(vis[i][j] or grid[i][j]=='1') return 0;
    vis[i][j]=true;

    int count=1;

    if(i<r-1) count+= dfs(grid, vis, i+1, j, r, c); 
    if(i>0) count+= dfs(grid, vis, i-1, j, r, c); 
    if(j<c-1) count+= dfs(grid, vis, i, j+1, r, c); 
    if(j>0) count+= dfs(grid, vis, i, j-1, r, c); 

    return count;
}


signed main()
{
    fast
    int tc;
    cin>>tc;
    while(tc--){
        int x,y;
        cin>>x>>y;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        vector<string> grid;
        while(true){
            string line;
            getline(cin,line);
            if(line=="") break; 
            grid.push_back(line);
        }
        vector<vector<bool>> vis(grid.size(), vector<bool> (grid[0].size(), false));
        
        cout<<dfs(grid, vis, x-1, y-1, grid.size(), grid[0].size())<<endl;
        if(tc) cout<<endl;
    }
    return 0;
}
