#include"stdio.h"
main()
{
 long data1[200],data2[200],number,sum,x;
 int i,i1,i2,i3,i4,k,kkk;
 char data1_[200][18],data2_[200][18],key='y';
 for(k=0;k<200;k++)
 {
 for(i=0;i<9;i++)
 {
 data1_[k][i*2]=i+1+'0';if(i>0)data1_[k][i*2-1]='+';
 data2_[k][i*2]=i+1+'0';if(i>0)data2_[k][i*2-1]=' ';
 }
 data1_[k][17]='\0';data2_[k][17]='\0';
 }
 k=0;
 for(i1=0;i1<8;i1++)
 {
 *(data1_[k]+i1*2+1)=' ';
 *(data2_[k]+i1*2+1)='+';
 k++;
 if(i1<7)
 for(i2=i1+1;i2<8;i2++)
 {
 *(data1_[k]+i1*2+1)=*(data1_[k]+i2*2+1)=' ';
 *(data2_[k]+i1*2+1)=*(data2_[k]+i2*2+1)='+';
 k++;
 if(i2<7)
 for(i3=i2+1;i3<8;i3++)
 {
 *(data1_[k]+i1*2+1)=*(data1_[k]+i2*2+1)=*(data1_[k]+i3*2+1)=' ';
 *(data2_[k]+i1*2+1)=*(data2_[k]+i2*2+1)=*(data2_[k]+i3*2+1)='+';
 k++;
 if(i3<7)
 for(i4=i3+1;i4<8;i4++)
 {
 *(data1_[k]+i1*2+1)=*(data1_[k]+i2*2+1)=
 *(data1_[k]+i3*2+1)=*(data1_[k]+i4*2+1)=' ';
 *(data2_[k]+i1*2+1)=*(data2_[k]+i2*2+1)=
 *(data2_[k]+i3*2+1)=*(data2_[k]+i4*2+1)='+';
 k++;
 }
 }
 }
 }
 clrscr();printf("If enter 54,You may get:54=1 2+3+4+5+6+7+8+9.\n");
 printf("\nAlready computed all the case.\n",k);
 for(k=0;k<200;k++)
 {
 sum=0;x=1;
 for(i=1;i<17;i++)
 {
 if(*(data1_[k]+i)!='+')
 if(*(data1_[k]+i)!=' ')x=x*10+*(data1_[k]+i)-'0';
 else continue;
 else {sum=sum+x;x=*(data1_[k]+i+1)-'0';i++;}
 }
 data1[k]=sum+x;sum=0;x=1;
 for(i=1;i<17;++i)
 {
 if(*(data2_[k]+i)!='+')
 if(*(data2_[k]+i)!=' ') x=x*10+*(data2_[k]+i)-'0';
 else continue;
 else {sum=sum+x;x=*(data2_[k]+i+1)-'0';i++;}
 }
 data2[k]=sum+x;
 }
 printf("\n.....................\n");
 printf("\nNow you may enter a long int to look up.\n");
 while(key=='y')
 {
 printf("\nEnter a number(<=9 digitals):");
 scanf("%ld",&number);
 kkk=1;
 for(k=0;k<200;k++)
 {
 if(number==data1[k]){printf("%ld=%s.\n",number,data1_[k]);kkk=0;break;}
 if(number==data2[k]){printf("%ld=%s.\n",number,data2_[k]);kkk=0;break;}
 }
 if(kkk)printf("Not found!\n");
 printf("\npress 'y' to continue, any key to quit.\n");
 key=getch();
 }
}

