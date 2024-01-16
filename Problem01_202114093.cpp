#include<iostream>
#include<math.h>
using namespace std;

class Point
{
public:
    int x,y;

    Point(int x, int y)
    {
        this->x=x;
        this->y=y;
    }
    void print()
    {
        cout << x << " " << y;
    }

    /*
    double operator -(Point p2)
    {
        return sqrt((this->x - p2.x)*(this->x - p2.x)+(this->y - p2.y)*(this->y - p2.y));
    }
    */


    Point operator *=(int p)
    {
        this->x*=p;
        this->y*=p;

        return *this;
    }


    friend double operator -(Point p1,Point p2);
};

double operator -(Point p1,Point p2)
    {
        return sqrt((p1.x - p2.x)*(p1.x - p2.x)+(p1.y - p2.y)*(p1.y - p2.y));
    }

bool operator >(Point p1, Point p2)
{
    int pq1=0,pq2=0;
    if(p1.x>=0 && p1.y>=0) pq1=1;
    if(p1.x<0 && p1.y>=0) pq1=2;
    if(p1.x<0 && p1.y<0) pq1=3;
    if(p1.x>=0 && p1.y<0) pq1=4;

    if(p2.x>=0 && p2.y>=0) pq2=1;
    if(p2.x<0 && p2.y>=0) pq2=2;
    if(p2.x<0 && p2.y<0) pq2=3;
    if(p2.x>=0 && p2.y<0) pq2=4;

    //if( (p1.x>=0 && p2.x>=0 && p1.y>=0 && p2.y>=0) || (p1.x<0 && p2.x<0 && p1.y<0 && p2.y<0) || (p1.x>=0 && p2.x>=0 && p1.y<0 && p2.y<0) || (p1.x<0 && p2.x<0 && p1.y>=0 && p2.y>=0) )
    if(pq1==pq2)
    {
        if(p1.x > p2.x) return true;
        else return false;
    }
    else if(pq1<pq2) return true;
    else return false;
}

bool operator <=(int p, Point p1)
{
    if(p1.x>p && p1.y>p) return true;
    else return false;
}
/*
Point operator *=(Point &p1,int p)
{
    p1.x*=p;
    p1.y*=p;

    return p1;
}
*/
int main()
{
    int x1,y1,x2,y2,m;
    cin >> x1 >> y1 >> x2 >> y2 >> m;
    Point p1(x1,y1),p2(x2,y2);
    /*
    double distance=p1-p2;
    cout << distance << endl;
    */

    /*
    if(p1>p2)
        cout << "P1 is greater than P2" ;
    else
        cout << "P2 is greater than P1" ;
    */

    /*
    if(m<=p1)
        cout << "P1 is greater than or equal to point(" << m << ", " << m << ")" ;
    else
        cout << "Point (" << m << ", "  << m << ")" << "is greater than or equal to P1" ;
    */

    p1*=-1;
    p1.print();

    return 0;
}
