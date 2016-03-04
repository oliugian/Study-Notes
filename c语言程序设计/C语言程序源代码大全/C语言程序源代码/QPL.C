/*qpl.c----n */
#define N 4
int main(void)
{  int i,j,k,t,found;
   int a[N+1];
   t=1;
   for (k=1;k<=N;k++)a[k]=k;
   printf("t=%3d     ",t);
   for (k=1;k<=N;k++) printf("%3d",a[k]);
   printf("\n");t++;
   found=1;
   while (found)
   {  i=N;found=0;
      while (i>1&&!found)
      {  i--;
	 if (a[i]<a[i+1]) found=1;
      }
      if (found)
      {  j=i+1;
	 for (k=j+1;k<N+1;k++) if (a[i]<a[k]) j=k;
	 k=a[i];a[i]=a[j];a[j]=k;
	 i++;j=N;
	 while (i<j) {k=a[i];a[i]=a[j];a[j]=k;i++;j--;}
	 printf("t=%3d     ",t);
	 for (k=1;k<N+1;k++) printf("%3d",a[k]);
	 printf("\n");t++;
      }
   }
   return (0);
}



