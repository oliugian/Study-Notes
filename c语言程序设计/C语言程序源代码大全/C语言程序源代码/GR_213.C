/* gr_213.c - - HEART */
#include <graphics.h>
#include <math.h>
#define PI 3.1415926

main()
{
    int x,y,y1,r,r1;
    double a;
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"");
    printf("Input Radius(<80)\n");
    scanf("%d",&r);
    cleardevice();
    setbkcolor(BLUE);
    setcolor(10);
    y1=240-r;
    for (a=0;a<2*PI;a+=PI/18)
    {
	x=r*cos(a)+320;
	y=r*sin(a)+240;
	r1=sqrt((x-320)*(x-320)+(y-y1)*(y-y1));
	circle(x,y,r1);
	delay(300);
    }
    getch();
    closegraph();
}
