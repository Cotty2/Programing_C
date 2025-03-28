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

double** submatrix(double **m1, double **m2, int N) {  
    double **temp;
    int i, j;

    temp = (double**)malloc(N * sizeof(double*));
    for (i = 0; i < N; i++) {
        temp[i] = (double*)malloc(N * sizeof(double));
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            temp[i][j] = m1[i][j] - m2[i][j];  
        }
    }

    return temp;
}
double** multmatrix(double **m1, double **m2, int N) {
    double **temp;
    int i, j, k;

    temp = (double**)malloc(N * sizeof(double*));
    for (i = 0; i < N; i++) {
        temp[i] = (double*)malloc(N * sizeof(double));
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                temp[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return temp;
}
int main() {
    double **m1, **m2, **result;
    int N, i, j;
    char operation;

    printf("vvedite matrisu (n): ");
    scanf("%d", &N);

    m1 = (double**)malloc(N * sizeof(double*));
    for (i = 0; i < N; i++) {
        m1[i] = (double*)malloc(N * sizeof(double));
    }

    m2 = (double**)malloc(N * sizeof(double*));
    for (i = 0; i < N; i++) {
        m2[i] = (double*)malloc(N * sizeof(double));
    }

    printf("vvedite 1 matrisu:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("m1[%d][%d] = ", i, j);
            scanf("%lf", &m1[i][j]);
        }
    }

    printf("vvedite 2 matrisu:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("m2[%d][%d] = ", i, j);
            scanf("%lf", &m2[i][j]);
        }
    }

    printf("vvedite operasiu (+, -, *): ");
    scanf(" %c", &operation);

    if (operation == '+') {
        result = summatrix(m1, m2, N);
    } 
     else if (operation == '-') {  
        result = submatrix(m1, m2, N); 
    } 
     else if (operation == '*') {  
        result = multmatrix(m1, m2, N);
    } else {
        printf("incorrect\n");
        return 1;
    }

    printf("result:\n");
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