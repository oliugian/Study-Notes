#include "dos.h"
#include "graphics.h"
#include "colorjy.h"
#include "hzkjy.h"
extern upbar();     /* upbar(x1,y1,x2,y2) */
extern dnbar();     /* dnbar(x1,y1,x2,y1) */
extern upbarfill(); /* upbarfill(x1,y1,x2,y2,color) */
extern dnbarfill(); /* dnbarfill(x1,y1,x2,y2,color) */
extern upbfjy();    /* */
extern dnbfjy();    /* */
extern defwin95();  /* defwin95(x1,y1,x2,y2,title)  */
extern defwinout(); /* defwinout(x1,y1,x2,y2,title) */
extern defwin32();  /* defwin32(x1,y1,x2,y2,title)  */
extern goodwaitwin();
extern waitwin();   /* waitwin(x,y,ch,BACKcolor,CHARcolor) */
extern waitwinchinese();

extern upbar(x1,y1,x2,y2)
int x1,y1,x2,y2;
{
 setcolor(8);
 line(x1,y2,x2,y2);
 line(x2,y1,x2,y2);
 setcolor(7);
 line(x1,y1,x1,y2);
 line(x1,y1,x2,y1);
 setcolor(7);
 line(x1+1,y2-1,x2-1,y2-1);
 line(x2-1,y1+1,x2-1,y2-1);
 setcolor(15);
 line(x1+1,y1+1,x1+1,y2-1);
 line(x1+1,y1+1,x2-1,y1+1);
 setcolor(7);
 rectangle(x1+2,y1+2,x2-2,y2-2);
 setfillstyle(1,7);
 floodfill(x1+3,y1+3,7);
}
extern dnbar(x1,y1,x2,y2)
int x1,y1,x2,y2;
{
 setcolor(15);
 line(x1,y2,x2,y2);
 line(x2,y1,x2,y2);
 setcolor(7);
 line(x1,y1,x1,y2);
 line(x1,y1,x2,y1);
 setcolor(7);
 line(x1+1,y2-1,x2-1,y2-1);
 line(x2-1,y1+1,x2-1,y2-1);
 setcolor(8);
 line(x1+1,y1+1,x1+1,y2-1);
 line(x1+1,y1+1,x2-1,y1+1);
 setcolor(7);
 rectangle(x1+2,y1+2,x2-2,y2-2);
 setfillstyle(1,7);
 floodfill(x1+3,y1+3,7);
}
extern upbarfill(x1,y1,x2,y2,color)
int x1,y1,x2,y2,color;
{
 setcolor(8);
 line(x1,y2,x2,y2);
 line(x2,y1,x2,y2);
 setcolor(7);
 line(x1,y1,x1,y2);
 line(x1,y1,x2,y1);
 setcolor(7);
 line(x1+1,y2-1,x2-1,y2-1);
 line(x2-1,y1+1,x2-1,y2-1);
 setcolor(15);
 line(x1+1,y1+1,x1+1,y2-1);
 line(x1+1,y1+1,x2-1,y1+1);
 setcolor(color);
 rectangle(x1+2,y1+2,x2-2,y2-2);
 setfillstyle(1,color);
 floodfill(x1+3,y1+3,color);
}
extern dnbarfill(x1,y1,x2,y2,color)
int x1,y1,x2,y2,color;
{
 setcolor(15);
 line(x1,y2,x2,y2);
 line(x2,y1,x2,y2);
 setcolor(7);
 line(x1,y1,x1,y2);
 line(x1,y1,x2,y1);
 setcolor(7);
 line(x1+1,y2-1,x2-1,y2-1);
 line(x2-1,y1+1,x2-1,y2-1);
 setcolor(8);
 line(x1+1,y1+1,x1+1,y2-1);
 line(x1+1,y1+1,x2-1,y1+1);
 setcolor(color);
 rectangle(x1+2,y1+2,x2-2,y2-2);
 setfillstyle(1,color);
 floodfill(x1+3,y1+3,color);
}
extern upbfjy(x1,y1,x2,y2,color)
int x1,y1,x2,y2,color;
{
 demo_setcolor(60,29,29,29);
 setfillstyle(1,12);
 setcolor(60);
 line(x1,y2,x2,y2);
 line(x2,y1,x2,y2);
 setcolor(15);
 line(x1,y1,x1,y2);
 line(x1,y1,x2,y1);
 setcolor(60);
 line(x1+1,y2-1,x2-1,y2-1);
 line(x2-1,y1+1,x2-1,y2-1);
 setcolor(7);
 line(x1+1,y1+1,x1+1,y2-1);
 line(x1+1,y1+1,x2-1,y1+1);
 setcolor(color);
 rectangle(x1+2,y1+2,x2-2,y2-2);
 setfillstyle(1,color);
 floodfill(x1+3,y1+3,color);
}
extern dnbfjy(x1,y1,x2,y2,color)
int x1,y1,x2,y2,color;
{
 demo_setcolor(60,29,29,29);
 setfillstyle(1,12);
 setcolor(15);
 line(x1,y2,x2,y2);
 line(x2,y1,x2,y2);
 setcolor(60);
 line(x1,y1,x1,y2);
 line(x1,y1,x2,y1);
/* setcolor(15);
 line(x1+1,y2-1,x2-1,y2-1);
 line(x2-1,y1+1,x2-1,y2-1);*/
 setcolor(60);
 line(x1+1,y1+1,x1+1,y2-1);
 line(x1+1,y1+1,x2-1,y1+1);
 setcolor(color);
 rectangle(x1+2,y1+2,x2-2,y2-2);
 setfillstyle(1,color);
 floodfill(x1+3,y1+3,color);
}
extern defwin95(x1,y1,x2,y2,title)
int x1,y1,x2,y2;
char title[200];
{
 upbarfill(x1,y1,x2,y2,7);
 setfillstyle(1,1);
 bar(x1+4,y1+4,x2-4,y1+24);
 setcolor(WHITE);
 outhz16(title,x1+10,y1+7,15,18);
 dnbfjy(x1+3,y1+28,x2-3,y2-28,15);
 dnbfjy(x1+3,y2-24,x2-3,y2-4,7);
}
extern defwinout(x1,y1,x2,y2,title)
int x1,y1,x2,y2;
char title[200];
{
 upbfjy(x1,y1,x2,y2,7);
 setfillstyle(1,1);
 bar(x1+4,y1+4,x2-4,y1+24);
 setcolor(WHITE);
 outhz16(title,x1+10,y1+7,15,18);
 dnbfjy(x1+3,y1+28,x2-3,y2-28,15);
 dnbfjy(x1+3,y2-24,x2-3,y2-4,7);
}

