#include <math.h>
float x1,x2,d;
float sg(a,b)
float a,b;
{  float disk;
   disk=sqrt(d);
   x1=(-b+disk)/(2*a);
   x2=(-b-disk)/(2*a);
}
main()
{  float a,b,c;
   scanf("%f %f %f",&a,&b,&c);
   d=b*b-4*a*c;
   if (d>0)
   {  sg(a,b);
      printf("x1=%6.2f  x2=%6.2f\n",x1,x2);
   }
}

