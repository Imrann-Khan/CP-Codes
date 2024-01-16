#include<bits/stdc++.h>
using namespace std;

class User
{
    string gmail,password,name;
    int balance;
public:
    string getGmail()
    {
        return gmail;
    }
    string getPassword()
    {
        return password;
    }
    string getName()
    {
        return name;
    }
    int getBalance()
    {
        return balance;
    }
    void setGmail(string x)
    {
        gmail=x;
    }
    void setPassword(string x)
    {
        password=x;
    }
    void setName(string x)
    {
        name=x;
    }
    int setBalance(int b)
    {
        balance=b;
    }

};
class Transaction
{
    string sender;
    string receiver;
    int prevBalance;
    int amount;
public:
    string getSender()
    {
        return sender;
    }
    string getReceiver()
    {
        return receiver;
    }
    int getPrevBalance()
    {
        return prevBalance;
    }
    int getAmount()
    {
        return amount;
    }
    string setSender(string x)
    {
        sender=x;
    }
    string setReceiver(string x)
    {
        receiver=x;
    }
    int setPrevBalance(int x)
    {
        prevBalance=x;
    }
    int setAmount(int x)
    {
        amount=x;
    }

};
User users[100];
Transaction trans[5000];
int index=0;
int indexTransaction=0;
bool status=false;
string currentuser="";
int main()
{
    int choice;
    cin>>choice;
    while(1)
    {
        if(choice==1)
        {
            if(status==true)
            {
                cout<<"Already "<<currentuser<<" is logged in."<<endl;
            }
           else
           {
                string gmail,pass,name;
                cin>>gmail>>pass>>name;
                User u;
                u.setGmail(gmail);
                u.setPassword(pass);
                u.setName(name);
                u.setBalance(500);
                users[index]=u;
                index++;
                cout<<"Acount created succesfully"<<endl;
           }
        }
        else if(choice==2)
        {
            if(status==true)
            {
                cout<<"Already "<<currentuser<<" is logged in."<<endl;
            }
            else
            {
            string gmail,pass;
            cin>>gmail>>pass;
            User u;
            u.setGmail(gmail);
            u.setPassword(pass);
            for(int i=0;i<index;i++)
            {
                if(users[i].getGmail().compare(gmail)==0 && users[i].getPassword().compare(pass)==0)
                {
                    status=true;
                    currentuser=gmail;
                    break;
                }
                else
                {
                    cout<<"Wrong account"<<endl;
                }
            }
            if(status==false)
            {
                cout<<"Log in failed"<<endl;
            }
            }
        }
        else if(choice==3)
        {
            if(status==false)
            {
                cout<<"No one is currently logged in"<<endl;
            }
            else
            {
                status=false;
                currentuser="";
            }
        }
        else if(choice==4)
        {
            string newPass;
            cin>>newPass;
        }
        else if(choice==5)
        {
            string receiverGmail;
            int amount;
            cin>>receiverGmail>>amount;
        }
        else if(choice==6)
        {

        }
        else if(choice==7)
        {

        }
        else if(choice==8)
        {

        }




    }
    return 0;
}
