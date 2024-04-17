/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ISMAEL BREA ARIAS LOGIN 1: ismael.brea
 * AUTHOR 2: DIEGO ROMÁN POSE  LOGIN 2: diego.roman
 * GROUP: 4.3
 * DATE: ** / ** / **
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "user_list.h"

#define MAX_BUFFER 255

void New(tUserName newUserName, tUserCategory newUserCategory, tList *list) {
    /* Objetivo: Procesar la petición de creación de un nuevo usuario.
     * Entradas:
     *   newUserName: Nombre del nuevo usuario.
     *   newUserCategory: Categoría del nuevo usuario.
     *   list: Puntero a la lista de usuarios.
     * Salidas: ninguna.
     * Precondiciones: list debe ser un puntero válido a una lista de usuarios.
     * Postcondiciones: Se incorpora un nuevo usuario a la lista de usuarios con la categoría indicada.
     */

    // Verificar si el usuario ya existe en la lista
    if (findItem(newUserName, *list) != LNULL) {
        // El usuario ya existe, imprimir un mensaje de error
        printf("+ Error: New not possible\n");
        return;
    }

    // Crear un nuevo objeto tItem para representar al nuevo usuario
    tItem newUser;

    strcpy(newUser.userName, newUserName);
    newUser.userCategory = newUserCategory;
    newUser.numPlay = 0;  // Inicializar el contador de tiempo de reproducción a 0

    // Insertar el nuevo usuario en la lista
    if (insertItem(newUser, LNULL, list)) {
        // Imprimir un mensaje de confirmación
        printf("* New: user %s category %s\n", newUserName, newUserCategory == basic ? "basic" : "pro");
    } else {
        // No se pudo agregar el nuevo usuario, imprimir un mensaje de error
        printf("+ Error: New not possible\n");
    }
}
}

void Add(tUserName userName, tSongTitle songTitle, tListU *userList) {
    /* Objetivo: Procesar la petición de agregar una canción a la lista de reproducción de un usuario.
     * Entradas:
     *   userName: Nombre del usuario al que se añadirá la canción.
     *   songTitle: Título de la canción a agregar.
     *   userList: Puntero a la lista de usuarios.
     * Salidas: ninguna.
     * Precondiciones: userList debe ser un puntero válido a una lista de usuarios.
     * Postcondiciones: Se agrega la canción a la lista de reproducción del usuario indicado.
     */

    // Buscar al usuario en la lista
    tPosU userPosition = findItemU(userName, *userList);

    if (userPosition != NULLU) {
        // Verificar si la canción ya está en la lista de reproducción del usuario
        tPosS songPosition = findItemS(songTitle, getItemU(userPosition, *userList).songList);
        if (songPosition == NULLS) {
            // La canción no está en la lista de reproducción del usuario, la añadimos
            tSong newSong;
            strcpy(newSong.songTitle, songTitle);
            newSong.playTime = 0;  // Inicializamos el tiempo de reproducción a 0

            // Insertar la nueva canción al final de la lista de reproducción
            if (insertItemS(newSong, lastS(getItemU(userPosition, *userList).songList), &(getItemU(userPosition, *userList).songList))) {
                // Imprimir mensaje de éxito
                printf("* Add: user %s adds song %s\n", userName, songTitle);
            } else {
                // No se pudo agregar la canción, imprimir mensaje de error
                printf("+ Error: Add not possible\n");
            }
        } else {
            // La canción ya está en la lista de reproducción del usuario, imprimir mensaje de error
            printf("+ Error: Add not possible\n");
        }
    } else {
        // No se encontró al usuario en la lista, imprimir mensaje de error
        printf("+ Error: Add not possible\n");
    }
}



void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3) {

    switch (command) {
        case 'N':
            printf("Command: %s %c %s %s\n", commandNumber, command, param1, param2);
            break;
        case 'D':
            break;
        case 'A':
            break;
        case 'U':
            break;
        case 'P':
            break;
        case 'S':
            break;
        case 'R':
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {

    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3);
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
