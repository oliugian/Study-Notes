/* m_n.c - - 计算 pow(m,n) 的精确值 */
#include <stdio.h>
int main(void)
{  int m,n,t,j,j1,a,b,i;
   static int p[7000];
   scanf("%d,%d",&m,&n);
   j=0;j1=1;p[1]=1;b=0;
   for (i=1;i<=n;i++)
   {   while (b!=0||j<=j1)
       {  j++;
	  a=p[j]*m+b;
	  b=a/10;
	  p[j]=a-10*b;
       }
       j1=j;j=0;
   }
   printf("%d^%d=",m,n);
   for (i=j1;i>=1;i--)
       printf("%d",p[i]);
   putchar('\n');
}
