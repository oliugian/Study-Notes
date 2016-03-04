#define N 199
#define NN 7000
#include <stdio.h>
int main(void)
{
   static int a[NN]={0},b[NN]={0};
   int i,j,k,m,n,x;
   n=N;i=0;
   while (n!=0)
   {
      a[i]=b[i]=n%10;
      i++;
      n=(n-n%10)/10;
   }
   for(k=1;k<N;k++)
   {
      for(i=0;i<NN;i++)
	 b[i]=a[NN-i-1];
      i=0;
      while (b[i]==0)i++;
      for(m=0;m<NN;m++)
	 b[m]=a[m];
      for (m=1;m<N;m++)
      {
/*	 printf("k=%d,m=%d\n",k,m);*/
	 x=0;
	 for(j=0;j<NN;j++)
	 {
	    if (b[j]==0&&x==0&&j>NN-i) break;
	    a[j]=a[j]+b[j]+x;
	    if (a[j]>9)
	    {
	       a[j]=a[j]%10;
	       x=1;
	    }
	    else x=0;
	 }
      }
   }
   for (k=0;k<(NN-1)/2;k++)
   {
      x=a[k];a[k]=a[NN-k-1];a[NN-k-1]=x;
   }
   m=0;
   while (a[m]==0)m++;
   printf("%d^%d=",N,N);
   for (k=m;k<NN;k++)
      printf("%d",a[k]);
   printf("\n");
   return 0;
}


