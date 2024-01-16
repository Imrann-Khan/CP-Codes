#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
string orderid="";
struct Order
{
    string orderID;
    string customerName;
    double orderPrice;
    void setOrderID()
    {
        for(int i=0;i<8;i++)
        {
           int x=rand()%26;
           int t=rand()%2;
           if(t==0)
           {
              x=x+65;
           }
           else
           {
              x=x+97;
           }
           char z=x;
           orderid=orderid+z;
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
        cout<<"order ID:"<<orderid<<endl;
        cout<<"Order by: "<<customerName<<endl;
        cout<<"Price: "<<orderPrice<<endl;
        
    }
};
int main()
{
    Order r1;
    string a;
    double y;
    cout<<"Enter customerName: ";
    cin>>a;
    cout<<"ordered price: ";
    cin>>y;
    r1.setOrderID();
    r1.setCustomerName(a);
    r1.setOrderPrice(y);
    r1.print();
    return 0;
}