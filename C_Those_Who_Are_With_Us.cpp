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

void SieveOfEratosthenes()
{
    for (int p = 2; p * p <= N; p++)
    {
        prime[p] = true;
    }
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }

    // for (int p = 2; p <= N; p++)
    //     if (prime[p])
    //         pr.push_back(p);
}

ll intPower(ll base, ll exp)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

bool Max(vector<pair<int, int>>& maxPos) 
{
    if (maxPos.size() <= 1) 
        return true;

    set<int> rowmx;
    for (auto pos : maxPos) 
        rowmx.insert(pos.first);
    
    for (auto i : rowmx) 
    {
        int c = -1;
        bool flag = true;

        for (auto j : maxPos) 
        {
            if (j.first == i) 
                continue;
            
            if (c == -1) 
                c = j.second;
            else if (j.second != c) 
            {
                flag = false;
                break;
            }
        }
        if (flag) 
            return true;
        
    }
    return false;
}


void solve()
{
    int n, m;
    cin >> n >> m;
    int mx = 0;
    vector<pair<int, int>> maxPos;
    rep(i,0,n-1)
    {
        rep(j,0,m-1)
        {
            int cur;
            cin >> cur;
            if (cur > mx) 
            {
                mx = cur;
                maxPos.clear(); 
                maxPos.push_back({i,j});
            } 
            else if (cur == mx) 
                maxPos.push_back({i, j}); 
        }
    }
    if (Max(maxPos)) 
        cout << mx - 1 << endl;
    else 
        cout << mx << endl;
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
