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
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> tmp(n);
    vector<ll> ans;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    priority_queue<ll> x;
    map<ll, ll> fr;
    rep(i, 0, n - 1)
    {
        cin >> a[i];
        tmp[i] = a[i];
        fr[a[i]]++;
    }
    sort(tmp.begin(), tmp.end());
    // rep(i, 0, tmp.size() - 1)
    //         cout
    //     << tmp[i] << " ";
    // cout << endl;
    int j = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (fr[tmp[i]])
        {
            if (a[j] == tmp[i])
            {
                fr[a[j]]--;
                if (!pq.empty())
                {
                    if (a[j] > pq.top())
                    {
                        // cout << a[j] << " ";
                        pq.push(a[j] + 1);
                        // x.push(a[j] + 1);
                        //   cout << a[j] + 1 << " ";
                    }
                    else
                        ans.push_back(a[j]);
                }
                else
                {
                    ans.push_back(a[j]);
                }
                j++;
                continue;
            }
            else
            {
                while (a[j] != tmp[i] and j < n)
                {
                    fr[a[j]]--;
                    pq.push(a[j] + 1);
                    x.push(a[j] + 1);
                    //  cout << a[j] + 1 << " ";
                    j++;
                }
                // cout << endl;
                if (a[j] > pq.top() and !pq.empty())
                {
                    // cout << a[j] << " ";
                    pq.push(a[j] + 1);
                    // x.push(a[j] + 1);
                    //   cout << a[j] + 1 << " ";
                }
                else
                    ans.push_back(a[j]);
                fr[a[j]]--;
                j++;
                if (j == n)
                    break;
            }
        }
        // else
        //     cout << i << endl;
        // rep(i, 0, ans.size() - 1) cout << ans[i] << " ";
        // cout << endl;
    }
    // cout << endl;
    //  rep(i, 0, ans.size() - 1) cout << ans[i] << " ";
    //  cout << endl;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    rep(i, 0, ans.size() - 1) cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    fast
        ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
