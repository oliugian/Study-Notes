#include <stdio.h>
int main(void)
{  int a[14],i,j,k,n=13;
   for (i=1;i<=13;i++)
      a[i]=i;
   for (k=1;k<=8;k++)
   {
       printf("%d ",a[1]);
       for (i=2;i<=n;i++)
	  a[i-1]=a[i];
       n--;
       for (i=1;i<=k;i++)
       {
	  for (j=1;j<=n;j++)
	      a[j-1]=a[j];
	  a[n]=a[0];
       }
    }
    printf("\n");
}

