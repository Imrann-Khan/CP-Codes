#include <bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll calculate_profit(ll n, ll a, ll b, ll k) 
{
    ll modified_profit = k * b - (k * (k - 1)) / 2;
    ll usual_profit = (n - k) * a;
    return modified_profit + usual_profit;
}

ll max_profit_for_case(ll n, ll a, ll b) 
{
    ll max_k = min(n, b);
    ll max_profit = calculate_profit(n, a, b, 0);
    max_profit = max(max_profit, calculate_profit(n, a, b, max_k)); 
    ll k_critical = ceil((b - a + 1) / 2);
    for (ll k =1; k <= min(max_k, k_critical+1); ++k) 
    {
        max_profit = max(max_profit, calculate_profit(n, a, b, k));
    }
    return max_profit;
}

signed main() {
    fast
    ll t;
    cin >> t;

    while (t--) 
    {
        ll n, a, b;
        cin >> n >> a >> b;
        cout << max_profit_for_case(n, a, b) << endl;
    }

    return 0;
}
