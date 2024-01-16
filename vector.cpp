#include<bits/stdc++.h>
using namespace std;



int main()
{
    vector <int> v1;
    cout<<v1.capacity()<<"  "<<v1.size()<<endl;
    v1.push_back(10);
    v1.push_back(20);
    cout<<v1.capacity()<<"  "<<v1.size()<<endl;
    v1.push_back(30);
    v1.push_back(40);
    cout<<v1.capacity()<<"  "<<v1.size()<<endl;
    v1.push_back(50);
    v1.push_back(60);
    cout<<v1.capacity()<<"  "<<v1.size()<<endl;
    v1.push_back(70);
    cout<<v1.capacity()<<"  "<<v1.size()<<endl;
    v1.push_back(80);
    v1.push_back(90);
    cout<<v1.capacity()<<"  "<<v1.size()<<endl;
    for (int i=0;i<v1.size();i++)
    {
        cout<<v1.at(i)<<"  ";
    }
    cout<<endl;
    vector<int>::iterator it;
    cout<<endl;
    for (it=v1.begin();it!=v1.end();it++)
    {
        cout<<&it<<"  ";
    }

    return 0;
}
