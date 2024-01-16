#include<bits/stdc++.h>
using namespace std;

map<int,vector<int> >mp;
int visited[100],par[100],dis[100];

void bfs(int s)
{
    queue<int> q;
    visited[s]=1;
    par[s]=-1;
    dis[s]=0;
    q.push(s);
    while(q.size()!=0)
    {
        int c=q.front();
        q.pop();
        for(int i=0;i<mp[c].size();i++)
        {
            if(visited[mp[c][i]]==0)
            {
                int f=mp[c][i];
                par[f]=c;
                dis[f]=dis[c]+1;
                visited[f]=1;
                q.push(f);
            }
        }
    }
}
void path(int k)
{
    if(visited[k]==0 && k>0)
    {
        cout<<"vertex do not exist!";
        return;
    }
    else
    {
        if(k==-1)   return;
        path(par[k]);
        cout<<k<<" ";
    }
}


int main()
{
    int v,e,s;
    cin>>v>>e;

    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    cin>>s;
    bfs(s);
    while(1){
        cout<<"Enter the vertex whose shortest path and shortest distance from "<<s<<" to be displayed: ";
        int x;
        cin>>x;
        cout<<"Shortest distance from "<<s<<" to "<<x<<" is: "<<dis[x]<<endl;
        cout<<"Shortest path from "<<s<<" to "<<x<<" is: ";
        path(x);
        cout<<endl;
    }
    return 0;
}
