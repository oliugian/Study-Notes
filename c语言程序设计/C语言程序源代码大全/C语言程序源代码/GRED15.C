int main(void)
{  int x=1,y=2,z=3,k;
   k=((x<<2)+(y>--z>0?y:z++))&&(y|--x);
   printf("%d\n",k);
   return 0;
}
