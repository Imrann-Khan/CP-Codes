#include<bits/stdc++.h>
using namespace std;

class A{
    int a,b;
public:
    A(int a, int b){
        this->a = a;
        this->b = b;
    }

    A(int a){
        this->a = a;
        this->b =0;
    }
};

int main(){
    A ob1(2,3), ob2(5);
    A ob3 = ob1;
}
