#include <iostream>
#include <stack>

using namespace std;
 
int main()
{
    int n = 3;
    int s = 1;

    scanf("%d %d", &n, &s);
    int count = 1;
    int **matrix = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++)
    {
        *matrix = (int *)malloc(sizeof(int) * n);
    }

    stack<int> List;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int temp; 
            scanf("%d ", &temp);
            matrix[i][j] = temp;
        }
    }
    for(int j = 0;j < n;j++)
    {
        if(matrix[s][j] == 1){
            List.push(j);
        }
    }

    matrix[s][s] = 1;

    while(!List.empty())
    {
        int a = List.top();
        List.pop();

        if(matrix[a][a] != 1)
        {
            for(int j = 0;j < n;j++)
            {
                if(matrix[a][j] == 1)
                {
                    List.push(j);
                }
            }
            count++;
            matrix[a][a] = 1;
        }
    }
    printf("%d", count);
    return 0;
}