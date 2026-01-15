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

void SieveOfEratosthenes()
{
    for (int p = 2; p * p <= N; p++)
    {
        prime[p] = true;
    }
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }

    // for (int p = 2; p <= N; p++)
    //     if (prime[p])
    //         pr.push_back(p);
}

ll intPower(ll base, ll exp)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

static const vector<pair<ll,int>> i_e = 
{
  {1, 1}, {2, -1}, {3, -1}, {5, -1}, {7, -1},
  {2*3, 1}, {2*5, 1}, {2*7, 1}, {3*5, 1}, {3*7, 1}, 
  {5*7, 1}, {2*3*5, -1}, {2*3*7, -1}, {2*5*7, -1}, {3*5*7, -1},
  {2*3*5*7, 1}
};

void solve()
{
    ll l,r;
    cin>>l>>r;

    ll ans=0;

    for(auto it:i_e)
    {
        ll temp = (r/it.first)-(l-1)/it.first;
        if(it.second==-1) ans-=temp;
        else ans+=temp;
    }
    cout<<ans<<endl;
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
