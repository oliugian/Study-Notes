/* zeno.c--series sum */
#include <stdio.h>
#define LIMIT 15
int main(void)
{
    int count;
    float time,x;
    for(time=0,x=1,count=1;count<=LIMIT;count++,x*=2.0)
    {
	time+=1.0/x;
	printf("time=%f when count=%d.\n",time,count);
    }
    return 0;
}

