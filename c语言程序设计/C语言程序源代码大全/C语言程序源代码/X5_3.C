main()
{int a,n,i;
 long int s=0,t=0;
 scanf("%d,%d",&a,&n);
 for (i=1;i<=n;i++)
   {t=t*10+a;
    s=s+t;}
 printf("%ld\n",s);
}



