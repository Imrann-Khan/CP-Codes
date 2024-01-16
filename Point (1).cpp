#include<iostream>
#include<math.h>
using namespace std;
class Point
{

    int x,y;
public:
    Point()
    {
    }
    Point(int a,int b)
    {
        x=a;
        y=b;
    }
    void print()
    {
        cout<<x<<" , "<<y<<endl;
    }
    float operator-(Point p2)
    {
        float dist= sqrt((this->x-p2.x)*(this->x-p2.x)+(this->y-p2.y)*(this->y-p2.y));
        return dist;
    }
    friend bool operator>(Point p1,Point p2);

//    Point operator*=(int n)
//    {
//        this->x=this->x*n;
//        this->y=this->y*n;
//        return *this;
//    }

    friend bool operator<=(int n,Point p2);
    friend void operator*=(Point &p,int n);
    //friend float operator-(Point p1,Point p2);
};
//float operator-(Point p1,Point p2)
//{
//    float dist= sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
//    return dist;
//}
void operator*=(Point &p,int n)
    {
        p.x=p.x*n;
        p.y=p.y*n;
        //return p;
    }
bool operator<=(int n,Point p2)
{
    if(p2.x>=n && p2.y>=n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator>(Point p1,Point p2)
{
    if(p1.x>0 && p1.y>0 && p2.x>0 && p2.y>0)
    {
        if(p1.x>p2.x)
            return true;
        else
            return false;

    }
    else if(p1.x<0 && p1.y>0 && p2.x<0 && p2.y>0)
    {
        if(p1.x>p2.x)
            return true;
        else
            return false;
    }
    else if(p1.x<0 && p1.y<0 && p2.x<0 && p2.y<0)

    {
        if(p1.x>p2.x)
            return true;
        else
            return false;
    }
    else if(p1.x>0 && p1.y<0 && p2.x>0 && p2.y<0)
    {
        if(p1.x>p2.x)
            return true;
        else
            return false;
    }
    else
    {
        if(p1.x>p2.x && p1.y>0 && p2.y>0)
            return true;
        else if(p1.x<p2.x && p1.y<0 && p2.y<0)
            return true;
        else if(p1.y>p2.y)
            return true;
        else
            return false;
    }
}
int main()
{
    Point p1(4,4),p2(3,2);
    float distance= p1-p2;
    cout<<distance<<endl;

    if(p1>p2)
    {
        cout<<"P1 is greater than P2"<<endl;
    }
    else
    {
        cout<<"P2 is greater than P1"<<endl;
    }

    if(2<=p1)
    {
        cout<<"P1 is greater than (2,2)"<<endl;
    }
    else
    {
        cout<<"(2,2) is greater than P1"<<endl;
    }

    p1*=-1;
    p1.print();
}







