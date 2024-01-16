#include<iostream>
#include<math.h>
using namespace std;
class Student
{
    int roll;
    int len;
    char *name;
public:
    Student()
    {
    }
    Student(char *p,int l,int r)
    {
        len=l;
        name=new char[len];
        int i;
        for(i=0; i<len; i++)
        {
            name[i]=p[i];
        }
        roll=r;
    }
    Student(const Student &s)
    {
        len=s.len;
        name=new char[len];
        int i;
        for(i=0; i<len; i++)
        {
            name[i]=s.name[i];
        }
        roll=s.roll;
    }
    void print()
    {
        for(int i = 0; i<len; i++)
            cout<<name[i];
        cout<<endl;
        cout<<roll<<endl;
    }
//    void operator++(int a)
//    {
//        for(int i=0; i<this->len; i++)
//        {
//            this->name[i]=this->name[i]+1;
//        }
//    }
    Student operator++(int a)
    {
        Student temp=*this;
        for(int i=0; name[i]!='\0'; i++)
        {
            this->name[i]=this->name[i]+1;
        }
        this->roll++;
        return temp;
    }
    char& operator[](int i)
    {
        return this->name[i];
    }
    friend void operator++(Student &s);
};
void operator++(Student &s)
    {
        for(int i=0; i<s.len; i++)
        {
            s.name[i]=s.name[i]+1;
        }
    }
int main()
{
    Student s1("cpp",3,202114000);
    Student s2=s1++;
    s2.print();
    s1.print();
    if(s1[0]>='a' && s1[0]<='z')
    {
        s1[0]=s1[0]-32;
    }
    s1.print();
}





