#include<bits/stdc++.h>

using namespace std;

int dp[1000][1000];

int mcm(vector<int> &a, int i, int j){
    if(i+1==j) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];

    int res = INT_MAX;

    for(int k=i+1;k<j;k++){
        res = min(res,mcm(a,i,k)+a[i]*a[k]*a[j]+mcm(a,k,j));
    }
    return dp[i][j]=res;
}

signed main(){
    memset(dp, -1, sizeof(dp));
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<mcm(a, 0, n-1)<<endl;
}