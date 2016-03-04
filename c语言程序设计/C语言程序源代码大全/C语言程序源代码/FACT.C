long int fact(n)
int n;
{  long int t;
   if(n==0)t=1;
   else t=n*fact(n-1);
   return (t);
}
main()
{  int m;
   scanf("%d",&m);
   printf("%d!=%ld\n",m,fact(m));
}
