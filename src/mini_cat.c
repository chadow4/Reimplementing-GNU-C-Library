#include <unistd.h>
#include "mini_lib.h"

#define BUF_SIZE 1024

int main(int argc, char **argv) {

    if (argc != 2) {
        mini_printf("Invalid number of arguments\n");
        return -1;
    }
    MYFILE *catFile = mini_fopen(argv[1], 'r');
    if (catFile == NULL) {
        return -1;

    }
    char *reader = mini_calloc(sizeof(char), BUF_SIZE);
    mini_fread(reader, sizeof(char), BUF_SIZE, catFile);
    mini_printf(reader);
    mini_exit();
    return 0;


}