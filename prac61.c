#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodeList
{
    int val;
    struct nodeList *next;
    
}nodeList;

// Функция создает звено
nodeList *createNode(int val)
{
    nodeList *node = (nodeList *)malloc(sizeof(nodeList));

    node->val = val;
    node->next = NULL;

    return node;
}

// Функция ставит звено в конец
void append(nodeList **list, int val)
{
    nodeList *newElement = createNode(val);

    nodeList *tmp = *list;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = newElement;
}

void pop(nodeList **list)
{
    nodeList *p = *list;
    if (!p)
    {
        return;
    }

    list = &(p->next);
    free(p);
}

int top(nodeList **list)
{
    nodeList *p = *list;
    if (!p)
    {
        return -1;
    }
    else 
    {
        return p->val;
    }
}

int main()
{
    int n = 3;
    int s = 1;
    int count = 1;
    int matrix[3][3] = {{0, 1, 0}, // Матрица смежности
                        {1, 0, 0},
                        {0, 0, 0}};

    nodeList **List = (nodeList **)malloc(sizeof(nodeList*));

    for(int j = 0; j < n; j++)
    {
        if(matrix[s-1][j] == 1)
        {
            append(List, j);
        }
    }

    matrix[s][s] = 1;
    while(!List)
    {
        int topOfList = top(List);
        pop(List);

        if(matrix[topOfList][topOfList] != 1)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[topOfList][j] == 1)
                {
                    append(List, j);
                }
            }
            count++;
            matrix[topOfList][topOfList] = 1;
        }
    }
    printf("%d", count);
    return 0;
}