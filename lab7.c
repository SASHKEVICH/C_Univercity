#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

typedef struct node // Определяю структуру NODE - "Звено"
{
    int expValue;
    int multipValue;
    struct node *next;

} listNode;

// Функция создает звено
listNode *createNode(int setExpValue, int setMultipValue)
{
    listNode *node = (listNode *)malloc(sizeof(listNode));

    node->expValue = setExpValue;
    node->multipValue = setMultipValue;
    node->next = NULL;

    return node;
}

// Функция ставит звено в конец
void append(listNode **list, int setExpValue, int setMultipValue)
{
    listNode *newElement = createNode(setExpValue, setMultipValue);

    listNode *tmp = *list;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = newElement;
}

/* Функция читает файл и работает с ним, представляя информацию в нем в виде
связного списка */
void readFileAndWorkWithNode(char *name, int x)
{
    int result = 0;
    int exp;
    int multi;
    FILE *file = fopen(name, "r");

    if (file == NULL)
    {
        printf("Файл не найден :(\n");
        system("PAUSE");
        return ;
    }

    fscanf(file, "%d", &exp);
    fscanf(file, "%d", &multi);
    listNode *list = createNode(exp, multi);

    while(!feof(file))
    {
        fscanf(file, "%d", &exp);
        fscanf(file, "%d", &multi);
        if (multi != 0)
        {
            append(&list, exp, multi);
        } else
        {
            continue;
        }
    }
    fclose(file);

    printf("Представление многочлена из файла = ");
    while(list)
    {
        if (list->multipValue < 0)
        {
            printf("- %dx^%d ", abs(list->multipValue), list->expValue);
        } else if (list->multipValue > 0)
        {
            printf("+ %dx^%d ", list->multipValue, list->expValue);
        }
        result += list->multipValue * powl(x, list->expValue);
        list = list->next;
    }
    printf("result = %d", result);
    printf("\n");
    printf("\n");

    if (result <= INT_MIN)
    {
        printf("Произошло переполнение :(\n");
        system("pause");
        return ;
    } else
    {
        printf("Результат умножения вашего x на этот многочлен - %d\n", result);
    }
    printf("\n");
}

int main()
{
    int x;
    char fileName[9] = "lab7.txt";

    printf("Введите число x: ");
    scanf("%d", &x);

    readFileAndWorkWithNode(fileName, x);
    printf("Работу выполнил Бекренев Александр, 420-4 группа.");
    return 0;
}