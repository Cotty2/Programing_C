#include <stdio.h>

// Объявление функций из triangle.c
double perim(double a, double b, double c);
double area(double a, double b, double c);

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
    if (a + b > c && a + c > b && b + c > a) {
        // Всё ок, считаем периметр и площадь
        double p = perim(a, b, c);
        double s = area(a, b, c);

        // Вывод результата
        printf("Периметр: %lf\n", p);
        printf("Площадь: %lf\n", s);
    } else {
        // Если не треугольник
        printf("Это не треугольник! Стороны неправильные!\n");
    }

    return 0;
}