#include <bits/stdc++.h>
#define ll long long int
#define fast ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

ll fb[1000000];
ll k=0;
ll cnt=0;
vector<pair<ll,ll>> m;
vector<pair<ll,ll>> mm;
void fibonacci(ll n) {
    ll a=1;
    ll b=1;
    mm.push_back(make_pair(1,k++));
    mm.push_back(make_pair(1,k++));
    for(ll i=2;i<n;i++)
    {
        ll temp=a+b;
        if(temp%2==0)
        {
            fb[i]=1;
            m.push_back(make_pair(i,i));
            cnt++;
        }
        else
        {
            fb[i]=0;
            mm.push_back(make_pair(i,k++));
        }
        a=b;
        b=temp;
    }
}

int main() {
    fast
    fb[0]=0;
    fb[1]=0;
    ll n;
    cin>>n;
    fibonacci(n);
    ll res=0;
    for (ll i=0;i<m.size();i++) {
        res+=(n-1-m[i].first);
    }
    ll temp=-1;
    if(cnt>1) temp=m[0].first;
    ll f=0;
    for(ll i=0;i<mm.size();i++)
    {
        if(mm[i].first>temp and temp!=-1)
        {
            f++;
            temp=m[f].first;
            cnt--;
            res+=cnt;
        }
        else
        {
            res+=cnt;
        }
    }
    cout<<res<<endl;
    return 0;
}
