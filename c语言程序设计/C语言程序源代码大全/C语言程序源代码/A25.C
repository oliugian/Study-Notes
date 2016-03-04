#include <math.h>
main()
{  int x,y,u,v,k,t;
   scanf("%d%d",&u,&v);
   x=u;y=v;k=1;
   while (x%2==0&&y%2==0){x=floor(x/2);y=floor(y/2);k*=2;}
   if (x%2!=0) {t=-y;goto bh2;} else t=x;
   bh1:t=floor(t/2);
   bh2:if (t%2==0) goto bh1;
   if (t>0) x=t;else y=-t;
   t=x-y;
   if (t!=0) goto bh1;else x*=k;
   printf("%d\n",x);
}


