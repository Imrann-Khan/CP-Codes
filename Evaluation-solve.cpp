#include<bits/stdc++.h>
using namespace std;

map<int,int> vis,dis,par;

void BFS(int x,int y)
{
    queue <int> q;
    q.push(x);
    par[x]=-1;
    dis[x]=0;
    vis[x]=1;

    while(!q.empty())
    {
        int senior=q.front();
        q.pop();
        for(int i=1;i<=2;i++)
        {
            int junior;
            if(i==1) junior= senior -1;
            else junior=senior*2;

            if(junior==0) continue;
            if(vis[junior]==0)
            {
                q.push(junior);
                dis[junior]=dis[senior] +1;
                par[junior]=senior;
                vis[junior]=1;

                if(y== junior) return;
            }
        }
    }
}


void path(int k)
{
    if(k==-1) return;
    path(par[k]);
    cout << k << "->";
}


int main()
{
    int a,b;
    cin >> a >> b;
    BFS(a,b);
    cout << dis[b] << "\n";
    path(b);
    return 0;
}
