#include <stdio.h>
#include <dos.h>
#include <string.h>

struct stu_type{
    char xh[7];
    char bj[10];
    char xm[8];
    char sex[2];
  };
int main(void)
{   char zkzh[8],*str="md ",*str1;
    struct stu_type stud;
    int k,chioce=1,ft();
    int yy;
    FILE *fp;
    while (chioce==1)
    {
      clrscr();

      printf("请输入准考证号：");
      scanf("%s",zkzh);
      fp=fopen("d:\\st98.dat","r");
      fread(&stud,sizeof(struct stu_type)+1,1,fp);
      while (!feof(fp)&&ft(stud.xh,zkzh)==0)
      {  fread(&stud,sizeof(struct stu_type)+1,1,fp);
      }
      if (!feof(fp))
      {  printf("\n\n");
	 printf("准考证号：");
	 for(k=0;k<7;k++)putchar(stud.xh[k]);printf("\n\n");
	 printf("班    级：");
	 for(k=0;k<10;k++)putchar(stud.bj[k]);printf("\n\n");
	 printf("姓    名：");
	 for(k=0;k<8;k++)putchar(stud.xm[k]);printf("\n\n");
	 printf("性    别：");
	 for(k=0;k<2;k++)putchar(stud.sex[k]);printf("\n\n");
	 printf("请确认（正确输入１，否则输入０）？ ");
	 scanf("%d",&yy);
	 if(yy==1)chioce=0;
	 else {printf("\n\n请重新输入准考证号！\n");getch();}
      }
      else {printf("\n\n查无此号，请重新输入准考证号！\n");getch();}

      fclose(fp);

    }
    system("cd\\");
    str1=strcat(str,zkzh);
    system(str);
    str1=strcat("cd\\",zkzh);
    system(str1);

    system("md stm");

    system("md user");
    system("md user\\bas");
    system("md user\\for");
    system("md user\\txt");
    system("md user\\txt\\asc");
    system("md user\\txt\\doc");
    system("md stm");
    system("md stm\\uc");
    system("md stm\\win");
    system("md stm\\uc\\drv");
    system("copy c:\\config.sys user\\txt\\asc\\cbk.sys>nul");
    system("copy c:\\autoexec.bat user\\txt\\doc\\abk.wri>nul");
    system("copy c:\\dos\\tree.com stm\\win\\try.cdx>nul");
    system("attrib -h d:\\ls");
    system("copy d:\\ls test.wps>nul");
    system("attrib +h d:\\ls");
    return 0;
}

int ft(char *x,char *y)
{  int k,f=1;
   for (k=0;k<7;k++)
     if (x[k]!=y[k]) f=0;
   return f;
}
