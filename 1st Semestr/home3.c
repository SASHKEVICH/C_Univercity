#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    system("chcp 1251");

    int input = 0;
    float m, eps, x, a = 0; // a = y[n + 1]
    float y = 0.1;          // y[0]

    printf("Введите значение m, x и eps через пробел: ");
    input = scanf("%f %f %f", &m, &x, &eps);

    if (input != 3)
    {
        printf("Вы ввели неверные данные...");
        exit(0);
    }
    if (x <= 0 || eps <= 0)
    {
        printf("Вы ввели неверные данные...");
        exit(0);
    }

    float b = 0;

    if (m == 0)
    {

        printf("Любое число в степени 0 равно единице. Результат - 1.\n");
    }
    else if (m > 0)
    { // Если показатель степени положителен.

        b = 1 / m;

        a = y + b * (x / pow(y, m - 1) - y);

        while (fabs(a - y) > eps)
        {

            y = a;

            a = y + b * (x / pow(y, m - 1) - y);
        }
        printf("Результат алгоритма - %f\n", a);

        float a1 = pow(x, b);
        printf("Результат pow - %f\n", a1);

        printf("Разница между алгоритом и функцией pow - %.7f\n", fabs(a1 - a));
        printf("Выполнил работу Бекренев Александр, группа 420-4.");
    }
    else
    { // Если показатель степени отрицателен.
        b = 1 / m;

        a = y + b * (x / pow(y, m - 1) - y);

        while (fabs(a - y) > eps)
        {

            y = a;

            a = y + b * (x / pow(y, m - 1) - y);
        }
        printf("Результат алгоритма - %f\n", a);

        float a1 = pow(x, b);
        printf("Результат pow - %f\n", a1);

        printf("Разница между алгоритом и функцией pow - %.7f\n", fabs(a1 - a));
        printf("Выполнил работу Бекренев Александр, группа 420-4.");
    }

    return 0;
}