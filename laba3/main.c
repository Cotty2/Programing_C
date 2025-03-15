#include <stdio.h>

int main() {
    char str[80];
    printf("Vvedite stroku: ");
    fgets(str, sizeof(str), stdin); 

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a') {
            str[i] = 'A';
        } else if (str[i] == 'b') 
            str[i] = 'B';
          else if (str[i] == '.') {
                str[i] = '!';
        }
    }

    printf("Resultat: %s\n", str);
    return 0;
}
