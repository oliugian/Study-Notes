#include <math.h>
#include <stdio.h>
#define M 9999
#define N 9
#define N1 4
float linar(a,b,c,m,n,p)
int m,n;
float a[][N],b[],c[];
int p[];
{  float sigma[N],z[N],s,d,sita[N1];
   int i,j,k,l,flag;
   flag=1;
   while (flag==1)
   {
      for (i=1;i<=m;i++)
      {  printf("x%d   %6.2f  %6.2f  ",p[i],c[p[i]],b[i]);
	 for (j=1;j<=n;j++) printf("%6.2f  ",a[i][j]);
	 printf("\n");
      }
      sigma[0]=M;
      for (j=1;j<=n;j++)
      {  s=0;
	 for (i=1;i<=m;i++) s=s+a[i][j]*c[p[i]];
	 sigma[j]=c[j]-s;
	 if (sigma[j]<sigma[0]) {k=j;sigma[0]=sigma[j];}
      }
      printf("             ");
      for (j=0;j<=n;j++) printf("%6.2f  ",sigma[j]);
      printf("\n");
      if (sigma[0]==0) flag=0;
      else
      {  sita[0]=M;
	 for (i=1;i<=m;i++)
	   if (a[i][k]>0)
	   {  sita[i]=b[i]/a[i][k];
	      if (sita[i]<sita[0]) {l=i;sita[0]=sita[i];}
	   }
	 if (sita[0]!=M)
	 {  p[l]=k;
	    printf("             ------------  l=%d  ------  k=%d  -----------\n",l,k);
	    b[l]=b[l]/a[l][k];
	    d=a[l][k];
	    for (j=1;j<=n;j++)  a[l][j]=a[l][j]/d;
	    for (i=1;i<=m;i++)
	      if (i!=l)
	      {  b[i]=b[i]-b[l]*a[i][k];
		 for (j=1;j<=n;j++) a[i][j]=a[i][j]-a[i][k]*a[l][j];
	      }
	 }
	 else
	 {  printf("no bound!\n");
	    return(0);
	 }
      }
  }
  s=0;
  for (i=1;i<=m;i++) s=s+c[p[i]]*b[i];
  return (s);
}
main()
{ static float c[N]={0,0,0.1,0.2,0.3,0.8,M,M,M};
  static float a[N1][N]={{0},{0,1,2,0,1,0,1,0,0},
			     {0,0,0,2,2,1,0,1,0},
			     {0,3,1,2,0,3,0,0,1}};
  static float b[N1]={0,100,100,100};
  static int p[N1]={0,6,7,8};
  int i;
  float min;
  min=linar(a,b,c,N1-1,N-1,p);
  printf("mins=%f\n",min);
  for (i=1;i<N1;i++) printf("x%d=%f  ",p[i],b[i]);
  printf("\n");
}
