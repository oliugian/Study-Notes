/* pnt_add.c - - pointer addition */
#include <stdio.h>
#define SIZE 4
int main(void)
{
    int dates[SIZE],* pti,index;
    float bills[SIZE],* ptf;
    pti=dates;      /* assign address of array to pointer */
    ptf=bills;
    for (index=0;index<SIZE;index++)
	printf("pointer+%d:%10p %10p\n",index,pti+index,ptf+index);
    return 0;
}
/*   dates+2==&dates[2]
     *(dates+2)==dates[2]   */
