#define N 10
main()
{int k,i,p,t;
 static int a[N+1];
 for (i=1;i<=N;i++)
   scanf("%d",&a[i]);
 for (k=1;k<N;k++)
   {p=k;
    for (i=k+1;i<=N;i++)
      if (a[p]<a[i]) p=i;
    t=a[p];a[p]=a[k];a[k]=t;
   }
 for (i=1;i<=N;i++)
   printf("%d ",a[i]);
 printf("\n");
}
