#include <stdio.h>

int main() {
    FILE *in, *out;
    char fam[30], name[30], otch[30];
    int year;
    in = fopen("people.txt","r");
    if (in == NULL) {
        printf("people.txt не найден\n");
        return 1;
    }
    out = fopen("people1.txt","w");
    if (out == NULL) {
        printf("ошибка people1.txt\n");
        fclose(in);
        return 1;
    }
    while (fscanf(in, "%s %s %s %d", fam, name, otch, &year) == 4) {
        if (year > 1980) {
            fprintf(out, "%s %s %s %d\n", fam, name, otch, year);
        }
    }
    fclose(in);
    fclose(out);
    
    printf("готово\n");
    return 0;
}
