#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// TODO: Метод вставки со сторожевым элементом (II)
int insertionSortMod();

int main()
{
    srand(time(NULL));

    int *newArr;
    int arrayLen = 100; // Начальная длина массива
    int st = 0; // Количество сравнений и перестановок

    FILE *file = fopen("statsMod.csv", "w");

    if (file == NULL)
    {
        printf("Ошибка создания файла :(");
        return 0;
    }

    while (arrayLen <= 10000)
    {
        for (int j = 0; j < 5; j++)
        {
            newArr = (int *)malloc((arrayLen + 1) * sizeof(int));

            for(int i = 1; i <= arrayLen; i++)
            {
                newArr[i] = rand() % 10;
            }
            st += insertionSortMod(newArr, arrayLen);
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
    printf("\nВсе прошло успешно!");
    return 0;
}

// Функция проводит модифицированную сортировку вставками
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
    return st;
}