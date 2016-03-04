#include "graphics.h"
#include "stdio.h"
#include "string.h"
void outhz48(char ch[],int x,int y,int color,int distance)
{
 int i,j,k;
  long r,n;
  char ch3[288],qm,wm;
  FILE *file1;
/*  if ((file1=fopen("hzk48s","rb"))==NULL)
     { printf("Not found hzk48s");
       exit(EXIT_FAILURE);
     }*/
     file1=fopen("hzk48s","rb");
  setcolor(color);
  for (k=0;k<strlen(ch);k++)
    {   j=0;
	qm=ch[k++]-176;
	wm=ch[k]-161;
	n=qm*94+wm;
	fseek(file1,n*288,0);
	fread(ch3,288,1,file1);
	for (i=0;i<48;i++)
	    { setlinestyle(4,ch3[j++],1);
	      line(x+7,y+i,x,y+i);

	      setlinestyle(4,ch3[j++],1);
	      line(x+15,y+i,x+8,y+i);

	      setlinestyle(4,ch3[j++],1);
	      line(x+23,y+i,x+16,y+i);

	      setlinestyle(4,ch3[j++],1);
	      line(x+31,y+i,x+24,y+i);

	      setlinestyle(4,ch3[j++],1);
	      line(x+39,y+i,x+32,y+i);

	      setlinestyle(4,ch3[j++],1);
	      line(x+47,y+i,x+40,y+i);
	    }
	x+=distance;
   }
 fclose(file1);
 setlinestyle(0,0,0);
}
/*
void outhz16(char ch[],int x,int y,int color,int distance)
{
 int i,j,k;
  long r,n;
  char ch3[32],qm,wm;
  FILE *file1;
     file1=fopen("hzk16","rb");
  setcolor(color);
  for (k=0;k<strlen(ch);k++)
    {   j=0;
	qm=ch[k++]-161;
	wm=ch[k]-161;
	n=qm*94+wm;
	fseek(file1,n*32,0);
	fread(ch3,32,1,file1);
	for (i=0;i<16;i++)
	    { setlinestyle(4,ch3[j++],1);
	      line(x+7,y+i,x,y+i);

	      setlinestyle(4,ch3[j++],1);
	      line(x+15,y+i,x+8,y+i);
	    }
	x+=distance;
   }
 fclose(file1);
 setlinestyle(0,0,0);
}
void demo_setcolor(int co,int r,int g,int b)
{
 outportb(0x3c8,co);
 outportb(0x3c9,r);
 outportb(0x3c9,g);
 outportb(0x3c9,b);
}*/