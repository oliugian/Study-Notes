/* gr_210.c - - LINESIN */
#include <graphics.h>
#include <math.h>
#define PI 3.1415926

main()
{
    int x1,y1,x2;
    double a;
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"");
    cleardevice();
    setbkcolor(BLUE);
    setcolor(10);
    for (a=0;a<=PI;a+=PI/380)
    {
	x1=280*cos(1.6*a)+320;
	y1=479-((90*sin(8*a))*cos(a/2.5)+240);
	x2=280*cos(1.8*a)+320;
	line(x1,y1,x2,y1);
	delay(50);
    }
    getch();
    closegraph();
}
