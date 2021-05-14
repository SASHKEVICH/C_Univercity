#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// TODO: �������� BST-������ ������� ������� � ���� �� ����������. ������ �����.

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
    printf("���������� ��������� � ������: ");
    scanf("%d", &arrayLen);

    int* array = (int *)malloc(sizeof(int) * arrayLen);
    bstNode** root = (bstNode **)malloc(sizeof(bstNode*)); // BST-������

    createArray(array, arrayLen);
    printf("�������� ������������������: \n");
    printArray(array, arrayLen);
    printf("\n������ ����� ������: \n");
    createBst(root, array, arrayLen);
    directApproach(root);

    printf("�������� �������� ���������, 420-4.");

    return 0;
}

// �������� �������
void createArray(int* array, int arrayLen)
{
    for(int i = 0; i < arrayLen; i++)
    {
        array[i] = rand() % 30;
    }
}

// ����� ������� � �������
void printArray(int* array, int arrayLen)
{
    for(int i = 0; i < arrayLen; i++)
    {
        printf("%d ", array[i]);
    }
}

// �������� bst-������ ���������� �������
void createBst(bstNode** root, int* array, int arrayLen)
{

    for(int i = 0; i < arrayLen; i++)
    {
        insertBstNode(root, array[i]);
    }
}

// ������� � ����
void insertBstNode(bstNode** root, int key)
{
    if(*root == NULL) // ������
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
                if(!temp->right) // ������
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
                if(!temp->left) // ������
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


// ������� ����������� ������ �����
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