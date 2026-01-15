#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int cs = 0; cs < T; ++cs) {
        int capMeters;
        if (!(cin >> capMeters)) break;
        int capacity = capMeters * 100;

        vector<int> cars;
        int x;
        while (cin >> x) {
            if (x == 0) break; 
            cars.push_back(x);
        }

        int n = static_cast<int>(cars.size());
        vector<vector<char>> reachable(n + 1, vector<char>(capacity + 1, 0));
        vector<vector<char>> parent(n + 1, vector<char>(capacity + 1, -1)); // 0=port, 1=starboard

        reachable[0][0] = 1;
        int prefix = 0;
        int bestCount = 0, bestPort = 0;

        for (int i = 0; i < n; ++i) {
            int len = cars[i];
            prefix += len;
            bool any = false;

            for (int port = 0; port <= capacity; ++port) {
                if (!reachable[i][port]) continue;

                // place on starboard
                if (prefix - port <= capacity && !reachable[i + 1][port]) {
                    reachable[i + 1][port] = 1;
                    parent[i + 1][port] = 1;
                    any = true;
                }

                // place on port
                int newPort = port + len;
                if (newPort <= capacity && prefix - newPort <= capacity && !reachable[i + 1][newPort]) {
                    reachable[i + 1][newPort] = 1;
                    parent[i + 1][newPort] = 0;
                    any = true;
                }
            }

            if (!any) break;
            bestCount = i + 1;

            for (int port = 0; port <= capacity; ++port) {
                if (reachable[i + 1][port] && prefix - port <= capacity) {
                    bestPort = port;
                    break;
                }
            }
        }

        cout << bestCount << "\n";

        vector<string> place(bestCount);
        int curPort = bestPort;
        for (int i = bestCount; i >= 1; --i) {
            if (parent[i][curPort] == 0) {
                place[i - 1] = "port";
                curPort -= cars[i - 1];
            } else {
                place[i - 1] = "starboard";
            }
        }
        for (auto &s : place) cout << s << "\n";

        if (cs + 1 != T) cout << "\n";
    }
    return 0;
}
