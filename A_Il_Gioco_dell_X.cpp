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


bool can(vector<vector<char>> &a, int i, int j, int n, vector<vector<bool>> &vis){
    if(i<0 or i>=n or j<0 or j>=n) return false;
    if(vis[i][j] or a[i][j]=='w') return false;

    if(i==n-1 and a[i][j]=='b') return true;

    vis[i][j]=true;

    if(i>0 and j>0 && can(a, i-1, j-1, n, vis)) return true;
    if(i>0 && can(a, i-1, j, n, vis)) return true;
    if(j>0 && can(a, i, j-1, n, vis)) return true;
    if(j<n-1 && can(a, i, j+1, n, vis)) return true;
    if(i<n-1 && can(a, i+1, j, n, vis)) return true;
    if(i<n-1 and j<n-1 && can(a, i+1, j+1, n, vis)) return true;

    return false;
}


signed main()
{
    fast
    int n;
    int tc=1;
    while (cin>>n)
    {
        if(n==0) break;
        vector<vector<char>> a(n, vector<char>(n));
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        rep(i,0,n-1){
            rep(j,0,n-1)
                cin>>a[i][j];
        }
        
        bool flag = false;

        for(int col=0;col<n;col++){
            if(can(a, 0, col, n, vis))
            {
                cout<<tc++<<" B\n";
                flag = true;
                break;
            }
        }
        
        if(!flag)
            cout<<tc++<<" W\n";
    }
}
