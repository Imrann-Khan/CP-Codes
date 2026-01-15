#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repl(i, a, b) for (ll i = a; i <= b; i++)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pi 3.141592653589793238462643383279502884197
using namespace std;

const ll MOD = 1e9 + 7;
const int N = 1e7 + 1;
bool prime[1121];
ll dp[1121][15][200];
vector<int> pr;

void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= 1120; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= 1120; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= 1120; p++)
        if (prime[p])
            pr.push_back(p);
}


int main()
{
    fast
    SieveOfEratosthenes();
    int n,k;
    while(cin>>n>>k, n||k){
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                for(int b=0;b<=pr.size();b++){
                    if(i==0 and j==0) dp[i][j][b]=1;
                    else{
                        dp[i][j][b]=dp[i][j][b-1];
                        if(j>0 and i-pr[b-1]>=0) dp[i][j][b]+=dp[i-pr[b-1]][j-1][b-1];
                    }
                }
            }
        }
        cout<<dp[n][k][pr.size()]<<endl;
    }
    return 0;
}
