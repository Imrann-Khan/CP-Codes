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
int dist[1001][1001];
const int dx[] = {-1, -2, -1, -2, +2, +1, +2, +1};
const int dy[] = {-2, -1, +2, +1, +1, +2, -1, -2};

void minimumMovement(){
    memset(dist, -1, sizeof(dist));
    dist[1][1]=0;
    queue<pair<int, int>> q;
    q.push({1,1});

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for(int k=0;k<8;k++){
            if(i+dx[k]>0 and i+dx[k]<=1000 and j+dy[k]>0 and j+dy[k]<=1000 and dist[i+dx[k]][j+dy[k]] == -1){
                dist[i+dx[k]][j+dy[k]] = dist[i][j] + 1;
                q.push({i+dx[k], j+dy[k]});
            }
        }
    }
}

void solve()
{
    int a, b;
    cin >> a >> b;
    cout<<dist[a][b]<<endl;
}

signed main()
{
    fast
    minimumMovement();
        ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
