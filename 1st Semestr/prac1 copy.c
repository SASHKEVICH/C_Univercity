#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

void createFile();
void readAndWriteNewFile();
void workWithFile();

int main()
{
    char nameOfFile[15];
    printf("Введите название файла с расширением .txt:\n");
    scanf("%s", &nameOfFile);

    createFile(nameOfFile);
    readAndWriteNewFile(nameOfFile);
    workWithFile();

    return 0;
}

void createFile(char *name)
{
    int n;
    int m;

    srand(time(NULL));

    FILE *f = fopen(name, "wb");

    if (f == NULL) {
        printf("Ошибка создания файла :(");
        system("pause");
        return ;
    }

    printf("Введите размерность матрицы n на m:\n");
    int resultOfScan = scanf("%d %d", &n, &m);

    if (resultOfScan != 2) 
    {
        printf("Вы ввели неверные данные :(");
        system("PAUSE");
    }
    fwrite(&n, sizeof(int), 1, f);
    fwrite(&m, sizeof(int), 1, f);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int elementOfMatrix = rand()%10;
            fwrite(&elementOfMatrix, sizeof(int), 1, f);
        }
    }
    fclose(f);
}

void readAndWriteNewFile(char *name)
{
    int n;
    int m;
    int k;
    int temp = 0; // Для временного сравнения числа в файле и K
    int tempElement;
    int count = 0;


    FILE *f = fopen(name, "rb");

    if (f == NULL) {
        printf("Файл не найден :(");
        system("pause");
        return ;
    }

    FILE *newFile = fopen("reorganizedFile.txt", "wb");

    if (newFile == NULL) {
        printf("Ошибка создания файла :(");
        system("pause");
        return ;
    }

    printf("Введите число k:\n");
    scanf("%d", &k);

    // Чтение n и m из файла
    fseek(f, 0, SEEK_SET);
    fread(&n, sizeof(int), 1, f);
    fseek(f, 4, SEEK_SET);
    fread(&m, sizeof(int), 1, f);
    fwrite(&n, sizeof(int), 1, newFile);
    fwrite(&m, sizeof(int), 1, newFile);
    
    for (int i = 0; i < n; i++)
    {
        int positionOfElement = 2 * sizeof(int) + i * sizeof(int);
        fseek(f, positionOfElement, SEEK_SET);
        fread(&temp, sizeof(int), 1, f);

        if (temp > k)
        {
            for (int j = 0; j < m; j++)
            {
                fseek(f, positionOfElement + j, SEEK_SET);
                fread(&tempElement, sizeof(int), 1, f);
                fwrite(&tempElement, sizeof(int), 1, newFile);
            }
            count++;
        }
    }

    printf("\nВ новый файл записалось %d строк.\n", count);

    // Переписываю значение n-строк для нового файла
    fseek(newFile, 0, SEEK_SET);
    fwrite(&count, sizeof(int), 1, newFile); 
    
    fclose(f);
    fclose(newFile);
}

void workWithFile()
{
    FILE *f = fopen("reorganizedMatrix.txt", "rb");
    int max = INT_MIN;
    int n;
    int m;
    int tempElement = 0;
    int maxElementIndexN;
    int maxElementIndexM;


    // Чтение n и m из нового файла
    fseek(f, 0, SEEK_SET);
    fread(&n, sizeof(int), 1, f);
    printf("%d строк\n", n);
    fseek(f, 4, SEEK_SET);
    fread(&m, sizeof(int), 1, f);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int positionOfElement = 2 * sizeof(int) + i * sizeof(int) + j;
            fseek(f, positionOfElement, SEEK_SET);
            fread(&tempElement, sizeof(int), 1, f);
            
            if (tempElement >= max)
            {
                max = tempElement;
                maxElementIndexN = i;
                maxElementIndexM = j;
            }
        }
    }
    printf("\nМаксимальное значение матрицы - %d под индексом %d %d.\n", max, maxElementIndexN, maxElementIndexM);
    printf("Работу выполнил Бекренев Александр. Группа 420-4.");
    fclose(f);
} 