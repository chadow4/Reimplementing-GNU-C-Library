#include <unistd.h>
#include "mini_lib.h"


int main(int argc, char **argv) {

    if(argc != 2){
        mini_printf("Error: number of arguments invalid\n");
        return -1;
    }

    MYFILE *myfile = mini_fopen(argv[1], 'a');
    if (myfile == NULL) {
        mini_printf("Erreur de création\n");
        return -1;
    }
    mini_printf("File created");
    mini_fclose(myfile);
    mini_exit();

    return 0;
}
