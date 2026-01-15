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




signed main()
{
    int n,k;
    cin>>n>>k;
    vector<int> o(n);
    sort(o.begin(), o.end());
    vector<int> dp(n+1, -1);
    rep(i,0,n-1) cin>>o[i];
}
