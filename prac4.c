#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double firstFunction(double x);
double secondFunction(double x);
double thirdFunction(double x);
double firstDerivative(double (*function)(double), double x);
double secondDerivative(double (*function)(double), double x);
double tangent(double (*function)(double), double root);
double findingRoot(double (*function)(double), double ( *rootList )[2], int i);
void printList(double *rootSt, int i);

int main()
{
    system("chcp 1251");

    double *rootSt1; // Массив корней первой функции
    double *rootSt2; // Массив корней второй функции
    double *rootSt3; // Массив корней третьей функции
    double root;

    rootSt1 = (double *)malloc(sizeof(double) * 4);
    rootSt2 = (double *)malloc(sizeof(double) * 1);
    rootSt3 = (double *)malloc(sizeof(double) * 8);

    double rootList1[4][2] = {{-2.2, -1.8}, {-1.2, -0.8}, {0.8, 1.2}, {2.2, 2.6}}; // Диапазон, где находятся корни
    double rootList2[1][2] = {{0.5, 1.2}}; 
    double rootList3[8][2] = {{-8.8, -8.4}, {-7.2, -6.8}, {-5.6, -5.3},{-4.1, -3.8},
    {-2.5, -2}, {-1, -0.6}, {1, 1.2}, {1.5, 1.8}}; 

    // Корни первой функции
    for(int i = 0; i < 4; i++)
    {
        rootSt1[i] = findingRoot(firstFunction, rootList1, i);
    }

    // Корни второй функции
    for(int i = 0; i < 1; i++)
    {
        rootSt2[i] = findingRoot(secondFunction, rootList2, i);
    }

    // Корни третьей функции
    for(int i = 0; i < 8; i++)
    {
        rootSt3[i] = findingRoot(thirdFunction, rootList3, i);
    }

    printf("Первая функция - x^4 - 0.48 * x^3 - 5.792 * x^2 + 0.486 * x + 4.792\n");
    printf("Корни первой функции:\n");
    printf("$-------------------------------------$\n");
    printList(rootSt1, 4);
    printf("$-------------------------------------$\n");
    printf("Вторая функция - 0.1 * sin(x) + x^3 - 1\n");
    printf("Корни второй функции:\n");
    printf("$-------------------------------------$\n");
    printList(rootSt2, 1);
    printf("$-------------------------------------$\n");
    printf("Третья функция - 0.1 * e^x - sin^2(x) + 0.5\n");
    printf("Корни третьей функции:\n");
    printf("$-------------------------------------$\n");
    printList(rootSt3, 8);
    printf("$-------------------------------------$\n");

    free(rootSt1);
    free(rootSt2);
    free(rootSt3);

    printf("Работу выполнили Бекренев Александр, Фролов Дмитрий, Подковырин Иван");
    system("PAUSE");


    
    return 0;
}

// Вычисляется значение функции в точке
double firstFunction(double x)
{
    double functionResult = powl(x, 4) - (0.48 * powl(x, 3)) - (5.792 * powl(x, 2)) + (0.486 * x) + 4.792;

    return functionResult;
}

double secondFunction(double x)
{
    double functionResult = 0.1 * sinl(x) + powl(x, 3) - 1;

    return functionResult;
}

double thirdFunction(double x)
{
    double functionResult = 0.1 * expl(x) - powl(sinl(x), 2) + 0.5;

    return functionResult;
}

// Вычисляется приближенное значение первой производной в точке
double firstDerivative(double (*function)(double), double x)
{
    float dx = 0.001; 
    double firstDerivativeResult = (function(x + dx) - function(x - dx)) / (2 * dx);

    return firstDerivativeResult;
}

// Вычисляется приближенное значение второй производной в точке
double secondDerivative(double (*function)(double), double x)
{
    float dx = 0.001;
    float h = dx * dx; // Квадрат dx
    double secondDerivativeResult = (function(x + dx) - 2 * function(x) + function(x + dx)) / h;

    return secondDerivativeResult;
}

double tangent(double (*function)(double), double root)
{
    float eps = 0.0001;
    while(fabs(function(root)) > eps)
    {
        root = root - (function(root) / firstDerivative(function, root));
    }

    return root;
}

void printList(double *rootSt, int i)
{
    for(int j = 0; j < i; j++)
    {
        printf("\tRoot = %lf\n", rootSt[j]);
        printf("\t-------------------------------\n");
    }
}

double findingRoot(double (*function)(double), double (*rootList)[2], int i)
{
    double root;
    double temp1 = firstDerivative(function, rootList[i][0]);
    double temp2 = firstDerivative(function, rootList[i][1]);
    double temp3 = secondDerivative(function, rootList[i][0]);
    double temp4 = secondDerivative(function, rootList[i][1]);

    if ((temp1 / temp2) > 0 && (temp3 / temp4) > 0) // Проверка производных на постоянство знаков
    {
        root = tangent(function, rootList[i][0]);
    }

    return root;
}