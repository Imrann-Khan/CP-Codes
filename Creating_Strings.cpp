#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main()
{
    fast
    string s; cin>>s;
    sort(s.begin(),s.end());
    ll p=s.size()*(s.size()-1);
    cout<<p<<endl<<s<<endl;
    for(ll i=s.size()-1;i>=0;i--)
    {
        for(ll j=i;j>0;j--)
        {
            swap(s[j],s[j-1]);
            cout<<s<<endl;
        }
    }
}