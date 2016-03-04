/* binary.c--prints integer in binary form */
#include <stdio.h>
void to_binary(int n);
int main(void)
{  int number;
   while(scanf("%d",&number)==1)
   {  to_binary(number);
      putchar('\n');
   }
   return 0;
}
void to_binary(int n)
{  int r;
   r=n%2;
   if (n>=2)
     to_binary(n/2);
   putchar('0'+r);
   return;
}
