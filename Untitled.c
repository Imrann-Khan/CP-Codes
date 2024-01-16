#include<stdio.h>
#include<string.h>

int main()
{
    char a[100];
    char *p;
    gets(a);
    p=&a[0];
    if(a[0]>='a'&&a[0]<='z')
    {*p=a[0]-32;}
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='\0')
        {
            if(a[i+1]>='a'&&a[i+1]<='z')
            {
                a[i+1]=a[i+1]-32;
            }
        }
    }
    puts(a);
    return 0;
}
