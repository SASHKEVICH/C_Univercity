#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr = NULL; // Динамический массив
    int arr_len = 5; // Число элементов массива
    int Sum = 0;     // Сумма элементов, расположенных между min и max
    int k = 0;       // Количество положительных элементов массива
    int max = -2147483647;
    int min = 2147483647;
    int res = 0; // Правильность введенных данных
    int num_min = 0;
    int num_max = 0;

    printf("Введите размерность массива: ");
    res = scanf("%d", &arr_len);
    if (res != 1 && arr_len < 0)
    {
        printf("Вы ввели неверные данные...");
        return 0;
    }

    arr = (int *)malloc(arr_len * sizeof(int));

    for (int i = 0; i < arr_len; i++)
    {
        printf("Введите значение члена последовательности: ");
        scanf("%d", &arr[i]);
        if (arr[i] > 0) // Задача А
            k++;
        if (max <= arr[i])
        {
            max = arr[i];
            num_max = i;
        }
        if (min >= arr[i])
        {
            min = arr[i];
            num_min = i;
        }
    }
    // Накопление суммы элементов массива (Задача Б)
    if (num_min < num_max)
    {
        for (int i = num_min + 1; i < num_max; i++)
        {
            Sum += arr[i];
        }
    }
    else if (num_min > num_max)
    {
        for (int i = num_max + 1; i < num_min; i++)
        {
            Sum += arr[i];
        }
    }

    for (int i = 0; i < arr_len; i++) // Задача В
    {
        if (arr[i] % 2 == 0)
        {
            for (int j = i; j < arr_len - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            arr = (int *)realloc(arr, (arr_len - 1) * sizeof(int));
            arr_len--;
            i--;
        }
    }

    if (k == 0)
    {
        printf("В массиве нет положительных элеметов\n");
    }
    else
    {
        printf("Колличество положительных элементов в массиве = %d\n", k);
    }
    printf("Сумма элементов расположенных между минимальным значением элементов = %d\n", Sum);
    printf("min = %d, max = %d\n", min, max);

    printf("Вывод преобразованного массива:\n");

    for (int i = 0; i < arr_len; i++) // Вывод элементов массива
    {
        printf("%3d", arr[i]);
    }
    free(arr);

    printf("\nРаботу выполнил Бекренев Александр, 420-4 группа.");
    return 0;
}