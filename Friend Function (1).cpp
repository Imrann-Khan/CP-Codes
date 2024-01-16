#include<bits\stdc++.h>
using namespace std;

class student
{
    float cgpa;
    string status;
public:
    string name;
    int id;

    student(string name,int id)
    {
        this->name=name;
        this->id=id;
    }

    void print()
    {
        cout << "NAME:" << name <<"ID:" << id << "\n";
    }
friend    student update_cgpa(student st);
friend    void print_cgpa(student st);
};
class A
{
    int i;
    double d;
    char c;
public:

int sum(A s2)
{
    return i+s2.i;
}
public:
    A(int x)
    {
        i=x;
    }
};
student update_cgpa(student st)
{
    st.cgpa=3.67;
    if(st.cgpa>2)
        st.status="PASSED";
    else st.status="FAILED";
    return st;
}
void print_cgpa(student st)
{
    cout << st.name << st.cgpa << st.status;
}
int main()

{
    /*student s1("maria",2034);

    s1.print();
    s1=update_cgpa(s1);

    print_cgpa(s1);*/
    A ob1(15),ob2(30);
    int sum=ob1.sum(ob2); /// SAME CLASS SAME FAMILY. SO ACCESS ALLOWED ///
    cout << sum;

    return 0;
}
