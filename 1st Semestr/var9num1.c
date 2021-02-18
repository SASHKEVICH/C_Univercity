#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system("chcp 1251");

    for (int i = 0; i < 33; i++)
    {
        printf("*");
    }
    printf("\n");
    printf("\n");

    printf("*     x     *\t    1 x 5\t*\n\n");

    for (int i = 0; i < 33; i++)
    {
        printf("*");
    }
    printf("\n");
    printf("\n");

    for (int j = 1; j <= 5; j++)
    {
        int res = j * 5;
        printf("*     %d     *\t  %5d\t        *\n\n", j, res);
    }

    for (int i = 0; i < 33; i++)
    {
        printf("*");
    }
    printf("Работу выполнил Бекренев Александр, 420-4 группа");

    return 0;
}