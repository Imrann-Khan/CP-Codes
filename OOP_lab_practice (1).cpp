#include <iostream>
using namespace std;

class Person
{
    int ID;
protected:
    string name;
    string Email;
public:
    void display()
    {
        cout.precision(15);
        cout<<"Name :"<<name<<"\nID :"<<ID<<"\nEmail :"<<Email;

    }
    void set_ID(int id)
    {
        this->ID = id;
    }
    void set_name(string name)
    {
        this->name=name;
    }
    void set_con(string Email )
    {
        this->Email= Email;
    }
    Person(int ID, string name, string Email)
    {
        this->ID = ID;
        this->name = name;
        this->Email = Email;
    }
};

class Student : protected Person
{
    float GPA;
protected :
    int Fees;
public :
    void display()
    {
        Person :: display();
        cout<< "\nGPA :" << GPA << "\nFees : "<< Fees ;
    }
    Student(int  Fees,float GPA, int ID, string name, string Email) : Person(ID, name, Email)
    {
        this->Fees=Fees;
        this->GPA=GPA;
    }
    getFees()
    {
        return Fees;
    }
};

class Employee : public Person
{
    int Basic_Sal;
protected:
    int Bonus;
public:
    void display()
    {
        Person :: display();
        cout << "\nBasic Salary : " << Basic_Sal << "\nBonus : " << Bonus ;
    }
    int getSal()
    {
        return Basic_Sal+Bonus;
    }
    Employee(int Basic_Sal,int Bonus,int ID, string name, string Email) : Person(ID, name, Email)
    {
        this->Basic_Sal=Basic_Sal;
        this->Bonus=Bonus;
    }
};

class PG_Student : private Student
{
    int thesis_marks;
public:
    void display()
    {
        Student :: display();
        cout << "\nThesis Marks : " << thesis_marks;
    }
    PG_Student(int thesis_marks,int  Fees,float GPA, int ID, string name, string Email) : Student(Fees, GPA, ID, name, Email)
    {
        this->thesis_marks=thesis_marks;
    }
};

class Staff_Officer : public Employee , public Student
{
protected:
    string Designation;
public:
    void display()
    {
        Employee :: display();
        Student :: display();
        cout << "\nDesignation : " << Designation ;
    }
    int getSal()
    {
        return Employee :: getSal()-getFees();
    }
    Staff_Officer(string Designation,int Basic_Sal,int Bonus,int  Fees,float GPA,int ID, string name, string Email): Employee(Basic_Sal,Bonus,ID, name, Email),Student(Fees, GPA, ID, name, Email)
    {
        this->Designation=Designation;
    }
};
int main ()
{
    Person P(93,"Sheikh","rafsanprove@gmail.com");
    P.display();
    Student S(23000,3.2,93,"Sheikh","rafsanprove@gmail.com");
    S.display();
    Employee E();
    PG_Student PG(140,23000,3.2,93,"Sheikh","rafsanprove@gmail.com");
    PG.display();
    Staff_Officer SO("General manager",95000,140,23000,3.2,93,"Sheikh","rafsanprove@gmail.com");
    SO.display();
}
