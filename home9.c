#include <stdlib.h>
#include <stdio.h>

// TODO: Генерация перестановок с помощью вложенных циклов

void createArray(int *array, int length);
void printArray(int *array, int length);
int permutation(int *array, int length);
void shift(int *array, int *tempArray, int length, int lastIndex);

int main()
{
    int length;
    printf("Длина массива: ");
    scanf("%d", &length);
    int *array = (int *)calloc(sizeof(int), length + 1);


    printf("Создать множество от 0 до n (1) или произвольное (2)?\n");
    printf("Введите 1 или 2:\n");
    int choice;
    scanf("%d", &choice);
    if(choice == 1)
    {
        createArray(array, length);    
    }
    else 
    {
        printf("Множество: \n");
        for(int i = 1; i < length + 1; i++)
        {   
            int temp;
            scanf("%d", &temp);
            array[i] = temp;
        }
    }

    printf("--------------------\n");
    printf("Перестановки:\n");

    int per = permutation(array, length);
    printf("Перестановок - %d", per);
    free(array);

    return 0;
}

// Заполнение массива элементами от 1 до n
void createArray(int *array, int length)
{
    for(int i = 1; i < length + 1; i++)
    {
        array[i] = i;
    }
}

void printArray(int *array, int length)
{
    for(int i = 1; i < length + 1; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int permutation(int *array, int length)
{
    int lastIndex;
    int per = 0;
    int *tempArray = (int *)calloc(sizeof(int), length + 1);
    createArray(tempArray, length);

    while(lastIndex != 1)
    {
        lastIndex = length;
        printArray(array, length);
        shift(array, tempArray, length, lastIndex);
        while((tempArray[lastIndex] == lastIndex) && (lastIndex > 1))
        {
            lastIndex--;
            shift(array, tempArray, length, lastIndex);
        }
        per++;
    }
    free(tempArray);
    return per;
}

// Алгоритм перестановки
void shift(int *array, int *tempArray, int length, int lastIndex)
{

    int temp1 = tempArray[lastIndex];
    int temp2 = array[lastIndex];

    for(int n = lastIndex - 1; n > 0; n--)
    {
        tempArray[n + 1] = tempArray[n];
        array[n + 1] = array[n];
    }
    tempArray[1] = temp1;
    array[1] = temp2;
}