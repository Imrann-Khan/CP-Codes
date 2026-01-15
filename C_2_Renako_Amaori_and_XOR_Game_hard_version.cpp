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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    
    int resA = 0;
    int resB  = 0;

    rep(i,0,n-1){
        cin >> a[i];
        resA ^= a[i];
    }
    rep(i,0,n-1){
        cin >> b[i];
        resB  ^= b[i];
    }
    if(resA == resB ){
        cout << "Tie\n";
        return;
    }

    int diff = resA ^ resB ;
    int msb = 0;
    for(int b = 31; b >= 0; b--){
        if((diff >> b) & 1){
            msb = b;
            break;
        }
    }

    int w= -1;
    for(int i = 0; i < n; i++){
        if(((a[i] ^ b[i]) >> msb) & 1){
            w = i;
        }
    }

    if(w % 2 == 0){
        cout << "Ajisai\n";
    } else {
        cout << "Mai\n";
    }
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