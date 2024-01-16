#include<bits/stdc++.h>
using namespace std;
#define white 0
#define grey 1
#define black 2

class treee
{
    int vertices;
    vector<int>v[3000];
    vector<int>col;
    vector<int>distance[2000];
    vector<int>disarray;
    vector<int>parent;
    vector<int>diss;
    int dis;
public:
    treee(int vertices)
    {
        this->vertices=vertices;
        parent.push_back(-1);
        dis=0;
        for(int i=0;i<vertices;i++)
        {
            col.push_back(0);
        }
    }
    void add_tree()
    {
        int a,b,c;
        for(int i=0;i<vertices-1;i++)
        {
            cin>>a>>b>>c;
            v[a].push_back(b);
            distance[a].push_back(c);
        }
    }
    void dfs()
    {
        for(int i=0;i<vertices;i++)
        {
            dfs_vis(i);
        }
    }
    void dfs_vis(int i)
    {
        col[i]=grey;
        distance[i]+=distance[i];
        for(int j=0;j<v[i].size();j++)
        {
            if(col[v[i][j]]==white)
            {
                parent[v[i][j]]=i;
                dfs_vis(v[i][j]);
            }
        }
        distance[i]+=distance[i];
        disarray.push_back(distance[i]);
        col[i]=black;
    }
    void print_max_distance()
    {
        for(int k=0;k<vertices;k++)
        {
            for(int i=0;i<disarray.size();i++)
            {
                for(int j=i+1;j<disarray.size()-1;j++)
                {
                    if(disarray[i]<disarray[j])
                        {
                        swap(disarray[i],disarray[j]);
                        }
                }
                diss[k]=disarray[0];
            }
        }
        for(int i=0;i<diss.size();i++)
            {
                for(int j=i+1;j<disarray.size()-1;j++)
                {
                    if(disarray[i]<disarray[j])
                        {
                        swap(disarray[i],disarray[j]);
                        }
                }
            }
            cout<<diss[0];
        }
};
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        treee tr(q);
        tr.add_tree();
        tr.dfs();
        tr.print_max_distance();
        cout<<endl;
    }
    return 0;
}
