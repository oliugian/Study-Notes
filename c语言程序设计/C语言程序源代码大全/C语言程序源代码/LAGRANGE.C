float Lagrange(x,y,n,x0)             /* N次Lagrange插值多项式 */
float x[],y[];                       /* 插值结点 */
int n;
float x0;                            /* 插值点 */
{
   int k,j;
   float y0,t;
   y0=0.0;
   for(k=0;k<=n;k++)
   {
      t=1.0;
      for(j=0;j<=n;j++)
	if(j != k) t*=(x0-x[j])/(x[k]-x[j]);
      y0+=t*y[k];
   }
   return (y0);
}
