#include <stdio.h>
#include "lagrange.c"
#define N 5
/*external Lagrange();*/
int main(void)
{
    float x[N],y[N],x0,y0;
    int k;
    printf("input xk,yk:\n");
    for(k=0;k<=N;k++)
      scanf("%f,%f",&x[k],&y[k]);
    printf("input x:");
    scanf("%f",&x0);
    y0=Lagrange(x,y,N,x0);
    printf("x=%12.6f,y=%12.6f\n",x0,y0);
    return 0;
}



