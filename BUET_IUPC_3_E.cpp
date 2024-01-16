#include <bits/stdc++.h>
#define ll long long int
#define fast ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    fast
    ll H, W;
    cin >> H >> W;

    ll maxMinArea = 0;

    for (ll verticalLine = 1; verticalLine < W; ++verticalLine) {
        ll S1 = verticalLine * H;
        ll remainingWidth = W - verticalLine;
        ll horizontalLine = H / 2;
        ll S2 = horizontalLine * remainingWidth;
        ll S3 = (H - horizontalLine) * remainingWidth;
        ll minArea = min(min(S1, S2), S3);
        maxMinArea = max(maxMinArea, minArea);
    }
    cout <<maxMinArea<<endl;

    return 0;
}
