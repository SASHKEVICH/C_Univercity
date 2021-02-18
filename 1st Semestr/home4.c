#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system("chcp 1251");
    int **M;
    int x, N = 0;

    printf("Введите количество строк и столбцов матрицы: ");
    scanf("%d", &N);

    M = (int **)malloc(N * sizeof(int *));
    for (int k = 0; k < N; k++)
    {
        M[k] = (int *)malloc(N * sizeof(int));
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i % 2 == 1)
            {
                M[i][j] = x;
                x--;
            }
            else
            {
                x++;
                M[i][j] = x;
            }
        }
        x += N;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j > -1; j--)
        {
            printf("%4d", M[j][i]);
        }
        printf("\n\n");
    }
    for (int i = 0; i < N; i++)
    {
        free(M[i]);
    }
    free(M);

    printf("Работу выполнил Бекренев Александр, 420-4 группа.");
    return 0;
}