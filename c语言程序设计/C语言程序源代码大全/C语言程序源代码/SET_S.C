#include <stdio.h>
void set_s(int n)
{
    if (n==0)
      putchar('O');
    else
    {
       set_s(n-1);
       putchar(',');putchar('{');
       set_s(n-1);
       putchar('}');
    }
}

int main(void)
{  int n;
   /*scanf("%d",&n);*/
   for (n=0;n<5;n++)
   {
      printf("s(%d)=",n);
      set_s(n);
      putchar('\n');
   }
   return 0;
}
