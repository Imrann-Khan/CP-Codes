#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

class Person
{
    int ID;
protected:
    string Email;
public:
    string Name;
    Person(int ID, string Email, string Name)
    {
        this->ID=ID;
        this->Email=Email;
        this->Name=Name;
    }
    void display()
    {
        cout<<endl<<"Name: "<<Name<<endl;
        cout<<"Email: "<<Email<<endl;
        cout<<"ID: "<<ID<<endl;
    }
};
class Student: protected Person
{
    double GPA;
protected:
    double Fees;
public:
    Student(double GPA, double Fees, int ID, string Email, string Name):Person(ID,Email,Name)
    {
        this->GPA=GPA;
        this->Fees=Fees;
    }
    void display()
    {
        Person::display();
        cout<<"GPA: "<<GPA<<endl;
        cout<<"Fees: "<<Fees<<endl;
    }
    void disp(){}
};
class Employee: public Person
{
    double BasicSal;
protected:
    double Bonus;
public:
    Employee(double BasicSal, double Bonus, int ID, string Email, string Name):Person(ID,Email,Name)
    {
        this->BasicSal=BasicSal;
        this->Bonus=Bonus;
    }
    double getSalary(double BasicSal, double Bonus)
    {
        return BasicSal+Bonus;
    }  
    double getBasicSal()
    {
        return BasicSal;
    } 
    void display()
    {
        Person::display();
        cout<<"Basic: "<<BasicSal<<endl;
        cout<<"Bonus: "<<Bonus<<endl;
    }
};
class PG_Student:private Student
{
    double thesis;
public:
    PG_Student(double thesis, double GPA, double Fees, int ID, string Email, string Name):Student(GPA,Fees,ID,Email,Name)
    {
        this->thesis=thesis;
    }
    void display()
    {
        Student::display();
        cout<<"Thesis: "<<thesis<<endl;
    }
};
class Staff_Officers:public Student, public Employee
{
protected:
    string Designation;
public:
    Staff_Officers(string Designation, double BasicSal, double Bonus, double GPA, double Fees, int ID, string Email, string Name):Employee(BasicSal,Bonus,ID,Email,Name),Student(GPA,Fees,ID,Email,Name)
    {
        this->Designation=Designation;
    }
    double getSal()
    {
        return getBasicSal() + Bonus + Fees;
    }
    void display()
    {
        Student::disp();
        Employee::display();
        cout<<"Designation: "<<Designation<<endl;
    }
};
int main()
{
    PG_Student pg(2.00,2.00,450.00,202114061,"ik11150100218@gmail.com","Imran");

    pg.display() ;

    Staff_Officers stf("Garrage Manager",1.00,1.00,2.00,450.00,202114093,"angelProvee@olly.com","Oggy&Olly");
    
    stf.display() ;

    return 0 ;
}
