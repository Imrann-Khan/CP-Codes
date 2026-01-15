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

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;

    if(count(str.begin(),str.end(),'0')==n){
        cout<<-1<<endl;
        return;
    }
    
    if(str.size()==1 and str[0]=='1'){
        cout<<1<<endl;
        return;
    }
    if(str.size()==1 and str[0]=='0'){
        cout<<0<<endl;
        return;
    }
    int ans=0;
    for(int i=1;i<str.size();i+=2){
        if(i-1==0){
            if(str[i-1]=='1'){
                if(str[i]=='0'){
                    ans++;
                    str[i-1]=(str[i-1]=='0') ? '1':'0';
                    str[i]=(str[i]=='0') ? '1':'0';
                    if(i<n-1) str[i+1]=(str[i+1]=='0') ? '1':'0';
                }
            }
            else{
                if(str[i]=='0'){
                    ans++;
                    if(i<n-1){
                        i++;
                        str[i-1]=(str[i-1]=='0') ? '1':'0';
                        str[i]=(str[i]=='0') ? '1':'0';
                        if(i<n-1) str[i+1]=(str[i+1]=='0') ? '1':'0';
                    }
                }
            }
        }
        if(str[i]==str[i-1]){
            ans++;
            str[i-1]=(str[i-1]=='0') ? '1':'0';
            str[i]=(str[i]=='0') ? '1':'0';
            if(i<n-1) str[i+1]=(str[i+1]=='0') ? '1':'0';
        }
    }
    cout<<ans<<endl;
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
