#include <unistd.h>
#include "mini_lib.h"

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {

    MYFILE *wcFile = mini_fopen(argv[1], 'r');
    char *reader = mini_calloc(sizeof(char), BUFFER_SIZE);
    mini_fread(reader, sizeof(char), BUFFER_SIZE, wcFile);
    int nb = 1;
    char str[100] = {0};

    for (int i = 0; *(reader + i) != '\0'; i++) {
        if (*(reader + i) == '\n' || *(reader + i) == ' ') {
            nb++;
        }
    }
    mini_fclose(wcFile);
    mini_printf("Le nombre de mots dans le fichier : ");
    mini_printf(intToString(nb, str, 10));

    mini_exit();

    return 0;
}