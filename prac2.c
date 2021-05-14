#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct Supply 
{
    char name[30];
    float price;
    float deadline;
} Supply;

Supply** readFile();
int numOfRows();
void printStructers();

int main()
{
    system("chcp 1251");

    FILE *file = fopen("testFilePrices.txt", "r");

    int rows = numOfRows(file);
    Supply **sup = readFile(file, rows);

    printStructers(sup, rows);

    printf("Работу с опозданием выполнил Бекренев Александр, 420-4 группа.");
    printf("Он старался все сделать красиво и вовсем разобраться, правда-правда :).");
    fclose(file);
    return 0;
}

// Читает строки из файла testFilePrices.txt и возвращает указтель на массив структур
Supply** readFile(FILE *file, int rows)
{
    Supply **sup; // Массив структур
    sup = (Supply **)malloc(sizeof(Supply *) * rows);

    for(int i = 0; i < rows; i++)
    {
        sup[i] = (Supply *)malloc(sizeof(Supply));    
    }

    if (file == NULL)
    {
        printf("Файл не найден :(");
        exit(1);
    } else
    {
        char buff[30];
        char temp[30];
        int count = 0;

        fseek(file, 0, SEEK_SET);

        for(int i = 0; i < rows; i++)
        {
            fgets(buff, sizeof(buff), file);
            char *rest = buff;
            char *token;

            // Выбираю строку с помощью strtok_r и записываю в структуру на нужные места
            while((token = strtok_r(rest, " ", &rest)))
            {   
                switch(count)
                {   
                    case 0: strcpy(temp, token);
                        strcpy(sup[i]->name, temp);
                        break;
                    case 1: sup[i]->price = strtof(token, NULL);
                        break;
                    case 2: sup[i]->deadline = strtof(token, NULL);
                        break;
                }
                count++;
                if (count >= 3)
                {
                    break;
                }
            }
            count = 0;
        }
    }
    return sup;
}

// Возвращает количество строк в файле
int numOfRows(FILE *file)
{
    int rows = 0;

    char buff[30];

    while(fgets(buff, sizeof(buff), file) != NULL)
    {
        rows++;
    }

    return rows;
}

// Выводит на экран только нужные строки
void printStructers(Supply **sup, int rows)
{  
    printf("Продукты, подлежащие скорой реализации:\n");
    for(int i = 0; i < rows; i++)
    {
        if(sup[i]->deadline <= 1)
        {
            printf("Имя - %s, срок реализации - %.1f\n", sup[i]->name, sup[i]->deadline);
        }
    }
    
    for(int i = 0; i < rows; i++)
    {
        free(sup[i]);
    }
    free(sup);
}
