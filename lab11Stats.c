#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// TODO: Восходящая сортировка слиянием. Метод слияния абстрактный обменный.

void mergeSort(int *array, int *tempArray, int j, int step, int arrayLen, int *swaps, int *count);
void mergeSortUp(int* array, int* tempArray, int arrayLen, int* swaps, int* count);

int main()
{
    system("chcp 1251");
    srand(time(NULL));

    int *newArr;
    int *newTempArray;
    int arrayLen = 100; // Начальная длина массива
    int count = 0; // Количество сравнений
    int swaps = 0; // Количество перестановок
    int swapsAndCount = 0;

    FILE *file = fopen("statsMerge.csv", "w");

    if (file == NULL)
    {
        printf("Ошибка создания файла :(");
        return 0;
    }

    while (arrayLen <= 10000)
    {
        newArr = (int *)malloc(arrayLen * sizeof(int));
        newTempArray = (int *)malloc(sizeof(int) * arrayLen);

        for(int i = 0; i < arrayLen; i++)
        {
            newArr[i] = rand() % 100;
        }
        mergeSortUp(newArr, newTempArray, arrayLen, &swaps, &count);
        swapsAndCount = swaps + count;

        fprintf(file, "%d;", arrayLen);
        fprintf(file, "%d\n", swapsAndCount);

        if (arrayLen < 1000)
        {
            arrayLen += 100;
        } else if (arrayLen >= 1000)
        {
            arrayLen += 1000;
        }
        swaps = 0;
        count = 0;
        swapsAndCount = 0;
    }
    fclose(file);
    free(newArr);
    free(newTempArray);

    return 0;
}

// Восходящая сортировка слиянием
void mergeSortUp(int* array, int* tempArray, int arrayLen, int* swaps, int* count)
{
    for(int step = 1; step < arrayLen; step *= 2) // step - шаг рассматриваемых подмассивов
    {
        for(int j = 0; j <= arrayLen - step; j = j + (2 * step)) // j - переменная для вычисления начала и конца подмассива
        {
            if(j + (2 * step) - 1 < arrayLen)
            {
                mergeSort(array, tempArray, j, step, j + (2 * step) - 1, swaps, count);
            } else
            {
                mergeSort(array, tempArray, j, step, arrayLen - 1, swaps, count);
            }
        }
    }
}

// Метод абстрактного слияния
void mergeSort(int *array, int *tempArray, int j, int step, int arrayLen, int *swaps, int *count)
{
    int i, k;
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
        (*count)++;
        if(tempArray[i1] <= tempArray[i2])
        {
            array[tempIndex] = tempArray[i1];
            i1++;
            (*count)++;
            (*swaps)++;
        } else {
            array[tempIndex] = tempArray[i2];
            i2--;
            (*count)++;
            (*swaps)++;
        }
        tempIndex++;
    }
}

