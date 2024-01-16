#include<stdio.h>
void rec(int n)
{
    int a=0,b=0;
    int c=a+b;
    if(n==1)
        printf("1,");
    else
    printf(" %d",c);
    rec(n-1);
}
int main()
{
    int p;
    scanf("%d",&p);
    rec(p);
    return 0;
}
