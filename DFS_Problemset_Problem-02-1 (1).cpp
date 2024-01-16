#include<bits/stdc++.h>
using namespace std;
int Count=0;
char a[100][100]= {};
int vis[100][100]={};
void DFS_visit(int i, int j, int w, int h)
{
    if( i>=h || j>=w || i<0 || j<0 || a[i][j]=='#' || vis[i][j]==1) return;
    Count++;
    vis[i][j]=1;
    DFS_visit(i+1,j,w,h);
    DFS_visit(i,j+1,w,h);
    DFS_visit(i-1,j,w,h);
    DFS_visit(i,j-1,w,h);
}
int main()
{
    int t;
    cin >> t;
    for(int z=1;z<=t;z++)
    {
        int w,h;
        cin >> w >> h;
        getchar();
        int start_i,start_j;
        /// Input
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                cin >> a[i][j];
                if(a[i][j]=='@')
                {
                    start_i=i;
                    start_j=j;
                }
            }
            getchar();
        }
        DFS_visit(start_i,start_j,w,h);
        cout << "Case " << z << ": "<< Count << "\n";
        Count=0;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                a[i][j]='\0';
                vis[i][j]=0;
            }
        }
    }
    return 0;
}
