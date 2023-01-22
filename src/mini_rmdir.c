#include "mini_lib.h"
#include <unistd.h>

int main(int argc, char **argv) {

    if (rmdir(argv[1]) == -1) {
        mini_printf("Error removing directory\n");
        return 1;
    }

    return 0;
}