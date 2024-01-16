#include<bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

class Map
{
public:
    map< int ,vector<string> > mp;
    map< vector<string> ,int > mp2;
    void printHighways()
    {
        cout << endl << endl ;
        for(map< int ,vector<string> > ::reverse_iterator it=mp.rbegin() ;it!=mp.rend() ;it++)
        {
            cout << it->second.at(0) << " "  << it->second.at(1) << " " << it->first <<endl;
        }
    }

    void printAllConnectedCities(string c)
    {
        vector<string> v;

        for(map< int ,vector<string> > ::reverse_iterator it=mp.rbegin() ;it!=mp.rend() ;it++)
        {
                if(it->second.at(0) == c)
                    v.push_back(it->second.at(1));
                else if(it->second.at(1) == c)
                    v.push_back(it->second.at(0));
        }
        sort(v.begin(),v.end());
        for(int i=0 ;i <v.size() ; i++)
            {
                cout << v.at(i) << " ";
            }
    }
};
/*
void print(map< int ,vector<string> > a)
{
    for(map< int ,vector<string> > :: iterator it=a.begin() ;it!=a.end() ;it++)
    {
        for(int i=0; i< it->size() ;i++)
        {
            cout << it->first << it->second.at(i);
        }
    }

}
*/
int main()
{
    Map ob;
    int n;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        string a,b;
        int c;
        cin >> a >> b >> c;
        ob.mp[c].push_back(a);
        ob.mp[c].push_back(b);

    }

    ob.printHighways();

    string s;
    cin >> s;
    ob.printAllConnectedCities(s);

}
