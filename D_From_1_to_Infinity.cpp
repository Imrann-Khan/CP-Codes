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
vector<ll> p(20,1),d(20);

ll totlen(ll n) {
    ll ans = 0, len = 1;
    ll temp = 1;
    while (temp <= n) {
        ll x = min(n, temp*10-1);
        ans += (x - temp + 1)*len;
        temp *= 10;
        len++;
    }
    return ans;
}

void solve(){
    ll k; 
    cin >> k;

    ll l=1, r=1e18, x=0;
    while (l<=r) {
        ll mid = (l+r)>>2;
        if (totlen(mid) < k) l = mid+1;
        else { 
            x = mid; 
            r = mid-1; 
        }
    }
    ll temp = totlen(x-1);

    ll ans;
    if (x-1 < 10) ans = x*(x-1)/2;
    string s = to_string(x-1);
    int c = s.size();
    ll pw = p[c-1], m = (x-1)/pw, r = (x-1)%pw;
    ans =  m*d[c-1] + m*(m-1)/2*pw + m*(r+1) + sumd(r);

    string t = to_string(x);
    for (int i = 0; i < k - temp; i++)
        ans += t[i] - '0';
    cout << ans << endl;
}

int main(){
    fast

    for(int i=1;i<20;i++){
        p[i] = p[i-1]*10;
        d[i] = 10*d[i-1] + 45*p[i-1];
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
