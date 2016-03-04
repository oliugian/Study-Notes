#include <stdio.h>
#define lastrow 8
main()
{  int row,col,pasca[lastrow];
   pasca[0]=1;
   printf("%5d\n",pasca[0]);
   for (row=1;row<lastrow;row++)
   {  pasca[row]=1;
      for (col=row-1;col>0;col--)
	pasca[col]=pasca[col]+pasca[col-1];
      for (col=0;col<row;col++)
	printf("%5d",pasca[col]);
      printf("\n");
   }
}

