#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// TODO: Создание BST-дерева методом вставки в лист не рекурсивно. Прямой обход.

typedef struct node
{
    struct node* left;
    struct node* right;
    int data;
} bstNode;

void createArray(int* array, int arrayLen);
void printArray(int* array, int arrayLen);
void insertBstNode(bstNode** root, int key);
void directApproach(bstNode** root);
void createBst(bstNode** root, int* array, int arrayLen);

int main()
{
    srand(time(NULL));
    system("chcp 1251");

    int arrayLen;
    printf("Количество элементов в дереве: ");
    scanf("%d", &arrayLen);

    int* array = (int *)malloc(sizeof(int) * arrayLen);
    bstNode** root = (bstNode **)malloc(sizeof(bstNode*)); // BST-дерево

    createArray(array, arrayLen);
    printf("Исходная последовательность: \n");
    printArray(array, arrayLen);
    printf("\nПрямой обход дерева: \n");
    createBst(root, array, arrayLen);
    directApproach(root);

    printf("Выполнил Бекренев Александр, 420-4.");

    return 0;
}

// Создание массива
void createArray(int* array, int arrayLen)
{
    for(int i = 0; i < arrayLen; i++)
    {
        array[i] = rand() % 30;
    }
}

// Вывод массива в консоль
void printArray(int* array, int arrayLen)
{
    for(int i = 0; i < arrayLen; i++)
    {
        printf("%d ", array[i]);
    }
}

// Заполняю bst-дерево элементами массива
void createBst(bstNode** root, int* array, int arrayLen)
{

    for(int i = 0; i < arrayLen; i++)
    {
        insertBstNode(root, array[i]);
    }
}

// Вставка в лист
void insertBstNode(bstNode** root, int key)
{
    if(*root == NULL) // Пустой
    {
        *root = (bstNode *)malloc(sizeof(bstNode));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->data = key;
        return;
    }
    else 
    {
        bstNode* temp = *root;
        while(temp != NULL)
        {
            if(key >= temp->data)
            {
                if(!temp->right) // Пустой
                {
                    temp->right = (bstNode *)malloc(sizeof(bstNode));
                    temp->right->left = NULL;
                    temp->right->right = NULL;
                    temp->right->data = key;
                    return;
                }
                else
                {
                    temp = temp->right;
                } 
            }
            else
            {
                if(!temp->left) // Пустой
                {
                    temp->left = (bstNode *)malloc(sizeof(bstNode));
                    temp->left->left = NULL;
                    temp->left->right = NULL;
                    temp->left->data = key;
                    return;
                }
                else 
                {
                    temp = temp->left;
                }
            }
        }
    }
}


// Функция выполняющая прямой обход
void directApproach(bstNode** root)
{
    bstNode* temp = *root;
    if(*root == NULL)
    {
        return;
    } 
    else 
    {
        printf("%d ", temp->data);
        directApproach(&temp->left);
        directApproach(&temp->right);
    }
}