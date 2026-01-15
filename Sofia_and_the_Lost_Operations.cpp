#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define MAXN 200200
#define MAXM 200200
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int n, m, k;
int arr[MAXN], brr[MAXN], drr[MAXM], buf[MAXN];
 
int cmp_i32(const void* pa, const void* pb) {
    return *(const int*)pa - *(const int*)pb;
}
 
void build() {
    k = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != brr[i])
            buf[k++] = brr[i];
    }
    qsort(buf, k, sizeof(*buf), cmp_i32);
}
 
bool check() {
    for (int i = 0; i < n; ++i)
        if (brr[i] == drr[m - 1])
            return true;
    return false;
}
 
bool solve() {
    if (!check()) return false;
    qsort(drr, m, sizeof(*drr), cmp_i32);
    int ib = 0, id = 0;
    while (ib < k && id < m) {
        if (buf[ib] == drr[id])
            ++ib, ++id;
        else if (buf[ib] < drr[id])
            return false;
        else ++id;
    }
    return ib == k;
}


signed main()
{
    fast
    ll t; cin>>t;
    while(t--)
    {
        cin>>n;
        for(ll i=0;i<n;i++) cin>>arr[i];
        for(ll i=0;i<n;i++) cin>>brr[i];
        cin>>m;
        for(ll i=0;i<m;i++) cin>>drr[i];
        build();
        if(solve()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}