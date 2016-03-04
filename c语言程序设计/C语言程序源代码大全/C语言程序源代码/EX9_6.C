main()
{  float *p,i,a[10];
   p=a;
   for (i=0;i<10;i++)
     scanf("%f",p++);
   printf("\n");
   for (p=a,i=0;i<10;i++,p++)
     printf("%d  %f\n",p,*p);
   printf("\n");
}

