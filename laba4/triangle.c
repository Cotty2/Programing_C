#include <math.h>
#include <stdbool.h>
// Функция для проверки 
bool norm(double a, double b, double c) {
    return(a + b > c && a + c > b && b + c > a);
}
// Функция для периметра
double perim(double a, double b, double c) {
    return a + b + c;
}

// Функция для площади 
double area(double a, double b, double c) {
    double p = (a + b + c) / 2; // полупериметр
    double s = sqrt(p * (p - a) * (p - b) * (p - c)); // формула
    return s;
}