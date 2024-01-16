#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int ll;

int main() {
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        ll n = s.size();
        ll balls = 0; 
        ll runs = 0;
        ll wickets=0;
        for (ll i = 0; i < n; i++) {
            balls++;
            if (s[i] == 'W') {
                wickets++;
                
            } else {
                runs += s[i] - '0';
            }
        }
        string over="Over",run="Run",wicket="Wicket";
        double o = balls / 6;
        double rem_balls = balls % 6;
        rem_balls/=10;
        double overs= o+rem_balls;
        if(overs>1) over="Overs";
        if(runs>1) run="Runs";
        if(wickets>1) wicket="Wickets";
        printf("%.1lf",overs);
        cout<<" "<<over<<" "<<runs<<" "<<run<<" "<<wickets<<" "<<wicket<<"."<<endl;
    }
    return 0;
}