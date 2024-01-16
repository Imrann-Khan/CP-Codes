#include<iostream>
#include<cstdlib>
#define endl "\n"
using namespace std;

int userID, index=0, userIndex=-1;
string userPassword;
float money,currentBalance=0.00;
bool accountExists=false;
char choice;

class Bank
{
    int ID;
    string password;
    float balance;
public:
    int getID()
    {
        return ID;
    }
    string getPassword()
    {
        return password;
    }
    float getBalance()
    {
        return balance;
    }

    void setID(int ID)
    {
        this->ID=ID;
    }

    void setPassword(string password)
    {
        this->password=password;
    }

    void setBalance(float balance)
    {
        this->balance=balance;
    }

}ATM[100];

void createAccount()
{
    cout<<"Please enter your user ID: ";
    cin>>userID;
    ATM[index].setID(userID)
    ;
    cout<<"Please enter your password: ";
    cin>>userPassword;
    ATM[index++].setPassword(userPassword);
    cout<<endl<<"Thank you! Your account has been created!"<<endl<<endl;

}
void menu2();

void userLogin()
{
    cout<<"Please enter your user ID: ";
    cin>>userID;
    cout<<"Please enter your user password: ";
    cin>>userPassword;
    accountExists=false;
    for(int i=0;i<index;++i)
    {
        if(ATM[i].getID()==userID and ATM[i].getPassword()==userPassword)
        {
            userIndex=i;
            accountExists=true;
            break;
        }
    }
    if(!accountExists)
    cout<<endl<<"****** ACCESS DENIED ******"<<endl<<endl;
    else
    {
        cout<<endl<<"Access granted!"<<endl<<endl;
        menu2();

    }

}

void menu()
{
     cout<<"Please select an option from the menu below:"<<endl<<endl;
     cout<<"l -> login"<<endl<<"c -> Create New Account"<<endl<<"q -> quit"<<endl<<endl;

}

void depositMoney()

{
    cout<<"Amount of deposit: $";
    cin>>money;
    currentBalance=ATM[userIndex].getBalance();
    currentBalance+=money;
    ATM[userIndex].setBalance(currentBalance);

}


void withdrawMoney()

{
    cout<<"Amount of withdrawal: $";
    cin>>money;
    currentBalance=ATM[userIndex].getBalance();
    currentBalance-=money;
    ATM[userIndex].setBalance(currentBalance);

}


void requestBalance()

{
    cout<<endl<<"Your balance is $"<<ATM[userIndex].getBalance()<<endl<<endl;
}


void menu2()

{
    while(true)
    {
        cout<<"d -> Deposit money"<<endl<<"w -> withdraw money"<<endl<<"r -> request balance"<<endl<<"q -> quit"<<endl<<endl;
        cout<<">";
        cin>>choice;
        switch(choice)
        {
        case 'd':
            depositMoney();
            cout<<endl;
            break;
        case 'w':
            withdrawMoney();
            cout<<endl;
            break;
        case 'r':
            requestBalance();
            break;
        case 'q':
            return ;

        }
    }
}

int main()
{
    cout<<"Hi! Welcome to Mr. Zamar's ATM machine!"<<endl<<endl;
    while(true)
    {
        menu();
        cout<<">";
        cin>>choice;
        switch(choice)
      {
        case 'l':
            userLogin();
            break;
        case 'c':
            createAccount();
            break;
        case 'q':
            cout<<endl<<"Thanks for stopping by!";
            return 0;
      }

    }
}
