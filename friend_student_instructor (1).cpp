/*** FRIEND FUNCTION ***/

#include <iostream>
using namespace std;

class student; //forward declaration

class instructor  
{
    public:
    student updateCGPA(student, float);  //function prototypes only
    void printstatus(student);
};

class student
{
    private:
    float cgpa;
    string status; //"passed if cgpa>2, otherwise failed"
    
    public:
    string name;
    int id;
    
    student(string name, int id)  //constructor
    {
        this->name = name;
        this->id = id;
    }
    
    void print()
    {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
    
    friend student update_cgpa(student, float);  //friend global function
    
    friend student instructor :: updateCGPA(student, float);  //friend class member function
    friend void instructor :: printstatus(student);  //friend class member function
    
    //friend class instructor;  //friend class
};

student update_cgpa(student st, float cgpa_)  //global function
{
    st.cgpa = cgpa_;
    if(st.cgpa>2)
    {
        st.status = "Passed";
    }
    else
    {
        st.status = "Failed";
    }
    
    return st;
}

student instructor :: updateCGPA(student st, float cgpa_)  //defining class member function
{
    st.cgpa = cgpa_;
    if(st.cgpa>2)
    {
        st.status = "Passed";
    }
    else
    {
        st.status = "Failed";
    }
    
    return st;
}

void instructor :: printstatus(student st)
{
    cout << st.name << ", ID " << st.id << ", status " << st.status << " with CGPA " << st.cgpa;
}

int main()
{
    student st1("Maria", 30);
    //st1.print();
    
    //st1 = update_cgpa(st1, 3.6);
    
    instructor ins;
    st1 = ins.updateCGPA(st1, 3.88);
    
    ins.printstatus(st1);
}
