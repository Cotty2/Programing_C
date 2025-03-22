#include <stdio.h>
#include <stdbool.h>
#include "triangle.h"

int main() {
    double a, b, c;

    // Ввод сторон
    printf("Введите стороны треугольника:\n");
    printf("Сторона a: ");
    scanf("%lf", &a);
    printf("Сторона b: ");
    scanf("%lf", &b);
    printf("Сторона c: ");
    scanf("%lf", &c);

    // Проверка на треугольник
    if (norm(a,b,c)) {
        //  считаем периметр и площадь
        double p = perim(a, b, c);
        double s = area(a, b, c);

        // Вывод результата
        printf("Периметр: %lf\n", p);
        printf("Площадь: %lf\n", s);
    } else {
        // Если не треугольник
        printf("Это не треугольник! \n");
    }

    return 0;
}
//gcc main.c triangle.c -o triangle -lm
//./triangle