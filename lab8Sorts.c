#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Сортировка методом вставок
void printArray();
int insertionSort();

int main()
{
    srand(time(NULL));

    int *newArr;
    int arrayLen = 100; // Начальная длина массива

    newArr = (int *)malloc(arrayLen * sizeof(int));

    for(int i = 0; i < arrayLen; i++)
    {
        newArr[i] = rand() % 10;
    }
            
    printf("Неотсортированный массив:\n");
    printArray(newArr, arrayLen);
    insertionSort(newArr, arrayLen);
    printf("Отсортированный массив:\n");
    printArray(newArr, arrayLen);
        
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
// Функция проводит сортировку вставками
int insertionSort(int *arr, int arrayLen)
{
    int sr = 0;
    int per = 0;
    int st = 0;
    for(int i = 1; i < arrayLen; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
            sr += 2;
            per++;
        }
        arr[j + 1] = key;
        per++;
    }
    st = per + sr;
    printf("%d per\n", per);
    printf("\n%d sr\n", sr);
    printf("\n%d st\n", st);
    return st;
}
