#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char *argv[]) {
    double a, b, c;
    double x1, x2, d;
    char vibor;

    while (1) {
        printf("Vvedite a:\n");
        scanf("%lf", &a);
        printf("Vvedite b:\n");
        scanf("%lf", &b);
        printf("Vvedite c:\n");
        scanf("%lf", &c);

        d = pow(b, 2) - 4 * a * c;
        printf("d = %1f \n", d);

        if (d > 0) {
            x1 = (-b + sqrt(d)) / (2 * a);  //
            x2 = (-b - sqrt(d)) / (2 * a);  

            printf("x1 = %1f \n", x1);
            printf("x2 = %1f \n", x2);

        } else if (d == 0) {
            x1 = -b / (2 * a);  //
            printf("x1 = x2 = %1f \n", x1);
        } else {
            printf("Kornei net\n");
        }

        printf("Next? (y/n): ");
        scanf(" %c", &vibor);  
        if (vibor!= 'y' && vibor != 'Y') {
            break;  
        }
    }

    return 0;
}