#include<bits/stdc++.h>
using namespace std;

class String
{
int len;
char *ptr;
public: //declare constructor, destructor and copy constructor
    String(int len, char *q)
    {
        this->len=len;
        char *ptr= new char[strlen(q)+1];
        strcpy(ptr,q);
    }
    String(const String &ob)
    {
        this->len=ob.len;
        this->ptr = new char[strlen(ob.ptr)+1];
        strcpy(this->ptr,ob.ptr);
    }

char get(int ind)
{
    //return the character at the given index
    //Check if index is out of bound
    //return 0 in case of error
    if(ind>=strlen(ptr)) return '\0';
    else return ptr[ind];
}
int put(int ind,char c)
{
//Assign character c at position index
//Check if index is out of bound
//return -1 in case of error
    if(ind>=strlen(ptr)) return -1;
    else
    {

        for(int i=len;i>ind;i--)
        {
            ptr[i]=ptr[i-1];
        }
    }
    ptr[ind]=c;
    ptr[strlen(ptr)+1]='\0';
    len++;
}
int getlength()
{
    return strlen(ptr);
}
void print()
{
//print the string upto allocation size
    for(int i=0;i<len;i++) cout<<ptr[i];
    cout<<endl;
}
friend void compare(String s1, String s2);
friend String concat(String s1, String s2);
friend void insert(String s1,int ind,char c);
~String()
{
    delete[] ptr;
}
};

void compare(String s1, String s2)
{
    if(strcmp(s1.ptr,s2.ptr)>=1)
    {
        cout<<" 1 "<<endl;
    }
    else if(strcmp(s1.ptr,s2.ptr)<1)
    {
        cout<<" 2 "<<endl;
    }
    else
    {
        cout<<" 0 "<<endl;
    }
}

String concat(String s1, String s2)
{
    strcat(s1.ptr,s2.ptr);
    return s1;
}

void insert(String s1,int ind,char c)
{
    int len=strlen(s1.ptr);
    if(ind>=strlen(s1.ptr)) cout<<" -1 "<<endl;
    else
    {
        for(int i=len;i>=ind;i--)
        {
            s1.ptr[i]=s1.ptr[i-1];
        }
    }
    s1.ptr[ind]=c;
    s1.ptr[len+1]='\0';
    len++;
}

int main()
{
    int l;
    cin>>l;
    char s[l];
    for(int i=0;i<l;i++) cin>>s[i];
    String ob1(l,&s[0]);
    String ob2=ob1;
    cout<<ob2.getlength()<<" ";
    ob2.print();
}
