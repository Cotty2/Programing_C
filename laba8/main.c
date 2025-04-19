#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 64
#define DATA_FILENAME "people.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    int yearOfBirth;
    char gender;
    float height;
} Person;

int mainSortField;
int secondarySortField;

int loadPersonsFromFile(Person **personsArray, int *numPersons) {
    FILE *file = fopen(DATA_FILENAME, "r");
    if (!file) {
        printf("Не удалось открыть файл %s\n", DATA_FILENAME);
        return 0;
    }

    *personsArray = NULL;
    *numPersons = 0;

    Person tempPerson;

    while (fscanf(file, "%s %d %c %f", tempPerson.name, &tempPerson.yearOfBirth, &tempPerson.gender, &tempPerson.height) == 4) {
        (*numPersons)++;
        *personsArray = (Person *)realloc(*personsArray, (*numPersons) * sizeof(Person));
        if (*personsArray == NULL) {
            printf("Ошибка выделения памяти\n");
            fclose(file);
            return 0;
        }
        (*personsArray)[*numPersons - 1] = tempPerson;
    }

    fclose(file);
    return 1;
}

int compareByYear(const void *a, const void *b) {
    const Person *p1 = (const Person *)a;
    const Person *p2 = (const Person *)b;
    return p1->yearOfBirth - p2->yearOfBirth;
}

int compareByName(const void *a, const void *b) {
    const Person *p1 = (const Person *)a;
    const Person *p2 = (const Person *)b;
    return strcmp(p1->name, p2->name);
}

int compareByGender(const void *a, const void *b) {
    const Person *p1 = (const Person *)a;
    const Person *p2 = (const Person *)b;
    return p1->gender - p2->gender;
}

int compareByHeight(const void *a, const void *b) {
    const Person *p1 = (const Person *)a;
    const Person *p2 = (const Person *)b;
    if (p1->height < p2->height) return -1;
    if (p1->height > p2->height) return 1;
    return 0;
}

int multiFieldComparator(const void *a, const void *b) {
    const Person *p1 = (const Person *)a;
    const Person *p2 = (const Person *)b;
    int result = 0;

    switch (mainSortField) {
        case 1: result = compareByYear(p1, p2); break;
        case 2: result = compareByName(p1, p2); break;
        case 3: result = compareByGender(p1, p2); break;
        case 4: result = compareByHeight(p1, p2); break;
        default: result = 0; break;
    }

    if (result == 0 && secondarySortField != 0) {
        switch (secondarySortField) {
            case 1: result = compareByYear(p1, p2); break;
            case 2: result = compareByName(p1, p2); break;
            case 3: result = compareByGender(p1, p2); break;
            case 4: result = compareByHeight(p1, p2); break;
            default: result = 0; break;
        }
    }

    return result;
}

void printPersonsList(Person *personsArray, int numPersons) {
    printf("Отсортированный список:\n");
    for (int i = 0; i < numPersons; i++) {
        printf("ФИО: %s, Год рождения: %d, Пол: %c, Рост(м): %.2f\n",
               personsArray[i].name, personsArray[i].yearOfBirth, personsArray[i].gender, personsArray[i].height);
    }
}

int main() {
    Person *persons = NULL;
    int totalPersons = 0;

    if (!loadPersonsFromFile(&persons, &totalPersons)) {
        return 1;
    }

    if (totalPersons == 0) {
        printf("Файл пуст или не содержит данных.\n");
        return 0;
    }

    printf("Выберите основное поле для сортировки:\n");
    printf("1. Год рождения\n");
    printf("2. ФИО\n");
    printf("3. Пол\n");
    printf("4. Рост\n");
    printf("Введите номер поля: ");
    scanf("%d", &mainSortField);

    printf("Выберите второстепенное поле для сортировки (0 - нет):\n");
    printf("1. Год рождения\n");
    printf("2. ФИО\n");
    printf("3. Пол\n");
    printf("4. Рост\n");
    printf("Введите номер поля: ");
    scanf("%d", &secondarySortField);

    if (secondarySortField == 0) {
        switch (mainSortField) {
            case 1: qsort(persons, totalPersons, sizeof(Person), compareByYear); break;
            case 2: qsort(persons, totalPersons, sizeof(Person), compareByName); break;
            case 3: qsort(persons, totalPersons, sizeof(Person), compareByGender); break;
            case 4: qsort(persons, totalPersons, sizeof(Person), compareByHeight); break;
            default:
                printf("Недопустимый выбор поля.\n");
                free(persons);
                return 1;
        }
    } else {
        qsort(persons, totalPersons, sizeof(Person), multiFieldComparator);
    }

    printf("\nРезультат сортировки:\n");
    printPersonsList(persons, totalPersons);

    free(persons);
    return 0;
}
