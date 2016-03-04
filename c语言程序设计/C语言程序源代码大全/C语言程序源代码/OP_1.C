#include <stdio.h>
#include <math.h>
#include "op2-2.c"
int main(void)
{  double f1(),f2(),f(),binary(),newton();
   double eps,x0,x,y;
   eps=0.001;
   x0=3.0;

   x=binary(1.0,6.0,eps,f1);
/*   x=newton(eps,x0,f1,f2);*/
   y=f(x);

   printf("min point x=%f,min value y=%f\n",x,y);
   return (0);
}

double f(double x)
{  double fx;
   fx=(((x-4)*x-6)*x-16)*x+4;
   return (fx);
}

double f1(double x)
{  double fx;
   fx=4*(((x-3)*x-3)*x-4);
   return (fx);
}

double f2(double x)
{  double fx;
   fx=12*((x-2)*x-1);
   return (fx);
}
