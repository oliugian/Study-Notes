#define N 10
float average(array)
float array[N];
{  int i;
   float aver,sum=array[0];
   for (i=1;i<N;i++)
     sum=sum+array[i];
   aver=sum/N;
   return (aver);
}
main()
{  float aver,score[N]={100,56,78,98.5,76,87,99,67.5,75,97};
   aver=average(score);
   printf("average score is %5.2f\n",aver);
}
