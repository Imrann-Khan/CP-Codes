#include<bits/stdc++.h>
using namespace std;

string land[1000];
int row,column,counts=0;
int visit[1000][1000]={};

void dfs(int r,int c)
{
    if(r<0 || r>=row || c<0 || c>=column || land[r][c]=='#' || visit[r][c]==1)
        return;
    visit[r][c]=1;
    counts++;
    dfs(r-1,c);
    dfs(r,c-1);
    dfs(r+1,c);
    dfs(r,c+1);
}

int main()
{
    cin >> column >> row;
    for(int i=0;i<row;i++)
        cin >> land[i];

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(land[i][j]=='@')
                dfs(i,j);
        }
    }
    cout << counts;
    return 0;
}
