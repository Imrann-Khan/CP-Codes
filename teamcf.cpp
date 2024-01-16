#include<iostream>
#include<cmath>
using namespace std;
 double x,y,c,test;
 double float_Iteration(double d){
	return 1-c/sqrt(x*x-d*d)-c/sqrt(y*y-d*d);
}
int main(){
	int n;
	scanf("%d",&n);
	if(n<=10){
	while(n){
		scanf("%lf %lf %lf",&x,&y,&c);
		double min;
	    min=(x<y)?x:y;
		double dist1=0;
		while(dist1+1e-12<min){
			test=(dist1+min)/2;
			if(float_Iteration(test)>0) dist1=test;
			else min=test;
		}
		printf("%.8lf\n",dist1);
		n--;
	 }
	}
	return 0;
}
