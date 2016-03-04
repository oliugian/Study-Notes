#include <math.h>
main()
{  int r,q,w,x,y;
   scanf("%d%d",&x,&y);
   r=x;q=0;w=y;
   while (w<=x) w*=2;
   while (w!=y)
   {  q*=2;w=floor(w/2);
      if (w<=r) {r-=w;q++;}
   }
   printf("%d,%d\n",q,r);
}
