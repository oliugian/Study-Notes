#include <stdio.h>
#define LASTROW 10
main()
{  int row,col,pasca[LASTROW];
   pasca[0]=1;
   printf("%5d\n",pasca[0]);
   for (row=1;row<LASTROW;row++)
   {  pasca[row]=1;
      for (col=row-1;col>0;col--)
	pasca[col]=pasca[col]+pasca[col-1];
      for (col=0;col<=row;col++)
	printf("%5d",pasca[col]);
      printf("\n");
   }
}

