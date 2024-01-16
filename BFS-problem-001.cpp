#include<bits/stdc++.h>
using namespace std;

map<string,vector<string> >mp;
map<string,int> visited,dis;
map<string,string>par;

void bfs(string s)
{
    queue<string> q;
    visited[s]=1;
    par[s]="-1";
    dis[s]=0;
    q.push(s);
    while(q.size()!=0)
    {
        string c=q.front();
        q.pop();
        for(int i=0; i<mp[c].size(); i++)
        {
            string f=mp[c][i];
            if(visited[f]==0)
            {

                par[f]=c;
                dis[f]=dis[c]+1;
                visited[f]=1;
                q.push(f);
            }
        }
    }
}
void path(string k)
{
    if(visited[k]==0 && k!="-1")
    {
        cout<<"File Not Found!";
        return;
    }
    else
    {
        string sl="//";
        if(k=="-1")   return;
        path(par[k]);
        cout<<k<<sl;
    }
}


int main()
{
    int e;
    cin >> e;

    for(int i=0; i<e; i++)
    {
        string a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    string s="C:";
    bfs(s);
    int query;
    cin >> query;
    while(query--)
    {
        string x;
        cin>>x;
        path(x);
        cout <<endl<< 2*(dis[x])<<endl;
        cout<<endl;
    }
    return 0;
}

