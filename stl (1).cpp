#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<string, vector<string> >cities;

void printAllConnectedCities(string c){
    sort(cities[c].begin(), cities[c].end());
    for(int i=0; i<cities[c].size(); i++)   cout<<cities[c][i]<<" ";
}

int main(){
    int n;
    cin>>n;
    while(n--){
        string x,y;
        int w;
        cin>>x>>y>>w;
        cities[x].push_back(y);
        cities[y].push_back(x);
    }
    f(cities);
}
