#include <stdio.h>
main()
{  int z[4][2];
   printf("z=%p,z[0]=%p,&z[0][0]=%p,*z=%p\n",z,z[0],&z[0][0],*z);
   printf("z+1=%p,z[0]+1=%p\n",z+1,z[0]+1);
   printf("&z[0][0]+1=%p,*z+1=%p\n",&z[0][0]+1,*z+1);
   printf("*(z+1)=%p\n",*(z+1));
}
