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

const ll MOD = 1e9 + 7;
const int N = 1e7 + 1;

int bfs(pair<int,int> src, pair<int,int> dest, vector<vector<char>> &grid, vector<vector<pair<int,int>>> &dist){
    int dx[] = {-1, 0, 1, 0}; 
    int dy[] = {0, -1, 0, 1}; 
    dist[src.first][src.second]={0,0};

    queue<pair<int, int>> q;
    q.push({src.first, src.second});
    
    while(!q.empty()){
        pair<int,int> p = q.front();
        int cursteps = dist[p.first][p.second].first;
        int curstones = dist[p.first][p.second].second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = p.first+dx[i];
            int ny = p.second+dy[i];
            
            if(nx<0 or nx>=grid.size() or ny<0 or ny>=grid[0].size()) continue;

            int wt= (grid[nx][ny]=='#')? 1 : 0;

            int nsteps = cursteps+1;
            int nstones = curstones+wt;


            if(nsteps<dist[nx][ny].first or (nsteps==dist[nx][ny].first and nstones<dist[nx][ny].second)){
                dist[nx][ny]={nsteps, nstones};
                q.push({nx, ny});
            }
            
        }
    }

    return dist[dest.first][dest.second].second+1;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<pair<int,int>>> dist(n,vector<pair<int,int>>(m, {INT_MAX,INT_MAX}));

    pair<int,int> src, dest;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='D'){
                src.first=i;
                src.second=j;
            } else if(grid[i][j]=='E'){
                dest.first=i;
                dest.second=j;
            }
        }
    }

    cout<<bfs(src, dest, grid, dist)<<endl;
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
