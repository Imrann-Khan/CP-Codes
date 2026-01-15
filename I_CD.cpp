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

int ans(vector<int> &t, int sum, int i,int mx,vector<int> &soln)
{
    if(i==t.size()) return sum;
    if(sum+t[i]>mx)
    {
        return ans(t, sum, i+1, mx,soln);
    }
    vector<int> take = soln;
    take.push_back(t[i]);
    int take_sum = ans(t, sum + t[i], i + 1, mx, take);
    vector<int> skip = soln;
    int skip_sum = ans(t, sum, i + 1, mx, skip);
    if (take_sum > skip_sum) 
    {
        soln = take;
        return take_sum;
    } 
    else 
    {
        soln = skip;
        return skip_sum;
    }
}


void solve(int s, int n, vector<int> &t)
{
    vector<int> soln;
    int sum = ans(t,0,0,s,soln);
    rep(i,0,(int)soln.size()-1) cout<<soln[i]<<" ";
    cout<<"sum:"<<sum<<endl;
}

signed main()
{
    fast

        //ll t=1;
    //cin >> t;
    int s,n;
    while (cin>>s>>n)
    {
        vector<int> t(n);
        rep(i,0,n-1) cin>>t[i];
        solve(s,n,t);
    }
}
