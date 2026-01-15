#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main()
{
    fast
    ll t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        stack<char> st;
        bool f=false;
        ll cnt=0;
        for(ll i=0;i<s.size();i++)
        {
            if(s[i]=='(' or s[i]=='{' or s[i]=='[') 
            {
                st.push(s[i]);
                cnt++;
            }
            else if(s[i]==')')
            {
                if(st.empty())
                {
                    f=true;
                    break;
                }
                char x=st.top();
                st.pop();
                if(x=='(') continue;
                else
                {
                    f=true;
                    break;
                }
            }
            else if(s[i]=='}')
            {
                if(st.empty())
                {
                    f=true;
                    break;
                }
                char x=st.top();
                st.pop();
                if(x=='{') continue;
                else
                {
                    f=true;
                    break;
                }
            }
            else if(s[i]==']')
            {
                if(st.empty())
                {
                    f=true;
                    break;
                }
                char x=st.top();
                st.pop();
                if(x=='[') continue;
                else
                {
                    f=true;
                    break;
                }
            }
        }
        if(f) cout<<"NO\n";
        else cout<<"YES\n";
    }
}