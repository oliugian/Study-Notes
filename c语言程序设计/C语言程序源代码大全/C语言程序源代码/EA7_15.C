#define N 10
float max=0,min=0;
float average(array,n)
float array[];
int n;
{  int i;
   float aver,sum=array[0];
   max=min=array[0];
   for (i=1;i<N;i++)
   {  if (array[i]>max) max=array[i];
      else if (array[i]<min) min=array[i];
      sum=sum+array[i];
   }
   aver=sum/N;
   return (aver);
}
main()
{  float aver,score[N]={100,56,78,98.5,76,87,99,67.5,75,97};
   aver=average(score,N);
   printf("max=%5.2f,min=%5.2f,average=%5.2f\n",max,min,aver);
}
