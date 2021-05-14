#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// TODO: Восходящая сортировка слиянием. Метод слияния абстрактный обменный.

int* createRandomArray(int arrayLen);
void printArray(int* array, int arrayLen);
void mergeSort(int *array, int *tempArray, int j, int step, int arrayLen);
void mergeSortUp(int* array, int* tempArray, int arrayLen);

int main()
{
    system("chcp 1251");
    srand(time(NULL));

    int arrayLen = 100;

    int* array = createRandomArray(arrayLen); // Оригинальный массив
    int* tempArray = (int *)malloc(sizeof(int) * arrayLen); // Временный массив
    printf("Оригинальный массив:\n");
    printArray(array, arrayLen);

    mergeSortUp(array, tempArray, arrayLen);

    printf("Отсортированный массив:\n");
    printArray(array, arrayLen);

    free(array);

    return 0;
}

int* createRandomArray(int arrayLen)
{
    int* array;

    array = (int *)malloc(sizeof(int) * arrayLen);

    for(int i = 0; i < arrayLen; i++)
    {
        array[i] = rand() % 50;
    }

    return array;
}

void printArray(int* array, int arrayLen)
{
    for(int i = 0; i < arrayLen; i++)
    {
        printf("%3d", array[i]);
    }
    printf("\n");
}

void mergeSortUp(int* array, int* tempArray, int arrayLen)
{
    for(int step = 1; step < arrayLen; step *= 2) // step - шаг рассматриваемых подмассивов
    {
        for(int j = 0; j < arrayLen - step; j = j + (2 * step)) // j - переменная для вычисления начала и конца подмассива
        {
            if((j + (2 * step) - 1) < arrayLen)
            {
                mergeSort(array, tempArray, j, step, j + (2 * step) - 1);
            } else
            {
                mergeSort(array, tempArray, j, step, arrayLen - 1);
            }
        }
    }
}

void mergeSort(int *array, int *tempArray, int j, int step, int arrayLen)
{
    int i = 0;
    int k = 0;
    int i1 = j;
    int i2 = arrayLen;
    int tempIndex = j;

    for(i = j; i < j + step; i++)
    {
        tempArray[i] = array[i];
    }

    for(i = j + step, k = arrayLen; i < arrayLen + 1 || k > j + step; i++, k--)
    {
        tempArray[i] = array[k];
    }

    while(i1 <= i2)
    {
        if(tempArray[i1] <= tempArray[i2])
        {
            array[tempIndex] = tempArray[i1];
            i1++;
        } else {
            array[tempIndex] = tempArray[i2];
            i2--;
        }
        tempIndex++;
    }
}
