/*  pattern.c - - PATTERN */
#include <graphics.h>
#include <math.h>
#define PI 3.1415926

void polygonc();
void block();

main()
{
    int i,j,a,length,n,theta,x=100,y=350;
    int gdriver=DETECT,gmode;
/*    printf("input length,n,theta:");
    scanf("%d,%d,%d",&length,&n,&theta); */
    length=420;n=20;theta=5;
    initgraph(&gdriver,&gmode,"c:\\tc");
    cleardevice();
    setbkcolor(BLUE);
    setcolor(14);
    a=length/4;
    for (i=1;i<=4;i++)
    {   for (j=1;j<=4;j++)
	{   block(x,y,a,n,theta);
	    theta=-theta;
	    x+=a;
	}
	x=100;y-=a;theta=-theta;
    }
    getch();
    closegraph();
}

void polygonc(x0,y0,r,n,af)
int x0,y0,r,n;
float af;
{
    int x,y,xs,ys,i;
    float dtheta,theta;
    if (n<3) return;
    dtheta=2*PI/n;
    theta=af*PI/180;
    xs=x0+r*cos(theta);
    ys=y0+r*sin(theta);
    moveto(xs,ys);
    for (i=1;i<n;i++)
    {   theta+=dtheta;
	x=x0+r*cos(theta);
	y=y0+r*sin(theta);
	lineto(x,y);
    }
    lineto(xs,ys);
}

void block(x,y,a,n,theta)
int x,y,a,n,theta;
{
    int x0,y0,i,r;
    float t,f,af=45.0;
    t=fabs(theta*PI/180);
    f=1.0/(cos(t)+sin(t));
    r=a/sqrt(2);
    x0=x+0.5*a;
    y0=y+0.5*a;
    for (i=1;i<=n;i++)
    {   polygonc(x0,y0,r,4,af);
	r*=f;
	af-=theta;
    }
}





