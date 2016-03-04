#include "graphics.h"
extern void menu1();
extern void menu2();
extern void menu1(x1,y1,x2,y2,color1,color2,color3)
int x1,y1,x2,y2,color1,color2,color3;
{
 setcolor(color1);
 line(x1,y1,x1,y2);
 line(x1+1,y1,x1+1,y2-1);
 line(x1+2,y1,x1+2,y2-2);
 line(x1+3,y1,x1+3,y2-3);
 line(x1+3,y1,x2,y1);
 line(x1+3,y1+1,x2-1,y1+1);
 line(x1+3,y1+2,x2-2,y1+2);
 line(x1+3,y1+3,x2-3,y1+3);
 setcolor(color2);
 line(x2-3,y1+3,x2-3,y2);
 line(x2-2,y1+2,x2-2,y2);
 line(x2-1,y1+1,x2-1,y2);
 line(x2,y1,x2,y2);
 line(x1+3,y2-3,x2-3,y2-3);
 line(x1+2,y2-2,x2-3,y2-2);
 line(x1+1,y2-1,x2-3,y2-1);
 line(x1,y2,x2-3,y2);
 setcolor(color3);
 rectangle(x1+4,y1+4,x2-4,y2-4);
 setfillstyle(1,color3);
 floodfill(x1+5,y1+5,color3);
}
extern void menu2(x1,y1,x2,y2,color1,color2,color3)
int x1,y1,x2,y2,color1,color2,color3;
{
 setcolor(color1);
 line(x1,y2,x2,y2);
 line(x2,y1,x2,y2);
 setcolor(color2);
 line(x1,y1,x1,y2);
 line(x1,y1,x2,y1);
 setcolor(color1);
 line(x1+1,y2-1,x2-1,y2-1);
 line(x2-1,y1+1,x2-1,y2-1);
 setcolor(color2);
 line(x1+1,y1+1,x1+1,y2-1);
 line(x1+1,y1+1,x2-1,y1+1);
 setcolor(color3);
 rectangle(x1+2,y1+2,x2-2,y2-2);
 setfillstyle(1,color3);
 floodfill(x1+3,y1+3,color3);
}
