#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char inputStr[256];
    printf("Введите выражение: ");
    fgets(inputStr, sizeof(inputStr), stdin);

    inputStr[strcspn(inputStr, "\n")] = 0;

    char *strok;
    double result = 0.0;
    char operation = '+';

    strok = strtok(inputStr, " ");
    while (strok != NULL) {
        if (strcmp(strok, "+") == 0 || strcmp(strok, "-") == 0) {
            operation = strok[0];
        } else {
            double number = atof(strok);
            if (operation == '+') {
                result += number;
            } else {
                result -= number;
            }
        }
        strok = strtok(NULL, " ");
    }

    printf("Результат: %f\n", result);
    return 0;
}