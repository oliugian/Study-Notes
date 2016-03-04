/* Optimization - - 一维搜索 */

double newton(eps,x0,f1,f2)    /* Newton 法 */
double x0,eps;
double (*f1)(),(*f2)();
{  double ls;
   int k=0;
   do
   { printf("%d  %f\n",k,x0);
     ls=x0;
     x0=x0-((*f1)(x0)/(*f2)(x0));
     k=k+1;
   }
   while (fabs(x0-ls)>eps);
   return (x0);
}

double binary(a,b,eps,f1)      /* 二分法 */
double a,b,eps;
double (*f1)();
{  double x,fa,fx;
   fa=f1(a);
   do
   {  x=(a+b)/2.0;
      fx=f1(x);
      if (fa*fx>0) a=x;
      else         b=x;
    }
    while (fabs(b-a)>eps);
    x=(a+b)/2.0;
    return (x);
}

