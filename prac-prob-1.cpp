#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<string,vector<string>>adj_list;
    map<string,int>level;
    map<string,string>parent;
    map<string,int>visited;
    for(int i=0;i<n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        adj_list[s1].push_back(s2);
        level[s1]=0;
        level[s2]=0;
        visited[s1]=0;
        visited[s2]=0;
        parent[s1];
        parent[s2];
    }
    string root="C:";
    level[root]=0;
    parent[root]="";
    visited[root]=1;
    queue<string>q;
    q.push(root);
    map<string,vector<string>>::iterator it;
    while(!q.empty())
    {
        string s=q.front();
        q.pop();
        for(it=adj_list.begin();it!=adj_list.end();it++)
        {
            if(it->first==s)
            {
                vector<string>v=it->second;
                for(auto i=v.begin();i!=v.end()&& visited[*i]==0;i++)
                {
                    string s2=*i;
                    q.push(s2);
                    visited[s2]=1;
                    level[s2]=level[s]+1;
                    parent[s2]=s;
                }
            }
        }
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string test;
        cin>>test;
        string temp=test;
        string ans;
        ans;
        while(parent[temp]!="")
        {
            ans="\\\\"+temp+ans;
            temp=parent[temp];
        }
        if(ans=="")
        {
            cout<<"File not found\n-1"<<endl;

        }
        else
        {
            ans="C:"+ans;
            cout<<ans<<endl;
            cout<<(level[test])*2<<endl;
        }
    }
        ///To print adj list
//    for(auto it=adj_list.begin();it!=adj_list.end();it++)
//    {
//        cout<<it->first<<" ";
//        vector<string>v=it->second;
//        for(auto i=v.begin();i!=v.end();i++)
//        {
//            cout<<*i<<" ";
//        }
//        cout<<endl;
//    }
    /// end
    ///to print parent
//    for(auto it=parent.begin();it!=parent.end();it++)
//    {
//        cout<<it->first<<" "<<it->second<<endl;
//    }
//    cout<<endl;
    ///end
    ///to print level
//    for(auto it=level.begin();it!=level.end();it++)
//    {
//        cout<<it->first<<" "<<it->second<<endl;
//    }
    ///end

    return 0;
}
