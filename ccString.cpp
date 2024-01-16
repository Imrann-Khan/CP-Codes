#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    int a;
    char *c;
public:

    A (int p, char *q){
        a = p;
        c = new char[strlen(q) + 1];
        strcpy(c,q);
    }

    A (const A &ob){
        this->a = ob.a;
        this->c = new char [strlen(ob.c)+1];
        strcpy(this->c, ob.c);
    }
};

int main(){
    A ob1(5, "Hello");
    A ob2 = ob1;
    ob2.c[0] = 'P';
    cout<<ob1.c;
}

