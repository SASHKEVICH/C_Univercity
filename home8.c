#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// TODO: Матрица смежности -> Матрица инцендентности

int volumeOfElements();
void createNewMatrix();
int readFileAndPrintMatrix();

int main()
{
    int volumeOfStrings = readFileAndPrintMatrix();
    int rebra = volumeOfElements();

    createNewMatrix(volumeOfStrings, rebra);
    return 0;
}

// Читает файл и возваращает количество строк матрицы смежности
int readFileAndPrintMatrix()
{
    int temp;
    int elements = 0;
    FILE *file = fopen("testFile.txt", "r");

    if(file == NULL)
    {
        printf("Файл не найден :(");
        return 0;
    }

    // Количество элементов в массиве
    while(fscanf(file, "%d", &temp) == 1)
    {
        elements++;
    }

    int volumeOfStrings = pow(elements, 0.5);

    fseek(file, 0, SEEK_SET);
    printf("Матрица смежности:\n");

    for(int i = 0; i < volumeOfStrings; i++)
    {
        for(int j = 0; j < volumeOfStrings; j++)
        {
            fscanf(file, "%d", &temp);
            printf("%3d", temp);
        }
        printf("\n");
    }

    fclose(file);
    return volumeOfStrings;
}


// Печать матрицы инцендентности
void createNewMatrix(int volumeOfStrings, int rebra)
{
    int temp;
    int temp_k = 0;
    int **newMatrix;
    FILE *file = fopen("testFile.txt", "r");
    if (file == NULL)
    {
        printf("Файл не найден :(");
        return ;
    }

    newMatrix = (int **)malloc(volumeOfStrings * sizeof(int*));
    for (int i = 0; i < rebra; i++)
    {
        newMatrix[i] = (int *)malloc(volumeOfStrings * sizeof(int));
    }

    fseek(file, 0, SEEK_SET);

    //Основная часть алгоритма
    for (int i = 0; i < volumeOfStrings; i++)
    {
        // Костыль, придуманный в полвторого ночи :)
        for (int k = 0; k < i; k++)
        {
            fscanf(file, "%d", &temp);
        }
        
        for (int j = i; j < volumeOfStrings; j++)
        {   
            fscanf(file, "%d", &temp);
            if (temp == 1)
            { 
                newMatrix[temp_k][i] = 1;
                newMatrix[temp_k][j] = 1;
                temp_k++;
            }
        }
    }
    fclose(file);

    printf("Матрица инцендентности: \n");
    for (int i = 0; i < rebra; i++)
    {
        for (int j = 0; j < volumeOfStrings; j++)
        {
            printf("%3d", newMatrix[i][j]);
        }
        printf("\n");
    }
    free(newMatrix);
}

// Подсчет количества единиц в матрице смежности, что равно количеству ребер в матр. инцендентности
int volumeOfElements()
{
    int count = 0;
    int temp;

    FILE *file = fopen("testFile.txt", "r");

    if(file == NULL)
    {
        printf("Файл не найден :(");
        return 0;
    }

    while(fscanf(file, "%d", &temp) == 1)
    {
        if(temp == 1)
        {
            count++;
        }
    }
    fclose(file);
    return count / 2;
}