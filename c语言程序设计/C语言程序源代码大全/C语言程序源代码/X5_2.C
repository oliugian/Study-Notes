#include "stdio.h"
main()
{char c;
 int n1=0,n2=0,n3=0,n4=0;
 while ((c=getchar())!='\n')
   {if ((c>='a'&&c<='z')||(c>='A'&&c<='Z')) n1=n1+1;
    else if (c==' ') n2=n2+1;
    else if (c>='0'&&c<='9') n3=n3+1;
    else n4=n4+1;}
 printf("%d %d %d %d\n",n1,n2,n3,n4);
}