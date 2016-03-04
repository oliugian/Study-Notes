/*  Josephus.c    */
#define N 26
#include <stdio.h>
int main(void)
{  static int a[N+1],b[N+1];
   int i,j,s,m,p;
   scanf("%d%d",&s,&m);
   for (i=1;i<=N;i++) a[i]=i;
   i=s-1;j=0;p=0;
   while (p<N)
   {  i++;
      bh:
      if (i>N) i-=N;
      if (a[i]==0) {i++;goto bh;}
      j++;
      if (j%m==0){ p++;b[p]=a[i];a[i]=0;j=0; }
   }
   for (i=1;i<=N;i++) printf("%3d",b[i]);
   printf("\n");
}

