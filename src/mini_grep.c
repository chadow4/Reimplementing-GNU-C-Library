#include <unistd.h>
#include "mini_lib.h"
#define BUF_SIZE 1024



int compare_char(char* first, char* second){
    for(int i = 0; *(char*)(first+i) != '\0'; i++){
        if(*(char*)(first+i) != *(char*)(second+i)){
            return -1;
        }
    }
    return 0;
}

int main (int argc, char **argv){

    if(argc !=3){
        mini_printf("Error: number of arguments invalid\n");
        return -1;
    }

    char* buffer = mini_calloc(sizeof(char), BUF_SIZE);
    char* reader = mini_calloc(sizeof(char), BUF_SIZE);
    
    MYFILE* file = mini_fopen(argv[2], 'r');
    if(file == NULL){
        return -1;
    }
    mini_fread(reader, sizeof(char), BUF_SIZE, file);

    int ind_buffer = 0;
    int init_ind = 0;
    
    for(int i = 0; *(reader+i)!='\0'; i++){
        *(buffer+ind_buffer) = *(reader+i);
    
        if(*(reader+i) == '\n'){
            *(buffer+ind_buffer+1) = '\0';
            for(int j = 0; *(char*)(buffer+j) != '\0'; j++){
                if(compare_char(argv[1], buffer+j) == 0){
                    mini_printf(buffer);
                    break;
                }
            }
        
            init_ind = 1;
            ind_buffer = 0;
        }
        if(init_ind == 0){
            ind_buffer++;
        }else{
            init_ind = 0;
        }
    }

    *(buffer+ind_buffer+1) = '\0';
    for(int j = 0; *(buffer+j) != '\0'; j++){
        if(compare_char(argv[1], buffer+j) == 0){
            mini_printf(buffer);
            break;
        }
    }
    return 0;
}
