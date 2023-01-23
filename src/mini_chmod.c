#include <sys/stat.h>
#include "mini_lib.h"

int main(int argc, char **argv) {

    if (argc != 3) {
        mini_printf("Error: number of arguments invalid\n");
        return 1;
    }

    mode_t mode = (mode_t) stringToInt(argv[1], 8);
    char *path = argv[2];

    if (chmod(path, mode) != 0) {
        mini_printf("Error: chmod\n");
        return 1;
    }

    mini_printf("permissions of file changed\n");


    return 0;
}