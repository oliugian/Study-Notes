#include <stdio.h>
int main(void)
{  int nVar1=100,nVar2=200,nVar3=300;
   int *Array[2];
   Array[0]=&nVar1;
   Array[1]=&nVar2;
   Array[2]=&nVar3;
   printf("%d\n",*Array++);
   return 0;
}

