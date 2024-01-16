#include <bits/stdc++.h>
#define ll long long int
#define fast ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

int findSmallestSubstringLength(const string& s) {
    int n = s.length();
    int minLength = INT_MAX;
    
    
    for (int i = 0; i < n; ++i) {
        int count = 0;
        int j = i;
        
     
        for (char c = 'A'; c <= 'Z'; ++c) {
            while (j < n) {
                if (s[j] == c) {
                    ++count;
                    break;
                }
                ++j;
            }
            ++j;
        }
        
        if (count == 26)
            minLength = min(minLength, j - i);
    }
    
    return (minLength == INT_MAX) ? -1 : minLength;
}

int main() {
    fast
    freopen("collectingofficer.in", "r", stdin);
    ll tc; cin>>tc;
    while(tc--)
    {
        ll n;
        string s;
        cin>>n;
        cin >> s;

        ll smallestSubstringLength = findSmallestSubstringLength(s);
    
        cout<< smallestSubstringLength << endl;
    }
    return 0;
}
