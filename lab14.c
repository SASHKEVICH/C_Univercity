#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
    TODO: Вставка в корень, операция удаления элемента из  BST-дерева.
    1.	Сделайте вывод элементов в порядке их добавления в дерево (сразу, когда получаете случайные значения).
    2.	Добавьте в вывод элементов дерева информацию о количестве узлов в поддереве 
    (например, выводите количество узлов в поддереве в скобках около каждого значения ключа) 
    – так можно будет проанализировать, как выглядит дерево или реализуйте вывод древовидной структуры.
    Не забывайте, что реализация ротации должна быть выполнена так, как показано в 10 лекции.
*/

typedef struct node 
{
    int data;
    int elements;
    struct node *right;
    struct node *left;
} bstNode;

void print2DUtil(bstNode *root, int space);
void print2D(bstNode **root);
void createArray(int* array, int arrayLen);
void printArray(int *array, int arrayLen);
void leftRotation(bstNode **root);
void rightRotation(bstNode **root);
void insertionInRoot(bstNode **root, int data);
void insertionInLeaf(bstNode **root, int data);
void createBSTInRoot(bstNode **root, int *array, int arrayLen);
void createBSTInLeaf(bstNode **root, int *array, int arrayLen);
void deletion(bstNode **root, int elementToDelete);
void partition(bstNode **root, int k);

int main()
{
    system("chcp 1251");
    srand(time(NULL));
    int length = 7; // Длина массива

    printf("Количество элементов в дереве: ");
    scanf("%d", &length);

    int *array = (int *)malloc(sizeof(int) * length);
    bstNode **inRoot = (bstNode **)malloc(sizeof(bstNode *));
    bstNode **inLeaf = (bstNode **)malloc(sizeof(bstNode *));
    *inRoot = NULL; // Иначе не работает. Почему-то корень дерева автоматически не пустой.
    *inLeaf = NULL;

    createArray(array, length);
    printf("Оригинальный массив:\n");
    printArray(array, length);

    createBSTInRoot(inRoot, array, length);
    printf("BST-Дерево со вставкой элементов в корень: \n");
    print2D(inRoot);

    createBSTInLeaf(inLeaf, array, length);
    printf("BST-Дерево со вставкой элементов в лист: \n");
    print2D(inLeaf);

    int elementToDelete = 11;
    printf("Какой элемент вы хотели бы удалить? ");
    scanf("%d", &elementToDelete);
    deletion(inRoot, elementToDelete);
    printf("Дерево с после удаления элемента '%d': \n", elementToDelete);
    print2D(inRoot);

    free(array);
    free(inLeaf);
    free(inRoot);
    
    printf("Работу выполнил Бекренев Александр. 420-4 группа.");
    return 0;
}

void print2DUtil(bstNode *root, int space)
{
    if(root == NULL) return;
  
    space += 7;
  
    print2DUtil(root->right, space);

    printf("\n");
    for (int i = 7; i < space; i++)
    {
        printf(" ");
    }
    printf("%d(%d)\n", root->data, root->elements);
  
    print2DUtil(root->left, space);
}

// Вывод BST-дерева в консоль 
void print2D(bstNode **root)
{
   print2DUtil((*root), 0);
}

// Создание массива
void createArray(int* array, int arrayLen)
{
    for(int i = 0; i < arrayLen; i++)
    {
        array[i] = rand() % 20;
    }
}

