#include <unistd.h>
#include "mini_lib.h"


int main(int argc, char **argv) {

    MYFILE *myfile = mini_fopen(argv[1], 'w');
    if (myfile == NULL) {
        mini_printf("Erreur de création\n");
    }
    mini_fclose(myfile);

    return 0;
}
