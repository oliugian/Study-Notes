#define N 7
main()
{  static int a[N+1][N+1];
   int m,k,i,j;
   m=N*N;
   i=1;j=N/2+1;
   for (k=1;k<=m;k++)
   {   a[i][j]=k;
       i=i-1;j=j+1;
       if (i==0&&j==N+1) { i=i+2;j=j-1; }
       else if (i==0) i=N;
       else if (j==N+1) j=1;
       else if (a[i][j]!=0) { i=i+2;j=j-1; }
   }
   for (i=1;i<=N;i++)
   {   for (j=1;j<=N;j++)
	   printf("%4d",a[i][j]);
       printf("\n");
   }
}


