/* sum_arr2.c - - sums the elements of an array */
#include <stdio.h>
#define SIZE 10
long sump(int *ar,int n);
int main(void)
{
    static int marbles[SIZE]={20,10,5,39,4,16,19,26,31,20};
    long answer;
    answer=sump(marbles,SIZE);
    printf("The total number of marbles is %ld.\n",answer);
    return 0;
}
long sump(int *ar,int n)        /* use pointer arithmetic */
{
    int i;
    long total=0;
    for (i=0;i<n;i++)          /* total+=*ar++  */
    {
	total+=*ar;            /* add value to total */
	ar++;                  /* advance pointer to next element */
    }
    return total;
}

