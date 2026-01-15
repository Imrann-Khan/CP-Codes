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

void depth(vector<int> &a, int l, int r, vector<int> &d, int dep)
{
    if(l>r) return;
    if(l==r)
    {
        d[a[l]]=dep;
        return;
    }
    int mid=-1;
    int mx=-1;
    rep(i,l,r)
    {
        if(a[i]>mx)
        {
            mx=a[i];
            mid=i;
        }
    }
    d[a[mid]]=dep;
    depth(a,l,mid-1,d,dep+1);
    depth(a,mid+1,r,d,dep+1);
}

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,0,n-1) cin>>a[i];
    vector<int> d(n+1);
    depth(a,0,n-1,d,0);
    rep(i,0,n-1) cout<<d[a[i]]<<" ";
    cout<<endl;
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
