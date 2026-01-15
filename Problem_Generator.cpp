#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;




void solve()
{
        ll  n, m;
        string a;
        cin>>n>>m>>a;
        ll difficultyCount[7] = {0};
        for (char ch : a) {
            difficultyCount[ch - 'A']++;
        }
        ll problemsToCreate = 0;
        for (ll i = 0; i < 7; ++i) {
            if (difficultyCount[i] < m) {
                problemsToCreate += m - difficultyCount[i];
            }
        }
        cout << problemsToCreate << '\n';
    
}


signed main()
{
    fast
    ll t; cin>>t;
    while(t--)
    {
        solve();
    }
}