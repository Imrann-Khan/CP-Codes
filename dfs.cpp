#include<bits/stdc++.h>
#define white 0
#define grey 1
#define black 2
using namespace std;

class graph{
    vector<int>v[100];         ///to store all the childs of each vertices
    vector<int>colors;         ///to keep track of discovered nodes
    vector<int>discovery_time; ///time when node is discovered or turned grey
    vector<int>finish_time;    ///time when node is traversed or turned black
    vector<int>parent;         ///storing parent of each vertices
    vector<int>dfs_traverse;   ///storing the sequence of traversed vertices
    int no_of_vertices, no_of_edges, time;

public:
    graph(int vertices, int edges)
    {
        no_of_edges = edges;
        no_of_vertices = vertices;
        time = 0;
        for(int i=0; i<no_of_vertices; i++)
        {
            colors.push_back(white);
            discovery_time.push_back(0);
            finish_time.push_back(0);
            parent.push_back(-1);
        }
    }
    void add_graph()
    {
        int n1, n2;
        for(int i=0; i<no_of_edges; i++)
        {
            cin >> n1 >> n2;
            v[n1].push_back(n2);
        }
    }
    void print_graph()
    {
        for(int i=0; i<no_of_vertices; i++)
        {
            cout << "Adjacent nodes of " << i;
            for(int j=0; j<v[i].size(); j++)
                cout << " -> " << v[i][j];
            cout << endl;
        }
    }
    void dfs()
    {
        for(int i=0; i<no_of_vertices; i++)
        {
            if(colors[i] == white)
            {
                dfs_visit(i);
            }
        }


    }
    void dfs_visit(int i)
    {
        colors[i] = grey;
        time++;
        discovery_time[i] = time;
        for(int j=0; j<v[i].size(); j++)
        {
            if(colors[v[i][j]] == white)
            {
                parent[v[i][j]] = i;
                dfs_visit(v[i][j]);
            }
        }
        colors[i] = black;
        time++;
        finish_time[i] = time;
        dfs_traverse.push_back(i);
    }

    void print_parent()
    {
        for(int i=0; i<no_of_vertices; i++)
        {
            cout << "parent of vertice " << i;
            for(int j=parent[i]; j != -1; j = parent[j])
            {
                cout << "->" << j;
            }
            cout << endl;
        }

    }

    void print_dfs()
    {
        cout << "Traversal of dfs ";
        for(int i=0; i<dfs_traverse.size(); i++)
            cout << " -> " << dfs_traverse[i];
    }
};

int main()
{
    int v,e;
    cin >> v >> e;
    graph g(v,e);
    g.add_graph();
    g.print_graph();
    g.dfs();
    g.print_parent();
    g.print_dfs();
}
