/* mac_arg.c - - macros with arguments */
#include <stdio.h>
#define SQUARE(X) X*X
#define PR(X) printf("The result is %d.\n",X)
int main(void)
{
    int x=4;
    int z;
    z=SQUARE(x);
    PR(z);
    z=SQUARE(2);
    PR(z);
    PR(SQUARE(x+2));        /* (x)*(x) */
    PR(100/SQUARE(2));      /* (x*x)        ((x)*(x)) */
    PR(SQUARE(++x));
    return 0;
}
