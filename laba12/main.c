#include <stdio.h>
#include <string.h>
#include <time.h>

int visokos(int god) {
    if ((god % 4 == 0 && god % 100 != 0) || god % 400 == 0)
        return 1;
    else
        return 0;
}

int dni_v_mes(int god, int mes) {
    int d[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (mes == 2 && visokos(god))
        return 29;
    return d[mes-1];
}

int den_nedeli(int god, int mes, int den) {
    struct tm t = {0};
    t.tm_year = god - 1900;
    t.tm_mon = mes - 1;
    t.tm_mday = den;
    mktime(&t);
    return t.tm_wday;
}

void pokazat_den(int god, int mes, int den) {
    char *dni[] = {"Воскресенье","Понедельник","Вторник","Среда","Четверг","Пятница","Суббота"};
    int d = den_nedeli(god, mes, den);
    printf("%04d.%02d.%02d - %s\n", god, mes, den, dni[d]);
}

void pokazat_mes(int god, int mes) {
    printf("Календарь %04d.%02d\n", god, mes);
    printf("Пн Вт Ср Чт Пт Сб Вс\n");

    int first = den_nedeli(god, mes, 1);
    int start = first == 0 ? 6 : first - 1;

    int days = dni_v_mes(god, mes);

    for (int i=0; i<start; i++) {
        printf("   ");
    }

    for (int d=1; d<=days; d++) {
        printf("%2d ", d);
        if ((start + d) % 7 == 0)
            printf("\n");
    }
    printf("\n");
}

void pokazat_god(int god) {
    for (int m=1; m<=12; m++) {
        pokazat_mes(god, m);
        printf("\n");
    }
}

int main() {
    char vvod[20];
    printf("Введите дату (гггг.мм.дд, гггг.мм, гггг) или now: ");
    scanf("%19s", vvod);

    if (strcmp(vvod, "now") == 0) {
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        int god = tm->tm_year + 1900;
        int mes = tm->tm_mon + 1;
        int den = tm->tm_mday;
        pokazat_den(god, mes, den);
    } else {
        int god, mes, den;
        int n = sscanf(vvod, "%d.%d.%d", &god, &mes, &den);
        if (n == 3) {
            if (god<1 || mes<1 || mes>12 || den<1 || den>dni_v_mes(god, mes)) {
                printf("Неверная дата\n");
                return 1;
            }
            pokazat_den(god, mes, den);
        } else {
            n = sscanf(vvod, "%d.%d", &god, &mes);
            if (n == 2) {
                if (god<1 || mes<1 || mes>12) {
                    printf("Неверный месяц или год\n");
                    return 1;
                }
                pokazat_mes(god, mes);
            } else {
                n = sscanf(vvod, "%d", &god);
                if (n == 1) {
                    if (god<1) {
                        printf("Неверный год\n");
                        return 1;
                    }
                    pokazat_god(god);
                } else {
                    printf("Неверный ввод\n");
                    return 1;
                }
            }
        }
    }

    return 0;
}
