#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pi 3.141592653589793238462643383279502884197
using namespace std;

const int white=-1;
const int grey=0;
const int black=1;


bool DFS(map<string, vector<string> > &edge, string s, map<string, int> &color)
{
    color[s]=grey;
    for( auto i: edge[s])
    {
        if(color[i]==grey) return false;
        if(color[i]==white and !DFS(edge,i,color)) return false;
    }
    color[s]=black;
    return true;
}


bool isDrunk(map<string, vector<string> > &edge, map<string, int> &color)
{
    for(auto i:edge)
    {
        if(color[i.first]==white)
        {
            if(!DFS(edge,i.first,color))
                return false;
        }
    }
    return true;
}

void solve()
{
    int m;
    cin>>m;
    map<string, vector<string> > edge;
    map<string, int> color;
    for(int i=0;i<m;i++)
    {
        string u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        color[u]=white;
        color[v]=white;
    }
    if(isDrunk(edge,color))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}


signed main()
{
    fast
    int t;
    cin >> t;
    int c=1;
    while (t--)
    {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}
