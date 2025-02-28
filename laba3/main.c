#include <stdio.h>

int main() {
    char str[80];
    int i = 0;

    printf("Vvedite stroku: ");
    gets(str);

    while (str[i] != '\0') {
        if (str[i] == 'a' || str[i] == 'b') {
            str[i] = str[i] - 32;
        }
        i++;
    }

    printf("Resultat: %s\n", str);
    return 0;
}

