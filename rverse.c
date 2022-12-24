#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char x = '3';
    char y = '5';
    int ans = (int)x + (int)y - 96;
    char ans2 = (char)ans;
    printf("%d", ans2);
}
