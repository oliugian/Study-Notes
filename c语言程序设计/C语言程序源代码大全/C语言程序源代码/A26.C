#include <math.h>
main()
{  int x,y,u,v,k;
   scanf("%d%d",&u,&v);
   x=u;y=v;k=1;
   while (x%2==0&&y%2==0){x=floor(x/2);y=floor(y/2);k*=2;}
   while (x!=y)
   {  while (x%2==0) x=floor(x/2);
      while (y%2==0) y=floor(y/2);
      while (x>y) x-=y;
      while (x<y) y-=x;
   }
   x*=k;
   printf("%d\n",x);
}


