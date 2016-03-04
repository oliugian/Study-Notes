#define N 15
main()
{  static int a[N+1]={0,1,3,5,7,9,11,13,15,17,19,21,23,25,27,29};
   int i,j,k,x;
/*   for (i=1;i<=N;i++)
     scanf("%d",&a[i]);*/
   scanf("%d",&x);
   i=1;j=N;k=(i+j)/2;
   while (x!=a[k]&&i<=j)
   {  if (x>a[k]) i=k+1;
      else        j=k-1;
      k=(i+j)/2;
   }
   if (j<i) printf("%d not found!\n",x);
   else     printf("a[%d]=%d\n",k,x);
}

