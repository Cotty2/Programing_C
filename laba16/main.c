#include <stdio.h>
#include <string.h>

int longbits(unsigned long x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

int bitsbytes(const unsigned char *bytes, size_t size) {
    int count = 0;
    for (size_t i = 0; i < size; i++) {
        unsigned char b = bytes[i];
        for (int j = 0; j < 8; j++) {
            count += (b >> j) & 1;
        }
    }
    return count;
}

int main() {
    long lnum;
    double dnum;

    printf("Введите число типа long: ");
    if (scanf("%ld", &lnum) != 1) {
        printf("Ошибка ввода long\n");
        return 1;
    }

    printf("Введите число типа double: ");
    if (scanf("%lf", &dnum) != 1) {
        printf("Ошибка ввода double\n");
        return 1;
    }
    int bits_long = longbits((unsigned long)lnum);
    unsigned char *p = (unsigned char*)&dnum;
    int bits_double = bitsbytes(p, sizeof(double));

    printf("битов в long: %d\n", bits_long);
    printf("битов в double: %d\n", bits_double);

    return 0;
}
