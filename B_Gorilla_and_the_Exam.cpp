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

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a[n];
    map<ll, ll> mp;
    rep(i, 0, n - 1)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    stack<ll> st;
    vector<ll> v;
    for (auto i : mp)
        v.push_back(i.second);
    sort(v.begin(), v.end(), greater<ll>());
    for (auto i : v)
    {
        st.push(i);
    }
    while (!st.empty() and st.top() <= k)
    {
        k -= st.top();
        st.pop();
    }
    cout << max((int)st.size(), 1) << endl;
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
