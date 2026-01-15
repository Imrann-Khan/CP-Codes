#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define fast                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;
const ll LIMIT = 1LL << 32;


ll cnt(const vector<string>& inp, int& i) 
{
    if (i >= inp.size()) 
        return 0;

    ll value = 0;
    ll nextVal=0;
    const string& command = inp[i];

    if (command[0] == 'e') 
    {
        i++;
        return 0; 
    }
    if (command[0] == 'a') 
    {
        i++;
        value = 1;
    } 
    else if (command[0] == 'f') 
    {
        i++; 
        ll n = stoll(command.substr(4));
        ll value1 = cnt(inp, i);
        if (value1 >=LIMIT) 
            value = LIMIT;
        else 
            value = n * value1;
    }

    nextVal = cnt(inp, i);
    ll total_value = value + nextVal;

    if (total_value >= LIMIT) 
    {
        return LIMIT;
    }
    return total_value;
}

void solve() {
    int l;
    cin>>l;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> inp(l);
    rep(i, 0, l - 1) 
        getline(cin, inp[i]); 
    

    int i=0;
    ll ans = cnt(inp, i);

    if (ans >= LIMIT) 
        cout << "OVERFLOW!!!\n";
    else 
        cout << ans << endl;
    
}

signed main() {
    fast

    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
