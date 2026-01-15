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

ll con(int n, int x)
{
    stack<ll> st;
    while (x)
    {
        st.push(x % n);
        x /= n;
    }
    ll ans = 0;
    ll sz = st.size();
    while (!st.empty())
    {
        // cout << st.top() << endl;
        ans *= 10;
        ans += st.top();
        st.pop();
        sz--;
    }
    cout << ans << endl;
    return ans;
}

signed main()
{
    fast
        ll n,
        k;
    cin >> n >> k;
    ll l = 0, r = 2e18;
    ll mid;
    int ans = 0;
    while (r >= l)
    {
        mid = l + (r - l) / 2;
        if (con(n, mid) >= k)
        {
            // cout << mid << " ";
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
