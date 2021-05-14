#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Итеративная функция
float iterFunc(int i)
{
    float sum;
    float elem1 = 1.5;
    float elem2 = 0;
    float elem3 = 0;

    for(int j = 4; j <= i; j++)
    {
        sum = ((j - 1) / (pow(j, 2) + 1)) * elem1;
        sum = sum - elem2 + elem3;
        elem3 = elem2;
        elem2 = elem1;
        elem1 = sum;
    }
    return sum;
}

// Рекурсивная функция
float rekFunc(int i)
{
    if(i <= 2)
    {
        return 0;
    } else if(i == 3)
    {
        return 1.5;
    } else {
        return ((i - 1) / (pow(i, 2) + 1)) * rekFunc(i - 1) - rekFunc(i - 2) + rekFunc(i - 3);
    }
}

int main()
{
    int i;
    printf("Введите i-номер последнего элемента, который больше 3: ");
    scanf("%d", &i);

    if(i <= 3)
    {
        printf("Введи положительное число, сука.");
        exit(0);
    }
    
    float sumRek = rekFunc(i);
    float sumIter = iterFunc(i);
    
    printf("Результат рекурсивной функции - %f\n", sumRek);
    printf("Результат итеративной функции - %f\n", sumIter);
    printf("Работу выполнил Бекренев Александр, 420-4 группа.");
    return 0;
}