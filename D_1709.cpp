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


void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    rep(i,0,n-1) cin>>a[i];
    rep(i,0,n-1) cin>>b[i];
    vector<pair<int,int> > ans;
    rep(i,0,n-1)
    {
        rep(j,0,n-2)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                ans.push_back({1,j+1});
            }
        }
    }
    rep(i,0,n-1)
    {
        rep(j,0,n-2)
        {
            if(b[j]>b[j+1])
            {
                swap(b[j],b[j+1]);
                ans.push_back({2,j+1});
            }
        }
    }
    rep(j,0,n-1)
    {
        if(a[j]>b[j])
        {
            swap(a[j],b[j]);
            ans.push_back({3,j+1});
        }
    }
    cout<<(int)ans.size()<<endl;
    for(auto i:ans)
        cout<<i.first<<" "<<i.second<<endl;
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
