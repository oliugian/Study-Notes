int main(void)
{  int x=1,y=2,z=3,k;
   int *nPtr1=&x;
   int *nPtr2=&y;
   k=(*nPtr2=z+y)!=(*nPtr1<*nPtr2)*10;
   printf("%d\n",k);
   return 0;
}
