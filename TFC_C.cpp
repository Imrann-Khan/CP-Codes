#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

vector<char> v;


string Oddlength(string a)
{
    string b;
    b=a.substr(0,a.size()-1);
    reverse(b.begin(),b.end());
    a+=b;
    return a;
}


signed main()
{
    fast
    ll t; cin>>t;
    ll c=t;
    while(t--)
    {
        string s; cin>>s;
        cout<<"Case "<<c-t<<": ";
        cout<<Oddlength(s)<<endl;;
    }
}

