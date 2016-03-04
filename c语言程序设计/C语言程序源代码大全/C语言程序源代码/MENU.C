#include <dos.h>
#include <stdio.h>
#include <string.h>
#include <graphic.h>
#include <stdlib.h>

/* send the cursor to x,y,  */
void goto_xy(x,y)
int x,y;
{
    union REGS r;
    r.h.ah=2;    /*  cursor addressing function */
    r.h.dl=y;    /*  column coordinate */
    r.h.dh=x;    /*  row coordinate */
    r.h.bh=0;    /*  video page */
    int86(0x10,&r,&r);
}

/* save a portion of the screen */
void save_video(startx,endx,starty,endy,buf_ptr)
int startx,endx,starty,endy;
unsigned int *buf_ptr;     /* buffer where screen will be store */
{
    union REGS r;
    register int i,j;
    for (i=starty;i<endy;i++)
      for (j=startx;j<endx;j++)
      {   goto_xy(j,i);
	  r.h.ah=8;      /* read character function */
	  r.h.bh=0;      /* assume active display page is 0 */
	  *buf_ptr++=int86(0x10,&r,&r);
	  putchar(' ');  /* clear the screen */
      }
}

/* restore a portion of the screen */
void restore_video(startx,endx,starty,endy,buf_ptr)
int startx,endx,starty,endy;
unsigned char *buf_ptr;
{
    union REGS r;
    register int i,j;
    for (i=starty;i<endy;i++)
    {   goto_xy(j,i);
	r.h.ah=9;       /* write character function */
	r.h.bh=0;       /* assume active display page is 0 */
	r.h.cx=1;       /* number of times to write the character */
	r.h.al=*buf_ptr++;    /* character */
	r.h.bl=*buf_ptr++;    /* attribute */
	int86(0x10,&r,&r);
    }
}

/* display the menu in its proper location */
void display_menu(menu,x,y,count)
char *menu[];
int x,y,count;
{
    register int i;
    for (i=0;i<count;i++,x++)
    {   goto_xy(x,y);
	printf(menu[i]);
    }
}

void draw_border(startx,starty,endx,endy)
int startx,starty,endx,endy;
{
    register int i;
    for (i=startx+1;i<endx;i++)
    {   goto_xy(i,starty);
	putchar(179);
	goto_xy(i,endy);
	putchar(179);
    }
    for (i=starty+1;i<endy;i++)
    {   goto_xy(startx,i);
	putchar(196);
	goto_xy(endx,i);
	putchar(196);
    }
    goto_xy(startx,starty);putchar(218);
    goto_xy(startx,endy);putchar(191);
    goto_xy(endx,starty);putchar(192);
    goto_xy(endx,endy);putchar(217);
}



/* display a pop_up menu and return selection */
int popup(menu,keys,count,x,y,border)
char *menu[];     /* menu text */
char *keys;       /* hot keys  */
int count;        /* number of menu items */
int x,y;          /* x,y coordinates of left hand corner */
int border;       /* no border if 0 */


