#include <unistd.h>
#include "mini_lib.h"

#define BUF_SIZE 1024

int main(int argc, char **argv) {

    char *reader = mini_calloc(sizeof(char), BUF_SIZE);

    MYFILE *file = mini_fopen(argv[3], 'r');
    mini_fread(reader, sizeof(char), BUF_SIZE, file);
    char *buffer = mini_calloc(sizeof(char), BUF_SIZE);
    int nb = 0;
    int j = 0;

    for (int i = 0; nb < stringToInt(argv[2]) && *(reader + i) != '\0'; i++) {

        *(buffer + i) = *(reader + i);
        if (*(reader + i) == '\n') {
            nb++;
        }
        j++;
    }
    *(char *) (buffer + j) = '\0';



    mini_printf(buffer);

    mini_exit();
    
    return 0;
}