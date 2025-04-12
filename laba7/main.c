#include <stdio.h>
#include <stdlib.h>

struct humen {
    char name[50];      
    char patronymic[50]; 
    char surname[50];   
    int dr;             
};

int main() {
    int n; 
    printf("введите количество людей: ");
    scanf("%d", &n);
    struct humen *first_array = (struct humen *)malloc(n * sizeof(struct humen));
    struct humen *second_array = (struct humen *)malloc(n * sizeof(struct humen));

    if (first_array == NULL || second_array == NULL) {
        printf("ошибка памяти\n");
        return 1;
    }


    FILE *file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("ошибка открытия \n");
        free(first_array);
        free(second_array);
        return 1;
    }

    printf("чтение:\n");
    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%s %s %s %d", 
                   first_array[i].name, 
                   first_array[i].patronymic, 
                   first_array[i].surname, 
                   &first_array[i].dr) != 4) {
            printf("ошибка чтения\n");
            fclose(file);
            free(first_array);
            free(second_array);
            return 1;
        }
        printf("Человек %d: %s %s %s, %d год\n", 
               i+1, 
               first_array[i].name, 
               first_array[i].patronymic, 
               first_array[i].surname, 
               first_array[i].dr);
    }

    fclose(file);

    for (int i = 0; i < n; i++) {
        second_array[i] = first_array[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (second_array[j].dr > second_array[j+1].dr) {
                struct humen temp = second_array[j];
                second_array[j] = second_array[j+1];
                second_array[j+1] = temp;
            }
        }
    }

    printf("\n отсортированный:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %s %s, %d год\n", 
               second_array[i].name, 
               second_array[i].patronymic, 
               second_array[i].surname, 
               second_array[i].dr);
    }

    free(first_array);
    free(second_array);

    return 0;
}
