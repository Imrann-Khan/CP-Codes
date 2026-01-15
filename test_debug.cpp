#include <bits/stdc++.h>
using namespace std;
int main(){
    int maxTime=200, w=4, points=3;
    vector<long long> gold = {5,1,2};
    vector<long long> wt = {120,120,84};
    
    vector<vector<long long>> dp(points+1, vector<long long>(maxTime+1, 0));
    
    for(int i=0;i<=points;i++){
        for(int j=0;j<=maxTime;j++){
            if(i==0 or j==0){
                dp[i][j]=0;
                continue;
            }
            if(wt[i-1] <= j){
                dp[i][j] = max(dp[i-1][j-wt[i-1]] + gold[i-1], dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    
    cout << "DP[3][200] = " << dp[3][200] << endl;
    cout << "DP[3][120] = " << dp[3][120] << endl;
    cout << "DP[2][200] = " << dp[2][200] << endl;
}
