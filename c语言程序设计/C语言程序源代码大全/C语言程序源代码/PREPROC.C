/* preproc.c - - simple preprocessor examples */
#include <stdio.h>
#define TWO 2
#define MSG "This is a \
program."
#define FOUR TWO*TWO
#define PX printf("X is %d.\n",x)
#define FMT "X is %d.\n"
int main(void)
{  int x=TWO;
   PX;
   x=FOUR;
   printf(FMT,x);
   printf("%s\n",MSG);
   printf("TWO:MSG\n");
   printf("%d:%s\n",TWO,MSG);
   return 0;
}
