#include "mini_lib.h"
#include <stdio.h> // for rename in man 2
int main(int argc, char *argv[]) {
    if (argc != 3) {
        mini_printf("Error: number of arguments invalid\n");
        return 1;
    }
    mini_printf("ts");
    if (rename(argv[1], argv[2]) != 0) {
        mini_printf("Error : Unable to move");
        return 1;
    }
    return 0;
}

