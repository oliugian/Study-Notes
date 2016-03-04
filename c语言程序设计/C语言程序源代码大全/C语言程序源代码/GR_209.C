/* gr_209.c - - DIAMOND */
#include <graphics.h>
#include <math.h>
#define PI 3.1415926

main()
{
    int x[50],y[50],n,i,j,r;
    double a;
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"");
    printf("Input n(15-30) and r(100-200)\n");
    scanf("%d,%d",&n,&r);
    cleardevice();
    setbkcolor(BLUE);
    setcolor(10);
    a=2*PI/n;
    for (i=0;i<n;i++)
    {
	x[i]=r*cos(i*a)+320;
	y[i]=r*sin(i*a)+240;
    }
    for (i=0;i<n-1;i++)
	for (j=i+1;j<n;j++)
	{
	    line(x[i],y[i],x[j],y[j]);
	    delay(30);
	}
    getch();
    closegraph();
}
