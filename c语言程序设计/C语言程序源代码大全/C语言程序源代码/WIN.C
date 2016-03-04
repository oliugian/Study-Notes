#include <stdio.h>
#include <dos.h>
#include <stdlib.h>

#define BORDER 1
#define ESC 27
#define MAX_FRAME 10
#define REV_VID 0x70
#define NORM_VID 7
#define BKSP 8

void save_video(),restore_video(),pd_driver();
void goto_xy(),cls(),write_string(),write_char();
void display_header(),draw_border();
void window_gets(),size(),move(),window_cls();
void dectohex(),notepad(),calc();

char far *vid_mem;

struct window_frame {
  int startx,endx,starty,endy;
  int curx,cury;
  unsigned char *p;
  char *header;
  int border;
  int active;
} frame[MAX_FRAME];

main()
{
  union inkey {
    char ch[2];
    int i;
  } c;
  int i;
  char ch;

  cls();
  goto_xy(0,0);

  make_window(0," Editor [Esc to exit] ",0,0,24,78,BORDER);
  make_window(1," Decimal to Hex ",7,40,10,70,BORDER);
  make_window(2," Calculator ",8,20,12,60,BORDER);
  make_window(3," Notepad [F1 to exit] ",5,20,17,60,BORDER);
  window(0);
  do {
    c.i=window_getche(0);
    ch=c.i;
    if(ch=='\r') window_putchar(0,'\n');
    switch(c.ch[1])
    {
      case 59:
	window(1);
	for(i=0;i<10;i++)
	  if(window_xy(1,i,i)) window_putchar(1,'x');
	getch();
	deactivate(1);
	break;
      case 60:
	size(1);
	move(1);
	break;
      case 61:
	calc();
	break;
      case 62:
	dectohex();
	break;
      case 63:
	notepad();
	break;
      case 72:
	window_upline(0);
	break;
      case 80:
	window_downline(0);
	break;
     }
   } while (ch!=ESC);
   deactivate(0);
   cls();
}

/**********************
void window(num)
int num;
{
   int vmode,choice;
   int x,y;

   vmode=video_mode();

   if((vmode!=2)&&(vmode!=3)&&(vmode!=7))
      printf("video must be in 80 column text mode ");
   exit(1);

   if(vmode==7)vid_mem=(char far *)0xB0000000;
   else vid_mem=(char far *)0xB8000000;

   if(!frame[num].active)
   {  save_video(num);
      frame[num].active=1;
   }

   if(frame[num].border) draw_border(num);
   display_header(num);

   x=frame[num].startx+frame[num].curx+1;
   y=frame[num].starty+frame[num].cury+1;
   goto_xy(x,y);
}
*********************/

make_window(num,header,startx,starty,endx,endy,border)
int num;
char *header;
int startx,starty,endx,endy;
int border;
{
   unsigned char *p;

   if(num>MAX_FRAME)
   {  printf("Too many windows\n");
      return 0;
   }
   p=(unsigned char *)malloc((2*endx-startx+1)*(endy-starty+1));
   if(!p)exit(1);

   frame[num].startx=startx;frame[num].endx=endx;
   frame[num].starty=starty;frame[num].endy=endy;
   frame[num].p=p;
   frame[num].header=header;
   frame[num].border=border;
   frame[num].active=0;
   frame[num].curx=0;frame[num].cury=0;
   return 1;
}

deactivate(num)
int num;
{
   frame[num].curx=0;
}

void size(num)
int num;
{
   char ch;
   int x,y,startx,starty;

   if(!frame[num].active) window(num);
   startx=x=frame[num].startx;
   starty=y=frame[num].starty;
   window_xy(num,0,0);

   do {
     ch=get_special();
     switch(ch)
     {
	case 75:
	  starty--;
	  break;
	case 77:
	  starty++;
	  break;
	case 72:
	  startx--;
	  break;
	case 80:
	  startx++;
	  break;
	case 71:
	  startx--;starty--;
	  break;
	case 73:
	  startx--;starty++;
	  break;
	case 79:
	  startx++;starty--;
	  break;
	case 81:
	  startx++;starty++;
	  break;
	case 60:
	  startx=x;
	  starty=y;
	  ch=59;
      }
      if(startx<0) startx++;
      if(startx>frame[num].endx)startx--;
      if(starty<0) starty++;
      if(starty>frame[num].endy)starty--;
      deactivate(num);
      frame[num].startx=startx;
      frame[num].starty=starty;
   } while(ch!=59);
   deactivate(num);
}

