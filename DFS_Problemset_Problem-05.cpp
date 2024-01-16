#include<bits/stdc++.h>
using namespace std;

bool Count=false;
char a[100][100]= {};
int vis[100][100]={};

void DFS_visit(int i,int j,int n);

void DFS(int n)
{
    for(int i=0;i<n;i++)
    {
        if(vis[i][0]==0 && a[i][0]=='w')
        {
            DFS_visit(i,0,n);
        }
    }
}

void DFS_visit(int i,int j,int n)
{
    if(i>=n || j>=n || i<0 || j<0 || a[i][j]=='b' || vis[i][j]==1) return;
    vis[i][j]=1;
    if(j==n-1 && a[i][j]=='w')
    {
        Count=true;
        return;
    }

    DFS_visit(i+1,j,n);
    DFS_visit(i,j+1,n);
    DFS_visit(i-1,j,n);
    DFS_visit(i,j-1,n);
    DFS_visit(i+1,j+1,n);
    DFS_visit(i-1,j-1,n);
    ///DFS_visit(i+1,j-1,n);
    ///DFS_visit(i-1,j+1,n);
}

int main()
{
    int t=0;
    while(1)
    {
        int n;
        t++;
        cin >> n;
        if(n==0) break;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> a[i][j];
            }
        }
        DFS(n);

        if(Count==true)
            cout << t << " W\n";
        else
            cout << t << " B\n";

        Count=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]='\0';
                vis[i][j]=0;
            }
        }
    }
    return 0;
}
