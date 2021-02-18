#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int **arr;
    int n, res;
    int down_half, sum = 0;
    srand(time(NULL));

    printf("Введите размерность матрицы: ");
    res = scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }

    if (n % 2)
    {
        down_half = n / 2;
    }
    else
    {
        down_half = n / 2 - 1;
    }

    for (int i = down_half + 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", arr[i][j]);
        }
        printf("\n\n");
    }
    printf("\nСумма элементов, лежащих в нижней половине матрицы = %d\n", sum);
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}