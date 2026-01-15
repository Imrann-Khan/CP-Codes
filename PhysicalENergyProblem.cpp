#include <bits/stdc++.h>
using namespace std;

int cost[] = {4, 5, 2, 3, 6};
int time_val[] = {200, 210, 230, 235, 215};
int dp[1005][3005]; // Max Distance 1000, Max Energy 3000 ধরে নিলাম

// Function: Minimum time to cover distance 'd' with energy 'h'
int solve(int d, int h)
{
    // Base Case 1: যদি দূরত্ব শেষ হয়ে যায়, সময় ০
    if (d == 0) return 0;
    
    // Base Case 2: যদি এনার্জি শেষ হয়ে যায় কিন্তু দূরত্ব বাকি থাকে (অসম্ভব)
    if (h <= 0) return 1e9; 

    // Memoization Check
    if (dp[d][h] != -1) return dp[d][h];

    int min_time = 1e9; // অসীম মান দিয়ে শুরু

    // ৫টি স্পিড অপশন লুপ চালিয়ে চেক করা
    for (int i = 0; i < 5; i++)
    {
        if (h >= cost[i]) // যদি এই স্পিড নেওয়ার মতো এনার্জি থাকে
        {
            // ১ কিমি কমালাম, কস্ট কমালাম, এবং টাইম যোগ করলাম
            int val = solve(d - 1, h - cost[i]);
            
            if (val != 1e9) { // যদি বাকি পথ ভ্যালিড হয়
                min_time = min(min_time, val + time_val[i]);
            }
        }
    }

    return dp[d][h] = min_time;
}

int main()
{
    int h, d;
    cin >> h >> d;

    // DP টেবিল -1 দিয়ে রিসেট
    // ইনপুট সাইজ অনুযায়ী অ্যারে সাইজ এডজাস্ট করে নিও
    memset(dp, -1, sizeof(dp));

    int result = solve(d, h);

    if (result >= 1e9)
        cout << "-1" << endl; // ইম্পসিবল কেস
    else
        cout << result << endl;

    return 0;
}