#include<bits/stdc++.h>
using namespace std;
int main()
{
  int i,t,s=0;
  char x[4];
  cin>>t;
  for(i=0;i<t;i++)
    {
        cin>>x;
        if((strcmp(x,"X++")==0)||(strcmp(x,"++X")==0)){
            s++;
        }
        else if((strcmp(x,"X--")==0)||(strcmp(x,"--X")==0)){
            s--;
        }
    }
cout<<s;
return 0;
}