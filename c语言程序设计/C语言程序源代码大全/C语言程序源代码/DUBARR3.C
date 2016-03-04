/* dubarr3.c--doubles array elements*/
#include <stdio.h>
void dub2(int ar[][4],int size);
int main(void)
{
    static int junk[3][4]={{2,4,5,8},{3,5,6,9},{12,10,8,6}};
    int i,j;
    dub2(junk,3);
    for (i=0;i<3;i++)
    {
	for (j=0;j<4;j++)
	    printf("%5d",junk[i][j]);
	putchar('\n');
    }
    return 0;
}

void dub2(int ar[][4],int size)    /* or int (*ar)[4]  */
{
     int i,j;
     for (i=0;i<size;i++)
	 for (j=0;j<4;j++)
	     ar[i][j]*=2;
}

