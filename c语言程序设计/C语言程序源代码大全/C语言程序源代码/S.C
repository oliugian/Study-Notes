main()
{int i;
 static int a[6];
 for (i=1;i<=5;i++)
   {a[i]=i;
    printf("%d ",a[5-i]);
   }
 printf("\n");
}
