#include "graphics.h"
#include "string.h"
#include "stdio.h"
extern void outhz16(char ch[],int x,int y,int color,int distance)
{

 int i,j,k;
 long r,n;
 char ch3[32],qm,wm;
 FILE *file1;
 file1=fopen("hzk16","rb");
 setcolor(color);
 for(k=0;k<strlen(ch);k++)
    {j=0;
     qm=ch[k++]-161;
     wm=ch[k]-161;
/*     qm=ch[k++]-160;
     wm=ch[k]-160;*/
     n=qm*94+wm;
/*   n=(qm-15)*94+wm;*/
     fseek(file1,n*32,0);
     fread(ch3,32,1,file1);
     for(i=0;i<16;i++)
	 {setlinestyle(4,ch3[j++],1);
	  line(x+7,y+i,x,y+i);
	  setlinestyle(4,ch3[j++],1);
	  line(x+15,y+i,x+8,y+i);
	 }
     x+=distance;
    }
 fclose(file1);
 setlinestyle(0,0,0);
}