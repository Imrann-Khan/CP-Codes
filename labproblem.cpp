#include<iostream>
#include<fstream>
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
    void print()
    {

    }
};
class Transaction
{
    string sender,receiver;
    int prevBalance,amount;
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
    void setSender(string x)
    {
        sender=x;
    }
    void setReceiver(string x)
    {
        receiver=x;
    }
    void setPrevBalance(int x)
    {
        prevBalance=x;
    }
    void setAmount(int x)
    {
        amount=x;
    }
};
User users[100];
Transaction trans[5000];
int index=0;
int indexTransaction=0;
bool status=false;
string currentUser="";
int main()
{
    int choice;
    cout<<"Enter your choice: ";
    while(cin>>choice)
    {
        if(choice==1)
        {
            if(status==true)
            {
                cout<<"Already "<<currentUser<<" logged in"<<endl;
            }
            else
            {
                string gmail,pass,name;
                cout<<"Enter gmail: ";
                cin>>gmail;
                cout<<"Enter password: ";
                cin>>pass;
                cout<<"Enter name: ";
                cin>>name;
                User u;
                u.setGmail(gmail);
                u.setPassword(pass);
                u.setName(name);
                u.setBalance(500);
                users[index]=u;
                index++;
                status=true;
                currentUser=gmail;
                cout<<endl<<"Account created succesfully"<<endl;
            }
        }
        else if(choice==2)
        {
            if(status==true)
                {
                  cout<<"Already "<<currentUser<<" logged in"<<endl;
                }
            else
                {
                    string gmail,pass;
                    cout<<"Enter gmail: ";
                    cin>>gmail;
                    cout<<endl<<"Enter Password: ";
                    cin>>pass;
                    User u;
                    u.setGmail(gmail);
                    u.setPassword(pass);
                    for(int i=0;i<index;i++)
                    {
                        if(users[i].getGmail()==gmail && users[i].getPassword()==pass)
                        {
                            status=true;
                            currentUser=gmail;
                            break;
                        }
                    }
               }
        }
        else if(choice==3)
        {
            status=false;
            currentUser="";
        }
        else if(choice==4)
        {
            if(status==false)
            {
                cout<<"Resetting password isn't possible"<<endl;
            }
            else
            {
                string newPass,gmail,currentpass;
                cout<<"Enter gmail: ";
                cin>>gmail;
                cout<<"Enter current password: ";
                cin>>currentpass;
                cout<<"Enter new password: ";
                cin>>newPass;
                for(int i=0;i<index;i++)
                {
                if(users[i].getGmail()==gmail && users[i].getPassword()==currentpass)
                    {
                       users[i].setPassword(newPass);
                       currentUser=gmail;
                       break;
                    }
                }
            }

        }
        else if(choice==5)
        {
            if(status==false)
            {
                cout<<"Sending money isn't possible"<<endl;
            }
            else
            {
                string receiverGmail,senderGmail;
                int amount;
                cout<<"Enter sender gmail: ";
                cin>>senderGmail;
                cout<<endl<<"Enter receiver gmail: ";
                cin>>receiverGmail;
                cout<<endl<<"Enter amount: ";
                cin>>amount;
                cout<<endl;
                Transaction t;
                t.setReceiver(currentUser);
                t.setSender(senderGmail);
                t.setAmount(amount);
                trans[indexTransaction]=t;
                indexTransaction++;
                for(int i=0;i<index;i++)
                {
                if(users[i].getGmail()==receiverGmail)
                    {
                       if(amount<=users[i].getBalance())
                       {
                           int c=0;
                           c=users[i].getBalance();
                           c=c+amount;
                           trans[indexTransaction].setPrevBalance(c);
                           users[i].setBalance(c);
                           break;
                       }
                    }
                }
            }

        }
        else if(choice==6)
        {
            string gmail;
            //ofstream tf;
            //tf.open("C:labassignment.txt",ios::app);

                    for(int i=0;i<indexTransaction;i++)
                {
                    int k=0;
                    if(trans[i].getReceiver()==gmail || trans[i].getSender()==gmail)
                    {
                        cout<<"Transaction-"<<k<<endl<<"sender: "<<trans[i].getSender()<<endl<<"receiver: "<<trans[i].getReceiver()<<endl<<"Amount:"<<trans[i].getAmount()<<"Tk"<<endl<<"Current Balance:"<<trans[i].getPrevBalance()<<endl;
                             k++;
                    }
                }
        }
        else if(choice==7)
        {
            for(int i=0;i<index;i++)
            {
                cout<<"Username: "<<users[i].getName()<<endl;
                cout<<"Gmail: "<<users[i].getGmail()<<endl;
                cout<<"balance: "<<users[i].getBalance()<<endl;
            }
        }
        else if(choice==8)
        {
            break;
        }
        cout<<"Enter your choice: ";
}
}

