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

void Merge(int *a, int l, int r, int mid)
{
    int l1 = mid - l + 1;
    int r1 = r - mid;
    int L[l1], R[r1];
    rep(i, 0, l1 - 1) L[i] = a[l + i];
    rep(i, 0, r1 - 1) R[i] = a[mid + i + 1];
    int i = 0, j = 0;
    int k = l;
    while (i < l1 and j < r1)
    {
        if (L[i] > R[j])
        {
            a[k++] = R[j];
            j++;
        }
        else
        {
            a[k++] = L[i];
            i++;
        }
    }
    while (i < l1)
    {
        a[k++] = L[i];
        i++;
    }
    while (j < r1)
    {
        a[k++] = R[j];
        j++;
    }
}

void merge_sort(int *a, int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    Merge(a, l, r, mid);
}

int dandc(int *a, int l, int r)
{
    int pivot = a[r];
    int i = l - 1;
    rep(j, l, r - 1)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void qksort(int *a, int l, int r)
{
    if (l < r)
    {
        int pivot = dandc(a, l, r);

        qksort(a, l, pivot - 1);
        qksort(a, pivot + 1, r);
    }
}

void countSort(int *a, int n)
{
    int mx = INT_MIN;
    rep(i, 0, n - 1)
    {
        mx = max(mx, a[i]);
    }
    int countArr[mx + 1] = {0};
    int outputArr[n + 1];
    rep(i, 0, n - 1)
    {
        countArr[a[i]]++;
    }
    rep(i, 1, mx)
    {
        countArr[i] += countArr[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        outputArr[countArr[a[i]] - 1] = a[i];
        countArr[a[i]]--;
    }
    rep(i, 0, n - 1)
        a[i] = outputArr[i];
}

signed main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n - 1) cin >> a[i];
    // merge_sort(a, 0, n - 1);
    // qksort(a, 0, n - 1);
    countSort(a, n);
    rep(i, 0, n - 1) cout << a[i] << " ";
}
