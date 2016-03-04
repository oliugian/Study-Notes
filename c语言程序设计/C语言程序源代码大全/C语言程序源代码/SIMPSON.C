#define N 10
#include  <stdio.h>
#include <math.h>
double f(x)
double x;
{double y;y=exp(x);
 return y;}
double simpson(a,b)
float a,b;
{double h,x,s;
 s=f(a)-f(b);
 h=(b-a)/10; x=a;

 do{x=x+h/2;s=s+4*f(x);
    x=x+h/2;s=s+2*f(x);}
 while(x<b);
 s=s*h/6;
 return(s);}

main()
{float a,b,s;
 scanf("%f,%f",&a,&b);
 s=simpson(a,b);
 printf("%16.12f\n",s);}