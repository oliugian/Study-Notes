/* swap3.c - - using pointers to make swapping work */
#include <stdio.h>
void interchange(int * u,int * v);
int main(void)
{
    int x=5,y=9;
    printf("Originally x=%d and y=%d.\n",x,y);
    interchange(&x,&y);      /* send address to function */
    printf("Now x=%d and y=%d.\n",x,y);
    return 00;
}
void interchange(int * u,int * v)
{
    int temp;
    temp=* u;      /* temp gets value that u points to */
    * u=* v;
    * v=temp;
}

