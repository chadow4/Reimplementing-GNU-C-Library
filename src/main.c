#include "mini_lib.h"
#include <stdio.h>
#include <string.h>

 #define DEBUG


int main(int arc, char **argv) {

    mini_printf("=============================================\n");

    /* Test mini_strcmp */

#ifdef DEBUG

    printf("\nexpected: %i result %i\n", strcmp("abcd", "abcd"), mini_strcmp("abcd", "abcd"));
    printf("expected: %i result %i\n", strcmp("abcd", "abc"), mini_strcmp("abcd", "abc"));
    printf("expected: %i result %i\n", strcmp("abc", "abcd"), mini_strcmp("abc", "abcd"));


    /* Test mini_strlen */


    char *testMiniStrLen = mini_calloc(sizeof(char), 20);
    strcpy(testMiniStrLen, "testMiniStrLen\n");



    printf("Length of string with strlen l = %d \n", mini_strlen(testMiniStrLen));
    printf("Length of string with mini_strlen l = %d \n", (int) strlen(testMiniStrLen));

#endif

    /* Test mini_strcpy */

    char *test4 = mini_calloc(sizeof(char), 6);
    mini_strcpy(test4, "tests\n");
    mini_printf(test4);

    /* Other Test with mini_calloc, mini_printf, mini_free & mini_exit*/

    char *test2 = mini_calloc(sizeof(char), 14);
    mini_strcpy(test2, "2eme test :)\n");
    mini_printf(test2);

    char *test3 = mini_calloc(sizeof(char), 16);
    mini_strcpy(test3, "3eme test\n");
    mini_printf(test3);


    mini_printf(test3);
    mini_printf(test2);

    char *testMiniScanF = mini_calloc(sizeof(char), 10);
    mini_printf("Test du scanf : \n");
    mini_scanf(testMiniScanF, 10);
    mini_printf(testMiniScanF);

    mini_free(test3);
    mini_free(test2);

    /* Test open, read , write files */


    MYFILE *readFile = mini_fopen("./testFiles/readFile.txt", 'r');
    MYFILE *writeFile = mini_fopen("./testFiles/writeFile.txt", 'w');


    char *buff = mini_calloc(sizeof(char), 50);
    char *helloWorld = "jecrisDansMonFichier";
    mini_printf(buff);

    mini_fread(buff, sizeof(char), 50, readFile);
    mini_fwrite(helloWorld, sizeof(char), 10, writeFile);

    mini_fflush(writeFile);

    mini_printf(buff);

    mini_printf("\n");

#ifdef DEBUG

    int res = mini_fclose(writeFile);

    printf("fichier closed : %d\n", res);

#endif

    MYFILE *getcFile = mini_fopen("./testFiles/getc.txt", 'r');
    MYFILE *putcFile = mini_fopen("./testFiles/putc.txt", 'w');
    char *test = mini_calloc(sizeof(char),2);
    *(test) = mini_fgetc(getcFile);

    mini_printf(test);
    mini_fputc(putcFile,*(test));

#ifdef DEBUG

    char str[100] = {0};

    printf("Base:10 %s\n", intToString(2324, str, 10));
    printf("Base:10 %s\n", intToString(-2324, str, 10));

#endif

    mini_exit();
    return 0;
}
    
   
