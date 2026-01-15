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

ll con(int a, int b)
{
    ll ans = 0;
    stack<int> st;
    while (a)
    {
        st.push(a % b);
        ans += (a % b);
        a /= b;
    }
    return ans;
}

signed main()
{
    fast int a;
    cin >> a;
    int ans = 0;
    for (int i = 2; i < a; i++)
    {
        ans += (con(a, i));
    }
    cout << ans / (__gcd(ans, a - 2)) << "/" << (a - 2) / (__gcd(ans, a - 2)) << endl;
    return 0;
}
