float Romberg(a,b,eps)
float a,b,eps;
{
  float h,s,t1,t2,s1,s2,c1,c2,r1,r2;
  int k=1;
  h=b-a;
  t1=(f(a)+f(b))*h/2.0;
  BH:s=0.0;
  x=a+h/2.0;
  do
  {
    s+=f(x);
    x+=h;
  }while(x<b);
  t2=(t1+h*s)/2.0;
  s2=(4*t2-t1)/3.0;
  if (k==1)
  {  t1=t2;s1=s2;h/=2.0;k++;goto BH; }
  c2=(16*s2-s1)/15.0;
  if (k==2)
  {  t1=t2;s1=s2;c1=c2;h/=2.0;k++;goto BH; }
  r2=(64*c2-c1)/63.0;
  if (k==3)
  {  t1=t2;s1=s2;c1=c2;r1=r2;h/=2.0;k++;goto BH; }
  if (abs(r2-r1)>=eps)
  {  t1=t2;s1=s2;c1=c2;r1=r2;h/=2.0;k++;goto BH; }
  return r2;
}


