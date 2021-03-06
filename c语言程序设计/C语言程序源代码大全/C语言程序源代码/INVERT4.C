/* invert4.c - - inverts last 4 bits of integers */
#include <stdio.h>
char * itobs(int,char *);
int invert_end(int num,int bits);
int main(void)
{
   char bin_str[8*sizeof(int)+1];
   int number;
   while(scanf("%d",&number)==1)
   {
      printf("%d is %s\n",number,itobs(number,bin_str));
      printf("invert is %s\n",itobs(invert_end(number,4),bin_str));
   }
   return 0;
}
char * itobs(int n,char * ps)
{
    int i;
    static int size=8*sizeof(int);
    for (i=size-1;i>=0;i--,n>>=1)
      ps[i]=(01&n)+'0';
    ps[size]='\0';
    return ps;
}
int invert_end(int num,int bits)
{
    int mask=0,bitval=1;
    while(bits-->0)
    {
       mask|=bitval;
       bitval<<=1;
    }
    return num^mask;
}

