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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    map<int,int> freq;
    rep(i,0,n-1){
        cin>>a[i];
        freq[a[i]]++;
    }
    set<int> s;
    for(auto it:freq){
        if(it.second%k!=0){
            cout<<0<<endl;
            return;
        }
    }
    ll ans=0;
    map<int, int> wfreq;
    int j=0;
    rep(i,0,n-1) {
        while (j < n) {
            if (wfreq[a[j]] + 1 > freq[a[j]] / k)
                break; 
            wfreq[a[j]]++;
            j++;
        }
        if(j-i>0) ans += (j - i);
        if (wfreq.count(a[i])) {
            wfreq[a[i]]--;
        }
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