void move(num)
int num;
{
   char ch;
   int x,y,ex,ey,startx,starty,endx,endy;

   if(!frame[num].active) window(num);
   startx=x=frame[num].startx;
   starty=y=frame[num].starty;
   endx=ex=frame[num].endx;
   endy=ey=frame[num].endy;
   window_xy(num,0,0);

   do {
     ch=get_special();
     switch(ch)
     {
	case 75:
	  starty--;
	  endy--;
	  break;
	case 77:
	  starty++;
	  endy++;
	  break;
	case 72:
	  startx--;
	  endx--;
	  break;
	case 80:
	  startx++;
	  endx++;
	  break;
	case 71:
	  startx--;starty--;
	  endx--;endy--;
	  break;
	case 73:
	  startx--;starty++;
	  endx--;endy++;
	  break;
	case 79:
	  startx++;starty--;
	  endx++;endy--;
	  break;
	case 81:
	  startx++;starty++;
	  endx++;endy++;
	  break;
	case 60:
	  startx=x;endx=ex;
	  starty=y;endy=ey;
	  ch=59;
      }
      if(startx<0) { startx++;endx++;}
      if(startx>frame[num].endx) { startx--;endx--;}
      if(starty<0) { starty++;endy++;}
      if(starty>frame[num].endy) { starty--;endy--;}
      deactivate(num);
      frame[num].startx=startx;
      frame[num].starty=starty;
      frame[num].endx=endx;
      frame[num].endy=endy;
      window(num);
   } while(ch!=59);
   deactivate(num);
}

void display_header(num)
int num;
{
   register int y,len;

   y=frame[num].starty;

   len=strlen(frame[num].header);
   len=(frame[num].endy-y-len)/2;
   if(len<0)return;
   y=y+len;
   write_string(frame[num].startx,y,frame[num].header,NORM_VID);
}

void draw_border(num)
int num;
{
   register int i;
   char far *v,far *t;

   t=v=vid_mem;
   for(i=frame[num].startx+1;i<frame[num].endx;i++)
   {  v+=(i*160)+frame[num].starty*2;
      *v++=179;
      *v=NORM_VID;
      v=t;
      v+=(i*160)+frame[num].endy*2;
      *v++=179;
      *v=NORM_VID;
      v=t;
   }
   for(i=frame[num].starty+1;i<frame[num].endy;i++)
   {  v+=frame[num].startx*160+i*2;
      *v++=196;
      *v=NORM_VID;
      v=t;
      v+=frame[num].endx*160+i*2;
      *v++=196;
      *v=NORM_VID;
      v=t;
   }
   write_char(frame[num].startx,frame[num].starty,218,NORM_VID);
   write_char(frame[num].startx,frame[num].endy,191,NORM_VID);
   write_char(frame[num].endx,frame[num].starty,192,NORM_VID);
   write_char(frame[num].endx,frame[num].endy,217,NORM_VID);
}

window_puts(num,str)
int num;
char *str;
{
   if(!frame[num].active) return 0;

   for( ;*str;str++) window_putchar(num,*str);
   return 1;
}

window_putchar(num,ch)
int num;
char ch;
{
   register int x,y;
   char far *v;

   if(!frame[num].active)return 0;

   x=frame[num].curx+frame[num].startx+1;
   y=frame[num].cury+frame[num].starty+1;

   v=vid_mem;
   v+=(x*160)+y*2;
   if(y>=frame[num].endy) return 1;
   if(x>=frame[num].endx) return 1;
   if(ch=='\n')
   {  x++;
      y=frame[num].starty+1;
      v=vid_mem;
      v+=(x*160)+y*2;
      frame[num].curx++;
      frame[num].cury=0;
   }
   else
   {  frame[num].cury++;
      *v++=ch;
      *v++=NORM_VID;
   }
   window_xy(num,frame[num].curx,frame[num].cury);
   return 1;
}

window_xy(num,x,y)
int num,x,y;
{
   if(x<0||x+frame[num].startx>=frame[num].endx-1) return 0;
   if(y<0||y+frame[num].starty>=frame[num].endy-1) return 0;
   frame[num].curx=x;
   frame[num].cury=y;
   goto_xy(frame[num].startx+x+1,frame[num].starty+y+1);
   return 1;
}

void window_gets(num,s)
int num;
char *s;
{
   char ch,*temp;

   temp=s;
   for(;;)
   {  ch=window_getche(num);
      switch(ch)
      {  case '\r':
	   *s='\0';
	   return;
	 case BKSP:
	   if(s>temp)
	   {  s--;
	      frame[num].cury--;
	      if(frame[num].cury<0) frame[num].cury=0;
	      window_xy(num,frame[num].curx,frame[num].cury);
	      write_char(frame[num].startx+frame[num].curx+1,
		    frame[num].starty+frame[num].cury+1,' ',NORM_VID);
	   }
	   break;
	 default:*s=ch;
	   s++;
       }
    }
}

