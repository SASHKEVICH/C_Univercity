#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    srand(time(NULL));
    int x[5];
    for (int i = 0; i < 5; i++) {
        x[i] = rand()%100;
        printf("%5d\n", x[i]);
    }

    return 0;
}