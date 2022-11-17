#include <unistd.h>
#include "mini_lib.h"
#include <errno.h>

#define BUF_SIZE 1024

char *buffer; // déclaration d'un buffer en variable globale;
int ind = -1; // déclaration d'un index à -1;


/*
 * mini_printf
 * @params char * ptr
 * @return void
*/

void mini_printf(char *str) {


    /* gestion des erreurs */

    if (ind == -1) {
        buffer = mini_calloc(sizeof(char), BUF_SIZE);
        ind = 0;
    }

    if (buffer == NULL) {
        mini_perror("Erreur :");
        mini_exit();
    }

    /* la boucle va copier tout le contenu dee la chaine str dans le buffer */

    for (int i = 0; *(str + i) != '\0'; i++) {
        *(buffer + ind) = *(str + i);
        ind++;
        if (*(str + i) == '\n' ||
            ind == BUF_SIZE) // si jamais la chaine str est terminé ou que nous avons atteint la taille du buffer
        {
            write(1, buffer, ind); // écrit le buffer sur l'entrée standard
            ind = 0;
        }
    }
}


/*
 * mini_exit_string
 * @return void
*/

void mini_exit_string() {
    write(STDOUT_FILENO, buffer, ind); // ecriture du reste du buffer
    char *returnN = mini_calloc(sizeof(char), 2);
    *(returnN) = '\n';
    write(STDOUT_FILENO, returnN, 1);
    ind = 0;
}


/*
 * mini_scanf
 * @params char * buffer, int sizebuffer
 * @return int
*/

int mini_scanf(char *buffer, int sizebuffer) {
    int reader = read(1, buffer, sizebuffer); // stockage du nombre de caractere lu

    if (reader == sizebuffer) { 

        *(buffer + sizebuffer - 1) = '\n';

        char *tmp = mini_calloc(sizeof(char), 1);
        while (*tmp != '\n') {
            read(1, tmp, 1);
        }

        buffer[reader] = '\0';
    }

    return reader;
}

/*
 * mini_strlen
 * @params char * s
 * @return int
*/

int mini_strlen(char *s) {
    int count = 0;
    while (*s != '\0') {
        count++;
        s++;
    }
    return count;
}


/*
 * mini_strcpy 
 * @params char * d , char * s
 * @return int
*/

int mini_strcpy(char *d, char *s) {
    int nb = 0;
    if (s == NULL) {
        mini_exit();
    }
    int n = mini_strlen(s);
    for (int i = 0; i <= n; i++) {
        *(d + i) = *(s + i);
        nb++;
    }

    return nb;
}

/*
 * mini_strcmp 
 * @params char* s1 , char * s2
 * @return int
*/

int mini_strcmp(char *s1, char *s2) {
    while ((*s1 != '\0') || (*s2 != '\0')) {
        if (*s1 > *s2)
            return 1;
        if (*s1 < *s2)
            return -1;
        s1++;
        s2++;
    }
    return 0;
}

/*
 * stringToInt
 * @params char * str
 * @return int
*/

int stringToInt(char *str) {
    int res = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
    return res;
}


/*
 * reverse
 * @params char * str[] , int length
 * @return void
*/

static void reverse(char str[], int length) {
    int start;
    int end = length - 1;
    for (start = 0; start < end; ++start, --end) {
        const char ch = str[start];
        str[start] = str[end];
        str[end] = ch;
    }
}

/*
 * intToString
 * @params int num , char *str , int base
 * @return char * 
*/

char * intToString(int num, char *str, int base) {
    int i = 0;
    char isNegNum = 0;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
    } else {
        if ((num < 0) && (base == 10)) {
            isNegNum = 1;
            num = -num;
        }

        do {
            const int rem = (num % base);
            str[i++] = (rem > 9) ? ((rem - 10) + 'a') : (rem + '0');
            num = num / base;
        } while (num != 0);
        if (isNegNum) {
            str[i++] = '-';
        }
        str[i] = '\0';
        reverse(str, i);
    }
    return str;
}


/*
 * mini_perror
 * @params char * message
 * @return void
*/

void mini_perror(char * message){
    write(1,message,mini_strlen(message));
    char err[3];
    intToString(errno,err,10);
    write(1,err,3);
    write(1,"\n",1);
}