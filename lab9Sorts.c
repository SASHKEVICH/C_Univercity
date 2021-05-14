#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// TODO: Метод вставки со сторожевым элементом (II)
void printArray();
int insertionSortMod();

int main()
{
    srand(time(NULL));

    int *newArr;
    int arrayLen = 10; // Начальная длина массива

    newArr = (int *)malloc((arrayLen + 1) * sizeof(int));

    newArr[0] = 0;
    for(int i = 1; i < arrayLen + 2; i++)
    {
        newArr[i] = rand() % 10;
    }
            
    printf("Неотсортированный массив:\n");
    printArray(newArr, arrayLen);
    insertionSortMod(newArr, arrayLen);
    printf("Отсортированный массив:\n");
    printArray(newArr, arrayLen);
        
    return 0;
}
// Функция выводит массив на экран консоли
void printArray(int *arr, int arrayLen)
{
    for(int i = 1; i < arrayLen + 1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Функция проводит сортировку вставками
int insertionSortMod(int *arr, int arrayLen)
{
    int sr = 0; // Сравнения
    int per = 0; // Перестановки
    int st = 0; // Сравнения + Перестановки
    for(int i = 2; i <= arrayLen; i++)
    {   
        arr[0] = arr[i];
        int key = arr[i];
        int j = i - 1;

        while (arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
            sr++;
            per++;
        }
        arr[j + 1] = key;
        per++;
    }
    st = per + sr;
    printf("%d per\n", per);
    printf("%d sr\n", sr);
    printf("%d st\n", st);
    return st;
}
