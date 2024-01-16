#include<iostream>
using namespace std;
class time
{
    int hour,minute,second;
    public:
    int getHour(){
    return hour;
    }
    int getMinute(){
    return minute;
    }
    int getSecond(){
    return second;
    }
    void setHour(int hour)
    {
        this->hour=hour;
    }
    void setMinute(int minute)
    {
        this->minute=minute;
    }
    void setSecond(int second){
    this->second=second;
    }
    friend void timeDiff(time ob1,time ob2);

};
void timeDiff(class time ob2, class time ob1)
    {
        int city1=ob1.hour*3600+ob1.minute*60+ob1.second;
        int city2=ob1.hour*3600+ob2.minute*60+ob2.second;
        int diff=abs(city1-city2);
        int hr=diff/3600;
        int mins=(diff%3600)/60;
        int sec=(diff%3600)%60;
        cout<<"Time difference between two cities"<<hr<<":"<<mins<<":"<<sec<<endl;
    }

int main()
{
    int h1,m1,s1,h2,m2,s2;
    cout<<"first time info:"<<endl<<"hour:";
    cin>>h1;
    cout<<"minute:";
    cin>>m1;
    cout<<"second:";
    cin>>s1;
    cout<<endl;
    cout<<"second time info:"<<endl<<"hour:";
    cin>>h2;
    cout<<"minute:";
    cin>>m2;
    cout<<"second:";
    cin>>s2;
    class time ob1,ob2;
    ob1.setHour(h1);
    ob1.setMinute(m1);
    ob1.setSecond(s1);
    ob2.setHour(h2);
    ob2.setMinute(m2);
    ob2.setSecond(s2);
    timeDiff(ob1,ob2);
}

