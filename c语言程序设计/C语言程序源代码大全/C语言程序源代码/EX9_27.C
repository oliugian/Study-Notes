main()
{  static float score[][4]={{60,70,80,90},{56,89,67,88},{34,78,90,66}};
   float *search();
   float *p;
   int i,j;
   for (i=0;i<3;i++)
   {  p=search(score+i);
      if (p==*(score+i))
      {  printf("No.%d scores: ",i);
	 for (j=0;j<4;j++)
	   printf("%5.2f ",*(p+j));
	 printf("\n");
      }
   }
}
float *search(pointer)
float (*pointer)[4];
{  int i;
   float *pt;
   pt=*(pointer+1);
   for (i=0;i<4;i++)
     if (*(*pointer+i)<60) pt=*pointer;
   return (pt);
}
