#include<iostream>
using namespace std;

///Forward Declaration
class B ;
class C ;
class D ;
class F ;
class G ;

class A{
    int a1 ;
protected:
    int a2 ;
public:
    string a3 ;
    A(int a1 , int a2,string a3){
        this->a1=a1 ;
        this->a2=a2 ;
        this->a3=a3 ;
    }
    virtual double fa()=0 ;
    ~A(){
	/// cout << "Destructor of A is called" << endl ;
    }
    int getA1(){
        return a1 ;
    }
    virtual void display(){
    // cout << "called from Class A" << endl ;
    cout << a1 << " " << a2 << " " << a3 ;
    }
};
class B: virtual public A{
    double b1 ;
protected:
    int b2 ;
private:
    double fb(){
        return b1+b2 ;
    }
public:
    B(int a1 , int a2,string a3,double b1,int b2):A(a1,a2,a3){
        this->b1=b1 ;
        this->b2=b2 ;
    }
    ~B(){
	/// cout << "Destructor of B is called" << endl ;
    }
    double getB1(){
        return b1 ;
    }
    double getFb(){
       return fb() ;
    }
    double fa(){
        return getA1()+a2+b1+b2 ;
    }
    void display(){
        // cout << "called from Class B" << endl ;
        A::display() ; cout << " " << b1 << " " << b2 ;
    }
};
class C:virtual public B{
public:
    int c1 ;
    C(int a1 , int a2,string a3,double b1,int b2,int c1):B(a1,a2,a3,b1,b2),A(a1,a2,a3){
        this->c1=c1 ;
    }
    virtual ~C(){
	/// cout << "Destructor of C is called" << endl ;
    }
    void display(){
        B::display() ; cout << " " << c1 ;
    }
};
class D:virtual public B{
public:
    int d1 ;
    D(int a1 , int a2,string a3,double b1,int b2,int d1):B(a1,a2,a3,b1,b2),A(a1,a2,a3){
        this->d1=d1 ;
    }
    virtual ~D(){
	/// cout << "Destructor of D is called" << endl ;
    }
    void display(){
        B::display() ; cout << " " << d1 ;
    }
};
class F:virtual public A{
protected:
    float f1 ;
public:
    F(int a1 , int a2,string a3,float f1):A(a1,a2,a3){
        this->f1=f1 ;
    }
    ~F(){
	/// cout << "Destructor of F is called" << endl ;
    }
    double ff(){
        return getA1()+a2+f1 ;
    }
    double getF1(){
        return f1 ;
    }
    void display(){
        A::display() ; cout << " " << f1 ;
    }
};
class G:public B,private F{
public:
    char g ;
    G(int a1 , int a2,string a3,double b1,int b2,float f1,char g):B(a1,a2,a3,b1,b2),F(a1,a2,a3,f1),A(a1,a2,a3){
        this->g=g ;
    }
    ~G(){
	/// cout << "Destructor of G is called" << endl ;
    }
    void display(){
        B::display() ; cout << " " << getF1() << " " << g ;
    }
    double fb(){
        return getFb() ;
    }
    double ff(){
        return F::ff()+(int)g ;
    }
};
template<typename typeofE1>class E:public C,public D{
public:
    typeofE1 e1 ;
    E(int a1 , int a2,string a3,double b1,int b2,int c1,int d1,typeofE1 e1):C(a1,a2,a3,b1,b2,c1),D(a1,a2,a3,b1,b2,d1),B(a1,a2,a3,b1,b2),A(a1,a2,a3){
        this->e1=e1 ;
    }
    ~E(){
	/// cout << "Destructor of E is called" << endl ;
    }
    void display(){
        D::display(); cout << " " << c1 << " " << e1 ;
    }
};
int main()
{
	//    create an object of class E (For BONUS MARKS)    
	E<float> E1(21,22,"E's String",23,24,25,26,27.27);
	cout << "Printing Elements of E" << endl ;
    E1.display(); cout << endl << endl ;

///Object of Abstract Class cant be declared 
//    A A1(1,2,"new");
//    create an object of class A

   	B B1(3,4,"B's String",9,10);
	cout << "Printing Elements of B" << endl ;
	B1.display() ; cout << endl << endl ;

	C C1(11,12,"C's String",13,14,15);
	cout << "Printing Elements of C" << endl ;
	C1.display() ; cout << endl << endl ;

	G G1(16,17,"G's String",18,19,20.20,'G');
	cout << "Printing Elements of G" << endl ;
	G1.display() ; cout<< endl << endl ;

	cout << "Delegate functions (Accessing Private Property)" << endl ;
	cout << G1.fb() << endl ; //make sure this works
	cout << G1.ff() << endl ; //or appropriate delegate function
	cout << endl << endl ;

	cout << "Object Slicing" << endl ;
	/// now it is late binding
	// But if we cout 'virtual' from class A's display, then it is early binding
	// if you cut virtual from A , output will be 5 6 Sabbir
	// now edit and try it
        B obj(5,6,"Sabbir",7,8) ;
        A * ptr;
        ptr = &obj;
	ptr->display() ;

	return 0 ;
}
