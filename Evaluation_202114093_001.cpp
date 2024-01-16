#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <queue>
#include <iterator>
#include <map>
using namespace std;
class User;
class Account;

class User
{
    char *id;
    char *name;
public:
    User(char* a,char* b)
    {
        id=new char[strlen(a)+1];
        strcpy(id,a);
        id[strlen(a)]='\0';

        name=new char[strlen(b)+1];
        strcpy(name,b);
        name[strlen(b)]='\0';
    }

    User(const User &u)
    {
        id=new char[strlen(u.id)+1];
        strcpy(this->id,u.id);
        id[strlen(u.id)]='\0';

        name=new char[strlen(u.name)+1];
        strcpy(this->name,u.name);
        name[strlen(u.name)]='\0';
    }

    ~User()
    {
        delete id;
        delete name;
    }

friend class Account;
friend int transferMoney(int i,int j, int amount);
};

class Account
{
    User *user;
    char *phone;
    int *balance;
public:
    Account(char *a, char *b, char*c)   /// HOLD
    {
        ///User temp(a,b);
        ///this->user=temp;
        user->id=new char[strlen(a)+1];
        strcpy(user->id,a);
        user->id[strlen(a)]='\0';

        user->name=new char[strlen(b)+1];
        strcpy(user->name,b);
        user->name[strlen(b)]='\0';

        phone=new char[strlen(c)+1];
        strcpy(phone,c);
        phone[strlen(c)]='\0';

        balance=new int;
        *balance=500;
    }
    Account(const Account &a)
    {
        this->phone=new char[strlen(a.phone)+1];
        strcpy(this->phone,a.phone);
        this->phone[strlen(a.phone)]='\0';

        this->balance=new int;
        *this->balance=*a.balance;

        this->user=a.user;
    }
    void setId(char *x)
    {
        user->id=new char[strlen(x)+1];
        strcpy(user->id,x);
        user->id[strlen(x)]='\0';

    }

    void setName(char *x)
    {

        user->name=new char[strlen(x)+1];
        strcpy(user->name,x);
        user->name[strlen(x)]='\0';

    }
    void setPhone(char *x)
    {
        phone=new char[strlen(x)+1];
        strcpy(phone,x);
        phone[strlen(x)]='\0';

    }
    void print()
    {
        cout << "ID: ";
        for(int i=0;i<strlen(user->id);i++)
        {
            cout << user->id[i];
        }
        cout << ", Name: ";
        for(int i=0;i<strlen(user->name);i++)
        {
            cout << user->name[i];
        }
        cout << ", Phone: ";
        for(int i=0;i<strlen(phone);i++)
        {
            cout << phone[i];
        }
        cout << ", Balance: " << *balance;
    }
    ~Account()
    {
        delete user;
        delete phone;
        delete balance;
    }

friend class User;
friend int transferMoney(int i,int j, int amount);
};

Account acc[4]={Account("10","Rafi","010"),Account("15","Binita","015"),Account("29","Nabil","029"),Account("36","Maisha","036")};

int transferMoney(int i,int j, int amount)
{
    if(strcmp(acc[i].phone,acc[j].phone)==0)
    {
        cout << "Invalid Transaction\n";
        return 0;
    }
    else
    {
        if(*acc[i].balance>=amount)
        {
            *acc[i].balance-=amount;
            *acc[j].balance+=amount;
            cout << "Transaction Successful" << "\n";
            return 1;
        }
        else
        {
            cout << "Insufficient Balance\n";
            return 0;
        }
    }
}

int main()
{
    Account admin=acc[0];
    admin.setId("A-11");
    admin.setName("Admin");
    admin.setPhone("01511");

    transferMoney(2,0,100);
    transferMoney(1,0,150);
    transferMoney(1,1,100);
    transferMoney(2,3,800);

    for(int i=0;i<4;i++)
    {
        acc[i].print();
        cout << "\n";
    }
    return 0;
}
