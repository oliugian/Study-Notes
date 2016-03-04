#include<graphics.h>
#include<dos.h>
extern void demo_setcolor(int co,int r,int g,int b)  /*修改调色板的颜色*/
{
  outportb(0x3c8,co);
  outportb(0x3c9,r);
  outportb(0x3c9,g);
  outportb(0x3c9,b);
}

