#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int **arr;
    int n = 0;   // Размерность массива
    int res = 0; // Проверка условия
    int var_a = 0;
    int var_b = 0;
    int count_elem = 0; // Элементы между a и b
    int max_elem = 0;
    int temp_list = 0;  // Временная переменная для списка
    int *temp_matr = 0; // Временная переменная для матрицы
    int flag = 0;

    srand(time(NULL));
    system("chcp 1251");

    printf("Введите размерность матрицы, значение a и значение b: ");
    res = scanf("%d %d %d", &n, &var_a, &var_b);
    if (res != 3)
    {
        printf("Вы ввели неверные данные...");
        system("PAUSE");
        return 0;
    }
    int *max; // Массив с максимальными элементами
    max = (int *)malloc(n * sizeof(int));

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < n; i++) // Счетчик элементов между a и b
    {
        for (int j = 0; j < n; j++)
        {
            if ((arr[i][j] >= var_a) || (arr[i][j] <= var_b))
                count_elem++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] > max_elem)
            {
                max[i] = arr[i][j];
                max_elem = arr[i][j];
            }
        }
        max_elem = 0;
    }

    printf("\nНеотсортированная матрица:\n");

    for (int i = 0; i < n; i++) // Неотсортированная матрица
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", arr[i][j]);
        }
        printf("\n\n");
    }

    printf("\nМассив с максимальными значениями\n");
    for (int i = 0; i < n; i++) // Массив с максимальными значениями
    {
        printf("Строка %i. Максимальный элемент этой строки - %3d\n", i + 1, max[i]);
    }
    printf("\n");

    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (max[j] > max[j + 1])
            {
                temp_list = max[j];
                max[j] = max[j + 1];
                max[j + 1] = temp_list;
                temp_matr = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp_matr;
                flag = 1;
            }
        }
        if (!flag)
            break;
    }

    printf("\nСортированный массив с максимальными значениями\n");
    for (int i = 0; i < n; i++) // Сортированный массив с максимальными значениями
    {
        printf("%3d", max[i]);
    }
    printf("\n\n");

    printf("Отсортированная матрица:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", arr[i][j]);
        }
        printf("\n\n");
    }
    printf("\nКоличество элементов от a до b - %d\n", count_elem);
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);
    system("PAUSE");
    return 0;
}
