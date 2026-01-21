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
vector<bool> prime(N);
vector<int> pr;


void solve()
{
    int n, h, y1, y2, l;
    cin >> n >> h >> y1 >> y2 >> l;
    
    int ans=0;

    vector<pair<int,int>> path(n);
    rep(i,0,n-1)
        cin>>path[i].first>>path[i].second;
    
    rep(i,0,n-1) {
        int t=path[i].first;
        int x=path[i].second;
        
        bool flag = 0;
        
        if (t == 1) 
            flag = (x >= h - y1);
        else 
            flag = (y2 >= x);
        
        if (flag) {
            ans++;
        } 
        else if (l > 1) {
            l--;
            ans++;
        } 
        else {
            break;
        }
    }
    
    cout << ans << endl;
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
