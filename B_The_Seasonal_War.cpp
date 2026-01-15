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


void dfs(vector<vector<char>> &grid, int i, int j, int n, vector<vector<bool>> &vis){
    if(i<0 or j<0 or i>=n or j>=n) return;
    if(vis[i][j]) return;
    vis[i][j]=true;
    if(grid[i][j]!='1') return;
    
    if(i>0 and j>0) dfs(grid, i-1, j-1, n, vis); 
    if(i<n-1 and j<n-1) dfs(grid, i+1, j+1, n, vis); 
    if(i>0 and j<n-1) dfs(grid, i-1, j+1, n, vis); 
    if(i<n-1 and j>0) dfs(grid, i+1, j-1, n, vis); 
    if(i<n-1) dfs(grid, i+1, j, n, vis); 
    if(i>0) dfs(grid, i-1, j, n, vis); 
    if(j<n-1) dfs(grid, i, j+1, n, vis); 
    if(j>0) dfs(grid, i, j-1, n, vis); 
}


signed main()
{
    fast
    int n;
    int tc=1;
    while(cin>>n){
        vector<vector<char>> grid(n, vector<char>(n));
        rep(i,0,n-1){
            rep(j,0,n-1)
                cin>>grid[i][j];
        }
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        int ans=0;
        rep(i,0,n-1){
            rep(j,0,n-1){
                if(!vis[i][j] and grid[i][j]=='1'){
                    dfs(grid, i, j, n, vis);
                    ans++;
                }
            }
        }
        cout<<"Image number "<<tc++<<" contains "<<ans<<" war eagles.\n";
    }
}
