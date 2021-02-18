#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])

{

  int A[5][5] = {16, 19, 20, 17, 5,
                 22, 9, 18, 3, 3,
                 8, 8, 21, 24, 1,
                 15, 16, 14, 10, 3,
                 8, 12, 17, 22, 22};

  int i, j, n = 5, p;

  int S[5] = {0, 0, 0, 0, 0};

  p = 0;

  for (i = 0; i < n; i++)
  {

    for (j = 0; j < n; j++)
      S[i] += A[j][i];

    if (S[p] >= S[i])
      p = i;
  }

  for (i = 0; i < n; i++)
    printf("%d ", A[i][p]);

  printf("\n");

  system("PAUSE");

  return 0;
}