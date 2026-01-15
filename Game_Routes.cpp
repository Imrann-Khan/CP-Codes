#include<bits/stdc++.h>
using namespace std;


vector<int> TopSort(vector<vector<int>> &edge, int v, vector<int> indeg)
{
    vector<int> ans;
    queue<int> q;
    for(int i = 0; i < v; i++)
    {
        if(indeg[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        //cout << p << " ";
        ans.push_back(p);
        for(auto j : edge[p])
        {
            indeg[j]--;
            if(indeg[j] == 0)
                q.push(j);
        }
    }
    return ans;
}


int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>> edge(v+1);
    vector<int> indeg(v+1,0);
    for(int i=0;i<e;i++)
    {
        int p,q;
        cin>>p>>q;
        edge[p].push_back(q);
        indeg[q]++;
    }
    cout<<indeg[v]<<endl;
    return 0;
}