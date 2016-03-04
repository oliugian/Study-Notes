swap(pt1,pt2)
int *pt1,*pt2;
{  int p;
   p=*pt1;*pt1=*pt2;*pt2=p;
}
exchange(q1,q2,q3)
int *q1,*q2,*q3;
{  if (*q1<*q2) swap(q1,q2);
   if (*q1<*q3) swap(q1,q3);
   if (*q2<*q3) swap(q2,q3);
}
main()
{  int a,b,c,*p1,*p2,*p3;
   scanf("%d,%d,%d",&a,&b,&c);
   p1=&a;p2=&b;p3=&c;
   exchange(p1,p2,p3);
   printf("\n%d,%d,%d\n",a,b,c);
}
