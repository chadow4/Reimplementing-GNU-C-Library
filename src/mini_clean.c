#include <unistd.h>
#include "mini_lib.h"


int main(int argc, char **argv) {

    if(argc !=2){
        mini_printf("Error: number of arguments invalid\n");
        return -1;
    }
    MYFILE *myfile = mini_fopen(argv[1], 'w');
    if (myfile == NULL) {
        return -1;
    }
    mini_fclose(myfile);

    return 0;
}
