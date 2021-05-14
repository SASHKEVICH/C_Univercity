#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// TODO: Сортировка подсчетом
int countingSort();
int findMaxElement();

int main()
{
    srand(time(NULL));

    int *newArr;
    int arrayLen = 100; // Начальная длина массива
    int count = 0; // Количество сравнений
    int countings = 0;

    FILE *file = fopen("statsCounting.csv", "w");

    if (file == NULL)
    {
        printf("Ошибка создания файла :(");
        return 0;
    }

    while (arrayLen <= 10000)
    {
        for (int j = 0; j < 5; j++)
        {
            newArr = (int *)malloc(arrayLen * sizeof(int));

            for(int i = 1; i <= arrayLen; i++)
            {
                newArr[i] = rand() % 100;
            }
            countings += countingSort(newArr, arrayLen, &count);
            count = 0;
        }
        countings = countings / 5;
        fprintf(file, "%d;", arrayLen);
        fprintf(file, "%d\n", countings);

        if (arrayLen < 1000)
        {
            arrayLen += 100;
        } else if (arrayLen >= 1000)
        {
            arrayLen += 1000;
        }
    }
    fclose(file);
    printf("Все прошло успешно!");
    return 0;
}

// Функция проводит сортировку подсчетом
int countingSort(int *arr, int arrayLen, int *count)
{
    int *countingList; // Подмассив с количеством уникальных элементов в основном массиве
    int maxElement = findMaxElement(arr, arrayLen, count);

    countingList = (int *)calloc(maxElement, sizeof(int));

    // Количество уникальных элементов в основном массиве
    for (int i = 0; i < arrayLen; i++) 
    {
 		countingList[arr[i]]++;
        (*count)++;
 	}
    
    int position = 0;

 	for (int i = 0; i < maxElement + 1; i++)
    {
 		for (int j = 0; j < countingList[i]; j++) 
        {
 			arr[position++] = i;
            (*count)++;
 		}
 	}
    free(countingList);

    return *count;
}

// Поиск максимального элемента в неотсортированном массиве
int findMaxElement(int *arr, int arrayLen, int *count)
{
    int maxElement = -1;

    for(int i = 0; i < arrayLen; i++)
    {
        if(arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
        (*count)++;
    }
    return maxElement;
}