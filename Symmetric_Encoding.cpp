#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


ll BS(ll low, ll high, vector<char> &v, char c)
{
    ll mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (v[mid] == c)
            return mid;
        if (v[mid] < c)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return mid;
}

void solve()
{
    ll n; cin>>n;
    string s; cin>>s;
    set<char> st;
    for(ll i=0;i<n;i++)
    {
        st.insert(s[i]);
    }
    vector<char> v;
    vector<char> pos(500);
    for(auto it=st.begin();it!=st.end();++it)
    {
        v.push_back(*it);
    }
    // for(ll i=0;i<v.size()/2;i++)
    // {
    //     pos[v[i]]=v[n-i-1];
    //     pos[v[n-i-1]]=v[i];
    // }
    // if(v.size()%2==1) pos[v[v.size()/2+1]]=v[v.size()/2+1];
    for(ll i=0;i<n;i++)
    {
        ll indx=BS(0,v.size()-1,v,s[i]);
        indx=v.size()-indx-1;
        cout<<v[indx];
    }
    cout<<endl;
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