#include <unistd.h>
#include <fcntl.h>
#include "mini_lib.h"

#define IOBUFFER_SIZE 2048

ELEMENTLISTS *elementLists = NULL;

/*
 * mini_fopen
 * @params char * file , char mode
 * @return MYFILE
*/

MYFILE *mini_fopen(char *file, char mode) {

    int fd;
    switch (mode) {
        case 'r':
            fd = open(file, O_RDONLY, 0755);
            break;

        case 'w':
            fd = open(file, O_TRUNC | O_WRONLY | O_CREAT, 0755);
            break;

        case 'b':
            fd = open(file, O_TRUNC | O_RDWR | O_CREAT, 0755);
            break;

        case 'a':
            fd = open(file, O_APPEND | O_WRONLY | O_CREAT, 0755);
            break;

    }
    if (fd == -1) {
        mini_printf("Error opening File\n");
        return NULL;
    }

    MYFILE *myfile;

    if ((myfile = mini_calloc(sizeof(MYFILE), 1)) == NULL) {
        return NULL;
    }

    /* remplissage de tout les champs de myfile */

    myfile->fd = fd;
    myfile->buffer_read = NULL;
    myfile->buffer_write = NULL;
    myfile->ind_read = -1;
    myfile->ind_write = -1;

    // ajout du myfiles dans la liste

    ELEMENTLISTS *newElement = mini_calloc(sizeof(ELEMENTLISTS), 1);

    newElement->File = myfile;

    newElement->suiv = NULL;


    if (elementLists == NULL) {
        elementLists = newElement;
    } else {
        ELEMENTLISTS *temp = elementLists;
        while (temp->suiv != NULL) {

            temp = temp->suiv;
        }
        temp->suiv = newElement;
    }


    return myfile;
}

static void affect0Buffer(char *buffer) {
    for (size_t i = 0; i < IOBUFFER_SIZE; i++) {
        buffer[i] = '\0';
    }

}

/*
 * mini_fread
 * @params void * buffer , int size_element , int number_element , MYFILE * file
 * @return int
*/

int mini_fread(void *buffer, int size_element, int number_element, MYFILE *file) {

    /* gestion d'erreurs */

    if (file->ind_read == -1) {
        file->ind_read = 0;
        file->buffer_read = mini_calloc(IOBUFFER_SIZE, 1);
        read(file->fd, file->buffer_read, IOBUFFER_SIZE);
    }
    int i = 0;
    while (i < size_element * number_element) {

        if (file->ind_read == IOBUFFER_SIZE) {
            affect0Buffer(((char *) file->buffer_read)); // affectation de caractere \0 pour tout le buffer
            if ((read(file->fd, file->buffer_read, IOBUFFER_SIZE) == 0)) {
                return i;
            }
            file->ind_read = 0;
        }

        if (((char *) file->buffer_read)[file->ind_read] == '\0') {
            return i;
        }

        ((char *) buffer)[i] = ((char *) file->buffer_read)[file->ind_read]; // stockage des elements de buffer_read dans le buffer
        file->ind_read++;

        i++;

    }
    return i;
}

/*
 * mini_fwrite
 * @params void * buffer , int size_element , int number_element , MYFILE * file
 * @return int
*/

int mini_fwrite(void *buffer, int size_element, int number_element, MYFILE *file) {

    /* gestion d'erreurs */

    if (file->ind_write == -1) {
        file->ind_write = 0;
        file->buffer_write = mini_calloc(IOBUFFER_SIZE, 1);
    }
    int i = 0;
    while (i < size_element * number_element) {
        if (file->ind_write == IOBUFFER_SIZE) {
            write(file->fd, file->buffer_write, IOBUFFER_SIZE);
            file->ind_write = 0;
        }

        ((char *) file->buffer_write)[file->ind_write] = ((char *) buffer)[i]; // stockage des elements du buffer dans buffer_write
        file->ind_write++;

        i++;
    }

    return i;
}

/*
 * mini_fflush
 * @params MYFILE * file
 * @return int
*/

int mini_fflush(MYFILE *file) {
    int res;
    if ((res = write(file->fd, file->buffer_write, file->ind_write)) == -1) {
        return -1;
    }
    file->ind_write = 0; // on remet ind_write a zero apres avoir flush
    return res;
}

/*
 * mini_fclose
 * @params MYFILE * file
 * @return int
*/

int mini_fclose(MYFILE *file) {

    if (file->ind_write > -1) { // si jamais le fichier est un fichier writtable alors on flush
        mini_fflush(file);
    }
    ELEMENTLISTS *current = elementLists;
    ELEMENTLISTS *temp = mini_calloc(sizeof(ELEMENTLISTS), 1);

    /* on parcourt le la liste des fichiers ouvert afin de supprimer le fichier voulu dans la liste*/
    while (current->suiv != NULL) {
        if (current->suiv->File == file) {
            temp = current->suiv->suiv;
            mini_free(current->suiv);
            current->suiv = temp;
            break;
        }
        current = current->suiv;
    }
    if (close(file->fd) == -1) {  // fermeture du fichier
        mini_perror("erreur de fermeture de fichier : ");
    }

    return 0;
}

/*
 * mini_exit_io
 * @return void
*/

void mini_exit_io() {
    ELEMENTLISTS *temp = elementLists;
    while (temp != NULL) {
        mini_fflush(temp->File);
        temp = temp->suiv;
    }
}

/*
 * mini_fgetc
 * @params MYFILE * file
 * @return int
*/


int mini_fgetc(MYFILE *file) {
    char buf;
    int result = mini_fread(&buf, sizeof(char), 1, file);
    if (result == -1) {
        return -1;
    }
    if (result == 0) {
        return 0;
    }
    return buf;
}

/*
 * mini_fputc
 * @params  MYFILE * ptr , char c
 * @return int
*/


int mini_fputc(MYFILE *file, char c) {
    if (mini_fwrite(&c, sizeof(char), 1, file) == -1) {
        return -1;
    }
    return 0;
}


char *mini_strcat(char *dest, char *src, int n) {
    int dest_len = mini_strlen(dest);
    int i;

    for (i = 0 ; i < n && src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

    return dest;
}

char *mini_fgets(char *buffer, int n, MYFILE *stream) {
    char read;
    while ((read = (char)mini_fgetc(stream)) > 0 && read != '\n' && n--) {
        mini_strcat(buffer, &read, 2);
    }
    if (read <= 0) {
        return NULL;
    }
    return buffer;
}
