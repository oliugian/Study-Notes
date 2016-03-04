/* gr_212.c - - KIDNEY */
#include <graphics.h>
#include <math.h>
#define PI 3.1415926

main()
{
    int x,y,r,r1;
    double a;
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"");
    printf("Input Radius(<150)\n");
    scanf("%d",&r);
    cleardevice();
    setbkcolor(BLUE);
    setcolor(10);
    for (a=0;a<2*PI;a+=PI/36)
    {
	x=r*cos(a)+320;
	y=r*sin(a)+240;
	r1=abs(x-320);
	circle(x,y,r1);
	delay(300);
    }
    getch();
    closegraph();
}
