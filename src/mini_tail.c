#include <unistd.h>
#include "mini_lib.h"

#define BUF_SIZE 1024

int main(int argc, char **argv){

    if(argc != 4){
        mini_printf("Error number of arguments\n");
        return -1;
    }

    char* reader = mini_calloc(sizeof(char), 5000);
    
    MYFILE* file = mini_fopen(argv[3], 'r');
    if(file == NULL){
        return -1;
    }
    mini_fread(reader, sizeof(char), 5000, file);

    char* buffer = mini_calloc(sizeof(char), 5000);

    int number = 0;
    for(int i = 0; *(reader+i) != '\0'; i++){
        if(*(reader+i) == '\n'){
            number++;
        }
    }
    number++; 

    if(stringToInt(argv[2],10)>number){
        mini_printf(reader);
        return 0;
    }else{
        number = number-stringToInt(argv[2],10);
    }
    int j = 0;
    int compteur = 0;
    for(int i = 0; *(reader+i) != '\0'; i++){
        
        if(compteur>=number){
            *(char*)(buffer+j) = *(char*)(reader+i);
            j++;
        }
        
        if(*(char*)(reader+i) == '\n'){
            compteur++;
        }
    }
    *(char*)(buffer+j) = '\0';


    mini_printf(buffer);
    mini_fclose(file);
    mini_exit();
    return 0;
}



