#define N 10
#include <stdio.h>

int main(void)
{  int ft();void print();
   int m=1,n,a[N],i,j,k;
   scanf("%d",&n);
   for (k=2;k<=n;k++)
   {
      for (i=1;i<k;i++) a[i]=1;
      a[k]=n-k+1;print(a,m,n,k);m++;
      j=k-1;
      do
      {	 while(a[j]<a[j+1])
	 {
	    a[j]++;a[j+1]--;
	    if(ft(a,k)){print(a,m,n,k);m++;}
	 }
	 j--;
       } while(j>=1);
   }
   return 0;
}

int ft(int a[],int size)
{
   int k;
   for (k=1;k<size;k++)
     if (a[k]>a[k+1]) return 0;
   return 1;
}

void print(int a[],int m,int n,int k)
{  int i;
   printf("m=%2d  %d=",m,n);
   for(i=1;i<k;i++)printf("%d+",a[i]);
   printf("%d\n",a[k]);
}