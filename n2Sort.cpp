#include <bits/stdc++.h>
using namespace std;

void n2Sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;
}

signed main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // rashidSort(a, n);
    n2Sort(a, n);
}