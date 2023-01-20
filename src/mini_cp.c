#include "mini_lib.h"
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char **argv){

    MYFILE *src, *dst;
    int in, out;
    char buf[BUF_SIZE];

    if(argc != 3){
        mini_printf("Invalid number of arguments\n");
        return -1;
    }

    src = mini_fopen(argv[1], 'r');

    if (src == NULL){
        return -1;
    }

    dst = mini_fopen(argv[2], 'w');

    if (dst == NULL){
        return -1;
    }

    while (1) {
        in = mini_fread(buf, 1, BUF_SIZE, src);
        if(in == 0){
            break;
        }
        out = mini_fwrite(buf,1,in,dst);
        if(out ==0){
            break;
        }
    }

    mini_fclose(src);
    mini_fclose(dst);

    return 0;
}