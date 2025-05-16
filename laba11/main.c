#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...) {
    va_list args;
    va_start(args, count);
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    va_end(args);
    return total;
}

int max(int count, ...) {
    va_list args;
    va_start(args, count);
    int maximum = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int num = va_arg(args, int);
        if (num > maximum) {
            maximum = num;
        }
    }
    va_end(args);
    return maximum;
}

int min(int count, ...) {
    va_list args;
    va_start(args, count);
    int minimum = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int num = va_arg(args, int);
        if (num < minimum) {
            minimum = num;
        }
    }
    va_end(args);
    return minimum;
}

float average(int count, ...) {
    va_list args;
    va_start(args, count);
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    va_end(args);
    return (float)total / count;
}

int main() {
    printf("Sum: %d\n", sum(5, 1, 2, 3, 4, 5));
    printf("Max: %d\n", max(5, 1, 2, 3, 4, 5));
    printf("Min: %d\n", min(5, 1, 2, 3, 4, 5));
    printf("Average: %.2f\n", average(5, 1, 2, 3, 4, 5));
    return 0;
}
