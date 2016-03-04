#include <stdio.h>
#include <math.h>
long Proc(long Number,int N)
{
   if (N==1)
     {  return Number;
     }
   else
     {  return (Number%10)*pow(10,N-1)+Proc(Number/10,N-1);
     };
};
void main()
{
   printf("Result is:%ld\n",Proc(1234567,7));
};

