#include <stdio.h>
#define N 51
float rand()
{  static int seed=1;
   int c1,c2,c3;
   c1=29;c2=217;c3=1024;
   seed=(seed*c1+c2)%c3;
   return (float)seed/c3;
}
main()
{  int a[N][2],k;
   for(k=0;k<N;k++)
   {  a[k][0]=21*rand();
      a[k][1]=(20-a[k][0])*rand();
   }

   for(k=0;k<N;k++)
   {   if(k%3==0)printf("\n\n");
       printf("%3d +%3d =           ",a[k][0],a[k][1]);
   }
   printf("\n");
}




