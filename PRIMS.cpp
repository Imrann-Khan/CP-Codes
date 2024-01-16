#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
vector<vector<pair<int,int>>> adj[20];

// Function to find sum of weights of edges of the Minimum Spanning Tree.
/*int spanningTree(int V, int E)
{ 

	
	// Create a priority queue to store edges with their weights
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	
	// Create a visited array to keep track of visited vertices
	vector<bool> visited(V, false);
	
	// Variable to store the result (sum of edge weights)
	int res = 0;
	
	// Start with vertex 0
	pq.push({0, 0});
	
	// Perform Prim's algorithm to find the Minimum Spanning Tree
	while(!pq.empty()){
		auto p = pq.top();
		pq.pop();
		
		int wt = p.first; // Weight of the edge
		int u = p.second; // Vertex connected to the edge
		
		if(visited[u] == true){
			continue; // Skip if the vertex is already visited
		}
		
		res += wt; // Add the edge weight to the result
		visited[u] = true; // Mark the vertex as visited
		
		// Explore the adjacent vertices
		for(auto v : adj[u]){
			// v[0] represents the vertex and v[1] represents the edge weight
			if(visited[v[0]] == false){
				pq.push({v[1], v[0]}); // Add the adjacent edge to the priority queue
			}
		}
	}
	
	return res; // Return the sum of edge weights of the Minimum Spanning Tree
}*/

int main()
{
    int n; cin>>n;
    int e; cin>>e;
    // Fill the adjacency list with edges and their weights
	for (int i = 0; i < e; i++) {
		int u ;
		int v ;
		int wt ;
        cin>>u>>v>>wt;
		adj[u].push_back({v, wt});
		adj[v].push_back({u, wt});
	}

    for (auto i : adj) {
        cout <<  << " - " << edge.weight << " -> " << edge.to << endl;
    }

	// Function call
	//cout << spanningTree(3, 3, graph) << endl;

	return 0;
}
