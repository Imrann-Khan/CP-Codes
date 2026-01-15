#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long sum = a[i] + a[j];
                int l = j, r = n - 1;
                int mid;
                while (r > l)
                {
                    int mid = (l + r + 1) >> 1;
                    if (a[mid] < sum)
                        l = mid;
                    else
                        r = mid - 1;
                }
                ans += (l - j);
            }
        }
        cout << ans << endl;
    }
}