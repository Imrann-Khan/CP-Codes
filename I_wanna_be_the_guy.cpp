#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll arr[n+1];
    for(ll i = 1 ; i <= n ; i++) arr[i]=0;
    ll x,y,c=0;
    cin >> x;
    for(ll i = 1 ; i <= x ; i++)
    {
        ll f; cin >> f;
        if(arr[f] == 0)
        {
            c++;
            arr[f]++;
        }

    }
    cin >> y;
    for(ll i = 1 ; i <= y ; i++)
    {
        ll f; cin >> f;
        if(arr[f] == 0)
        {
            c++;
            arr[f]++;
        }

    }

    if(c == n) cout <<"I become the guy.\n";
    else cout <<"Oh, my keyboard!\n";
    return 0;
}
