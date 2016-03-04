/* reverse.c--displays a file in reverse order */
#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032'  /* eof marker in DOS text files */
int main(int argc,char *argv[])
{
    char ch,name[]={"d1.ttt"};
    FILE *fp,*fp1;
    long count,last;

    if (argc!=2)
    {
       printf("Usage:reverse file\n");
       exit(1);
    }
    if ((fp=fopen(argv[1],"rb"))==NULL)
    {
       printf("reverse can't open %s\n",argv[1]);
       exit(1);
    }
    fseek(fp,0L,SEEK_END);
    last=ftell(fp);
    if ((fp1=fopen(name,"w"))==NULL)
    {
       printf("reverse can't open %s\n",argv[2]);
       exit(2);
    }
    for (count=1L;count<=last;count++)
    {
	fseek(fp,-count,SEEK_END);
	ch=getc(fp);
	/*if (ch!=CNTL_Z&&ch!='\r')*/
	   putc(ch,stdout);
	   putc(ch,fp1);
    }
    fclose(fp);fclose(fp1);
    return 0;
}
