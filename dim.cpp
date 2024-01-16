#include<bits/stdc++.h>
using namespace std;
struct Order{
    string orderID;
    string customerName;
    double orderPrice;
    void setOrderID()
    {
     string order="";

     for(int i=0;i<8;i++){
      int e=rand()%26;
      int d=rand()%2;

     if(d==0)
     {
         e=e+65;
     }
     else{
        e=e+97;
     }
     order=order+(char)e;
     orderID=order;

    }
    }
    void setCustomerName(string x)
    {
        customerName=x;

    }
    void setOrderPrice(double y)
    {
      orderPrice=y;
    }
    void print()
    {
        cout<<"Order ID: "<<orderID<<endl;
        cout<<"Ordered By: "<<customerName<<endl;
        cout<<"Price: "<<orderPrice<<" Taka"<<endl;

    }
};
int main()
{
     struct Order a;
    string s;
    double r;
    cin>>s;
    cin>>r;
    a.setOrderID();
    a.setCustomerName(s);
    a.setOrderPrice(r);
    a.print();

}