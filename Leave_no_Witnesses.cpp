#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define s second
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

void sieveOfEratosthenes()
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
    cin >> n;
    string s; 
    cin >> s;

    int m = 0; 
    while ((1 << m) <= n) m++;

    vector<char> b(n, '1');
    vector<bool> z(n+1, false);
    for (int x = n; x >= 1; x--) 
    {
        bool flag  = false;
        for (int k = 0; k < m; k++) 
        {
            if (!((x >> k) & 1)) 
            {
                int y = x | (1 << k);
                if (y <= n && z[y]) 
                { 
                    flag = true; 
                    break; 
                }
            }
        }
        if (flag) z[x] = true;
        else      
        { 
            b[x-1] = '0';
            z[x] = true; 
        }
    }

    vector<char> c(n, '0');
    vector<bool> o(n+1, false);
    for (int x = 1; x <= n; x++) 
    {
        bool flag  = false;
        for (int k = 0; k < m; k++) 
        {
            if ((x >> k) & 1) 
            {
                int y = x ^ (1 << k);
                if (o[y]) 
                { 
                    flag  = true; 
                    break; 
                }
            }
        }
        if (flag) o[x] = true;
        else    
        { 
            c[x-1] = '1'; 
            o[x] = true; 
        }
    }

    int r = 0;
    for (int i = 0; i < n; i++) 
    {
        if (b[i] == '0' && c[i] == '1') 
        {
            cout << -1 << endl;
            return;
        }
        char t = (b[i] == '0' ? '0' : (c[i] == '1' ? '1' : s[i]));
        if (s[i] != t) ++r;
    }
    cout << r << endl;
}

int main(){
    fast
    int tc; 
    cin >> tc;
    while (tc--) 
    {
        solve();
    }
    return 0;
}
