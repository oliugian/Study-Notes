#include <stdio.h>
int main(void)
{  int i,j,k=0,k1,k2,m1,m2,n1,n2;
   float u,x,y;
   for (i=0;i<12;i++)
     for (j=i;j<12;j++)
     {  u=60/143.0;
	x=u*(12*j+i);y=u*(12*i+j);
	k1=x;k2=y;
	n1=(x-k1)*60;n2=(y-k2)*60;
	if (k1==60) {i++;k1=0;}
	if (k2==60) {j++;k2=0;}
	if (i==0) m1=12;else m1=i;
	if (j==0) m2=12;else m2=j;
	printf("%2d:%2d:%2d <====> %2d:%2d:%2d\n",m1,k1,n1,m2,k2,n2);
	k++;
     }
     printf("k=%d\n",k);
}
