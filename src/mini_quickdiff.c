#include "mini_lib.h"
#include <unistd.h>

int main(int argc, char **argv) {

    if (argc != 3) {
        mini_printf("Error: number of arguments invalid\n");
        return 1;
    }

    MYFILE *file1 = mini_fopen(argv[1], 'r');
    MYFILE *file2 = mini_fopen(argv[2], 'r');
    int countLine = 1;

    char *linesFile1 = mini_calloc(sizeof(char), 1024);
    char *linesFile2 = mini_calloc(sizeof(char), 1024);
    if (!file1 || !file2) {
        mini_printf("Error: opening files\n");
        return 1;
    }

    while (mini_fgets(linesFile1, 1024, file1) != NULL && mini_fgets(linesFile2, 1024, file2) != NULL) {
        if (mini_strcmp(linesFile1, linesFile2) != 0) {
            char lineNumber[10] = {0};
            intToString(countLine, lineNumber, 10);
            mini_printf("Line ");
            mini_printf(lineNumber);
            mini_printf(" : \n");
            mini_printf("File 1: ");
            mini_printf(linesFile1);
            mini_printf("\n");
            mini_printf("File 2: ");
            mini_printf(linesFile2);
            mini_printf("\n");
            mini_printf("\n");
        }
        countLine++;
        mini_free(linesFile1);
        mini_free(linesFile2);
        linesFile1 = mini_calloc(sizeof(char), 1024);
        linesFile2 = mini_calloc(sizeof(char), 1024);
    }
    return 0;

}