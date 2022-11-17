#include <unistd.h>
#include "mini_lib.h"

MallocElement *malloc_list = NULL; // défini une malloc_list à NULL en variable globale;

/*
 * mini_calloc
 * @params int size_element , int number_element
 * @return void
*/
void *mini_calloc(int size_element, int number_element) {


    /* Vérification d'entrée */

    if (number_element < 0) {
        return NULL;
    }

    if (size_element <= 0) {
        return NULL;
    }


    /* Déclarations */

    MallocElement *elem = NULL;  // déclaration d'un élément à NULL
    MallocElement *current_list = malloc_list; // déclaration d'une current_list qui prend la valeur de malloc_list

    int size_buffer = size_element * number_element;

    /* Vérification si nous avons un élément avec une zone libre dans la current_list */

    while (current_list != NULL) {
        if (current_list->statut == 0 && current_list->size >= size_buffer) {
            elem = current_list;
            break;
        }
        current_list = current_list->suiv;
    }

    /* Si jamais l'élement est NULL (pas trouvé de zone libre dans la liste) */

    if (elem == NULL) {
        if ((elem = sbrk(sizeof(MallocElement))) == (void *) (-1)) { // alloue la mémoire à l'élement
            mini_exit();
        }
        if ((elem->zone_alloc = sbrk(size_buffer)) ==
            (void *) (-1)) { // alloue la mémoire à zone d'allocation de l'élément
            mini_exit();
        }

        elem->size = size_buffer; // on affecte à la taille de l'élément la taille du buffer

        /*  Ajoute l'élément au début de la liste afin de simplifier l'ajout de l'élément
         *  (éviter de reboucler dessus)
        */

        elem->suiv = malloc_list;
        malloc_list = elem;
    }

    elem->statut = 1; // on affecte 1 au statut de l'élement pour dire qu'il n'est pas libre

    /* on initialise tout le buffer avec des \0 */

    char *temp = elem->zone_alloc;
    for (int i = 0; i < size_buffer; i++) {
        temp[i] = '\0';
    }

    return elem->zone_alloc;
}


/*
 * mini_free
 * @params void * ptr
 * @return void
*/
void mini_free(void *ptr) {

    MallocElement *ml = malloc_list;

    while (ml != NULL) {
        if (ml->zone_alloc == ptr) {
            ml->statut = 0;
            return;
        }
        ml = ml->suiv;
    }
}

/*
 * mini_exit
 * @return void
*/

void mini_exit() {
    mini_exit_string();
    mini_exit_io();
    _exit(0);
}

