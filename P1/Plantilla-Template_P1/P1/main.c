/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ISMAEL BREA ARIAS    LOGIN 1: ismael.brea
 * AUTHOR 2: DIEGO ROMÁN POSE     LOGIN 2: diego.roman
 * GROUP:4.3                       DATE:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif


void New(char tUserName, tUserCategory userCategory, tList *list){

}

    /* Objetivo: alta de un usuario de categoría basic o pro
    * Entradas: lista, nombre de usuario y categoría del usuario
    * Salidas: lista
    * Precondiciones: La lista debe estar inicializada y no debe estar llena.
                     El nombre de usuario debe ser único (no debe existir otro usuario con el mismo nombre).
    * Postcondiciones: Se agrega un nuevo usuario a la lista con el nombre y categoría especificados.
                       Si se realiza con éxito, la lista se modifica con el nuevo usuario añadido.
                       Si no se puede realizar el alta (por ejemplo, debido a un nombre de usuario duplicado),
                       la lista permanece sin cambios.
    * */



    void processCommand(char *commandNumber, char command, char *param1, char *param2) {

    switch (command) {
        case 'N':
            printf("Command: %s %c %s %s\n", commandNumber, command, param1, param2);
            break;
        case 'D':
            break;
        case 'U':
            break;
        case 'P':
            break;
        case 'S':
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}






