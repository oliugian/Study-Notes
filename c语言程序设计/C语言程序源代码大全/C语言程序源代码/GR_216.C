/* gr_216.c - - TEXT */
#include <graphics.h>
#include <math.h>

main()
{
    int i,t,x=300,y=50;
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"");
    setbkcolor(BLUE);
    setcolor(10);
    for (i=1;i<=10;i++)
    {
	x-=15;y+=15;
	settextstyle(1,0,i);
	cleardevice();
	outtextxy(x,y,"Hello!");
	delay(300);
    }
    getch();
    closegraph();
}
