/*fibo.c--fibonacci numbers*/
long int fibonacci(n)
int n;
{  long int f;
   if (n==1) f=0;
   else if (n==2) f=1;
   else f=fibonacci(n-1)+fibonacci(n-2);
   return (f);
}
main()
{  int m,i;
   scanf("%d",&m);
   for (i=1;i<=m;i++)
     printf("%4d  %7ld\n",i,fibonacci(i));
   printf("\n");
}
