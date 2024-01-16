#include<bits/stdc++.h>
using namespace std;

int memo[100][100];
int lcs(string s1,string s2)
{
    if(s1.length()==0 || s2.length()==0) return 0;
    if(memo[s1.length()][s2.length()]!=-1) return memo[s1.length()][s2.length()];
    if(s1[s1.length()-1]==s2[s2.length()-1]) return memo[s1.length()][s2.length()]=1+lcs(s1.substr(0,s1.length()-1),s2.substr(0,s2.length()-1));
    else return memo[s1.length()][s2.length()]=max(lcs(s1.substr(0,s1.length()-1),s2),lcs(s2.substr(0,s2.length()-1),s1));
}
int main()
{
    string s3="ABCD";
    string s4="BACYD";
    memset(memo,-1,sizeof(memo));
    cout<<lcs(s3,s4)<<"\n";
    for(int i=0;i<s3.length();i++) memo[i][0]=0;
    for(int i=0;i<s4.length();i++) memo[0][i]=0;
    for(int i=0;i<s3.length()+1;i++)
    {
        for(int j=0;j<s4.length()+1;j++)
        {
            cout<<memo[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}