#include <bits/stdc++.h>
#define ll long long int
#define fast ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    fast;
    ll tc;
    cin >> tc;
    
    while (tc--)
    {
        ll n,pr=0;
        cin >> n;
        map<pair<ll,ll>,ll> m;
        map<pair<ll,ll>,ll>::iterator it1;
        map<pair<ll,ll>,ll>::iterator it2;
        ll cnt=0;
        for (ll i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            m[{x,i}] = y; 
            cnt+=y;
        }
        it1=m.begin();
        it2=m.end();
        it2--;
        ll trade=cnt/2;
        ll i=0;
        ll a=trade;
        ll ans=0;
        while(i<trade)
        {
            if(a>it2->second) 
            {
                pr+=(it2->first.first*it2->second);
                i+=it2->second;
                a-=it2->second;
                it2->second=0;
            }
            else 
            {
                pr+=(it2->first.first*a);
                it2->second-=a;
                i+=a;
                a=0;
            }
            it2--;
        }

        /*for(it2=m.begin();it2!=m.end();it2++)
        {
            cout<<it2->first.first<<" "<<it2->second<<endl;
        }*/

        it1=m.begin();
        ll bpr=0;
        i=0;
        a=trade;
        while(i<trade)
        {
            if(it1->second<a)
            { 
                bpr+=(it1->first.first*it1->second);
                i+=it1->second;
                a-=it1->second;
                it1++;
            }
            else
            {
                bpr+=(it1->first.first*a);
                i+=a;
                a=0;
                it1++;
            }
        }
        //cout<<pr<<" "<<bpr<<endl;
        cout << (pr-bpr) << endl;
        m.clear();
    }
    
    return 0;
}



/*
3
4
10 2
30 7
20 4
50 1
2
1 100
1 1000
3
100 2
50 3
30 1
*/