main()
{int m,n,x,y,r;
 scanf("%d,%d",&m,&n);
 if (m>n) {x=m;y=n;}
 else     {x=n;y=m;}
 r=x%y;
 while (r!=0) {x=y;y=r;r=x%y;}
 printf("d=%d,c=%d\n",y,m*n/y);
}
