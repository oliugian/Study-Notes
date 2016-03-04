/*  pattern1.c - - PATTERN */
#include <graphics.h>
#include <math.h>
#define PI 3.1415926

void polygonc();
void block();

main()
{
    int a,r,rr,n,theta,x=320,y=240;
    int gdriver=DETECT,gmode;
/*    printf("input a,n,theta:");
    scanf("%d,%d,%d",&a,&n,&theta);  */
    a=100;n=20;theta=5;
    initgraph(&gdriver,&gmode,"c:\\tc");
    cleardevice();
    setbkcolor(BLUE);
    setcolor(14);
    r=2*a*sin(PI/4.75);
    block(x,y,a,n,-theta);
    for (rr=30;rr<360;rr+=60)
    {   x=r*cos(rr*PI/180)+320;
	y=r*sin(rr*PI/180)+240;
	block(x,y,a,n,theta);
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
    float t,f,af=0;
    t=fabs(theta*PI/180);
    f=1.0/(cos(t)+sin(t));
    r=a/sqrt(2);
    x0=x;
    y0=y;
    for (i=1;i<=n;i++)
    {   polygonc(x0,y0,r,6,af);
	r*=f;
	af-=theta;
    }
}





