#include<bits/stdc++.h>

using namespace std;

/// BFS
                                    ///A B C D E
///unique named vertex/// o to n-1 /// O-O-O-O-O here n=6
///or from 1 to n/// or starting from A

///edge can be bi or one directional/// graph 2 types -Directed & undirected
///undirected=(u,v)=(v,u)/// undirected  u,v)!=(v,u)
///Adjacent vertex///nearby connected vertex ///A-B or C-D
/// A  B  C  D  E
/// O->O->O->O->O
///A,B connected ; B-A not connected
///2 common graph representatives/// Adjacency Matrix(AM) & Adjacency List(AL)
/// AM: dimension n x n ///vertex represented by index
///find out adjacency of any matrix :
/// x E {0,1,2......,n-1}

/**for (int i=0;i<n;i++)
{
    if(adj[x][i]==1)
    {
        cout<<i<<" ";
    }

}**/

///find out adjacency of any list :
/// x E {0,1,2......,n-1}

/** vector<int> adj[n];
for (int i=0;i<adj[3].size();i++)
{

       cout<<adj[3][i];

}**/

/// AL:
/// n list needed
/// vector<int>v[n]; or vector<int>v[6];

/**
v[0]->1
v[1]->2,4
.
.
.
v[n]->NULL
**/

/// Representation
/// AM: cin>>n; int adj[n][n];         AM: AM: cin>>n; vector<int> adj[n];
/// cin>>e;                            cin>>e;
/// for(int i=1;i<=e;i++){             for(int i=1;i<=e;i++){
///    cin>>u>>v:  adj[u][v]=1           cin>>u>>v:    adj[u].push_back(v);
///    adj[v][u]= 1                      adj[v].push_back(u);  --->>>> for undirected
/// }                                  }
///


