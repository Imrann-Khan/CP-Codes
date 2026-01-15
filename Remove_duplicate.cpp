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

void removeDuplicates(vector<int> &nums)
{
    int sz = nums.size();
    int k = 0;
    int cnt = 0;
    for (int i = 0; i < sz; i++)
    {
        if (i != sz - 1 and nums[i] == nums[i + 1])
            cnt++;
        else
        {
            cnt = 0;
        }
        if (cnt < 2)
            nums[k++] = nums[i];
    }
    cout << k << endl;
    for (int i = 0; i < k; i++)
        cout << nums[i] << " ";
    cout << endl;
}

signed main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    removeDuplicates(nums);
}
