#include<bits/stdc++.h>
using namespace std;

void f(char *p){
    char *q = new char[strlen(p)+1];
    for(int i=0; i<strlen(p); i++){
        q[i] = p[i];
    }
    q[strlen(p)] = '\0';
}

int main(){
    f("abc");
}
