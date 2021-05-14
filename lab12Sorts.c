#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// TODO: LSD-сортировка массива строк. Строки состоят из цифр.

char* createString(int length);
void createMassive(char** massiveOfStrings, int amountOfStrings, int lengthOfString);
void printMassiveOfStr(char** massiveOfStrings, int amountOfStrings);
void radixSort(char** massiveOfStrings, int amountOfStrings, int lengthOfString);

int main()
{
    system("chcp 1251");
    srand(time(NULL));

    int lengthOfString;
    int amountOfStrings;
    char** massiveOfStrings = (char **)malloc(sizeof(char *) * amountOfStrings);

    printf("Количество символов в строке: ");
    scanf("%d", &lengthOfString);
    printf("Количество строк: ");
    scanf("%d", &amountOfStrings);

    createMassive(massiveOfStrings, amountOfStrings, lengthOfString);
    printf("Массив строк:\n");
    printMassiveOfStr(massiveOfStrings, amountOfStrings);
    radixSort(massiveOfStrings, amountOfStrings, lengthOfString);
    printf("------------------------\n");
    printf("Отсортированный массив строк:\n");
    printMassiveOfStr(massiveOfStrings, amountOfStrings);

    system("pause");

    return 0;
}


// Рандомная строка из цифр
char* createString(int length)
{
    char charset[] = "0123456789";
    char* randomString;

    if(length > 0)
    {
        randomString = (char *)malloc(sizeof(char) * length);

        if (randomString) 
        {            
            for (int i = 0; i < length; i++) 
            {            
                int key = rand() % 10;
                randomString[i] = charset[key];
            }

            randomString[length] = '\0';
        }
    }

    return randomString;
}

// Массив строк
void createMassive(char** massiveOfStrings, int amountOfStrings, int lengthOfString)
{
    for(int word = 0; word < amountOfStrings; word++)
    {
        char* string = createString(lengthOfString);
        massiveOfStrings[word] = string;
    }
}

// Вывод массива строк в консоль
void printMassiveOfStr(char** massiveOfStrings, int amountOfStrings)
{
    for(int i = 0; i < amountOfStrings; i++)
    {
        printf("%s \n", massiveOfStrings[i]);
    }
}

// Функция проводит сортировку подсчетом
void countingSort(int *arr, int arrayLen)
{
    int *countingList; // Подмассив с количеством уникальных элементов в основном массиве
    int position = 0;

    countingList = (int *)calloc(arrayLen, sizeof(int));

    // Количество уникальных элементов в основном массиве
    for (int i = 0; i < arrayLen; i++) 
    {
 		countingList[arr[i]]++;
 	}

 	for (int i = 0; i < arrayLen + 1; i++)
    {
 		for (int j = 0; j < countingList[i]; j++) 
        {
 			arr[position++] = i;
 		}
 	}
    free(countingList);

}

// LSD-сортировка
void radixSort(char** massiveOfStrings, int amountOfStrings, int lengthOfString)
{
    int *countingList1; // Подмассив с количеством уникальных элементов в основном массиве
    int *countingList2;
    char **tempMassive;

    for(int n = lengthOfString - 1; n >= 0; n--)
    {
        countingList1 = (int *)calloc(10, sizeof(int));
        countingList2 = (int *)calloc(10, sizeof(int));
        tempMassive = (char **)malloc(sizeof(char *) * amountOfStrings);

        // Подсчет количества уникальных элементов у n-го разряда каждой строки
        for(int word = 0; word < amountOfStrings; word++)
        {
            countingList1[massiveOfStrings[word][n] - 48]++;
        }
        countingList2[0] = countingList1[0];
        
        // Копирование первого массива подсчета во второй по специальному алгоритму
        for(int i = 1; i < 10; i++)
        {
            countingList2[i] = countingList2[i - 1] + countingList1[i];
        }
        
        for(int word = amountOfStrings - 1; word >= 0; word--) 
        {
            int symbol = massiveOfStrings[word][n] - 48;
            tempMassive[countingList2[symbol] - 1] = massiveOfStrings[word];
            countingList2[symbol]--;
        }

        for(int i = 0; i < amountOfStrings; i++)
        {
            massiveOfStrings[i] = tempMassive[i];
        }
        free(countingList1);
        free(countingList2);
        free(tempMassive);
    }
}
