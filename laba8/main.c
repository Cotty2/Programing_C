#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 64
#define DATA_FILE "people.txt"

typedef struct {
    char fullName[MAX_STR_LEN];
    int birthYear;
    char sex;
    float stature;
} Chelovek;

int primarySortKey;
int secondarySortKey;

int loadDataFromFile(Chelovek **list, int *total) {
    FILE *fp = fopen(DATA_FILE, "r");

    *list = NULL;
    *total = 0;

    Chelovek buffer;

    while (fscanf(fp, "%s %d %c %f", buffer.fullName, &buffer.birthYear, &buffer.sex, &buffer.stature) == 4) {
        (*total)++;
        *list = (Chelovek *)realloc(*list, (*total) * sizeof(Chelovek));
        if (*list == NULL) {
            printf("Ошибка выделения памяти\n");
            fclose(fp);
            return 0;
        }
        strcpy((*list)[*total - 1].fullName, buffer.fullName);
        (*list)[*total - 1].birthYear = buffer.birthYear;
        (*list)[*total - 1].sex = buffer.sex;
        (*list)[*total - 1].stature = buffer.stature;
    }

    fclose(fp);
    return 1;
}

int cmpByYear(const void *x, const void *y) {
    const Chelovek *a = (const Chelovek *)x;
    const Chelovek *b = (const Chelovek *)y;
    return a->birthYear - b->birthYear;
}

int cmpByName(const void *x, const void *y) {
    const Chelovek *a = (const Chelovek *)x;
    const Chelovek *b = (const Chelovek *)y;
    return strcmp(a->fullName, b->fullName);
}

int cmpBySex(const void *x, const void *y) {
    const Chelovek *a = (const Chelovek *)x;
    const Chelovek *b = (const Chelovek *)y;
    return a->sex - b->sex;
}

int cmpByHeight(const void *x, const void *y) {
    const Chelovek *a = (const Chelovek *)x;
    const Chelovek *b = (const Chelovek *)y;
    if (a->stature < b->stature) return -1;
    if (a->stature > b->stature) return 1;
    return 0;
}

int multiFieldCompare(const void *x, const void *y) {
    const Chelovek *a = (const Chelovek *)x;
    const Chelovek *b = (const Chelovek *)y;
    int res = 0;

    switch (primarySortKey) {
        case 1: res = cmpByYear(a, b); break;
        case 2: res = cmpByName(a, b); break;
        case 3: res = cmpBySex(a, b); break;
        case 4: res = cmpByHeight(a, b); break;
        default: res = 0; break;
    }

    if (res == 0 && secondarySortKey != 0) {
        switch (secondarySortKey) {
            case 1: res = cmpByYear(a, b); break;
            case 2: res = cmpByName(a, b); break;
            case 3: res = cmpBySex(a, b); break;
            case 4: res = cmpByHeight(a, b); break;
            default: res = 0; break;
        }
    }

    return res;
}

void displayList(Chelovek *list, int total) {
    printf("Список отсортированных данных:\n");
    for (int i = 0; i < total; i++) {
        printf("ФИО: %s, Год рождения: %d, Пол: %c, Рост(м): %.2f\n",
               list[i].fullName, list[i].birthYear, list[i].sex, list[i].stature);
    }
}

int main() {
    Chelovek *Cheloveks = NULL;
    int count = 0;

    if (!loadDataFromFile(&Cheloveks, &count)) {
        return 1;
    }

    if (count == 0) {
        printf("Файл пуст или не содержит данных.\n");
        return 0;
    }

    printf("Выберите основное поле для сортировки:\n");
    printf("1. Год рождения\n");
    printf("2. ФИО\n");
    printf("3. Пол\n");
    printf("4. Рост\n");
    printf("Введите номер поля: ");
    scanf("%d", &primarySortKey);

    printf("Выберите второстепенное поле для сортировки (0 - нет):\n");
    printf("1. Год рождения\n");
    printf("2. ФИО\n");
    printf("3. Пол\n");
    printf("4. Рост\n");
    printf("Введите номер поля: ");
    scanf("%d", &secondarySortKey);

    if (secondarySortKey == 0) {
        switch (primarySortKey) {
            case 1: qsort(Cheloveks, count, sizeof(Chelovek), cmpByYear); break;
            case 2: qsort(Cheloveks, count, sizeof(Chelovek), cmpByName); break;
            case 3: qsort(Cheloveks, count, sizeof(Chelovek), cmpBySex); break;
            case 4: qsort(Cheloveks, count, sizeof(Chelovek), cmpByHeight); break;
            default:
                printf("Недопустимый выбор поля.\n");
                free(Cheloveks);
                return 1;
        }
    } else {
        qsort(Cheloveks, count, sizeof(Chelovek), multiFieldCompare);
    }

    printf("\nРезультат сортировки:\n");
    displayList(Cheloveks, count);

    free(Cheloveks);
    return 0;
}
