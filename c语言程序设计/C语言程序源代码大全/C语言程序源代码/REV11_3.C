/* rev11_3.c - - 字符串、循环、指针和指针增量 */
#include <stdio.h>
char *pr(char *str)
{
    char *pc;
    pc=str;
    while (*pc)
       putchar(*pc++);
    do {
	  putchar(*--pc);
       } while (pc-str);
    return (pc);
}
int main(void)
{  char *x;
   x=pr("Ho Ho Ho!");
   putchar('\n');
   return 0;
}
/*  考虑函数调用：    x=pr("Ho Ho Ho!");
    １、打印结果
    ２、x 应该具有的类型
    ３、x 获得的值
    ４、表达式  *--pc 的含义，与  --*pc  的区别
    ５、用  *pc-- 代替  *--pc  后的打印结果
    ６、两个 while 表达式测试的内容
    ７、如果将一个空字符串赋予  pr()  作为参数，将出现什么情况
*/