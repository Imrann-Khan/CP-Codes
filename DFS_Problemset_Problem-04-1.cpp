#include<bits/stdc++.h>
using namespace std;
int Count=0;
char a[100][100]= {};
int vis[100][100]={};

void DFS_visit(int i,int j,int w,int h);

void DFS(int w,int h)
{
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(vis[i][j]==0 && a[i][j]=='@')
            {
                DFS_visit(i,j,w,h);
                Count++;
            }
        }
    }
}

void DFS_visit(int i,int j,int w,int h)
{
    if( i>=h || j>=w || i<0 || j<0 || a[i][j]=='*' || vis[i][j]==1) return;
    vis[i][j]=1;
    DFS_visit(i+1,j,w,h);
    DFS_visit(i,j+1,w,h);
    DFS_visit(i-1,j,w,h);
    DFS_visit(i,j-1,w,h);
    DFS_visit(i+1,j+1,w,h);
    DFS_visit(i-1,j-1,w,h);
    DFS_visit(i+1,j-1,w,h);
    DFS_visit(i-1,j+1,w,h);
}

int main()
{
    while(1)
    {
        int w,h;
        cin >> h >> w;
        if(h==0 || w==0) break;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                cin >> a[i][j];
            }
        }
        DFS(w,h);

        cout << Count << "\n";
        Count=0;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                ///a[i][j]='\0';
                vis[i][j]=0;
            }
        }
    }
    return 0;
}
