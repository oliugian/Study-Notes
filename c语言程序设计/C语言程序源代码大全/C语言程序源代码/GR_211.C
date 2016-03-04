/*  exp11.c - - circles */
/*  把一个半径为Rlarge的圆周n等分,以各等分点为圆心Rsmall为半径画圆 */
/*  rl>rs  rl==rs  rl<rs */

#include <graphics.h>
#include <math.h>
#define PI 3.1415926
main()
{
    int x,y,rlarge,rsmall;
    double a;
    int gdriver=DETECT,gmode;
    printf("Input Rlarge(<100)&&Rsmall\n");
    scanf("%d,%d",&rlarge,&rsmall);
    initgraph(&gdriver,&gmode,"c:\\tc");
    cleardevice();
    setbkcolor(BLUE);
    setcolor(10);
    for (a=0;a<=2*PI;a+=PI/18)
    {
	x=rlarge*cos(a)+320;
	y=rlarge*sin(a)+240;
	circle(x,y,rsmall);
	delay(300);
    }
    getch();
    closegraph();
}



