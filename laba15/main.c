#include <stdio.h>
void forwar(int n) {
    if (n == 0) return;
    forwar(n / 10);
    printf("%d ", n % 10);
}
void bwar(int n) {
    if (n == 0) return;
    printf("%d ", n % 10);
    bwar(n / 10);
}

int main() {
    int N;
    printf("Введите натуральное число: ");
    scanf("%d", &N);

    if (N == 0) {
        printf("0\n0\n");
        return 0;
    }

    forwar(N);
    printf("\n");
    bwar(N);
    printf("\n");

    return 0;
}
