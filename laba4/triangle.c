#include <math.h>

// Функция для периметра
double perim(double a, double b, double c) {
    return a + b + c;
}

// Функция для площади (формула Герона)
double area(double a, double b, double c) {
    double p = (a + b + c) / 2; // полупериметр
    double s = sqrt(p * (p - a) * (p - b) * (p - c)); // формула
    return s;
}