#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector<int> cnt(k + 1, 0);
    for (int e : a) {
        if (e <= k) {
            cnt[e] |= 1;
        }
    }
    for (int e : b) {
        if (e <= k) {
            cnt[e] |=2;
        }
    }

    vector<int> c(4, 0);
    for (int e : cnt) {
        c[e]++;
    }

    if (c[1] > k / 2 || c[2] > k / 2 || c[1] + c[2] + c[3] != k) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

signed main()
{
    fast
    ll t; cin>>t;
    while(t--)
    {
        solve();
    }
}