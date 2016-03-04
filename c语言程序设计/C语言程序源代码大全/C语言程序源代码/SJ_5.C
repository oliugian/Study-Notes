#include <stdio.h>
#define N 100
int main(void)
{  int a[N],i,j,k,p,q,x,y;
   a[0]=1;i=j=0;
   for (k=1;k<100;k++)
   {  p=a[i];q=a[j];
      x=2*p+1;y=3*q+1;
      if (x>y) { a[k]=y;j++;}
      else if (x<y) { a[k]=x;i++;}
      else { a[k]=x;i++;j++;}
   }
   for (k=0;k<100;k++)
   {  if (k%10==0) putchar('\n');
      printf("%5d",a[k]);
   }
}
