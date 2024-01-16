#include <iostream>
using namespace std;

int n;
int row[100], col[100];
int d[100];
int m[100][100];
int s[100][100];

int MCM(int i, int j) {
    if (i == j) {
        return 0;
    }
    if (m[i][j] != 99999) {
        return m[i][j];
    }

    for (int k = i; k < j; k++) {
        int cost = MCM(i, k) + MCM(k + 1, j) + d[i - 1] * d[k] * d[j];
        if (cost < m[i][j]) {
            m[i][j] = cost;
            s[i][j] = k;
        }
    }

    return m[i][j];
}

void printOptimalOrder(int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalOrder(i, s[i][j]);
        printOptimalOrder(s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> row[i] >> col[i];
        d[i] = row[i];
        d[i + 1] = col[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            m[i][j] = 99999;
            s[i][j] = -1;
        }
    }

    int minCost = MCM(1, n);
    cout << "Minimum Cost: " << minCost << endl;

    cout << "Optimal Order of Multiplication: ";
    printOptimalOrder(1, n);
    cout << endl;

    // for(int i=0;i<=n;i++){
    //         for(int j=0;j<=n;j++){
    //             cout<<s[i][j]<<" ";
    //         }
    //         cout<<endl;
    // }

    // for(int i=0;i<=n;i++){
    //         for(int j=0;j<=n;j++){
    //             cout<<m[i][j]<<" ";
    //         }
    //         cout<<endl;
    // }
    return 0;
}
