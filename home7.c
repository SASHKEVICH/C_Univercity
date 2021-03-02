#include <stdlib.h>
#include <stdio.h>

void printMatrix();
void workWithMatrix();

int main()
{
    // Нужно будет прописывать польный путь до файла вместе с его расширением
    char fileName[100] = "testFile.txt"; 

    printf("Оригинальная матрица: \n");

    printMatrix(fileName);

    printf("----------------------------------------");
    printf("\n");

    workWithMatrix(fileName);
    printf("Работу выполнил Бекренев Александр. Группа 420-4.");

    return 0;
}

// Вывод основной матрицы на экран
void printMatrix(char *name)
{
    FILE *file = fopen(name, "rt");
    int temp;

    if (file == NULL)
    {
        printf("Файл не найден :(");
        return ;
    }

    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < 4; i++)
    {   
        for (int j = 0; j < 4; j++)
        {
            fscanf(file, "%d", &temp);
            printf("%3d", temp);
        }
        printf("\n");
    }
    fclose(file);
}

void workWithMatrix(char *name)
{

    FILE *file = fopen(name, "rt");
    int temp;

    if (file == NULL)
    {
        printf("Файл не найден :(");
        return ;
    }

    // Непосредственно сам алгоритм
    for (int f = 0; f < 4; f++)
    {
        for (int k = 0; k < 4; k++)
        {
            printf("По индексу: %d %d\n", f, k);
            for (int i = 0; i < 4; i++)
            {   
                for (int j = 0; j < 4; j++)
                {
                    fscanf(file, "%d", &temp);
                    if (i != f && j != k)
                        printf("%3d", temp);
                }
                if (i != f)
                    printf("\n");
            }
            fseek(file, 0, SEEK_SET);
            printf("\n");
        }
    }
    fclose(file);
}
