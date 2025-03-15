#include <stdio.h>
#include <string.h>
typedef struct book {
    int num;
    char *title;
    char *author;
    char *publisher;
    char *isbn;
    int year;
    char *series;
    char *volume;
}BOOK;
int main(int argc,char *argv[])
{
    FILE *F; BOOK *book;
    char s[1024], *ps,author[256];

}

    F=fopen(argv[argc],"r");
    while ( fgets (s,"author"))

