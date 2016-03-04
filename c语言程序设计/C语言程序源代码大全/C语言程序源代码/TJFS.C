#include <stdio.h>
main()
{  int i,j,n,s,max,min,a[1000];
   float average;
   for(i=1;i<=1000;)
   {  scanf("%d,",&a[i]);
      if(a[i]>=0)i++;
      else break;
   }
   s=0; max=0; min=100;
   for(j=1;j<=i-1;j++)
      s+=a[j];
   n=j-1; average=s/n;
   printf("n=%d\n",n);
   printf("average=%7.2f\n",average);
   for(j=1;j<=n;j++)
      if(a[j]>=max)max=a[j];
   printf("max=%d\n",max);
   for(j=1;j<=n;j++)
      if(a[j]<=min)min=a[j];
   printf("min=%d\n",min);
}