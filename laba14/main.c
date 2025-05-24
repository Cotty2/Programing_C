#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

void fib_sum(int n, int a, int b, int sum, int *result) {
    if (n == 0) {
        *result = sum;
        longjmp(env, 1);
    }
    fib_sum(n - 1, b, a + b, sum + a, result);
}

int main() {
    int n;
    printf("Введите количество чисел Фибоначчи для суммы (не более 46): ");
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    if (n > 46) {
        printf("Ошибка: число слишком большое\n");
        return 1;
    }

    int result = 0;
    if (setjmp(env) == 0) {
        fib_sum(n, 1, 1, 0, &result);
    }

    printf("Сумма первых %d чисел Фибоначчи: %d\n", n, result);
    return 0;
}
