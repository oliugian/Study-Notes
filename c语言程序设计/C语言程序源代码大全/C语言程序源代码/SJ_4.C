
int b[22];
long int count=0;
static int a[21][8];
static int s[12]={1,3,5,7,11,13,17,19,23,29,31,37};
fun(int i,int k)
{int j,flag,p;
for(j=1;a[i][j]!=0;++j)
 {
 flag=1;
 for(p=1;p<=k && flag==1 ;++p)
    if(b[p]==a[i][j])
    flag=0;
  if(flag==1)
  {b[++k]=a[i][j];
   if(k!=20) fun(a[i][j],k);
   else
   {flag=0;
    for(p=0;p<=11 && flag==0 ;++p)
      if(b[k]+b[1]==s[i]) flag=1;
    if(flag==1) {print();++count;}
   }
   --k;
  }
 }
}

 print()
{int i;
for(i=1;i<=20;++i)
  printf("%3d",b[i]);
printf("\n");
}

main()
{int i,j,m;
for(i=1;i<=20;++i)
 {m=0;
 for(j=0;j<=11;++j)
  if ( (s[j]-i<=20) && (s[j]-i>0)) a[i][++m]=s[j]-i;
 }
b[1]=9;
fun(9,1);
printf("\ncount=%ld\n",count);
}
