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
vector<int> primDiv;
const int N = 500000;

void SieveOfEratosthenes()
{
    vector<bool> prime(N + 1, true);
    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= N; p++)
        if (prime[p])
            primDiv.push_back(p);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> perm;
    perm.push_back(2);
    perm.push_back(1);
    ll sum = 3;
    vector<bool> freq(n + 1, true);
    freq[2] = 0;
    freq[1] = 0;
    int k = n / 3 - 1;
    int j = 0;
    if (k > 2)
    {
        rep(i, 3, k)
        {
        pp:
            int x = primDiv[j] * i - sum;
            if (!freq[x])
            {
                j++;
                goto pp;
            }
            if (x > n)
            {
                j--;
                goto pp;
            }
            sum += x;
            perm.push_back(x);
            j++;
            freq[x] = 0;
        }
    }
    rep(i, 1, n)
    {
        if (freq[i])
            perm.push_back(i);
    }
    rep(i, 0, (int)perm.size() - 1)
    {
        cout << perm[i] << " ";
    }
    cout << endl;
}

signed main()
{
    fast
    SieveOfEratosthenes();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
