main()
{  int q,r,x,y;
   scanf("%d%d",&x,&y);
   q=0;r=x;
   while (r>=y) {r-=y;q++;}
   printf("%d,%d\n",q,r);
}

