#include <bits/stdc++.h>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
typedef long long ll;

// C++ code to print all possible
// subsequences for given array using
// recursion
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vt;
int l;
void printSubsequences(int arr[], int index, vector<int> &subarr, int n)
{
    if (index == n)
    {
        for (auto it : subarr)
        {
            vt[l].push_back(it);
        }
        l++;
        return;
    }
    else
    {
        subarr.push_back(arr[index]);
        printSubsequences(arr, index + 1, subarr, n);
        subarr.pop_back();
        printSubsequences(arr, index + 1, subarr, n);
    }
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vt.resize(pow(2, n) - 1);
    vector<int> vec;

    printSubsequences(arr, 0, vec, n);
    for (ll i = 0; i < 16; i++)
    {
        // if (vt[i].size() == n - 1)
        // {
        for (auto it : vt[i])
            cout << it << " ";
        cout << endl;
        // }
    }
    vt.empty();
}

signed main()
{
    fast
        ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}