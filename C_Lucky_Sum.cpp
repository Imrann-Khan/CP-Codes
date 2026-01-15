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

vector<ll> v;

void genAll(ll a,ll x)
{
    if (x>1e10) 
       return;
    if(10*x+4>=a) v.push_back(10*x+4);
    genAll(a, 10*x+4);
    if(10*x+7>=a)v.push_back(10*x+7);
    genAll(a, 10*x+7);
}


void solve()
{
    ll a,b;
    cin>>a>>b;
    genAll(a,0);
    sort(v.begin(),v.end());
    // for(auto i:v) cout<<i<<" ";
    // cout<<endl;
    ll ans=0,cur=0;
    rep(i,a,b)
    {
        if(v[cur]>=i and cur<v.size()) ans+=v[cur];
        else ans+=v[++cur];
    }
    cout<<ans<<endl;
}

signed main()
{
    fast

        ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
