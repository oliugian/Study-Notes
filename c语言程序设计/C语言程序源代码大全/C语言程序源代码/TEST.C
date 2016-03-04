
#include <stdio.h>

char xx[100][11] ;
int yy[10] ;
int ReadDat(void) ;
void WriteDat(void) ;

void CountRs(void)
{


}
void main()
{
  int i ;

  for(i = 0 ; i < 10 ; i++) yy[i] = 0 ;
  if(ReadDat()) {
    printf("选票数据文件XP.IN不能打开!\007\n") ;
    return ;
  }
  CountRs() ;
  WriteDat() ;
}

int ReadDat(void)
{
  FILE *fp ;
  int i ;

  if((fp = fopen("TEST.IN", "r")) == NULL) return 1 ;
  for(i = 0 ; i < 100 ; i++) {
    if(fgets(xx[i], 11 , fp) == NULL) return 1 ;
    xx[i][10] = '\0' ;
  }
  fclose(fp) ;
  return 0 ;
}

void WriteDat(void)
{
  FILE *fp ;
  int i ;

  fp = fopen("TEST.OUT", "w") ;
  for(i = 0 ; i < 10 ; i++) {
    fprintf(fp, "%d\n", yy[i]) ;
    printf("第%d个人的选票数=%d\n", i + 1, yy[i]) ;
  }
  fclose(fp) ;
}
