#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


bool isGreaterThanFavoriteValue(ll value, ll favoriteValue) 
{
    return value > favoriteValue;
}

void solve()
{
    ll n,f,k;
    cin>>n>>f>>k;
    vector<ll> cubes(n);
        for (ll i = 0; i < n; i++) 
        {
            cin >> cubes[i];
        }
        ll favoriteValue = cubes[f - 1];
        ll greaterCount = count_if(cubes.begin(), cubes.end(), bind(isGreaterThanFavoriteValue, placeholders::_1, favoriteValue));
        ll equalCount = count(cubes.begin(), cubes.end(), favoriteValue);
        if (greaterCount >= k)
        {
            cout << "NO\n"; 
        } 
        else if (greaterCount + equalCount <= k) 
        {
            cout << "YES\n"; 
        } 
        else 
        {
            cout << "MAYBE\n"; 
        }
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