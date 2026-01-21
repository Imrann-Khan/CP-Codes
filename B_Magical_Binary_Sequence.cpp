#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> blocks;
    int last_val = -1; 

    for (int i = 0; i < n; i += 2) {
        if (s[i] != s[i+1]) {
            int val1 = s[i] - '0';
            int val2 = s[i+1] - '0';
            
            if (last_val == -1) {
                blocks.push_back(i + 1);
                last_val = val1;
            } 
            else {
                if (val1 != last_val) {
                    blocks.push_back(i + 1);
                    last_val = val1;
                } 
                else {
                    blocks.push_back(i + 2);
                    last_val = val2;
                }
            }
        }
    }

    cout << blocks.size() << endl;
    for (size_t i = 0; i < blocks.size(); ++i) {
        cout << blocks[i] << (i == blocks.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}