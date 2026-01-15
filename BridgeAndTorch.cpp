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


int solve(vector<int> times, int n, vector<int> &dp){
    if(n==1) return times[0];
    if(n==2) return times[1];
    if(n==2) return times[0]+times[1]+times[2];

    if(dp[n]!=-1) return dp[n];

    int op1 = times[0]+2*times[1]+times[n-1];
    int op2 = times[n-1]+times[n-2]+2*times[0];

    int res = min(op1+solve(times, n-2, dp), op2+solve(times, n-2, dp));

    dp[n] = res;
    return res;
}

signed main()
{
    int n;
    cin>>n;
    vector<int> times(n);
    vector<int> dp(n+1, -1);
    rep(i,0,n-1) cin>>times[i];
    cout<<solve(times, n, dp)<<endl;
}
