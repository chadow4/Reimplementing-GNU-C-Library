#ifndef MINI_LIB_H
#define MINI_LIB_H


typedef struct malloc_element {
    void *zone_alloc;
    int size;
    int statut;
    struct malloc_element *suiv;

}
        MallocElement;


typedef struct my_file {
    int fd;
    void *buffer_read;
    void *buffer_write;
    int ind_read;
    int ind_write;
}
        MYFILE;


typedef struct ElementLists {
    struct my_file *File;
    struct ElementLists *suiv;
}
        ELEMENTLISTS;


extern void *mini_calloc(int size_element, int number_element);

extern void mini_free(void *ptr);

extern void mini_exit();

extern void mini_exit_string();

extern void mini_exit_io();

extern void mini_printf(char *txt);

extern int mini_scanf(char *buf, int size_buffer);

extern int mini_strcpy(char *s, char *d);

extern int mini_strlen(char *s);

extern int mini_strcmp(char *s1, char *s2);

extern struct my_file *mini_fopen(char *file, char mode);

extern int mini_fread(void *buffer, int size_element, int number_element, MYFILE *file);

extern int mini_fwrite(void *buffer, int size_element, int number_element, MYFILE *file);

extern int mini_fflush(MYFILE *file);

extern int mini_fclose(MYFILE *file);

extern int mini_fputc(MYFILE *file, char c);

extern int mini_fgetc(MYFILE *my_file);

extern int stringToInt(char *str);

extern char * intToString(int num, char *str, int base);

extern void mini_perror(char * message);


#endif