window_getche(num)
int num;
{
   union inkey{
     char ch[2];
     int i;
   } c;
   if(!frame[num].active) return 0;
   window_xy(num,frame[num].curx,frame[num].cury);
   c.i=bioskey(0);
   if(c.ch[0])
   {  switch(c.ch[0])
      {  case '\r':
	   break;
	 case BKSP:
	   break;
	 default:
	   if(frame[num].cury+frame[num].starty<frame[num].endy-1)
	   {  write_char(frame[num].startx+frame[num].curx+1,
		  frame[num].starty+frame[num].cury+1,c.ch[0],NORM_VID);
	      frame[num].cury++;
	   }
       }
       if(frame[num].curx<0) frame[num].curx=0;
       if(frame[num].curx+frame[num].startx>frame[num].endx-2) frame[num].curx--;
    }
    window_xy(num,frame[num].curx,frame[num].cury);
    return c.i;
}

void window_cls(num)
int num;
{
   register int i,j;
   char far *v,far *t;

   v=vid_mem;
   t=v;
   for(i=frame[num].starty+1;i<frame[num].endy;i++)
     for(j=frame[num].startx+1;j<frame[num].endx;j++)
     {  v=t;
	v+=(j*160)+i*2;
	*v++=' ';
	*v=NORM_VID;
     }
   frame[num].curx=0;
   frame[num].cury=0;
}

void window_cleol(num)
int num;
{
   register int i,x,y;

   x=frame[num].curx;
   y=frame[num].cury;
   window_xy(num,frame[num].curx,frame[num].cury);

   for(i=frame[num].cury;i<frame[num].endy-1;i++) window_putchar(num,' ');
   window_xy(num,x,y);
}

window_upline(num)
int num;
{
   if(frame[num].curx>0)
   {  frame[num].curx--;
      window_xy(num,frame[num].curx,frame[num].cury);
      return 1;
   }
   return 0;
}

window_downline(num)
int num;
{
   if(frame[num].curx<frame[num].endx-frame[num].startx-1)
   {  frame[num].curx++;
      window_xy(num,frame[num].curx,frame[num].cury);
      return 1;
   }
   return 0;
}

window_bksp(num)
int num;
{
   if(frame[num].cury>0)
   {  frame[num].cury--;
      window_xy(num,frame[num].curx,frame[num].cury);
      window_putchar(num,' ');
      frame[num].cury--;
      window_xy(num,frame[num].curx,frame[num].cury);
   }
}

void write_string(x,y,p,attrib)
int x,y;
char *p;
int attrib;
{
   register int i;
   char far *v;

   v=vid_mem;
   v+=(x*160)+y*2;
   for(i=y;*p;i++)
   {  *v++=*p++;
      *v++=attrib;
   }
}

void write_char(x,y,ch,attrib)
int x,y;
char ch;
int attrib;
{
   register int i;
   char far *v;

   v=vid_mem;
   v+=(x*160)+y*2;
   *v++=ch;
   *v=attrib;
}

void save_video(num)
int num;
{
   register int i,j;
   char *buf_ptr;
   char far *v,far *t;

   buf_ptr=frame[num].p;
   v=vid_mem;
   for(i=frame[num].starty;i<frame[num].endy+1;i++)
     for(j=frame[num].startx;j<frame[num].endx+1;j++)
     {  t=(v+(j*160)+i*2);
	*buf_ptr++=*t++;
	*buf_ptr++=*t;
	*(t-1)=' ';
     }
}

/**************
void restore_video(num);
int num;
{
   register int i,j;
   unsigned char *buf_ptr;
   char far *v,far *t;

   buf_ptr=frame[num].p;
   v=vid_mem;
   t=v;
   for(i=frame[num].starty;i<frame[num].endy+1;i++)
     for(j=frame[num].startx;j<frame[num].endx+1;j++)
     {  v=t;
	v+=(j*160)+i*2;
	*v++=*buf_ptr++;
	*v=*buf_ptr++;
     }
   frame[num].active=0;
}
********************/

void cls()
{
   union REGS r;
   r.h.ah=6;
   r.h.al=0;
   r.h.dh=0;
   r.h.dl=0;
   r.h.dh=24;
   r.h.dl=79;
   r.h.bh=7;
   int86(0x10,&r,&r);
}

void goto_xy(x,y)
int x,y;
{
   union REGS r;
   r.h.ah=2;
   r.h.dl=y;
   r.h.dh=x;
   r.h.bh=0;
   int86(0x10,&r,&r);
}

get_special()
{
   union inkey{
     char ch[2];
     int i;
   } c;
   while(!bioskey(1));
   c.i=bioskey(0);
   return c.ch[1];
}

video_mode()
{
   union REGS r;
   r.h.ah=15;
   return int86(0x10,&r,&r) & 255;
}

is_in(s,c)
char *s,c;
{
   register int i;
   for(i=0;*s;i++) if(*s++==c) return i+1;
   return 0;
}

bioskey(c)
int c;
{
   switch(c)
   {  case 0: return get_key();
      case 1: return kbhit();
   }
}

get_key()
{
   union REGS r;

   r.h.ah=0;
   return int86(0x16,&r,&r);
}










