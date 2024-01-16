#include<bits/stdc++.h>
using namespace std;

class ATM
{
    string id;
    string pass;
    double balance;
    public:
    string getId()
    {
        return id;
    }
    void setId(string id)
    {
        this->id=id;
    }
    string getPass()
    {
        return pass;
    }
    void setPass(string pass)
    {
        this->pass=pass;
    }
    double getBalance()
    {
        return balance;
    }
    void setBalance(double balance)
    {
         this->balance=balance;
    }
};
ATM users[1000];
bool st = false;
int index = 0;
int main()
{
    int a;
    while(1)
    {
        cout<<"1. Create a bank account by supplying a user id and password."<<endl<<"2. Login using their id and password."<<endl<<"3. Quit the program."<<endl<<"4. Show info."<<endl;
        cin>>a;
        if(a==1)
        {
            string id,pass;
            cout<<"Enter id: ";
            cin>>id;
            cout<<"Enter password: ";
            cin>>pass;
            st=false;
            ATM u;
            u.setId(id);
            u.setPass(pass);
            u.setBalance(0.00);
            users[index]=u;
            index++;
        }
        else if(a==2)
        {
            string id,pass;
            cout<<"Enter id: ";
            cin>>id;
            cout<<"Enter password: ";
            cin>>pass;
            for(int i=0;i<index;i++)
            {
                if(users[i].getId()==id && users[i].getPass()==pass)
                {
                    st=true;
                    cout<<"loggeed in successfully!"<<endl;
                    while(1)
                    {
                        cout<<" 1. Withdraw money."<<endl<<" 2. Deposit money."<<endl<<" 3. Request balance."<<endl<<" 4. Quit the program.";
                        cout<<endl<<"Enter your choice: ";
                        int c;
                        cin>>c;
                        if(c==1)
                        {
                            double w;
                            cout<<"Amount of withdrawal:";
                            cin>>w;
                            double k=users[i].getBalance();
                            k=k+w;
                            users[i].setBalance(k);
                        }
                        else if(c==2)
                        {
                            double d;
                            cout<<"Amount of deposit: ";
                            cin>>d;
                            double b=users[i].getBalance();
                            b=b+d;
                            users[i].setBalance(b);
                        }
                        else if(c==3)
                        {
                            cout<<"Your balance is $";
                            cout<<users[i].getBalance();
                        }
                        else if(c==4)
                        {
                            cout<<"Thanks for stopping by";
                            st=false;
                            break;
                        }
                    }
                }

            }
        }
        else if(a==3)
        {
            break;
        }
        else if(a==4)
        {
            for(int i=0;i<index;i++)
            {
                cout << users[i].getId()<<endl;
                cout << users[i].getPass()<<endl;
                cout << users[i].getBalance()<<endl;
            }
        }
    }
    return 0;
}
