#define N 5
#include <stdio.h>

void creat_arr1(int ar[][N],int n)
{
    int i,j,k=1;
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
      {
	 ar[i][j]=k;
	 k++;
      }
}

void creat_arr2(int ar[][N],int n)
{
    int i,j,k;
    i=j=0;
    for(k=1;k<n*n;k++)
    {
       ar[i][j]=k;
       if (i==0&&j<n-1) {i=j+1;j=0;}
       else if (j==n-1) {j=i+1;i=n-1;}
       else {i--;j++;}
    }
}

void creat_arr3(int ar[][N],int n)
{
    int i,j,k=1;
    for (i=0;i<n;i++)
      if (i%2!=0)
	for (j=n-1;j>=0;j--)
	{
	   ar[i][j]=k;
	   k++;
	}
      else
	for (j=0;j<n;j++)
	{
	   ar[i][j]=k;
	   k++;
	}
}

void creat_arr4(int ar[][N],int n)
{
     int i,j,k,*p;
     p=ar[0];
     for (i=0;i<n*n;i++,p++) *p=0;
     i=0;j=(n-1)/2;
     for (k=1;k<=n*n;k++)
     {
	ar[i][j]=k;i--;j++;
	if (i<0&&j==n) {i+=2;j--;}
	else if (i<0) i=n-1;
	else if (j==n) j=0;
	if (ar[i][j]!=0) {i+=2;j--;}
     }
}

void creat_arr5(int ar[][N],int n)
{
     int a,b,c,d,s,i,k,q,*p;
     a=0;b=n+1;c=n+1;d=0;s=0;p=ar[0];
     for (i=0;i<n*n;i++,p++) *p=0;
     for (k=n-1;k>=0;k-=2)
     {
	a++;
	for (q=a;q<=a-1+k;q++)
	{  s++;
	   ar[a-1][q-1]=s;
	}
	b--;
	for (q=a;q<=a-1+k;q++)
	{  s++;
	   ar[q-1][b-1]=s;
	}
	c--;
	for (q=b;q>=b+1-k;q--)
	{  s++;
	   ar[c-1][q-1]=s;
	}
	d++;
	for (q=c;q>=c+1-k;q--)
	{  s++;
	   ar[q-1][d-1]=s;
	}
    }
    k=n/2;
    if(n%2!=0)ar[k][k]=s+1;
}

void show_arr(int ar[][N],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
	 printf("%4d",ar[i][j]);
       printf("\n");
    }
    printf("\n");
}

int main(void)
{
   int array[N][N];
   creat_arr1(array,N);
   show_arr(array,N);
   creat_arr2(array,N);
   show_arr(array,N);
   creat_arr3(array,N);
   show_arr(array,N);
   creat_arr4(array,N);
   show_arr(array,N);
   creat_arr5(array,N);
   show_arr(array,N);
   return 0;
}



