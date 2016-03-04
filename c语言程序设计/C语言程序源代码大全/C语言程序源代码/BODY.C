#include <stdio.h>
#include <graphics.h>

main()
{  int by,bm,bd,cy,cm,cd,w,bj,bs,k,n,t,tzl,tqx,ttl;
   static int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

   int gdriver=DETECT,gmode;

   printf("Please input your birthday:\n");
   printf("                  year:");
   scanf("%d",&by);
   printf("                 month:");
   scanf("%d",&bm);
   printf("                   day:");
   scanf("%d",&bd);

   printf("Please input your countday:\n");
   printf("                  year:");
   scanf("%d",&cy);
   printf("                 month:");
   scanf("%d",&cm);
   printf("                   day:");
   scanf("%d",&cd);

   if(cy%4!=0)t=0;
   else if(cy%100==0)t=1;
   else if(cy%400==0)t=1;
   else t=0;
   if(t==0)month[2]=29;

   bs=0;
   for(k=1;k<=bm;k++) bs=bs+month[k];
   bs=bs+bd;
   bj=0;
   for(k=1;k<=cm;k++) bj=bj+month[k];
   bj=bj+bd;
   n=cy-by;
   w=365*n+n/4+bj-bs;
   tzl=w%33;
   tqx=w%28;
   ttl=w%23;
   printf("w=%d\n",w);
   printf("zl=%f\n",w/33.0);
   printf("qx=%f\n",w/28.0);
   printf("tl=%f\n",w/23.0);
   getch();

   initgraph(&gdriver,&gmode,"d:\\tc");
   cleardevice();
   moveto(50,60);
   lineto(580,60);
   lineto(580,400);
   lineto(50,400);
   lineto(50,60);

   line(70,90,70,370);
   line(65,230,510,230);




   getch();
   closegraph();
}





