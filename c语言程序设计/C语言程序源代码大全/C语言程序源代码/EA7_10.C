#define N 10
main()
{  static int a[N]={1,3,5,7,9,11,13,15,17,19};
   static int b[N]={2,4,6,1,3,7,13,15,18,20};
   int i,n=0,m=0,k=0;
   for (i=0;i<N;i++)
      if (large(a[i],b[i])==1) n=n+1;
      else if (large(a[i],b[i])==0) m=m+1;
      else k=k+1;
   printf("a>b %d\na=b %d\na<b %d\n",n,m,k);
   if (n>k)      printf("array a is larger than array b\n");
   else if (n<k) printf("array a is smaller than array b\n");
   else          printf("array a is equal to array b\n");
}
large(x,y)
int x,y;
{  int flag;
   if (x>y)      flag=1;
   else if (x<y) flag=-1;
   else          flag=0;
   return (flag);
}
