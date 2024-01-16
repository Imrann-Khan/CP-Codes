#include<bits/stdc++.h>
using namespace std;

int Binary_Exponentiation(int a, int b)
{
    if(b==0) return 1;
    int res=Binary_Exponentiation(a,b/2);

    if(b&1) return a*res*res; /// (b%2!=0) and (b&1) same thing. (b&1) returns true if odd (bitwise AND with 1)
    else return res*res;
}

int main()
{
    int a,b;
    cin >> a >> b;
    cout << Binary_Exponentiation(a,b);
    return 0;
}
