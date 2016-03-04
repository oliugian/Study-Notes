jy_rose(int x,int y1,int y2)
{ int t;
  line(x,y1,x+3,y1);
  line(x,y2,x+3,y2);
  t=(y2-y1)/2-3;
  line(x,y1,x,y1+t);
  line(x,y1+t,x-3,(y2-y1)/2+y1);
  line(x,y2,x,y2-t);
  line(x,y2-t,x-3,(y2-y1)/2+y1);
}
jy_1(int x,int y)
{
 outtextxy(x,y,"-1");
}
thesame()
{ setfillstyle(1,8);
 bar(58,88,592,148);
 upbar(48,78,582,138);
 dnbarfill(40,160,600,410,60);
}
same()
{cleardevice();
 setbkcolor(7);
 menu2(1,1,639,479,8,15,7);
 dnbar(8,8,632,472);
 dnbarfill(28,28,612,58,9);
 outhz16("线性代数辅助教学逆矩阵",190,36,15,16);
 dnbarfill(28,68,612,417,9);
 dnbar(28,427,612,452);
}
same2()
{
 outhz16("请按回车键继续",40,432,9,16);
 setcolor(9);
 outtextxy(155,436,"...");}
jy(int x1,int y1,int x2,int y2)
{
 line(x1,y1,x1+3,y1);
 line(x1,y2,x1+3,y2);
 line(x1,y1,x1,y2);
 line(x2,y1,x2,y2);
 line(x2,y1,x2-3,y1);
 line(x2,y2,x2-3,y2);
}
