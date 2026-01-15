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

bool comp(pair<int,char> &p1, pair<int, char> &p2){
    if(p1.first>p2.first) return true;
    if(p1.first==p2.first){
        return p1.second<p2.second;
    }
    return false;
}


int dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j, int r, int c, char x){
    if(i<0 or j<0 or i>=r or j>=c) return 0;
    if(vis[i][j] or grid[i][j]!=x) return 0;
    vis[i][j]=true;

    int count=1;

    if(i<r-1) count+= dfs(grid, vis, i+1, j, r, c, x); 
    if(i>0) count+= dfs(grid, vis, i-1, j, r, c, x); 
    if(j<c-1) count+= dfs(grid, vis, i, j+1, r, c, x); 
    if(j>0) count+= dfs(grid, vis, i, j-1, r, c, x); 

    return count;
}


signed main()
{
    fast
    int tc;
    cin>>tc;
    int y=1;
    while(tc--){
        int r,c;
        cin>>r>>c;
        vector<vector<char>> grid(r, vector<char> (c));
        vector<vector<bool>> vis(r, vector<bool> (c, false));
        vector<pair<int, char>> res(26);
        set<char> s;
        rep(i,0,r-1){
            rep(j,0,c-1){
                cin>>grid[i][j];
                s.insert(grid[i][j]);
            }
        }
        for(char x: s){
            int ans=0;
            rep(i,0,r-1){
                rep(j,0,c-1){
                    if(!vis[i][j] and grid[i][j]==x){
                        dfs(grid, vis, i, j, r, c, x);
                        ans++;
                    }
                }
            }
            res[x-'a']={ans,x};
        }
        sort(res.begin(), res.end(), comp);
        cout<<"World #"<<y++<<endl;
        for(auto it:res){
            if(it.first!=0){
                cout<<it.second<<": "<<it.first<<endl;
            }
        }
    }
    return 0;
}
