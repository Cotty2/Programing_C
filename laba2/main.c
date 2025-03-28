#include <stdio.h>

/*1 �������� ������ ������ ���� double �������� 3 �� 3. 
2������ � ������� ��� ��������, ������� �� ������� ����� ��� ���������, ������������� �� ������� ��������� � ����� ���������, 
������������� ��  �������� ���������.
3�������� ������ ������ ���� int �������� 2 �� 2.
4������ � ������� ��� ��������, ������� �� ������� ������� ������ �������.
*/

int main() {
    double m[3][3];
    double sum1 = 0, sum2 = 0;
    int m2[2][2];
    double res[2][2];
    char i, j, k;

    printf("Vvedite matrisu 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%lf", &m[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        sum1 += m[i][i];
    }

    for (i = 0; i < 3; i++) {
        sum2 += m[i][2 - i];
    }

    printf("Sum diagonal main: %.2lf\n", sum1);
    printf("Sum diagonal ne main: %.2lf\n", sum2);

    printf("Vvedite matrisu 2x2:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                res[i][j] += m2[i][k] * m2[k][j];
            }
        }
    }

    printf("Kvadrat matrisi 2x2:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%.2lf ", res[i][j]);
        }
    }
    return 0;
}

