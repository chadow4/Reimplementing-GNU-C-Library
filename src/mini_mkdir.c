#include "mini_lib.h"
#include <sys/stat.h>


int main(int argc, char **argv) {

    if (argc != 2) {
        mini_printf("Error number of arguments");
    }

    if (mkdir(argv[1], 0775) == -1) {
        mini_printf("Error directory creation\n");
        return 1;
    }

    return 0;
}