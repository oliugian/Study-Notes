/* M 进制转换为 R 进制 */

#include "string.h"
#include "stdio.h"
#include "math.h"

long int m_dec(str,m,l)
char str[];
int m,l;
{  int i;
   long int n=0;
   for(i=0;i<l;i++)
      if(str[i]-'0'>9&&str[i]-'0'<23) n=n*m+(str[i]-'0'-7);
      else if(str[i]-'0'>=23) n=n*m+(str[i]-'0'-39);
	   else n=n*m+(str[i]-'0');
   return(n);
}

void dec_r(n,r)
long int n;
int r;
{  int t;
   t=n%r;
   if(n>=r) dec_r(n/r,r);
   if(t>9) putchar('0'+t+7);
   else putchar('0'+t);
}

void massage()
{   printf("\n\n*****  Input M, R and Num, like:  M<Num>R.  M, R MUST little than 16,");
    printf("\n\n*****  as: 1<M<16, 1<N<16. For examples: 8<12345>10, 2<101111>16 etc.\n");
    printf("\n\n********* : ");
}

void in_err()
{   printf("\n\n\t\t*********   Input   Error   !    ********* \n\n");
}

main()
{   char str1[25],str2[25],f;
    int i,j,m,r,k,l,o,e1,e2,e3;
    long int t;
    e2=1;
    while(e2)
    {    e1=0;
	 while(!e1)
	 {    massage();
	      scanf("%s",str1);
              printf("\n\n");
	      l=strlen(str1);
	      if(l<5) in_err();
	      else
	      {   for(i=0;str1[i]!='<';i++) ;
		  if(i>2) in_err();
		  else
		  {   if(i==2) m=(str1[0]-'0')*10+(str1[1]-'0');
		      else m=str1[0]-'0';
		      if(m<2||m>16) in_err();
		      else
		      {   for(j=1,i++,k=0;str1[i]!='>'&&j==1;i++,k++)
			  {  if(m<=10)
			     { if(str1[i]-'0'<m&&str1[i]>='0') str2[k]=str1[i];
			       else
			       {   in_err();
				   j=0;
				}
			     }
			     else
			     {   if(str1[i]-'0'<9&&str1[i]>='0') str2[k]=str1[i];
				 else
				 {   if(str1[i]>'A'&&str1[i]-'A'<=m-11) str2[k]=str1[i];
				     else
				     {   if(str1[i]>'a'&&str1[i]-'a'<=m-11) str2[k]=str1[i];
					 else
					 {   in_err();
					     j=0;
					 }
				     }
				 }
			     }
			  }
			  if(j==1)
			  { if(l-i-1>2) in_err();
			    else
			    {   if(l-i-1==2) r=(str1[i+1]-'0')*10+(str1[i+2]-'0');
				else r=str1[i+1]-'0';
				if(r>16||r<2) in_err();
				else e1=1;
			    }
			  }
		      }
		  }
	      }
	 }
	 t=m_dec(str2,m,k);
	 dec_r(t,r);
	 e3=1;
	 while(e3)
	 {    printf("\n\n\n*** Do you want to continue ? ( Y/N ) : ");
	      f=getchar();  /* 此处不运行,但不可少 */
	      scanf("%c",&f);
	      if(f=='n'||f=='N')
	      { e2=0;
		e3=0;
	      }
	      else
	      {   if(f=='y'||f=='Y')
		  { e2=1;
		    e3=0;
		  }
		  else e3=1;
	      }
	 }
     }
}