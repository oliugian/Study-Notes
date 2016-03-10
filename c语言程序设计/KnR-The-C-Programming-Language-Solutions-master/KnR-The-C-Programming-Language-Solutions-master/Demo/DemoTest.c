#include <stdio.h>
#include <stdlib.h>
#define ngx_tolower(c)    (unsigned char) ((c >= 'A' && c <= 'Z') ? (c | 0x20) : c)
int main(void)
{
    static char   basis64[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    printf("%d",sizeof(basis64));
    return 0;
}