// Вывод массива в консоль
void printArray(int *array, int arrayLen)
{
    for(int i = 0; i < arrayLen; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Заполнение BST-дерева в корень
void createBSTInRoot(bstNode **root, int *array, int arrayLen)
{
    for(int i = 0; i < arrayLen; i++)
    {
        insertionInRoot(root, array[i]);
    }
}

// Заполнение BST-дерева в лист
void createBSTInLeaf(bstNode **root, int *array, int arrayLen)
{
    for(int i = 0; i < arrayLen; i++)
    {
        insertionInLeaf(root, array[i]);
    }
}

// Вставка в лист
void insertionInLeaf(bstNode **root, int data)
{
    if(*root == NULL) // Пустой
    {
        *root = (bstNode *)malloc(sizeof(bstNode));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->data = data;
        (*root)->elements = 1;
        return;
    }
    else 
    {
        (*root)->elements++;
        bstNode* temp = *root;
        while(temp != NULL)
        {
            if(data >= temp->data)
            {
                if(!temp->right) // Пустой
                {
                    temp->right = (bstNode *)malloc(sizeof(bstNode));
                    temp->right->left = NULL;
                    temp->right->right = NULL;
                    temp->right->data = data;
                    temp->right->elements = 1;
                    return;
                }
                else
                {
                    temp->right->elements++;
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
                    temp->left->data = data;
                    temp->left->elements = 1;
                    return;
                }
                else 
                {
                    temp->left->elements++;
                    temp = temp->left;
                }
            }
        }
    }
}

// Вставка в корень
void insertionInRoot(bstNode **root, int data)
{
    if(*root == NULL)
    {
        *root = (bstNode *)malloc(sizeof(bstNode));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->data = data;
        (*root)->elements = 1;
        return;
    }
    else 
    {
        (*root)->elements += 1;
        if(data >= (*root)->data)
        {
            insertionInRoot(&(*root)->right, data);
            leftRotation(root);
        }
        else
        {
            insertionInRoot(&(*root)->left, data);
            rightRotation(root);
        }
    }
}

// Операция разделения дерева
void partition(bstNode **root, int k)
{
    if(*root == NULL) return;
    int T = ((*root)->left == NULL) ? 0 : (*root)->left->elements;

    if(T > k)
    {
        partition(&(*root)->left, k);
        rightRotation(root);
    } 
    else if(T < k) 
    {
        partition(&(*root)->right, (k - T - 1));
        leftRotation(root);
    }
}

// Операция удаления элемента
void deletion(bstNode **root, int elementToDelete)
{
    if(*root == NULL) return;

    if((*root)->left)
    {
        if((*root)->left->data == elementToDelete)
        {
            bstNode *temp = *root;
            if(temp->left->elements == 1)
            {
                temp->left = NULL;
                return;
            }
        }
    }
    else if((*root)->right)
    {
        if((*root)->right->data == elementToDelete)
        {
            bstNode *temp = *root;
            if(temp->right->elements == 1)
            {
                temp->right = NULL;
                return;
            }
        }
    }

    if((*root)->data == elementToDelete)
    {
        bstNode *temp = *root;
        if(temp->elements == 2)
        {
            if(temp->left)
            {
                bstNode *leftSubRoot = temp->left;
                *root = leftSubRoot;
                temp = NULL;
            }
            else
            {
                bstNode *rightSubRoot = temp->right; 
                partition(&rightSubRoot, 0);
                *root = rightSubRoot;    
                temp = NULL;
            }
        }
        else 
        {
            if((temp->left) && (temp->right))
            {
                bstNode *rightSubRoot = temp->right;
                bstNode *leftSubRoot = temp->left;

                partition(&rightSubRoot, 0);
                rightSubRoot->left = leftSubRoot;
                *root = rightSubRoot;
                temp = NULL;
            }
            else if(temp->right)
            {
                bstNode *rightSubRoot = temp->right;
                partition(&rightSubRoot, 0);
                *root = rightSubRoot;
                temp = NULL;
            }
            else
            {
                bstNode *leftSubRoot = temp->left;
                *root = leftSubRoot;
                temp = NULL;
            }
        }
    }

    if((*root)->data >= elementToDelete)
    {
        deletion(&(*root)->left, elementToDelete);
    }
    else 
    {
        deletion(&(*root)->right, elementToDelete);
    }

}

// Ротация влево
void leftRotation(bstNode **root)
{
    bstNode *newRoot;
    int newElements = (*root)->elements;

    newRoot = (*root)->right;
    (*root)->right = newRoot->left;
    newRoot->left = *root;
    *root = newRoot;

    (*root)->elements = newElements;

    if(((*root)->left->left) || ((*root)->left->right))
    {
        // Если есть левая ветка у левой ветки
        if(((*root)->left->left) && (!(*root)->left->right))
        {
            (*root)->left->elements = 1 + (*root)->left->left->elements;
        } 
        // Если есть правая ветка у левой ветки
        else if((!(*root)->left->left) && ((*root)->left->right))
        {
            (*root)->left->elements = 1 + (*root)->left->right->elements;
        }
        // Если есть обе
        else
        {
            (*root)->left->elements = 1 + (*root)->left->right->elements + (*root)->left->left->elements;
        }
    }
    // Если нет никаких
    else 
    {
        (*root)->left->elements = 1;
    }
}

// Ротация вправо
void rightRotation(bstNode **root)
{
    bstNode *newRoot;
    int newElements = (*root)->elements;

    newRoot = (*root)->left;
    (*root)->left = newRoot->right;
    newRoot->right = *root;

    *root = newRoot;

    (*root)->elements = newElements;
    if(((*root)->right->left) || ((*root)->right->right))
    {
        // Если есть левая ветка у правой ветки
        if(((*root)->right->left) && (((*root)->right->right) == NULL))
        {
            (*root)->right->elements = 1 + (*root)->right->left->elements;
        } 
        // Если есть правая ветка у правой ветки
        else if((((*root)->right->left) == NULL) && ((*root)->right->right))
        {
            (*root)->right->elements = 1 + (*root)->right->right->elements;
        }
        // Если есть обе
        else
        {
            (*root)->right->elements = 1 + (*root)->right->right->elements + (*root)->right->left->elements;
        }
    }
    // Если нет никаких
    else 
    {
        (*root)->right->elements = 1;
    }
}
