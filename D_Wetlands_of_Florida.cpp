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
    if(vis[i][j] or grid[i][j]=='L') return 0;
    vis[i][j]=true;

    int count=1;

    if(i>0 and j>0) count+= dfs(grid, vis, i-1, j-1, r, c); 
    if(i<r-1 and j<c-1) count+= dfs(grid,  vis, i+1, j+1, r, c); 
    if(i>0 and j<c-1) count+= dfs(grid, vis, i-1, j+1, r, c); 
    if(i<r-1 and j>0) count+= dfs(grid, vis, i+1, j-1, r, c); 
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

        vector<string> grid;
        vector<pair<int, int>> queries;
        string line;
        while(getline(cin,line)){
            if(line=="") continue;
            if((line[0]=='W' or line[0]=='L')) grid.push_back(line);
            else break;
        }
        stringstream ss(line);
        int r,c;
        if(ss>>r>>c) queries.push_back({r, c});
        while(getline(cin,line) && !line.empty()){
            stringstream qs(line);
            if(qs>>r>>c) queries.push_back({r, c});
        }

        for(pair<int,int> q: queries){
            vector<vector<bool>> vis(grid.size(), vector<bool> (grid[0].size(), false));
            cout<<dfs(grid, vis, q.first-1, q.second-1, grid.size(), grid[0].size())<<endl;
        }
        if(tc) cout<<endl;
    }
    return 0;
}
