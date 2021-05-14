#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// TODO: Сортировка подсчетом

void printArray();
int countingSort();
int findMaxElement();

int main()
{
    srand(time(NULL));
    int *newArr;
    int arrayLen = 100; // Начальная длина массива
    int count = 0; // Сравнения 

    newArr = (int *)malloc(arrayLen * sizeof(int));

    for(int i = 0; i < arrayLen; i++)
    {
        newArr[i] = rand() % 100;
    }
            
    printf("Неотсортированный массив:\n");
    printArray(newArr, arrayLen);
    int countings = countingSort(newArr, arrayLen, &count);
    printf("Отсортированный массив:\n");
    printArray(newArr, arrayLen);
    printf("Количество сравнений - %d", countings);


    free(newArr);
    return 0;
}
// Функция выводит массив на экран консоли
void printArray(int *arr, int arrayLen)
{
    for(int i = 0; i < arrayLen; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
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



