#define NL printf("\n")
#define PRINT(F,V) printf("V=%F\n",V)
#define PRINT1(F,X1) PRINT(F,X1);NL
#define PRINT2(F,X1,X2) PRINT(F,X1);PRINT(F,X2);NL
main()
{  int a,b,c,d;
   float e,f,g,h;
   long i,j;
   char n,m;
   a=1;b=2;c=3;d=4;e=1.5;f=2.5;g=3.5;h=4.5;
   i=10;j=100;n='x';m='y';
   PRINT(d,a);
   PRINT1(d,a);
   PRINT2(d,a,b);
   PRINT2(d,c,d);
   PRINT2(f,e,f);
   PRINT2(f,g,h);
   PRINT2(ld,i,j);
   PRINT2(c,n,m);
}
