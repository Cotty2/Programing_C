#include <stdio.h>
#include <stdlib.h>

struct humen {
    char name[50];     
    char patronymic[50]; 
    char surname[50];   
    int dr;            
};

int main() {
    FILE *file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия .\n");
        return 1;
    }

    int count = 0;
    char buffer[200];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (buffer[0] != '\n') count++; 
    }
    rewind(file);

    if (count == 0) {
        printf("Файл пуст.\n");
        fclose(file);
        return 1;
    }

    struct humen *first_array = malloc(count * sizeof(struct humen));
    struct humen *second_array = malloc(count * sizeof(struct humen));

    printf("Чтение (%d человек):\n", count);
    for (int i = 0; i < count; i++) {
        if (fscanf(file, "%s %s %s %d", 
                first_array[i].name, 
                first_array[i].patronymic, 
                first_array[i].surname, 
                &first_array[i].dr) != 4) {
            printf("Ошибка %d\n", i+1);
            fclose(file);
            free(first_array);
            free(second_array);
            return 1;
        }
        printf("%s %s %s, %d\n", 
              first_array[i].name, 
              first_array[i].patronymic, 
              first_array[i].surname, 
              first_array[i].dr);
    }
    fclose(file);
    for (int i = 0; i < count; i++) {
        second_array[i] = first_array[i];
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (second_array[j].dr > second_array[j+1].dr) {
                struct humen temp = second_array[j];
                second_array[j] = second_array[j+1];
                second_array[j+1] = temp;
            }
        }
    }
    printf("\nотсортированный список:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %s %s, %d\n", 
              second_array[i].name, 
              second_array[i].patronymic, 
              second_array[i].surname, 
              second_array[i].dr);
    }
    free(first_array);
    free(second_array);

    return 0;
}
