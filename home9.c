#include <stdlib.h>
#include <stdio.h>

// TODO: Генерация перестановок с помощью вложенных циклов

void createArray(int *array, int length);
void printArray(int *array, int length);
void permutation(int *array, int length);
void shift(int *array, int length, int m);

int main()
{
    int length = 4;
    // printf("Длина массива: ");
    // scanf("%d", &length);
    // int *array = (int *)malloc(sizeof(int) * length);

    int array[4] = {1, 2, 3, 4};

    createArray(array, length);
    printf("Оригинальный массив:\n");
    printArray(array, length);

    printf("Тест:\n");
    permutation(array, length);
    // printArray(array, length);

    return 0;
}

// Заполнение массива элементами от 1 до n
void createArray(int *array, int length)
{
    for(int i = 0; i < length; i++)
    {
        array[i] = i + 1;
    }
}

void printArray(int *array, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void permutation(int *array, int length)
{
    int lastIndex = 0;
    int *tempArray = (int *)malloc(sizeof(int) * length);
    int temp;

    for(int i = 0; i < length; i++)
    {
        tempArray[i] = array[i];
    }

    while(lastIndex != 1)
    {
        printArray(array, length);
        lastIndex = length - 1;
        shift(array, length, lastIndex);
        while((array[lastIndex] == lastIndex) && (lastIndex > 0))
        {
            lastIndex--;
            shift(array, length, lastIndex);
            printArray(array, length);
        }
    }
}

// Алгоритм перестановки
void shift(int *array, int length, int m)
{
    int temp = array[m - 1];
    for(int n = length - 2; n >= 0; n--)
    {
        array[n + 1] = array[n];
    }
    array[0] = temp;
}