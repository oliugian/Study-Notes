#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

float a[6][600],b[6][600],aa[6][600];
int N,M;
float c1[]={1.5,1.12,1.03,1.01,1.00,1,1,1};
float h[]={0.125,0.375,0.375,0.125};
float g[]={-2.0,2.0};
float k1[]={0.0078125,0.054685,0.171875,-0.171875,-0.054685,-0.0078125};

void dwt();
void recon_dwt();
void curve(int i,float *p,int j);
void curvel(int i,float *p,int j);

main()
{    int i,j,n;
     char file1[30],file[30];
     int driver,mode;
     float *p;
     FILE *fp;
     do
     {    clrscr();
	  gotoxy(10,5);
	  cprintf("please input the name of the data file:");
	  scanf("%s",file);
     }
     while((fp=fopen(file,"rb"))==NULL);
     gotoxy(10,7);

     cprintf("please input the length of data:");
     scanf("%d",&N);
     gotoxy(10,9);
     cprintf("please input the number of scales:");
     scanf("%d",&M);
     clrscr();
     j=1;
     for(i=0;i<N;i++)
     {   fscanf(fp,"%d",&n);
	 a[0][i]=n;
	 if(j==6)
	 { fscanf(fp,"\n");
	   j=0;
	 }
	 j++;
      }
      fclose(fp);
      dwt();
      for(i=0;i<=N+10;i++)
	 aa[M][i]=a[M][i];
      recon_dwt();

      driver=DETECT;
      initgraph(&driver,&mode,"");
      setbkcolor(BLUE);
      settextstyle(0,0,1);
      cleardevice();

      moveto(1,100);
      outtext("scale1");
      curve(N,b[1],100);
      moveto(1,200);
      outtext("scale2");
      curve(N ,b[2],200);
      moveto(1,300);
      outtext("scale3");
      curve(N,b[3],300);
      moveto(1,400);
      outtext("scale4");
      curve(N,b[4],400);
      getch();
      cleardevice();

      moveto(1,220);
      outtext("original signal");
      curve(N,a[0],200);
      moveto(1,390);
      outtext("the costructed signal");
      curve(N,aa[0],370);
      getch();
      cleardevice();
      closegraph();
 }

 void dwt()
 {  float p,q;
    int i,j,k;
    float c2;
    int c=1;
    for(k=1;k<=M;k++)
    {   c2=1/c1[k-1];
       if(k==1)
       {
	 for(i=N;i<=N+2*c+1;i++)
	    a[k-1][i]=a[k-1][2*N-1-i];
	 for(i=0;i<=2;i++)
	 {
	   p=0;q=0;
	   for(j=-1;j<=2;j++)
	      p=p+h[j+1]*a[0][(int)(fabs(i-j+0.5)-0.5)];
	   for(j=0;j<=1;j++)
	      q=q+g[j]*a[0][(int)(fabs(i-j+0.5)-0.5)];
	   a[1][i]=p;b[1][i]=-c2*q;
	 }
	  for(i=3;i<=N-1;i++)
	  {
	    p=0;q=0;
	    for(j=-1;j<=2;j++)
	     { p=p+h[j+1]*a[0][(int)(fabs(i-j+0.5)-0.5)]; }
	    for(j=0;j<=1;j++)
	     { q=q+g[j]*a[0][(int)(fabs(i-j+0.5)-0.5)];}
	    a[1][i]=p;b[1][i]=-c2*q;
	   }
	}

	  else
	  {   for(i=N;i<=N+2*c+1;i++)
		 a[k-1][i]=a[k-1][2*N-1-i];
	      for(i=c/2;i<=2*c;i++)
	      {
		p=0;q=0;
		for(j=-1;j<=2;j++)
		 { p=p+h[j+1]*a[k-1][(int)(fabs(i-c*j))];}
		for(j=0;j<=1;j++)
		  {q=q+g[j]*a[k-1][(int)(fabs(i-c*j))];  }
		a[k][i-c/2]=p;b[k][i-c/2]=-c2*q;
	       }
	       for(i=2*c+1;i<=N+c/2;i++)
	       {
		  p=0;q=0;
		  for(j=-1;j<=2;j++)
		     {p=p+h[j+1]*a[k-1][i-c*j];}
		  for(j=0;j<=1;j++)
		    { q=q+g[j]*a[k-1][i-c*j];}
		  a[k][i-c/2]=p;b[k][i-c/2]=-c2*q;
		}
	       }
	    c=2*c;
     }
 }
    void curve(int i,float p[],int j)
	{
	  int k,m;
	  setcolor(RED);
	  line(50,j,652,j);
	  outtextxy(150,j+5,"50");
	  outtextxy(250,j+5,"100");
	  outtextxy(350,j+5,"150");
	  outtextxy(450,j+5,"200");
	  outtextxy(550,j+5,"250");
	  outtextxy(650,j+5,"300");
	  outtextxy(150,j+1,"|");
	  outtextxy(250,j+1,"|");
	  outtextxy(350,j+1,"|");
	  outtextxy(450,j+1,"|");
	  outtextxy(550,j+1,"|");
	  outtextxy(650,j+1,"|");
	  for(k=0;k<i;k++)
	  {  m=600/i;
	     setcolor(GREEN);
	     line(50+k*m,j-(int)(2.341*p[k]),50+(k+1)*m,j-(int)(2.341*p[k+1]));
	  }
	}
     void recon_dwt()
     {   int i,j,k;
	 float p,q,c2;
	 int c=pow(2,M-1);
	 for(k=M;k>=1;k--)
	 {
	   c2=c1[k-1];
	   for(i=N;i<=N+3*c;i++)
	   {
	      b[k][i]=-b[k][2*N-1-i];
	      aa[k][i]=aa[k][2*N-1-i];
	    }
	    for(i=-c/2;i<=3*c;i++)
	    { p=0;q=0;

	      for(j=-1;j<=2;j++)
		p=p+h[j+1]*aa[k][(int)(fabs(i+c*j))];
	      for(j=-3;j<=2;j++)
		if((i-c*j)<=0)
		q=q+k1[j+3]*(-b[k][(int)(fabs(i-c*j))]);
		else
		q=q+k1[j+3]*b[k][(int)(i-c*j)];
	      aa[k-1][i+c/2]=p-c2*q;
	     }
	     for(i=3*c+1;i<=N-c/2;i++)
	     {
	       p=0;q=0;
	       for(j=-1;j<=2;j++)
		 p=p+h[j+1]*aa[k][i+c*j];
	       for(j=-3;j<=2;j++)
		 q=q+k1[j+3]*b[k][i-c*j];
	       aa[k-1][i+c/2]=p-c2*q;
	      }
	      c=c/2;
	 }
   }
