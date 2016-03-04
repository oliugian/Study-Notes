void swapInt(int nVar1,int nVar2)
{
   int Temp=nVar1;nVar1=nVar2;nVar2=Temp;
}
void main()
{  int nVar1=1000,nVar2=2000;
   swapInt(nVar1,nVar2);
   printf("after:%d,%d\n",nVar1,nVar2);
}
