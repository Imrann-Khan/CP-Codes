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

int mxDigit(int n)
{
    int ans = -1;
    while(n != 0)
    {
        ans = max(ans, n % 10);
        n /= 10;
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> dp(1000001);
    dp[0]=0;
    for(int i=1;i<10;i++) dp[i]=1;
    for(int i=10;i<=1000000;i++)
    {
        dp[i]=dp[i-mxDigit(i)]+1;
    }
    cout<<dp[n]<<endl;
}

signed main()
{
    fast

        ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
