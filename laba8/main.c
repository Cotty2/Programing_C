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
} Individual;

int primarySortKey;
int secondarySortKey;

int loadDataFromFile(Individual **list, int *total) {
    FILE *fp = fopen(DATA_FILE, "r");

    *list = NULL;
    *total = 0;

    Individual buffer;

    while (fscanf(fp, "%s %d %c %f", buffer.fullName, &buffer.birthYear, &buffer.sex, &buffer.stature) == 4) {
        (*total)++;
        *list = (Individual *)realloc(*list, (*total) * sizeof(Individual));
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

int saveDataToFile(Individual *list, int total) {
    FILE *fp = fopen(DATA_FILE, "w");
    if (fp == NULL) {
        printf("Не удалось открыть файл %s для записи\n", DATA_FILE);
        return 0;
    }

    for (int i = 0; i < total; i++) {
        fprintf(fp, "%s %d %c %f\n", list[i].fullName, list[i].birthYear, list[i].sex, list[i].stature);
    }

    fclose(fp);
    return 1;
}

int cmpByYear(const void *x, const void *y) {
    const Individual *a = (const Individual *)x;
    const Individual *b = (const Individual *)y;
    return a->birthYear - b->birthYear;
}

int cmpByName(const void *x, const void *y) {
    const Individual *a = (const Individual *)x;
    const Individual *b = (const Individual *)y;
    return strcmp(a->fullName, b->fullName);
}

int cmpBySex(const void *x, const void *y) {
    const Individual *a = (const Individual *)x;
    const Individual *b = (const Individual *)y;
    return a->sex - b->sex;
}

int cmpByHeight(const void *x, const void *y) {
    const Individual *a = (const Individual *)x;
    const Individual *b = (const Individual *)y;
    if (a->stature < b->stature) return -1;
    if (a->stature > b->stature) return 1;
    return 0;
}

int multiFieldCompare(const void *x, const void *y) {
    const Individual *a = (const Individual *)x;
    const Individual *b = (const Individual *)y;
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

void displayList(Individual *list, int total) {
    for (int i = 0; i < total; i++) {
        printf("Имя: %s, Год: %d, Пол: %c, Рост: %.2f\n",
               list[i].fullName, list[i].birthYear, list[i].sex, list[i].stature);
    }
}

int main() {
    Individual *persons = NULL;
    int count = 0;

    if (!loadDataFromFile(&persons, &count)) {
        return 1;
    }

    if (count == 0) {
        printf("В файле нет данных.\n");
        return 0;
    }

    printf("Выберите первое поле для сортировки (1: Год, 2: Имя, 3: Пол, 4: Рост): ");
    scanf("%d", &primarySortKey);

    printf("Выберите второе поле (0 - нет, 1: Год, 2: Имя, 3: Пол, 4: Рост): ");
    scanf("%d", &secondarySortKey);

    if (secondarySortKey == 0) {
        switch (primarySortKey) {
            case 1: qsort(persons, count, sizeof(Individual), cmpByYear); break;
            case 2: qsort(persons, count, sizeof(Individual), cmpByName); break;
            case 3: qsort(persons, count, sizeof(Individual), cmpBySex); break;
            case 4: qsort(persons, count, sizeof(Individual), cmpByHeight); break;
            default:
                printf("Неверный выбор поля.\n");
                free(persons);
                return 1;
        }
    } else {
        qsort(persons, count, sizeof(Individual), multiFieldCompare);
    }

    printf("\nОтсортированные данные:\n");
    displayList(persons, count);

    free(persons);
    return 0;
}
