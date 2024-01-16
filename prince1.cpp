#include<bits/stdc++.h>
using namespace std;

string lands[10000];
int row, column, counts;
int visit[10000][10000];

void dfs(int r, int c)
{
    if(r<0 || r>=row || c<0 || c>=column || lands[r][c] == '#' || visit[r][c] == 1)
        return;
    visit[r][c] = 1;
    counts++;
    dfs(r-1, c);
    dfs(r,c-1);
    dfs(r+1,c);
    dfs(r,c+1);

}

int main()
{
    int cases;
    cin >> cases;
    for(int c1=1; c1<=cases; c1++)
    {
        cin >> column >> row;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<column; j++)
            {
                visit[i][j] = 0;
            }
        }
         counts = 0;
        for(int i=0; i<row; i++)
            cin >> lands[i];
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<column; j++)
            {
                if(lands[i][j] == '@')
                {
                    dfs(i,j);


                }
            }
        }

            cout << "Case " << c1 << ": " << counts << endl;
    }
}
//4
//6 9
//....#.
//.....#
//......
//......
//......
//......
//......
//#@...#
//.#..#.
//11 9
//.#.........
//.#.#######.
//.#.#.....#.
//.#.#.###.#.
//.#.#..@#.#.
//.#.#####.#.
//.#.......#.
//.#########.
//...........
//11 6
//..#..#..#..
//..#..#..#..
//..#..#..###
//..#..#..#@.
//..#..#..#..
//..#..#..#..
//7 7
//..#.#..
//..#.#..
//###.###
//...@...
//###.###
//..#.#..
//..#.#..
