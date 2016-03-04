#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
void main(void)
{
   short int gd=DETECT,gm;
   register int i,j,k;
   int mx,my;
   initgraph(&gd,&gm,"");
   while (! kbhit())
   {
      randomize();
      putpixel(random(640),random(479),random(15));
      for (i=0;i<=200;i++)
	putpixel(random(640),random(479),BLACK);
   }
   return;
}

