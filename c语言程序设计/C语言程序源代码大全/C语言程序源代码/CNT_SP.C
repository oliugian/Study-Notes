/* cnt_sp.c - - counts whitespace characters */
#include <stdio.h>
#include "bool.h"
BOOLEAN whitesp(char);
int main(void)
{
    int ch;
    int count=0;
    while((ch=getchar())!=EOF)
      if (whitesp(ch)==TRUE) count++;
    printf("There are %d whitespace characters.\n",count);
    return 0;
}
BOOLEAN whitesp(char c)
{
    if(c==' '||c=='\n'||c=='\t')
      return (TRUE);
    else
      return (FALSE);
}
