#include <stdlib.h>
#include <stdio.h>

// TODO: ��������� ������������ � ������� ��������� ������

void createArray(int *array, int length);
void printArray(int *array, int length);
int permutation(int *array, int length);
void shift(int *array, int *tempArray, int length, int lastIndex);

int main()
{
    int length;
    printf("����� �������: ");
    scanf("%d", &length);
    int *array = (int *)calloc(sizeof(int), length + 1);


    printf("������� ��������� �� 1 �� n (1) ��� ������������ (2)?\n");
    printf("������� 1 ��� 2:\n");
    int choice;
    scanf("%d", &choice);
    if(choice == 1)
    {
        createArray(array, length);    
    }
    else 
    {
        printf("���������: \n");
        for(int i = 1; i < length + 1; i++)
        {   
            int temp;
            scanf("%d", &temp);
            array[i] = temp;
        }
    }

    printf("--------------------\n");
    printf("������������:\n");

    int per = permutation(array, length);
    printf("������������ - %d", per);
    free(array);

    return 0;
}

// ���������� ������� ���������� �� 1 �� n
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

// �������� ������������
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