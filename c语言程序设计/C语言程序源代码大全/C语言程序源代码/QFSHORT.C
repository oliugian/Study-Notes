#include <stdlib.h>
void qfshort(f,n,k,max,e)
int n,k;
double f[],max,e[];
{  int *s,*r,i,top,j;
   double h,t;
   s=malloc(n*sizeof(int));
   r=malloc(n*sizeof(int));
   for (i=0;i<=n-1;i++) {r[i]=0;e[i]=max;}
   e[k]=0.0;r[k]=1;top=0;s[top]=k;
   while (top>=0)
   {  i=s[top];top--;
      for (j=0;j<=n-1;j++)
      {  t=f[i*n+j];h=t+e[i];
	 if ((h<e[j])&&(t>0.0))
	 {  e[j]=h;
	    if (r[j]==0) {r[j]=1;top++;s[top]=j;}
	 }
      }
   }
   free(s);free(r);
   return;
}

#include <stdio.h>
main()
{  static double f[8][8]=
		 {{0.0,-1.0,30.0,20.0,-1.0,50.0,-1.0,40.0},
		  {-1.0,0.0,35.0,45.0,-1.0,-1.0,65.0,-1.0},
		  {30.0,35.0,0.0,-1.0,80.0,10.0,-1.0,25.0},
		  {20.0,45.0,-1.0,0.0,50.0,-1.0,40.0,30.0},
		  {-1.0,-1.0,80.0,50.0,0.0,20.0,70.0,-1.0},
		  {50.0,-1.0,10.0,-1.0,20.0,0.0,-1.0,50.0},
		  {-1.0,65.0,-1.0,40.0,70.0,-1.0,0.0,30.0},
		  {40.0,-1.0,25.0,30.0,-1.0,50.0,30.0,0.0}};
   double e[8];
   int i;
   printf("\n");
   qfshort(f,8,3,1.0e+4,e);
   for (i=0;i<=7;i++)
     printf("E(%d)=%e\n",i,e[i]);
   printf("\n");
}


