#include<stdio.h>
#include<math.h>
int main()
{
    int count=0,flag=1;
    double g,x,phi,positive;//phi for error of trial.

    printf("Initial guess:");
    scanf("%lf",&g);

    while(flag)
        {
        count++;//for number of trials.
        if(count==10000) flag=0;
        positive=10.0-3.0*pow(g,2);

            if(positive>0)
            {
                x=pow(positive,0.2);
                phi=fabs(x-g);

                if(phi>.000000001) g=x;
                else
                {
                    flag=0;
                    printf("\n\nEquation's Root=%.10lf",x);
                    printf("\nNumber of trials=%d\n",count);
                    break;
                }
            }

            else
            {
                flag=0;
                printf("\n\nNumber you've guessed is not close\nenough to the root.\nTry another initial guess.\n");
            }
        }
     return 0;
}
