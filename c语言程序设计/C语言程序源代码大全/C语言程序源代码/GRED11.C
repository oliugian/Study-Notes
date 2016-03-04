int main(void)
{  int x=1,y=2,z=3,k;
   k=((x=y+1)++||(y<x+2)-(++x<y<z)*2;
   printf("%d\n",k);
   return 0;
}
