#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

void fib_sum(int n, int a, int b, int sum, int *result) {
    if (n > 44) {
        printf("Ошибка: число слишком большое\n");
        longjmp(env, 2); 
    }
    if (n == 0) {
        *result = sum;
        longjmp(env, 1);  
    }
    fib_sum(n - 1, b, a + b, sum + a, result);
}

int main() {
    int n;
    printf("Введите количество чисел Фибоначчи для суммы: ");
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    int result = 0;
    int ret = setjmp(env);
    if (ret == 0) {
        fib_sum(n, 1, 1, 0, &result);
    } else if (ret == 1) {

        printf("Сумма первых %d чисел Фибоначчи: %d\n", n, result);
    } else if (ret == 2) {

        return 1;
    }

    return 0;
}
