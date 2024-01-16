#include<bits/stdc++.h>
using namespace std;
class Toyota{
    string modelname;
    int year;
    string color;
    public:
   void setmodelname(string modelname)
   {
       this->modelname=modelname;
   }
   string getmodelname(string modelname)
   {
       return modelname;
   }
   void setyear(int year)
   {
       this->year=year;
   }
   int getyear(int year)
   {
       return year;
   }
   void setcolor(string color)
   {
    this->color=color;
   }



void compare(Toyota s,Toyota s1)
{
    if(s.modelname==s1.modelname&&s.year==s1.year&&s.color==s1.color)
    {
        cout<<"Same Car "<<endl;

    }
    else{
        cout<<"Different Car "<<endl;
    }
}
};

int main()
{
    Toyota s,s1;
    string modelname,color;
    int year;
    cout<<"Enter the model of first car :"<<endl;
    cin>>modelname;
    s.setmodelname(modelname);
    cout<<"Enter the year of first model car :"<<endl;
    cin>>year;
    s.setyear(year);
    cout<<"Enter the color of first model car :"<<endl;
    cin>>color;
    s.setcolor(color);

    cout<<"Enter the model of second car :"<<endl;
    cin>>modelname;
    s1.setmodelname(modelname);
    cout<<"Enter the year of second model car :"<<endl;
    cin>>year;
    s1.setyear(year);
    cout<<"Enter the color of second model car :"<<endl;
    cin>>color;
    s1.setcolor(color);
    s.compare(s,s1);
}
