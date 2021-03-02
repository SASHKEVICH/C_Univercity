#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Сортировка методом вставок

int insertionSort();

int main()
{
    srand(time(NULL));

    int *newArr;
    int arrayLen = 100; // Начальная длина массива
    int st = 0; // Количество сравнений и перестановок

    FILE *file = fopen("stats.csv", "w");

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

            for(int i = 0; i < arrayLen; i++)
            {
                newArr[i] = rand() % 10;
            }
            st += insertionSort(newArr, arrayLen);
        }
        st = st / 5;
        fprintf(file, "%d;", arrayLen);
        fprintf(file, "%d\n", st);

        if (arrayLen < 1000)
        {
            arrayLen += 100;
        } else if (arrayLen >= 1000)
        {
            arrayLen += 1000;
        }
    }
    fclose(file);
    return 0;
}

// Функция проводит сортировку вставками
int insertionSort(int *arr, int arrayLen)
{
    int sr = 0;
    int per = 0;
    int st = 0;
    for (int i = 1; i < arrayLen; i++)
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
    return st;
}