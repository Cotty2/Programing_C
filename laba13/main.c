#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void obrabotka(int sig) {
    if (sig == SIGABRT) {
        printf("Пойман сигнал SIGABRT (аварийное завершение)\n");
    } else if (sig == SIGFPE) {
        printf("Пойман сигнал SIGFPE (ошибка деления или арифметики)\n");
    } else if (sig == SIGILL) {
        printf("Пойман сигнал SIGILL (недопустимая инструкция)\n");
    } else if (sig == SIGINT) {
        printf("Пойман сигнал SIGINT (прерывание, Ctrl+C)\n");
    } else if (sig == SIGSEGV) {
        printf("Пойман сигнал SIGSEGV (ошибка памяти)\n");
    } else if (sig == SIGTERM) {
        printf("Пойман сигнал SIGTERM (запрос завершения)\n");
    } else {
        printf("Пойман неизвестный сигнал %d\n", sig);
    }
    if (sig != SIGINT) {
        exit(0);
    }
}

int main() {
    signal(SIGABRT, obrabotka);
    signal(SIGFPE, obrabotka);
    signal(SIGILL, obrabotka);
    signal(SIGINT, obrabotka);
    signal(SIGSEGV, obrabotka);
    signal(SIGTERM, obrabotka);

    char buf[20];
    printf("Введите сигнал для вызова (ABRT, FPE, ILL, INT, SEGV, TERM) или exit для выхода:\n");

    while (1) {
        printf("> ");
        if (fgets(buf, sizeof(buf), stdin) == NULL) break;
        buf[strcspn(buf, "\n")] = 0;

        if (strcmp(buf, "exit") == 0) {
            printf("Выход из программы\n");
            break;
        } else if (strcmp(buf, "ABRT") == 0) {
            raise(SIGABRT);
        } else if (strcmp(buf, "FPE") == 0) {
            raise(SIGFPE);
        } else if (strcmp(buf, "ILL") == 0) {
            raise(SIGILL);
        } else if (strcmp(buf, "INT") == 0) {
            raise(SIGINT);
        } else if (strcmp(buf, "SEGV") == 0) {
            raise(SIGSEGV);
        } else if (strcmp(buf, "TERM") == 0) {
            raise(SIGTERM);
        } else {
            printf("Неизвестный сигнал, попробуйте снова\n");
        }
    }

    return 0;
}
