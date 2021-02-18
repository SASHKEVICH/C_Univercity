#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int max_min_A5(int *arr, int arr_n)
{
    int max = -2147483647;
    int min = 2147483647;

    for (int i = 0; i < arr_n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (int i = 0; i < arr_n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    int sum = min + max;
    return sum;
}

float averege_elem_A6(int *arr, int arr_n)
{
    int aver_sum;
    for (int i = 0; i < arr_n; i++)
    {
        aver_sum += arr[i];
    }

    aver_sum = aver_sum / arr_n; // Расчет среднего арифмитического

    return aver_sum;
}

int counter_M4(int *arr, int arr_n, int A6)
{
    int k = 0; // Счетчик элементов меньших среднего ариметического
    for (int i = 0; i < arr_n; i++)
    {
        if (arr[i] < A6)
        {
            k++;
        }
    }
    return k;
}

int main(void)
{
    int *arr_1, *arr_2; // Динамаческие массивы
    int n, m;           // Размерности массивов
    float z = 0;        // Общий результат

    printf("Введите размерность двух массивов через пробел: ");

    int res = scanf("%d %d", &n, &m); // Проверк на ввод
    srand(time(NULL));

    if (res != 2)
    {
        printf("Вы ввели неверные данные...");
        return 0;
    }

    arr_1 = (int *)malloc(n * sizeof(int));
    arr_2 = (int *)malloc(m * sizeof(int));

    printf("\nПервый массив размерности %d: \n", n);
    for (int i = 0; i < n; i++)
    {
        arr_1[i] = rand() % (10 + 10 + 1) - 10;
        printf("%3d ", arr_1[i]);
    }
    printf("\n");
    printf("Второй массив размерности %d: \n", m);
    for (int i = 0; i < m; i++)
    {
        arr_2[i] = rand() % (10 + 10 + 1) - 10;
        printf("%3d ", arr_2[i]);
    }
    printf("\n");

    int res_A5_1 = max_min_A5(arr_1, n);
    float res_A6_1 = averege_elem_A6(arr_1, n);
    int res_M4_1 = counter_M4(arr_1, n, res_A6_1);

    printf("\nСумма макс. и мин. значений 1-го массива: %d\n", res_A5_1);
    printf("Среднее арифметическое: %.2f\n", res_A6_1);
    printf("Количество элементов меньших ср. арифм. : %d\n", res_M4_1);

    int res_A5_2 = max_min_A5(arr_2, m);
    float res_A6_2 = averege_elem_A6(arr_2, m);
    int res_M4_2 = counter_M4(arr_2, m, res_A6_2);

    printf("\nСумма макс. и мин. значений 2-го массива: %d\n", res_A5_2);
    printf("Среднее арифметическое: %.2f\n", res_A6_2);
    printf("Количество элементов меньших ср. арифм. : %d\n", res_M4_2);

    if (res_M4_2 > 3)
    {
        z = sqrtf(res_A5_2 + (5.234 * res_M4_2));
    }
    else
    {
        z = fabs((res_A5_1 / res_M4_1) - 1.27 * pow(10, -2));
    }

    free(arr_1);
    free(arr_2);

    printf("\nИтоговое значение z = %f\n", z);
    printf("\nВыполнил Бекренев Александр, 420-4\n");
    system("pause");

    return 0;
}