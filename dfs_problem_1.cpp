#include<bits/stdc++.h>
#define white 0
#define grey 1
#define black 2
#define endl "\n"
using namespace std;

class graph
{
    int vertices;
    int edges;
    int time;
    vector<int>v[100];
    vector<int>parent;
    vector<int>dis_time;
    vector<int>fin_time;
    vector<int>trav;
    vector<int>col;
public:
    graph(int vertices,int edges)
    {
        this->vertices=vertices;
        this->edges=edges;
        time=0;
        for(int i=0;i<vertices;i++)
        {
            col.push_back(0);
            dis_time.push_back(0);
            fin_time.push_back(0);
            parent.push_back(-1);
        }
    }
    void add_graph()
    {
        int n1,n2;
        for(int i=0;i<edges;i++)
        {
            cout<<"Enter edges: ";
            cin>>n1>>n2;
            v[n1].push_back(n2);
        }
    }
    void dfs()
    {
        for(int i=0;i<vertices;i++)
        {
           if(col[i]==white)
           {
            dfs_vis(i);
           }
        }
    }
    void dfs_vis(int i)
    {
        time++;
        dis_time[i]=time;
        col[i]=grey;
        for(int j=0;j<v[i].size();j++)
        {
            if(col[v[i][j]]==white)
            {
                parent[v[i][j]]=i;
                dfs_vis(v[i][j]);
            }
        }
        time++;
        fin_time[i]=time;
        col[i]=black;
        trav.push_back(i);
    }
    void print_trav()
    {
        cout<<"dfs trav: ";
        for(int i=0;i<trav.size();i++)
        {
            cout<<"-> "<<trav[i];
        }
    }
    void print_graph()
    {
        for(int i=0;i<vertices;i++)
        {
            cout<<"adjacents of node "<<i<<"are: ";
            for(int j=0;j<v[i].size();j++)
            {
                cout<<"-> "<<v[i][j];
            }
            cout<<endl;
        }
    }
    void print_discovery_and_finish_time()
    {
        for(int i=0;i<dis_time.size();i++)
        {
            cout<<"disovery and finish time of "<<i<<" are: ";
            cout<<dis_time[i]<<" "<<fin_time[i]<<endl;
        }
        cout<<endl;
    }
    void par(int p)
    {
        cout<<"Parent of node "<< p <<" is: "<< parent[p];
    }
};
int main()
{
    int v,e,p;
    cin >> v >> e;
    graph g(v,e);
    g.add_graph();
    g.print_graph();
    g.dfs();
    g.print_trav();
    g.print_discovery_and_finish_time();
    cout<<"Enter node: ";
    cin>>p;
    g.par(p);
    return 0;
}