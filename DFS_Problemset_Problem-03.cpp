#include<bits/stdc++.h>
using namespace std;
map<int , vector<int> > mp;
map< pair<int,int>, int > weight;
int mx[1000],vis[1000],dis[1000];
void reset()
{
    for(int i=0;i<1000;i++)
        vis[i]=0,dis[i]=0;
}
void all_reset()
{
    mp.clear();
    weight.clear();
    for(int i=0;i<1000;i++)
        mx[i]=0,vis[i]=0,dis[i]=0;
}
void DFS_visit(int s)
{
    vis[s]=1;
    for(int i=0;i<mp[s].size();i++)
    {
        if(vis[mp[s][i]]==0)
        {
            dis[mp[s][i]]+=(dis[s]+weight[{s,mp[s][i]}]);
            DFS_visit(mp[s][i]);
        }
    }
}
void DFS(int n)
{
    for(int i=0;i<n;i++)
    {
        DFS_visit(i);
        int m=dis[0];
        for(int j=0;j<1000;j++)
        {
            if(m<dis[j])
                m=dis[j];
        }
        mx[i]=m;
        reset();
    }
}
int main()
{
    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++)
    {
        int n,a,b,w;
        cin >> n;
        for(int i=0;i<n-1;i++)
        {
            cin >> a >> b >> w;
            mp[a].push_back(b);
            mp[b].push_back(a);
            weight[{a,b}]=w;
            weight[{b,a}]=w;
        }
        DFS(n);
        int fm=mx[0],fi=0;
        for(int i=0;i<1000;i++)
        {
            if(fm<mx[i])
                fm=mx[i],fi=i;
        }
        DFS_visit(fi);
        fm=0;
        for(int i=0;i<1000;i++)
        {
            if(fm<dis[i])
                fm=dis[i];
        }
        cout << "Case " << tc << " : " << fm << "\n";
        all_reset();
    }
    return 0;
}
/*
2
4
0 1 20
1 2 30
2 3 50
5
0 2 20
2 1 10
0 3 29
0 4 50
*/
