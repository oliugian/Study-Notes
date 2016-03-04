/* dubarr2.c--doubles array elements*/
#include <stdio.h>
void dub(int ar[],int size);
int main(void)
{
    static int junk[3][4]={{2,4,5,8},{3,5,6,9},{12,10,8,6}};
    int i,j;
    dub(junk[0],3*4);
    for (i=0;i<3;i++)
    {
	for (j=0;j<4;j++)
	    printf("%5d",junk[i][j]);
	putchar('\n');
    }
    return 0;
}

void dub(int ar[],int size)    /* or int *ar  */
{
     int i;
     for (i=0;i<size;i++)
	 ar[i]*=2;
}

