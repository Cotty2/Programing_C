#include <stdio.h>

struct humen {
    char name[50];      
    char surname[50];   
    int dr;      
};

int main() {
    struct humen first_array[4];   
    struct humen second_array[4];  

    printf("Введите данные 4 людей:\n");
    for (int i = 0; i < 4; i++) {
        printf("Человек %d:\n", i+1);
        printf("Имя: ");
        scanf("%s", first_array[i].name);
        printf("Фамилия: ");
        scanf("%s", first_array[i].surname);
        printf("Год рождения: ");
        scanf("%d", &first_array[i].dr);
    }

    for (int i = 0; i < 4; i++) {
        second_array[i] = first_array[i];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (second_array[j].dr > second_array[j+1].dr) {
                struct humen temp = second_array[j];
                second_array[j] = second_array[j+1];
                second_array[j+1] = temp;
            }
        }
    }
    printf("\nОтсортированный:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s %s, %d год\n", 
               second_array[i].name, 
               second_array[i].surname, 
               second_array[i].dr);
    }

    return 0;
}