#include <stdio.h>
char ref[]={'D','O','L','T'};
int main(void)
{
    char *ptr;
    int index;
    for (index=0,ptr=ref;index<4;index++,ptr++)
      printf("%c %c\n",ref[index],*ptr);
    return 0;
}
