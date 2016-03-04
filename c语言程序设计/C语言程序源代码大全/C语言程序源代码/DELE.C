#define N 15
main()
{  static int a[N]={1,1,2,1,4,4,3,3,4,3,1,1,6,6,6};
   int i,j,k,m=N;
   for (k=0;k<m-1;k++)
     for (j=k+1;j<m;j++)
	while (a[k]==a[j])
	{  if (k==m-1) break;
	   for (i=j+1;i<m;i++) a[i-1]=a[i];
	   m--;
	}
   for (k=0;k<m;k++) printf("%3d",a[k]);
   printf("\nm=%d\n",m);
}

