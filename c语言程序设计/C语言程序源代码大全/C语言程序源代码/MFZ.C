#define N 7
main()
{  static int a[N+1][N+1];
   int i,j,k;
   i=1;j=(N+1)/2;
   for (k=1;k<=N*N;k++)
   {  a[i][j]=k;i--;j++;
      if (i==0&&j==N+1) {i+=2;j--;}
      else if (i==0) i=N;
      else if (j==N+1) j=1;
      if (a[i][j]!=0) {i+=2;j--;}
   }
   for (i=1;i<=N;i++)
   {  for (j=1;j<=N;j++)
	printf("%4d",a[i][j]);
      printf("\n");
   }
}
