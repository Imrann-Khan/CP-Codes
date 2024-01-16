#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

const int INF = INT_MAX;

// Structure to represent an edge
struct Edge {
    int to, weight;
};

// Function to find the minimum spanning tree using Prim's algorithm
vector<Edge> primMST(vector<vector<Edge>>& graph, int startVertex) {
    int n = graph.size();
    vector<bool> included(n, false);
    vector<Edge> minimumSpanningTree;
    included[startVertex] = true;

    for (int i = 1; i < n; ++i) {
        Edge minEdge = { -1, INF };

        for (int v = 0; v < n; ++v) {
            if (included[v]) {
                for (const Edge& edge : graph[v]) {
                    if (!included[edge.to] && edge.weight < minEdge.weight) {
                        minEdge = edge;
                    }
                }
            }
        }

        if (minEdge.to != -1) {
            minimumSpanningTree.push_back(minEdge);
            included[minEdge.to] = true;
        }
    }

    return minimumSpanningTree;
}

int main() {
    int n, m; // Number of vertices and edges
    cin >> n >> m;
    vector<vector<Edge>> graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w; // Edge from u to v with weight w
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    int startVertex; // Starting vertex for Prim's algorithm
    cin >> startVertex;

    vector<Edge> minimumSpanningTree = primMST(graph, startVertex);
    int total=0;
    cout << "Minimum Spanning Tree Edges:" << endl;
    for (const Edge& edge : minimumSpanningTree) {
        cout << edge.to << " - " << edge.weight << " -> " << edge.to << endl;
        total+=edge.to;
    }
    cout<<total;

    return 0;
}