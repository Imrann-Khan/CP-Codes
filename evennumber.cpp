#include<bits/stdc++.h>
#define TR ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{
    TR
    lng long n,q;
    cin>>n;
    long long low[n],high[n];
    for(long long i=0;i<n;i++){
        cin>>low[i]>>high[i];
    }
    sort(low,low+n);
    sort(high,high+n);
    cin>>q;
    while(q--){
        long long key;cin>>key;long long c=0;
        long long l=0,h=n-1,af1=0,af2=0;
        while(l<=h){
           long mid=(l+h)/2;
            if(low[mid]<=key){
                if(low[mid+1]>key||mid==n-1){
                    c=mid+1;
                }
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        af1=n-c;
        c=0,l=0, h=n-1;
        
        while(l<=h){
           long mid=(l+h)/2;
            if(high[mid]>=key){
                if(high[mid-1]<key||mid==0){
                    c=mid+1;
                }
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(c==0) af2=0;
        else af2=n-c+1;
        af2=n-af2;
        long f=n-(af1+af2);
        cout<<f<<endl;
    }
  
return 0;
}