#include<bits/stdc++.h>
#define endl "\n"
using namespace std ;

class Person ;
class Employee ;
class Student ;
class Staff_officer ;
class PG_student ;

class Person{
    int ID ;
protected:
    string email ;
public:
    string Name ;
    Person(int ID , string email, string Name){
        this->ID=ID ;
        this->email=email ;
        this->Name=Name ;
    }
    void display(){
        cout << "Name : " << Name << endl ;
        cout << "Id : " << ID << endl ;
        cout << "Email : " << email << endl ;
    }
    void setID(int ID){
        this->ID=ID ;
    }
    void setEmail(string email){
        this->email=email ;
    }
    string getEmail(){
        return email ;
    }
    int getID(){
        return ID ;
    }

};
class Employee : public Person{
    int Basic_sal ;
protected:
    int Bonus ;
public:
    Employee(int ID , string email, string Name ,int Basic_sal ,int Bonus):Person(ID ,email,Name){
        this->Basic_sal=Basic_sal ;
        this->Bonus=Bonus ;
    }
    void display(){
        Person::display() ;
        cout << "Basic Salary : " << Basic_sal << endl ;
        cout << "Bonus : " << Bonus << endl ;
    }
    void setBasic_sal(int Basic_sal){
        this->Basic_sal=Basic_sal ;
    }
    void setBonus(int Bonus){
        this->Bonus=Bonus ;
    }
    int getBasic_sal(){
        return Basic_sal ;
    }
    int getBonus(){
        return Bonus ;
    }
    int getSalary(){
        return Basic_sal + Bonus ;
    }
};
class Student :protected Person{
    double gpa ;
protected:
    double fees ;
public:
    Student(int ID , string email, string Name,double gpa , double fees):Person(ID,email,Name){
        this->fees=fees ;
        this->gpa=gpa ;
    }
    void display(){
        Person::display() ;
        cout << "GPA : " << gpa << endl ;
        cout << "Fees : " << fees << endl ;
    }
    void setGPA(double gpa){
        this->gpa=gpa ;
    }
    void setFees(double fees){
        this->fees=fees ;
    }
    double getGPA(){
        return gpa ;
    }
    double getFees(){
        return fees ;
    }
    int getID(){
        return Person::getID() ;
    }
};
class Staff_officer:public Employee , public Student{
protected:
    string Designation ;
public:
    Staff_officer(int ID , string email, string Name ,int Basic_sal ,int Bonus,double gpa , double fees , string Designation):Employee(ID,email,Name,Basic_sal,Bonus),Student(ID,email,Name,gpa,fees){
        this->Designation=Designation ;
    }
    void display(){
        cout << "\t\tStudent Information" << endl ;
        Student::display() ;

        cout << "\t\tEmployee Information" << endl ;
        Employee::display() ;
        cout << "Designation : " << Designation << endl ;
        cout << "Total Salary(fees deducted) : " << int(Employee::getSalary()-fees) << endl ;
    }
    int getSalary(){
        return Employee::getSalary()-fees ;
    }
    int getFees(){
        return fees ;
    }
};
class PG_student:private Student{
private:
    int thesis_marks ;
public:
    PG_student(int ID , string email, string Name,double gpa , double fees , int thesis_marks):Student(ID,email,Name,gpa,fees){
        this->thesis_marks=thesis_marks ;
    }
    void display(){
        Student::display() ;
        cout << "Thesis marks : " << thesis_marks << endl ;
    }
    int getFees(){
        return Student::getFees() ;
    }
    int getID(){
        return Student::getID() ;
    }
};

int main(){

    cout << "Print (Hello World)" << endl ;

    PG_student pg(202114063,"sabbir_063@gmail.com","Sabbir Musfique",3.36,200,300) ;

    pg.display() ;

    Staff_officer stf(202114117,"zarifmustafa@gmail.com","Zarif Zeisan Mustafa",1000000,50000,3.95,450,"CEO") ;
    
    stf.display() ;

    return 0 ;
}
