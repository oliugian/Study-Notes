#include<stdio.h>
#define N 6
main()
{int a[N]={4,5,3,6,1,8};
 int i,j,t;
 for(i=1;i<=N;i++)
 scanf("%d",&a[i]);
  printf("\n");
  for(j=0;j<N-i;j++)
  if(a[j]>a[j+1])
  {t=a[i];
  a[j]=a[j+1];
  a[j+1]=t;};
  for(i=1;i<N;i++)
  printf("%5d",a[i]);
  }