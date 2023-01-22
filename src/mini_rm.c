#include "mini_lib.h"
#include <unistd.h>

int main(int argc, char **argv) {

    if (unlink(argv[1]) == -1) {
        mini_printf("Error removing files");
        return 1;
    }

    return 0;
}