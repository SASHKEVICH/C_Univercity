#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("chcp 1251");

    int k, correct = 0;
    int chisl, znam = 1;

    float sum, b, A = 0;

    printf("Введите через пробел количество элементов k и ваше число А ");
    correct = scanf("%d %f", &k, &A);

    if (correct != 2)
    {
        printf("Вы ввели неверные данные...");
        return 0;
    }

    for (int i = 0; i < k; i++)
    {
        chisl = chisl + znam;
        znam = chisl;
        b = chisl / znam;
        sum += b;
    }

    if (sum > A)
    {
        printf("Сумма первых %d элементов больше вашего числа.\n", k);
    }
    else
    {
        printf("Сумма первых %d элементов меньше вашего числа.\n", k);
    }

    printf("Работу выполнил Бекренев Александр, 420-4 группа\n");
    return 0;
}