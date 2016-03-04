/*  m_to_r.c - - m->r tanslation */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int str_to_dec(str,l)
char str[];
int l;
{
    int i,m=0;
    for (i=0;i<l;i++) m=m*10+(str[i]-'0');
    return(m);
}

int m_to_dec(str,l,m)
char str[];
int l,m;
{
    int i,n=0;
    for (i=0;i<l;i++)
       if (str[i]-'0'>9&&str[i]-'0'<23) n=n*m+(str[i]-'0'-7);
       else if (str[i]-'0'>23) n=n*m+(str[i]-'0'-39);
       else n=n*m+(str[i]-'0');
    return(n);
}

void dec_to_r(n,r)
int n;
{
    int t;
    t=n%r;
    if (n>=r)dec_to_r(n/r,r);
    if (t>9) putchar('0'+t+7);
    else putchar('0'+t);
}

int check(str,l)
char str[];
int l;
{
    int i,m,r;
    char *p,*q;
    p=strchr(str,'<');
    if (p==NULL) return 0;
    else m=p-str;
    if (m==0) return 0;
    for(i=0;i<m;i++) if (!isdigit(str[i])) return 0;
    q=strchr(str,'>');
    if (q==NULL) return 0;
    else r=(str+l)-q;
    for (i=l-r+1;i<l;i++) if (!isdigit(str[i])) return 0;
    for (i=m+1;i<l-r;i++) if (!isxdigit(str[i])) return 0;
    return 1;
}

int main(void)
{
    int m,r,n,l;
    char str[20],*p1,*q1;
    gets(str);
    l=strlen(str);
    p1=strchr(str,'<');
    q1=strchr(str,'>');
    if (check(str,l,p1,q1))
    {
       m=str_to_dec(str,p1-str);
       printf("m=%d\n",m);
       r=str_to_dec(q1+1,(str+l-1)-q1);
       printf("r=%d\n",r);
       n=m_to_dec(p1+1,q1-p1-1,m);
       printf("n=%d\n",n);
       dec_to_r(n,r);
       putchar('\n');
    }
    else
       printf("error!\n");
    return 0;
}
