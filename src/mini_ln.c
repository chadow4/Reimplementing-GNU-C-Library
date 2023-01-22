#include "mini_lib.h"
#include <unistd.h>

int main(int argc, char **argv) {

    if (argc != 3) {
        mini_printf("Error number of arguments\n");
        return 1;
    }
    if (symlink(argv[1], argv[2]) == -1) {
        mini_printf("Error created link\n");
        return 1;
    }
    return 0;
}