#include <stdio.h>
#include <stdlib.h>

int main(void) {
    system("chcp 1251");
    float q, p, h = 0;
    int input = 0;

    printf("Введите проценты по вкладам через пробел:\n");

    input = scanf("%f %f %f", &q, &p, &h);

    if (input != 3) {
        printf("Вы ввели некорректные данные...\n");
        exit(0);
    }

    if (q <= 0 || h <= 0 || p <= 0) {
        printf("Введите, пожалуйста, положительное число процентов, отличное от 0...\n");
        exit(0);
    }

    float result = 1;

    q = result * q / 100 / 3;
    p = result * p / 100 / 6;
    h = result * h / 100 / 12;

    if (q > p && q > h) { 
        printf("Вклад на три месяца выгоднее остальных.\n");
    } else if (p > q && p > q) {
        printf("Вклад на полгода выгоднее остальных.\n");
    } else {
        printf("Вклад на год выгоднее остальных.\n");
    }
    return 0;
}