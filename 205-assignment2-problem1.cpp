#include<iostream>
using namespace std;
class Toyota
{
    string model_name,color;
    int year;
public:
    string getModelName(){
    return model_name;
    }
    int getYear(){
    return year;
    }
    string getColor(){
    return color;
    }
    void setModelName(string model_name){
    this->model_name=model_name;
    }
    void setYear(int year){
    this->year=year;
    }
    void setColor(string color){
    this->color=color;
    }
    bool sameCar(Toyota x){
string model_name1=this->model_name;
string model_name2=x.getModelName();
int year1=this->year;
int year2=x.getYear();
string color1=this->color;
string color2=x.getColor();
if(model_name1==model_name2 && year1==year2 && color1==color2)
{
    return true;
}
else
    return false;
}
};

int main()
{
    int n,i;
    cout<<"Number of model:";
    cin>>n;
    Toyota x[n];
    for(i=0;i<n;i++)
    {
        string name,color;
        int year;
        cout<<"Name of the car"<<i+1<<endl;
        cin>>name;x[i].setModelName(name);
        cout<<"Year of the car"<<i+1<<endl;
        cin>>year;x[i].setYear(year);
        cout<<"Color of the car"<<i+1<<endl;
        cin>>color;x[i].setColor(color);
    }
        int x1,x2;
        cout<<"input the serial numbers of the cars you want to compare:";
        while(cin>>x1>>x2 && (x1!=0 && x2!=0))
        {
            if(x[x1-1].sameCar(x[x2-1]))
            {
                cout<<"The cars are the same:";
            }
            else
                cout<<"The cars are not the same:"<<endl;
                cout<<"input the serial numbers of the cars you want to compare:";
        }

        return 0;

    }



