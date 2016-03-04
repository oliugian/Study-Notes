/* 程序设计作业第二题 */

static str1[25],str2[25];  /* 下标可据输入数改变 */

void prn_str(n)
int n;
{  int i,j,k,e0=0;
   for(i=0;i<n;i++)
   {  if(*(str1+i)!=*(str2+i)) e0=1;
   }
   if(!e0) return;
   for(i=0;i<n;i++) *(str2+i)=*(str1+i);
   printf("%d=",n);
   for(i=1;i<n;i++)
   {  if(*(str2+i-1)<=*(str2+i)) printf("%d+",*(str2+i-1));
      else
      {   printf("%d+",*(str2+i-1));
	  k=i-1;
	  break;
      }
   }
   for(j=k+1;j<n;j++)
   {  if(*(str2+k)<*(str2+j))
      {	printf("%d+",*(str2+j));
	break;
      }
      else if(*(str2+k)==*(str2+j)) printf("%d+",*(str2+j));
   }
   printf("\b \n");
}

void run_prn(n,m,j)
int n,m,j;
{  int i;
   for(i=1;i<=j;i++)
   {  if(m-j<-1) break;
      *(str1+m-j)=j;
      if(m<=1)
      { prn_str(n);
	continue;
      }
      run_prn(n,m-j,i);
   }
}

void message()
{   printf("\n\n*** Please input a number: N. N>1, like: 2, 8, 10, etc.\n");
    printf("\n********* : ");
}

main()
{   char f;
    int i,n,e0,e1;
    do
    { message();
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {  *(str1+i)=1;
	 *(str2+i)=1;
      }
      *(str1+i)=*(str2+i)=0;
      printf("\n\n%d=",n);
      for(i=0;i<n;i++) printf("%d+",*(str1+i));
      printf("\b \n",*(str1+i));
      for(i=0;i<n;i++) run_prn(n,n,i);
      do
      { printf("\n\n***** Do you want to continue ? ( Y/N ) : ");
	scanf("%c",&f);   /* 此处不可少,少则有错 */
	scanf("%c",&f);
	if(f=='y'||f=='Y')
	  { e1=0; e0=1; }
	else if(f=='n'||f=='N')
	       { e1=0; e0=0; }
	     else e1=1;
      }while(e1);
    }while(e0);
}