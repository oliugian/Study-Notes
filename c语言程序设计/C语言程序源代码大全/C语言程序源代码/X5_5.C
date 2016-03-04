main()
{int k;
 double s=0;
 for (k=1;k<=100;k++) s=s+k;
 for (k=1;k<=50;k++) s=s+k*k;
 for (k=1;k<=10;k++) s=s+1/(double)k;
 printf("%f\n",s);
}

