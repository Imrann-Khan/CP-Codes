#include <bits/stdc++.h>
using namespace std;

void n2Sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void rashidSort(int arr[], int n)
{
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(arr[i], mx);
    }
    // cout << mx << endl;
    int frq[mx + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        frq[arr[i]]++;
    }
    int j = 0;
    for (int i = 1; i <= mx; i++)
    {
        while (frq[i] != 0)
        {
            arr[j++] = i;
            frq[i]--;
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// void rashidSort(int arr[], int n)
// {
//     int mx = 0;
//     for (int i = 0; i < n; i++)
//     {
//         mx = max(arr[i], mx);
//     }
//     // cout << mx << endl;
//     int frq[mx + 1] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         frq[arr[i]]++;
//     }
//     int output[n];
//     for (int i = 1; i <= mx; i++)
//     {
//         frq[i] += frq[i - 1];
//     }
//     // for (int i = 0; i < n; i++)
//     //     cout << frq[i] << " ";
//     // cout << endl;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         output[frq[arr[i]] - 1] = arr[i];
//         frq[arr[i]]--;
//     }

//     for (int i = 0; i < n; i++)
//         cout << output[i] << " ";
//     cout << endl;
// }

signed main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    rashidSort(a, n);
}