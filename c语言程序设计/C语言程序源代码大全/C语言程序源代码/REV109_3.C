#include <stdio.h>
int main(void)
{
   int *ptr1,*ptr2;
   static int torf[2][2]={12,14,16};
   static int fort[2][2]={{12},{14,16}};
   ptr1=torf[0];ptr2=fort[0];
   printf("*ptr1=%d,*(ptr1+2)=%d\n",*ptr1,*(ptr1+2));
   printf("*ptr2=%d,*(ptr2+2)=%d\n",*ptr2,*(ptr2+2));
   return 0;
}
