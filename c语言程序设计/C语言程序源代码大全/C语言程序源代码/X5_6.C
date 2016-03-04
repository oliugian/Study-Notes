main()
{int m,a,b,c;
 for (m=100;m<1000;m++)
   {a=m/100;
    b=(m-a*100)/10;
    c=m-a*100-b*10;
    if (m==a*a*a+b*b*b+c*c*c)
      printf("%d\n",m);
   }
}
