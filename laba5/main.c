#include <stdio.h>
#include <stdlib.h>

double** summatrix(double **m1, double **m2, int N) {
    double **temp;
    int i, j;

    temp = (double**)malloc(N * sizeof(double*));
    for (i = 0; i < N; i++) {
        temp[i] = (double*)malloc(N * sizeof(double));
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            temp[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return temp;
}

int main() {
    double **m1, **m2, **result;
    int N, i, j;
    char operation;

    printf("Введите размерность матриц (n): ");
    scanf("%d", &N);

    m1 = (double**)malloc(N * sizeof(double*));
    for (i = 0; i < N; i++) {
        m1[i] = (double*)malloc(N * sizeof(double));
    }

    m2 = (double**)malloc(N * sizeof(double*));
    for (i = 0; i < N; i++) {
        m2[i] = (double*)malloc(N * sizeof(double));
    }

    printf("Введите элементы первой матрицы:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("m1[%d][%d] = ", i, j);
            scanf("%lf", &m1[i][j]);
        }
    }

    printf("Введите элементы второй матрицы:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("m2[%d][%d] = ", i, j);
            scanf("%lf", &m2[i][j]);
        }
    }

    printf("Введите операцию (+, -, *): ");
    scanf(" %c", &operation);

    if (operation == '+') {
        result = summatrix(m1, m2, N);
    } else {
        printf("Неверная операция!\n");
        return 1;
    }

    printf("Результат:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < N; i++) {
        free(m1[i]);
        free(m2[i]);
        free(result[i]);
    }
    free(m1);
    free(m2);
    free(result);

    return 0;
}