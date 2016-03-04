/* sum_arr1.c - - sums the elements of an array */
#include <stdio.h>
#define SIZE 10
long sum(int ar[],int n);
int main(void)
{
    static int marbles[SIZE]={20,10,5,39,4,16,19,26,31,20};
    long answer;
    answer=sum(marbles,SIZE);
    printf("The total number of marbles is %ld.\n",answer);
    printf("The size of marbles is %d bytes.\n",sizeof marbles);
    return 0;
}
long sum(int *ar,int n)
{
    int i;
    long total=0;
    for (i=0;i<n;i++) total+=ar[i];
    printf("The size of ar is %d bytes.\n",sizeof ar);
    return total;
}

