#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

// Grid directions (Up, Down, Left, Right)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int N; // Grid size

// BFS to fill distances from a specific start point
void bfs(int startX, int startY, const vector<vector<int>>& grid, vector<vector<int>>& distGrid) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    distGrid[startX][startY] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Check boundary, obstacle (0), and if already visited
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && grid[nx][ny] == 1 && distGrid[nx][ny] == -1) {
                distGrid[nx][ny] = distGrid[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int solve(int n, vector<vector<int>>& grid, vector<pair<int, int>> &rareElements) {
    N = n;
    

    // 1. Find all rare elements
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Assuming rare elements are marked differently or you have their coords given.
            // For this logic, let's assume specific coordinates are passed, 
            // OR logic to identify them inside the grid.
            // (Here I assume you have a list of them already)
        }
    }
    
    // Example: Let's say we identified rare elements at (r1, c1), (r2, c2)...
    // rareElements.push_back({r1, c1}); ...
    
    int K = rareElements.size();
    
    // Store distance from each rare element to every cell
    // dists[k][i][j] = distance from k-th rare element to cell (i, j)
    vector<vector<vector<int>>> allDists(K, vector<vector<int>>(N, vector<int>(N, -1)));

    // 2. Run BFS from each rare element
    for (int k = 0; k < K; k++) {
        bfs(rareElements[k].first, rareElements[k].second, grid, allDists[k]);
    }

    int minMaxDist = INT_MAX;

    // 3. Check every cell to be a potential "Research Center"
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) { // Can build here
                int currentMax = 0;
                bool possible = true;

                for (int k = 0; k < K; k++) {
                    if (allDists[k][i][j] == -1) {
                        possible = false; // Cannot reach a rare element from here
                        break;
                    }
                    currentMax = max(currentMax, allDists[k][i][j]);
                }

                if (possible) {
                    minMaxDist = min(minMaxDist, currentMax);
                }
            }
        }
    }

    return (minMaxDist == INT_MAX) ? -1 : minMaxDist;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, q;
        cin >> n >> q;
        vector<pair<int, int>> rareElements;
        while(q--){
            int x, y;
            cin >> x >> y;
            // Adjustment for 1-based indexing
            rareElements.push_back({x - 1, y - 1}); 
        }
        vector<vector<int>> grid(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
            }
        }
        cout << solve(n, grid, rareElements) << endl;
    }
}
