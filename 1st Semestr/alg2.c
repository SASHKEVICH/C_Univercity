#include <stdlib.h>
#include <stdio.h>

// Функция транспонирует матрицу
void transpose(int **matrix, int matr_size_m, int matr_size_n)
{
    int t;
    for (int i = 0; i < matr_size_m; ++i)
    {
        for (int j = i; j < matr_size_n; ++j)
        {
            t = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = t;
        }
    }
}

int main(void)
{
    system("chcp 1251");
    int n; // Количество столбцов матрицы
    int m; // Количество строк матрицы
    int p = 0;
    int max = 0;
    int max_local = 0;
    int flag = 0;
    // int arr[4][3] = {3, 6, 8,
    //                  4, 3, 7,    Тестовая матрица
    //                  5, 9, 6,
    //                  6, 4, 5};
    printf("Введите размерность матрицы: ");
    scanf("%d %d", &m, &n);

    int **arr = (int **)malloc((n * m) * sizeof(int *));

    for (int i = 0; i < n; i++)
        arr[i] = (int *)calloc(m, sizeof(int));

    transpose(arr, m, n);

    for (int i = 0; i < n; i++)
    {
        flag = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] < arr[i][j + 1])
            {
                max_local = arr[i][0];
                flag++;
                if (flag == 3)
                    max_local = arr[i][n];
            }
            else
            {
                break;
            }
        }
        flag = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] > arr[i][j + 1])
            {
                max_local = arr[i][0];
                flag++;
                if (flag == 3)
                    max_local = arr[i][0];
            }
            else
            {
                break;
            }
        }
        if (max_local > max)
            max = max_local;
    }

    if (flag == 0)
        printf("В матрице нет упорядоченных столбцов");
    else
        printf("Максимальный элемент матрицы - %d\n\n", max);

    printf("Исходная матрица: \n\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", arr[i][j]);
        }
        printf("\n\n");
    }
    for (int i = 0; i < m; i++)
    {
        free(arr[i]);
    }
    free(arr);
    system("pause");
    return 0;
}