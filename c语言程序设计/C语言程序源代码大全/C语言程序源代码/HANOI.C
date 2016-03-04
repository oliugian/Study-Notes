/*hanoi.c----hanoi tower*/
void movedisk(takeoff,puton)
int takeoff,puton;
{
   printf("%3d--->%3d\n",takeoff,puton);
}
void movetower(n,a,b,c)
int n,a,b,c;
{  if (n>0)
   {  movetower(n-1,a,c,b);
      movedisk(a,b);
      movetower(n-1,c,b,a);
   }
}
main()
{  int total;
   scanf("%d", &total);
   movetower(total,1,3,2);
}
