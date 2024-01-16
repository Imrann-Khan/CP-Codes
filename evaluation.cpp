#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack <char> s1,s2;
    string s;
    cin >> s;
    for(int i=0; i<s.size();i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            s1.push(s[i]);
        else if((s1.top()=='(' && s[i]==')' ) || (s1.top()=='{' && s[i]=='}' ) || (s1.top()=='[' && s[i]==']' ))
        {
            if(s1.size()==0)
            {
                cout << "Not Balanced";
                break;
            }
            else s1.pop();
        }
    }
    if(s1.size()!=0)
    {
        cout << "Not Balanced";
    }
    else cout << "Balanced";
    /*while (!s1.empty())
        {
            cout << ' ' << s1.top();
            s1.pop();
        }
*/
    return 0;
}
