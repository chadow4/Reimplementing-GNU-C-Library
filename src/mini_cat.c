#include <unistd.h>
#include "mini_lib.h"

#define BUF_SIZE 1024

int main(int argc, char **argv) {

    MYFILE *catFile = mini_fopen(argv[1], 'r');
    char *reader = mini_calloc(sizeof(char),BUF_SIZE);
    mini_fread(reader,sizeof(char),BUF_SIZE,catFile);
    mini_printf(reader);
    mini_fclose(catFile);
    mini_exit();


}