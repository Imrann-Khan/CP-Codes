#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

// কো-অর্ডিনেট রাখার জন্য স্ট্রাকচার
struct Point {
    int x, y;
};

// ম্যানহাটান ডিসটেন্স বের করার ফাংশন (Walking Cost)
int getDist(Point p1, Point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

// ওয়ার্মহোলের ডেটা
struct Wormhole {
    Point start, end;
    int cost;
};

// Dijkstra চালানোর জন্য পেয়ার (Distance, NodeIndex)
// priority_queue ডিফল্টভাবে Max Heap হয়, তাই উল্টো করে Min Heap বানাতে হবে
typedef pair<int, int> pii; 

int solve() {
    int N;
    Point src, dest;
    
    cin >> N;
    cin >> src.x >> src.y >> dest.x >> dest.y;

    vector<Wormhole> holes(N);
    for(int i = 0; i < N; i++) {
        cin >> holes[i].start.x >> holes[i].start.y 
            >> holes[i].end.x >> holes[i].end.y 
            >> holes[i].cost;
    }

    // ১. সব পয়েন্টকে নোড হিসেবে একটি লিস্টে সাজাই
    vector<Point> nodes;
    nodes.push_back(src);      // Index 0
    nodes.push_back(dest);     // Index 1
    
    for(int i = 0; i < N; i++) {
        nodes.push_back(holes[i].start); // Index 2, 4, ...
        nodes.push_back(holes[i].end);   // Index 3, 5, ...
    }

    int totalNodes = nodes.size();

    // ২. গ্রাফ (Adjacency Matrix) তৈরি করি
    // adj[i][j] = i থেকে j তে যাওয়ার খরচ
    vector<vector<int>> adj(totalNodes, vector<int>(totalNodes));

    // প্রথমে সব কানেকশনকে 'Walking Distance' দিয়ে পূরণ করি
    for(int i = 0; i < totalNodes; i++) {
        for(int j = 0; j < totalNodes; j++) {
            adj[i][j] = getDist(nodes[i], nodes[j]);
        }
    }

    // এবার ওয়ার্মহোলগুলোর শর্টকাট আপডেট করি
    for(int i = 0; i < N; i++) {
        int u = 2 + 2 * i;     // Wormhole Start Node Index
        int v = 2 + 2 * i + 1; // Wormhole End Node Index
        int wCost = holes[i].cost;

        // চেক করি: ওয়ার্মহোল দিয়ে যাওয়া কি হেঁটে যাওয়ার চেয়ে সস্তা?
        // দ্বিমুখী রাস্তা (Bi-directional)
        adj[u][v] = min(adj[u][v], wCost);
        adj[v][u] = min(adj[v][u], wCost);
    }

    // ৩. Priority Queue দিয়ে Dijkstra শুরু
    // min-heap: {cost, u}
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    vector<int> dist(totalNodes, INT_MAX);

    // Source (Node 0) দিয়ে শুরু
    dist[0] = 0;
    pq.push({0, 0}); // {cost, node_index}

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // যদি বর্তমান খরচ আগের জানা খরচের চেয়ে বেশি হয়, তবে স্কিপ (Outdated)
        if (d > dist[u]) continue;

        // Destination (Node 1) এ পৌঁছে গেলে ব্রেক করতে পারি (অপশনাল)
        if (u == 1) return d;

        // সব নোড চেক করি (যেহেতু সবাই সবার সাথে কানেক্টেড)
        for(int v = 0; v < totalNodes; v++) {
            int weight = adj[u][v];

            // Relaxation Step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[1]; // Destination এর মিনিমাম খরচ
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cout << solve() << endl;
    }
    return 0;
}