#include <stdlib.h>
#include <stdio.h>

void workWithMatrix();

int main()
{  
    char fileName[10] = "home7.txt";

    workWithMatrix(fileName);

    return 0;
}

void workWithMatrix(char *name)
{

    FILE *file = fopen(name, "r");
    int temp;

    int arr[4][4] = {{1, 2, 3, 4}, 
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};           
    for (int f = 0; f < 4; f++)
    {
        for (int k = 0; k < 4; k++)
        {
            printf("Индекс %d %d\n", f, k);
            for (int i = 0; i < 4; i++)
            {   
                for (int j = 0; j < 4; j++)
                {
                    fscanf(file, "%d", &temp);
                    if (i != f && j != k)
                        printf("%3d", temp);
                }
                if (i != f)
                    printf("\n");
            }
            fseek(file, 0, SEEK_SET);
            printf("\n");
        }
    }
}