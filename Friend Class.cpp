#include<bits/stdc++.h>
#include<math.h>
using namespace std;
class real_num;
class complex_num
{
    float real, imaginary;
public:
    setReal(float real)
    {
        this -> real= real;
    }
    setImaginary(float imaginary)
    {
        this -> imaginary= imaginary;
    }

    friend class real_num;
};

class real_num
{
    int i;
public:
    setI(int i)
    {
        this -> i=i;
    }
    void sum(complex_num c)
    {
        double x=i+c.real+c.imaginary;
        cout << x;
    }
};

int main()
{
    int k;
    float f1,f2;
    cin >> k >> f1 >> f2;
    complex_num cmp;
    real_num rl;
    rl.setI(k);
    cmp.setReal(f1);
    cmp.setImaginary(f2);
    rl.sum(cmp);
}