extern defwin32(x1,y1,x2,y2,title)
int x1,y1,x2,y2;
char title[200];
{
 int xx;
 demo_setcolor(60,29,29,29);
 setfillstyle(1,12);
 xx=strlen(title);
 setfillstyle(1,7);
 bar(x1,y1,x1+3,y2);
 bar(x1,y1,x2,y1+3);
 bar(x2,y1,x2-3,y2);
 bar(x1,y2-3,x2,y2);
 setfillstyle(1,15);
 bar(x1+4,y1+44,x2-4,y2-4);
 bar(x1+4,y1+24,x2-4,y1+42);
 setfillstyle(1,7);
 bar(x1+4,y1+24,x1+22,y1+42);
 bar(x1+4,y1+4,x1+22,y1+22);
 setfillstyle(1,1);
 bar(x1+24,y1+4,x2-44,y1+22);
 upbfjy(x2-42,y1+4,x2-24,y1+22,7);
 upbfjy(x2-22,y1+4,x2-4,y1+22,7);
 upbfjy(x2-22,y1+24,x2-4,y1+42,7);
 setfillstyle(1,15);
 bar(x1+8,y1+12,x1+17,y1+14);
 bar(x1+10,y1+31,x1+15,y1+33);
 setcolor(8);
 line(x1+9,y1+15,x1+18,y1+15);
 line(x1+18,y1+15,x1+18,y1+13);
 line(x1+11,y1+34,x1+16,y1+34);
 line(x1+16,y1+34,x1+16,y1+32);
 setcolor(15);
 outhz16(title,(x1+x2-20)/2-xx*8/2,y1+6,15,18);
 demo_setcolor(61,3,3,3);
 setfillstyle(1,13);
 setcolor(61);
 line(x2-23,y1,x2-23,y1+43);
 rectangle(x1,y1,x2,y2);
 rectangle(x1+3,y1+3,x2-3,y2-3);
 rectangle(x1+8,y1+12,x1+17,y1+14);
 rectangle(x1+10,y1+31,x1+15,y1+33);
 line(x1+23,y1,x1+23,y1+43);
 line(x2-23,y1,x2-23,y1+43);
 line(x1,y1+23,x2,y1+23);
 line(x1,y2-23,x1+3,y2-23);
 line(x2,y2-23,x2-3,y2-23);
 line(x1+23,y2,x1+23,y2-3);
 line(x2-23,y2,x2-23,y2-3);
 line(x1+3,y1+43,x2-3,y1+43);
 line(x2-43,y1+3,x2-43,y1+23);
 setcolor(8);
 line(x2-13,y1+10,x2-16,y1+14);
 line(x2-16,y1+14,x2-10,y1+14);
 line(x2-10,y1+14,x2-13,y1+10);
 line(x2-37,y1+10,x2-31,y1+10);
 line(x2-31,y1+10,x2-34,y1+14);
 line(x2-34,y1+14,x2-37,y1+10);
 setcolor(8);
 line(x2-13,y1+28,x2-16,y1+32);
 line(x2-16,y1+32,x2-10,y1+32);
 line(x2-10,y1+32,x2-13,y1+28);
 line(x2-16,y1+34,x2-10,y1+34);
 line(x2-10,y1+34,x2-13,y1+38);
 line(x2-13,y1+38,x2-16,y1+34);

 floodfill(x2-14,y1+13,8);
 floodfill(x2-34,y1+13,8);
 floodfill(x2-14,y1+31,8);
 floodfill(x2-14,y1+35,8);
 setcolor(61);
/* outtextxy(x1+26,y1+30,"[F] [E] [O] [H]"); */

}
extern waitwin(int x,int y,char ch[],int bkcolor,int color)
{int xx;
 xx=strlen(ch);
 upbarfill(x,y,x+xx*8+15,y+25,bkcolor);
 setcolor(color);
 outtextxy(x+10,y+10,ch);
}
extern waitwinchinese(int x,int y,char ch[],int bkcolor,int color)
{int xx;
  xx=strlen(ch);
  upbarfill(x,y,x+xx*9+15,y+25,bkcolor);
  setcolor(color);
  outhz16(ch,x+10,y+6,color,18);
}
extern goodwaitwin(int x,int y,char ch[],int bkcolor,int color)
{int xx;
  xx=strlen(ch);
  upbarfill(x,y,x+xx*9+15,y+50,bkcolor);
  setcolor(color);
  outhz16(ch,x+10,y+20,color,18);
}
