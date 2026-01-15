#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;



void solve()
{
    ll n;
    cin>>n;
    ll x=ceil(log2(n));
    ll z=floor(log2(n));
    vector<ll> v1,v2;
    ll q=pow(2,z);
    ll y=pow(2,x);
    //cout<<y<<" "<<q<<endl;
    if(n==y)
    {
        cout<<x+1<<endl;
        for(ll i=0;i<=x;i++)
        {
            if(i!=x) cout<<0<<" ";
            else cout<<1;
        }
        cout<<endl;
        return;
    }
    {
        ll temp=y-n;
        unordered_set<ll> s;
        while(temp!=0)
        {
            ll f=floor(log2(temp));
            s.insert(f);
            temp-=pow(2,f);
        }
        for(ll i=0;i<=x;i++)
        {
            if(i==x) v1.push_back(1);
            else
            {
                if(s.find(i)!=s.end()) v1.push_back(-1);
                else v1.push_back(0);
            }
        }
        s.clear();
    }
    {
        ll temp=n-q;
        unordered_set<ll> s;
        while(temp!=0)
        {
            ll f=floor(log2(temp));
            s.insert(f);
            temp-=pow(2,f);
        }
        for(ll i=0;i<=z;i++)
        {
            if(i==z) v2.push_back(1);
            else
            {
                if(s.find(i)!=s.end()) v2.push_back(1);
                else v2.push_back(0);
            }
        }
    }
    bool p=false;
    for(ll i=1;i<v1.size();i++)
    {
        if((v1[i]==1 and v1[i-1]==1) or (v1[i-1]==-1 and v1[i]==-1))
        {
            p=true;
            break;
        }
    }
    bool r=false;
    for(ll i=1;i<v2.size();i++)
    {
        if((v2[i]==1 and v2[i-1]==1) or (v2[i-1]==-1 and v2[i]==-1))
        {
            r=true;
            break;
        }
    }
    if(!p)
    {
        cout<<v1.size()<<endl;
        for(ll i=0;i<v1.size();i++)
        {
            cout<<v1[i]<<" ";
        }
        cout<<endl;
    }
    else if(!r)
    {
        cout<<v2.size()<<endl;
        for(ll i=0;i<v2.size();i++)
        {
            cout<<v2[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        if(v2[v2.size()-1]==1 and v2[v2.size()-2]==1)
        {
            cout<<v1.size()<<endl;
            for(ll i=1;i<v1.size()-1;i++)
            {
                if(v1[i]==v1[i-1] and v1[i]==-1)
                {
                    if(v2[i+1]==0)
                    {
                        v1[i+1]=-1;
                        v1[i]=0;
                        v1[i-1]=1;
                    }
                    else
                    {
                        v1[i+1]=0;
                        v1[i]=0;
                        v1[i-1]=1;
                    }
                }
            }
            for(ll i=0;i<v1.size();i++) cout<<v1[i]<<" ";
        }
        
        else
        {
            
        cout<<v2.size()<<endl;
            for(ll i=1;i<v2.size()-2;i++)
            {
                if(v2[i]==v2[i-1] and v2[i]==1)
                {
                    if(v2[i+1]==0)
                    {
                        v2[i+1]=1;
                        v2[i]=0;
                        v2[i-1]=-1;
                    }
                    else
                    {
                        v2[i+1]=0;
                        v2[i+2]=1;
                        v2[i]=0;
                        v2[i-1]=-1;
                    }
                }
            }
            for(ll i=0;i<v2.size();i++) cout<<v2[i]<<" ";
        }
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