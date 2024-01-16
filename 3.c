#include <stdio.h>
#include<string.h>
int main()
 {
   char a[100],b[100];
   int c;
   gets(a);
   gets(b);
   c=strcmp(a,b);
   printf("%d",c);
   return 0;
}
