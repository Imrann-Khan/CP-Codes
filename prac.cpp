#include <bits/stdc++.h>
using namespace std;

int Find(int n, int *arr, int key)
{
    int l = 0, r = n - 1;
    int mid;
    while (r > l)
    {
        int m = (l + r + 1) >> 1;
        if (arr[mid] <= key)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

pair<int, int> checkPositiveTarget(int nums[], int target)
{
    int negLeft = 0;

    int low = 0, high = 10;
    while (low < high)
    {
        int mid = (low + high + 1) >> 1;
        if (nums[mid] < 0)
            low = mid;
        else
            high = mid - 1;
    }
    int negRight = low;
    int posLeft = low + 1;
    while (negLeft < negRight)
    {
        if (nums[negLeft] * nums[negRight] == target)
        {
            return {negLeft, negRight};
        }
        else if (nums[negLeft] * nums[negRight] > target)
            negLeft++;
        else
            negRight--;
    }
    int posRight = 10;
    while (negLeft < negRight)
    {
        if (nums[posLeft] * nums[posRight] == target)
        {
            return {posLeft, posRight};
        }
        else if (nums[posLeft] * nums[posRight] > target)
            posRight--;
        else
            posLeft++;
    }
    return {-1, -1};
}

pair<int, int> checkNegativeTarget(int nums[], int target)
{
    int negRight = 0;
    int low = 0, high = 10;
    while (low < high)
    {
        int mid = (low + high + 1) >> 1;
        if (nums[mid] < 0)
            low = mid;
        else
            high = mid - 1;
    }
    int posRight = low + 1;
    while (posRight > negRight)
    {
        if (nums[negLeft] * nums[negRight] == target)
        {
            return {negLeft, negRight};
        }
        else if (nums[negLeft] * nums[negRight] > target)
            posRight++;
        else
            negRight++;
    }
    return {-1, -1};
}

pair<int, int>
chack(int nums[], int target)
{
    if (target < 0)
        return checkPositiveTarget(nums, target);
    else
        return checkNegativeTarget(nums, target);
}

signed main()
{
    // int x, y, z;
    // cin >> x >> y >> z;
    // int a[x][y];
    // int b[y][z];
    // int res[x][z];

    // for (int i = 0; i < x; i++)
    // {
    //     for (int j = 0; j < y; j++)
    //     {
    //         cin >> a[i][j];
    //     }
    // }

    // for (int i = 0; i < y; i++)
    // {
    //     for (int j = 0; j < z; j++)
    //     {
    //         cin >> b[i][j];
    //     }
    // }

    // for (int i = 0; i < x; i++)
    // {
    //     for (int j = 0; j < y; j++)
    //     {
    //         int x = 0;
    //         for (int k = 0; k < z; k++)
    //         {
    //             x += a[i][k] * b[k][j];
    //         }
    //         res[i][j] = x;
    //     }
    // }

    // for (int i = 0; i < x; i++)
    // {
    //     for (int j = 0; j < z; j++)
    //     {
    //         cout << res[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // int n, m;
    // cin >> n >> m;
    // int a[n][n];
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cin >> a[i][j];
    //     }
    // }

    // int prfxsum[n + 1][m + 1] = {};

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         prfxsum[i][j] = prfxsum[i - 1][j] + prfxsum[i][j - 1] - prfxsum[i - 1][j - 1] + a[i - 1][j - 1];
    //     }
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << prfxsum[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // int q;
    // cin >> q;
    // while (q--)
    // {
    //     int xl, yl, xr, yr;
    //     cin >> xl >> yl >> xr >> yr;
    //     cout << prfxsum[xr][yr] - prfxsum[xl - 1][yr] - prfxsum[xr][yl - 1] + prfxsum[xl - 1][yl - 1] << endl;
    // }

    // int n, k;
    // cin >> n >> k;
    // int a[n];
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    // int ans = 0;
    // int ans = INT_MIN;
    // int mx = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     mx += a[i];
    //     if (mx > ans)
    //         ans = mx;
    //     else if (mx < 0)
    //         mx = 0;
    //     cerr << mx << endl;
    // }
    // cout << ans << endl;
    // int l = 0, r = 0;
    // int cursum = a[0];
    // while (r < n)
    // {
    //     if (cursum < k)
    //     {
    //         r++;
    //         cursum += a[r];
    //     }
    //     else if (cursum > k)
    //     {
    //         cursum -= a[l++];
    //     }
    //     else
    //     {
    //         cout << l << " " << r << endl;

    //         if (a[l] == 0)
    //             l++;
    //         else
    //         {
    //             r++;
    //             cursum += a[r];
    //         }
    //     }
    // }
    // cout << ans << endl;
    // int n, k;
    // cin >> n >> k;
    // int a[n];
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    // sort(a, a + n);
    // cout << Find(n, a, k) << endl;
    // int n;
    // cin >> n;
    // int a[n];
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    // int l = 0, r = n - 1;
    // while (r > l)
    // {
    //     int mid = l + (r - l) / 2;
    //     if (a[mid] > a[mid + 1])
    //     {
    //         r = mid;
    //     }
    //     else
    //         l = mid + 1;
    // }
    // cout << l << endl;

    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int q;
    while (q--)
    {
        int target;
        cin >> target;
        pair<int, int> ans = check(nums, target);
        cout << ans.first << " " << ans.second << endl;
    }
}

/*
10
-5 -4 -3 -2 -1 0 1 2 3 4 5

*/
